from hdlConvertor.hdlAst import HdlOp, HdlStmIf, HdlStmBlock, HdlStmAssign
from hdlConvertor.to.hdlUtils import Indent, iter_with_last
from hdlConvertor.to.hwt.expr import ToHwtExpr


class ToHwtStm(ToHwtExpr):

    def visit_HdlStmProcess(self, o):
        """
        :type o: HdlStmProcess
        """
        w = self.out.write
        if o.labels:
            w("# ")
            if o.labels:
                w(o.labels[0])
                # w(", ")
        #w("sens: ")
        #if o.sensitivity:
        #    for last, s in iter_with_last(o.sensitivity):
        #        if isinstance(s, HdlOp):
        #            w(str(s.fn))
        #            w(" ")
        #            self.visit_iHdlExpr(s.ops[0])
        #        else:
        #            self.visit_iHdlExpr(s)
        #        if not last:
        #            w(", ")
        w("\n")
        self.visit_doc(o)
        self.visit_iHdlStatement(o.body)
        #w("\n")

    def visit_HdlStmBlock(self, o):
        """
        :type o: HdlStmBlock
        """
        self.visit_doc(o)
        w = self.out.write
        for is_last, i in iter_with_last(o.body):
            self.visit_iHdlStatement(i)
            if not is_last:
                w(",\n")

    def visit_HdlStmIf(self, o):
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
        self.visit_doc(o)
        w = self.out.write
        w("If(")
        self.visit_iHdlExpr(o.cond)
        w(",\n")
        with Indent(self.out):
            self.visit_iHdlStatement(o.if_true)
            w("\n")
        w(")")
        for (c, _stm) in o.elifs:
            w(".Elif(")
            self.visit_iHdlExpr(c)
            w(",\n")
            with Indent(self.out):
                self.visit_iHdlStatement(_stm)
            w("\n")
            w(")")

        ifFalse = o.if_false
        if ifFalse is not None:
            w(".Else(\n")
            with Indent(self.out):
                self.visit_iHdlStatement(ifFalse)
                w("\n")
            w(")")

    def visit_HdlStmAssign(self, o):
        """
        :type o: HdlStmAssign
        """
        self.visit_doc(o)
        w = self.out.write
        self.visit_iHdlExpr(o.dst)
        if o.is_blocking:
            raise NotImplementedError(o)
        if o.time_delay is not None:
            raise NotImplementedError()
        if o.event_delay is not None:
            raise NotImplementedError()
        w("(")
        self.visit_iHdlExpr(o.src)
        w(")")

    def visit_HdlStmCase(self, o):
        """
        :type o: HdlStmCase
        """
        self.visit_doc(o)
        w = self.out.write
        w("Switch(")
        self.visit_iHdlExpr(o.switch_on)
        w(")")
        with Indent(self.out):
            for c, stm in o.cases:
                w("\\\n")
                w(".Case(")
                self.visit_iHdlExpr(c)
                w(",\n")
                with Indent(self.out):
                    self.visit_iHdlStatement(stm)
                w(")")
            if o.default is not None:
                w("\\\n")
                w(".Default(\n")
                with Indent(self.out):
                    self.visit_iHdlStatement(o.default)
                    w(")")
