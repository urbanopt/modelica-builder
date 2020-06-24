"""
****************************************************************************************************
:copyright (c) 2020, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""

import sys

from antlr4 import FileStream, CommonTokenStream
from antlr4.error.ErrorListener import ErrorListener
from antlr4.tree.Tree import TerminalNodeImpl

from modelica_builder.modelica_parser.modelicaLexer import modelicaLexer
from modelica_builder.modelica_parser.modelicaParser import modelicaParser


class ModelicaErrorListener(ErrorListener):
    def __init__(self, filepath, *args, **kwargs):
        self._filepath = filepath
        super().__init__(*args, **kwargs)

    def syntaxError(self, recognizer, offending_symbol, line, column, msg, e):
        print(f"{self._filepath}:{line}:{column}: {msg}", file=sys.stderr)


def parse(source):
    """parse creates an AST from the given file

    :param source: string, file to parse
    :return: tree, parser, the tree and parser used to construct the tree
    """
    fs = FileStream(source)
    lexer = modelicaLexer(fs)
    stream = CommonTokenStream(lexer)
    parser = modelicaParser(stream)
    parser.removeErrorListeners()
    parser.addErrorListener(ModelicaErrorListener(source))
    tree = parser.stored_definition()

    return tree, parser


def is_terminal_node(node):
    return type(node) is TerminalNodeImpl


def get_span(node):
    """get the character start and end of a node

    :param node: object or dict, node to get span
    :return: start, stop, character indices for start and stop of node
    """
    # allow dicts for easy mocking
    if type(node) is dict:
        return node['start'], node['stop']

    if is_terminal_node(node):
        return node.symbol.start, node.symbol.stop

    return node.start.start, node.stop.stop
