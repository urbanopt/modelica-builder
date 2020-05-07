"""
****************************************************************************************************
:copyright (c) 2020, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""


import os
from unittest import TestCase

from modelica_builder.model import Model

from .tests import DiffAssertions


class TestModel(TestCase, DiffAssertions):
    def setUp(self):
        self.result = None
        self.data_dir = os.path.join(os.path.dirname(__file__), 'data')
        self.output_dir = os.path.join(os.path.dirname(__file__), 'output')
        if not os.path.exists(self.output_dir):
            os.makedirs(self.output_dir)

    def tearDown(self):
        if self.result is not None:
            test_name = self.id().split('.')[-1]
            with open(os.path.join(self.output_dir, f'{test_name}__result.txt'), 'w') as f:
                f.write(self.result)

    def test_get_name(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        name = model.get_name()

        # Assert
        self.assertEqual('DCMotor', name)

    def test_set_name(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.set_name('NewModelName')
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['model NewModelName', 'end NewModelName'])
        self.assertHasDeletions(source_file, self.result, ['model DCMotor', 'end DCMotor'])

    def test_set_within_statement(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.set_within_statement('A.B.C')
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['within A.B.C;'])
        self.assertHasDeletions(source_file, self.result, ['within models;'])

    def test_model_add_connect(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.add_connect('PortA', 'PortB')
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['connect(PortA, PortB);'])
        self.assertNoDeletions(source_file, self.result)

    def test_model_remove_connect_specific(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.remove_connect('DC.p', 'R.n')
        self.result = model.execute()

        # Assert
        self.assertNoAdditions(source_file, self.result)
        self.assertHasDeletions(source_file, self.result, ['connect(DC.p, R.n);'])

    def test_model_edit_connect_both_ports(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.edit_connect('DC.p', 'R.n', new_port_a='PortA', new_port_b='PortB')
        self.result = model.execute()

        # Assert
        expected_additions = [
            'connect(PortA, PortB);',
        ]
        self.assertHasAdditions(source_file, self.result, expected_additions)

        expected_deletions = [
            'connect(DC.p, R.n);'
        ]
        self.assertHasDeletions(source_file, self.result, expected_deletions)

    def test_model_edit_connect_one_port(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.edit_connect('DC.p', 'R.n', new_port_a='PortA')
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['connect(PortA, R.n);'])
        self.assertHasDeletions(source_file, self.result, ['connect(DC.p, R.n);'])

    def test_model_edit_connect_match_star(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.edit_connect('*', 'R.n', new_port_b='PortB')
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['connect(DC.p, PortB);'])
        self.assertHasDeletions(source_file, self.result, ['connect(DC.p, R.n);'])

    def test_model_edit_connect_negated_match(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        # replace connections where port a is fake_port_a and port b is not fake_port_b
        model.edit_connect('fake_port_a', '!fake_port_b', new_port_b='PortC')
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['connect(fake_port_a, PortC);'])
        self.assertHasDeletions(source_file, self.result, ['connect(fake_port_a, fake_port_c);'])

    def test_model_edit_connect_bad_edit(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act, Assert
        # not allowed to replace a wildcard port (could result in duplicate connects)
        with self.assertRaises(Exception):
            model.edit_connect('*', 'R.n', new_port_a='PortA')

    def test_model_insert_component(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.insert_component('FancyClass', 'myInstance',
                               arguments={'arg1': '1234'}, string_comment='my comment',
                               annotations=['my annotation'], insert_index=0)
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['FancyClass myInstance(arg1=1234) "my comment" annotation(my annotation);'])
        self.assertNoDeletions(source_file, self.result)

    def test_model_remove_component(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.remove_component('Resistor', 'R')
        self.result = model.execute()

        # Assert
        self.assertNoAdditions(source_file, self.result)
        self.assertHasDeletions(source_file, self.result, ['Resistor R(R=100);'])

    def test_model_update_component_argument(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.update_component_argument('Resistor', 'R', 'R', '54321')
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['Resistor R(R=54321);'])
        self.assertHasDeletions(source_file, self.result, ['Resistor R(R=100);'])

    def test_model_update_component_argument_conditional_true(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.update_component_argument('Resistor', 'R', 'R', '54321', if_value='100')
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['Resistor R(R=54321);'])
        self.assertHasDeletions(source_file, self.result, ['Resistor R(R=100);'])

    def test_model_update_component_argument_conditional_true_w_whitespace(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.update_component_argument('Resistor', 'R', 'R', '54321', if_value='  100\n')
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['Resistor R(R=54321);'])
        self.assertHasDeletions(source_file, self.result, ['Resistor R(R=100);'])

    def test_model_update_component_argument_conditional_false(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.update_component_argument('Resistor', 'R', 'R', '54321', if_value='bogus_value')
        self.result = model.execute()

        # Assert
        self.assertNoAdditions(source_file, self.result)
        self.assertNoDeletions(source_file, self.result)

    def test_model_add_param(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.add_parameter('Real', 'myParam', string_comment='a comment', assigned_value=1.25)
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['parameter Real myParam=1.25 "a comment"'])
        self.assertNoDeletions(source_file, self.result)
