# :copyright (c) URBANopt, Alliance for Sustainable Energy, LLC, and other contributors.
# See also https://github.com/urbanopt/modelica-builder/blob/develop/LICENSE.md


# -*- coding: utf-8 -*-

import pytest

import os

from modelica_builder.model import Model

large_file = os.path.join(os.path.join(os.path.dirname(__file__), 'data'), 'Office.mo')
small_file = os.path.join(os.path.join(os.path.dirname(__file__), 'data'), 'DCMotor.mo')

# used for parameterized benchmarks for comparing performance on different file sizes
bench_file_size_data = [
    ("large", large_file),
    ("small", small_file),
]


@pytest.mark.parametrize("size,filename", bench_file_size_data)
def test_bench_parse_and_execute(benchmark, size, filename):
    def parse_and_execute(filename):
        """just parses a file then executes it without edits"""
        mo = Model(filename)
        mo.execute()

    benchmark(parse_and_execute, filename)
