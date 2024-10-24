# :copyright (c) URBANopt, Alliance for Sustainable Energy, LLC, and other contributors.
# See also https://github.com/urbanopt/modelica-builder/blob/develop/LICENSE.md


import os
import tempfile
from unittest import TestCase

from modelica_builder import config
from modelica_builder.model import Model

from .tests import DiffAssertions


class TestModel(TestCase, DiffAssertions):
    def setUp(self):
        # simplify indentation to make diffing simpler
        config.INDENT_INSERTED_COMPONENT_ARGS = False
        config.INDENT_INSERTED_ANNOTATION_ARGS = False

        self.result = None
        self.data_dir = os.path.join(os.path.dirname(__file__), 'data')
        self.output_dir = os.path.join(os.path.dirname(__file__), 'output')
        if not os.path.exists(self.output_dir):
            os.makedirs(self.output_dir)

        self.tmp_file = None

    def tearDown(self):
        if self.result is not None:
            test_name = self.id().split('.')[-1]
            with open(os.path.join(self.output_dir, f'{test_name}__result.txt'), 'w') as f:
                f.write(self.result)

        # cleanup the temp file if one was created
        if self.tmp_file is not None:
            os.unlink(self.tmp_file)

    def create_tmp_file(self, file_content):
        if self.tmp_file is not None:
            os.unlink(self.tmp_file)

        tmp_fd, self.tmp_file = tempfile.mkstemp()
        os.close(tmp_fd)
        with open(self.tmp_file, 'w') as f:
            f.write(file_content)

        return self.tmp_file

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
                               modifications={'arg1': '1234'}, string_comment='my comment',
                               annotations=['my annotation'], insert_index=0)
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result,
                                ['FancyClass myInstance(arg1=1234) "my comment" annotation(my annotation);'])
        self.assertNoDeletions(source_file, self.result)

    def test_model_insert_component_multiple(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.insert_component('FancyClass', 'myInstance',
                               modifications={'arg1': '1234'}, string_comment='my comment',
                               annotations=['my annotation'])
        model.insert_component('AnotherClass', 'anotherInstance',
                               modifications={'x': '"hello"'}, string_comment='this is another class',
                               annotations=['abc'])
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, [
            'FancyClass myInstance(arg1=1234) "my comment" annotation(my annotation);',
            'AnotherClass anotherInstance(x="hello") "this is another class" annotation(abc);'])
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

    def test_model_update_component_modification(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.update_component_modification('Resistor', 'R', 'R', '54321')
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['Resistor R(R=54321);'])
        self.assertHasDeletions(source_file, self.result, ['Resistor R(R=100);'])

    def test_model_update_component_modification_conditional_true(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.update_component_modification('Resistor', 'R', 'R', '54321', if_value='100')
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['Resistor R(R=54321);'])
        self.assertHasDeletions(source_file, self.result, ['Resistor R(R=100);'])

    def test_model_update_component_modification_conditional_true_w_whitespace(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.update_component_modification('Resistor', 'R', 'R', '54321', if_value='  100\n')
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['Resistor R(R=54321);'])
        self.assertHasDeletions(source_file, self.result, ['Resistor R(R=100);'])

    def test_model_update_component_modification_conditional_false(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.update_component_modification('Resistor', 'R', 'R', '54321', if_value='bogus_value')
        self.result = model.execute()

        # Assert
        self.assertNoAdditions(source_file, self.result)
        self.assertNoDeletions(source_file, self.result)

    def test_model_add_param_type_real(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.add_parameter('Real', 'myParam', string_comment='a comment', assigned_value=1.25)
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['parameter Real myParam=1.25 "a comment"'])
        self.assertNoDeletions(source_file, self.result)

    def test_model_add_param_type_string(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.add_parameter('String', 'myParam', string_comment='a comment',
                            assigned_value='"supercalifragilisticexpialidocious"')
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result,
                                ['parameter String myParam="supercalifragilisticexpialidocious" "a comment"'])
        self.assertNoDeletions(source_file, self.result)

    def test_get_parameter_value(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'Office.mo')
        model = Model(source_file)

        # Act
        result = model.get_parameter_value('String', 'idfName')
        result_int = model.get_parameter_value('Integer', 'nPorts')
        result_real = model.get_parameter_value('Real', 'fraLat')
        result_bool = model.get_parameter_value('Boolean', 'use_moisture_balance')

        # Assert
        self.assertEqual(result, '"modelica://a_project/Loads/B123/input.idf"')
        self.assertEqual(result_int, 0)
        self.assertEqual(result_real, 1.25)
        self.assertFalse(result_bool)

    def test_model_update_param(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'Office.mo')
        model = Model(source_file)

        # Act
        model.update_parameter('String', 'idfName', '"54321"')
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['54321'])
        self.assertHasDeletions(source_file, self.result, ['modelica://a_project/Loads/B123/input.idf'])

    def test_model_redeclaration_string_replacement(self):
        """Should update redeclaration of a component"""
        # Setup
        source_file = os.path.join(self.data_dir, 'Office.mo')
        model = Model(source_file)

        # Act

        model.overwrite_component_redeclaration(
            'Buildings.ThermalZones.ReducedOrder.RC.TwoElements',
            'thermalZoneTwoElements',
            'Medium = Buildings.Media.Air',)
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['redeclare package Medium = Buildings.Media.Air'])
        self.assertHasDeletions(source_file, self.result, ['Modelica.Media.Air.DryAirNasa'])

    def test_model_redeclaration_string_no_assign_replacement(self):
        """Update a redeclare statement with a string. This is used when the
        redeclare clause doesn't have a assignment
        """
        source_file = os.path.join(self.data_dir, 'Office.mo')
        model = Model(source_file)

        # Act
        model.overwrite_component_redeclaration(
            'IDEAS.Buildings.Components.Window',
            'MMM_Fixed_3000_x_2000mm_3__WinRoom0BoQ',
            'IDEAS.Buildings.Components.Shading.Screen shaType',
            existing_redeclaration='IDEAS.Buildings.Components.Shading.None shaType',
        )
        model.overwrite_component_redeclaration(
            'IDEAS.Buildings.Components.Window',
            'MMM_Fixed_3000_x_2000mm_3__WinRoom0BoQ',
            'Something.Else Fun',
            existing_redeclaration='IDEAS.Buildings.Data.Frames.AluminiumInsulated fraType',
        )
        self.result = model.execute()

        # Debug
        # model.save_as(os.path.join(self.data_dir, 'Office2.mo'))

        # Assert
        self.assertHasAdditions(source_file, self.result,
                                ['IDEAS.Buildings.Components.Shading.Screen shaType',
                                 'redeclare Something.Else Fun'])
        self.assertHasDeletions(source_file, self.result,
                                ['IDEAS.Buildings.Components.Shading.None shaType',
                                 'redeclare IDEAS.Buildings.Data.Frames.AluminiumInsulated fraType'])

    def test_model_remove_component_argument(self):
        """Should remove an argument in an existing component."""
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.remove_component_argument('ElectroMechanicalElement', 'EM', 'J')
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['ElectroMechanicalElement EM(k=10 , b=2);'])
        self.assertHasDeletions(source_file, self.result, ['J=10'])

    def test_model_remove_component_argument_first(self):
        """Should remove an argument in an existing component."""
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.remove_component_argument('ElectroMechanicalElement', 'EM', 'k')
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['ElectroMechanicalElement EM( J=10, b=2);'])
        self.assertHasDeletions(source_file, self.result, ['k=10'])

    def test_model_remove_component_argument_last(self):
        """Should remove an argument in an existing component."""
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.remove_component_argument('ElectroMechanicalElement', 'EM', 'b')
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['ElectroMechanicalElement EM(k=10, J=10 );'])
        self.assertHasDeletions(source_file, self.result, ['b=2'])

    def test_model_remove_component_argument_all(self):
        """Should remove an argument in an existing component."""
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.remove_component_argument('VsourceDC', 'DC', 'f')
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, [' VsourceDC DC();'])
        self.assertHasDeletions(source_file, self.result, ['f=10'])

    def test_model_remove_first_component_and_add_param(self):
        """Tests that we can successfully resolve overlapping edits of a deletion
        (removing first component) and an insert (adding new param)
        """
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.remove_component('Resistor', 'R')
        model.add_parameter('Real', 'myParam', string_comment='a comment', assigned_value='10.0')
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['parameter Real myParam=10.0 "a comment"'])
        self.assertHasDeletions(source_file, self.result, ['Resistor R(R=100);'])

    def test_model_remove_constant(self):
        """Test to remove an entire component that is flagged as a constant type"""
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        model.remove_component('Integer', 'notUsed')
        self.result = model.execute()

        # Assert
        self.assertNoAdditions(source_file, self.result)
        self.assertHasDeletions(source_file, self.result, ['constant Integer notUsed=5 "unused constant that needs to be deleted";'])

    def test_model_update_annotation_when_no_model_annotation_exists(self):
        # Setup
        mo_file = '''
model Test
equation
end Test;'''
        source_file = self.create_tmp_file(mo_file)
        model = Model(source_file)

        # Act
        model.update_model_annotation({'rootModification': 100})
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['annotation(rootModification=100);'])

    def test_model_update_annotation_when_modification_exists_and_is_simple(self):
        # Setup
        mo_file = """
model Test
equation
  annotation(rootModification=321);
end Test;"""
        source_file = self.create_tmp_file(mo_file)
        model = Model(source_file)

        # Act
        model.update_model_annotation({'rootModification': 100})
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['annotation(rootModification=100);'])
        self.assertHasDeletions(source_file, self.result, ['annotation(rootModification=321);'])

    def test_model_update_annotation_when_modification_exists_and_has_own_modifications(self):
        # Setup
        mo_file = """
model Test
equation
  annotation(rootModification(childModification=321));
end Test;"""
        source_file = self.create_tmp_file(mo_file)
        model = Model(source_file)

        # Act
        model.update_model_annotation({'rootModification': {'childModification': 100}})
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, ['annotation(rootModification(childModification=100));'])
        self.assertHasDeletions(source_file, self.result, ['annotation(rootModification(childModification=321));'])

    def test_model_update_annotation_keeps_other_modifications_not_updated(self):
        # Setup
        mo_file = """
model Test
equation
  annotation(rootModification=321);
end Test;"""
        source_file = self.create_tmp_file(mo_file)
        model = Model(source_file)

        # Act
        model.update_model_annotation({'insertedModification': 555})
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result,
                                ['annotation(rootModification=321, insertedModification=555);'])
        self.assertHasDeletions(source_file, self.result, ['annotation(rootModification=321);'])

    def test_model_update_annotation_can_update_and_insert(self):
        # Setup
        mo_file = """
model Test
equation
  annotation(rootModification=321, rootModification2(childA=0, childB=1));
end Test;"""
        source_file = self.create_tmp_file(mo_file)
        model = Model(source_file)

        # Act
        model.update_model_annotation({
            'rootModification': 100,
            'insertedModification': 555,
            'rootModification2': {'childB': 123, 'childC': 'abc'}})
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, [
            'annotation(rootModification=100, rootModification2(childA=0, childB=123, childC=abc), insertedModification=555);'])
        self.assertHasDeletions(source_file, self.result,
                                ['annotation(rootModification=321, rootModification2(childA=0, childB=1));'])

    def test_model_update_annotation_and_add_connect(self):
        """Model annotation should always the last statement for the model"""
        # Setup
        mo_file = """
model Test
equation
end Test;"""
        source_file = self.create_tmp_file(mo_file)
        model = Model(source_file)

        # Act
        # make an insert before and after annotation
        model.add_connect('port_a', 'port_b')
        model.update_model_annotation({'rootModification': 100})
        model.add_connect('port_c', 'port_d')
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, [
            'annotation(rootModification=100)',
            'connect(port_a, port_b)',
            'connect(port_c, port_d)',
        ])
        self.assertNoDeletions(source_file, self.result)
        # make sure the annotation was inserted at the end
        self.assertIn('annotation(rootModification=100);\nend Test;', self.result,
                      'Annotation should be at the END of the model')

    def test_model_update_annotation_can_overwrite_existing_modifications(self):
        # Setup
        mo_file = """
model Test
equation
  annotation(rootModification=321);
end Test;"""
        source_file = self.create_tmp_file(mo_file)
        model = Model(source_file)

        # Act
        model.update_model_annotation({'modA': 100, 'OVERWRITE_MODIFICATIONS': True})
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, [
            'annotation(modA=100)',
        ])
        self.assertHasDeletions(source_file, self.result, [
            'annotation(rootModification=321);'
        ])

    def test_model_update_annotation_can_overwrite_existing_nested_modifications(self):
        """Annotation should always be at the end of the model"""
        # Setup
        mo_file = """
model Test
equation
  annotation(rootModification=321, modA(hello=100));
end Test;"""
        source_file = self.create_tmp_file(mo_file)
        model = Model(source_file)

        # Act
        model.update_model_annotation({
            'rootModification': 100,
            'modA': {'world': 555, 'OVERWRITE_MODIFICATIONS': True}})
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, [
            'annotation(rootModification=100, modA(world=555))',
        ])
        self.assertHasDeletions(source_file, self.result, [
            'annotation(rootModification=321, modA(hello=100));'
        ])

    def test_model_update_component_modifications_simple(self):
        # Setup
        mo_file = """
model Test
  Resistor R(R=100);
equation
end Test;"""
        source_file = self.create_tmp_file(mo_file)
        model = Model(source_file)

        # Act
        model.update_component_modifications(
            'Resistor', 'R', {'R': 123}
        )
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, [
            'Resistor R(R=123);',
        ])
        self.assertHasDeletions(source_file, self.result, [
            'Resistor R(R=100);'
        ])

    def test_model_rename_argument(self):
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        model.rename_component_argument(
            'ElectroMechanicalElement', 'EM', 'k', 'new_arg_name'
        )
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, [
            'new_arg_name=10',
        ])
        self.assertHasDeletions(source_file, self.result, [
            'k=10'
        ])

    def test_model_rename_argument_more_than_one_char(self):
        mo_file = """
model Test
  Resistor R(Resistance=100);
equation
end Test;"""
        source_file = self.create_tmp_file(mo_file)
        model = Model(source_file)

        model.rename_component_argument(
            'Resistor', 'R', 'Resistance', 'R'
        )
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, [
            'R=100',
        ])
        self.assertHasDeletions(source_file, self.result, [
            'Resistance=10'
        ])

    def test_model_update_component_modifications_when_modification_is_nested(self):
        # Setup
        mo_file = """
model Test
  Resistor R(root(child=100));
equation
end Test;"""
        source_file = self.create_tmp_file(mo_file)
        model = Model(source_file)

        # Act
        model.update_component_modifications(
            'Resistor', 'R', {'root': {'child': 123}}
        )
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, [
            'Resistor R(root(child=123));',
        ])
        self.assertHasDeletions(source_file, self.result, [
            'Resistor R(root(child=100));'
        ])

    def test_model_update_component_modifications_keeps_modifications_not_updated(self):
        # Setup
        mo_file = """
model Test
  Resistor R(modA=100, modB=200);
equation
end Test;"""
        source_file = self.create_tmp_file(mo_file)
        model = Model(source_file)

        # Act
        model.update_component_modifications(
            'Resistor', 'R', {'modA': 123}
        )
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, [
            'Resistor R(modA=123, modB=200);',
        ])
        self.assertHasDeletions(source_file, self.result, [
            'Resistor R(modA=100, modB=200);'
        ])

    def test_model_update_component_modifications_can_update_and_insert(self):
        # Setup
        mo_file = """
model Test
  Resistor R(modA=100, modB(modC=200));
equation
end Test;"""
        source_file = self.create_tmp_file(mo_file)
        model = Model(source_file)

        # Act
        model.update_component_modifications(
            'Resistor', 'R', {
                'modA': 123,
                'modB': {
                    'modD': 321,
                },
                'modZ': 555
            }
        )
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, [
            'Resistor R(modA=123, modB(modC=200, modD=321), modZ=555);',
        ])
        self.assertHasDeletions(source_file, self.result, [
            'Resistor R(modA=100, modB(modC=200));'
        ])

    def test_model_update_component_modifications_can_overwrite_existing_modifications(self):
        # Setup
        mo_file = """
model Test
  Resistor R(modA=100, modB=200);
equation
end Test;"""
        source_file = self.create_tmp_file(mo_file)
        model = Model(source_file)

        # Act
        model.update_component_modifications(
            'Resistor', 'R', {'modA': 123, 'OVERWRITE_MODIFICATIONS': True}
        )
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, [
            'Resistor R(modA=123);',
        ])
        self.assertHasDeletions(source_file, self.result, [
            'Resistor R(modA=100, modB=200);'
        ])

    def test_model_update_component_modifications_can_overwrite_nested_modifications(self):
        # Setup
        mo_file = """
model Test
  Resistor R(modA=100, modB(modC=200, modD=300));
equation
end Test;"""
        source_file = self.create_tmp_file(mo_file)
        model = Model(source_file)

        # Act
        model.update_component_modifications(
            'Resistor', 'R', {
                'modB': {
                    'modZ': 555,
                    'OVERWRITE_MODIFICATIONS': True
                },
            },
        )
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, [
            'Resistor R(modA=100, modB(modZ=555));',
        ])
        self.assertHasDeletions(source_file, self.result, [
            'Resistor R(modA=100, modB(modC=200, modD=300));'
        ])

    def test_model_update_component_modifications_adds_newlines_correctly(self):
        # Setup
        # NOTE: changing the indentation settings
        config.INDENT_INSERTED_COMPONENT_ARGS = True
        mo_file = """
model Test
  Resistor R(R=1);
equation
end Test;"""
        source_file = self.create_tmp_file(mo_file)
        model = Model(source_file)

        # Act
        model.update_component_modifications(
            'Resistor', 'R', {
                'modB': {
                    'modZ': 555,
                },
                'inserted': '321'
            },
        )
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, [
            'Resistor R(R=1,',
            'modB(',
            'modZ=555),',
            'inserted=321);',
        ])
        self.assertHasDeletions(source_file, self.result, [
            'Resistor R(R=1);'
        ])

    def test_model_insert_equation_for_loop_simple(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        identifier = 'i'
        expression = 'range(n_ports)'
        loop_body_list = ['connect(conArr[i], conArr[i+1]);']
        model.insert_equation_for_loop(
            index_identifier=identifier,
            expression_raw=expression,
            loop_body_raw_list=loop_body_list,
        )
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(
            source_file,
            self.result,
            loop_body_list + [
                f'for {identifier} in {expression} loop',
                'end for;'
            ])
        self.assertNoDeletions(source_file, self.result)

    def test_model_insert_equation_for_loop_multiline_body(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'DCMotor.mo')
        model = Model(source_file)

        # Act
        identifier = 'i'
        expression = 'range(n_ports)'
        loop_body_list = [
            'if i == 1 then',
            '  connect(conArr[i], conArr[i-1]);',
            'end if;',
        ]
        model.insert_equation_for_loop(
            index_identifier=identifier,
            expression_raw=expression,
            loop_body_raw_list=loop_body_list,
        )
        self.result = model.execute()

        # Assert
        # Remove the leading/training whitespace of the body lines for comparison
        # If we didn't the assert would fail (expectations are strict about whitespace)
        expected_body_additions = [line.strip() for line in loop_body_list]
        self.assertHasAdditions(
            source_file,
            self.result,
            expected_body_additions
            + [
                f'for {identifier} in {expression} loop',
                'end for;'
            ])
        self.assertNoDeletions(source_file, self.result)

    def test_model_get_argument_value(self):
        mo_file = """
model Test
  AnInstanceOfObj Obj(
    redeclare package Medium=Modelica.Media.Air.DryAirNasa,
    Resist=100,
    Desist=true,
    redeclare IDEAS.Buildings.Components.Occupants.Fixed occNum(nOccFix=25.0)
  );
equation
end Test;"""
        source_file = self.create_tmp_file(mo_file)
        model = Model(source_file)

        value = model.get_component_argument_value(
            'AnInstanceOfObj', 'Obj', 'Resist', type_cast=int
        )
        self.assertEqual(value, 100)

        value = model.get_component_argument_value(
            'AnInstanceOfObj', 'Obj', 'Resist'
        )
        self.assertEqual(value, '100')

        value = model.get_component_argument_value(
            'AnInstanceOfObj', 'Obj', 'Desist', type_cast=bool
        )
        self.assertEqual(value, True)

    def test_model_get_argument_with_array(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'district.mo')
        model = Model(source_file)

        value = model.get_component_argument_value(
            'Buildings.Controls.OBC.CDL.Continuous.Sources.Constant', 'THotWatSupSet', 'k', type_cast=str
        )
        self.assertEqual(value, 'fill(63+273.15,nBui)')

        # try setting the argument value
        model.update_component_modifications(
            'Buildings.Controls.OBC.CDL.Continuous.Sources.Constant', 'THotWatSupSet',
            {'k': 'fill(65 + 273.15, nBui)'}
        )
        self.result = model.execute()

        # Assert
        self.assertHasAdditions(source_file, self.result, [
            'fill(65 + 273.15, nBui)',
        ])
        self.assertHasDeletions(source_file, self.result, [
            'fill(63 + 273.15, nBui)'
        ])

    def test_model_update_argument_with_extends_and_redeclare(self):
        # Setup
        source_file = os.path.join(self.data_dir, 'district.mo')
        model = Model(source_file)

        model.update_extended_component_modification(
            'Buildings.Experimental.DHC.Examples.Combined.BaseClasses.PartialSeries',
            'Buildings.Experimental.DHC.Loads.Combined.BuildingTimeSeriesWithETS', 'bui',
            'datDes',
            'epsPla', '1.0', if_value='0.935'
        )
        self.result = model.execute()
        model.save_as(os.path.join(self.output_dir, 'district_updated2.mo'))

        # Assert
        self.assertHasAdditions(source_file, self.result, [
            'epsPla=1.0',
        ])
        self.assertHasDeletions(source_file, self.result, [
            'epsPla=0.935',
        ])
