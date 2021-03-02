"""
****************************************************************************************************
:copyright (c) 2020-2021, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""


import difflib


class ASTAssertions:
    def assertIsRule(self, element, expected_rule, parser):
        element_rule = parser.ruleNames[element.getRuleIndex()]
        if element_rule != expected_rule:
            raise AssertionError(f'Element does not match expected rule. Expected {expected_rule} but was {element_rule}')


class DiffAssertions:
    def assertArrayHasDiffs(self, type_, original, new, expected_diffs, strict=True):
        """Asserts that the arrays original and new have differences of the given type.

        :param type_: string, additions or deletions
        :param original: array of strings, base array for comparison
        :param new: array of strings, array to calculate differences off of the original
        :param expected_diffs: array of strings: expected differences of the given type
        :strict: bool, if true then expected_diffs must account for all diffs of given type
        """
        diffs = get_diffs(original, new)
        actual_diffs = diffs[type_]

        missing_diffs = []
        for expected_diff in expected_diffs:
            found = False
            for actual_diff in actual_diffs:
                if expected_diff in actual_diff:
                    found = True
                    break
            if not found:
                missing_diffs.append(expected_diff)

        if missing_diffs:
            raise AssertionError(f'Expected to find additions {missing_diffs} in {actual_diffs}')

        n_expected = len(expected_diffs)
        n_actual = len(actual_diffs)
        if strict and n_expected != n_actual:
            raise AssertionError(f'Expected {n_expected} {type_}, but found {n_actual}:\n  EXPECTED: {expected_diffs}\n  ACTUAL: {actual_diffs}')

    def assertHasDeletions(self, original_filename, new_content, deletions, strict=True):
        """Asserts that the new content has deleted lines from the original file

        :param original_filename: string, file whose content serves as the base comparison
        :param new_content: string, content to compare to the file's content
        :param deletions: array of strings, lines expected to be deleted (leading and trailing whitespace ignored)
        :param strict: bool, if true, then provided deletions must account for all deletions
        """
        with open(original_filename, 'r') as f:
            original_lines = f.readlines()
        new_lines = new_content.splitlines(keepends=True)
        self.assertArrayHasDiffs('deletions', original_lines, new_lines, deletions, strict)

    def assertHasAdditions(self, original_filename, new_content, additions, strict=True):
        """Asserts that the new content has added lines to the original file

        :param original_filename: string, file whose content serves as the base comparison
        :param new_content: string, content to compare to the file's content
        :param additions: array of strings, lines expected to be added (leading and trailing whitespace ignored)
        :param strict: bool, if true, then provided additions must account for all additions
        """
        with open(original_filename, 'r') as f:
            original_lines = f.readlines()
        new_lines = new_content.splitlines(keepends=True)
        self.assertArrayHasDiffs('additions', original_lines, new_lines, additions, strict)

    def _assertNoDiffs(self, type_, original, new):
        diffs = get_diffs(original, new)
        actual_diffs = diffs[type_]
        if len(actual_diffs) != 0:
            raise AssertionError(f'Expected no {type_} but found {len(actual_diffs)}: {actual_diffs}')

    def assertNoDeletions(self, original_filename, new_content):
        with open(original_filename, 'r') as f:
            original_lines = f.readlines()
        new_lines = new_content.splitlines(keepends=True)
        self._assertNoDiffs('deletions', original_lines, new_lines)

    def assertNoAdditions(self, original_filename, new_content):
        with open(original_filename, 'r') as f:
            original_lines = f.readlines()
        new_lines = new_content.splitlines(keepends=True)
        self._assertNoDiffs('additions', original_lines, new_lines)


def ignore_diff(line):
    return len(clean_diff(line).strip()) == 0


def clean_diff(line):
    return line[1:]


def get_diffs(original, new):
    # remove empty lines before comparing, allowing for a 'cleaner' diffing
    original_compacted = [line.strip() for line in original if line.strip()]
    new_compacted = [line.strip() for line in new if line.strip()]

    # compare the arrays and group additions and deletions
    differ = difflib.Differ()
    diffs = list(differ.compare(original_compacted, new_compacted))

    return {
        'additions': [clean_diff(d) for d in diffs if d.startswith('+')],
        'deletions': [clean_diff(d) for d in diffs if d.startswith('-')]
    }
