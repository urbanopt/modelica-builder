import os

from modelica_builder.edit import Edit
from modelica_builder.selector import NthChildSelector, ConnectClauseSelector
from modelica_builder.transformation import Transformation
from modelica_builder.transformer import Transformer
from modelica_builder.builder import ConnectBuilder


class Model(Transformer):
    def __init__(self, source):
        if not os.path.exists(source):
            raise Exception(f'Modelica file does not exist: {source}')
        super().__init__(source)

    def add_connect(self, port_a, port_b, annotations=None):
        """add_connect creates a new connect clause in the equation section

        :param port_a: string, first port identifier
        :param port_b: string, second port identifier
        :param annotations: array of strings, optional annotations to add
        """
        connect = ConnectBuilder(port_a, port_b, annotations)
        self.add(connect.transformation())

    def edit_connect(self, port_a, port_b, new_port_a=None, new_port_b=None):
        """edit_connect finds all connect clauses that match the pattern
        connect(<port_a>, <port_b>), in that order. If a port is an asterisk, '*',
        then it matches any identifier.

        :param port_a: string, identifier for first port; an asterisk matches all
        :param port_b: string, identifier for second port; an asterisk matches all
        :param new_port_a: string | None, replacement for port a; if None no changes are made
        :param new_port_b: string | None, replacement for port b; if None no changes are made
        """
        # verify the paramaters are sensible
        if (port_a == '*' and new_port_a is not None) or (port_b == '*' and new_port_b is not None):
            raise Exception('Invalid to have a port match a wildcard and replace it (might result in duplicate clauses)')

        # make up to two transformations (one for each replacement)
        if new_port_a is not None:
            selector = (ConnectClauseSelector(port_a, port_b)
                        .chain(NthChildSelector(2)))
            self.add(Transformation(selector, Edit.make_replace(new_port_a)))

        if new_port_b is not None:
            selector = (ConnectClauseSelector(port_a, port_b)
                        .chain(NthChildSelector(4)))
            self.add(Transformation(selector, Edit.make_replace(new_port_b)))
