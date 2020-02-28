# -*- coding: utf-8 -*-

import os
from unittest import TestCase

from .tests import ASTAssertions

from modelica_builder.selector import ElementListSelector, NthChildSelector
from modelica_builder.modelica_parser import parse


class TestSelectors(TestCase, ASTAssertions):
    def setUp(self):
        self.data_dir = os.path.join(os.path.dirname(__file__), 'data')
        self.output_dir = os.path.join(os.path.dirname(__file__), 'output')
        if not os.path.exists(self.output_dir):
            os.makedirs(self.output_dir)

    def test_element_list_selector(self):
        # Setup
        tree, parser = parse(os.path.join(self.data_dir, 'DCMotor.mo'))

        # Act
        selector = ElementListSelector()
        element_list = selector.apply(tree, parser)

        # Assert
        self.assertEqual(1, len(element_list), "should have one element list")
        self.assertIsRule(element_list[0], 'element_list', parser)

    def test_nth_child_selector(self):
        # Setup
        tree, parser = parse(os.path.join(self.data_dir, 'DCMotor.mo'))

        # Act
        selector = (ElementListSelector()
                    .chain(NthChildSelector(2)))
        element = selector.apply(tree, parser)

        # Assert
        self.assertEqual(1, len(element), "should have one element")
        # the third child should be the Inductor line
        # (semicolons are also children of the element_list)
        elementText = element[0].getText()
        self.assertTrue(elementText.startswith('Inductor'))
