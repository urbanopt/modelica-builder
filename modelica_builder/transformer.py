"""
****************************************************************************************************
:copyright (c) 2020, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""


from modelica_builder.edit import Edit
from modelica_builder.modelica_parser import parse
from modelica_builder.modelica_parser.modelicaParser import ParseTreeWalker


class SelectorListener:
    """SelectorListener is a collection of selectors which are applied by walking
    the tree. It is to be used by passing it to an antlr4 ParseTreeWalker's walk method
    """

    def __init__(self, parser):
        self._parser = parser
        self._selection_results = {}
        self._rule_selectors = {}

    def add_selector(self, selector):
        """add_selector registers a selector

        :param selector: Selector
        """
        # get the last node in the path
        selector_base = selector.get_base_rule()

        rule_method = f'enter{selector_base.capitalize()}'
        if rule_method in self._rule_selectors:
            self._rule_selectors[rule_method].append(selector)
        else:
            self._rule_selectors[rule_method] = [selector]

    def get_result(self, selector):
        """get_result returns results of a selector, if the listener has walked the tree

        :param selector: Selector
        :return: list, list of selected nodes
        """
        return self._selection_results.get(selector, [])

    def __getattr__(self, name):
        """this is how the class functions like an antlr4 listener. The walker
        we are passed to will call enter<rule_name> for each node in the tree it
        visits. If we've registered any selectors for that method, we call them
        and add their results to our selection results for later retrieval
        """
        def noop(_):
            pass

        if name not in self._rule_selectors:
            return noop

        def handle_rule(ctx):
            for handler in self._rule_selectors[name]:
                result = handler.apply(ctx, self._parser)
                if handler in self._selection_results:
                    self._selection_results[handler].extend(result)
                else:
                    self._selection_results[handler] = result

        return handle_rule


class Transformer:
    """Transformer collects transformations and applies them to files"""

    def __init__(self, source):
        self._source = source
        self._tree, self._parser = parse(source)
        self._transformations = []
        self._listener = None

    def apply_selector(self, selector):
        return selector.apply_to_root(self._tree, self._parser)

    def add(self, transformation):
        """add adds a transformation to be applied

        :param transformation: Transformation
        """
        self._transformations.append(transformation)

    def execute(self, walk_tree=False):
        """execute applies transformations to a file and returns the result as a string

        :return: string, transformed source
        """
        if walk_tree:
            # build the listener
            self._listener = SelectorListener(self._parser)
            for transformation in self._transformations:
                self._listener.add_selector(transformation.selector)

            # walk the tree with our listener
            walker = ParseTreeWalker()
            walker.walk(self._listener, self._tree)

            # build edits from the selected nodes
            all_edits = []
            for transformation in self._transformations:
                selected_nodes = self._listener.get_result(transformation.selector)
                edits = [transformation.edit(node) for node in selected_nodes]
                all_edits += edits
        else:
            all_edits = []
            # apply selectors and build edits
            for transformation in self._transformations:
                selected_nodes = self.apply_selector(transformation.selector)
                all_edits += [transformation.edit(node) for node in selected_nodes]

        # sort the edits
        all_edits.sort()
        with open(self._source, 'r') as f:
            return Edit.apply_edits(
                reversed(all_edits),
                f.read())
