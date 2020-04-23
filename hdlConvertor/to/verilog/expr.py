from hdlConvertor.hdlAst import HdlBuiltinFn, HdlName, HdlIntValue, HdlAll,\
    HdlCall, HdlTypeAuto
from hdlConvertor.py_ver_compatibility import is_str
from hdlConvertor.to.common import ToHdlCommon, ASSOCIATIVITY
from hdlConvertor.to.hdlUtils import iter_with_last
from hdlConvertor.to.verilog.utils import collect_array_dims, get_wire_t_params


L = ASSOCIATIVITY.L_TO_R
R = ASSOCIATIVITY.R_TO_L


class ToVerilog2005Expr(ToHdlCommon):

    GENERIC_BIN_OPS = {
        HdlBuiltinFn.AND: " & ",
        HdlBuiltinFn.AND_LOG: " && ",
        HdlBuiltinFn.OR: " | ",
        HdlBuiltinFn.OR_LOG: " || ",
        HdlBuiltinFn.NAND: " ~& ",
        HdlBuiltinFn.NOR: " ~| ",
        HdlBuiltinFn.XOR: " ^ ",
        HdlBuiltinFn.XNOR: " ~^ ",

        HdlBuiltinFn.DIV: " / ",
        HdlBuiltinFn.POW: " ** ",
        HdlBuiltinFn.MOD: " % ",

        HdlBuiltinFn.EQ: ' == ',
        HdlBuiltinFn.NEQ: " != ",

        HdlBuiltinFn.SLL: " << ",
        HdlBuiltinFn.SRL: " >> ",

        HdlBuiltinFn.DOWNTO: ":",

        HdlBuiltinFn.ASSIGN: ' = ',
        HdlBuiltinFn.PLUS_ASSIGN: ' += ',
        HdlBuiltinFn.MINUS_ASSIGN: ' -= ',
        HdlBuiltinFn.MUL_ASSIGN: ' *= ',
        HdlBuiltinFn.DIV_ASSIGN: ' /= ',
        HdlBuiltinFn.MOD_ASSIGN: ' %= ',
        HdlBuiltinFn.AND_ASSIGN: ' &= ',
        HdlBuiltinFn.OR_ASSIGN: ' |= ',
        HdlBuiltinFn.XOR_ASSIGN: ' ^= ',
        HdlBuiltinFn.SHIFT_LEFT_ASSIGN: ' <<= ',
        HdlBuiltinFn.SHIFT_RIGHT_ASSIGN: ' >>= ',
        HdlBuiltinFn.ARITH_SHIFT_LEFT_ASSIGN: ' <<<= ',
        HdlBuiltinFn.ARITH_SHIFT_RIGHT_ASSIGN: ' >>>= ',
    }
    GENERIC_BIN_OPS.update(ToHdlCommon.GENERIC_BIN_OPS)

    OP_PRECEDENCE = {
        HdlBuiltinFn.INDEX: (1, L),

        HdlBuiltinFn.CALL: (2, L),
        HdlBuiltinFn.TYPE_OF: (2, L),
        HdlBuiltinFn.PARAMETRIZATION: (2, L),

        HdlBuiltinFn.MINUS_UNARY: (4, R),
        HdlBuiltinFn.PLUS_UNARY: (4, R),

        HdlBuiltinFn.CONCAT: (5, L),

        HdlBuiltinFn.REPL_CONCAT: (6, L),

        HdlBuiltinFn.DIV: (7, L),
        HdlBuiltinFn.MUL: (7, L),
        HdlBuiltinFn.MOD: (7, L),

        HdlBuiltinFn.ADD: (8, L),
        HdlBuiltinFn.SUB: (8, L),

        HdlBuiltinFn.SLL: (9, L),
        HdlBuiltinFn.SRL: (9, L),

        HdlBuiltinFn.GT: (10, L),
        HdlBuiltinFn.LT: (10, L),
        HdlBuiltinFn.GE: (10, L),
        HdlBuiltinFn.LE: (10, L),

        HdlBuiltinFn.EQ:  (11, L),
        HdlBuiltinFn.NEQ: (11, L),

        HdlBuiltinFn.AND:  (12, L),
        HdlBuiltinFn.XOR:  (12, L),
        HdlBuiltinFn.OR:   (12, L),
        HdlBuiltinFn.NAND: (12, L),
        HdlBuiltinFn.XNOR: (12, L),

        HdlBuiltinFn.AND_LOG: (13, L),
        HdlBuiltinFn.OR_LOG: (13, L),

        HdlBuiltinFn.TERNARY: (14, R),

        HdlBuiltinFn.RISING: (15, R),
        HdlBuiltinFn.FALLING: (15, R),
        HdlBuiltinFn.DOWNTO: (16, L),
        HdlBuiltinFn.TO: (16, L),
    }
    OP_PRECEDENCE.update({k: (3, R) for k in [
        HdlBuiltinFn.NEG,
        HdlBuiltinFn.NEG_LOG,
        HdlBuiltinFn.OR_UNARY,
        HdlBuiltinFn.AND_UNARY,
        HdlBuiltinFn.NAND_UNARY,
        HdlBuiltinFn.NOR_UNARY,
        HdlBuiltinFn.XOR_UNARY,
        HdlBuiltinFn.XNOR_UNARY
    ]})
    OP_PRECEDENCE.update({k: (16, ASSOCIATIVITY.NONE) for k in [
        HdlBuiltinFn.ASSIGN,
        HdlBuiltinFn.PLUS_ASSIGN,
        HdlBuiltinFn.MINUS_ASSIGN,
        HdlBuiltinFn.MUL_ASSIGN,
        HdlBuiltinFn.DIV_ASSIGN,
        HdlBuiltinFn.MOD_ASSIGN,
        HdlBuiltinFn.AND_ASSIGN,
        HdlBuiltinFn.OR_ASSIGN,
        HdlBuiltinFn.XOR_ASSIGN,
        HdlBuiltinFn.SHIFT_LEFT_ASSIGN,
        HdlBuiltinFn.SHIFT_RIGHT_ASSIGN,
        HdlBuiltinFn.ARITH_SHIFT_LEFT_ASSIGN,
        HdlBuiltinFn.ARITH_SHIFT_RIGHT_ASSIGN,
    ]})

    GENERIC_UNARY_OPS = {
        HdlBuiltinFn.NEG_LOG: "!",
        HdlBuiltinFn.NEG: "~",
        HdlBuiltinFn.MINUS_UNARY: "-",
        HdlBuiltinFn.PLUS_UNARY: "+",
        HdlBuiltinFn.OR_UNARY: "|",
        HdlBuiltinFn.AND_UNARY: "&",
        HdlBuiltinFn.NAND_UNARY: "~&",
        HdlBuiltinFn.NOR_UNARY: "~|",
        HdlBuiltinFn.XOR_UNARY: "^",
        HdlBuiltinFn.XNOR_UNARY: "~^",
        HdlBuiltinFn.RISING: "posedge ",
        HdlBuiltinFn.FALLING: "negedge ",
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
        :return: True, the flag used to mark that the ; should be added if this is a statement
        """
        w = self.out.write
        if isinstance(o, HdlName):
            w(o.val)
        elif is_str(o):
            w('"%s"' % o)
        elif isinstance(o, HdlIntValue):
            self.visit_HdlIntValue(o)
        elif isinstance(o, HdlCall):
            self.visit_HdlCall(o)
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

    def visit_HdlCall(self, o):
        """
        :type o: HdlCall
        """
        w = self.out.write
        op = o.fn
        if op == HdlBuiltinFn.CONCAT:
            w = self.out.write
            w("{")
            for is_last, (o_i, _o) in iter_with_last(enumerate(o.ops)):
                self._visit_operand(_o, o_i, o, False, True)
                if not is_last:
                    w(", ")
            w("}")
            return
        elif op == HdlBuiltinFn.REPL_CONCAT:
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
        elif op == HdlBuiltinFn.TERNARY:
            cond, v0, v1 = o.ops
            self._visit_operand(cond, 0, o, True, False)
            w(" ? ")
            self._visit_operand(v0, 1, o, False, False)
            w(" : ")
            self._visit_operand(v1, 2, o, False, False)
            return
        elif op == HdlBuiltinFn.TYPE_OF:
            w("type(")
            self._visit_operand(o.ops[0], 0, o, False, True)
            w(")")
            return
        else:
            super(ToVerilog2005Expr, self).visit_HdlCall(o)
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
                if isinstance(t, HdlCall) and t.fn == HdlBuiltinFn.TYPE_OF:
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
