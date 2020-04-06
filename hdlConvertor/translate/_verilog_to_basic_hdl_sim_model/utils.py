from hdlConvertor.hdlAst._expr import HdlCall, HdlBuiltinFn, HdlName


def to_property_call(o, prop_name):
    """
    :note: a * b -> a.prop_name(b)
    :type o: HdlCall
    """
    o.fn = HdlBuiltinFn.CALL
    o.ops[0] = hdl_getattr(o.ops[0], prop_name)
    return o


def hdl_name_prefix(prefix_name, o):
    """
    :type o: HdlName
    :type prefix_name: iHdlExpr
    :return: HdlCall
    """
    assert isinstance(o, HdlName), o
    res = HdlCall(HdlBuiltinFn.DOT, [prefix_name, o])
    return res


def hdl_getattr(o, prop_name):
    """
    :type o: iHdlExpr
    :type prop_name: str
    :return: HdlCall
    """
    res = HdlCall(HdlBuiltinFn.DOT, [o, HdlName(prop_name)])
    return res
