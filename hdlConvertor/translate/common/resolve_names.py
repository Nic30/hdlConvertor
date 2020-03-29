"""
Use declarations collected from resolve_names
and use them to associate HdlNames to a HdlObjects.
"""
from hdlConvertor.hdlAst._structural import HdlModuleDec, HdlModuleDef,\
    HdlComponentInst
from itertools import chain
from hdlConvertor.hdlAst._defs import HdlVariableDef
from hdlConvertor.hdlAst._statements import HdlStmAssign
from hdlConvertor.hdlAst._expr import HdlCall, HdlBuiltinFn, HdlName, HdlAll,\
    HdlIntValue


def resolve_names_HdlVariableDef(name_scope, o):
    """
    :type name_scope: NameScope
    :type o: HdlVariableDef
    """
    name_scope.register_name(o.name, o)


def resolve_names_HdlModuleDec(name_scope, o):
    """
    :type name_scope: NameScope
    :type o: HdlModuleDec
    """
    name_scope.register_name(o.name, o)
    _name_scope = name_scope.level_push(o.name)
    for p in chain(o.params, o.ports):
        resolve_names_HdlVariableDef(_name_scope, p)

    for o2 in o.objs:
        raise NotImplementedError(o2)
    if o.body is not None:
        resolve_names_HdlModuleDef(name_scope, o.body)


def resolve_names_HdlModuleDef(name_scope, o):
    """
    :type name_scope: NameScope
    :type o: HdlModuleDef
    """
    name_scope = name_scope.get_child(o.module_name)
    resolve_names(name_scope, o.objs)


def resolve_names_port_param_map(name_scope, mod_name_scope, pmap):
    for pm in pmap:
        assert isinstance(pm, HdlCall) and\
            pm.fn == HdlBuiltinFn.MAP_ASSOCIATION, pm
        mod_port, connected_sig = pm.ops
        assert isinstance(mod_port, HdlName), mod_port
        _, mod_port.obj = mod_name_scope.get_object_and_scope_by_name(mod_port)
        assert isinstance(connected_sig, HdlName), connected_sig
        _, connected_sig.obj = name_scope.get_object_and_scope_by_name(mod_port)


def resolve_names_HdlComponentInst(name_scope, o):
    """
    :type name_scope: NameScope
    :type o: HdlComponentInst
    """
    if o.name is not None:
        o.name.obj = o

    mod_name_scope, mod_def = name_scope.get_object_and_scope_by_name(o.module_name)
    mod_name_scope = mod_name_scope.get_child(o.module_name)
    o.module_name.obj = mod_def
    resolve_names_port_param_map(name_scope, mod_name_scope, o.param_map)
    resolve_names_port_param_map(name_scope, mod_name_scope, o.port_map)


def resolve_names_iHdlExpr(name_scope, o):
    """
    :type name_scope: NameScope
    :type o: iHdlExpr
    """
    if isinstance(o, HdlCall):
        for o2 in o.ops:
            resolve_names_iHdlExpr(o2)
    elif isinstance(o, HdlName):
        _, o.obj = name_scope.get_object_and_scope_by_name(o)
    elif o is None or o is HdlAll or isinstance(o,  (HdlIntValue, float, str)):
        pass
    else:
        assert isinstance(o, list), o
        for o2 in o:
            resolve_names_iHdlExpr(name_scope, o2)


def resolve_names_HdlStmAssign(name_scope, o):
    """
    :type name_scope: NameScope
    :type o: HdlStmAssign
    """
    resolve_names_iHdlExpr(name_scope, o.src)
    resolve_names_iHdlExpr(name_scope, o.dst)
    if o.event_delay is not None:
        for e in o.event_delay:
            resolve_names_iHdlExpr(name_scope, e)
    if o.time_delay is not None:
        resolve_names_iHdlExpr(name_scope, o.time_delay)


def _resolve_names(name_scope, o):
    if isinstance(o, HdlVariableDef):
        resolve_names_HdlVariableDef(name_scope, o)
    elif isinstance(o, HdlModuleDec):
        resolve_names_HdlModuleDec(name_scope, o)
    elif isinstance(o, HdlModuleDef):
        resolve_names_HdlModuleDef(name_scope, o)
    elif isinstance(o, HdlStmAssign):
        resolve_names_HdlStmAssign(name_scope, o)
    elif isinstance(o, HdlComponentInst):
        resolve_names_HdlComponentInst(name_scope, o)
    else:
        raise NotImplementedError(o)


def resolve_names(name_scope, objs):
    for o in objs:
        _resolve_names(name_scope, o)
