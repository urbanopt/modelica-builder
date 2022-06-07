"""
****************************************************************************************************
:copyright (c) 2020-2022, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""


from modelica_builder import config
from modelica_builder.edit import Edit
from modelica_builder.selector import (
    ElementListSelector,
    EquationSectionSelector,
    NthChildSelector
)
from modelica_builder.transformation import SimpleTransformation


class ComponentBuilder:
    def __init__(self, insert_index, type_, identifier):
        """ComponentBuilder allows you to construct and insert a component

        :param insert_index: int, index to place the new component. if < 0, it will insert at the end
        :param type_: string, type of the component
        :param identifier: string, component identifier
        """
        self._modifications = {}
        self._annotations = []
        self._conditional = None
        self._string_comment = None
        self._insert_index = insert_index
        self._type = type_
        self._identifier = identifier

    def set_modification(self, arg_name, arg_value):
        """set_modification sets a component initialization modification

        :param arg_name: string, name of the modification
        :param arg_value: string, value of the modification
        """
        self._modifications[arg_name] = arg_value

    def set_conditional(self, conditional):
        self._conditional = conditional

    def set_string_comment(self, string_comment):
        self._string_comment = string_comment

    def add_annotation(self, annotation):
        """add_annotation adds an annotation to the component

        :param annotation: string, annotation to add
        """
        self._annotations.append(annotation)

    def transformation(self):
        """transformation creates the transformation required for inserting the
        built component

        :return: Transformation
        """
        if self._insert_index == 0:
            selector = (ElementListSelector()
                        .chain(NthChildSelector(0)))
            insert_after = False
        elif self._insert_index < 0:
            # insert after the last child
            selector = (ElementListSelector()
                        .chain(NthChildSelector(-1)))
            insert_after = True
        else:
            selector = (ElementListSelector()
                        .chain(NthChildSelector(self._insert_index)))
            insert_after = True

        edit = Edit.make_insert(self.build(), insert_after=insert_after)
        return SimpleTransformation(selector, edit)

    def build(self):
        """build constructs the text for the component

        :return: string
        """
        modifications = ''
        if self._modifications:
            modifications = f"({', '.join([f'{k}={v}' for k, v in self._modifications.items()])})"

        conditional = ''
        if self._conditional:
            conditional = f" {self._conditional}"

        string_comment = ''
        if self._string_comment:
            string_comment = f' "{self._string_comment}"'

        annotations = ''
        if self._annotations:
            annotations = f" annotation({', '.join(self._annotations)})"

        return f'\n{config.INDENTATION}{self._type} {self._identifier}{modifications}{conditional}{string_comment}{annotations};\n{config.INDENTATION}'


class ConnectBuilder:
    def __init__(self, a, b, annotations=None):
        """ConnectBuilder allows you to construct a connect clause

        :param a: string, port a
        :param b: string, port b
        :param annotation: list, list of annotation strings
        """
        self._a = a
        self._b = b
        self._annotations = [] if annotations is None else annotations

    def transformation(self):
        """transformation creates the transformation required for inserting the
        built connect clause

        :return: Transformation
        """
        # select the last child of the equation section and insert after it
        selector = (EquationSectionSelector()
                    .chain(NthChildSelector(-1))
                    .assert_count(1, 'Failed to find end of the equation section'))
        edit = Edit.make_insert(self.build(), insert_after=True)
        return SimpleTransformation(selector, edit)

    def build(self):
        """build constructs the text for the connect clause

        :return: string
        """
        annotations = ''
        if self._annotations:
            annotations = f" annotation({', '.join(self._annotations)})"

        return f'\n{config.INDENTATION}connect({self._a}, {self._b}){annotations};\n{config.INDENTATION}'


class ParameterBuilder:
    def __init__(self, insert_index, type_, identifier):
        """ParameterBUilder allows you to construct and insert a parameter

        :param insert_index: int, index to place the new parameter. if < 0, it will insert at the end
        :param type_: string, type of the parameter
        :param identifier: string, parameter identifier
        """
        self._modifications = {}
        self._value = None
        self._annotations = []
        self._string_comment = None
        self._insert_index = insert_index
        self._type = type_
        self._identifier = identifier

    def set_modification(self, arg_name, arg_value):
        """set_modification sets a parameter initialization modification

        :param arg_name: string, name of the modification
        :param arg_value: string, value of the modification
        """
        self._modifications[arg_name] = arg_value

    def set_value(self, value):
        """set_value sets the value of the parameter

        E.g. if you created the parameter `Real myParam`, calling set_value with
        10.0 would result in `Real myParam=10.0`

        :param value: variant, value to set
        """
        self._value = value

    def set_string_comment(self, string_comment):
        self._string_comment = string_comment

    def add_annotation(self, annotation):
        """add_annotation adds an annotation to the parameter

        :param annotation: string, annotation to add
        """
        self._annotations.append(annotation)

    def transformation(self):
        """transformation creates the transformation required for inserting the
        built parameter

        :return: Transformation
        """
        if self._insert_index == 0:
            selector = (ElementListSelector()
                        .chain(NthChildSelector(0)))
            insert_after = False
        elif self._insert_index < 0:
            # insert after the last child
            selector = (ElementListSelector()
                        .chain(NthChildSelector(-1)))
            insert_after = True
        else:
            selector = (ElementListSelector()
                        .chain(NthChildSelector(self._insert_index)))
            insert_after = True

        edit = Edit.make_insert(self.build(), insert_after=insert_after)
        return SimpleTransformation(selector, edit)

    def build(self):
        """build constructs the text for the parameter

        :return: string
        """
        modifications = ''
        if self._modifications:
            modifications = f"({', '.join([f'{k}={v}' for k, v in self._modifications.items()])})"

        value_assignment = ''
        if self._value is not None:
            value_assignment = f"={self._value}"

        string_comment = ''
        if self._string_comment:
            string_comment = f' "{self._string_comment}"'

        annotations = ''
        if self._annotations:
            annotations = f" annotation({', '.join(self._annotations)})"

        return f'\n{config.INDENTATION}parameter {self._type} {self._identifier}{modifications}{value_assignment}{string_comment}{annotations};\n{config.INDENTATION}'


class EquationForLoopBuilder:
    def __init__(self, index_identifier, expression_raw, loop_body_raw_list):
        """EquationForLoopBuilder creates a for loop for the equation section

        :param index_identifier: string
        :param expression_raw: string
        :param loop_body_raw_list: list
        """
        self._index_identifier = index_identifier
        self._expression_raw = expression_raw
        self._loop_body_raw_list = loop_body_raw_list

    def transformation(self):
        """transformation creates the transformation required for inserting the
        built for loop

        :return: Transformation
        """
        # select the last child of the equation section and insert after it
        selector = (EquationSectionSelector()
                    .chain(NthChildSelector(-1))
                    .assert_count(1, 'Failed to find end of the equation section'))
        edit = Edit.make_insert(self.build(), insert_after=True)
        return SimpleTransformation(selector, edit)

    def build(self):
        """build constructs the text for the for loop

        :return: string
        """
        loop_body_raw = f'\n{config.INDENTATION * 2}'.join(self._loop_body_raw_list)
        return f'\n{config.INDENTATION}for {self._index_identifier} in {self._expression_raw} loop\n{config.INDENTATION * 2}{loop_body_raw}\n{config.INDENTATION}end for;'
