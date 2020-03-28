from abc import ABC, abstractmethod

from antlr4.xpath import XPath


def select(root, parser, rule, child=None, child_value=None):
    """select selects the rule in AST that has a child with child_value
    If child is None, then it just returns the matched rule nodes
    e.g. select a component declaration whose identifier is
    thermalZoneTwoElements

    :param root: object, tree to search
    :param parser: object, parser that generated the tree
    :param rule: string, name of node to search for
    :param child: string, (optional) name of direct descendant used to filter nodes by inspecting it's text
    :param child_value: (optional) string, value to match text to
    """
    matches = XPath.XPath.findAll(root, f'//{rule}', parser)
    if len(matches) == 0:
        return []

    # check if the nodes should be filtered
    if child is None:
        return matches

    def child_missing():
        return []

    results = []
    for match in matches:
        # this works b/c nodes of AST are ParserRuleContext, and calling child
        # node as a method returns that context
        children = getattr(match, child, child_missing)()

        # possible for match to have multiple children of the same type
        # e.g. connect_clause has two component_reference, so treat result as a
        # list
        if not isinstance(children, list):
            children = [children]

        # filter this match based on child condition
        for _child in children:
            val = _child.getText()
            if val == child_value:
                results.append(match)

    return results


def select_path(root, parser, path):
    """select_path selects nodes based on a series of node selectors

    Example:
    select_path(
        root,
        parser,
        [
            {
                # get component
                'rule': 'declaration',
                'child': 'IDENT',
                'child_value': self._component_identifier
            },
            {
                # get argument
                'rule': 'element_modification',
                'child': 'name',
                'child_value': self._argument_name
            },
            {
                # get argument value
                'rule': 'expression',
                'child': None,
                'child_value': None
            }
        ]
    )

    :param root: object, tree root to search
    :param parser: object, parser that made the tree
    :param path: list of dicts, sparse path to a node
    """
    selectors = path

    selected_nodes = [root]
    # for each selector, apply it to our selected nodes
    for selector in selectors:
        # early exit if search ends
        if not selected_nodes:
            return []

        new_roots = []
        for node in selected_nodes:
            new_roots += select(
                node,
                parser,
                selector['rule'],
                selector.get('child'),
                selector.get('child_value'))

        selected_nodes = new_roots

    return selected_nodes


class Selector(ABC):
    """Selector is the base class for all selectors"""
    def __init__(self):
        self._chained_selector = None
        self._assert_count = None
        self._assert_message = None

    @abstractmethod
    def _select(self, root, parser):
        """_select should be overridden when implementing a Selector

        :param root: object, root of tree to search
        :param parser: object, parser that built the tree
        :return: list, list of nodes that were selected
        """
        pass

    def assert_count(self, count, message):
        self._assert_count = count
        self._assert_message = message
        return self

    def apply(self, root, parser):
        """apply runs selector as well as any chained selectors

        :param root: object, root of tree to search
        :param parser: object, parser that built the tree
        :return: list, list of nodes that were selected
        """
        selected_nodes = self._select(root, parser)
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

    def __init__(self, type_name):
        self._type_name = type_name
        super().__init__()

    def _select(self, root, parser):
        nodes = select(
            root,
            parser,
            'component_clause',
            'type_specifier',
            self._type_name)

        results = []
        for node in nodes:
            results += select(node, parser, 'component_declaration')

        return results


class ComponentDeclarationByIdentifierSelector(Selector):
    """ComponentDeclarationByIdentitySelector is a selector which returns component
    declarations that match the given constraints
    """

    def __init__(self, identifier):
        self._identifier = identifier
        super().__init__()

    def _select(self, root, parser):
        nodes = select(root, parser, 'component_declaration')

        return [
            node
            for node in nodes
            if node.declaration().IDENT().getText() == self._identifier]


class ComponentArgumentValueSelector(Selector):
    """ComponentArgumentSelector returns arguments to component
    declarations
    """

    def __init__(self, argument_name):
        self._argument_name = argument_name
        super().__init__()

    def _select(self, root, parser):
        return select_path(
            root,
            parser,
            [
                {
                    # get argument
                    'rule': 'element_modification',
                    'child': 'name',
                    'child_value': self._argument_name
                },
                {
                    # get argument value
                    'rule': 'expression',
                    'child': None,
                    'child_value': None
                },
            ]
        )


class ConnectClauseSelector(Selector):
    """ConnectClauseSelector is a Selector which returns connect clauses"""

    def __init__(self, port_a='*', port_b='*'):
        """
        :param port_a: string, identifier to match for first port; matches all if set to '*'
        :param port_b: string, identifier to match for second port; matches all if set to '*'
        """
        self._port_a = port_a
        self._port_b = port_b
        super().__init__()

    def _select(self, root, parser):
        nodes = select(root, parser, 'connect_clause')

        # filter connect clauses
        filtered_nodes = []
        for node in nodes:
            # check port a
            port_a_node = node.getChild(2)
            if self._port_a != '*' and self._port_a != port_a_node.getText():
                continue

            # check port b
            port_b_node = node.getChild(4)
            if self._port_b != '*' and self._port_b != port_b_node.getText():
                continue

            filtered_nodes.append(node)

        return filtered_nodes


class ElementListSelector(Selector):
    """ElementListSelector is a selector which returns the element list"""

    def _select(self, root, parser):
        return select(root, parser, 'element_list')


class NthChildSelector(Selector):
    def __init__(self, n):
        """NthChildSelector is a selector which returns the nth child

        :param n: int, child's index. If n < 0, it selects the last child
        """
        self._idx = n
        super().__init__()

    def _select(self, root, parser):
        idx = self._idx
        if self._idx < 0:
            # get last child's index
            idx = root.getChildCount() - 1

        child = root.getChild(idx)
        if child is None:
            return []
        return [child]


class EquationSectionSelector(Selector):
    def _select(self, root, parser):
        return select(root, parser, 'equation_section')
