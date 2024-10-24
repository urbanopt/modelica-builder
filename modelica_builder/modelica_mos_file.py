# :copyright (c) URBANopt, Alliance for Sustainable Energy, LLC, and other contributors.
# See also https://github.com/urbanopt/modelica-builder/blob/develop/LICENSE.md

import copy
import logging
import re
from pathlib import Path
from typing import Any, Union

logger = logging.getLogger(__name__)


class ModelicaMOS(object):
    def __init__(self, filename: str, header_data: str = None, data_definition: str = None):
        """Read in a .mos file if it exists into a data object
        The format is CSV with additional header info, so for
        now read the data as a string and then convert the timeseries
        data as floats.

        Args:
            filename (str): Name of the file to import, typically a full path
            header_data (str, optional): header information as a string. Defaults to None.
            data_definition (str, optional): The type of data without the dimension, e.g., double tab1. Defaults to None.

        Raises:
            FileNotFoundError: File does not exist
            Exception: The file extension needs to be MOS
        """
        # allow reading in the header_data directly for testing purposes, for the
        # most part.
        self.data = []
        if not header_data:
            if Path(filename).exists():
                self.filename = Path(filename)
            else:
                raise FileNotFoundError(f"{filename} does not exist")

            if self.filename.suffix.lower() != ".mos":
                raise Exception(f"{filename} is not a .mos file")

            self.header_data = ""
            self.data_definition = ""
            # read the first n-rows until the data are not prepended with a # or is blank
            for line in self.filename.open():
                if line.startswith('#') or line.strip() == '':
                    self.header_data += line
                else:
                    # if the line has a ; then it is data
                    if ';' not in line:
                        # strip out the dimensions, because we will put
                        # those in based on the size of data later.
                        self.data_definition = line.rstrip().split('(')[0]
                    else:
                        self.data.append(line.rstrip().split(';'))

            # convert the data types to have first column be int and the remaining float
            for row, column in enumerate(self.data):
                self.data[row] = [int(column[0])] + [float(x) for x in column[1:]]
        else:
            self.header_data = header_data
            self.data_definition = "double tab1"

    @classmethod
    def from_list(cls, data: list, header_data: str = None):
        """Create a ModelicaMOS object from a list of data. Time must
        be the first column and should be integers. The remaining columns
        should be floats.

        Args:
            data (list): List of data in format of [[time, value1, value2, ...], [time2, ...], ...]
            header_data (str, optional): Header data. Defaults to None.

        Returns:
            ModelicaMOS: ModelicaMOS object
        """
        mos = cls("dummy.mos", header_data)
        mos.data = data
        return mos

    def retrieve_header_variable_value(self, key: str, cast_type: type = str) -> Any:
        """Retrieve a value from a variable in the header

        Args:
            key (str): Key to retrieve
            cast_type (type, optional): Type to cast the value to. Defaults to str.

        Returns:
            str: Value of the key
        """
        # check if the peak water heating load is zero, otherwise just skip
        key_re = rf'#(\s?{key}\s?)=\s?(-?\b\d[\d,.]*\b)(.*\s)'
        match = re.search(key_re, self.header_data)
        if match:
            # the first group is the variable name, the second is the value
            value = match.group(2).strip()
            if value and cast_type:
                try:
                    if cast_type != str:
                        value = value.replace(',', '')
                        return cast_type(value)
                    else:
                        return value
                except ValueError:
                    raise Exception(f"Unable to cast {value} to {cast_type}")
            else:
                return value
        else:
            return None

    def replace_header_variable_value(self, key: str, new_value: Any) -> bool:
        """Replace the variable value in the header vars

        Args:
            key (str): Key of the variable value to replace
            new_value (Any): new value

        Returns:
            bool: Always True (for now)
        """
        key_re = rf'#(\s?{key}\s?)=\s?(-?\b\d[\d,.]*\b)(.*\s)'

        # verify that group3 exists, otherwise the key doesn't exist
        match = re.search(key_re, self.header_data)
        if match:
            if match.group(3):
                # if there are units, then put the unit back in
                self.header_data = re.sub(key_re, '#' + r'\g<1>' + f"= {new_value}" + r'\g<3>', self.header_data)
            else:
                # no g3, therefore, just replace the var and value.
                self.header_data = re.sub(key_re, '#' + r'\g<1>' + f"= {new_value}", self.header_data)

        # replace the value, this requires recreating the variable and value
        self.header_data = re.sub(key_re, '#' + r'\g<1>' + f"= {new_value}" + r'\g<3>', self.header_data)
        return True

    def scale_loads(self, scale_factors: list, load_type: Union[str, int, list[int]] = "all") -> bool:
        """Scale the loads by a factor. The scale factors must look like the following:
            [
              {'start_time': Timestamp('2021-01-01 00:00:00'), 'end_time': Timestamp('2021-01-04 23:59:59'), 'scaling_factor': 0.72},
              {'start_time': Timestamp('2021-05-01 00:00:00'), 'end_time': Timestamp('2021-01-10 23:59:59'), 'scaling_factor': 1.50},
              ...
            ]

        This method can be used to scale the loads for a time period in an attempt to match
        existing data from another source. For example, if we know the total loads per day, then
        you can scale the loads to meet the total load.

        Args:
            scale_factors (list): A list of dictionaries with start, end, and value to scale.

            load_type (str, optional): Type of load to scale. Defaults to "all", but can be "heating",
                                       "cooling", "water_heating", or "all".

        Returns:
            bool: Always True
        """
        # skip if data is empty
        if not self.data:
            raise Exception("No data to scale")

        # if passing a string, then convert to the index in the same
        # format as the load_type version.
        if isinstance(load_type, str):
            # column name mappers
            column_mapper = {
                "cooling": [1],
                "heating": [2],
                "water_heating": [3],
                "all": [1, 2, 3]
            }
        elif isinstance(load_type, int):
            column_mapper = {
                "custom": [load_type],
            }
            load_type = 'custom'
        elif isinstance(load_type, list):
            column_mapper = {
                "custom": load_type,
            }
            load_type = 'custom'

        # create a copy to operate on
        scale_factor = copy.deepcopy(scale_factors)
        # convert the start_time and end_time to seconds from the beginning of the year
        first_time_stamp = scale_factor[0]["start_time"]
        for scale_factor in scale_factors:
            scale_factor["start_time_seconds"] = (scale_factor["start_time"] - first_time_stamp).total_seconds()
            scale_factor["end_time_seconds"] = (scale_factor["end_time"] - first_time_stamp).total_seconds()

        logger.debug(scale_factors)

        # convert the scale_factor datetime to a seconds value
        for column_index in column_mapper[load_type]:
            # multiple each row's column by the scale factor
            for row, column in enumerate(self.data):
                # get the scaling factor based on the time (inclusive on both sides)
                for scale_factor in scale_factors:
                    if scale_factor["start_time_seconds"] <= column[0] <= scale_factor["end_time_seconds"]:
                        column[column_index] = column[column_index] * scale_factor["scaling_factor"]
                        self.data[row] = column

        return True

    def save(self):
        """Save the file back to disk"""
        self.save_as(self.filename)

    def save_as(self, filename: Union[str, Path]):
        """Save the file to a new filename"""
        # reconstruct the file data
        data_definition = self.data_definition + f"({len(self.data)},{len(self.data[0])})"
        write_data = self.header_data + data_definition + '\n'
        for row in self.data:
            # join the row with a ; and convert each element to a string
            write_data += ';'.join([str(x) for x in row]) + '\n'
        Path(filename).write_text(write_data)
