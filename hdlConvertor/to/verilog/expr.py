from hdlConvertor.hdlAst import HdlBuiltinFn, HdlName, HdlIntValue, HdlAll,\
    HdlCall, HdlTypeAuto
from hdlConvertor.py_ver_compatibility import is_str
from hdlConvertor.to.common import ToHdlCommon
from hdlConvertor.to.hdlUtils import iter_with_last
from hdlConvertor.to.verilog.utils import collect_array_dims, get_wire_t_params


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
        HdlBuiltinFn.INDEX: 1,

        HdlBuiltinFn.CALL: 2,
        HdlBuiltinFn.TYPE_OF: 2,
        HdlBuiltinFn.PARAMETRIZATION: 2,

        HdlBuiltinFn.MINUS_UNARY: 4,
        HdlBuiltinFn.PLUS_UNARY: 4,

        HdlBuiltinFn.CONCAT: 5,

        HdlBuiltinFn.REPL_CONCAT: 6,

        HdlBuiltinFn.DIV: 7,
        HdlBuiltinFn.MUL: 7,
        HdlBuiltinFn.MOD: 7,

        HdlBuiltinFn.ADD: 8,
        HdlBuiltinFn.SUB: 8,

        HdlBuiltinFn.SLL: 9,
        HdlBuiltinFn.SRL: 9,

        HdlBuiltinFn.GT: 10,
        HdlBuiltinFn.LT: 10,
        HdlBuiltinFn.GE: 10,
        HdlBuiltinFn.LE: 10,

        HdlBuiltinFn.EQ: 11,
        HdlBuiltinFn.NEQ: 11,

        HdlBuiltinFn.AND: 12,
        HdlBuiltinFn.XOR: 12,
        HdlBuiltinFn.OR: 12,
        HdlBuiltinFn.NAND: 12,
        HdlBuiltinFn.XNOR: 12,

        HdlBuiltinFn.AND_LOG: 13,
        HdlBuiltinFn.OR_LOG: 13,

        HdlBuiltinFn.TERNARY: 14,

        HdlBuiltinFn.RISING: 15,
        HdlBuiltinFn.FALLING: 15,
        HdlBuiltinFn.DOWNTO: 16,
        HdlBuiltinFn.TO: 16,
    }
    OP_PRECEDENCE.update({k: 3 for k in [
        HdlBuiltinFn.NEG,
        HdlBuiltinFn.NEG_LOG,
        HdlBuiltinFn.OR_UNARY,
        HdlBuiltinFn.AND_UNARY,
        HdlBuiltinFn.NAND_UNARY,
        HdlBuiltinFn.NOR_UNARY,
        HdlBuiltinFn.XOR_UNARY,
        HdlBuiltinFn.XNOR_UNARY
    ]})
    OP_PRECEDENCE.update({k: 16 for k in [
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
