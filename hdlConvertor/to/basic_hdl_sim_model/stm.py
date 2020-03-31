from hdlConvertor.hdlAst import HdlCall, HdlStmIf, HdlStmBlock, HdlStmAssign
from hdlConvertor.to.basic_hdl_sim_model.expr import ToBasicHdlSimModelExpr
from hdlConvertor.to.hdlUtils import Indent, iter_with_last


class BasicHdlSimModelStm(ToBasicHdlSimModelExpr):

    def visit_HdlStmProcess(self, proc):
        """
        :type proc: HdlStmProcess
        """
        w = self.out.write
        w("# sensitivity: ")
        for last, s in iter_with_last(proc.sensitivity):
            if isinstance(s, HdlCall):
                w(str(s.fn))
                w(" ")
                self.visit_iHdlExpr(s.ops[0])
            else:
                self.visit_iHdlExpr(s)
            if not last:
                w(", ")
        w("\n")
        w("def ")
        w(proc.labels[0])
        w("(self):\n")
        body = proc.body
        with Indent(self.out):
            self.visit_iHdlStatement_in_statement(body)
        w("\n")

    def visit_iHdlStatement_in_statement(self, stm):
        if isinstance(stm, HdlStmAssign):
            self.visit_HdlStmAssign(stm)
        elif isinstance(stm, HdlStmIf):
            self.visit_HdlStmIf(stm)
        elif isinstance(stm, HdlStmBlock):
            self.visit_HdlStmBlock(stm)
        else:
            raise NotImplementedError(stm)

    def visit_HdlStmBlock(self, stm):
        """
        :type stm: HdlStmBlock
        """
        w = self.out.write
        for is_last, i in iter_with_last(stm.body):
            self.visit_iHdlStatement_in_statement(i)
            if not is_last:
                w("\n")

    def visit_HdlStmIf(self, stm):
        """
        :type stm: HdlStmIf

        if cond:
            ...
        else:
            ...

        will become

        c, cVld = sim_eval_cond(cond)
        if not cVld:
            # ivalidate outputs
        elif c:
            ...
        else:
            ...
        """
        w = self.out.write
        c = stm.cond
        ifTrue = stm.if_true
        ifFalse = stm.if_false
        w("if ")
        self.visit_iHdlExpr(c)
        w(":\n")
        with Indent(self.out):
            self.visit_iHdlStatement_in_statement(ifTrue)
            w("\n")

        for (c, _stm) in stm.elifs:
            w("elif ")
            self.visit_iHdlExpr(c)
            w(":\n")
            with Indent(self.out):
                self.visit_iHdlStatement_in_statement(_stm)
                w("\n")

        w("else:\n")
        with Indent(self.out):
            if ifFalse is None:
                w("pass")
            else:
                self.visit_iHdlStatement_in_statement(ifFalse)

    def visit_HdlStmAssign(self, a):
        """
        :type a: HdlStmAssign
        """
        w = self.out.write
        self.visit_iHdlExpr(a.dst)
        w(" = ")
        if a.is_blocking:
            raise NotImplementedError(a)
        if a.time_delay is not None:
            raise NotImplementedError()
        if a.event_delay is not None:
            raise NotImplementedError()
        self.visit_iHdlExpr(a.src)
