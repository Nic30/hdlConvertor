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
    return HdlCall(HdlBuiltinFn.DOT, [prefix_name, o])


def hdl_getattr(o, prop_name):
    """
    :type o: iHdlExpr
    :type prop_name: str
    :return: HdlCall
    """
    return HdlCall(HdlBuiltinFn.DOT, [o, HdlName(prop_name)])


def hdl_call(o, args):
    """
    :type o: iHdlExpr
    :type args: List[iHdlExpr]
    :return: HdlCall
    """
    return HdlCall(HdlBuiltinFn.CALL, [o, *args])


def hdl_map_asoc(o1, o2):
    """
    :type o1: iHdlExpr
    :type o2: iHdlExpr
    :return: HdlCall
    """
    return HdlCall(HdlBuiltinFn.MAP_ASSOCIATION, [o1, o2])
