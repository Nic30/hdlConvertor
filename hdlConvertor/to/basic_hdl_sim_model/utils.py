from hdlConvertor.hdlAst import HdlName, HdlBuiltinFn, HdlIntValue, HdlCall, iHdlExpr
from hdlConvertor.translate.common.name_scope import LanguageKeyword


def BitsT(width, is_signed=False, bits_cls_name="Bits3t"):
    """
    Create an AST expression of Bits type constructor
    (reg/std_logic_vector equivalent for BasicHdlSimModel)

    :type width: iHdlExpr
    """
    if isinstance(width, HdlCall):
        if width.fn == HdlBuiltinFn.DOWNTO:
            high, low = width.ops
            assert int(low) == 0
            width = int(high) + 1
        else:
            raise NotImplementedError(width)
    c = HdlCall(HdlBuiltinFn.CALL, [
        HdlName(bits_cls_name, obj=LanguageKeyword()),
        HdlIntValue(width, None, None),
        HdlIntValue(int(is_signed), None, None)
    ])
    return c


def sensitivityByOp(op):
    """
    Get sensitivity type for operator.

    :type op: HdlBuiltinFn
    :return: Tuple[sensitive on rising edge, sensitive to falling edge]
    """

    if op == HdlBuiltinFn.RISING:
        return (True, False)
    elif op == HdlBuiltinFn.FALLING:
        return (False, True)
    else:
        raise TypeError(op)
