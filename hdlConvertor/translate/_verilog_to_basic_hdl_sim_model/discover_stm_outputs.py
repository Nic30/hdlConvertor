from typing import Set, List, Dict

from hdlConvertor.hdlAst import iHdlExpr, HdlName, \
    HdlContext, HdlModuleDec, HdlStmAssign, HdlStmProcess, \
    HdlStmIf, HdlStmBlock
from hdlConvertor.hdlAst._structural import HdlModuleDef


def get_output_ids(e, outputs):
    """
    :type e: iHdlExpr
    :type outputs: Set[HdlName]
    """
    if isinstance(e, HdlName):
        outputs.add(e)
    else:
        raise NotImplementedError(e)


def discover_outputs(stm, outputs):
    """
    :type stm: iHdlStm
    :type outputs: Dict["HdlStm", Set[HdlName]]
    """
    _outputs = None
    if isinstance(stm, HdlStmAssign):
        o = set()
        get_output_ids(stm.dst, o)
    elif isinstance(stm, HdlStmBlock):
        _outputs = {}
        for obj in stm.body:
            discover_outputs(obj, _outputs)
    elif isinstance(stm, HdlStmIf):
        _outputs = {}
        if stm.if_true:
            discover_outputs(stm.if_true, _outputs)
        for (_, elif_case) in stm.elifs:
            if elif_case:
                discover_outputs(elif_case, _outputs)
        if stm.if_false:
            discover_outputs(stm.if_false, _outputs)
    elif isinstance(stm, HdlStmProcess):
        o = discover_outputs(stm.body, outputs)
    else:
        raise NotImplementedError(stm)

    if _outputs is not None:
        # collect outputs from substatements and update main outputs
        o = set()
        for os in _outputs.values():
            for _o in os:
                assert isinstance(_o, HdlName), _o
                o.add(_o)
        outputs.update(_outputs)

    outputs[stm] = o
    return o


def discover_stm_outputs(stm):
    """
    :type stm: iHdlStm
    :return: Dict["HdlStm", List[HdlName]]
    """
    _outputs = {}
    # :type _outputs: Dict[HdlStm, Set[HdlName]]
    discover_outputs(stm, _outputs)
    _outputs = {
        k: list(sorted(outputs))
        for k, outputs in _outputs.items()
    }
    return _outputs


def discover_stm_outputs_context(c):
    """
    :type c: HdlContext
    """
    outputs = {}
    # :type _outputs: Dict[HdlStm, Set[HdlName]]
    for o0 in c.objs:
        if isinstance(o0, HdlModuleDef):
            for o1 in o0.objs:
                if isinstance(o1, HdlStmProcess):
                    _outputs = discover_stm_outputs(o1)
                    outputs.update(_outputs)
    return outputs
