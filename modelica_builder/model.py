"""
****************************************************************************************************
:copyright (c) 2020-2022, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""

import logging
import os

from modelica_builder.builder import (
    ComponentBuilder,
    ConnectBuilder,
    EquationForLoopBuilder,
    ParameterBuilder
)
from modelica_builder.edit import Edit
from modelica_builder.selector import (
    ComponentArgumentSelector,
    ComponentDeclarationSelector,
    ComponentModificationNameSelector,
    ComponentModificationValueSelector,
    ComponentRedeclarationSelector,
    ConnectClauseSelector,
    ModelIdentifierSelector,
    NthChildSelector,
    ParentSelector,
    WithinSelector
)
from modelica_builder.transformation import (
    ComponentModificationsTransformation,
    ModelAnnotationTransformation,
    SimpleTransformation
)
from modelica_builder.transformer import Transformer

logger = logging.getLogger(__name__)


class Model(Transformer):
    def __init__(self, source):
        if not os.path.exists(source):
            raise Exception(f'Modelica file does not exist: {source}')
        self._source = source

        self._updated_model_annotation_modifications = False

        super().__init__(source)

    def get_name(self):
        """returns the model's name

        :return: string
        """
        selector = ModelIdentifierSelector()
        result = self.apply_selector(selector)
        if result:
            return result[0].getText()

        raise Exception('Model name not found')

    def set_name(self, name):
        """sets the model's name

        :param name: string
        """
        selector = ModelIdentifierSelector()
        self.add(SimpleTransformation(selector, Edit.make_replace(name)))

    def set_within_statement(self, within_string):
        """changes 'within <string>;' at the beginning of
        the file

        :param within_string: string, new value
        """
        selector = (WithinSelector()
                    .assert_count(1, 'A single within statement must already exist'))
        self.add(SimpleTransformation(selector, Edit.make_replace(f'within {within_string};')))

    def add_connect(self, port_a, port_b, annotations=None):
        """add_connect creates a new connect clause in the equation section

        :param port_a: string, first port identifier
        :param port_b: string, second port identifier
        :param annotations: array of strings, optional annotations to add
        """
        connect = ConnectBuilder(port_a, port_b, annotations)
        self.add(connect.transformation())

    def remove_connect(self, port_a, port_b):
        """remove_connect finds and removes the connect clause that matches

        :param port_a: string, first port identifier; an asterisk matches all
        :param port_b: string, second port identifier; an asterisk matches all
        """
        # select the parent of the component to also select the semicolon and comments
        selector = (ConnectClauseSelector(port_a, port_b)
                    .chain(ParentSelector()))
        self.add(SimpleTransformation(selector, Edit.make_delete()))

    def edit_connect(self, port_a, port_b, new_port_a=None, new_port_b=None):
        """edit_connect finds all connect clauses that match the pattern
        connect(<port_a>, <port_b>), in that order. If a port is an asterisk, '*',
        then it matches any identifier.

        :param port_a: string, identifier for first port; an asterisk matches all
        :param port_b: string, identifier for second port; an asterisk matches all
        :param new_port_a: string | None, replacement for port a; if None no changes are made
        :param new_port_b: string | None, replacement for port b; if None no changes are made
        """
        # verify the paramaters are sensible
        if (port_a == '*' and new_port_a is not None) or (port_b == '*' and new_port_b is not None):
            raise Exception(
                'Invalid to have a port match a wildcard and replace it (might result in duplicate clauses)')

        # make up to two transformations (one for each replacement)
        if new_port_a is not None:
            selector = (ConnectClauseSelector(port_a, port_b)
                        .chain(NthChildSelector(2)))
            self.add(SimpleTransformation(selector, Edit.make_replace(new_port_a)))

        if new_port_b is not None:
            selector = (ConnectClauseSelector(port_a, port_b)
                        .chain(NthChildSelector(4)))
            self.add(SimpleTransformation(selector, Edit.make_replace(new_port_b)))

    def insert_equation_for_loop(self, index_identifier, expression_raw, loop_body_raw_list):
        """constructs and inserts a for loop in the equation section

        :param index_identifier: string, identifier for the index variable
        :param expression_raw: string, the expression for iteration, e.g. range(x)
        :param loop_body_raw: list, list of loop body lines, each of which is valid modelica code
        """
        self.add(
            EquationForLoopBuilder(
                index_identifier, expression_raw, loop_body_raw_list
            ).transformation())

    def insert_component(self, type_, identifier, modifications=None, conditional=None, string_comment=None,
                         annotations=None, insert_index=-1):
        """insert_component constructs and inserts a component

        :param type_: string, type of the component
        :param identifier: string, component identifier
        :param modifications: dict {string: string}, component initialization modifications with arg name as the key and arg value as the value
        :param conditional: string, conditional applied to the modelica component
        :param string_comment: string
        :param annotations: list of strings, annotations to add to the component
        :param insert_index: int, index to place the new component. if < 0, it will insert at the end
        """
        component = ComponentBuilder(insert_index, type_, identifier)
        if modifications is not None:
            for arg_name, arg_value in modifications.items():
                component.set_modification(arg_name, arg_value)

        if conditional is not None:
            component.set_conditional(conditional)

        if string_comment is not None:
            component.set_string_comment(string_comment)

        if annotations is not None:
            for annotation in annotations:
                component.add_annotation(annotation)

        self.add(component.transformation())

    def rename_component_argument(self, type_, identifier, old_argument_name, new_argument_name):
        """Rename the argument name of a component

        :param type_: string, type of the component
        :param identifier: string, component identifier
        :param old_argument_name: string, name of the argument that will be replaced
        :param new_argument_name: string, name of the new argument name
        """
        selector = (ComponentDeclarationSelector(type_, identifier)
                    .chain(
            ComponentModificationNameSelector(
                old_argument_name
            )))

        self.add(SimpleTransformation(selector, Edit.make_replace(f'{new_argument_name}')))

    def overwrite_component_redeclaration(self, type_, identifier, new_declaration):
        """
        Overwrite the component redeclaration with a new string

        :param type_: string, type of the component
        :param identifier: string, component identifier
        :param new_declaration: string, new component redeclaration string. It is the entire string, i.e., argument=value
        """
        selector = (ComponentDeclarationSelector(type_, identifier)
                    .chain(ComponentRedeclarationSelector()))

        self.add(SimpleTransformation(selector, Edit.make_replace(f'{new_declaration}')))

    def remove_component(self, type_=None, identifier=None):
        """remove_component removes a component declaration.
        Note that if the component is part of a list of declarations, e.g.
        TypeName IdentifierA, IdentifierB, IdentifierC;
        then _all_ declarations are removed.

        :param type_: string, optional, type in the declaration
        :param identifier: string, optional, identifier in the declaration
        """
        if type_ is None and identifier is None:
            raise Exception('At least one of the parameters must not be None')

        selector = (ComponentDeclarationSelector(type_, identifier)
                    .chain(ParentSelector())  # component_list
                    .chain(ParentSelector())  # component_clause
                    .chain(ParentSelector()))  # element

        self.add(SimpleTransformation(selector, Edit.make_delete()))

    def remove_component_argument(self, type_, identifier, argument_name):
        """Remove the argument from a component

        :param type_: string, type of the component
        :param identifier: string, component identifier
        :param argument_name: string, name of the argument that will be removed
        """
        if type_ is None and identifier is None:
            raise Exception('At least one of the parameters must not be None')

        selector = (
            ComponentDeclarationSelector(type_, identifier)
            .chain(ComponentArgumentSelector(argument_name))
        )

        self.add(SimpleTransformation(selector, Edit.make_delete()))

    def update_component_modification(self, type_, identifier, modification_name, new_value, if_value=None):
        """update_component_modification changes the value of an _existing_ component
        modification value. ie this won't work if the argument isn't already used

        :param type_: string, component type
        :param identifier: string, component identifier
        :param modification_name: string, modification to update
        :param new_value: string, new modification value
        :param if_value: string, if provided it will only update the value if the existing value matches this
        """
        selector = (ComponentDeclarationSelector(type_, identifier)
                    .chain(
            ComponentModificationValueSelector(
                modification_name,
                modification_value=if_value)))

        self.add(SimpleTransformation(selector, Edit.make_replace(new_value)))

    def update_component_modifications(self, type_, identifier, modifications):
        """update_component_modifications updates or creates modifications for
        specific components.

        :param type_: string, component type
        :param identifier: string, component identifier
        :param modifications: dict, see comment below about its structure

        The modifications param is a dictionary. Each key represents a modification
        argument name. Each value represents the modification value. If a value
        in the dict is another dict, then the modification is interpreted as a
        class modification. If the key 'OVERWRITE_MODIFICATIONS' is found in a dict
        and is True, then all existing modifications at that depth are overwritten with the
        new modifications.

        Refer to the tests in test_model.py for specific examples
        """
        self.add(ComponentModificationsTransformation(type_, identifier, modifications))

    def add_parameter(self, type_, identifier, modifications=None, assigned_value=None, string_comment=None,
                      annotations=None):
        """add_parameter inserts a new parameter at the top of the model's element list

        :param type_: string, type of the component
        :param identifier: string, component identifier
        :param modifications: dict {string: variant}, component initialization modifications with arg name as the key and arg value as the value
        :param assigned_value: variant, value to assign to the parameter
        :param string_comment: string, comment to add
        :param annotations: list of strings, annotations to add to the component
        """
        parameter = ParameterBuilder(0, type_, identifier)

        if modifications:
            for arg_name, arg_value in modifications.items():
                parameter.set_modification(arg_name, arg_value)

        if string_comment:
            parameter.set_string_comment(string_comment)

        if annotations:
            for annotation in annotations:
                parameter.add_annotation(annotation)

        # Make sure that 0 is an allowed value (i.e., check for not None instead of truthy)
        if assigned_value is not None:
            parameter.set_value(assigned_value)

        self.add(parameter.transformation())

    def update_model_annotation(self, modifications):
        """Updates the model annotation modifications. If a modification exists
        then it is updated, if it doesn't then it is inserted. If this method is
        called more than once, previous calls are IGNORED and only the last call
        is used.

        The modifications param is a dictionary. Each key represents a modification
        argument name. Each value represents the modification value. If a value
        in the dict is another dict, then the modification is interpreted as a
        class modification. If the key 'OVERWRITE_MODIFICATIONS' is found in a dict
        and is True, then all existing modifications at that depth are overwritten with the
        new modifications.

        Refer to the tests in test_model.py for specific examples

        :param modifications: dict
        """
        # if this method has been called before, remove our previous transformation
        if self._updated_model_annotation_modifications:
            logger.warning('Ignoring previous model annotations update')
            self._transformations.pop(0)

        # add the transformation to the FRONT, ensuring it ends up at the END of the model definition
        #
        # Explanation
        # there's an edge case where this transformation might try to insert
        # at the end of the model (when the model annotation doesn't exist already) and another
        # transformation might try to insert at the end  as well (e.g. adding a connect caluse).
        # Thus we want to make sure our insert operation (if it happens) happens first
        self._updated_model_annotation_modifications = True
        self._transformations.insert(0, ModelAnnotationTransformation(modifications))

    def save(self):
        """overwrite the source file with the processed result"""
        self.save_as(self._source)

    def save_as(self, filename):
        """save the result to a file

        :param filename: string, name of file
        """
        result = self.execute()
        # Setting newline=None here means any \n we added will be translated
        # to the native OS's line separator:
        # https://docs.python.org/3.6/library/functions.html#open
        with open(filename, 'wt', newline=None) as f:
            f.write(result)
