from hdlConvertor.hdlAst._expr import HdlOpType, HdlValueId, HdlValueInt,\
    HdlAll, HdlOp, HdlOthers
from hdlConvertor.py_ver_compatibility import is_str
from hdlConvertor.to.common import ToHdlCommon, ASSOCIATIVITY
from hdlConvertor.to.hdlUtils import iter_with_last, Indent


L = ASSOCIATIVITY.L_TO_R
R = ASSOCIATIVITY.R_TO_L


# https://www.csee.umbc.edu/portal/help/VHDL/operator.html
class ToVhdl2008Expr(ToHdlCommon):
    GENERIC_UNARY_OPS = ToHdlCommon.GENERIC_UNARY_OPS
    GENERIC_UNARY_OPS.update({HdlOpType.NEG: "NOT ",
                              HdlOpType.NEG_LOG: "NOT "})
    BITWISE_BIN_OPS = {HdlOpType.AND, HdlOpType.AND_LOG,
                       HdlOpType.OR, HdlOpType.OR_LOG,
                       HdlOpType.XOR, HdlOpType.NAND,
                       HdlOpType.NOR, HdlOpType.XNOR}
    GENERIC_BIN_OPS = {
        HdlOpType.AND: " AND ",
        HdlOpType.AND_LOG: " AND ",
        HdlOpType.OR: " OR ",
        HdlOpType.OR_LOG: " OR ",
        HdlOpType.DIV: " / ",
        HdlOpType.MOD: " MOD ",
        HdlOpType.REM: " REM ",
        HdlOpType.POW: " ** ",
        HdlOpType.NAND: " NAND ",
        HdlOpType.NOR: " NOR ",
        HdlOpType.XOR: " XOR ",
        HdlOpType.XNOR: " XNOR ",
        HdlOpType.EQ: ' = ',
        HdlOpType.NEQ: " /= ",
        HdlOpType.TO: " TO ",
        HdlOpType.DOWNTO: " DOWNTO ",
        HdlOpType.ARROW: " => ",
        HdlOpType.MAP_ASSOCIATION: " => ",
        HdlOpType.RANGE: " RANGE ",
        HdlOpType.CONCAT: " & ",
        HdlOpType.ROL: " ROL ",
        HdlOpType.ROR: " ROR ",
        HdlOpType.SLA: " SLA ",
        HdlOpType.SRA: " SRA ",
        HdlOpType.SLL: " SLL ",
        HdlOpType.SRL: " SRL ",
    }
    GENERIC_BIN_OPS.update(ToHdlCommon.GENERIC_BIN_OPS)
    NUM_BASES = {
        2: "",
        8: "O",
        16: "X",
        256: "",  # 'X' literals
    }
    OP_PRECEDENCE = {
        HdlOpType.DOT: (1, L),
        HdlOpType.CALL: (1, L),
        HdlOpType.INDEX: (1, L),
        HdlOpType.RISING: (1, L),
        HdlOpType.FALLING: (1, L),
        HdlOpType.APOSTROPHE: (1, L),

        HdlOpType.POW: (2, R),
        HdlOpType.ABS: (2, L),
        HdlOpType.NEG: (2, L),

        HdlOpType.MUL: (3, L),
        HdlOpType.DIV: (3, L),
        HdlOpType.MOD: (3, L),
        HdlOpType.REM: (3, L),

        HdlOpType.PLUS_UNARY: (4, R),
        HdlOpType.MINUS_UNARY: (4, R),

        HdlOpType.CONCAT: (5, L),
        HdlOpType.ADD: (5, L),
        HdlOpType.SUB: (5, L),

        HdlOpType.SLL: (6, L),
        HdlOpType.SRL: (6, L),
        HdlOpType.SLA: (6, L),
        HdlOpType.SRA: (6, L),
        HdlOpType.ROL: (6, L),
        HdlOpType.ROR: (6, L),

        HdlOpType.EQ:  (7, L),
        HdlOpType.NEQ: (7, L),
        HdlOpType.GT:  (7, L),
        HdlOpType.LT:  (7, L),
        HdlOpType.GE:  (7, L),
        HdlOpType.LE:  (7, L),

        HdlOpType.AND:  (8, L),
        HdlOpType.OR:   (8, L),
        HdlOpType.NAND: (8, ASSOCIATIVITY.NONE),
        HdlOpType.NOR:  (8, ASSOCIATIVITY.NONE),
        HdlOpType.XOR:  (8, L),
        HdlOpType.XNOR: (8, ASSOCIATIVITY.NONE),

        HdlOpType.DOWNTO: (9, L),
        HdlOpType.TO: (9, L),
        HdlOpType.TERNARY: (9, R),

        HdlOpType.RANGE: (10, L),
        HdlOpType.ARROW: (11, L),
    }

    def visit_HdlValueInt(self, o):
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

    def visit_HdlOp(self, o):
        """
        :type o: HdlOp
        """
        fn = o.ops[0]
        if fn == HdlValueId("assert"):
            self.visit_assert(o.ops[1:])
            return
        elif fn == HdlValueId("report"):
            self.visit_report(o.ops[1:])
            return

        w = self.out.write
        op = o.fn
        if op == HdlOpType.RISING:
            w("RISING_EDGE(")
            self.visit_iHdlExpr(o.ops[0])
            w(")")
        elif op == HdlOpType.FALLING:
            w("FALLING_EDGE(")
            self.visit_iHdlExpr(o.ops[0])
            w(")")
        elif op == HdlOpType.INDEX or op == HdlOpType.CALL:
            self._visit_operand(o.ops[0], 0, o, False, False)
            w("(")
            for isLast, (o_i, _o) in iter_with_last(enumerate(o.ops[1:])):
                self._visit_operand(_o, o_i + 1, o, False, True)
                if not isLast:
                    w(", ")
            w(")")
        elif op == HdlOpType.TERNARY:
            has_3_ops = len(o.ops) == 3
            if has_3_ops:
                cond, o0, o1 = o.ops
            else:
                cond, o0 = o.ops

            self._visit_operand(o0, 1, o, True, False)
            w(" WHEN ")
            self._visit_operand(cond, 0, o, True, False)
            if has_3_ops:
                if isinstance(o1, HdlOp) and o1.fn == HdlOpType.TERNARY:
                    w(" ELSE\n")
                    self.visit_iHdlExpr(o1)  # must not have parenthesis
                else:
                    w(" ELSE ")
                    self._visit_operand(o1, 2, o, False, False)
        elif op == HdlOpType.APOSTROPHE:
            self._visit_operand(o.ops[0], 0, o, True, False)
            w("'")
            args = o.ops[1]
            if isinstance(args, list):
                self.visit_iHdlExpr(args)
            elif isinstance(args, HdlValueId):
                # normal attribute
                self.visit_iHdlExpr(args)
            else:
                w("(")
                self._visit_operand(args, 0, o, False, True)
                w(")")
        elif op == HdlOpType.ABS:
            w("ABS(")
            self.visit_iHdlExpr(o.ops[0])
            w(")")
        elif op == HdlOpType.DEFINE_RESOLVER:
            assert self.in_typedef
            self.visit_iHdlExpr(o.ops[0])
            w(" ")
            self.visit_iHdlExpr(o.ops[1])
        else:
            return ToHdlCommon.visit_HdlOp(self, o)

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
            CONC = self.GENERIC_BIN_OPS[HdlOpType.CONCAT]
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
