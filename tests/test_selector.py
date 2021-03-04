"""
****************************************************************************************************
:copyright (c) 2020-2021, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""


# -*- coding: utf-8 -*-

import os
from unittest import TestCase

from modelica_builder.modelica_parser import parse
from modelica_builder.selector import ElementListSelector, NthChildSelector, Selector

from .tests import ASTAssertions


class TestSelectors(TestCase, ASTAssertions):
    def setUp(self):
        self.data_dir = os.path.join(os.path.dirname(__file__), 'data')
        self.output_dir = os.path.join(os.path.dirname(__file__), 'output')
        if not os.path.exists(self.output_dir):
            os.makedirs(self.output_dir)

    def test_assert_count_fails(self):
        # Setup
        class NoneSelector(Selector):
            """NoneSelector selects nothing"""

            def _select(self, root, parser):
                return []

        tree, parser = parse(os.path.join(self.data_dir, 'DCMotor.mo'))

        # Act, Assert
        selector = NoneSelector().assert_count(1, 'Unexpected number of nodes selected')

        with self.assertRaises(Exception):
            selector.apply_to_root(tree, parser)

    def test_assert_count_passes(self):
        # Setup
        class OneSelector(Selector):
            """OneSelector selects one node"""

            def _select(self, root, parser):
                # note that we aren't really using a node from tree
                # it shouldn't matter for this test
                return [{}]

        tree, parser = parse(os.path.join(self.data_dir, 'DCMotor.mo'))

        # Act, Assert
        selector = OneSelector().assert_count(1, 'Unexpected number of nodes selected')
        # no exception should be raised
        selector.apply_to_root(tree, parser)

    def test_element_list_selector(self):
        # Setup
        tree, parser = parse(os.path.join(self.data_dir, 'DCMotor.mo'))

        # Act
        selector = ElementListSelector()
        element_list = selector.apply_to_root(tree, parser)

        # Assert
        self.assertEqual(1, len(element_list), "should have one element list")
        self.assertIsRule(element_list[0], 'element_list', parser)

    def test_nth_child_selector(self):
        # Setup
        tree, parser = parse(os.path.join(self.data_dir, 'DCMotor.mo'))

        # Act
        selector = (ElementListSelector().chain(NthChildSelector(1)))
        element = selector.apply_to_root(tree, parser)

        # Assert
        self.assertEqual(1, len(element), "should have one element")
        # the third child should be the Inductor line
        # (semicolons are also children of the element_list)
        elementText = element[0].getText()
        self.assertTrue(elementText.startswith('Inductor'))
