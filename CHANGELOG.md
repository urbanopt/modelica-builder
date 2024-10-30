# Changelog

## Version 0.5.2
### What's Changed
* build(deps): bump jinja2 from 3.1.2 to 3.1.3 by @dependabot in https://github.com/urbanopt/modelica-builder/pull/84
* build(deps-dev): bump requests from 2.31.0 to 2.32.0 by @dependabot in https://github.com/urbanopt/modelica-builder/pull/87
* Add Modelica measure base classes by @nllong in https://github.com/urbanopt/modelica-builder/pull/76
* Update certifi and jinja by @nllong in https://github.com/urbanopt/modelica-builder/pull/94
* Prep 0.5.2-rc2 release by @nllong in https://github.com/urbanopt/modelica-builder/pull/95
* Update GitHub action versions by @nllong in https://github.com/urbanopt/modelica-builder/pull/97
* Parse Modelica parameters with non-primitive types by @vtnate in https://github.com/urbanopt/modelica-builder/pull/98
* Add from_list method to create an MOS file by @nllong in https://github.com/urbanopt/modelica-builder/pull/100


**Full Changelog**: https://github.com/urbanopt/modelica-builder/compare/v0.5.1...v0.5.2

## Version 0.5.1

### What's Changed

* Ensure the correct template is loaded when parsing the package by @vtnate in https://github.com/urbanopt/modelica-builder/pull/81
* Create config file to automatically publish to pypi when a Github release is made by @vtnate in https://github.com/urbanopt/modelica-builder/pull/82

**Full Changelog**: https://github.com/urbanopt/modelica-builder/compare/v0.5.0...v0.5.1

## Version 0.5.0

### What's Changed

* Support py312 by @vtnate in https://github.com/urbanopt/modelica-builder/pull/73
* Add method to scale loads in an MOS file by @nllong in https://github.com/urbanopt/modelica-builder/pull/74
* Bump version of antlr runtime to 4.13.1 by @nllong in https://github.com/urbanopt/modelica-builder/pull/75
* Add `.mpignore` to skip loading files in ModelicaProject by @nllong in https://github.com/urbanopt/modelica-builder/pull/77
* Upgrade to MBLv10 by @vtnate in https://github.com/urbanopt/modelica-builder/pull/72
* Update copyright dates by @nllong in https://github.com/urbanopt/modelica-builder/pull/80

**Full Changelog**: https://github.com/urbanopt/modelica-builder/compare/v0.4.0...v0.5.0

## Version 0.4.0

### What's Changed

* Add get method for a component's argument by @nllong in https://github.com/urbanopt/modelica-builder/pull/57
* Update README.rst by @nllong in https://github.com/urbanopt/modelica-builder/pull/58
* build(deps): bump pygments from 2.12.0 to 2.15.0 by @dependabot in https://github.com/urbanopt/modelica-builder/pull/60
* Add extends redeclare update method by @nllong in https://github.com/urbanopt/modelica-builder/pull/59
* Add method for getting and setting parameters by @nllong in https://github.com/urbanopt/modelica-builder/pull/61
* Bump version and update test dependencies by @nllong in https://github.com/urbanopt/modelica-builder/pull/62
* update _source filename when calling save_as by @nllong in https://github.com/urbanopt/modelica-builder/pull/64
* update deprecated import statements by @vtnate in https://github.com/urbanopt/modelica-builder/pull/65
* Add poetry and remove tox by @nllong in https://github.com/urbanopt/modelica-builder/pull/67
* Move Modelica methods over from GMT by @nllong in https://github.com/urbanopt/modelica-builder/pull/68
* Update antlr4 and use a non-deprecated docker base image by @vtnate in https://github.com/urbanopt/modelica-builder/pull/66

## New Contributors
* @vtnate made their first contribution in https://github.com/urbanopt/modelica-builder/pull/65

**Full Changelog**: https://github.com/urbanopt/modelica-builder/compare/v0.3.0...v0.4.0

## Version 0.3.0

* bump version and copyright dates by @nllong in https://github.com/urbanopt/modelica-builder/pull/55
* Add get method for a component's argument by @nllong in https://github.com/urbanopt/modelica-builder/pull/57
* Update README.rst by @nllong in https://github.com/urbanopt/modelica-builder/pull/58
* build(deps): bump pygments from 2.12.0 to 2.15.0 by @dependabot in https://github.com/urbanopt/modelica-builder/pull/60
* Add extends redeclare update method by @nllong in https://github.com/urbanopt/modelica-builder/pull/59
* Add method for getting and setting parameters by @nllong in https://github.com/urbanopt/modelica-builder/pull/61

## Version 0.2.3

* Update precommit and ci by @nllong in https://github.com/urbanopt/modelica-builder/pull/54
* Update overwrite_component_redeclaration to handle the redeclare of args by @nllong in https://github.com/urbanopt/modelica-builder/pull/53

## Version 0.2.2

* Add component argument/parameter deletion, remove_component_argument
* Add test for deleting a "constant Integer x=5" component
* Update testing dependencies
* Add component redeclare package argument replacement

## Version 0.2.1

* Fix import issue when installing package for a poetry-managed projects

# Version 0.2.0

* Fix compatibility with files containing '\r\n', which is typically used on Windows

## Version 0.1.1

* Add ability to rename a component's argument name
* Convert to use GitHub actions instead of Travis
* Update README with more practical example

## Version 0.1.0

* Initial release
