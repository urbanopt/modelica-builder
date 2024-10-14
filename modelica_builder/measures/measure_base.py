# :copyright (c) URBANopt, Alliance for Sustainable Energy, LLC, and other contributors.
# See also https://github.com/urbanopt/modelica-builder/blob/develop/LICENSE.md

# For now all of the measure-based classes are here within the same file.
# The MeasureAttributes and MeasureArguments classes should be moved
# to their own files in the future.

import json
import typing
from pathlib import Path

from modelica_builder.modelica_project import ModelicaProject


class MeasureAttributes(dict):
    def __init__(self):
        """Class to store attributes from measures that are run in the context of
        modelica_builder.
        """
        super().__init__()

    def load(self, filepath: Path = None):
        """Read the JSON dictionary into self"""
        if Path(filepath / "measure_attributes.json").exists():
            self.update(json.load(open(filepath / "measure_attributes.json", "r")))
        else:
            self.clear()

    def save(self, filepath: Path):
        """Save the JSON dictionary to disk"""
        json.dump(self, open(filepath / "measure_attributes.json", "w"), indent=2)

    def register_value(self, model_name: str, measure_name: str, argument_name: str, value: typing.Any):
        if model_name not in self:
            self[model_name] = {}

        if measure_name not in self[model_name]:
            self[model_name][measure_name] = {}

        self[model_name][measure_name][argument_name] = value

    def get_attribute(self, name: str):
        return self[name]


class MeasureArguments(list):
    def __init__(self):
        super().__init__()

    def add_argument(self, name: str, display_name: str, description: str = None, units: str = None, default: typing.Any = None, register_values: bool = False):
        """Add arguments to the list (self).

        Args:
            name (str): _description_
            display_name (str): _description_
            description (str, optional): _description_. Defaults to None.
            units (str, optional): _description_. Defaults to None.
            default (typing.Any, optional): _description_. Defaults to None.
            register_values (bool, optional): Store the before (if possible) and after value to a local file. Defaults to False.
        """
        arg = {
            "name": name,
            "display_name": display_name,
            "units": units,
            "default": default,
            "register_values": register_values,
        }
        if description:
            arg["description"] = description
        else:
            arg["description"] = display_name

        self.append(arg)

    def set_value(self, name: str, value: typing.Any, register_values: bool = False):
        for arg in self:
            if arg["name"] == name:
                arg["value"] = value
                if register_values:
                    arg["register_values"] = True
                break
        else:
            raise ValueError(f"Argument '{name}' not found")

    def get_args_with_register_values(self):
        """Return list of args that have a registered value field set to True"""
        return [arg for arg in self if arg["register_values"]]

    def get_value(self, name: str):
        for arg in self:
            if arg["name"] == name:
                return arg["value"]
        else:
            raise ValueError(f"Argument '{name}' not found")


class MeasureBase():
    def __init__(self) -> None:
        self.measure_args = MeasureArguments()
        self.measure_attributes = MeasureAttributes()

    def run(self, project: ModelicaProject, user_arguments: list[dict]):
        # read in the measure_attributes file if it exists
        self.measure_attributes.load(project.root_directory)
