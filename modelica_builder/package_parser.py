# :copyright (c) URBANopt, Alliance for Sustainable Energy, LLC, and other contributors.
# See also https://github.com/urbanopt/modelica-builder/blob/develop/LICENSE.md

import copy
import os
import re
from jinja2 import Environment, FileSystemLoader
from pathlib import Path
from typing import Any, Dict, List, Optional, Union


# config for jinga2
def strcat(value, append):
    return value + str(append)


ALL_CUSTOM_FILTERS = {
    'strcat': strcat
}
# end config for jinga2


class PackageParser(object):
    """Class to read and modify the package.mo and the package.order file
    """

    def __init__(self, path: Union[str, Path] = None):
        """Create an instance to manage the package.mo/order file. If no path is provided then the user
        must add in their own package and order data. Or the user can load from the new_from_template
        class method.

        Args:
            path (Union[str, Path], optional): path to where the package.mo and package.order reside.
                                               Defaults to None.
        """
        self.path: Union[str, Path, None] = path
        self.order_data: Any = None
        self.package_data: Any = None
        self.package_name: Union[str, None] = None
        self.within: Union[list, None] = None
        self._subpackages: Dict[str, "PackageParser"] = {}

        self.load()

        # read in the path if it was given and pull out the package name
        if self.path is not None:
            self.path = Path(self.path)
            # The package name is also the name of the directory
            self.package_name = self.path.name

        self.template_env = Environment(
            loader=FileSystemLoader(
                searchpath=os.path.join(
                    os.path.dirname(os.path.abspath(__file__)), "templates"
                )
            )
        )
        self.template_env.filters.update(ALL_CUSTOM_FILTERS)

    def __getattr__(self, name: str) -> "PackageParser":
        """Enable dynamic access to subpackages via attribute notation.

        Args:
            name (str): The name of the subpackage (case-insensitive)

        Returns:
            PackageParser: The subpackage parser instance

        Raises:
            AttributeError: If the subpackage doesn't exist
        """
        # Avoid recursion for private attributes
        if name.startswith('_'):
            raise AttributeError(f"'{type(self).__name__}' object has no attribute '{name}'")

        # Check if this is a class-level attribute or method before treating it as a subpackage
        if hasattr(type(self), name):
            raise AttributeError(f"'{type(self).__name__}' object has no attribute '{name}'")

        # Check if this is a known subpackage
        name_lower = name.lower()
        if name_lower in object.__getattribute__(self, '_subpackages'):
            return object.__getattribute__(self, '_subpackages')[name_lower]

        # Check if the subpackage exists in the order but hasn't been loaded yet
        if hasattr(self, 'order_data') and self.order_data:
            orders = [o for o in self.order_data.split('\n') if o.strip()]
            for order_name in orders:
                if order_name.lower() == name_lower:
                    # Try to load the existing subpackage
                    try:
                        path = object.__getattribute__(self, 'path')
                    except AttributeError:
                        path = None
                    if path:
                        subpackage_path = Path(path) / order_name
                        if subpackage_path.exists():
                            subpackage = PackageParser(subpackage_path)
                            object.__getattribute__(self, '_subpackages')[name_lower] = subpackage
                            return subpackage

        raise AttributeError(f"Subpackage '{name}' not found. Use add_model('{name}') to create it first.")

    def parse_within_statement(self) -> Optional[List[str]]:
        """Read in the package_data and parse out the within statement. The result will
        be returns, but will also set the within attribute.
        """
        # use a regex to pull out the string between within and ;
        if self.package_data is None:
            self.within = None
            return None

        matches = re.findall(r'within\s(.*?);', self.package_data)
        # it is possible that there is no "within" block in the root package file.
        if len(matches) == 0 or matches is None:
            self.within = None
        elif len(matches) == 1:
            self.within = matches[0].split(".")
        else:
            raise ValueError("There are more than on within statements in the package.mo file")

        return self.within

    @classmethod
    def new_from_template(cls,
                          path: Union[str, Path],
                          name: str,
                          order: List[str],
                          mbl_version: Union[str, None] = None,
                          within: Union[str, None] = None
                          ) -> "PackageParser":
        """Create new package data based on the package.mo template. If 'within' is not specified, then it is
        assumed that this is a top level package and will load from the package_base template.

        Args:
            path (str): the path where the resulting package file and order will be saved to.
            name (str): the name of the model
            order (list[str]): ordered list of which models will be loaded (saved to package.order)
            mbl_version (str, optional): the version of the model buildings library (only used in package_base.mot)
            within (str, optional): name where this package is within. Defaults to None.


        Returns:
            PackageParser: object of the package parser
        """
        klass = PackageParser(path)
        if within and not mbl_version:
            template = klass.template_env.get_template("package.mot")
        else:
            template = klass.template_env.get_template("package_base.mot")

        klass.package_data = template.render(within=within, name=name, order=order, mbl_version=mbl_version)
        klass.order_data = "\n".join(order)
        klass.package_name = name
        klass.parse_within_statement()
        return klass

    def load(self) -> None:
        """Load the package.mo and package.mo data from the member variable path
        """
        filename = os.path.join(str(self.path), "package.mo")
        if os.path.exists(filename):
            with open(filename, "r") as f:
                self.package_data = f.read()

        filename = os.path.join(str(self.path), "package.order")
        if os.path.exists(filename):
            with open(filename, "r") as f:
                self.order_data = f.read()

        self.parse_within_statement()

    def save(self) -> None:
        """Save the updated files to the same location. Also saves all subpackages recursively.
        """
        # verify that the path exists before saving
        if self.path is None:
            raise ValueError("Path to save the package.mo and package.order files is not set.")

        # Ensure the directory exists (important for nested subpackages)
        Path(self.path).mkdir(parents=True, exist_ok=True)

        with open(os.path.join(str(self.path), "package.mo"), "w") as f:
            f.write(self.package_data)

        with open(os.path.join(str(self.path), "package.order"), "w") as f:
            f.write(self.order_data)
            f.write("\n")

        # Recursively save all subpackages
        for subpackage in self._subpackages.values():
            subpackage.save()

    def save_as(self, new_path: Union[str, Path]) -> None:
        """Save the package.mo and package.order file to the new path. Be
        careful just running this method without also updating all the related
        <model>.mo and package.mo files with the new within statement. Look at the
        ModelicaProject class for more support.

        Args:
            new_path (Union[str, Path]): Fully qualified path to save files to.
        """
        new_path = Path(new_path)
        with open(new_path / "package.mo", "w") as f:
            f.write(self.package_data)

        with open(new_path / "package.order", "w") as f:
            f.write(self.order_data)
            f.write("\n")

        # update link to saved path
        self.path = new_path

    @property
    def order(self) -> List[str]:
        """Return the order of the packages from the package.order file

        Returns:
            List[str]: list of the loaded models in the package.order file
        """
        data = self.order_data.split("\n")
        if "" in data:
            data.remove("")
        return data

    def rename_package(self, new_model: str):
        """Rename the model name in the package.mo file.

        Args:
            new_model (str): new name
        """
        if self.package_name is None:
            raise ValueError("Package name is not set, verify that it was parsed correctly in the source code")

        self.package_data = self.package_data.replace(self.package_name, new_model)
        self.package_name = new_model

    def rename_model(self, previous_model: str, new_model: str):
        """Rename the model name in the package.order file.

        Args:
            new_model (str): new name
        """
        self.order_data = self.order_data.replace(previous_model, new_model)

    def update_within_statement(self, new_within: str, element_index: Union[int, None] = None):
        """Update the within statement in the package.mo file

        Args:
            new_within (str): Full string of the new within statement, e.g., a.b.c.d
            element_index (int): index of the element to replace, None is the entire string
        """
        # new within
        new_within_list = copy.deepcopy(self.within)
        if element_index is not None:
            new_within_list[element_index] = new_within  # type: ignore
        else:
            new_within_list = new_within.split(".")

        self.package_data = self.package_data.replace(f"within {'.'.join(self.within)};", f"within {'.'.join(new_within_list)};")  # type: ignore
        self.within = new_within_list

    def add_model(self, new_model_name: str, insert_at: int = -1, create_subpackage: bool = False) -> "PackageParser":
        """Insert a new model into the package. Note that the order_data is stored as a string right now,
        so there is a bit of a hack to get this to work correctly.

        Args:
            new_model_name (str): name of the new model to add to the package order.
            insert_at (int, optional):  location to insert package, if 0 at beginning, -1 at end. Defaults to -1.
            create_subpackage (bool, optional): If True, create a subpackage directory and PackageParser. Defaults to False.

        Returns:
            PackageParser: The created subpackage if create_subpackage is True, otherwise self for chaining.

        Raises:
            ValueError: If create_subpackage is True but self.path is None.
        """
        # Validate that path exists when creating subpackages
        if create_subpackage and self.path is None:
            raise ValueError(
                f"Cannot create subpackage '{new_model_name}': PackageParser.path is None. "
                "Either set path during initialization or use create_subpackage=False."
            )

        data = self.order_data.split("\n")
        if insert_at == -1:
            data.append(new_model_name)
        else:
            data.insert(insert_at, new_model_name)
        self.order_data = "\n".join(data)

        # remove any empty lines
        self.order_data = self.order_data.replace('\n\n', '\n')

        # If create_subpackage is True, create the subpackage structure
        if create_subpackage:
            subpackage_path = Path(self.path) / new_model_name
            subpackage_path.mkdir(parents=True, exist_ok=True)

            # Determine the within statement for the subpackage
            if self.within:
                subpackage_within = f"{'.'.join(self.within)}.{self.package_name}"
            else:
                subpackage_within = self.package_name

            # Create the subpackage PackageParser
            subpackage = PackageParser.new_from_template(
                path=subpackage_path,
                name=new_model_name,
                order=[],
                within=subpackage_within
            )

            # Store it for later access
            self._subpackages[new_model_name.lower()] = subpackage
            return subpackage

        return self
