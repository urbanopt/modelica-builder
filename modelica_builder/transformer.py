"""
****************************************************************************************************
:copyright (c) 2020-2022, Alliance for Sustainable Energy, LLC.
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
            all_edits += transformation.build_edits(self._tree, self._parser)

        # apply the edits
        # Reading with newline='' lets us retain the original newline characters
        # allowing us to handle files made on Windows with \r\n
        with open(self._source, 'rt', newline='') as f:
            return Edit.apply_edits(all_edits, f.read())
