# This example changes the initialization of the ElectroMechanicalElement "EM"
# argument "k"

import os
from unittest import TestCase

from modelica_builder.transformation import ReplaceComponentArgumentValueByType
from modelica_builder.transformer import Transformer


class TestComponents(TestCase):
    def setUp(self):
        self.data_dir = os.path.join(os.path.dirname(__file__), 'data')
        self.output_dir = os.path.join(os.path.dirname(__file__), 'output')
        if not os.path.exists(self.output_dir):
            os.makedirs(self.output_dir)

    def test_change_arg(self):
        # Build the transformations
        transformation = ReplaceComponentArgumentValueByType(
            "ElectroMechanicalElement", "k", "8"
        )

        # create the list of transformations to run
        transformer = Transformer()
        transformer.add(transformation)

        result = transformer.execute(os.path.join(self.data_dir, 'DCMotor.mo'))

        # original doesn't exist, new one exists
        self.assertNotIn('ElectroMechanicalElement EM(k=10, J=10, b=2);', result)
        self.assertIn('ElectroMechanicalElement EM(k=8, J=10, b=2);', result)

        # write the new file to disk
        with open(os.path.join(self.output_dir, 'DCMotor_01.mo'), 'w') as file:
            file.write(result)

        self.assertTrue(os.path.exists(os.path.join(self.output_dir, 'DCMotor_01.mo')))
