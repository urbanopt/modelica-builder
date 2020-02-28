import difflib


class ASTAssertions:
    def assertIsRule(self, element, expected_rule, parser):
        element_rule = parser.ruleNames[element.getRuleIndex()]
        if element_rule != expected_rule:
            raise AssertionError(f'Element does not match expected rule. Expected {expected_rule} but was {element_rule}')


def ignore_diff(line):
    return len(clean_diff(line).strip()) == 0


def clean_diff(line):
    return line[1:]


def get_diffs(original, new):
    differ = difflib.Differ()
    diffs = list(differ.compare(original, new))

    return {
        'additions': [clean_diff(d) for d in diffs if d.startswith('+') and not ignore_diff(d)],
        'subtractions': [clean_diff(d) for d in diffs if d.startswith('-') and not ignore_diff(d)]
    }
