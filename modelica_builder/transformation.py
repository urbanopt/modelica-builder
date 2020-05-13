"""
****************************************************************************************************
:copyright (c) 2020, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""


from collections import namedtuple

from modelica_builder.edit import Edit
from modelica_builder.selector import (
    ComponentArgumentValueSelector,
    ComponentDeclarationByTypeSelector
)


class SimpleTransformation:
    """SimpleTransformation creates edits using a selector and edit"""
    def __init__(self, selector, edit):
        self.selector = selector
        self.edit = edit

    def build_edits(self, tree, parser):
        edits = []
        for selected_node in self.selector.apply_to_root(tree, parser):
            edits.append(self.edit(selected_node))

        return edits
