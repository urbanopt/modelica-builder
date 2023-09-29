"""
****************************************************************************************************
:copyright (c) 2020-2023, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""
import os
import shutil
import unittest
from pathlib import Path

from modelica_builder.model import Model
from modelica_builder.modelica_project import ModelicaFileObject, ModelicaProject


class ModelicaProjectTest(unittest.TestCase):
    def setUp(self):
        self.data_dir = Path(__file__).parent / 'data' / 'packages'
        self.output_dir = Path(__file__).parent / 'output' / 'packages'
        if os.path.exists(self.output_dir):
            shutil.rmtree(self.output_dir)
        os.makedirs(self.output_dir, exist_ok=False)

    def test_load_package_files(self):
        package_file = self.data_dir / 'teaser_single' / 'package.mo'
        project = ModelicaProject(package_file)

        self.assertTrue(project.file_data['package.mo'].file_path.exists())
        district_mo_file = 'Districts' + os.path.sep + 'DistrictEnergySystem.mo'
        self.assertTrue(project.file_data[district_mo_file].file_path.exists())

        # assert the file type of the DistrictEnergySystem.mo file
        self.assertEqual(project.file_data[district_mo_file].file_type, ModelicaFileObject.FILE_TYPE_MODEL)

        # check the data in the DistrictEnergySystem.mo file
        mofile = project.file_data[district_mo_file].object
        self.assertIsInstance(mofile, Model)

    def test_get_model_from_package(self):
        """Return a model object from a string path"""
        package_file = self.data_dir / 'teaser_single' / 'package.mo'
        project = ModelicaProject(package_file)

        model = project.get_model('Districts.DistrictEnergySystem')
        self.assertIsInstance(model, Model)

        with self.assertRaises(Exception) as ctx:
            model = project.get_model('Districts.DistrictEnergySystem.mo')
        self.assertIn("Model name should not have the .mo extension", str(ctx.exception))

        with self.assertRaises(Exception) as ctx:
            model = project.get_model('not.a.path.to.a.model')
        self.assertIn("ModelicaPackage does not contain a", str(ctx.exception))

        # verify that searching for a package.mo will raise an exception
        with self.assertRaises(Exception) as ctx:
            model = project.get_model('package')
        self.assertIn("Model is a package file, not a model", str(ctx.exception))

    def test_project_save_as(self):
        """Saving a package will require renaming the within statements in all the files"""
        package_file = self.data_dir / 'teaser_single' / 'package.mo'
        project = ModelicaProject(package_file)

        project.save_as('test_package_1', self.output_dir)

        # verify that the package.mo file was saved
        self.assertTrue((self.output_dir / 'test_package_1' / 'package.mo').exists())
