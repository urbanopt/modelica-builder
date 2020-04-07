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
        self._transformations = {}

    def add(self, transformation):
        """add adds a transformation to be applied

        :param transformation: Transformation
        """
        # create the edits for the transformation
        edits = []
        selected_nodes = transformation.selector.apply(self._tree, self._parser)
        for node in selected_nodes:
            edits.append(transformation.edit(node))

        self._transformations[transformation] = edits

    def execute(self):
        """execute applies transformations to a file and returns the result as a string

        :return: string, transformed source
        """
        # sort and apply edits in reverse to avoid changing token offsets
        # in the edited file
        all_edits = [edits for _, edits in self._transformations.items()]
        # flatten the list
        all_edits = [edit
                     for transformation_edits in all_edits
                     for edit in transformation_edits]

        all_edits.sort()
        with open(self._source, 'r') as f:
            return Edit.apply_edits(
                reversed(all_edits),
                f.read())
