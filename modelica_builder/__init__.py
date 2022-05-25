# -*- coding: utf-8 -*-
from pkg_resources import DistributionNotFound, get_distribution

from modelica_builder.transformer import Transformer

try:
    # Change here if project is renamed and does not equal the package name
    dist_name = 'modelica-builder'
    __version__ = get_distribution(dist_name).version
except DistributionNotFound:
    __version__ = 'unknown'
finally:
    del get_distribution, DistributionNotFound

__all__ = ['Transformer',
           'Transformation',
           'Edit',
           'Selector']
