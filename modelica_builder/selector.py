"""
****************************************************************************************************
:copyright (c) 2020-2022, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""


import re
from abc import ABC, abstractmethod
from antlr4.xpath import XPath

DEFAULT_BASE_PATH = 'stored_definition'


class Selector(ABC):
    # Classes should override this to specify which grammar rule the selector will get called on
    #   when _select is called, this node will be passed as the `base` argument
    #   unless it is being chained after another selector
    BASE_PATH = DEFAULT_BASE_PATH

    """Selector is the base class for all selectors"""

    def __init__(self):
        self._chained_selector = None
        self._assert_count = None
        self._assert_message = None

    @abstractmethod
    def _select(self, base, parser):
        """_select should be overridden when implementing a Selector

        :param base: object, base of tree to search
        :param parser: object, parser that built the tree
        :return: list, list of nodes that were selected
        """

    def get_base_rule(self):
        return self.BASE_PATH.split('/')[-1]

    def assert_count(self, count, message):
        self._assert_count = count
        self._assert_message = message
        return self

    def apply_to_root(self, tree_root, parser):
        """apply_to_root applies a selector to the AST root, rather than its base node

        Note that this is different from the apply() method because that one has an expected
        rule context to be passed as the base node, whereas you just need the tree root for this method
        """
        bases = XPath.XPath.findAll(tree_root, self.BASE_PATH, parser)
        result = []
        for base in bases:
            result.extend(self.apply(base, parser))
        return result

    def apply(self, base, parser):
        """apply runs selector as well as any chained selectors

        :param base: object, base of tree to search
        :param parser: object, parser that built the tree
        :return: list, list of nodes that were selected
        """
        selected_nodes = self._select(base, parser)
        if self._assert_count is not None and len(selected_nodes) != self._assert_count:
            raise Exception(f'Failed selector count assertion: {self._assert_message}')

        if not self._chained_selector:
            return selected_nodes

        selected_and_chained_nodes = []
        for node in selected_nodes:
            selected_and_chained_nodes += self._chained_selector.apply(
                node, parser)

        return selected_and_chained_nodes

    def chain(self, selector):
        """chain chains a selector after this one

        :param selector: object, selector to chain after this one is applied
        :return: object, returns self
        """
        if self._chained_selector is None:
            self._chained_selector = selector
        else:
            self._chained_selector.chain(selector)

        return self


class ComponentDeclarationByTypeSelector(Selector):
    """ComponentDeclarationByIdentitySelector is a selector which returns component
    declarations that match the given constraints
    """
    BASE_PATH = 'stored_definition/class_definition/class_specifier/long_class_specifier/composition/element_list/element/component_clause'

    def __init__(self, type_name):
        self._type_name = type_name
        super().__init__()

    def _select(self, base, parser):
        # type_specifier is second child
        type_specifier = base.type_specifier()
        if type_specifier.getText() != self._type_name:
            return []

        xpath = 'component_clause/component_list/component_declaration'
        return XPath.XPath.findAll(base, xpath, parser)


class ComponentDeclarationByIdentifierSelector(Selector):
    """ComponentDeclarationByIdentitySelector is a selector which returns component
    declarations that match the given constraints
    """
    BASE_PATH = 'stored_definition/class_definition/class_specifier/long_class_specifier/composition/element_list/element/component_clause/component_declaration'

    def __init__(self, identifier):
        self._identifier = identifier
        super().__init__()

    def _select(self, base, parser):
        declaration_text = base.declaration().IDENT().getText()
        return [base] if declaration_text == self._identifier else []


class ComponentDeclarationSelector(Selector):
    """ComponentDeclarationSelector is a selector which matches component declarations
    based on their type and/or identifier
    """
    BASE_PATH = 'stored_definition/class_definition/class_specifier/long_class_specifier/composition/element_list/element/component_clause'

    def __init__(self, type_name=None, identifier=None):
        self._type_name = type_name
        self._identifier = identifier

        super().__init__()

    def _select(self, base, parser):
        # check the type
        type_specifier = base.type_specifier()
        if self._type_name is not None and type_specifier.getText() != self._type_name:
            return []

        # select the declaration(s)
        xpath = 'component_clause/component_list/component_declaration'
        component_declaration_nodes = XPath.XPath.findAll(base, xpath, parser)

        if self._identifier is None:
            return component_declaration_nodes

        # filter component_declaration nodes if identifier was provided
        return [
            node
            for node in component_declaration_nodes
            if node.declaration().IDENT().getText() == self._identifier]


class ComponentModificationValueSelector(Selector):
    """ComponentModificationSelector returns modifications to component
    declarations
    """
    BASE_PATH = 'stored_definition/class_definition/class_specifier/long_class_specifier/composition/element_list/element/component_clause/component_list/component_declaration'

    def __init__(self, modification_name, modification_value=None):
        """
        :param modification_name: str, mane of the modification to select
        :param modification_value: None | str, if not None, it only selects modifications with this value
        """

        self._modification_name = modification_name
        self._modification_value = modification_value
        super().__init__()

    def _select(self, base, parser):
        xpath = 'component_declaration/declaration/modification/class_modification/argument_list/argument/element_modification_or_replaceable/element_modification'
        element_modifications = XPath.XPath.findAll(base, xpath, parser)

        # filter modifications (ie arguments) to those that match our name
        filtered_modifications = []
        for element_modification in element_modifications:
            modification_name_text = element_modification.name().getText()
            if modification_name_text == self._modification_name:
                filtered_modifications.append(element_modification)

        # get the argument expressions (ie argument values)
        results = []
        for element_modification in filtered_modifications:
            xpath = '//expression'
            results.extend(XPath.XPath.findAll(element_modification, xpath, parser))

        # filter out non-matching values if modification_value is specified
        if self._modification_value is not None:
            filtered_results = []
            for result in results:
                a = result.getText()
                b = self._modification_value
                if re.sub(r"\s*", "", a) == re.sub(r"\s*", "", b):
                    filtered_results.append(result)
            results = filtered_results

        return results


class ComponentModificationNameSelector(Selector):
    """ComponentModificationSelector returns modifications to component
    declarations
    """
    BASE_PATH = 'stored_definition/class_definition/class_specifier/long_class_specifier/composition/element_list/element/component_clause/component_list/component_declaration'

    def __init__(self, argument_name):
        """
        :param modification_name: str, mane of the modification to select
        """

        self.argument_name = argument_name
        super().__init__()

    def _select(self, base, parser):
        xpath = 'component_declaration/declaration/modification/class_modification/argument_list/argument/element_modification_or_replaceable/element_modification'
        element_modifications = XPath.XPath.findAll(base, xpath, parser)

        # filter modifications (ie arguments) to those that match our name
        filtered_modifications = []
        for element_modification in element_modifications:
            argument_name_text = element_modification.name().getText()
            if argument_name_text == self.argument_name:
                filtered_modifications.append(element_modification)

        # get the argument names
        results = []
        for element_modification in filtered_modifications:
            xpath = '//name'
            results.extend(XPath.XPath.findAll(element_modification, xpath, parser))

        return results


class ComponentArgumentSelector(Selector):
    """ComponentArgumentSelector returns the parameter/arugment of a component out of the list
    including the trailing or leading comma (terminal node impl). This works only for deletion!
    """

    BASE_PATH = 'stored_definition/class_definition/class_specifier/long_class_specifier/composition/element_list/element/component_clause/component_list/component_declaration'

    def __init__(self, argument_name):
        """
        :param argument_name: str, name of the argument to select
        """

        self._argument_name = argument_name
        super().__init__()

    def _select(self, base, parser):
        xpath = 'component_declaration/declaration/modification/class_modification/argument_list'
        element_modifications = XPath.XPath.findAll(base, xpath, parser)

        # filter modifications (ie arguments) to those that match our name
        # check if the first child node is the argument of interest
        xpath = 'argument/element_modification_or_replaceable/element_modification'
        filtered_modifications = []
        for element_modification in element_modifications:
            for index, child in enumerate(element_modification.children):
                argument_name_texts = XPath.XPath.findAll(child, xpath, parser)
                # should only be one, if there isn't one, then skip, otherwise error
                if len(argument_name_texts) == 1:
                    if argument_name_texts[0].name().getText() == self._argument_name:
                        filtered_modifications.append(child)
                        if len(element_modification.children) > 1:
                            if index == 0:
                                # grab the next comma / terminal node
                                filtered_modifications.append(element_modification.children[index + 1])
                            else:
                                filtered_modifications.append(element_modification.children[index - 1])

        return filtered_modifications


class ConnectClauseSelector(Selector):
    """ConnectClauseSelector is a Selector which returns connect clauses"""
    BASE_PATH = 'stored_definition/class_definition/class_specifier/long_class_specifier/composition/equation_section/equation/connect_clause'

    def __init__(self, port_a='*', port_b='*'):
        """Allowed patterns for ports:
          - '*': matches all
          - '!': prepended to a name indicates it should match everything but that name

        :param port_a: string, identifier to match for first port
        :param port_b: string, identifier to match for second port
        """

        if port_a.startswith('!'):
            self._port_a = port_a[1:]
            self._port_a_negated = True
        else:
            self._port_a = port_a
            self._port_a_negated = False

        if port_b.startswith('!'):
            self._port_b = port_b[1:]
            self._port_b_negated = True
        else:
            self._port_b = port_b
            self._port_b_negated = False

        super().__init__()

    def _select(self, base, parser):
        # check port a
        port_a_node = base.getChild(2)
        port_a_matches = self._port_a == port_a_node.getText()
        if self._port_a_negated:
            port_a_matches = not port_a_matches
        if self._port_a != '*' and not port_a_matches:
            return []

        # check port b
        port_b_node = base.getChild(4)
        port_b_matches = self._port_b == port_b_node.getText()
        if self._port_b_negated:
            port_b_matches = not port_b_matches
        if self._port_b != '*' and not port_b_matches:
            return []

        return [base]


class ElementListSelector(Selector):
    """ElementListSelector is a selector which returns the element list"""
    BASE_PATH = 'stored_definition/class_definition/class_specifier/long_class_specifier/composition/element_list'

    def _select(self, base, parser):
        return [base]


class ParentSelector(Selector):
    """ParentSelector selects the parent"""

    def _select(self, base, parser):
        if base.parentCtx:
            return [base.parentCtx]
        return []


class NthChildSelector(Selector):
    def __init__(self, n):
        """NthChildSelector is a selector which returns the nth child

        :param n: int, child's index. If n < 0, it selects the last child
        """
        self._idx = n
        super().__init__()

    def _select(self, base, parser):
        idx = self._idx
        if self._idx < 0:
            # get last child's index
            idx = base.getChildCount() - 1

        child = base.getChild(idx)
        if child is None:
            return []
        return [child]


class EquationSectionSelector(Selector):
    BASE_PATH = 'stored_definition/class_definition/class_specifier/long_class_specifier/composition/equation_section'

    def _select(self, base, parser):
        return [base]


class WithinSelector(Selector):
    BASE_PATH = 'stored_definition/within_statement'

    def _select(self, base, parser):
        return [base]


class ModelIdentifierSelector(Selector):
    BASE_PATH = 'stored_definition/class_definition/class_specifier/long_class_specifier'

    def _select(self, base, parser):
        # return both identifiers
        # (first is the initial declaration second is the 'end <modelname>')
        return [base.IDENT()[0], base.IDENT()[1]]


class ComponentRedeclarationSelector(Selector):
    """ComponentRedeclarationSelector selects a component's redeclare package string
    """
    BASE_PATH = 'stored_definition/class_definition/class_specifier/long_class_specifier/composition/element_list/element/component_clause/component_list/component_declaration'

    def __init__(self):
        """
        :param modification_name: str, mane of the modification to select
        :param modification_value: None | str, if not None, it only selects modifications with this value
        """

        super().__init__()

    def _select(self, base, parser):
        # select the element_reclaration's short_class_specifier
        xpath = 'component_declaration/declaration/modification/class_modification/argument_list/argument/element_redeclaration/short_class_definition/short_class_specifier'
        element_modifications = XPath.XPath.findAll(base, xpath, parser)

        return element_modifications
