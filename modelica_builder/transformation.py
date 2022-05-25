"""
****************************************************************************************************
:copyright (c) 2020-2022, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""


import logging
from antlr4.xpath import XPath
from copy import deepcopy

from modelica_builder import config
from modelica_builder.edit import Edit
from modelica_builder.selector import (
    ComponentDeclarationSelector,
    EquationSectionSelector,
    NthChildSelector
)

logger = logging.getLogger(__name__)


class SimpleTransformation:
    def __init__(self, selector=None, edit=None):
        self.selector = selector
        self.edit = edit

    def build_edits(self, tree, parser):
        selected_nodes = self.selector.apply_to_root(tree, parser)
        return [self.edit(node) for node in selected_nodes]


def build_modifications(modifications, depth=1, indented=True):
    """returns a string with modifications formatted properly

    :param modifications: dict
    :param depth: int, current modification depth, used for determining code indentation
    :param indent: bool, if true each inserted modification will be indented on new line
    :return: string
    """
    mod_strings = []
    for mod_name, mod_value in modifications.items():
        if isinstance(mod_value, dict):
            # treat the modification as a class_modification
            mod_strings.append(f'{mod_name}({build_modifications(mod_value, depth + 1, indented)})')
        else:
            # treat the modification as a simple assignment
            mod_strings.append(f'{mod_name}={mod_value}')

    if indented:
        # depth + 1 because we assume the _root_ thing we're modifying in the
        # modelica code is already indented once
        # e.g. a component declaration is usually indented once
        indent_depth = depth + 1
        indentation = '\n' + config.INDENTATION * indent_depth
    else:
        indentation = ''

    return indentation + f',{indentation}'.join(mod_strings)


def make_edits_for_modifications(class_modification_node, modifications, parser, depth=1, indented=False):
    """Constructs a list of edits required to update the node with the
    provided modifications.

    :param class_modification_node: modelicaParser.Class_modificationContext
    :param modifications: dict
    :param parser: antlr4.Parser
    :param depth: int, current modification depth, used for determining code indentation
    :param indent: bool, if true each inserted modification will be indented on new line
    """
    requested_modifications = deepcopy(modifications)
    overwrite_modifications = requested_modifications.pop('OVERWRITE_MODIFICATIONS', False)
    if overwrite_modifications:
        # don't care about selectively updating existing values
        # just overwrite any existing modifications
        new_modifications_string = build_modifications(
            requested_modifications,
            depth=depth,
            indented=indented)
        edit = Edit.make_replace(new_modifications_string)
        # replace the entire argument_list with our new modifications
        return [edit(class_modification_node.argument_list())]

    all_edits = []
    element_modification_xpath = 'class_modification/argument_list/argument/element_modification_or_replaceable/element_modification'
    element_modification_nodes = XPath.XPath.findAll(class_modification_node, element_modification_xpath, parser)

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
                all_edits += make_edits_for_modifications(
                    next_class_modification_node,
                    requested_modification_value,
                    parser,
                    depth=depth + 1,
                    indented=indented)
            else:
                edit = Edit.make_replace(f'={requested_modification_value}')
                # replace the modification node with our value
                all_edits.append(edit(element_modification_node.modification()))

    # remaining modifications will need to be inserted (matched modification were removed from the dict)
    if requested_modifications:
        new_modifications_string = build_modifications(
            requested_modifications,
            depth=depth,
            indented=indented)
        edit = Edit.make_insert(', ' + new_modifications_string, insert_after=True)
        all_edits.append(edit(class_modification_node.argument_list()))

    return all_edits


class ModelAnnotationTransformation:
    def __init__(self, modifications):
        self.modifications = modifications

    def build_edits(self, tree, parser):
        # try to find the model annotation
        model_annotation_xpath = 'stored_definition/class_definition/class_specifier/long_class_specifier/composition/model_annotation'
        model_annotation_node = XPath.XPath.findAll(tree, model_annotation_xpath, parser)
        if not model_annotation_node:
            # insert the model annotation along with the modifications
            selector = (EquationSectionSelector()
                        .chain(NthChildSelector(-1))
                        .assert_count(1, 'Failed to find end of the equation section'))

            edit = Edit.make_insert(f'\n{config.INDENTATION}annotation({build_modifications(self.modifications, indented=False)});')
            return SimpleTransformation(selector, edit).build_edits(tree, parser)

        # model annotation exists, recursively update or insert the modifications
        model_annotation_node = model_annotation_node[0]
        return make_edits_for_modifications(
            model_annotation_node.annotation().class_modification(),
            self.modifications,
            parser,
            indented=config.INDENT_INSERTED_ANNOTATION_ARGS,
        )


class ComponentModificationsTransformation:
    def __init__(self, type_, identifier, modifications):
        """Provides a transformation that inserts or updates a component's
        modifications

        :param type_: string, component type
        :param identifier: string, component identifier
        :param modifications: dict, modifications to update
        """
        self._type = type_
        self._identifier = identifier
        self._modifications = modifications

    def build_edits(self, tree, parser):
        # try to find the component declaration
        component_declaration_selector = ComponentDeclarationSelector(self._type, self._identifier)
        component_declaration_nodes = component_declaration_selector.apply_to_root(tree, parser)

        # if we failed to find the component declaration, do nothing
        if len(component_declaration_nodes) == 0:
            return []

        # for each selected declaration node, try to build edits
        all_component_edits = []
        for idx, component_declaration_node in enumerate(component_declaration_nodes):
            class_modification_node = None
            try:
                class_modification_node = component_declaration_node.declaration().modification().class_modification()
            except Exception as e:
                logger.debug(str(e), exc_info=True)
                logger.warning(f'Failed to find class_modification context for #{idx} component_declaration where type="{self._type}" and identifier="{self._identifier}"; skipping modification updates')
                continue

            all_component_edits += make_edits_for_modifications(
                class_modification_node,
                self._modifications,
                parser,
                indented=config.INDENT_INSERTED_COMPONENT_ARGS,
            )

        return all_component_edits
