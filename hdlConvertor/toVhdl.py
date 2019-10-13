from hdlConvertor.toHdlUtils import Indent, AutoIndentingStream,\
    iter_with_last_flag, UnIndent, is_str
from hdlConvertor.hdlAst import HdlDirection, HdlBuiltinFn, HdlName,\
    HdlIntValue, HdlAll, HdlCall, HdlOthers, iHdlStatement, HdlStmProcess,\
    HdlStmIf, HdlStmAssign, HdlStmCase, HdlStmWait, HdlStmReturn, HdlStmFor, \
    HdlVariableDef, HdlModuleDec, HdlFunctionDef, HdlComponentInst,\
    HdlModuleDef, HdlNamespace, HdlImport
from hdlConvertor.hdlAst._statements import HdlStmBlock


class ToVhdl():
    """
    Convert hdlObject AST back to VHDL-1993
    """
    INDENT_STEP = "    "
    DIR2V = {
        HdlDirection.IN: "IN",
        HdlDirection.OUT: "OUT",
        HdlDirection.INOUT: "INOUT",
    }

    GENERIC_BIN_OPS = {
        HdlBuiltinFn.AND: "AND",
        HdlBuiltinFn.LOG_AND: "AND",
        HdlBuiltinFn.OR: "OR",
        HdlBuiltinFn.LOG_OR: "OR",
        HdlBuiltinFn.SUB: "-",
        HdlBuiltinFn.ADD: "+",
        HdlBuiltinFn.MUL: "*",
        HdlBuiltinFn.DIV: "/",
        HdlBuiltinFn.MOD: "MOD",
        HdlBuiltinFn.NAND: "NAND",
        HdlBuiltinFn.NOR: "NOR",
        HdlBuiltinFn.XOR: "XOR",
        HdlBuiltinFn.XNOR: "XNOR",
        HdlBuiltinFn.EQ: '=',
        HdlBuiltinFn.NEQ: "/=",
        HdlBuiltinFn.LT: "<",
        HdlBuiltinFn.LE: "<=",
        HdlBuiltinFn.GT: ">",
        HdlBuiltinFn.GE: ">=",
        HdlBuiltinFn.SLL: "SLL",
        HdlBuiltinFn.SRL: "SRL",
        HdlBuiltinFn.TO: "TO",
        HdlBuiltinFn.DOWNTO: "DOWNTO",
        HdlBuiltinFn.ARROW: "=>",
        HdlBuiltinFn.MAP_ASSOCIATION: "=>",
    }

    def __init__(self, out_stream):
        self.out = AutoIndentingStream(out_stream, self.INDENT_STEP)
        self.used_libraries = set()

    def print_doc(self, obj):
        doc = obj.doc
        if doc is not None:
            doc = doc.split("\n")
            w = self.out.write
            for last, d in iter_with_last_flag(doc):
                if last and d == "":
                    break
                w("--")
                w(d)
                w("\n")

    def print_direction(self, d):
        vd = self.DIR2V[d]
        self.out.write(vd)

    def print_generic_or_port_declr(self, o):
        """
        :type p: HdlVariableDef
        """
        self.print_doc(o)
        w = self.out.write
        w(o.name)
        w(" : ")
        d = o.direction
        if d != HdlDirection.INTERNAL:
            self.print_direction(d)
            w(" ")
        self.print_type(o.type)
        v = o.value
        if v:
            w(" := ")
            self.print_expr(v)

    def print_module_header(self, e, vhdl_obj_name="ENTITY"):
        """
        :param e: Entity
        :type e: HdlModuleDec
        """
        self.print_doc(e)
        w = self.out.write
        w(vhdl_obj_name)
        w(" ")
        w(e.name)
        w(" IS\n")
        gs = e.params
        if gs:
            with Indent(self.out):
                w("GENERIC(\n")
                with Indent(self.out):
                    for last, g in iter_with_last_flag(gs):
                        self.print_generic_or_port_declr(g)
                        if last:
                            w("\n")
                        else:
                            w(",\n")

                w(");\n")
        ps = e.ports
        if ps:
            with Indent(self.out):
                w("PORT(\n")
                with Indent(self.out):
                    for last, p in iter_with_last_flag(ps):
                        self.print_generic_or_port_declr(p)
                        if last:
                            w("\n")
                        else:
                            w(",\n")
                w(");\n")
        w("END ")
        w(vhdl_obj_name)
        w(";\n")

    def print_component(self, o):
        """
        :type o: HdlModuleDec
        """
        self.print_module_header(o, vhdl_obj_name="COMPONENT")

    def print_assert(self, args):
        """
        :type args: List[iHdlExpr]
        """
        w = self.out.write
        w("ASSERT ")
        for is_last, (prefix, a) in iter_with_last_flag(
                zip(("", "REPORT ", "SEVERITY "), args)):
            w(prefix)
            self.print_expr(a)
            if not is_last:
                w(" ")

    def print_report(self, args):
        """
        :type args: List[iHdlExpr]
        """
        w = self.out.write
        w("REPORT ")
        for is_last, (prefix, a) in iter_with_last_flag(
                zip(("", "SEVERITY "), args)):
            w(prefix)
            self.print_expr(a)
            if not is_last:
                w(" ")

    def print_expr(self, expr):
        w = self.out.write
        if isinstance(expr, HdlName):
            w(expr)
            return
        elif is_str(expr):
            w('"%s"' % expr)
            return
        elif isinstance(expr, HdlIntValue):
            v = expr.val
            bits = expr.bits
            if bits is None:
                if expr.base is not None:
                    if expr.base == 256:
                        w("'%s'" % str(v))
                        return
                    bases = {
                        2: "B",
                        8: "O",
                        16: "X",
                    }
                    b = bases[expr.base]
                    w('%s"%"' % (b, v))
                w(str(v))
                return

            elif bits % 8 == 0:
                f = 'X"{0:0%dX}"' % (bits / 8)
            else:
                f = '"{0:0%db}"' % (bits)
            w(f.format(v))

            return
        elif isinstance(expr, HdlName):
            w(v)
            return
        elif isinstance(expr, HdlAll):
            w("*")
            return
        elif isinstance(expr, HdlCall):
            pe = self.print_expr
            fn = expr.ops[0]
            if fn == HdlName("assert"):
                self.print_assert(expr.ops[1:])
                return
            elif fn == HdlName("report"):
                self.print_report(expr.ops[1:])
                return

            o = expr
            op = expr.fn
            symbol = self.GENERIC_BIN_OPS.get(op, None)
            if symbol is not None:
                w("(")
                pe(o.ops[0])
                w(" ")
                w(symbol)
                w(" ")
                pe(o.ops[1])
                w(")")
                return
            elif op == HdlBuiltinFn.NOT:
                w("!")
                pe(o.ops[0])
                return
            elif op == HdlBuiltinFn.NEG:
                w("~")
                pe(o.ops[0])
                return
            elif op == HdlBuiltinFn.RISING:
                w("RISIG_EDGE(")
                pe(o.ops[0])
                w(")")
                return
            elif op == HdlBuiltinFn.FALLING:
                w("FALLING_EDGE(")
                pe(o.ops[0])
                w(")")
                return
            elif op == HdlBuiltinFn.NEG:
                w("~")
                pe(o.ops[0])
                return
            elif op == HdlBuiltinFn.CONCAT:
                w("{")
                pe(o.ops[0])
                w(", ")
                pe(o.ops[1])
                w("}")
                return
            elif op == HdlBuiltinFn.INDEX or op == HdlBuiltinFn.CALL:
                pe(o.ops[0])
                w("(")
                for isLast, a in iter_with_last_flag(o.ops[1:]):
                    pe(a)
                    if not isLast:
                        w(", ")
                w(")")
                return
            elif op == HdlBuiltinFn.DOT:
                pe(o.ops[0])
                w(".")
                pe(o.ops[1])
                return
            elif op == HdlBuiltinFn.TERNARY:
                pe(o.ops[0])
                w(" ? ")
                o0, o1 = o.ops[1:]
                pe(o0)
                w(" : ")
                pe(o1)
                return
            elif op == HdlBuiltinFn.APOSTROPHE:
                pe(o.ops[0])
                w("'")
                args = o.ops[1]
                if isinstance(args, list):
                    # aggregate
                    w("(")
                    for isLast, a in iter_with_last_flag(args):
                        pe(a)
                        if not isLast:
                            w(", ")
                    w(")")
                else:
                    # normal attribute
                    pe(args)
                return
            else:
                raise NotImplementedError(op)
        elif expr is HdlAll:
            w("ALL")
            return
        elif isinstance(expr, list):
            w("(\n")
            with Indent(self.out):
                for is_last, elem in iter_with_last_flag(expr):
                    self.print_expr(elem)
                    if not is_last:
                        w(",\n")
            w(")")
            return
        elif expr is HdlAll:
            w("ALL")
            return
        elif expr is HdlOthers:
            w("OTHERS")
            return
        raise NotImplementedError(expr)

    def print_type(self, t):
        """
        :type t: iHdlExpr
        """
        self.print_expr(t)

    def print_variable(self, var, end=";\n"):
        """
        :type var: HdlVariableDef
        """
        self.print_doc(var)
        name = var.name
        t = var.type
        latch = var.is_latched
        c = var.is_const
        w = self.out.write
        if c:
            w("CONSTANT ")
        elif latch:
            w("VARIABLE ")
        else:
            w("SIGNAL ")
        w(name)
        w(" : ")
        self.print_type(t)
        v = var.value
        if v is not None:
            w(" := ")
            self.print_expr(v)
        w(end)

    def print_process(self, proc):
        """
        :type proc: HdlStmProcess
        """
        sens = proc.sensitivity
        body = proc.body
        w = self.out.write

        w("PROCESS")
        if sens:
            w("(")
            for last, item in iter_with_last_flag(sens):
                self.print_expr(item)
                if not last:
                    w(", ")
            w(")")
        w("\n")
        self.print_block(body, force_space_before=False)
        w(" PROCESS;\n")

    def print_block(self, stms, force_space_before=True):
        """
        :type stms: Union[List[iHdlStatement], iHdlStatement, iHdlExpr]
        :return: True if statements are wrapped in begin-end block
        """
        w = self.out.write
        if isinstance(stms, HdlStmBlock):
            must_have_begin_end = True
            stms = stms.body
        elif isinstance(stms, list):
            must_have_begin_end = len(stms) != 1
        else:
            must_have_begin_end = False
            stms = [stms, ]

        if must_have_begin_end:
            if force_space_before:
                w(" BEGIN\n")
            else:
                w("BEGIN\n")
        else:
            w("\n")

        with Indent(self.out):
            for s in stms:
                if isinstance(s, iHdlStatement):
                    self.print_statement(s)
                else:
                    self.print_expr(s)
                    w(";\n")

        if must_have_begin_end:
            w("END")
            return True

        return False

    def print_if(self, stm):
        """
        :type stm: HdlStmIf
        """
        w = self.out.write
        c = stm.cond
        ifTrue = stm.if_true
        ifFalse = stm.if_false

        w("IF ")
        self.print_expr(c)
        w(" THEN ")
        need_space = self.print_block(ifTrue)

        for cond, stms in stm.elifs:
            if need_space:
                w(" ")
            w("ELSIF ")
            self.print_expr(cond)
            w(" THEN ")
            need_space = self.print_block(stms)

        if ifFalse is not None:
            if need_space:
                w(" ")
            w("ELSE")
            self.print_block(ifFalse)
        if need_space:
            w("\n")
        w("END IF;\n")

    def print_assignment(self, a):
        """
        :type a: HdlStmAssign
        """
        s = a.src
        d = a.dst
        w = self.out.write
        if a.time_delay is not None:
            raise NotImplementedError()
        if a.event_delay is not None:
            raise NotImplementedError()

        self.print_expr(d)
        w(" <= ")
        self.print_expr(s)
        w(";\n")

    def print_case(self, cstm):
        """
        :type cstm: HdlStmCase
        """
        w = self.out.write
        w("CASE ")
        self.print_expr(cstm.switch_on)
        w(" IS\n")
        with Indent(self.out):
            cases = cstm.cases
            for k, stms in cases:
                w("WHEN ")
                self.print_expr(k)
                w(" => ")
                is_block = self.print_block(stms)
                if is_block:
                    w("\n")
            defal = cstm.default
            if defal is not None:
                is_block = w("WHEN OTHERS => ")
                self.print_block(defal)
                if is_block:
                    w("\n")
        w("END CASE;\n")

    def print_statement(self, o):
        """
        :type o: iHdlStatement
        """
        self.print_doc(o)
        if isinstance(o, HdlStmProcess):
            self.print_process(o)
        elif isinstance(o, HdlStmIf):
            self.print_if(o)
        elif isinstance(o, HdlStmAssign):
            self.print_assignment(o)
        elif isinstance(o, HdlStmCase):
            self.print_case(o)
        elif isinstance(o, HdlStmWait):
            self.print_wait(o)
        elif isinstance(o, HdlStmReturn):
            self.print_return(o)
        elif isinstance(o, HdlStmFor):
            self.print_for(o)
        else:
            raise NotImplementedError(o)

    def print_return(self, o):
        """
        :type o: HdlStmReturn
        """
        w = self.out.write
        w("RETURN")
        if o.val is not None:
            w(" ")
            self.print_expr(o.val)
        w(";\n")

    def print_for(self, o):
        """
        :type o: HdlStmFor
        """
        w = self.out.write
        w("FOR ")
        self.print_expr(o.params[0])
        w(" IN ")
        self.print_expr(o.params[1])
        w(" LOOP\n")
        with Indent(self.out):
            for b in o.body:
                self.print_statement(b)
        w("END FOR;\n")

    def print_wait(self, o):
        """
        :type o: HdlStmWait
        """
        w = self.out.write
        w("WAIT")
        for e in o.val:
            if isinstance(e, HdlCall) and e.fn == HdlBuiltinFn.MUL:
                w(" FOR ")
                self.print_expr(e.ops[0])
                w(" ")
                self.print_expr(e.ops[1])
            else:
                w(" ON ")
                self.print_expr(e)
        w(";\n")

    def print_map_item(self, item):
        self.print_expr(item)

    def print_map(self, map_):
        w = self.out.write
        with Indent(self.out):
            for last, m in iter_with_last_flag(map_):
                self.print_map_item(m)
                if last:
                    w("\n")
                else:
                    w(",\n")

    def print_component_instance(self, c):
        """
        :type c: HdlComponentInst
        """
        self.print_doc(c)
        w = self.out.write
        self.print_expr(c.name)
        w(": ")
        self.print_expr(c.module_name)
        gms = c.param_map
        if gms:
            w(" GENERIC MAP(\n")
            self.print_map(gms)
            w(")")

        pms = c.port_map
        if pms:
            w(" PORT MAP(\n")
            self.print_map(pms)
            w(")")
        w(";")

    def print_body_items(self, objs):
        w = self.out.write
        in_def_section = True
        with Indent(self.out):
            for o in objs:
                if isinstance(o, HdlVariableDef):
                    assert in_def_section, o
                    self.print_variable(o)
                    continue
                elif isinstance(o, HdlModuleDec):
                    assert in_def_section, o
                    self.print_component(o)
                    continue
                elif isinstance(o, HdlFunctionDef):
                    assert in_def_section, o
                    self.print_function(o)
                    continue

                if in_def_section:
                    with UnIndent(self.out):
                        w("BEGIN\n")
                    in_def_section = False

                if isinstance(o, HdlComponentInst):
                    self.print_component_instance(o)
                    w("\n")
                elif isinstance(o, iHdlStatement):
                    self.print_statement(o)
                else:
                    raise NotImplementedError(o)
        if in_def_section:
            w("BEGIN\n")

    def print_module_body(self, a):
        """
        :type a: HdlModuleDef
        """
        w = self.out.write
        w("ARCHITECTURE ")
        w(a.name)
        w(" OF ")
        w(a.module_name)
        w(" IS\n")
        self.print_body_items(a.objs)
        self.out.write("END ARCHITECTURE;\n")

    def print_function(self, o):
        """
        :type o: HdlFunctionDef
        """
        w = self.out.write
        self.print_doc(o)
        is_procedure = o.return_t is None
        if is_procedure:
            w("PROCEDURE ")
        else:
            w("FUNCTION ")

        w(o.name)

        w(" (")
        with Indent(self.out):
            for is_last, par in iter_with_last_flag(o.params):
                self.print_variable(par, end="")
                if not is_last:
                    w(",\n")
        w(")")
        if not is_procedure:
            w(" RETURN ")
            self.print_type(o.return_t)
        w("\n")
        w("IS\n")
        self.print_body_items(o.body)
        w("END FUNCTION;\n")

    def print_library(self, o):
        w = self.out.write
        w("LIBRARY ")
        self.print_expr(o)
        w(";\n")

    def print_hdl_import(self, o):
        """
        :type o: HdlImport
        """
        self.print_doc(o)
        w = self.out.write
        lib_name = o.path[0]
        if lib_name not in self.used_libraries:
            self.print_library(lib_name)
            self.used_libraries.add(lib_name)

        w("USE ")
        for last, p in iter_with_last_flag(o.path):
            self.print_expr(p)
            if not last:
                w(".")
        w(";\n")

    def print_namespace(self, o):
        """
        :type o: HdlNamespace
        """
        self.print_doc(o)
        w = self.out.write
        # if o.declaration_only:
        w("PACKAGE ")
        w(o.name)
        w(" IS\n")
        with Indent(self.out):
            for _o in o.objs:
                self.print_main_obj(_o)

        w("END PACKAGE;\n")

    def print_main_obj(self, o):
        w = self.out.write
        if isinstance(o, HdlModuleDec):
            w("\n")
            self.print_module_header(o)
            w("\n")
        elif isinstance(o, HdlModuleDef):
            self.print_module_body(o)
        elif isinstance(o, HdlNamespace):
            self.print_namespace(o)
        elif isinstance(o, HdlVariableDef):
            self.print_variable(o)
        elif isinstance(o, HdlFunctionDef):
            self.print_function(o)
        else:
            raise NotImplementedError(o)

    def print_context(self, context):
        """
        :type context: HdlContext
        """
        for o in context.objs:
            if isinstance(o, HdlImport):
                self.print_hdl_import(o)
            else:
                self.print_main_obj(o)


if __name__ == "__main__":
    import os
    import sys
    BASE_DIR = os.path.join(os.path.dirname(__file__), "..")
    TEST_DIR = os.path.join(BASE_DIR, 'tests', 'vhdl')
    from hdlConvertor.language import Language
    from hdlConvertor import HdlConvertor
    c = HdlConvertor()
    filenames = [os.path.join(TEST_DIR, "package_constants.vhd")]
    d = c.parse(filenames, Language.VHDL, [], False, True)
    tv = ToVhdl(sys.stdout)
    tv.print_context(d)
