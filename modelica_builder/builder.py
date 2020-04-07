"""
****************************************************************************************************
:copyright (c) 2020, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""


from modelica_builder.edit import Edit
from modelica_builder.selector import (
    ElementListSelector,
    EquationSectionSelector,
    NthChildSelector
)
from modelica_builder.transformation import Transformation


class ComponentBuilder:
    def __init__(self, insert_index, type_, identifier):
        """ComponentBuilder allows you to construct and insert a component

        :param insert_index: int, index to place the new component. if < 0, it will insert at the end
        :param type_: string, type of the component
        :param identifier: string, component identifier
        """
        self._arguments = {}
        self._annotations = []
        self._insert_index = insert_index
        self._type = type_
        self._identifier = identifier

    def set_argument(self, arg_name, arg_value):
        """set_argument sets a component initialization argument

        :param arg_name: string, name of the argument
        :param arg_value: string, value of the argument
        """
        self._arguments[arg_name] = arg_value

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
        if self._insert_index < 0:
            # insert after the last child
            selector = (ElementListSelector()
                        .chain(NthChildSelector(-1)))
            insert_after = True
        else:
            selector = (ElementListSelector()
                        .chain(NthChildSelector(self._insert_index)))
            insert_after = True

        edit = Edit.make_insert(self.build(), insert_after=insert_after)
        return Transformation(selector, edit)

    def build(self):
        """build constructs the text for the component

        :return: string
        """
        arguments = ''
        if self._arguments:
            arguments = f"({', '.join([f'{k}={v}' for k, v in self._arguments.items()])})"
        annotations = ''
        if self._annotations:
            annotations = f" annotation({', '.join(self._annotations)})"

        return f'\n\t{self._type} {self._identifier}{arguments}{annotations};\n\t'


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
        return Transformation(selector, edit)

    def build(self):
        """build constructs the text for the connect clause

        :return: string
        """
        annotations = ''
        if self._annotations:
            annotations = f" annotation({', '.join(self._annotations)})"

        return f'\n\tconnect({self._a}, {self._b}){annotations};\n\t'
