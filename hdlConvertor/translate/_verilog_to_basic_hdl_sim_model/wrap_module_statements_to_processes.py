from hdlConvertor.hdlAst._expr import HdlCall, HdlName, HdlBuiltinFn
from hdlConvertor.hdlAst._statements import HdlStmAssign, HdlStmProcess
from hdlConvertor.hdlAst._structural import HdlModuleDec, HdlModuleDef


def collect_hdl_ids(expr, res):
    """
    :type expr: iHdlExpr
    :type res: Set[HdlName]
    """
    if isinstance(expr, HdlCall):
        for o in expr.ops:
            collect_hdl_ids(o, res)
    elif isinstance(expr, HdlName):
        res.add(expr)
    else:
        raise NotImplementedError(expr)


def collect_indexes(expr):
    """
    Collect indexes from expression with optional index operator

    :type expr: iHdlExpr
    """
    if isinstance(expr, HdlCall) and expr.fn == HdlBuiltinFn.INDEX:
        assert len(expr.ops) == 2, expr.ops
        for i in collect_indexes(expr.ops[0]):
            yield i
        yield expr.ops[1]


def wrap_module_statements_to_processes(context):
    """
    Wrap statements which are not in any process instance in HdlStmProcess instance

    :type context: HdlContext
    """
    for o in context.objs:
        if isinstance(o, HdlModuleDef):
            objs = o.objs
            for i, obj in enumerate(objs):
                if isinstance(obj, HdlStmAssign):
                    p = HdlStmProcess()
                    p.body = obj
                    p.sensitivity = set()
                    for i in collect_indexes(obj.dst):
                        collect_hdl_ids(i, p.sensitivity)
                    collect_hdl_ids(obj.src, p.sensitivity)
                    objs[i] = p
