"""
****************************************************************************************************
:copyright (c) 2020, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""


from modelica_builder.edit import Edit
from modelica_builder.modelica_parser import parse
from modelica_builder.modelica_parser.modelicaParser import modelicaParser


class Transformer:
    """Transformer collects transformations and applies them to files"""

    def __init__(self, source, use_cpp=True):
        self._source = source
        self._tree, self._parser = parse(source, use_cpp)
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
            all_edits += transformation.build_edits(self._tree, self._parser)

        # apply the edits
        with open(self._source, 'r') as f:
            return Edit.apply_edits(all_edits, f.read())
