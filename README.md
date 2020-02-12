# Modelica Transformer
Package for parsing and transforming Modelica documents.

## Setup
```bash
# install
pip install ./

# install for dev
pip install --editable ./
```

## Usage
Transformations are how we specify what nodes to change and how to change them. This is done by combining Selectors and Edits. Selectors specify how to select nodes in the AST, and edits are modifications (insert, replace, delete) to the text of selected nodes.

A Transformer is a collection of Transformations, which can then be applied to a file.

See the examples directory for more information.

## Development
If you change the source grammar file you need to regenerate the parser and lexer.

With docker installed, run these commands from this the repo's root directory
```bash
# build Antlr container
docker build -t antlr4:latest -f antlr/Dockerfile .

# run parser generator for python
docker run -v "$(pwd)/modelicaTransformer/modelicaAntlr":/var/antlrResult \
  antlr4:latest \
  -Dlanguage=Python3 /var/antlrResult/modelica.g4

# commit results along with grammar file
```

If not using Docker, Install antlr4 following [these instructions](https://github.com/antlr/antlr4/blob/master/doc/getting-started.md#installation)
```bash
# in modelicaTransformer/modelicaAntlr
antlr4 -Dlanguage=Python3 modelica.g4

# commit results along with grammar file
```

