from hdlConvertor.hdlAst._expr import HdlBuiltinFn, HdlName, HdlIntValue,\
    HdlAll, HdlCall, HdlOthers
from hdlConvertor.to.common import ToHdlCommon
from hdlConvertor.to.hdlUtils import is_str, iter_with_last, Indent


class ToVhdl2008Expr(ToHdlCommon):
    GENERIC_BIN_OPS = {
        **ToHdlCommon.GENERIC_BIN_OPS,
        HdlBuiltinFn.AND: " AND ",
        HdlBuiltinFn.LOG_AND: " AND ",
        HdlBuiltinFn.OR: " OR ",
        HdlBuiltinFn.LOG_OR: " OR ",
        HdlBuiltinFn.DIV: " / ",
        HdlBuiltinFn.MOD: " MOD ",
        HdlBuiltinFn.NAND: " NAND ",
        HdlBuiltinFn.NOR: " NOR ",
        HdlBuiltinFn.XOR: " XOR ",
        HdlBuiltinFn.XNOR: " XNOR ",
        HdlBuiltinFn.EQ: ' = ',
        HdlBuiltinFn.NEQ: " /= ",
        HdlBuiltinFn.SLL: " SLL ",
        HdlBuiltinFn.SRL: " SRL ",
        HdlBuiltinFn.TO: " TO ",
        HdlBuiltinFn.DOWNTO: " DOWNTO ",
        HdlBuiltinFn.ARROW: " => ",
        HdlBuiltinFn.MAP_ASSOCIATION: " => ",
        HdlBuiltinFn.RANGE: " RANGE ",
    }
    NUM_BASES = {
        2: "B",
        8: "O",
        16: "X",
        256: "",
    }
    OP_PRECEDENCE = {
        HdlBuiltinFn.RANGE: 9,

        HdlBuiltinFn.DOWNTO: 8,
        HdlBuiltinFn.TO: 8,
        HdlBuiltinFn.TERNARY: 8,

        HdlBuiltinFn.XOR: 7,
        HdlBuiltinFn.AND: 7,
        HdlBuiltinFn.OR: 7,

        HdlBuiltinFn.EQ: 6,
        HdlBuiltinFn.NEQ: 6,
        HdlBuiltinFn.GT: 6,
        HdlBuiltinFn.LT: 6,
        HdlBuiltinFn.GE: 6,
        HdlBuiltinFn.LE: 6,


        HdlBuiltinFn.CONCAT: 5,
        HdlBuiltinFn.ADD: 5,
        HdlBuiltinFn.SUB: 5,

        HdlBuiltinFn.NEG: 4,

        HdlBuiltinFn.DIV: 3,
        HdlBuiltinFn.MUL: 3,
        HdlBuiltinFn.MOD: 3,

        HdlBuiltinFn.NOT: 2,
        HdlBuiltinFn.POW: 2,

        HdlBuiltinFn.RISING: 1,
        HdlBuiltinFn.FALLING: 1,
        HdlBuiltinFn.INDEX: 1,
        HdlBuiltinFn.CALL: 1,
    }

    def visit_HdlIntValue(self, o):
        w = self.out.write
        v = o.val
        bits = o.bits
        if is_str(v):
            w('%s"%s"' % (self.NUM_BASES[o.base], v))
            return

        if bits is None:
            if o.base is not None:
                if o.base == 256:
                    w("'%s'" % str(v))
                    return
                b = self.bases[o.base]
                w('%s"%"' % (b, v))
            w(str(v))
            return
        elif bits % 8 == 0:
            f = 'X"{0:0%dx}"' % (bits / 8)
        else:
            f = '"{0:0%db}"' % (bits)
        w(f.format(v))

    def visit_HdlCall(self, o):
        """
        :type o: HdlCall
        """
        fn = o.ops[0]
        if fn == HdlName("assert"):
            self.visit_assert(o.ops[1:])
            return
        elif fn == HdlName("report"):
            self.visit_report(o.ops[1:])
            return

        w = self.out.write
        op = o.fn
        if op == HdlBuiltinFn.NOT or op == HdlBuiltinFn.NEG:
            w("NOT ")
            self._visit_operand(o.ops[0], 0, o, False, False)
            return
        elif op == HdlBuiltinFn.RISING:
            w("RISIG_EDGE(")
            self._visit_operand(o.ops[0], 0, o, False, True)
            w(")")
            return
        elif op == HdlBuiltinFn.FALLING:
            w("FALLING_EDGE(")
            self._visit_operand(o.ops[0], 0, o, False, True)
            w(")")
            return
        elif op == HdlBuiltinFn.INDEX or op == HdlBuiltinFn.CALL:
            self._visit_operand(o.ops[0], 0, o, True, False)
            w("(")
            for isLast, (o_i, _o) in iter_with_last(enumerate(o.ops[1:])):
                self._visit_operand(_o, o_i + 1, o, False, True)
                if not isLast:
                    w(", ")
            w(")")
            return
        elif op == HdlBuiltinFn.TERNARY:
            cond, o0, o1 = o.ops
            self._visit_operand(cond, 0, o, True, False)
            w(" WHEN ")
            self._visit_operand(o0, 1, o, True, False)
            w(" ELSE ")
            self._visit_operand(o1, 2, o, True, False)
            return
        elif op == HdlBuiltinFn.APOSTROPHE:
            self._visit_operand(o.ops[0], 0, o, True, False)
            w("'")
            args = o.ops[1]
            if isinstance(args, list):
                self.visit_iHdlExpr(args)
            else:
                # normal attribute
                self._visit_operand(args, 0, o, True, False)
            return
        else:
            return ToHdlCommon.visit_HdlCall(self, o)

    def visit_iHdlExpr(self, expr):
        w = self.out.write
        if expr is HdlAll:
            w("ALL")
            return
        elif expr is HdlOthers:
            w("OTHERS")
            return
        elif isinstance(expr, list):
            w("(\n")
            with Indent(self.out):
                for is_last, elem in iter_with_last(expr):
                    self.visit_iHdlExpr(elem)
                    if not is_last:
                        w(",\n")
            w(")")
            return
        ToHdlCommon.visit_iHdlExpr(self, expr)
