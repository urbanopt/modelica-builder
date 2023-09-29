# :copyright (c) URBANopt, Alliance for Sustainable Energy, LLC, and other contributors.
# See also https://github.com/urbanopt/geojson-modelica-translator/blob/develop/LICENSE.md

import re
from pathlib import Path
from typing import Any, Union


class ModelicaMOS(object):
    def __init__(self, filename: str, data: str = None):
        """Read in a .mos file if it exists into a data object
        The format is CSV with additional header info, so for
        now read the data as a string.

        Args:
            filename (str): Name of the file to import, typically a full path

        Raises:
            FileNotFoundError: File does not exist
            Exception: The file extension needs to be MOS
        """
        # allow reading in the data directly for testing purposes, for the
        # most part.
        if not data:
            if Path(filename).exists():
                self.filename = Path(filename)
            else:
                raise FileNotFoundError(f"{filename} does not exist")

            if self.filename.suffix.lower() != ".mos":
                raise Exception(f"{filename} is not a .mos file")

            self.data = self.filename.read_text()
        else:
            self.data = data

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
        match = re.search(key_re, self.data)
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
        match = re.search(key_re, self.data)
        if match:
            if match.group(3):
                # if there are units, then put the unit back in
                self.data = re.sub(key_re, '#' + r'\g<1>' + f"= {new_value}" + r'\g<3>', self.data)
            else:
                # no g3, therefore, just replace the var and value.
                self.data = re.sub(key_re, '#' + r'\g<1>' + f"= {new_value}", self.data)

        # replace the value, this requires recreating the variable and value
        self.data = re.sub(key_re, '#' + r'\g<1>' + f"= {new_value}" + r'\g<3>', self.data)
        return True

    def save(self):
        """Save the file back to disk"""
        self.filename.write_text(self.data)

    def save_as(self, filename: Union[str, Path]):
        """Save the file to a new filename"""
        Path(filename).write_text(self.data)
