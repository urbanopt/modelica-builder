===========================
Modelica Builder (ModBuild)
===========================

*Note: this project is still in flux and the name/methods/namespaces may change*

The Modelica Builder  project aims to make in-place modifcations to Modelica language files easier.
The principal use case is to load, modify using higher level abstracted methods, and then save the
resulting file. The user has access to the entire Abstract Syntax Tree of the entire Modelica grammar.


.. code-block:: python

    transformation = ReplaceComponentArgumentValueByType("ElectroMechanicalElement", "k", "8")
    transformer = Transformer()
    transformer.add(transformation)

    result = transformer.execute('DCMotor.mo')

    # new file (as a string) will be in the result variable
    print(result)


The Modelica Builder project does not:

* Compile nor check for syntax validity


Setup
-----

.. code-block:: bash

    # install
    pip install -r requirements.txt

Usage
-----
Transformations specify what nodes to change and how to change them. This is done by combining
Selectors and Edits. Selectors specify how to select nodes in the AST, and edits are modifications
(insert, replace, delete) to the text of selected nodes.

A Transformer is a collection of Transformations, which can then be applied to a file.

See the tests for more examples and information.


Development
-----------

If you change the source grammar file you need to regenerate the parser and lexer.

With docker installed, run these commands from this the repo's root directory

.. code-block:: bash

    # build Antlr container
    docker build -t antlr4:latest -f antlr/Dockerfile .

    # run parser generator for python
    docker run -v "$(pwd)/modelica_builder/modelica_parser":/var/antlrResult \
        antlr4:latest \
        -Dlanguage=Python3 /var/antlrResult/modelica.g4

    # commit results along with grammar file


If not using Docker, Install antlr4 following `these instructions <https://github.com/antlr/antlr4/blob/master/doc/getting-started.md#installation>`_

.. code-block:: bash

    # in modelica_building/modelica_parser
    antlr4 -Dlanguage=Python3 modelica.g4

    # commit results along with grammar file

Managed Tasks
-------------

Updating Licenses
*****************

To apply the copyright/license to all the files, run the following managed task. To update, then update the
script, and then rerun the managed task.

.. code-block:: bash

    ./setup.py update_licenses


Testing
*******

To run the tests, simply run the following:

.. code-block:: python

    py.test

Known Issues
------------

* The transformations occur on strings which are immutable. Need to investigate using byte arrays. This does not
cause errors, but can be slow when parsing really large modelica files.

Release Instructions
--------------------

* Bump version to <NEW_VERSION> in setup.cfg (use semantic versioning as much as possible).
* Run `autopep8` to nicely format the code (or run `pre-commit --all-files`).
* Create a PR against develop into main.
* After main branch passes, then merge and checkout the main branch. Build the distribution using the following code:

.. code-block:: bash

    # Remove old dist packages
    rm -rf dist/*
    python setup.py sdist

* Run `git tag <NEW_VERSION>`. (Note that `python setup.py --version` pulls from the latest tag`.)
* Verify that the files in the dist/* folder have the correct version (no dirty, no sha)
* Run the following to release

.. code-block:: bash

    pip install twine
    twine upload dist/*

* Push the tag to GitHub after everything is published to PyPi, then go to GitHub and add in the CHANGELOG.rst notes into the tagged release and officially release.

.. code-block:: bash

    git push origin <NEW_VERSION>
