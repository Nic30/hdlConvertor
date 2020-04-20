from hdlConvertor.hdlAst import HdlDirection, HdlName, HdlIntValue,\
    HdlCall, HdlAll, HdlTypeAuto, HdlOthers, HdlTypeType
from hdlConvertor.py_ver_compatibility import is_str
from hdlConvertor.to.hdl_ast_visitor import HdlAstVisitor


class ToJson(HdlAstVisitor):

    def visit_HdlContext(self, context):
        """
        :type context: HdlContext
        """
        res = []
        for o in context.objs:
            d = self.visit_main_obj(o)
            res.append(d)
        return res

    def visit_HdlLibrary(self, o):
        """
        :type o: HdlLibrary
        """
        return self.visit_iHdlObjWithName(o)

    def visit_iHdlObjWithName(self, o):
        """
        :type o: iHdlObj
        """
        d = self.visit_iHdlObj(o)
        d["name"] = o.name
        return d

    def visit_CodePosition(self, o):
        """
        :type o: CodePosition
        """
        return (o.start_line, o.start_column, o.stop_line, o.stop_column)

    def visit_iHdlObj(self, o):
        """
        :type o: iHdlObj
        """
        d = {
            "__class__": o.__class__.__name__,
        }
        if o.doc:
            d["doc"] = o.doc
        if o.position:
            d["position"] = self.visit_CodePosition(o.position)
        return d

    def visit_HdlImport(self, o):
        """
        :type o: HdlImport
        """
        d = self.visit_iHdlObj(o)
        d["path"] = self.visit_iHdlExpr(o.path)
        return d

    def visit_HdlNamespace(self, o):
        """
        :type o: HdlNamespace
        """
        d = self.visit_iHdlObjWithName(o)
        d["objs"] = [self.visit_main_obj(o2) for o2 in o.objs]
        d["declaration_only"] = o.declaration_only
        return d

    def visit_HdlDirection(self, o):
        """
        :type o: HdlDirection
        """
        if o == HdlDirection.UNKNOWN:
            return None
        else:
            return o.name

    def visit_HdlVariableDef(self, o):
        """
        :type o: HdlVariableDef
        """
        d = self.visit_iHdlObjWithName(o)

        for flag_name in ["is_latched", "is_const", "is_static",
                          "is_virtual", ]:
            if getattr(o, flag_name):
                d[flag_name] = True
        d["type"] = self.visit_iHdlExpr(o.type)
        if o.value is not None:
            d["value"] = self.visit_iHdlExpr(o.value)
        d["direction"] = self.visit_HdlDirection(o.direction)
        return d

    def visit_HdlModuleDec(self, o):
        """
        :type o: HdlModuleDec
        """
        d = self.visit_HdlNamespace(o)
        d["params"] = [self.visit_HdlVariableDef(p) for p in o.params]
        d["ports"] = [self.visit_HdlVariableDef(p) for p in o.ports]
        return d

    def visit_HdlModuleDef(self, o):
        """
        :type o: HdlModuleDec
        """
        d = self.visit_iHdlObjWithName(o)
        if o.dec is not None:
            d["dec"] = self.visit_HdlModuleDec(o.dec)
        if o.module_name is not None:
            d["module_name"] = self.visit_iHdlExpr(o.module_name)
        d["objs"] = [self.visit_main_obj(o2) for o2 in o.objs]
        return d

    def _visit_iHdlStatement(self, o):
        """
        :type o: iHdlStatement
        """
        d = self.visit_iHdlObj(o)
        d["labels"] = [str(x) for x in o.labels]
        if o.in_prepoc:
            d["in_prepoc"] = True
        return d

    def visit_HdlComponentInst(self, o):
        """
        :type o: HdlComponentInst
        """
        d = self.visit_iHdlObjWithName(o)
        if o.module_name is not None:
            d["module_name"] = self.visit_iHdlExpr(o.module_name)
        d["param_map"] = [self.visit_iHdlExpr(pm) for pm in o.param_map]
        d["port_map"] = [self.visit_iHdlExpr(pm) for pm in o.port_map]
        return d

    def visit_HdlFunctionDef(self, o):
        """
        :type o: HdlFunctionDef
        """
        d = self.visit_iHdlObjWithName(o)
        for f in ["is_declaration_only",
                  "is_operator",
                  "is_static",
                  "is_task",
                  "is_virtual",
                  ]:
            if getattr(o, f):
                d[f] = True
        if o.return_t is not None:
            d["return_t"] = self.visit_iHdlExpr(o.return_t)
        d["params"] = [self.visit_HdlVariableDef(v) for v in o.params]
        d["body"] = [self.visit_main_obj(o2) for o2 in o.body]
        return d

    def visit_HdlStmProcess(self, o):
        """
        :type o: HdlStmProcess
        """
        d = self._visit_iHdlStatement(o)
        if o.sensitivity is not None:
            d["sensitivity"] = [self.visit_iHdlExpr(x) for x in o.sensitivity]
        d["body"] = self.visit_iHdlStatement(o.body)
        return d

    def visit_HdlStmIf(self, o):
        """
        :type o: HdlStmIf
        """
        d = self._visit_iHdlStatement(o)
        d["if_true"] = self.visit_iHdlStatement(o.if_true)
        d["elifs"] = [
            [self.visit_iHdlExpr(c), self.visit_iHdlStatement(stm)]
            for c, stm in o.elifs
        ]
        if o.if_false is not None:
            d["if_false"] = self.visit_iHdlStatement(o.if_false)
        return d

    def visit_HdlStmBlockJoinType(self, o):
        """
        :type o: HdlStmBlockJoinType
        """
        return o.name

    def visit_HdlStmBlock(self, o):
        """
        :type o: HdlStmBlock
        """
        d = self._visit_iHdlStatement(o)
        d["join_t"] = self.visit_HdlStmBlockJoinType(o.join_t)
        d["body"] = [self.visit_main_obj(o2) for o2 in o.body]
        return d

    def visit_HdlStmCase(self, o):
        """
        :type o: HdlStmCase

        :return: True if requires ;\n after end
        """
        d = self._visit_iHdlStatement(o)
        d["switch_on"] = self.visit_iHdlExpr(o.switch_on)
        d["cases"] = [
            [self.visit_iHdlExpr(c), self.visit_iHdlStatement(stm)]
            for c, stm in o.cases
        ]
        if o.default is not None:
            d["default"] = self.visit_iHdlStatement(o.default)
        return d

    def visit_HdlStmWait(self, o):
        """
        :type o: HdlStmWait
        """
        d = self._visit_iHdlStatement(o)
        d["val"] = self.visit_iHdlExpr(o.val)
        return d

    def visit_HdlStmFor(self, o):
        """
        :type o: HdlStmFor
        """
        d = self._visit_iHdlStatement(o)
        d["init"] = self.visit_iHdlStatement(o.init)
        d["cond"] = self.visit_iHdlExpr(o.cond)
        d["step"] = self.visit_iHdlStatement(o.step)
        d["body"] = self.visit_iHdlStatement(o.body)
        return d

    def visit_HdlStmForIn(self, o):
        """
        :type o: HdlStmForIn
        """
        d = self._visit_iHdlStatement(o)
        d["var_defs"] = [self.visit_main_obj(o2) for o2 in o.var_defs]
        d["collection"] = self.visit_iHdlExpr(o.collection)
        d["body"] = self.visit_iHdlStatement(o.body)
        return d

    def visit_HdlStmWhile(self, o):
        """
        :type o: HdlStmWhile
        """
        d = self._visit_iHdlStatement(o)
        d["cond"] = self.visit_iHdlExpr(o.cond)
        d["body"] = self.visit_iHdlStatement(o.body)
        return d

    def visit_HdlStmRepeat(self, o):
        """
        :type o: HdlStmRepeat
        """
        d = self._visit_iHdlStatement(o)
        d["n"] = self.visit_iHdlExpr(o.n)
        d["body"] = self.visit_iHdlStatement(o.body)
        return d

    def visit_HdlStmAssign(self, o):
        """
        :type o: HdlStmAssign
        """
        d = self._visit_iHdlStatement(o)
        if o.event_delay is not None:
            d["event_delay"] = self.visit_iHdlExpr(o.event_delay)
        if o.time_delay is not None:
            d["time_delay"] = self.visit_iHdlExpr(o.time_delay)
        d["src"] = self.visit_iHdlExpr(o.src)
        d["dst"] = self.visit_iHdlExpr(o.dst)
        return d

    def visit_HdlStmReturn(self, o):
        """
        :type o: HdlStmReturn
        """
        d = self._visit_iHdlStatement(o)
        if o.val is not None:
            d["val"] = self.visit_iHdlExpr(o.val)
        return d

    def visit_HdlStmContinue(self, o):
        """
        :type o: HdlStmContinue
        """
        return self._visit_iHdlStatement(o)

    def visit_HdlStmBreak(self, o):
        """
        :type o: HdlStmBreak
        """
        return self._visit_iHdlStatement(o)

    def visit_iHdlExpr(self, o):
        """
        :type o: iHdlExpr
        :return: iHdlExpr
        """
        if isinstance(o, HdlName):
            d = {
                "__class__": o.__class__.__name__,
                "val": str(o),
            }
        elif is_str(o) or o is None:
            d = o
        elif isinstance(o, HdlIntValue):
            d = self.visit_HdlIntValue(o)
        elif isinstance(o, HdlCall):
            d = self.visit_HdlCall(o)
        elif o is HdlAll or\
                o is HdlTypeAuto or\
                o is HdlOthers or\
                o is HdlTypeType:
            d = {
                "__class__": o.__class__.__name__,
            }
        elif isinstance(o, (list, tuple)):
            return [self.visit_iHdlExpr(o2) for o2 in o]
        else:
            raise NotImplementedError(o)
        return d

    def visit_HdlIntValue(self, o):
        """
        :type o: HdlIntValue
        """
        d = {
            "__class__": o.__class__.__name__,
            "val": o.val,
        }
        if o.bits is not None:
            d["bits"] = o.bits
        if o.base is not None:
            d["base"] = o.base
        return d

    def visit_HdlCall(self, o):
        """
        :type o: HdlCall
        :return: iHdlExpr
        """
        d = {
            "__class__": o.__class__.__name__,
            "ops": [self.visit_iHdlExpr(op) for op in o.ops],
            "fn": o.fn.name
        }
        return d


if __name__ == "__main__":
    import os
    from hdlConvertor.language import Language
    from hdlConvertor import HdlConvertor
    from pprint import pprint
    BASE_DIR = os.path.join(os.path.dirname(__file__), "..", "..")
    TEST_DIR = os.path.join(BASE_DIR, 'tests', 'verilog')
    c = HdlConvertor()
    filenames = [os.path.join(TEST_DIR, "arbiter_tb.v")]
    # AES = os.path.join(BASE_DIR, "..", "aes")
    # files = [
    #    # "aes_cipher_top.v",
    #    # "aes_key_expand_128.v",
    #    # "aes_inv_cipher_top.v",  "aes_rcon.v",
    #    "test_bench_top.v",
    #    # "aes_inv_sbox.v",        "aes_sbox.v",
    # ]
    #
    # filenames = [os.path.join(AES, f) for f in files]
    d = c.parse(filenames, Language.VERILOG, [], False, True)
    tv = ToJson()
    res = tv.visit_HdlContext(d)
    pprint(res)
