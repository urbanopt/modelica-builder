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
        model.insert_component(0, 'FancyClass', 'myInstance', {'arg1': '1234'}, ['my annotation'])
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['FancyClass myInstance(arg1=1234) annotation(my annotation);'])
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
