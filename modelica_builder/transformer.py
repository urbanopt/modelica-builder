"""
****************************************************************************************************
:copyright (c) 2020, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""


from modelica_builder.edit import Edit
from modelica_builder.modelica_parser import parse


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

    def execute(self):
        """execute applies transformations to a file and returns the result as a string

        :return: string, transformed source
        """
        all_edits = []
        # apply selectors and build edits
        for transformation in self._transformations:
            selected_nodes = self.apply_selector(transformation.selector)
            all_edits += [transformation.edit(node) for node in selected_nodes]

        # apply the edits
        with open(self._source, 'r') as f:
            return Edit.apply_edits(all_edits, f.read())
