from itertools import chain

from hdlConvertor.hdlAst import HdlImport, HdlStmProcess, HdlStmIf,\
    HdlStmAssign, HdlStmCase, HdlStmWait, HdlStmReturn, HdlStmFor, HdlStmForIn,\
    HdlStmWhile, HdlStmBlock, iHdlStatement, HdlModuleDec, HdlModuleDef,\
    HdlNamespace, HdlVariableDef, HdlFunctionDef, HdlCall, HdlComponentInst
from hdlConvertor.hdlAst._structural import HdlLibrary
from hdlConvertor.hdlAst._statements import HdlStmBreak, HdlStmContinue


class HdlAstVisitor(object):
    def visit_doc(self, o):
        pass

    def visit_HdlContext(self, context):
        """
        :type context: HdlContext
        """
        for o in context.objs:
            if isinstance(o, HdlImport):
                self.visit_HdlImport(o)
            elif isinstance(o, HdlLibrary):
                self.visit_HdlLibrary(o)
            else:
                self.visit_main_obj(o)

    def visit_HdlLibrary(self, o):
        """
        :type o: HdlLibrary
        """
        pass

    def visit_main_obj(self, o):
        if isinstance(o, HdlModuleDec):
            return self.visit_HdlModuleDec(o)
        elif isinstance(o, HdlModuleDef):
            return self.visit_HdlModuleDef(o)
        elif isinstance(o, HdlNamespace):
            return self.visit_HdlNamespace(o)
        elif isinstance(o, HdlVariableDef):
            return self.visit_HdlVariableDef(o)
        elif isinstance(o, HdlFunctionDef):
            return self.visit_HdlFunctionDef(o)
        elif isinstance(o, iHdlStatement):
            return self.visit_iHdlStatement(o)
        elif isinstance(o, HdlComponentInst):
            return self.visit_HdlComponentInst(o)
        else:
            return self.visit_iHdlExpr(o)

    def visit_iHdlStatement(self, stm):
        """
        :type o: iHdlStatement
        """
        # statement can be also expressin
        if isinstance(stm, iHdlStatement):
            self.visit_doc(stm)

        if isinstance(stm, HdlStmProcess):
            return self.visit_HdlStmProcess(stm)
        elif isinstance(stm, HdlStmIf):
            return self.visit_HdlStmIf(stm)
        elif isinstance(stm, HdlStmAssign):
            return self.visit_HdlStmAssign(stm)
        elif isinstance(stm, HdlStmCase):
            return self.visit_HdlStmCase(stm)
        elif isinstance(stm, HdlStmWait):
            return self.visit_HdlStmWait(stm)
        elif isinstance(stm, HdlStmReturn):
            return self.visit_HdlStmReturn(stm)
        elif isinstance(stm, HdlStmBreak):
            return self.visit_HdlStmBreak(stm)
        elif isinstance(stm, HdlStmContinue):
            return self.visit_HdlStmContinue(stm)
        elif isinstance(stm, HdlStmFor):
            return self.visit_HdlStmFor(stm)
        elif isinstance(stm, HdlStmForIn):
            return self.visit_HdlStmForInt(stm)
        elif isinstance(stm, HdlStmWhile):
            return self.visit_HdlStmWhile(stm)
        elif isinstance(stm, HdlStmBlock):
            return self.visit_HdlStmBlock(stm)
        else:
            return self.visit_iHdlExpr(stm)

    def visit_HdlModuleDec(self, o):
        """
        :type o: HdlModuleDec
        """
        for p in o.params:
            self.visit_param(p)
        for p in o.ports:
            self.visit_port(p)
        for o in o.objs:
            raise NotImplementedError()
        if o.body:
            self.visit_HdlModuleDef(o.body)

    def visit_HdlVariableDef(self, o):
        """
        :type o: HdlVariableDef
        """
        self.visit_type(o.type)
        if o.value is not None:
            self.visit_iHdlExr(o.value)

    def visit_iHdlExpr(self, o):
        """
        :type o: iHdlExpr
        :return: iHdlExpr
        """
        return o

    def visit_HdlCall(self, o):
        """
        :type o: HdlCall
        :return: iHdlExpr
        """
        for op in o.ops:
            self.visit_iHdlExpr(op)
        return o

    def visit_port(self, o):
        return self.visit_HdlVariableDef(o)

    def visit_param(self, o):
        return self.visit_HdlVariableDef(o)

    def visit_HdlModuleDef(self, o):
        """
        :type o: HdlModuleDef
        """
        for _o in o.objs:
            if isinstance(_o, iHdlStatement):
                self.visit_iHdlStatement(_o)
            elif isinstance(_o, HdlVariableDef):
                self.visit_HdlVariableDef(_o)
            elif isinstance(_o, HdlComponentInst):
                self.visit_HdlComponentInst(_o)
            else:
                raise NotImplementedError(_o)

    def visit_HdlComponentInst(self, o):
        """
        :type o: HdlComponentInst
        """
        for pm in chain(o.param_map, o.port_map):
            self.visit_iHdlExpr(pm)

    def visit_HdlFunctionDef(self, o):
        """
        :type o: HdlFunctionDef
        """
        for p in o.params:
            self.visit_HdlVariableDef(p)
        if o.return_t is not None:
            self.visit_iHdlExpr(o.return_t)
        for o2 in o.body:
            self.visit_main_obj(o2)

    def visit_HdlStmProcess(self, proc):
        """
        :type proc: HdlStmProcess
        """
        self.visit_iHdlStatement(proc.body)

    def visit_HdlStmBlock(self, o):
        """
        :type o: HdlStmBlock
        """
        for o in o.body:
            self.visit_iHdlStatement(o)

    def visit_HdlStmCase(self, o):
        """
        :type o: HdlStmCase
        """
        self.visit_iHdlExpr(o.switch_on)
        for c, stm in o.cases:
            self.visit_iHdlExpr(c)
            self.visit_iHdlStatement(stm)
        if o.default is not None:
            self.visit_iHdlStatement(o.default)

    def visit_HdlStmWait(self, o):
        """
        :type o: HdlStmWait
        """
        self.visit_iHdlExpr(o.val)

    def visit_HdlStmIf(self, o):
        """
        :type o: HdlStmIf
        """
        self.visit_iHdlExpr(o.cond)
        if o.if_true is not None:
            self.visit_iHdlStatement(o.if_true)
        for c, stm in o.elifs:
            self.visit_iHdlExpr(c)
            self.visit_iHdlStatement(stm)
        if o.if_false is not None:
            self.visit_iHdlStatement(o.if_false)

    def visit_HdlStmFor(self, o):
        """
        :type o: HdlStmFor
        """
        self.visit_iHdlStatement(o.init)
        self.visit_iHdlExpr(o.cond)
        self.visit_iHdlStatement(o.step)
        self.visit_iHdlStatement(o.body)

    def visit_HdlStmForIn(self, o):
        """
        :type o: HdlStmForIn
        """
        raise TypeError("does not support HdlStmForIn", self, o)

    def visit_HdlStmWhile(self, o):
        """
        :type o: HdlStmWhile
        """
        self.visit_iHdlExpr(o.cond)
        self.visit_iHdlStatement(o.body)

    def visit_HdlStmAssign(self, o):
        """
        :type o: HdlStmAssign
        """
        self.visit_iHdlExpr(o.src)
        self.visit_iHdlExpr(o.dst)
        if o.event_delay is not None:
            self.visit_iHdlExpr(o.event_delay)
        if o.time_delay is not None:
            self.visit_iHdlExpr(o.time_delay)

    def visit_type(self, t):
        """
        :type t: iHdlExpr
        """
        self.visit_iHdlExpr(t)
