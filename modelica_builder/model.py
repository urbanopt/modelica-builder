"""
****************************************************************************************************
:copyright (c) 2020, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""


import os

from modelica_builder.builder import ComponentBuilder, ConnectBuilder, ParameterBuilder
from modelica_builder.edit import Edit
from modelica_builder.selector import (
    ComponentArgumentValueSelector,
    ComponentDeclarationSelector,
    ConnectClauseSelector,
    ModelIdentifierSelector,
    NthChildSelector,
    ParentSelector,
    WithinSelector
)
from modelica_builder.transformation import Transformation
from modelica_builder.transformer import Transformer


class Model(Transformer):
    def __init__(self, source):
        if not os.path.exists(source):
            raise Exception(f'Modelica file does not exist: {source}')
        self._source = source

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
        self.add(Transformation(selector, Edit.make_replace(name)))

    def set_within_statement(self, within_string):
        """changes 'within <string>;' at the beginning of
        the file

        :param within_string: string, new value
        """
        selector = (WithinSelector()
                    .assert_count(1, 'A single within statement must already exist'))
        self.add(Transformation(selector, Edit.make_replace(f'within {within_string};')))

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
        self.add(Transformation(selector, Edit.make_delete()))

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
            raise Exception('Invalid to have a port match a wildcard and replace it (might result in duplicate clauses)')

        # make up to two transformations (one for each replacement)
        if new_port_a is not None:
            selector = (ConnectClauseSelector(port_a, port_b)
                        .chain(NthChildSelector(2)))
            self.add(Transformation(selector, Edit.make_replace(new_port_a)))

        if new_port_b is not None:
            selector = (ConnectClauseSelector(port_a, port_b)
                        .chain(NthChildSelector(4)))
            self.add(Transformation(selector, Edit.make_replace(new_port_b)))

    def insert_component(self, insert_index, type_, identifier, arguments=None, string_comment=None, annotations=None):
        """insert_component constructs and inserts a component

        :param insert_index: int, index to place the new component. if < 0, it will insert at the end
        :param type_: string, type of the component
        :param identifier: string, component identifier
        :param arguments: dict {string: string}, component initialization arguments with arg name as the key and arg value as the value
        :param string_comment: string
        :param annotations: list of strings, annotations to add to the component
        """
        component = ComponentBuilder(insert_index, type_, identifier)
        if arguments is not None:
            for arg_name, arg_value in arguments.items():
                component.set_argument(arg_name, arg_value)

        if string_comment is not None:
            component.set_string_comment(string_comment)

        if annotations is not None:
            for annotation in annotations:
                component.add_annotation(annotation)

        self.add(component.transformation())

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

        self.add(Transformation(selector, Edit.make_delete()))

    def update_component_argument(self, type_, identifier, argument_name, new_value, if_value=None):
        """update_component_argument changes the value of an _existing_ component
        initialization argument value. ie this won't work if the argument isn't
        already used

        :param type_: string, component type
        :param identifier: string, component identifier
        :param argument_name: string, argument to update
        :param new_value: string, new argument value
        :param if_value: string, if provided it will only update the value if the existing value matches this
        """
        selector = (ComponentDeclarationSelector(type_, identifier)
                    .chain(ComponentArgumentValueSelector(argument_name, argument_value=if_value)))

        self.add(Transformation(selector, Edit.make_replace(new_value)))

    def add_parameter(self, type_, identifier, arguments=None, assigned_value=None, string_comment=None, annotations=None):
        """

        :param insert_index: int, index to place the new component. if < 0, it will insert at the end
        :param type_: string, type of the component
        :param identifier: string, component identifier
        :param arguments: dict {string: string}, component initialization arguments with arg name as the key and arg value as the value
        :param assigned_value: string, value to assign to the parameter, e.g. Real myParam=10.0
        :param string_comment: string, comment to add
        :param annotations: list of strings, annotations to add to the component
        """
        parameter = ParameterBuilder(0, type_, identifier)

        if arguments:
            for arg_name, arg_value in arguments.items():
                parameter.set_argument(arg_name, arg_value)

        if string_comment:
            parameter.set_string_comment(string_comment)

        if annotations:
            for annotation in annotations:
                parameter.add_annotation(annotation)

        if assigned_value:
            parameter.set_value(assigned_value)

        self.add(parameter.transformation())

    def save(self):
        """overwrite the source file with the processed result"""
        self.save_as(self._source)

    def save_as(self, filename):
        """save the result to a file

        :param filename: string, name of file
        """
        result = self.execute()
        with open(filename, 'w') as f:
            f.write(result)
