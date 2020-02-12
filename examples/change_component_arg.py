# This example changes the initialization of the ElectroMechanicalElement "EM"
# argument "k"

from modelicabuilder.transformation import ReplaceComponentArgumentValueByType
from modelicabuilder.transformer import Transformer


def main():
    transformation = ReplaceComponentArgumentValueByType(
        "ElectroMechanicalElement",
        "k",
        "8")
    transformer = Transformer()
    transformer.add(transformation)

    result = transformer.execute('DCMotor.mo')

    print("Transformed .mo file:")
    print(result)


if __name__ == '__main__':
    main()
