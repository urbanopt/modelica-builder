# :copyright (c) URBANopt, Alliance for Sustainable Energy, LLC, and other contributors.
# See also https://github.com/urbanopt/modelica-builder/blob/develop/LICENSE.md

import json
import logging
import os
import shutil
import unittest
from pathlib import Path

_log = logging.getLogger(__name__)

from modelica_builder.modelica_project import ModelicaProject
from tests.data.measures.set_argument_value.measure import SetArgumentValue


class ModelicaMOSTest(unittest.TestCase):
    def setUp(self):
        self.data_dir = Path(os.path.dirname(__file__)) / 'data'
        self.output_dir = Path(os.path.dirname(__file__)) / 'output'
        if not os.path.exists(self.output_dir):
            os.makedirs(self.output_dir)

    def test_simple_measure(self):
        # remove the output project if it exists
        if Path(self.output_dir / 'test_simple_measure').exists():
            shutil.rmtree(self.output_dir / 'test_simple_measure')

        modelica_project = ModelicaProject(self.data_dir / 'packages' / 'teaser_single' / 'package.mo')
        modelica_project.save_as('test_simple_measure', self.output_dir)

        # reload the new project
        modelica_project = ModelicaProject(self.output_dir / 'test_simple_measure' / 'package.mo')

        # assert that the DistrictEnergySystem file has 4 nPorts_aHeaWat
        with open(modelica_project.file_data['Districts/DistrictEnergySystem.mo'].file_path, 'r') as f:
            file_contents = f.read()
            assert 'nPorts_aHeaWat=1' in file_contents

        measure = SetArgumentValue('nPorts')
        args = measure.arguments()
        args.set_value('model_name', 'Districts/DistrictEnergySystem')
        args.set_value('type', 'Loads.B5a6b99ec37f4de7f94020090.building')
        args.set_value('identifier', 'TeaserLoad_be9c7414')
        args.set_value('argument_name', 'nPorts_aHeaWat')
        args.set_value('value', '5', True)
        measure.run(modelica_project, args)

        # ensure that the DistrictEnergySystem file now has 5 nPorts_aHeaWat, just by grepping the file
        with open(modelica_project.file_data['Districts/DistrictEnergySystem.mo'].file_path, 'r') as f:
            file_contents = f.read()
            assert 'nPorts_aHeaWat=5' in file_contents

        # check if the measure attributes were saved to disk
        measure_att_file = self.output_dir / 'test_simple_measure' / 'measure_attributes.json'
        assert measure_att_file.exists()

        measure_attributes = json.loads(measure_att_file.read_text())
        assert measure_attributes['Districts/DistrictEnergySystem']['nPorts']['nPorts_aHeaWat_previous_value'] == "1"
        assert measure_attributes['Districts/DistrictEnergySystem']['nPorts']['value'] == "5"
