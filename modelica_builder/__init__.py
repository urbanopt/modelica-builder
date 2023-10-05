# -*- coding: utf-8 -*-
from importlib.metadata import PackageNotFoundError, version

from modelica_builder.transformer import Transformer

try:
    # Change here if project is renamed and does not equal the package name
    dist_name = 'modelica-builder'
    __version__ = version(dist_name)
except PackageNotFoundError:
    __version__ = 'unknown'
finally:
    del version, PackageNotFoundError

__all__ = ['Transformer',
           'Transformation',
           'Edit',
           'Selector',
           'ModelicaProject',
           'PackageParser',
           'ModelicaMOS',]
