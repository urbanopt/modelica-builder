# -*- coding: utf-8 -*-
# """
#     Setup file for modelica_builder.
#     Use setup.cfg to configure your project.

#     This file was generated with PyScaffold 3.2.3.
#     PyScaffold helps you to put up the scaffold of your new Python project.
#     Learn more under: https://pyscaffold.org/
# """
# import sys
# from pkg_resources import VersionConflict, require
# from setuptools import setup

# from management.update_licenses import UpdateLicenses

# try:
#     require('setuptools>=38.3')
# except VersionConflict:
#     print("Error: version of setuptools is too old (<38.3)!")
#     sys.exit(1)


# if __name__ == "__main__":
#     setup(
#         use_pyscaffold=True,
#         cmdclass={"update_licenses": UpdateLicenses}
#     )

import sys
import os
import platform
import fnmatch
import setuptools

target = platform.system().lower()
PLATFORMS = {'windows', 'linux', 'darwin', 'cygwin'}
for known in PLATFORMS:
    if target.startswith(known):
        target = known


def run_setup(with_binary):
    if with_binary:
        
        extra_compile_args = {
            'windows': ['/DANTLR4CPP_STATIC'],
            'linux': ['-std=c++11'],
            'darwin': ['-std=c++11'],
            'cygwin': ['-std=c++11'],
        }

        # Define an Extension object that describes the Antlr accelerator
        parser_ext = setuptools.Extension(
            # Extension name shall be at the same level as the sa_mygrammar_parser.py module
            # name='spam.parser.sa_mygrammar_cpp_parser',
            name='modelica_builder.modelica_parser.sa_modelica_cpp_parser',

            # Add the Antlr runtime source directory to the include search path
            # include_dirs=["src/spam/parser/cpp_src/antlr4-cpp-runtime"],
            include_dirs=["src/modelica_builder/modelica_parser/cpp_src/antlr4-cpp-runtime"],

            # Rather than listing each C++ file (Antlr has a lot!), discover them automatically
            sources=get_files("src/modelica_builder/modelica_parser/cpp_src", "*.cpp"),
            depends=get_files("src/modelica_builder/modelica_parser/cpp_src", "*.h"),

            extra_compile_args=extra_compile_args.get(target, [])
        )
        ext_modules = [parser_ext]
    else:
        ext_modules = []

    # Define a package
    setuptools.setup (
        name='modelica_builder',
        version='1.0.0',
        description='Example Speedy Antlr project',
        packages=setuptools.find_packages("src"),
        package_dir={"": "src"},
        include_package_data=True,
        install_requires=[
            "antlr4-python3-runtime",
        ],
        ext_modules=ext_modules,
        cmdclass={"build_ext": ve_build_ext},
    )

#===============================================================================
from setuptools.command.build_ext import build_ext
from distutils.errors import CCompilerError, DistutilsExecError, DistutilsPlatformError

def get_files(path, pattern):
    """
    Recursive file search that is compatible with python3.4 and older
    """
    matches = []
    for root, _, filenames in os.walk(path):
        for filename in fnmatch.filter(filenames, pattern):
            matches.append(os.path.join(root, filename))
    return matches


class BuildFailed(Exception):
    pass


class ve_build_ext(build_ext):
    """
    This class extends setuptools to fail with a common BuildFailed exception
    if a build fails
    """

    def run(self):
        try:
            build_ext.run(self)
        except DistutilsPlatformError:
            raise BuildFailed()

    def build_extension(self, ext):
        try:
            build_ext.build_extension(self, ext)
        except (CCompilerError, DistutilsExecError, DistutilsPlatformError):
            raise BuildFailed()
        except ValueError:
            # this can happen on Windows 64 bit, see Python issue 7511
            if "'path'" in str(sys.exc_info()[1]):  # works with Python 2 and 3
                raise BuildFailed()
            raise


# Detect if an alternate interpreter is being used
is_jython = "java" in sys.platform
is_pypy = hasattr(sys, "pypy_version_info")

# Force using fallback if using an alternate interpreter
using_fallback = is_jython or is_pypy

if not using_fallback:
    try:
        run_setup(with_binary=True)
    except BuildFailed:
        if 'SPAM_EXAMPLE_REQUIRE_CI_BINARY_BUILD' in os.environ:
            # Require build to pass if running in travis-ci
            raise
        else:
            using_fallback = True

if using_fallback:
    run_setup(with_binary=False)