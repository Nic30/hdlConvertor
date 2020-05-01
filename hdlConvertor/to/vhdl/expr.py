from hdlConvertor.hdlAst._expr import HdlBuiltinFn, HdlName, HdlIntValue,\
    HdlAll, HdlCall, HdlOthers
from hdlConvertor.py_ver_compatibility import is_str
from hdlConvertor.to.common import ToHdlCommon, ASSOCIATIVITY
from hdlConvertor.to.hdlUtils import iter_with_last, Indent


L = ASSOCIATIVITY.L_TO_R
R = ASSOCIATIVITY.R_TO_L


# https://www.csee.umbc.edu/portal/help/VHDL/operator.html
class ToVhdl2008Expr(ToHdlCommon):
    GENERIC_UNARY_OPS = ToHdlCommon.GENERIC_UNARY_OPS
    GENERIC_UNARY_OPS.update({HdlBuiltinFn.NEG: "NOT ",
                              HdlBuiltinFn.NEG_LOG: "NOT "})
    BITWISE_BIN_OPS = {HdlBuiltinFn.AND, HdlBuiltinFn.AND_LOG,
                       HdlBuiltinFn.OR, HdlBuiltinFn.OR_LOG,
                       HdlBuiltinFn.XOR, HdlBuiltinFn.NAND,
                       HdlBuiltinFn.NOR, HdlBuiltinFn.XNOR}
    GENERIC_BIN_OPS = {
        HdlBuiltinFn.AND: " AND ",
        HdlBuiltinFn.AND_LOG: " AND ",
        HdlBuiltinFn.OR: " OR ",
        HdlBuiltinFn.OR_LOG: " OR ",
        HdlBuiltinFn.DIV: " / ",
        HdlBuiltinFn.MOD: " MOD ",
        HdlBuiltinFn.REM: " REM ",
        HdlBuiltinFn.POW: " ** ",
        HdlBuiltinFn.NAND: " NAND ",
        HdlBuiltinFn.NOR: " NOR ",
        HdlBuiltinFn.XOR: " XOR ",
        HdlBuiltinFn.XNOR: " XNOR ",
        HdlBuiltinFn.EQ: ' = ',
        HdlBuiltinFn.NEQ: " /= ",
        HdlBuiltinFn.TO: " TO ",
        HdlBuiltinFn.DOWNTO: " DOWNTO ",
        HdlBuiltinFn.ARROW: " => ",
        HdlBuiltinFn.MAP_ASSOCIATION: " => ",
        HdlBuiltinFn.RANGE: " RANGE ",
        HdlBuiltinFn.CONCAT: " & ",
        HdlBuiltinFn.ROL: " ROL ",
        HdlBuiltinFn.ROR: " ROR ",
        HdlBuiltinFn.SLA: " SLA ",
        HdlBuiltinFn.SRA: " SRA ",
        HdlBuiltinFn.SLL: " SLL ",
        HdlBuiltinFn.SRL: " SRL ",
    }
    GENERIC_BIN_OPS.update(ToHdlCommon.GENERIC_BIN_OPS)
    NUM_BASES = {
        2: "",
        8: "O",
        16: "X",
        256: "",  # 'X' literals
    }
    OP_PRECEDENCE = {
        HdlBuiltinFn.DOT: (1, L),
        HdlBuiltinFn.CALL: (1, L),
        HdlBuiltinFn.INDEX: (1, L),
        HdlBuiltinFn.RISING: (1, L),
        HdlBuiltinFn.FALLING: (1, L),
        HdlBuiltinFn.APOSTROPHE: (1, L),

        HdlBuiltinFn.POW: (2, R),
        HdlBuiltinFn.ABS: (2, L),
        HdlBuiltinFn.NEG: (2, L),

        HdlBuiltinFn.MUL: (3, L),
        HdlBuiltinFn.DIV: (3, L),
        HdlBuiltinFn.MOD: (3, L),
        HdlBuiltinFn.REM: (3, L),

        HdlBuiltinFn.PLUS_UNARY: (4, R),
        HdlBuiltinFn.MINUS_UNARY: (4, R),

        HdlBuiltinFn.CONCAT: (5, L),
        HdlBuiltinFn.ADD: (5, L),
        HdlBuiltinFn.SUB: (5, L),

        HdlBuiltinFn.SLL: (6, L),
        HdlBuiltinFn.SRL: (6, L),
        HdlBuiltinFn.SLA: (6, L),
        HdlBuiltinFn.SRA: (6, L),
        HdlBuiltinFn.ROL: (6, L),
        HdlBuiltinFn.ROR: (6, L),

        HdlBuiltinFn.EQ:  (7, L),
        HdlBuiltinFn.NEQ: (7, L),
        HdlBuiltinFn.GT:  (7, L),
        HdlBuiltinFn.LT:  (7, L),
        HdlBuiltinFn.GE:  (7, L),
        HdlBuiltinFn.LE:  (7, L),

        HdlBuiltinFn.AND:  (8, L),
        HdlBuiltinFn.OR:   (8, L),
        HdlBuiltinFn.NAND: (8, ASSOCIATIVITY.NONE),
        HdlBuiltinFn.NOR:  (8, ASSOCIATIVITY.NONE),
        HdlBuiltinFn.XOR:  (8, L),
        HdlBuiltinFn.XNOR: (8, ASSOCIATIVITY.NONE),

        HdlBuiltinFn.DOWNTO: (9, L),
        HdlBuiltinFn.TO: (9, L),
        HdlBuiltinFn.TERNARY: (9, R),

        HdlBuiltinFn.RANGE: (10, L),
        HdlBuiltinFn.ARROW: (11, L),
    }

    def visit_HdlIntValue(self, o):
        w = self.out.write
        v = o.val
        bits = o.bits
        if is_str(v):
            v = v.upper()
            if o.base == 256:
                w("'%s'" % v)
            else:
                w('%s"%s"' % (self.NUM_BASES[o.base], v))
            return

        if bits is None:
            if o.base is not None:
                b = self.NUM_BASES[o.base]
                if o.base == 256:
                    w("'%d'" % v)
                elif o.base == 16:
                    w('%s"%X"' % (b, v))
                elif o.base == 8:
                    w('%s"%o"' % (b, v))
                elif o.base == 2:
                    w('{0}"{1:b}"'.format(b, v))
                else:
                    raise NotImplementedError(o.base)
            else:
                w(str(v))
            return
        elif bits % 8 == 0:
            f = 'X"{0:0%dx}"' % (bits / 8)
        else:
            f = '"{0:0%db}"' % (bits)
        w(f.format(v))

    def _visit_operand_parentheses_extra_check(self, op_my, precedence_my, asoc_my,
                                               op_parent, precedence_parent, asoc_parent,
                                               left, right):
        if super(ToVhdl2008Expr, self)._visit_operand_parentheses_extra_check(
                op_my, precedence_my, asoc_my,
                op_parent, precedence_parent, asoc_parent, left, right):
            return True
        elif op_my in self.BITWISE_BIN_OPS and\
                op_parent in self.BITWISE_BIN_OPS and\
                op_my != op_parent:
            return True
        else:
            return False

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
        if op == HdlBuiltinFn.RISING:
            w("RISING_EDGE(")
            self.visit_iHdlExpr(o.ops[0])
            w(")")
        elif op == HdlBuiltinFn.FALLING:
            w("FALLING_EDGE(")
            self.visit_iHdlExpr(o.ops[0])
            w(")")
        elif op == HdlBuiltinFn.INDEX or op == HdlBuiltinFn.CALL:
            self._visit_operand(o.ops[0], 0, o, False, False)
            w("(")
            for isLast, (o_i, _o) in iter_with_last(enumerate(o.ops[1:])):
                self._visit_operand(_o, o_i + 1, o, False, True)
                if not isLast:
                    w(", ")
            w(")")
        elif op == HdlBuiltinFn.TERNARY:
            has_3_ops = len(o.ops) == 3
            if has_3_ops:
                cond, o0, o1 = o.ops
            else:
                cond, o0 = o.ops

            self._visit_operand(o0, 1, o, True, False)
            w(" WHEN ")
            self._visit_operand(cond, 0, o, True, False)
            if has_3_ops:
                if isinstance(o1, HdlCall) and o1.fn == HdlBuiltinFn.TERNARY:
                    w(" ELSE\n")
                    self.visit_iHdlExpr(o1)  # must not have parenthesis
                else:
                    w(" ELSE ")
                    self._visit_operand(o1, 2, o, False, False)
        elif op == HdlBuiltinFn.APOSTROPHE:
            self._visit_operand(o.ops[0], 0, o, True, False)
            w("'")
            args = o.ops[1]
            if isinstance(args, list):
                self.visit_iHdlExpr(args)
            elif isinstance(args, HdlName):
                # normal attribute
                self.visit_iHdlExpr(args)
            else:
                w("(")
                self._visit_operand(args, 0, o, False, True)
                w(")")
        elif op == HdlBuiltinFn.ABS:
            w("ABS(")
            self.visit_iHdlExpr(o.ops[0])
            w(")")
        else:
            return ToHdlCommon.visit_HdlCall(self, o)

    def visit_str(self, o):
        """
        :type o: str
        """
        w = self.out.write
        if o == "":
            w('""')
        else:
            ESCAPES = {
                '\n': 'LF\n',
                '\c': 'CR'
            }
            CONC = self.GENERIC_BIN_OPS[HdlBuiltinFn.CONCAT]
            first = True
            string_begin = True
            for c in o:
                esc = ESCAPES.get(c, None)
                if esc is not None:
                    if not string_begin:
                        w('"')  # string end "
                        string_begin = True
                    if not first:
                        w(CONC)
                    w(esc)
                else:
                    if string_begin:
                        string_begin = False
                        w('"')  # string start "
                    w(c)
                first = False

            if not string_begin:
                w('"')  # string end "

    def visit_iHdlExpr(self, expr):
        w = self.out.write
        if expr is HdlAll:
            w("ALL")
        elif expr is HdlOthers:
            w("OTHERS")
        elif self.in_typedef and expr is None:
            w("<>")
        elif is_str(expr):
            self.visit_str(expr)
        elif isinstance(expr, list):
            with_nl = len(expr) > 3
            if with_nl:
                w("(\n")
            else:
                w("(")
            with Indent(self.out):
                for is_last, elem in iter_with_last(expr):
                    self.visit_iHdlExpr(elem)
                    if not is_last:
                        if with_nl:
                            w(",\n")
                        else:
                            w(", ")
            w(")")
        else:
            ToHdlCommon.visit_iHdlExpr(self, expr)
