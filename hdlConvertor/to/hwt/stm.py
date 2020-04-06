from hdlConvertor.hdlAst import HdlCall, HdlStmIf, HdlStmBlock, HdlStmAssign
from hdlConvertor.to.basic_hdl_sim_model.expr import ToBasicHdlSimModelExpr
from hdlConvertor.to.hdlUtils import Indent, iter_with_last
from hdlConvertor.to.hwt.expr import ToHwtExpr


class ToHwtStm(ToHwtExpr):

    def visit_HdlStmProcess(self, proc):
        """
        :type proc: HdlStmProcess
        """
        w = self.out.write
        w("# ")
        if proc.labels:
            w(proc.labels[0])
            w(", ")
        w("sens: ")
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
        body = proc.body
        self.visit_iHdlStatement(body)
        #w("\n")

    def visit_HdlStmBlock(self, stm):
        """
        :type stm: HdlStmBlock
        """
        w = self.out.write
        for is_last, i in iter_with_last(stm.body):
            self.visit_iHdlStatement(i)
            if not is_last:
                w(",\n")

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
        w("If(")
        self.visit_iHdlExpr(c)
        w(",\n")
        with Indent(self.out):
            self.visit_iHdlStatement(ifTrue)
            w("\n")
        for (c, _stm) in stm.elifs:
            w(").Elif(")
            self.visit_iHdlExpr(c)
            w(",\n")
            with Indent(self.out):
                self.visit_iHdlStatement(_stm)
            w("\n")
            w(")")
        if not stm.elifs:
            w(")")

        if ifFalse is not None:
            w(".Else(\n")
            with Indent(self.out):
                self.visit_iHdlStatement(ifFalse)
            w(")\n")

    def visit_HdlStmAssign(self, a):
        """
        :type a: HdlStmAssign
        """
        w = self.out.write
        self.visit_iHdlExpr(a.dst)
        if a.is_blocking:
            raise NotImplementedError(a)
        if a.time_delay is not None:
            raise NotImplementedError()
        if a.event_delay is not None:
            raise NotImplementedError()
        w("(")
        self.visit_iHdlExpr(a.src)
        w(")")
