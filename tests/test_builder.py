"""
****************************************************************************************************
:copyright (c) 2020-2021, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""


# -*- coding: utf-8 -*-

import os

import pytest

from modelica_builder.builder import ComponentBuilder
from modelica_builder.transformer import Transformer

from .tests import get_diffs


@pytest.mark.parametrize("test_file", ["DCMotor.mo", "DCMotorCRLF.mo"])
class TestComponentBuilder:
    @classmethod
    def setup_class(cls):
        cls.data_dir = os.path.join(os.path.dirname(__file__), 'data')
        cls.output_dir = os.path.join(os.path.dirname(__file__), 'output')
        if not os.path.exists(cls.output_dir):
            os.makedirs(cls.output_dir)

    def test_component_builder_at_index_0(self, test_file):
        # Setup
        insert_index = 0

        # Act
        component_builder = ComponentBuilder(insert_index=insert_index, type_='CustomType', identifier='MyComponent')
        component_builder.set_modification('k', 10)
        component_builder.add_annotation('Placement(transformation(extent{{10, 16}, {0, 26}}))')

        transformer = Transformer(os.path.join(self.data_dir, test_file))
        transformer.add(component_builder.transformation())

        result = transformer.execute()

        # Assert
        # write the new file to disk
        with open(os.path.join(self.output_dir, 'DCMotor_component_builder_0.mo'), 'w') as file:
            file.write(result)

        with open(os.path.join(self.data_dir, test_file), 'r') as f:
            diffs = get_diffs(f.readlines(), result.splitlines(keepends=True))

            assert 1 == len(diffs['additions']), f'should have 1 addition, has these: {diffs["additions"]}'
            assert 0 == len(diffs['deletions']), f'should have 0 deletions, has these: {diffs["deletions"]}'

            assert 'CustomType MyComponent(k=10) annotation(Placement(transformation(extent{{10, 16}, {0, 26}}))' in diffs['additions'][0]

    def test_component_builder_at_index_1(self, test_file):
        # Setup
        insert_index = 1

        # Act
        component_builder = ComponentBuilder(insert_index=insert_index, type_='CustomType', identifier='MyComponent')
        component_builder.set_modification('k', 10)
        component_builder.add_annotation('Placement(transformation(extent{{10, 16}, {0, 26}}))')

        transformer = Transformer(os.path.join(self.data_dir, test_file))
        transformer.add(component_builder.transformation())

        result = transformer.execute()

        # Assert
        # write the new file to disk
        with open(os.path.join(self.output_dir, 'DCMotor_component_builder_1.mo'), 'w') as file:
            file.write(result)

        with open(os.path.join(self.data_dir, test_file), 'r') as f:
            diffs = get_diffs(f.readlines(), result.splitlines(keepends=True))

            assert 1 == len(diffs['additions']), f'should have 1 addition, has these: {diffs["additions"]}'
            assert 0 == len(diffs['deletions']), f'should have 0 deletions, has these: {diffs["deletions"]}'

            assert 'CustomType MyComponent(k=10) annotation(Placement(transformation(extent{{10, 16}, {0, 26}}))' in diffs['additions'][0]

    def test_component_builder_at_end(self, test_file):
        # Setup
        insert_index = 0

        # Act
        component_builder = ComponentBuilder(insert_index=insert_index, type_='CustomType', identifier='MyComponent')
        component_builder.set_modification('k', 10)
        component_builder.add_annotation('Placement(transformation(extent{{10, 16}, {0, 26}}))')

        transformer = Transformer(os.path.join(self.data_dir, test_file))
        transformer.add(component_builder.transformation())

        result = transformer.execute()

        # Assert
        # write the new file to disk
        with open(os.path.join(self.output_dir, 'DCMotor_component_builder_at_end.mo'), 'w') as file:
            file.write(result)

        with open(os.path.join(self.data_dir, test_file), 'r') as f:
            diffs = get_diffs(f.readlines(), result.splitlines(keepends=True))

            assert 1 == len(diffs['additions']), f'should have 1 addition, has these: {diffs["additions"]}'
            assert 0 == len(diffs['deletions']), f'should have 0 deletions, has these: {diffs["deletions"]}'

            assert 'CustomType MyComponent(k=10) annotation(Placement(transformation(extent{{10, 16}, {0, 26}}))' in diffs['additions'][0]
