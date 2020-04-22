from copy import copy

from hdlConvertor.hdlAst._expr import HdlBuiltinFn
from hdlConvertor.hdlAst._statements import HdlStmWait, HdlStmBlock
from hdlConvertor.to.hdlUtils import Indent, iter_with_last
from hdlConvertor.to.verilog.expr import ToVerilog2005Expr


class ToVerilog2005Stm(ToVerilog2005Expr):
    ASSIGN_OPS = {
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

    def __init__(self, out_stream):
        super(ToVerilog2005Stm, self).__init__(out_stream)
        self.top_stm = None

    def visit_iHdlStatement(self, stm):
        """
        :type stm: iHdlStatement
        """
        if self.top_stm is None:
            self.top_stm = stm
            try:
                return ToVerilog2005Expr.visit_iHdlStatement(self, stm)
            finally:
                self.top_stm = None
        else:
            return ToVerilog2005Expr.visit_iHdlStatement(self, stm)

    def visit_HdlStmProcess(self, proc):
        """
        :type proc: HdlStmProcess
        """
        self.visit_doc(proc)
        sens = proc.sensitivity
        body = proc.body
        w = self.out.write
        skip_body = False
        if sens is None:
            if isinstance(body, HdlStmWait):
                skip_body = True
                wait = body
                body = []
            elif (isinstance(body, HdlStmBlock)
                    and body.body
                    and isinstance(body.body[0], HdlStmWait)):
                wait = body.body[0]
                body = body.body[1:]
            else:
                wait = None

            if wait is None:
                assert self.top_stm is proc
                assert isinstance(body, HdlStmBlock), body
                body = body.body
                wait = body[-1]
                assert isinstance(wait, HdlStmWait), wait
                assert len(wait.val) == 0
                body = body[:-1]
                w("initial")
            else:
                if self.top_stm is proc:
                    w("always ")
                w("#")
                assert len(wait.val) == 1
                self.visit_iHdlExpr(wait.val[0])
            _body = HdlStmBlock()
            _body.body = body
            body = _body
        else:
            if self.top_stm is proc:
                w("always ")
            w("@(")
            for last, item in iter_with_last(sens):
                self.visit_iHdlExpr(item)
                if not last:
                    w(", ")
            w(")")

        # to prevent useless newline for empty always/time waits
        if skip_body:
            return True
        else:
            return self.visit_iHdlStatement_in_statement(body)

    def visit_iHdlStatement_in_statement(self, stm):
        """
        Print statement which is body of other statement
        e.g. body of process, branch of if-then-else or case of case stememnt
        """
        w = self.out.write
        if isinstance(stm, HdlStmBlock):
            if len(stm.body) == 1:
                stm = stm.body[0]
            else:
                w(" ")
                return self.visit_HdlStmBlock(stm)

        w("\n")
        with Indent(self.out):
            return self.visit_iHdlStatement(stm)

    def visit_HdlStmBlock(self, o):
        """
        :type o: HdlStmBlock
        """
        self.visit_doc(o)
        w = self.out.write

        w("begin\n")
        with Indent(self.out):
            for s in o.body:
                need_semi = self.visit_iHdlStatement(s)
                if need_semi:
                    w(";\n")
                else:
                    w("\n")
        w("end")
        return False

    def visit_HdlStmIf(self, o):
        """
        :type o: HdlStmIf
        """
        self.visit_doc(o)
        w = self.out.write

        w("if (")
        self.visit_iHdlExpr(o.cond)
        w(")")
        need_semi = self.visit_iHdlStatement_in_statement(o.if_true)

        for cond, stms in o.elifs:
            if need_semi:
                w(";\n")
            else:
                w(" ")
            w("else if (")
            self.visit_iHdlExpr(cond)
            w(")")
            need_semi = self.visit_iHdlStatement_in_statement(stms)

        ifFalse = o.if_false
        if ifFalse is not None:
            if need_semi:
                w(";\n")
            else:
                w(" ")
            w("else")
            need_semi = self.visit_iHdlStatement_in_statement(ifFalse)
        if need_semi:
            w(";")

    def visit_HdlStmAssign(self, o):
        """
        :type o: HdlStmAssign
        :return: True if requires ;\n after end
        """
        self.visit_doc(o)
        w = self.out.write
        if self.top_stm is o:
            w("assign ")
            self.visit_iHdlExpr(o.dst)
            w(" = ")
        else:
            self.visit_iHdlExpr(o.dst)
            if o.is_blocking:
                w(" = ")
            else:
                w(" <= ")

        if o.time_delay is not None:
            w("#")
            self.visit_iHdlExpr(o.time_delay)
            w(" ")
        if o.event_delay is not None:
            w("@")
            if len(o.event_delay) > 1:
                w("(")
            for is_last, e in iter_with_last(o.event_delay):
                self.visit_iHdlExpr(e)
                if not is_last:
                    w(", ")
            if len(o.event_delay) > 1:
                w(")")
            w(" ")

        self.visit_iHdlExpr(o.src)
        return True

    def visit_HdlStmCase(self, o):
        """
        :type o: HdlStmCase

        :return: True if requires ;\n after end
        """
        self.visit_doc(o)
        w = self.out.write
        w("case(")
        self.visit_iHdlExpr(o.switch_on)
        w(")\n")
        with Indent(self.out):
            cases = o.cases
            for k, stms in cases:
                self.visit_iHdlExpr(k)
                w(":")
                need_semi = self.visit_iHdlStatement_in_statement(stms)
                if need_semi:
                    w(";\n")
                else:
                    w("\n")
            defal = o.default
            if defal is not None:
                w("default:")
                need_semi = self.visit_iHdlStatement_in_statement(defal)
                if need_semi:
                    w(";\n")
                else:
                    w("\n")
        w("endcase")
        return False

    def visit_HdlStmWait(self, o):
        """
        :type o: HdlStmWait

        :return: True if requires ;\n after end
        """
        self.visit_doc(o)
        w = self.out.write
        w("#")
        assert len(o.val) == 1, o.val
        self.visit_iHdlExpr(o.val[0])
        return True

    def visit_HdlStmFor(self, o):
        """
        :type o: HdlStmFor

        :return: True if requires ;\n after end
        """
        self.visit_doc(o)
        w = self.out.write
        w("for (")
        if isinstance(o.init, HdlStmBlock):
            init_stms = o.init.body
        else:
            init_stms = [o.init, ]

        for is_last, stm in iter_with_last(init_stms):
            self.visit_iHdlStatement(stm)
            if not is_last:
                w(", ")
        w("; ")
        self.visit_iHdlExpr(o.cond)
        w("; ")
        if isinstance(o.init, HdlStmBlock):
            step_stms = o.step.body
        else:
            step_stms = [o.step, ]

        for is_last, stm in iter_with_last(step_stms):
            self.visit_iHdlStatement(stm)
            if not is_last:
                w(", ")
        w(")")
        return self.visit_iHdlStatement_in_statement(o.body)

    def visit_HdlStmForIn(self, o):
        """
        :type o: HdlStmForIn
        :return: True if requires ;\n after end
        """
        self.visit_doc(o)
        raise NotImplementedError()

    def visit_HdlStmWhile(self, o):
        """
        :type o: HdlStmWhile
        :return: True if requires ;\n after end
        """
        self.visit_doc(o)
        w = self.out.write
        w("while (")
        self.visit_iHdlExpr(o.cond)
        w(") ")
        return self.visit_iHdlStatement(o.body)

    def visit_HdlStmRepeat(self, o):
        """
        :type o: HdlStmRepeat
        :return: True if requires ;\n after end
        """
        self.visit_doc(o)
        w = self.out.write
        w("repeat (")
        self.visit_iHdlExpr(o.n)
        w(") ")
        return self.visit_iHdlStatement(o.body)
