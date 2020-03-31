from hdlConvertor.hdlAst._expr import HdlCall, HdlBuiltinFn, HdlName


def hdl_name_prefix(prefix_name, o):
    """
    :type o: HdlName
    :type prefix_name: iHdlExpr
    :return: HdlCall
    """
    assert isinstance(o, HdlName), o
    res = HdlCall()
    res.fn = HdlBuiltinFn.DOT
    res.ops = [prefix_name, o]
    return res


def hdl_getattr(o, prop_name):
    """
    :type o: iHdlExpr
    :type prop_name: str
    :return: HdlCall
    """
    res = HdlCall()
    res.fn = HdlBuiltinFn.DOT
    res.ops = [o, HdlName(prop_name)]
    return res
