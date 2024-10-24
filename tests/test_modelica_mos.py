# :copyright (c) URBANopt, Alliance for Sustainable Energy, LLC, and other contributors.
# See also https://github.com/urbanopt/modelica-builder/blob/develop/LICENSE.md

import logging
import os
import unittest
from datetime import datetime
from pathlib import Path

_log = logging.getLogger(__name__)

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
        file = ModelicaMOS('not_a_real_file.mos', header_data=data)
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
        file = ModelicaMOS('not_a_real_file.mos', header_data=data)
        self.assertEqual(file.retrieve_header_variable_value('Var1', cast_type=float), 1245.25)
        self.assertEqual(file.retrieve_header_variable_value('Var2', cast_type=float), 1245)
        self.assertEqual(file.retrieve_header_variable_value('Var3', cast_type=float), 1245)
        self.assertEqual(file.retrieve_header_variable_value('Var 4', cast_type=float), 1245)

    def test_variable_retrieval_negatives(self):
        # test with decimal separators
        data = """
#Var1 = -1,245.25 Watts
"""
        file = ModelicaMOS('not_a_real_file.mos', header_data=data)
        self.assertEqual(file.retrieve_header_variable_value('Var1', cast_type=float), -1245.25)

    def test_variable_retrieval_not_found(self):
        data = """
#Var1 = 1234 Watts
"""
        file = ModelicaMOS('not_a_real_file.mos', header_data=data)
        self.assertEqual(file.retrieve_header_variable_value('Var2', cast_type=float), None)

    def test_replace_variable_value(self):
        data = """
#Var1 = 0 Watts
#Var2 = 1
#Var3=2
#Var4 = -3
"""
        file = ModelicaMOS('not_a_real_file.mos', header_data=data)
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

    def test_scaling_loads(self):
        scaling_factors = [
            #  y  m  d  h  m  s
            {'start_time': datetime(2021, 1, 1, 0, 0, 0), 'end_time': datetime(2021,  1,  1,  3,  0,  0), 'scaling_factor': 0.25},  # noqa
            {'start_time': datetime(2021, 1, 1, 4, 0, 0), 'end_time': datetime(2021, 12, 31, 23, 59, 59), 'scaling_factor': 1}
        ]
        file = ModelicaMOS(self.data_dir / 'B2_no_water_load.mos')
        file.scale_loads(scaling_factors)

        # save to a new file to compare
        file.save_as(self.output_dir / 'B2_no_water_load_scaled.mos')
        # read in the new file and check the value
        self.assertTrue((self.output_dir / 'B2_no_water_load_scaled.mos').exists())
        new_mos = ModelicaMOS(self.output_dir / 'B2_no_water_load_scaled.mos')

        # to find these values, you must manually look at the original file and then the scaling factor and make
        # sure that the values match.
        _log.debug(new_mos.data)
        self.assertEqual(new_mos.data[0][0], 3600)
        self.assertEqual(new_mos.data[0][1], -25)
        self.assertEqual(new_mos.data[0][2], 50)

        # second >= 14400 should not be scaled, which is in row 3 (0-based)
        self.assertEqual(new_mos.data[3][0], 14400)
        self.assertEqual(new_mos.data[3][1], -100)
        self.assertEqual(new_mos.data[3][2], 200)

    def test_scaling_loads_single_named_column(self):
        scaling_factors = [
            #  y  m  d  h  m  s
            {'start_time': datetime(2021, 1, 1, 0, 0, 0), 'end_time': datetime(2021,  1,  1,  3,  0,  0), 'scaling_factor': 0.25},  # noqa
            {'start_time': datetime(2021, 1, 1, 4, 0, 0), 'end_time': datetime(2021, 12, 31, 23, 59, 59), 'scaling_factor': 1}
        ]
        file = ModelicaMOS(self.data_dir / 'B2_no_water_load.mos')
        file.scale_loads(scaling_factors, 'heating')

        # save to a new file to compare
        file.save_as(self.output_dir / 'B2_no_water_load_scaled_single_named_column.mos')
        # read in the new file and check the value
        self.assertTrue((self.output_dir / 'B2_no_water_load_scaled_single_named_column.mos').exists())
        new_mos = ModelicaMOS(self.output_dir / 'B2_no_water_load_scaled_single_named_column.mos')

        # to find these values, you must manually look at the original file and then the scaling factor and make
        # sure that the values match.
        _log.debug(new_mos.data)
        self.assertEqual(new_mos.data[0][0], 3600)
        self.assertEqual(new_mos.data[0][1], -100)
        self.assertEqual(new_mos.data[0][2], 50)

        # second >= 14400 should not be scaled, which is in row 3 (0-based)
        self.assertEqual(new_mos.data[3][0], 14400)
        self.assertEqual(new_mos.data[3][1], -100)
        self.assertEqual(new_mos.data[3][2], 200)

    def test_scaling_loads_column_index(self):
        """Test scaling a load by a column index"""
        scaling_factors = [
            #  y  m  d  h  m  s
            {'start_time': datetime(2021, 1, 1, 0, 0, 0), 'end_time': datetime(2021,  1,  1,  3,  0,  0), 'scaling_factor': 0.25},  # noqa
            {'start_time': datetime(2021, 1, 1, 4, 0, 0), 'end_time': datetime(2021, 12, 31, 23, 59, 59), 'scaling_factor': 1}
        ]
        file = ModelicaMOS(self.data_dir / 'B2_no_water_load.mos')
        file.scale_loads(scaling_factors, 1)

        # save to a new file to compare
        file.save_as(self.output_dir / 'B2_no_water_load_scaled_column_index.mos')
        # read in the new file and check the value
        self.assertTrue((self.output_dir / 'B2_no_water_load_scaled_column_index.mos').exists())
        new_mos = ModelicaMOS(self.output_dir / 'B2_no_water_load_scaled_column_index.mos')

        # to find these values, you must manually look at the original file and then the scaling factor and make
        # sure that the values match.
        _log.debug(new_mos.data)
        self.assertEqual(new_mos.data[0][0], 3600)
        self.assertEqual(new_mos.data[0][1], -25)
        self.assertEqual(new_mos.data[0][2], 200)

        # second >= 14400 should not be scaled, which is in row 3 (0-based)
        self.assertEqual(new_mos.data[3][0], 14400)
        self.assertEqual(new_mos.data[3][1], -100)
        self.assertEqual(new_mos.data[3][2], 200)

    def test_scaling_load_no_data_error(self):
        # test with decimal separators
        data = """
#Var1 = -1,245.25 Watts
"""
        file = ModelicaMOS('not_a_real_file.mos', header_data=data)
        with self.assertRaises(Exception) as ctx:
            file.scale_loads([])
        self.assertIn("No data to scale", str(ctx.exception))

    def test_creating_file_from_list(self):
        data = [
            [0, 1.1, 1.2, 1.3],
            [3600, 2.1, 2.2, 2.3],
            [7200, 3.1, 3.2, 3.3],
            [10800, 4.1, 4.2, 4.3],
        ]
        file = ModelicaMOS.from_list(data, header_data="dummy header data to prevent file not found")
        self.assertEqual(file.data, data)
