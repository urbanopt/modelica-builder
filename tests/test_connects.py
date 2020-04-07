"""
****************************************************************************************************
:copyright (c) 2020, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""


# -*- coding: utf-8 -*-

import os
from unittest import TestCase

from modelica_builder.edit import Edit
from modelica_builder.selector import ConnectClauseSelector, Selector, select
from modelica_builder.transformation import Transformation
from modelica_builder.transformer import Transformer


# TODO: Can we move this to a more general location, it seems useful as a function within
# the library.
class ComponentReferenceSelector(Selector):
    def __init__(self, component_identifier):
        self._component_identifier = component_identifier
        super().__init__()

    def _select(self, root, parser):
        nodes = select(root, parser, 'component_reference')

        # filter out non matching component references
        return [
            node
            for node in nodes
            if node.getText() == self._component_identifier]


class TestConnects(TestCase):
    def setUp(self):
        self.data_dir = os.path.join(os.path.dirname(__file__), 'data')
        self.output_dir = os.path.join(os.path.dirname(__file__), 'output')
        if not os.path.exists(self.output_dir):
            os.makedirs(self.output_dir)

    def test_connect(self):
        # select connect clause component reference of "DC.p"
        selector = (ConnectClauseSelector().chain(ComponentReferenceSelector('DC.p')))

        # replace our selected nodes with DC.n
        transformation = Transformation(selector, Edit.make_replace('DC.n'))
        transformer = Transformer(os.path.join(self.data_dir, 'DCMotor.mo'))
        transformer.add(transformation)

        result = transformer.execute()

        # original doesn't exist, new one exists
        self.assertNotIn('connect(DC.p, R.n);', result)
        self.assertIn('connect(DC.n, R.n);', result)

        # write the new file to disk
        with open(os.path.join(self.output_dir, 'DCMotor_02.mo'), 'w') as file:
            file.write(result)
