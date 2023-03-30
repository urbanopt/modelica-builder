=========
Changelog
=========

Version 0.2.3
=============
* Update precommit and ci by @nllong in https://github.com/urbanopt/modelica-builder/pull/54
* Update overwrite_component_redeclaration to handle the redeclare of args by @nllong in https://github.com/urbanopt/modelica-builder/pull/53

Version 0.2.2
=============

* Add component argument/parameter deletion, remove_component_argument
* Add test for deleting a "constant Ingeger x=5" component
* Update testing dependencies
* Add component redeclare package argument replacement

Version 0.2.1
=============

* Fix import issue when installing package for a poetry-managed projects

Version 0.2.0
=============

* Fix compatibility with files containing '\r\n', which is typically used on Windows

Version 0.1.1
=============

* Add ability to rename a component's argument name
* Convert to use GitHub actions instead of Travis
* Update README with more practical example

Version 0.1.0
=============

* Initial release
