from antlr4 import FileStream, CommonTokenStream

from modelicabuilder.modelicaparser.modelicaLexer import modelicaLexer
from modelicabuilder.modelicaparser.modelicaParser import modelicaParser

__all__ = [
    'modelicaLexer',
    'modelicaParser',
    'parse'
]


def parse(source):
    """parse creates an AST from the given file

    :param source: string, file to parse
    :return: tree, parser, the tree and parser used to construct the tree
    """
    fs = FileStream(source)
    lexer = modelicaLexer(fs)
    stream = CommonTokenStream(lexer)
    parser = modelicaParser(stream)
    tree = parser.stored_definition()

    return tree, parser
