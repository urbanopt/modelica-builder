"""
****************************************************************************************************
:copyright (c) 2020-2021, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""

import distutils.cmd
import distutils.log
import glob
import os
import re

PYTHON_REGEX = re.compile(r'^""".\*{100}.*:copyright.*\*{100}."""$', re.MULTILINE | re.DOTALL)
PYTHON_LICENSE = '''"""
****************************************************************************************************
:copyright (c) 2020-2021, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""'''

EXCLUDE_FILES = ["__init__.py", "modelicaLexer.py", "modelicaListener.py", "modelicaParser.py"]
PATHS = [
    {"glob": "modelica_builder/**/*.py", "license": PYTHON_LICENSE, "REGEX": PYTHON_REGEX, },
    {"glob": "management/**/*.py", "license": PYTHON_LICENSE, "REGEX": PYTHON_REGEX},
    {"glob": "tests/**/*.py", "license": PYTHON_LICENSE, "REGEX": PYTHON_REGEX},
    # single files
    # { "glob": 'bin/resources/**/file.py', "license": PYTHON_LICENSE, "REGEX": PYTHON_REGEX },
]


class UpdateLicenses(distutils.cmd.Command):
    """Custom comand for updating the GeoJSON schemas on which this project depends."""

    description = "Update the license/copyright headers"

    user_options = []

    def initialize_options(self):
        pass

    def finalize_options(self):
        pass

    def check_and_update_license(self, filename):
        """
        check if the license exists in the file, and if it does, then make sure it is up-to-date with
        the license defined in this file.

        :param filename: str, path of the file to update
        :return: None
        """
        s = open(filename, "r").read()
        if PYTHON_REGEX.search(s):
            print("License already exists, updating")
            content = re.sub(PYTHON_REGEX, PYTHON_LICENSE, s)
            with open(filename, "w") as f:
                f.write(content)
                f.close()
        else:
            print("Adding license")
            with open(filename, "r+") as f:
                content = f.read()
                f.seek(0, 0)
                f.write(PYTHON_LICENSE.rstrip("\r\n") + "\n\n\n" + content)
                f.close()

    def run(self):
        for p in PATHS:
            gl = glob.glob(p["glob"], recursive=True)
            for g in gl:
                print(os.path.basename(g))
                if os.path.basename(g) in EXCLUDE_FILES:
                    print(f"Skipping file {g}")
                else:
                    print(f"Checking license in file {g}")
                    self.check_and_update_license(g)
