from modelica_builder.edit import Edit
from modelica_builder.modelica_parser import parse


class Transformer:
    """Transformer collects transformations and applies them to files"""
    _transformations = []
    _edits = []

    def add(self, transformation):
        """add adds a transformation to be applied

        :param transformation: Transformation
        """
        self._transformations.append(transformation)

    def _build_edits(self, tree, parser):
        """_build_edits generates edits on nodes by applying selectors

        :param tree: object, a node from Antlr AST
        :param parser: object, modelica parser
        """
        self._edits = []

        for trans in self._transformations:
            selected_nodes = trans.selector.apply(tree, parser)
            for node in selected_nodes:
                self._edits.append(trans.edit(node))

    def execute(self, source):
        """execute applies transformations to a file and returns the result as a string

        :param source: string, path to file to transform
        :return: string, transformed source
        """
        tree, parser = parse(source)

        self._build_edits(tree, parser)

        # sort and apply edits in reverse to avoid changing token offsets
        # in the edited file
        self._edits.sort()
        with open(source, 'r') as f:
            return Edit.apply_edits(
                reversed(self._edits),
                f.read())
