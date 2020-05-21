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
    # stop property is None. I'm not sure if this is do the parser itself or the
    # C++ parser interface.
    try:
        start = node.start.start
    except AttributeError:
        start = None
    try:
        stop = node.stop.stop
    except AttributeError:
        stop = None

    if start is None and stop is None:
        raise Exception('Unable to determine the start and stop of the node. If using the C++ parser, consider using the python parser instead')
    if start is None:
        start = stop - len(node.getText())
    if stop is None:
        stop = start + len(node.getText())
    return start, stop
