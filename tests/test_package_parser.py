# :copyright (c) URBANopt, Alliance for Energy Innovation, LLC, and other contributors.
# See also https://github.com/urbanopt/modelica-builder/blob/develop/LICENSE.md

import os
import shutil
import unittest
from pathlib import Path

from modelica_builder.package_parser import PackageParser

# NOTE: Update this version to test against new Modelica Buildings Library releases
MBL_VERSION = '12.1.0'


class PackageParserTest(unittest.TestCase):
    def setUp(self):
        self.data_dir = os.path.join(os.path.dirname(__file__), 'data')
        self.output_dir = os.path.join(os.path.dirname(__file__), 'output')
        if not os.path.exists(self.output_dir):
            os.makedirs(self.output_dir)

    def test_new_from_template(self):
        package = PackageParser.new_from_template(
            self.output_dir,
            'new_model_name',
            ["model_a", "model_b"],
            within="SomeWithin",
        )
        package.save()

        self.assertTrue(os.path.exists(os.path.join(self.output_dir, 'package.mo')))
        self.assertTrue(os.path.exists(os.path.join(self.output_dir, 'package.order')))

        # check for strings in files
        with open(os.path.join(self.output_dir, 'package.mo')) as f:
            file_data = f.read()
            self.assertTrue('within SomeWithin;' in file_data, 'Incorrect within clause')
            self.assertTrue('package new_model_name' in file_data, 'Incorrect package definition')
            self.assertTrue('end new_model_name;' in file_data, 'Incorrect package ending')

        with open(os.path.join(self.output_dir, 'package.order')) as f:
            self.assertTrue('model_a\nmodel_b' in f.read(), 'Incorrect package order')

    def test_mbl_version(self):
        package = PackageParser.new_from_template(
            self.output_dir,
            'new_model_name',
            ["model_a", "model_b"],
            mbl_version="2.0.0"
        )
        package.save()

        self.assertTrue((Path(self.output_dir) / 'package.mo').exists())
        self.assertTrue((Path(self.output_dir) / 'package.order').exists())

        # check for strings in files
        with open(Path(self.output_dir) / 'package.mo') as f:
            file_data = f.read()
            self.assertTrue('Buildings(version="2.0.0"' in file_data, 'Incorrect mbl_version')

    def test_modelica_version_default(self):
        # verify backwards compatibility: when modelica_version isn't provided, default to 4.0.0
        package = PackageParser.new_from_template(
            self.output_dir,
            'new_model_name',
            ["model_a", "model_b"],
            mbl_version="2.0.0"
        )
        package.save()

        with open(Path(self.output_dir) / 'package.mo') as f:
            file_data = f.read()
            self.assertTrue('Modelica(version="4.0.0"' in file_data, 'Incorrect default modelica_version')

    def test_modelica_version_custom(self):
        package = PackageParser.new_from_template(
            self.output_dir,
            'new_model_name',
            ["model_a", "model_b"],
            mbl_version="2.0.0",
            modelica_version="4.1.0"
        )
        package.save()

        with open(Path(self.output_dir) / 'package.mo') as f:
            file_data = f.read()
            self.assertTrue('Modelica(version="4.1.0"' in file_data, 'Incorrect custom modelica_version')

    def test_round_trip(self):
        package = PackageParser.new_from_template(
            self.output_dir,
            'another_model',
            ["model_x", "model_y"],
            within="DifferentWithin",
        )
        package.save()

        # Read in the package
        package = PackageParser(self.output_dir)
        self.assertListEqual(package.order, ["model_x", "model_y"])

    def test_rename_package_model(self):
        package = PackageParser.new_from_template(
            self.output_dir,
            'rename_model',
            ["model_1", "model_2"],
            within="RenameWithin",
        )
        package.save()

        package.rename_package('my_super_new_model')
        self.assertEqual(len(package.order), 2)
        self.assertIn('my_super_new_model', package.package_data)
        self.assertEqual(package.package_name, 'my_super_new_model')

    def test_rename_model_in_order(self):
        package = PackageParser.new_from_template(
            self.output_dir,
            'rename_model',
            ["model_1", "model_2"],
            within="RenameWithin",
        )
        package.save()

        package.rename_model('model_1', 'my_super_new_model')
        self.assertEqual(len(package.order), 2)
        self.assertIn('my_super_new_model', package.order)

    def test_add_model(self):
        package = PackageParser.new_from_template(
            self.output_dir,
            'so_many_models',
            ["model_beta", "model_gamma"],
            within="SoMany",
        )
        package.save()

        package.add_model('model_delta', create_subpackage=False)
        package.add_model('model_alpha', 0, create_subpackage=False)
        self.assertEqual(len(package.order), 4)
        self.assertListEqual(['model_alpha', 'model_beta', 'model_gamma', 'model_delta'], package.order)

    def test_within_clause(self):
        package = PackageParser.new_from_template(
            self.output_dir,
            'within_clause',
            ["model_a", "model_b"],
            within="SomeWithin",
        )
        package.save()

        self.assertEqual(package.within, ['SomeWithin'])

        package.update_within_statement('NewWithin')
        self.assertEqual(package.within, ['NewWithin'])

    def test_add_subpackage_and_access(self):
        """Test adding a subpackage and accessing it via attribute notation"""
        project_path = Path(self.output_dir) / 'test_subpackage_project'
        if project_path.exists():
            import shutil
            shutil.rmtree(project_path)
        project_path.mkdir(parents=True)

        # Create root package
        package = PackageParser.new_from_template(
            project_path,
            'MyProject',
            [],
            mbl_version=MBL_VERSION
        )

        # Add a subpackage
        package.add_model('Districts', create_subpackage=True)
        package.save()  # Save to write files to disk

        # Access via attribute notation
        districts = package.districts
        self.assertIsInstance(districts, PackageParser)
        self.assertEqual(districts.package_name, 'Districts')
        self.assertTrue((project_path / 'Districts').exists())
        self.assertTrue((project_path / 'Districts' / 'package.mo').exists())
        self.assertTrue((project_path / 'Districts' / 'package.order').exists())

        # Check within statement
        self.assertEqual(districts.within, ['MyProject'])

    def test_nested_subpackages(self):
        """Test creating nested subpackages: package.districts.models"""
        project_path = Path(self.output_dir) / 'test_nested_project'
        if project_path.exists():
            import shutil
            shutil.rmtree(project_path)
        project_path.mkdir(parents=True)

        # Create root package
        package = PackageParser.new_from_template(
            project_path,
            'NestedProject',
            [],
            mbl_version=MBL_VERSION
        )

        # Add nested subpackages
        package.add_model('Districts', create_subpackage=True)
        package.districts.add_model('Models', create_subpackage=True)
        package.save()  # Save to write files to disk

        # Verify structure
        self.assertTrue((project_path / 'Districts' / 'Models').exists())
        self.assertTrue((project_path / 'Districts' / 'Models' / 'package.mo').exists())

        # Check within statements
        models = package.districts.models
        self.assertEqual(models.within, ['NestedProject', 'Districts'])

    def test_subpackage_save_recursive(self):
        """Test that saving parent package also saves all subpackages"""
        project_path = Path(self.output_dir) / 'test_recursive_save'
        if project_path.exists():
            import shutil
            shutil.rmtree(project_path)
        project_path.mkdir(parents=True)

        # Create structure
        package = PackageParser.new_from_template(
            project_path,
            'SaveProject',
            [],
            mbl_version=MBL_VERSION
        )

        package.add_model('Districts', create_subpackage=True)
        package.districts.add_model('Model1', create_subpackage=False)
        package.districts.add_model('Model2', create_subpackage=False)

        # Save only the root
        package.save()

        # Verify Districts package.order contains the models
        with open(project_path / 'Districts' / 'package.order') as f:
            content = f.read()
            self.assertIn('Model1', content)
            self.assertIn('Model2', content)

    def test_subpackage_attribute_error(self):
        """Test that accessing non-existent subpackage raises AttributeError"""
        project_path = Path(self.output_dir) / 'test_error_project'
        if project_path.exists():
            import shutil
            shutil.rmtree(project_path)
        project_path.mkdir(parents=True)

        package = PackageParser.new_from_template(
            project_path,
            'ErrorProject',
            [],
            mbl_version=MBL_VERSION
        )

        with self.assertRaises(AttributeError) as context:
            _ = package.nonexistent

        self.assertIn('nonexistent', str(context.exception))

    def test_case_insensitive_subpackage_access(self):
        """Test that subpackage access is case-insensitive"""
        project_path = Path(self.output_dir) / 'test_case_project'
        if project_path.exists():
            import shutil
            shutil.rmtree(project_path)
        project_path.mkdir(parents=True)

        package = PackageParser.new_from_template(
            project_path,
            'CaseProject',
            [],
            mbl_version=MBL_VERSION
        )

        # Capture the returned subpackage from add_model
        returned_districts = package.add_model('Districts', create_subpackage=True)

        # All these should work
        districts1 = package.districts
        districts2 = package.Districts
        districts3 = package.DISTRICTS

        # Verify that the returned subpackage is the same instance as accessed via attribute notation
        self.assertIs(returned_districts, districts1)
        self.assertIs(districts1, districts2)
        self.assertIs(districts2, districts3)

    def test_full_workflow(self):
        """Test the complete workflow from example code"""
        project_path = Path(self.output_dir) / 'test_workflow'
        if project_path.exists():
            import shutil
            shutil.rmtree(project_path)
        project_path.mkdir(parents=True)

        # Example of how we want to access the package
        package = PackageParser.new_from_template(
            project_path,
            'WorkflowProject',
            [],
            mbl_version=MBL_VERSION
        )
        package.add_model('Districts', create_subpackage=True)
        package.districts.add_model('Model_Sigma', create_subpackage=True)
        package.save()

        # Verify the structure was created
        self.assertTrue((project_path / 'package.mo').exists())
        self.assertTrue((project_path / 'Districts').exists())
        self.assertTrue((project_path / 'Districts' / 'Model_Sigma').exists())
        self.assertTrue((project_path / 'Districts' / 'Model_Sigma' / 'package.mo').exists())

        # Verify package.order contents
        with open(project_path / 'package.order') as f:
            self.assertIn('Districts', f.read())

        with open(project_path / 'Districts' / 'package.order') as f:
            self.assertIn('Model_Sigma', f.read())

        # Verify within statements in package.mo files
        with open(project_path / 'Districts' / 'package.mo') as f:
            content = f.read()
            self.assertIn('within WorkflowProject;', content)

        with open(project_path / 'Districts' / 'Model_Sigma' / 'package.mo') as f:
            content = f.read()
            self.assertIn('within WorkflowProject.Districts;', content)

    def test_add_model_with_no_path_raises_error(self):
        """Test that add_model raises ValueError when create_subpackage=True but path is None"""
        # Create a PackageParser without a path
        package = PackageParser()
        package.order_data = "model_a\nmodel_b"
        package.package_name = "TestPackage"

        # Try to add a model with create_subpackage=True
        with self.assertRaises(ValueError) as context:
            package.add_model('NewModel', create_subpackage=True)

        self.assertIn("Cannot create subpackage 'NewModel'", str(context.exception))
        self.assertIn("PackageParser.path is None", str(context.exception))

        # Verify that add_model works with create_subpackage=False
        package.add_model('NewModel', create_subpackage=False)
        self.assertIn('NewModel', package.order)

    def test_subpackage_cache_synchronization(self):
        """Test that add_model returns the same instance if subpackage is already cached"""
        project_path = Path(self.output_dir) / 'test_cache_sync'
        if project_path.exists():
            shutil.rmtree(project_path)
        project_path.mkdir(parents=True)

        package = PackageParser.new_from_template(
            project_path,
            'CacheProject',
            [],
            mbl_version=MBL_VERSION
        )

        # First, create the subpackage using add_model
        districts1 = package.add_model('Districts', create_subpackage=True)

        # Try to call add_model again with the same name
        districts2 = package.add_model('Districts', create_subpackage=True)

        # Verify they are the same instance
        self.assertIs(districts1, districts2, "add_model should return cached instance")

        # Also verify attribute access returns the same instance
        districts3 = package.districts
        self.assertIs(districts1, districts3, "Attribute access should return cached instance")

        # Verify that the model name only appears once in the order
        order_lines = [line for line in package.order_data.split('\n') if line.strip()]
        districts_count = sum(1 for line in order_lines if line == 'Districts')
        self.assertEqual(districts_count, 1, "Model name should only appear once in order")
