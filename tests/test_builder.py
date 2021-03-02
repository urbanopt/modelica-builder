"""
****************************************************************************************************
:copyright (c) 2020-2021, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""


# -*- coding: utf-8 -*-

import os
from unittest import TestCase

from modelica_builder.builder import ComponentBuilder
from modelica_builder.transformer import Transformer

from .tests import get_diffs


class TestComponentBuilder(TestCase):
    def setUp(self):
        self.data_dir = os.path.join(os.path.dirname(__file__), 'data')
        self.output_dir = os.path.join(os.path.dirname(__file__), 'output')
        if not os.path.exists(self.output_dir):
            os.makedirs(self.output_dir)

    def test_component_builder_at_index_0(self):
        # Setup
        insert_index = 0

        # Act
        component_builder = ComponentBuilder(insert_index=insert_index, type_='CustomType', identifier='MyComponent')
        component_builder.set_modification('k', 10)
        component_builder.add_annotation('Placement(transformation(extent{{10, 16}, {0, 26}}))')

        transformer = Transformer(os.path.join(self.data_dir, 'DCMotor.mo'))
        transformer.add(component_builder.transformation())

        result = transformer.execute()

        # Assert
        # write the new file to disk
        with open(os.path.join(self.output_dir, 'DCMotor_component_builder_0.mo'), 'w') as file:
            file.write(result)

        with open(os.path.join(self.data_dir, 'DCMotor.mo'), 'r') as f:
            diffs = get_diffs(f.readlines(), result.splitlines(keepends=True))

            self.assertEqual(1, len(diffs['additions']), f'should have 1 addition, has these: {diffs["additions"]}')
            self.assertEqual(0, len(diffs['deletions']), f'should have 0 deletions, has these: {diffs["deletions"]}')

            self.assertIn('CustomType MyComponent(k=10) annotation(Placement(transformation(extent{{10, 16}, {0, 26}}))', diffs['additions'][0])

    def test_component_builder_at_index_1(self):
        # Setup
        insert_index = 1

        # Act
        component_builder = ComponentBuilder(insert_index=insert_index, type_='CustomType', identifier='MyComponent')
        component_builder.set_modification('k', 10)
        component_builder.add_annotation('Placement(transformation(extent{{10, 16}, {0, 26}}))')

        transformer = Transformer(os.path.join(self.data_dir, 'DCMotor.mo'))
        transformer.add(component_builder.transformation())

        result = transformer.execute()

        # Assert
        # write the new file to disk
        with open(os.path.join(self.output_dir, 'DCMotor_component_builder_1.mo'), 'w') as file:
            file.write(result)

        with open(os.path.join(self.data_dir, 'DCMotor.mo'), 'r') as f:
            diffs = get_diffs(f.readlines(), result.splitlines(keepends=True))

            self.assertEqual(1, len(diffs['additions']), f'should have 1 addition, has these: {diffs["additions"]}')
            self.assertEqual(0, len(diffs['deletions']), f'should have 0 deletions, has these: {diffs["deletions"]}')

            self.assertIn('CustomType MyComponent(k=10) annotation(Placement(transformation(extent{{10, 16}, {0, 26}}))', diffs['additions'][0])

    def test_component_builder_at_end(self):
        # Setup
        insert_index = 0

        # Act
        component_builder = ComponentBuilder(insert_index=insert_index, type_='CustomType', identifier='MyComponent')
        component_builder.set_modification('k', 10)
        component_builder.add_annotation('Placement(transformation(extent{{10, 16}, {0, 26}}))')

        transformer = Transformer(os.path.join(self.data_dir, 'DCMotor.mo'))
        transformer.add(component_builder.transformation())

        result = transformer.execute()

        # Assert
        # write the new file to disk
        with open(os.path.join(self.output_dir, 'DCMotor_component_builder_at_end.mo'), 'w') as file:
            file.write(result)

        with open(os.path.join(self.data_dir, 'DCMotor.mo'), 'r') as f:
            diffs = get_diffs(f.readlines(), result.splitlines(keepends=True))

            self.assertEqual(1, len(diffs['additions']), f'should have 1 addition, has these: {diffs["additions"]}')
            self.assertEqual(0, len(diffs['deletions']), f'should have 0 deletions, has these: {diffs["deletions"]}')

            self.assertIn('CustomType MyComponent(k=10) annotation(Placement(transformation(extent{{10, 16}, {0, 26}}))', diffs['additions'][0])
