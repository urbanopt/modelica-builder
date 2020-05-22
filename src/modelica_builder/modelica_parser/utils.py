"""
****************************************************************************************************
:copyright (c) 2020, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""

import os


from antlr4 import FileStream, CommonTokenStream
from antlr4.tree.Tree import TerminalNodeImpl

from modelica_builder.modelica_parser.modelicaLexer import modelicaLexer
from modelica_builder.modelica_parser.modelicaParser import modelicaParser
from modelica_builder.modelica_parser import sa_modelica


def parse(source, use_cpp=True):
    """parse creates an AST from the given file

    :param source: string, file to parse
    :return: tree, parser, the tree and parser used to construct the tree
    """
    # allow tests to set the environment variable to determine the parser version
    if 'TEST_USE_PYTHON_PARSER' in os.environ:
        use_cpp = False
        print('INFO: overriding `use_cpp` to False because env var TEST_USE_PYTHON_PARSER was found')

    fs = FileStream(source)
    if use_cpp:
        if not sa_modelica.USE_CPP_IMPLEMENTATION:
            raise Exception('sa_modelica could not use C++ implementation')
        print("INFO: using C++ parser")
        tree = sa_modelica.parse(fs, 'stored_definition')
        return tree, None

    print("INFO: using python parser")
    lexer = modelicaLexer(fs)
    stream = CommonTokenStream(lexer)
    parser = modelicaParser(stream)
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

    # when using the C++ parser, there are some cases where the node's start or
    # stop property is None, so this might raise an attribute error
    # When this happens, it means there's a rule that matches an empty string, and
    # the grammar should be updated s.t. that's not possible
    # Issue here: https://github.com/amykyta3/speedy-antlr-tool/issues/3
    start = node.start.start
    stop = node.stop.stop

    return start, stop
