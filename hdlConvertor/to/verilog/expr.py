from hdlConvertor.hdlAst import HdlBuiltinFn, HdlName, HdlIntValue, HdlAll,\
    HdlCall, HdlTypeAuto
from hdlConvertor.to.common import ToHdlCommon
from hdlConvertor.to.hdlUtils import is_str, iter_with_last
from hdlConvertor.to.verilog.utils import collect_array_dims, get_wire_t_params


class ToVerilog2005Expr(ToHdlCommon):

    GENERIC_BIN_OPS = {
        **ToHdlCommon.GENERIC_BIN_OPS,
        HdlBuiltinFn.AND: "&",
        HdlBuiltinFn.LOG_AND: "&&",
        HdlBuiltinFn.OR: "|",
        HdlBuiltinFn.LOG_OR: "||",
        HdlBuiltinFn.NAND: "~&",
        HdlBuiltinFn.NOR: "~|",
        HdlBuiltinFn.XOR: "^",
        HdlBuiltinFn.XNOR: "~^",

        HdlBuiltinFn.DIV: "/",
        HdlBuiltinFn.POW: "**",
        HdlBuiltinFn.MOD: "%",

        HdlBuiltinFn.EQ: '==',
        HdlBuiltinFn.NEQ: "!=",

        HdlBuiltinFn.SLL: "<<",
        HdlBuiltinFn.SRL: ">>",

        HdlBuiltinFn.DOWNTO: ":",

        HdlBuiltinFn.ASSIGN: '=',
        HdlBuiltinFn.PLUS_ASSIGN: '+=',
        HdlBuiltinFn.MINUS_ASSIGN: '-=',
        HdlBuiltinFn.MUL_ASSIGN: '*=',
        HdlBuiltinFn.DIV_ASSIGN: '/=',
        HdlBuiltinFn.MOD_ASSIGN: '%=',
        HdlBuiltinFn.AND_ASSIGN: '&=',
        HdlBuiltinFn.OR_ASSIGN: '|=',
        HdlBuiltinFn.XOR_ASSIGN: '^=',
        HdlBuiltinFn.SHIFT_LEFT_ASSIGN: '<<=',
        HdlBuiltinFn.SHIFT_RIGHT_ASSIGN: '>>=',
        HdlBuiltinFn.ARITH_SHIFT_LEFT_ASSIGN: '<<<=',
        HdlBuiltinFn.ARITH_SHIFT_RIGHT_ASSIGN: '>>>=',
    }
    OP_PRECEDENCE = {
        **{k: 18 for k in [
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
        ]},
        HdlBuiltinFn.RISING: 17,
        HdlBuiltinFn.FALLING: 17,

        HdlBuiltinFn.TERNARY: 16,

        HdlBuiltinFn.AND: 11,
        HdlBuiltinFn.XOR: 11,
        HdlBuiltinFn.OR: 11,
        HdlBuiltinFn.NAND: 11,
        HdlBuiltinFn.XNOR: 11,

        HdlBuiltinFn.EQ: 10,
        HdlBuiltinFn.NEQ: 10,
        HdlBuiltinFn.GT: 9,
        HdlBuiltinFn.LT: 9,
        HdlBuiltinFn.GE: 9,
        HdlBuiltinFn.LE: 9,

        HdlBuiltinFn.CONCAT: 5,
        HdlBuiltinFn.REPL_CONCAT: 5,
        HdlBuiltinFn.ADD: 7,
        HdlBuiltinFn.SUB: 7,
        HdlBuiltinFn.DIV: 6,
        HdlBuiltinFn.NEG: 5,
        HdlBuiltinFn.MUL: 3,

        HdlBuiltinFn.NOT: 3,

        HdlBuiltinFn.DOWNTO: 2,
        HdlBuiltinFn.TO: 2,

        HdlBuiltinFn.CALL: 2,
        HdlBuiltinFn.TYPE_OF: 2,
        HdlBuiltinFn.INDEX: 1,

        HdlBuiltinFn.SLL: 8,
        HdlBuiltinFn.SRL: 8,
    }
    GENERIC_UNARY_OPS = {
        HdlBuiltinFn.NOT: "!",
        HdlBuiltinFn.NEG: "~",
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
        """
        w = self.out.write
        if isinstance(o, HdlName):
            w(o)
            return
        elif is_str(o):
            w('"%s"' % o)
            return
        elif isinstance(o, HdlIntValue):
            return self.visit_HdlIntValue(o)
        elif isinstance(o, HdlCall):
            return self.visit_HdlCall(o)
        elif o is HdlAll:
            w("*")
            return
        elif o is HdlTypeAuto:
            return
        elif o is None:
            w("null")
            return

        raise NotImplementedError(o)

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
            self._visit_operand(cond, 0, o, False, False)
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
            w(base_t)
            if width is not None:
                # 1D vector
                w("[")
                if is_signed:
                    raise NotImplementedError(t)
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
