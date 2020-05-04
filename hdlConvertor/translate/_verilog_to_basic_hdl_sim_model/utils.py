from hdlConvertor.hdlAst._expr import HdlOp, HdlOpType, HdlValueId


def to_property_call(o, prop_name):
    """
    :note: a * b -> a.prop_name(b)
    :type o: HdlOp
    """
    o.fn = HdlOpType.CALL
    o.ops[0] = hdl_getattr(o.ops[0], prop_name)
    return o


def hdl_name_prefix(prefix_name, o):
    """
    :type o: HdlValueId
    :type prefix_name: iHdlExpr
    :return: HdlOp
    """
    assert isinstance(o, HdlValueId), o
    return HdlOp(HdlOpType.DOT, [prefix_name, o])


def hdl_getattr(o, prop_name):
    """
    :type o: iHdlExpr
    :type prop_name: str
    :return: HdlOp
    """
    return HdlOp(HdlOpType.DOT, [o, HdlValueId(prop_name)])


def hdl_call(o, args):
    """
    :type o: iHdlExpr
    :type args: List[iHdlExpr]
    :return: HdlOp
    """
    return HdlOp(HdlOpType.CALL, [o, ] + args)


def hdl_index(o, i):
    """
    :type o: iHdlExpr
    :type args: List[iHdlExpr]
    :return: HdlOp
    """
    return HdlOp(HdlOpType.INDEX, [o, i])


def hdl_downto(msb, lsb):
    return HdlOp(HdlOpType.DOWNTO, [msb, lsb])


def hdl_map_asoc(o1, o2):
    """
    :type o1: iHdlExpr
    :type o2: iHdlExpr
    :return: HdlOp
    """
    return HdlOp(HdlOpType.MAP_ASSOCIATION, [o1, o2])
