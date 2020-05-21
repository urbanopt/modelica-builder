"""
****************************************************************************************************
:copyright (c) 2020, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""


from copy import deepcopy

from modelica_builder.edit import Edit
from modelica_builder.selector import (
    EquationSectionSelector,
    NthChildSelector,
    findAll
)


class SimpleTransformation:
    def __init__(self, selector=None, edit=None):
        self.selector = selector
        self.edit = edit

    def build_edits(self, tree, parser):
        selected_nodes = self.selector.apply_to_root(tree, parser)
        return [self.edit(node) for node in selected_nodes]


class ModelAnnotationTransformation:
    def __init__(self, modifications):
        self.modifications = modifications

    def build_edits(self, tree, parser):
        def build_modifications(modifications):
            """returns a string with modifications formatted properly"""
            mod_strings = []
            for mod_name, mod_value in modifications.items():
                if isinstance(mod_value, dict):
                    # treat the modification as a class_modification
                    mod_strings.append(f'{mod_name}({build_modifications(mod_value)})')
                else:
                    # treat the modification as a simple assignment
                    mod_strings.append(f'{mod_name}={mod_value}')
            return ', '.join(mod_strings)

        # try to find the model annotation
        model_annotation_xpath = 'stored_definition/class_definition/class_specifier/long_class_specifier/composition/model_annotation'
        model_annotation_node = findAll(tree, model_annotation_xpath, parser)
        if not model_annotation_node:
            # insert the model annotation along with the modifications
            selector = (EquationSectionSelector()
                        .chain(NthChildSelector(-1))
                        .assert_count(1, 'Failed to find end of the equation section'))

            edit = Edit.make_insert(f'\n\tannotation({build_modifications(self.modifications)});')
            return SimpleTransformation(selector, edit).build_edits(tree, parser)

        def make_edits_for_modifications(class_modification_node, modifications):
            """Constructs a list of edits required to update the node with the
            provided modifications.

            :param class_modification_node: modelicaParser.Class_modificationContext
            :param modifications: dict
            """
            requested_modifications = deepcopy(modifications)
            overwrite_modifications = requested_modifications.pop('OVERWRITE_MODIFICATIONS', False)
            if overwrite_modifications:
                # don't care about selectively updating existing values
                # just overwrite any existing modifications
                new_modifications_string = build_modifications(requested_modifications)
                edit = Edit.make_replace(new_modifications_string)
                # replace the entire argument_list with our new modifications
                return [edit(class_modification_node.argument_list())]

            all_edits = []
            element_modification_xpath = 'class_modification/argument_list/argument/element_modification_or_replaceable/element_modification'
            element_modification_nodes = findAll(class_modification_node, element_modification_xpath, parser)

            # iterate through the existing element modifications
            for element_modification_node in element_modification_nodes:
                # check if there's a request to update this modification
                element_modification_name = element_modification_node.name().getText()
                if element_modification_name in requested_modifications:
                    # found a modification to update
                    requested_modification_value = requested_modifications.pop(element_modification_name)
                    if isinstance(requested_modification_value, dict):
                        # recursively make edits for this modification
                        next_class_modification_node = element_modification_node.modification().class_modification()
                        all_edits += make_edits_for_modifications(next_class_modification_node, requested_modification_value)
                    else:
                        edit = Edit.make_replace(f'={requested_modification_value}')
                        # replace the modification node with our value
                        all_edits.append(edit(element_modification_node.modification()))

            # remaining modifications will need to be inserted (matched modification were removed from the dict)
            if requested_modifications:
                new_modifications_string = build_modifications(requested_modifications)
                edit = Edit.make_insert(', ' + new_modifications_string, insert_after=True)
                all_edits.append(edit(class_modification_node.argument_list()))

            return all_edits

        # model annotation exists, recursively update or insert the modifications
        model_annotation_node = model_annotation_node[0]
        return make_edits_for_modifications(
            model_annotation_node.annotation().class_modification(),
            self.modifications
        )
