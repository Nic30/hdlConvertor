from hdlConvertor.hdlAst._structural import HdlModuleDec, HdlModuleDef,\
    HdlComponentInst
from itertools import chain
from hdlConvertor.hdlAst._defs import HdlVariableDef
from hdlConvertor.hdlAst._statements import HdlStmAssign


def discover_declarations_HdlVariableDef(name_scope, o):
    """
    :type name_scope: NameScope
    :type o: HdlVariableDef
    """
    name_scope.register_name(o.name, o)


def discover_declarations_HdlModuleDec(name_scope, o):
    """
    :type name_scope: NameScope
    :type o: HdlModuleDec
    """
    name_scope.register_name(o.name, o)
    _name_scope = name_scope.level_push(o.name)
    for p in chain(o.params, o.ports):
        discover_declarations_HdlVariableDef(_name_scope, p)

    for o2 in o.objs:
        raise NotImplementedError(o2)
    if o.body is not None:
        discover_declarations_HdlModuleDef(name_scope, o.body)


def discover_declarations_HdlModuleDef(name_scope, o):
    """
    :type name_scope: NameScope
    :type o: HdlModuleDef
    """
    name_scope = name_scope.get_child(o.module_name)
    discover_declarations(name_scope, o.objs)


def discover_declarations_HdlComponentInst(name_scope, o):
    """
    :type name_scope: NameScope
    :type o: HdlComponentInst
    """
    if o.name is not None:
        name_scope.register_name(o.name, o)
    # name_scope = name_scope.get_object_by_name(o.module_name)


def _discover_declarations(name_scope, o):
    if isinstance(o, HdlVariableDef):
        discover_declarations_HdlVariableDef(name_scope, o)
    elif isinstance(o, HdlModuleDec):
        discover_declarations_HdlModuleDec(name_scope, o)
    elif isinstance(o, HdlModuleDef):
        discover_declarations_HdlModuleDef(name_scope, o)
    elif isinstance(o, HdlStmAssign):
        pass
    elif isinstance(o, HdlComponentInst):
        discover_declarations_HdlComponentInst(name_scope, o)
    else:
        raise NotImplementedError(o)


def discover_declarations(name_scope, objs):
    for o in objs:
        _discover_declarations(name_scope, o)
