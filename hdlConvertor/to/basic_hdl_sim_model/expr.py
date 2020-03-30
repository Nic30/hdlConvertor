from hdlConvertor.hdlAst import HdlBuiltinFn, HdlName, HdlIntValue, \
    HdlCall
from hdlConvertor.to.common import ToHdlCommon
from hdlConvertor.to.hdlUtils import is_str


class ToBasicHdlSimModelExpr(ToHdlCommon):
    OP_PRECEDENCE = {
        HdlBuiltinFn.RISING: 1,
        HdlBuiltinFn.FALLING: 1,
        HdlBuiltinFn.DOWNTO: 1,
        HdlBuiltinFn.TO: 1,

        # note that HdlExpressions in BasicHdlSimModel
        # do not use == but ._eq()
        HdlBuiltinFn.EQ: 11,
        HdlBuiltinFn.NEQ: 11,
        HdlBuiltinFn.GT: 11,
        HdlBuiltinFn.LT: 11,
        HdlBuiltinFn.GE: 11,
        HdlBuiltinFn.LE: 11,

        HdlBuiltinFn.OR: 10,
        HdlBuiltinFn.XOR: 9,
        HdlBuiltinFn.AND: 8,

        HdlBuiltinFn.ADD: 6,
        HdlBuiltinFn.SUB: 6,

        HdlBuiltinFn.DIV: 5,
        HdlBuiltinFn.MUL: 5,
        HdlBuiltinFn.MOD: 5,

        HdlBuiltinFn.NOT: 4,
        HdlBuiltinFn.NEG: 4,
        HdlBuiltinFn.POW: 3,
        HdlBuiltinFn.INDEX: 2,

        HdlBuiltinFn.CONCAT: 1,
        HdlBuiltinFn.TERNARY: 1,
        HdlBuiltinFn.CALL: 1,
    }
    _unaryEventOps = {
        HdlBuiltinFn.RISING: "._onRisingEdge()",
        HdlBuiltinFn.FALLING: "._onFallingEdge()",
    }
    _unaryOps = {
        HdlBuiltinFn.NOT: "~",
        HdlBuiltinFn.NEG: "-",
    }

    GENERIC_BIN_OPS = {
        **ToHdlCommon.GENERIC_BIN_OPS,
        HdlBuiltinFn.AND: "&",
        HdlBuiltinFn.OR: "|",
        HdlBuiltinFn.XOR: "^",

        HdlBuiltinFn.EQ: '==',
        HdlBuiltinFn.NEQ: "!=",

        HdlBuiltinFn.DIV: "//",
        HdlBuiltinFn.POW: "**",
        HdlBuiltinFn.MOD: "%",

        HdlBuiltinFn.SLL: "<<",
        HdlBuiltinFn.SRL: ">>",
    }

    def visit_HdlIntValue(self, o):
        """
        :type o: HdlIntValue
        """
        w = self.out.write
        if o.bits is None:
            w(str(o.val))
        else:
            if o.base is None:
                f = "{0}'h{1:x}"
            else:
                b = o.base
                if b == 2:
                    base_char = 'b'
                elif b == 8:
                    base_char = 'O'
                elif b == 10:
                    base_char = 'd'
                elif b == 16:
                    base_char = 'h'
                else:
                    raise NotImplementedError(b)
                f = "{0}'" + base_char + "{1}"
            w(f.format(o.bits, o.val))

    def visit_iHdlExpr(self, o):
        """
        :type o: iHdlExpr
        """
        w = self.out.write
        if isinstance(o, HdlName):
            w(o)
            return
        elif is_str(o):
            w('"%s"' % o)
            return
        elif isinstance(o, HdlIntValue):
            self.visit_HdlIntValue(o)
            return
        elif isinstance(o, HdlCall):
            self.visit_HdlCall(o)
            return
        elif o is None:
            w("None")
            return

        raise NotImplementedError(o)

    def visit_HdlCall(self, o):
        """
        :type op: HdlCall
        """
        ops = o.ops
        op = o.fn
        w = self.out.write

        op_str = self._unaryEventOps.get(op, None)
        if op_str is not None:
            op0 = ops[0]
            w(op0)
            w(op_str)
        else:
            return super(ToBasicHdlSimModelExpr, self).visit_HdlCall(o)
