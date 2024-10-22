# :copyright (c) URBANopt, Alliance for Sustainable Energy, LLC, and other contributors.
# See also https://github.com/urbanopt/modelica-builder/blob/develop/LICENSE.md

import logging
import os
import pathspec
import time
from pathlib import Path
from typing import Union

from modelica_builder.model import Model
from modelica_builder.package_parser import PackageParser

_log = logging.getLogger(__name__)


class ModelicaFileObject:
    """Class for storing a Modelica file object. Example is a '.mo' file that is
    lazily parsed into the AST using Modelica-Builder or a '.mos' file that reads in the
    header's values using the ModelicaMOS class."""

    # enumerations for different file types
    FILE_TYPE_PACKAGE = 0
    FILE_TYPE_MODEL = 1
    FILE_TYPE_SCRIPT = 2
    FILE_TYPE_TEXT = 3

    def __init__(self, file_path):
        self.file_path = Path(file_path)
        self.object = None
        self.file_contents = None
        self.file_type = None

        # depending on the file type, parse the object when it is first accessed.
        if self.file_path.is_dir():
            self.file_contents = None
        elif self.file_path.name == 'package.mo':
            # this parses both the .mo and .order files, so we
            # need to skip over the .order file. The PackageParser is
            # a directory, not the file itself.
            self.object = PackageParser(self.file_path.parent)
            self.file_type = self.FILE_TYPE_PACKAGE
        elif self.file_path.name == 'package.order':
            pass
        elif self.file_path.suffix == '.mo':
            self.file_type = self.FILE_TYPE_MODEL
            self._parse_mo_file()
        elif self.file_path.suffix == '.mos':
            self.file_type = self.FILE_TYPE_SCRIPT
            self.file_contents = self.file_path.read_text()
        elif self.file_path.suffix == '.txt':
            self.file_type = self.FILE_TYPE_TEXT
            self.file_contents = self.file_path.read_text()
        else:
            # not sure what to do with this
            _log.warning(f"Unknown file type {self.file_path}")

    def exists(self):
        self.file_path.exists()

    def _parse_mo_file(self):
        """method to parse the mo file into a Modelica AST"""
        # time the loading of the file
        start = time.time()
        self.object = Model(self.file_path)
        end = time.time()

        _log.debug(f"Took {end - start} seconds to load {self.file_path.name}")

    @property
    def name(self):
        """method to get the name of the file"""
        return self.file_path.name


class ModelicaProject:
    """Class for storing all the files in a Modelica project. This class should organically
    grow as more requirements are needed.

    The current functionality includes:
    * Load in a package.mo file and store all the related files in memory space."""

    def __init__(self, package_file):
        self.root_directory = Path(package_file).parent
        self.file_types = ['.mo', '.txt', '.mos', '.order', ]
        self.file_types_to_skip = ['.log', '.mat', ]

        # skip some specific files that software may create that are not needed to be
        # sent around with the modelica project.
        self.file_names_to_skip = ['.DS_Store', '.mpignore', 'analysis_name.txt', 'analysis_variables.csv',]

        # Keep track of the files that have been ignored.
        self.mpignore_files = []

        # object to store all the files in the package
        self.file_data = {}

        self._load_data()

    def _load_data(self) -> None:
        """method to load all of the files into a data structure for processing"""
        # walk the tree and add in all the files

        # Try to find a .mpignore file in the directory with the package.mo.
        # Eventually we should support searching up the tree.
        project_ignore_file = self.root_directory / '.mpignore'
        if project_ignore_file.exists():
            patterns = []
            with open(project_ignore_file) as f:
                patterns = f.read().splitlines()
            spec = pathspec.PathSpec.from_lines(pathspec.patterns.GitWildMatchPattern, patterns)
        else:
            spec = None

        for file_path in self.root_directory.rglob('*'):
            # if there is a spec, check if the file is in the spec and ignore if matches
            if spec:
                if spec.match_file(str(file_path.relative_to(self.root_directory))):
                    self.mpignore_files.append(file_path)
                    continue

            if file_path.suffix in self.file_types_to_skip and file_path.is_file():
                # skip files that have the file_types_to_skip suffix
                continue

            if file_path.name in self.file_names_to_skip and file_path.is_file():
                # skip files that have the file_names_to_skip name
                continue

            if file_path.suffix in self.file_types and file_path.is_file():
                # only store the relative path that is in the package
                rel_path = file_path.relative_to(self.root_directory)
                self.file_data[str(rel_path)] = ModelicaFileObject(file_path)
            elif file_path.is_dir():
                # this is a directory, add in an empty ModelicaFileObject
                # to keep track of the directory.
                #
                # We ignore if there is a tmp directory and display only the
                # first time the tmp shows up in the tree walking.
                if 'tmp' in file_path.parts:
                    if file_path.parts[-1] == 'tmp':
                        _log.warning(f"Found a tmp directory, skipping {file_path}")

                    # always continue
                    continue

                rel_path = file_path.relative_to(self.root_directory)
                self.file_data[str(rel_path)] = ModelicaFileObject(file_path)
            else:
                print(f"Unknown file {file_path}, these can be ignored by creating a .mpignore file in the project root")

        # now sort the file_data by the keys
        self.file_data = {key: self.file_data[key] for key in sorted(self.file_data)}

        # validate the data, extend as needed.
        if self.file_data.get('package.mo', None) is None:
            raise Exception('ModelicaPackage does not contain a /package.mo file')

    def pretty_print_tree(self) -> None:
        """Pretty print all the items in the directory structure
        """
        # Print a couple lines, just because
        print()
        for key, obj in self.file_data.items():
            # find how many indents we need based on the number of path separators
            indent = key.count(os.path.sep)
            print(" " * indent + f"{os.path.sep} {key.replace(os.path.sep, f' {os.path.sep} ')}")

    def get_model(self, model_name: Union[Path, str]) -> Model:
        """Return the model object based on the based string name. The model
        name should be in the format that Modelica prefers which is period(.)
        delimited.

        Args:
            model_name (str): Name of the model to return, in the form of . delimited

        Raises:
            Exception: Various exceptions if the model is not found or the file type is incorrect

        Returns:
            Model: The Modelica Builder model object
        """
        # check if the last 3 characters are .mo. The path should originally be
        # a period delimited path.
        model_name = str(model_name)
        if model_name.endswith('.mo'):
            raise Exception(f"Model name should not have the .mo extension: {model_name} ")

        # convert the model_name to the path format
        model_name = Path(model_name.replace('.', os.path.sep))

        # now add on the extension
        model_name = model_name.with_suffix('.mo')

        if self.file_data.get(str(model_name)) is None:
            raise Exception(f"ModelicaPackage does not contain a {model_name} model")
        else:
            # verify that the type of file is model
            model = self.file_data[str(model_name)]
            if model.file_type != ModelicaFileObject.FILE_TYPE_MODEL:
                raise Exception(f"Model is a package file, not a model: {model_name}")

            return self.file_data[str(model_name)].object

    def save_as(self, new_package_name: str, output_dir: Path = None) -> None:
        """method to save the ModelicaProject to a new location which
        requires a new path name and updating all of the "within" statements

        Args:
            new_package_name (str): Name of the new package, which will also be the directory name
            output_dir (Path, optional): Where to persist the new directory and package. Defaults to existing.
        """
        if output_dir is None:
            output_dir = self.root_directory
        output_dir = output_dir / new_package_name

        # in the root package, rename the modelica package (there is not within statement)
        self.file_data['package.mo'].object.rename_package(new_package_name)

        # go through each of the package.mo files first and update the within statements
        for path, file in self.file_data.items():
            if path == 'package.mo':
                # this file is handled above, so just skip
                continue

            if file.file_type == ModelicaFileObject.FILE_TYPE_PACKAGE:
                # this is a package, so update the within statement
                file.object.update_within_statement(new_package_name, element_index=0)

            elif file.file_type == ModelicaFileObject.FILE_TYPE_MODEL:
                new_within_statement = f"{new_package_name}.{str(Path(path).parent).replace(os.path.sep, '.')}"
                file.object.set_within_statement(new_within_statement)

                # there are a few very specific methods that exist when reading in weather files or
                # load files. I am not sure how to abstract out this logic at the moment.

                # IDF names - find the existing value and replace if found
                idf_name = file.object.get_parameter_value('String', 'idfName')
                if idf_name:
                    # replace the previous model name with the new name
                    idf_name = idf_name.replace(self.root_directory.name, new_package_name)
                    file.object.update_parameter('String', 'idfName', idf_name)

                epw_name = file.object.get_parameter_value('String', 'epwName')
                if epw_name:
                    # replace the previous model name with the new name
                    epw_name = epw_name.replace(self.root_directory.name, new_package_name)
                    file.object.update_parameter('String', 'epwName', epw_name)

                weather_filename = file.object.get_parameter_value('String', 'weaName')
                if weather_filename:
                    # replace the previous model name with the new name
                    weather_filename = weather_filename.replace(self.root_directory.name, new_package_name)
                    file.object.update_parameter('String', 'weaName', weather_filename)

                filename = file.object.get_parameter_value('String', 'filNam')
                if filename:
                    # replace the previous model name with the new name
                    filename = filename.replace(self.root_directory.name, new_package_name)
                    file.object.update_parameter('String', 'filNam', filename)

        # now persist all the files to the new location
        if not output_dir.exists():
            output_dir.mkdir(parents=True, exist_ok=True)

        for path, file in self.file_data.items():
            # create the new path
            new_path = output_dir / path
            if file.file_path.is_dir():
                # this is a directory, so just create it
                new_path.mkdir(parents=True, exist_ok=True)

            elif file.file_type == ModelicaFileObject.FILE_TYPE_PACKAGE:
                file.object.save_as(new_path.parent)
            elif file.file_type == ModelicaFileObject.FILE_TYPE_MODEL:
                file.object.save_as(new_path)
            elif file.file_type == ModelicaFileObject.FILE_TYPE_SCRIPT:
                # just save the file as it is text (mos-based file)
                open(new_path, 'w').write(file.file_contents)
            elif file.file_type == ModelicaFileObject.FILE_TYPE_TEXT:
                # just save the file as it is text (all other files)
                open(new_path, 'w').write(file.file_contents)
            elif file.file_path.name == 'package.order':
                # this is included in the FILE_TYPE_PACKAGE, so just skip
                continue
            else:
                _log.warn(f"Unknown file type, not including in .save_as, {file.file_path}")
