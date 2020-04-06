from itertools import chain

from hdlConvertor.hdlAst import HdlImport, HdlStmProcess, HdlStmIf,\
    HdlStmAssign, HdlStmCase, HdlStmWait, HdlStmReturn, HdlStmFor, HdlStmForIn,\
    HdlStmWhile, HdlStmBlock, iHdlStatement, HdlModuleDec, HdlModuleDef,\
    HdlNamespace, HdlVariableDef, HdlFunctionDef, HdlCall, HdlComponentInst, \
    HdlIntValue, HdlStmBreak, HdlStmContinue, HdlStmRepeat, HdlLibrary, HdlContext


class HdlAstVisitor(object):
    def __init__(self):
        self._visit_call_dispatch_dict = {
            cls: getattr(self, "visit_" + cls.__name__)
            for cls in [
                HdlContext, HdlImport, HdlLibrary, HdlModuleDec, HdlModuleDef,
                HdlNamespace, HdlVariableDef, HdlFunctionDef,
                HdlComponentInst, HdlStmProcess, HdlStmIf, HdlStmAssign,
                HdlStmCase, HdlStmWait, HdlStmRepeat, HdlStmReturn,
                HdlStmBreak, HdlStmContinue, HdlStmFor, HdlStmForIn,
                HdlStmWhile, HdlStmBlock, HdlCall, HdlIntValue
            ]
        }

    def visit_iHdlObj(self, o):
        visit_fn = self._visit_call_dispatch_dict.get(o.__class__, None)
        if visit_fn is not None:
            return visit_fn(o)
        else:
            return self.visit_iHdlExpr(o)

    def visit_doc(self, o):
        pass

    def visit_HdlContext(self, context):
        """
        :type context: HdlContext
        """
        for o in context.objs:
            self.visit_main_obj(o)

    def visit_HdlImport(self, o):
        """
        :type o: HdlImport
        """
        pass

    def visit_HdlLibrary(self, o):
        """
        :type o: HdlLibrary
        """
        pass

    def visit_HdlNamespace(self, o):
        """
        :type o: HdlNamespace
        """
        self.visit_doc(o)
        for o2 in o.objs:
            self.visit_iHdlObj(o2)

    def visit_main_obj(self, o):
        visit_fn = self._visit_call_dispatch_dict.get(o.__class__, None)
        if visit_fn is not None:
            return visit_fn(o)
        else:
            return self.visit_iHdlExpr(o)

    def visit_iHdlStatement(self, o):
        """
        :type o: iHdlStatement
        """
        # statement can be also expressin
        visit_fn = self._visit_call_dispatch_dict.get(o.__class__, None)
        if visit_fn is not None:
            return visit_fn(o)
        else:
            return self.visit_iHdlExpr(o)

    def visit_HdlModuleDec(self, o):
        """
        :type o: HdlModuleDec
        """
        self.visit_doc(o)
        for p in o.params:
            self.visit_param(p)
        for p in o.ports:
            self.visit_port(p)
        for o in o.objs:
            raise NotImplementedError()

    def visit_HdlVariableDef(self, o):
        """
        :type o: HdlVariableDef
        """
        self.visit_doc(o)
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

    def visit_HdlIntValue(self, o):
        """
        :type o: HdlIntValue
        """
        pass

    def visit_port(self, o):
        return self.visit_HdlVariableDef(o)

    def visit_param(self, o):
        return self.visit_HdlVariableDef(o)

    def visit_HdlModuleDef(self, o):
        """
        :type o: HdlModuleDef
        """
        if o.dec is not None:
            self.visit_HdlModuleDec(o.dec)

        self.visit_doc(o)
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
        self.visit_doc(o)
        for pm in chain(o.param_map, o.port_map):
            self.visit_iHdlExpr(pm)

    def visit_HdlFunctionDef(self, o):
        """
        :type o: HdlFunctionDef
        """
        self.visit_doc(o)
        for p in o.params:
            self.visit_HdlVariableDef(p)
        if o.return_t is not None:
            self.visit_iHdlExpr(o.return_t)
        for o2 in o.body:
            self.visit_main_obj(o2)

    def visit_HdlStmProcess(self, o):
        """
        :type o: HdlStmProcess
        """
        self.visit_doc(o)
        self.visit_iHdlStatement(o.body)

    def visit_HdlStmBlock(self, o):
        """
        :type o: HdlStmBlock
        """
        self.visit_doc(o)
        for o in o.body:
            self.visit_iHdlStatement(o)

    def visit_HdlStmCase(self, o):
        """
        :type o: HdlStmCase
        """
        self.visit_doc(o)
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
        self.visit_doc(o)
        self.visit_iHdlExpr(o.val)

    def visit_HdlStmIf(self, o):
        """
        :type o: HdlStmIf
        """
        self.visit_doc(o)
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
        self.visit_doc(o)
        self.visit_iHdlStatement(o.init)
        self.visit_iHdlExpr(o.cond)
        self.visit_iHdlStatement(o.step)
        self.visit_iHdlStatement(o.body)

    def visit_HdlStmForIn(self, o):
        """
        :type o: HdlStmForIn
        """
        self.visit_doc(o)
        for v in o.var_defs:
            self.visit_main_obj(v)
        self.visit_iHdlExpr(o.collection)
        self.visit_iHdlStatement(o.body)

    def visit_HdlStmWhile(self, o):
        """
        :type o: HdlStmWhile
        """
        self.visit_doc(o)
        self.visit_iHdlExpr(o.cond)
        self.visit_iHdlStatement(o.body)

    def visit_HdlStmRepeat(self, o):
        """
        :type o: HdlStmRepeat
        """
        self.visit_doc(o)
        self.visit_iHdlExpr(o.n)
        self.visit_iHdlStatement(o.body)

    def visit_HdlStmReturn(self, o):
        """
        :type o: HdlStmReturn
        """
        self.visit_doc(o)
        if o.val is not None:
            self.visit_iHdlExpr(o.val)

    def visit_HdlStmBreak(self, o):
        """
        :type o: HdlStmBreak
        """
        self.visit_doc(o)

    def visit_HdlStmContinue(self, o):
        """
        :type o: HdlStmContinue
        """
        self.visit_doc(o)

    def visit_HdlStmAssign(self, o):
        """
        :type o: HdlStmAssign
        """
        self.visit_doc(o)
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
