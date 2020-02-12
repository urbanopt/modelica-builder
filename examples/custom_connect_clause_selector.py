# This example selects the 'DC.p' of the first connect clause and replaces it
# with 'DC.n'. It also demonstrates how to chain selectors: first we select all
# connect clause nodes, then from those nodes we select the component reference

from modelicabuilder.selector import Selector, ConnectSelector, select
from modelicabuilder.edit import Edit
from modelicabuilder.transformation import Transformation
from modelicabuilder.transformer import Transformer


class ComponentReferenceSelector(Selector):
    def __init__(self, component_identifier):
        self._component_identifier = component_identifier

    def _select(self, root, parser):
        nodes = select(root, parser, 'component_reference')

        # filter out non matching component references
        return [
            node
            for node in nodes
            if node.getText() == self._component_identifier]


def main():
    # select connect clause component reference of "DC.p"
    selector = (ConnectSelector()
                .chain(ComponentReferenceSelector('DC.p')))

    # replace our selected nodes with DC.n
    transformation = Transformation(selector, Edit.make_replace('DC.n'))
    transformer = Transformer()
    transformer.add(transformation)

    result = transformer.execute('DCMotor.mo')

    print("Transformed .mo file:")
    print(result)


if __name__ == '__main__':
    main()
