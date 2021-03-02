"""
****************************************************************************************************
:copyright (c) 2020-2021, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""

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
