from hdlConvertor.to.basic_hdl_sim_model.expr import ToBasicHdlSimModelExpr
from hdlConvertor.to.hdlUtils import Indent, iter_with_last
from hdlConvertor.hdlAst._statements import HdlStmIf, HdlStmBlock, HdlStmAssign


class BasicHdlSimModelStm(ToBasicHdlSimModelExpr):

    def print_HdlStmProcess(self, proc):
        """
        :type proc: HdlStmProcess
        """
        w = self.out.write
        w("def ")
        w(proc.labels[0])
        w("(self):\n")
        body = proc.body
        with Indent(self.out):
            self.print_iHdlStatement_in_statement(body)
        w("\n")

    def print_iHdlStatement_in_statement(self, stm):
        if isinstance(stm, HdlStmAssign):
            self.print_HdlStmAssign(stm)
        elif isinstance(stm, HdlStmIf):
            self.print_HdlStmIf(stm)
        elif isinstance(stm, HdlStmBlock):
            self.print_HdlStmBlock(stm)
        else:
            raise NotImplementedError(stm)

    def print_HdlStmBlock(self, stm):
        """
        :type stm: HdlStmBlock
        """
        w = self.out.write
        for is_last, i in iter_with_last(stm.body):
            self.print_iHdlStatement_in_statement(i)
            if not is_last:
                w("\n")

    def print_HdlStmIf(self, stm):
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
        self.print_iHdlExpr(c)
        w(":\n")
        with Indent(self.out):
            self.print_iHdlStatement_in_statement(ifTrue)
            w("\n")

        for (c, _stm) in stm.elifs:
            w("elif ")
            self.print_iHdlExpr(c)
            w(":\n")
            with Indent(self.out):
                self.print_iHdlStatement_in_statement(_stm)
                w("\n")

        w("else:\n")
        with Indent(self.out):
            if ifFalse is None:
                w("pass")
            else:
                self.print_iHdlStatement_in_statement(ifFalse)

    def print_HdlStmAssign(self, a):
        """
        :type a: HdlStmAssign
        """
        w = self.out.write
        self.print_iHdlExpr(a.dst)
        w(" = ")
        if a.is_blocking:
            raise NotImplementedError(a)
        if a.time_delay is not None:
            raise NotImplementedError()
        if a.event_delay is not None:
            raise NotImplementedError()
        self.print_iHdlExpr(a.src)
