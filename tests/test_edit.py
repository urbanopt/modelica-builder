"""
****************************************************************************************************
:copyright (c) 2020-2021, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""


# -*- coding: utf-8 -*-

from unittest import TestCase

from modelica_builder.edit import Edit


class TestEdit(TestCase):
    def setUp(self):
        self.data = 'CatBat123'

    def test_make_replace(self):
        # Setup
        replace = Edit.make_replace('Dog')

        # Act
        edit = replace({'start': 0, 'stop': 2})
        result = Edit.apply_edits([edit], self.data)

        # Assert
        self.assertEqual('DogBat123', result)

    def test_make_insert_after(self):
        # Setup
        insert = Edit.make_insert('Dog', insert_after=True)

        # Act
        edit = insert({'start': 0, 'stop': 2})
        result = Edit.apply_edits([edit], self.data)

        # Assert
        self.assertEqual('CatDogBat123', result)

    def test_make_insert_before(self):
        # Setup
        insert = Edit.make_insert('Dog', insert_after=False)

        # Act
        edit = insert({'start': 0, 'stop': 2})
        result = Edit.apply_edits([edit], self.data)

        # Assert
        self.assertEqual('DogCatBat123', result)
