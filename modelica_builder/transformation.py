"""
****************************************************************************************************
:copyright (c) 2020, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""


from collections import namedtuple

from modelica_builder.edit import Edit
from modelica_builder.selector import (
    ComponentArgumentValueSelector,
    ComponentDeclarationByTypeSelector
)

# Transformation is an abstraction of a collection of nodes and changes to
# those nodes. selector indicates which nodes to apply the change to.
# edit indicates the change to apply
Transformation = namedtuple('Transformation', ['selector', 'edit'])


def ReplaceComponentArgumentValueByType(
        component_type,
        argument_name,
        new_value):
    """ReplaceComponentArgumentValueByType creates a transformation which changes a
    component's initialization value for an argument

    :param component_type: string, type of the component to select
    :param argument_name: string, name of argument to modify
    :param new_value: string, new argument value
    :return: Transformation
    """
    selector = (ComponentDeclarationByTypeSelector(component_type)
                .chain(ComponentArgumentValueSelector(argument_name)))
    edit = Edit.make_replace(new_value)

    return Transformation(selector, edit)
