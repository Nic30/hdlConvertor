from hdlConvertor.hdlAst import HdlOpType, HdlValueId, HdlValueInt, HdlAll,\
    HdlOp, HdlTypeAuto
from hdlConvertor.py_ver_compatibility import is_str
from hdlConvertor.to.common import ToHdlCommon, ASSOCIATIVITY,\
    ASSIGN_OPERATORS_SYMBOLS_C
from hdlConvertor.to.hdlUtils import iter_with_last
from hdlConvertor.to.verilog.utils import collect_array_dims, get_wire_t_params


L = ASSOCIATIVITY.L_TO_R
R = ASSOCIATIVITY.R_TO_L

ASSIGN_OPERATORS = [
    HdlOpType.ASSIGN,
    HdlOpType.PLUS_ASSIGN,
    HdlOpType.MINUS_ASSIGN,
    HdlOpType.MUL_ASSIGN,
    HdlOpType.DIV_ASSIGN,
    HdlOpType.MOD_ASSIGN,
    HdlOpType.AND_ASSIGN,
    HdlOpType.OR_ASSIGN,
    HdlOpType.XOR_ASSIGN,
    HdlOpType.SHIFT_LEFT_ASSIGN,
    HdlOpType.SHIFT_RIGHT_ASSIGN,
    HdlOpType.ARITH_SHIFT_LEFT_ASSIGN,
    HdlOpType.ARITH_SHIFT_RIGHT_ASSIGN,
]


class ToVerilog2005Expr(ToHdlCommon):

    GENERIC_BIN_OPS = {
        HdlOpType.AND: " & ",
        HdlOpType.AND_LOG: " && ",
        HdlOpType.OR: " | ",
        HdlOpType.OR_LOG: " || ",
        HdlOpType.NAND: " ~& ",
        HdlOpType.NOR: " ~| ",
        HdlOpType.XOR: " ^ ",
        HdlOpType.XNOR: " ~^ ",

        HdlOpType.DIV: " / ",
        HdlOpType.POW: " ** ",
        HdlOpType.MOD: " % ",

        HdlOpType.EQ: ' == ',
        HdlOpType.NEQ: " != ",

        HdlOpType.SLL: " << ",
        HdlOpType.SRL: " >> ",

        HdlOpType.DOWNTO: ":",

        HdlOpType.ARITH_SHIFT_LEFT_ASSIGN: ' <<<= ',
        HdlOpType.ARITH_SHIFT_RIGHT_ASSIGN: ' >>>= ',
    }
    GENERIC_BIN_OPS.update(ToHdlCommon.GENERIC_BIN_OPS)
    GENERIC_BIN_OPS.update(ASSIGN_OPERATORS_SYMBOLS_C)

    OP_PRECEDENCE = {
        HdlOpType.INDEX: (1, L),

        HdlOpType.CALL: (2, L),
        HdlOpType.TYPE_OF: (2, L),
        HdlOpType.PARAMETRIZATION: (2, L),

        HdlOpType.MINUS_UNARY: (4, R),
        HdlOpType.PLUS_UNARY: (4, R),

        HdlOpType.CONCAT: (5, L),

        HdlOpType.REPL_CONCAT: (6, L),

        HdlOpType.DIV: (7, L),
        HdlOpType.MUL: (7, L),
        HdlOpType.MOD: (7, L),

        HdlOpType.ADD: (8, L),
        HdlOpType.SUB: (8, L),

        HdlOpType.SLL: (9, L),
        HdlOpType.SRL: (9, L),

        HdlOpType.GT: (10, L),
        HdlOpType.LT: (10, L),
        HdlOpType.GE: (10, L),
        HdlOpType.LE: (10, L),

        HdlOpType.EQ:  (11, L),
        HdlOpType.NEQ: (11, L),

        HdlOpType.AND:  (12, L),
        HdlOpType.XOR:  (12, L),
        HdlOpType.OR:   (12, L),
        HdlOpType.NAND: (12, L),
        HdlOpType.XNOR: (12, L),

        HdlOpType.AND_LOG: (13, L),
        HdlOpType.OR_LOG: (13, L),

        HdlOpType.TERNARY: (14, R),

        HdlOpType.RISING: (15, R),
        HdlOpType.FALLING: (15, R),
        HdlOpType.DOWNTO: (16, L),
        HdlOpType.TO: (16, L),
    }
    OP_PRECEDENCE.update({k: (3, R) for k in [
        HdlOpType.NEG,
        HdlOpType.NEG_LOG,
        HdlOpType.OR_UNARY,
        HdlOpType.AND_UNARY,
        HdlOpType.NAND_UNARY,
        HdlOpType.NOR_UNARY,
        HdlOpType.XOR_UNARY,
        HdlOpType.XNOR_UNARY
    ]})
    OP_PRECEDENCE.update({k: (16, ASSOCIATIVITY.NONE)
                          for k in ASSIGN_OPERATORS})

    GENERIC_UNARY_OPS = {
        HdlOpType.NEG_LOG: "!",
        HdlOpType.NEG: "~",
        HdlOpType.MINUS_UNARY: "-",
        HdlOpType.PLUS_UNARY: "+",
        HdlOpType.OR_UNARY: "|",
        HdlOpType.AND_UNARY: "&",
        HdlOpType.NAND_UNARY: "~&",
        HdlOpType.NOR_UNARY: "~|",
        HdlOpType.XOR_UNARY: "^",
        HdlOpType.XNOR_UNARY: "~^",
        HdlOpType.RISING: "posedge ",
        HdlOpType.FALLING: "negedge ",
    }

    def visit_HdlValueInt(self, o):
        """
        :type o: HdlValueInt
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
        :return: True, the flag used to mark that the ; should be added if this is a statement
        """
        w = self.out.write
        if isinstance(o, HdlValueId):
            w(o.val)
        elif is_str(o):
            w('"%s"' % o)
        elif isinstance(o, HdlValueInt):
            self.visit_HdlValueInt(o)
        elif isinstance(o, HdlOp):
            self.visit_HdlOp(o)
        elif o is HdlAll:
            w("*")
        elif o is HdlTypeAuto:
            pass
        elif o is None:
            w("null")
        elif isinstance(o, float):
            w(str(o))
        else:
            raise NotImplementedError(o.__class__, o)
        return True

    def visit_HdlOp(self, o):
        """
        :type o: HdlOp
        """
        w = self.out.write
        op = o.fn
        if op == HdlOpType.CONCAT:
            w = self.out.write
            w("{")
            for is_last, (o_i, _o) in iter_with_last(enumerate(o.ops)):
                self._visit_operand(_o, o_i, o, False, True)
                if not is_last:
                    w(", ")
            w("}")
            return
        elif op == HdlOpType.REPL_CONCAT:
            w = self.out.write
            w("{")
            self._visit_operand(o.ops[0], 0, o, True, False)
            w("{")
            for is_last, (o_i, _o) in iter_with_last(enumerate(o.ops[1:])):
                self._visit_operand(_o, o_i, o, False, True)
                if not is_last:
                    w(", ")
            w("}}")
            return
        elif op == HdlOpType.TERNARY:
            cond, v0, v1 = o.ops
            self._visit_operand(cond, 0, o, True, False)
            w(" ? ")
            self._visit_operand(v0, 1, o, False, False)
            w(" : ")
            self._visit_operand(v1, 2, o, False, False)
            return
        elif op == HdlOpType.TYPE_OF:
            w("type(")
            self._visit_operand(o.ops[0], 0, o, False, True)
            w(")")
            return
        else:
            super(ToVerilog2005Expr, self).visit_HdlOp(o)
        return True

    def visit_type_first_part(self, t):
        """
        :type t: iHdlExpr
        :return: True if the type has also the array dimension part
        """
        w = self.out.write
        t, array_dims = collect_array_dims(t)
        wire_params = get_wire_t_params(t)
        if wire_params is None:
            if t != HdlTypeAuto:
                if isinstance(t, HdlOp) and t.fn == HdlOpType.TYPE_OF:
                    w("var ")
                self.visit_iHdlExpr(t)
        else:
            base_t, width, is_signed, _ = wire_params
            if base_t is not HdlTypeAuto:
                w(base_t.val)
            if is_signed is None:
                pass
            elif is_signed:
                w(" signed")
            else:
                w(" unsigned")

            if width is not None:
                # 1D vector
                w("[")
                self.visit_iHdlExpr(width)
                w("]")
        return len(array_dims) > 0

    def visit_type_array_part(self, t):
        """
        :type t: iHdlExpr
        """
        w = self.out.write
        _, array_dim = collect_array_dims(t)
        for ad in array_dim:
            w("[")
            self.visit_iHdlExpr(ad)
            w("]")
