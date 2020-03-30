from hdlConvertor.hdlAst._expr import HdlBuiltinFn, HdlCall, HdlName
from hdlConvertor.to.hdl_ast_visitor import HdlAstVisitor


def to_property_call(o, prop_name):
    """
    :note: a * b -> a.prop_name(b)
    :type o: HdlCall
    """
    o.fn = HdlBuiltinFn.CALL
    _op0 = HdlCall()
    _op0.fn = HdlBuiltinFn.DOT
    o.ops[0] = _op0.ops.extend([o.ops[0], HdlName(prop_name)])


class BasicHdlSimModelTranslateVerilogOperands(HdlAstVisitor):
    def visit_iHdlExpr(self, o):
        """
        :type o: iHdlExpr
        """
        if isinstance(o, HdlCall):
            return self.visit_HdlCall(o)

    def visit_HdlCall(self, o):
        """
        :type o: HdlCall
        """
        op = o.fn
        if op == HdlBuiltinFn.EQ:
            # HdlBuiltinFn.EQ: '%s._eq(%s)',
            to_property_call(o, "_eq")
        elif op == HdlBuiltinFn.CONCAT:
            to_property_call(o, "_concat")
        elif op == HdlBuiltinFn.TERNARY:
            to_property_call(o, "_ternary__val")
        elif op == HdlBuiltinFn.DOWNTO:
            # HdlBuiltinFn.DOWNTO: "slice(%s, %s)",
            o.fn = HdlBuiltinFn.CALL
            o.ops = [HdlName("slice"), *o.ops]
        elif op == HdlBuiltinFn.TO:
            raise NotImplementedError(o)
        elif op == HdlBuiltinFn.CALL:
            raise NotImplementedError("inline", o)
