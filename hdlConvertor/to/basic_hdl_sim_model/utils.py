from hdlConvertor.hdlAst import HdlName, HdlBuiltinFn, HdlIntValue, HdlCall


def BitsT(width, is_signed=False):
    """
    Create an AST expression of Bits type constructor
    (reg/std_logic_vector equivalent for BasicHdlSimModel)
    """
    if isinstance(width, HdlCall):
        if width.fn == HdlBuiltinFn.DOWNTO:
            high, low = width.ops
            assert int(low) == 0
            width = int(high) + 1
        else:
            raise NotImplementedError(width)
    c = HdlCall()
    c.fn = HdlBuiltinFn.CALL
    c.ops = (
        HdlName("Bits3t"),
        HdlIntValue(width, None, None),
        HdlIntValue(int(is_signed), None, None)
    )
    return c
