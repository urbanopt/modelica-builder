#!/bin/bash

docker build -t antlr4:latest -f antlr/Dockerfile .

# Generate C++ target with visitor
docker run -v "$(pwd)/modelica_builder/modelica_parser":/var/antlrResult \
        antlr4:latest \
        -Dlanguage=Cpp -visitor -no-listener -o /var/antlrResult/cpp_src /var/antlrResult/modelica.g4
        # -Dlanguage=Cpp  -o /var/antlrResult/cpp_src /var/antlrResult/modelica.g4

# Generate Python target
docker run -v "$(pwd)/modelica_builder/modelica_parser":/var/antlrResult \
        antlr4:latest \
        -Dlanguage=Python3 -no-visitor -no-listener -o /var/antlrResult /var/antlrResult/modelica.g4
        # -Dlanguage=Python3 -o /var/antlrResult /var/antlrResult/modelica.g4

# Run antlr tool to generate the accelerator files
python3 <<EOF
from speedy_antlr_tool import generate

generate(
    py_parser_path="modelica_builder/modelica_parser/modelicaParser.py",
    cpp_output_dir="modelica_builder/modelica_parser/cpp_src",
)
EOF
