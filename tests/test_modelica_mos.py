# :copyright (c) URBANopt, Alliance for Sustainable Energy, LLC, and other contributors.
# See also https://github.com/urbanopt/geojson-modelica-translator/blob/develop/LICENSE.md

import os
import unittest
from pathlib import Path

from modelica_builder.modelica_mos_file import ModelicaMOS


class ModelicaMOSTest(unittest.TestCase):
    def setUp(self):
        self.data_dir = Path(os.path.dirname(__file__)) / 'data'
        self.output_dir = Path(os.path.dirname(__file__)) / 'output'
        if not os.path.exists(self.output_dir):
            os.makedirs(self.output_dir)

    def test_variable_retrieval_basic(self):
        data = """
#Var1 = 0 Watts
#Var2 = 1 Watts
#Var3 = 2
"""
        file = ModelicaMOS('not_a_real_file.mos', data=data)
        self.assertEqual(file.retrieve_header_variable_value('Var1', cast_type=int), 0)
        self.assertEqual(file.retrieve_header_variable_value('Var2'), '1')
        self.assertEqual(file.retrieve_header_variable_value('Var3'), '2')

    def test_variable_retrieval_floats(self):
        # test with decimal separators
        data = """
#Var1 = 1,245.25 Watts
# Var2 = 1,245 Watts
# Var3 = 1,245 Watts with space
# Var 4 = 1,245 Watts
"""
        file = ModelicaMOS('not_a_real_file.mos', data=data)
        self.assertEqual(file.retrieve_header_variable_value('Var1', cast_type=float), 1245.25)
        self.assertEqual(file.retrieve_header_variable_value('Var2', cast_type=float), 1245)
        self.assertEqual(file.retrieve_header_variable_value('Var3', cast_type=float), 1245)
        self.assertEqual(file.retrieve_header_variable_value('Var 4', cast_type=float), 1245)

    def test_variable_retrieval_negatives(self):
        # test with decimal separators
        data = """
#Var1 = -1,245.25 Watts
"""
        file = ModelicaMOS('not_a_real_file.mos', data=data)
        self.assertEqual(file.retrieve_header_variable_value('Var1', cast_type=float), -1245.25)

    def test_variable_retrieval_not_found(self):
        data = """
#Var1 = 1234 Watts
"""
        file = ModelicaMOS('not_a_real_file.mos', data=data)
        self.assertEqual(file.retrieve_header_variable_value('Var2', cast_type=float), None)

    def test_replace_variable_value(self):
        data = """
#Var1 = 0 Watts
#Var2 = 1
#Var3=2
#Var4 = -3
"""
        file = ModelicaMOS('not_a_real_file.mos', data=data)
        self.assertEqual(file.retrieve_header_variable_value('Var1', cast_type=float), 0)
        file.replace_header_variable_value('Var1', 1234)
        file.replace_header_variable_value('Var2', 2345)
        file.replace_header_variable_value('Var3', 3456)
        file.replace_header_variable_value('Var4', -1234)

        # check that the value was replaced
        self.assertEqual(file.retrieve_header_variable_value('Var1', cast_type=float), 1234)
        self.assertEqual(file.retrieve_header_variable_value('Var2', cast_type=float), 2345)
        self.assertEqual(file.retrieve_header_variable_value('Var3', cast_type=float), 3456)
        self.assertEqual(file.retrieve_header_variable_value('Var4', cast_type=float), -1234)

    def test_read_write_with_replace(self):

        file = ModelicaMOS(self.data_dir / 'B2_no_water_load.mos')
        self.assertEqual(file.retrieve_header_variable_value('Peak water heating load', cast_type=float), 0)
        file.replace_header_variable_value('Peak water heating load', 5124)
        file.replace_header_variable_value('Peak space cooling load', -10000)

        # save off the new file
        file.save_as(self.output_dir / 'B2_no_water_load_updated.mos')

        # reread the saved file and check the values
        new_file = ModelicaMOS(self.output_dir / 'B2_no_water_load_updated.mos')
        self.assertEqual(new_file.retrieve_header_variable_value('Peak water heating load', cast_type=float), 5124)
        self.assertEqual(new_file.retrieve_header_variable_value('Peak space cooling load', cast_type=float), -10000)

        # just call the save method for 'crash' check
        new_file.save()
