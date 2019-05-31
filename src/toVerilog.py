

class Indent():
    """
    indentation context
    """

    def __init__(self, autoIndentStream):
        self.s = autoIndentStream
        self.original_indent = None

    def __enter__(self):
        s = self.s
        self.original_indent = s.indent_str
        s.indent_cnt += 1
        s.indent_str = s.indent_str + s.INDENT_STEP
    
    def __exit__(self, exception_type, exception_value, traceback):
        s = self.s
        s.indent_cnt -= 1
        s.indent_str = self.original_indent


class AutoIndentingStream():

    def __init__(self, stream, indent_step):
        """
        :param stream: output stream
        :param indent_step: string of indent
        """

        self.INDENT_STEP = indent_step
        self.stream = stream
        self.requires_indent = True
        self.indent_cnt = 0
        self.indent_str = ""

    def write(self, s):
        w = self.stream.write
        if self.requires_indent:
            w(self.indent_str)
        w(s)
        self.requires_indent = s.endswith("\n")


def iter_with_last_flag(it):
    # Ensure it's an iterator and get the first field
    it = iter(it)
    prev = next(it)
    for item in it:
        # Lag by one item so I know I'm not at the end
        yield False, prev
        prev = item

    # Last item
    yield True, prev

        
class ToVerilog():
    """
    Convert hdlObject AST back to Verilog 
    """
    INDENT_STEP = "    "
    DIR2V = {
        "IN": "input",
        "OUT": "output",
        "INOUT": "inout",
    }
    WIRE = {'literal': {'type': 'ID', 'value': 'wire'}}
    GENERIC_BIN_OPS = {
        "AND": "&",
        "LOG_AND": "&&",
        "OR": "|",
        "LOG_OR": "||",
        "SUB": "-",
        "ADD": "+",
        "MUL": "*",
        "DIV": "/",
        "MOD": "%",
        "NAND": "~&",
        "NOR": "~|",
        "XOR": "^",
        "XNOR": "~^",
        "EQ": '==',
        "NEQ": "!=",
        "LOWERTHAN": "<",
        "LE": "<=",
        "GREATERTHAN": ">",
        "GE": ">=",
        "SLL": "<<",
        "SRL": ">>", 
    }
    
    def __init__(self, out_stream):
        self.out = AutoIndentingStream(out_stream, self.INDENT_STEP)
        
    def print_doc(self, obj):
        doc = obj.get("__doc__", None)
        if doc is not None:
            doc = doc.split("\n")
            w = self.out.write
            for last, d in iter_with_last_flag(doc):
                if last and d == "":
                    break
                w("// ")
                w(d)
                w("\n")

    def print_direction(self, d):
        vd = self.DIR2V[d]
        self.out.write(vd)
    
    def print_generic_declr(self, g):
        self.print_doc(g)
        w = self.out.write
        w("parameter ")
        is_array = self.print_type_first_part(g["type"])
        w(" ")
        w(g["name"])
        v = g.get("value", None)
        if v:
            w(" = ")
            self.print_expr(v)

    def print_port_declr(self, p):
        w = self.out.write
        d = p['direction']
        var = p['variable']
        self.print_doc(var)
        name = var["name"]
        self.print_direction(d)
        w(" ")
        l = var.get("latched", False)
        if l:
            w("reg ")

        t = var["type"]
        is_array = self.print_type_first_part(t)
        if is_array:
            raise NotImplementedError()
        
        w(name)

    def print_module_header(self, e):
        self.print_doc(e)
        w = self.out.write
        w("module ")
        w(e["name"])
        gs = e.get("generics", [])
        if gs:
            w(" #(\n")
            with Indent(self.out):
                for last, g in iter_with_last_flag(gs):
                    self.print_generic_declr(g)
                    if last:
                        w("\n")
                    else:
                        w(",\n")
            
            w(")")
        ps = e.get("ports", [])
        if ps:
            w("(\n")
            with Indent(self.out):
                for last, p in iter_with_last_flag(ps):
                    self.print_port_declr(p)
                    if last:
                        w("\n")
                    else:
                        w(",\n")
            w(")")
        w(";\n")

    def print_expr(self, expr):
        w = self.out.write
        if isinstance(expr, str):
            w(expr)
            return
        
        lit = expr.get("literal", None)
        if lit is not None:
            t = lit["type"]
            v = lit["value"]
            if t == "INT":
                bits = lit["bits"]
                if bits == -1:
                    w(str(v))
                else:
                    w(str(bits))
                    w("'h")
                    w("%x" % v)
            elif t == "ID":
                w(v)
            elif t == "ALL":
                w("*")
            else:
                raise NotImplementedError()
            return
            
        o = expr.get("binOperator", None)
        
        if o is not None:
            op = o["operator"]
            symbol = self.GENERIC_BIN_OPS.get(op, None)
            if symbol is not None:
                w("(")
                self.print_expr(o["op0"])
                w(" ")
                w(symbol)
                w(" ")
                self.print_expr(o["op1"])
                w(")")
                return

            if op == "DOWNTO":
                self.print_expr(o["op0"])
                w(":")
                self.print_expr(o["op1"])
            elif op == "TO":
                self.print_expr(o["op1"])
                w(":")
                self.print_expr(o["op0"])
            elif op == "NOT":
                w("!")
                self.print_expr(o["op0"])
            elif op == "NEG":
                w("~")
                self.print_expr(o["op0"])
            elif op == "RISING":
                w("posedge ")
                self.print_expr(o["op0"])
            elif op == "FALLING":
                w("negedge ")
                self.print_expr(o["op0"])
            elif op == "NEG":
                w("~")
                self.print_expr(o["op0"])
            elif op == "CONCAT":
                w("{")
                self.print_expr(o["op0"])
                w(", ")
                self.print_expr(o["op1"])
                w("}")
            elif op == "INDEX":
                self.print_expr(o["op0"])
                w("[")
                self.print_expr(o["op1"])
                w("]")
            elif op == "REPL_CONCAT":
                w("{(")
                self.print_expr(o["op0"])
                w("){")
                self.print_expr(o["op1"])
                w("}}")
            elif op == "TERNARY":
                self.print_expr(o['op0'])
                w(" ? ")
                o0, o1 = o['operands']
                self.print_expr(o0)
                w(" : ")
                self.print_expr(o1)
            
            else:
                raise NotImplementedError(op)
            return
        raise NotImplementedError()

    def print_type_first_part(self, t):
        """
        :return: True if the type has also the array dimmension part
        """
        w = self.out.write
        if t != self.WIRE:
            op = t.get("binOperator", None)
            if op is None:
                assert t["literal"]
                self.print_expr(t)
                return False

            if op and op.get('operator', None) == "CALL" and op["op0"] == self.WIRE:
                # 1D vector
                w("[")
                ops = op["operands"]
                size_expr =  ops[0]
                is_signed = ops[1]["literal"]["value"]
                if is_signed:
                    raise NotImplementedError()
                self.print_expr(size_expr)
                w("] ")
            else:
                o = op["operator"]
                if o == "INDEX":
                    self.print_type_first_part(op["op0"])
                    return True
                raise NotImplementedError()
        
        return False

    def print_type_array_part(self, t):
        w = self.out.write
        op = t.get("binOperator", None)
        if op and op["operator"] == "INDEX":
            self.print_type_array_part(op["op0"])
            w("[")
            self.print_expr(op["op1"])
            w("]")

    def print_variable(self, var):
        self.print_doc(var)
        name = var["name"]
        t = var["type"]
        l = var.get("latched", False)
        w = self.out.write
        if l:
            w("reg ")
        else:
            w("wire ")
        is_array = self.print_type_first_part(t)
        w(name)
        if is_array:
            w(" ")
            self.print_type_array_part(t)

    def print_process(self, proc):
        sens = proc['sensitivity']
        body = proc['body']
        w = self.out.write
        
        w("always @ (")
        for last, item in iter_with_last_flag(sens):
            self.print_expr(item)
            if not last:
                w(", ")
        w(") begin\n")
        with Indent(self.out):
            for stm in body:
                self.print_statement(stm)

        w("end\n")

    def print_block(self, stms):
        """
        :return: True if statements are wrapped in begin-end block
        """
        w = self.out.write
        if len(stms) != 1:
            w(" begin\n")
        else:
            w("\n")

        with Indent(self.out):
            for s in stms:
                self.print_statement(s)

        if len(stms) != 1:
            w("end\n")
            return True
        return False
        
    def print_if(self, stm):
        w = self.out.write
        c = stm['cond']
        ifTrue = stm["ifTrue"]
        ifFalse = stm.get("ifFalse", None)
        
        w("if (")
        self.print_expr(c)
        w(")")
        need_space = self.print_block(ifTrue)

        for cond, stms in stm.get('elseIfs', []):
            if need_space:
                w(" ")
            w("else if (")
            self.print_expr(cond)
            w(")")
            need_space = self.print_block(stms)
        
        if ifFalse is not None:
            if need_space:
                w(" ")
            w("else")
            self.print_block(ifFalse)
    
    def print_assignment(self, a, is_top=False):
        s = a["src"]
        d = a["dst"]
        w = self.out.write
        if is_top:
            w("assign ")
            self.print_expr(d)
            w(" = ")
            self.print_expr(s)
        else:
            self.print_expr(d)
            w(" <= ")
            self.print_expr(s)
        w(";\n")

    def print_case(self, cstm):
        w = self.out.write
        w("case(")
        self.print_expr(cstm["switchOn"])
        w(")")
        with Indent(self.out):
            cases = cstm['cases']
            for k, stms in cases:
                self.print_expr(k)
                w(":")
                is_block = self.print_block(stms)
                if is_block:
                    w("\n")
            defal = cstm.get("default", None)
            if defal is not None:
                w("default:")
                self.print_block(defal)
                
        w("endcase\n")

    def print_statement(self, stm, is_top=False):
        self.print_doc(stm)
        t = stm["type"]
        if t == "PROCESS":
            self.print_process(stm)
        elif t == "IF":
            self.print_if(stm)
        elif t == "ASSIGMENT":
            self.print_assignment(stm, is_top=is_top)
        elif t == "CASE":
            self.print_case(stm)
        else:
            raise NotImplementedError(t)

    def print_map_item(self, item):
        op = item.get("binOperator", None)
        if op and op["operator"] == "MAP_ASSOCIATION":
            w = self.out.write
            # k, v pair
            k, v  = op["op0"], op["op1"]
            w(".")
            self.print_expr(k)
            w("(")
            self.print_expr(v)
            w(")")
        else:
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
        self.print_doc(c)
        w = self.out.write
        self.print_expr(c["entityName"])
        w(" ")
        self.print_expr(c["name"])
        gms = c['genericMap']
        if gms:
            w(" #(\n")
            self.print_map(gms)
            w(")")

        pms = c['portMap']
        if pms:
            w(" (\n")
            self.print_map(pms)
            w(")")
        w(";")

    def print_module_body(self, a):
        w = self.out.write
        with Indent(self.out):
            for v in a['variables']:
                self.print_variable(v)
                w(";\n")

            for c in a['componentInstances']:
                self.print_component_instance(c)
                w("\n")

            for s in a['statements']:
                self.print_statement(s, is_top=True)
         
        self.out.write("endmodule\n")

    def apply(self, context):
        mod_head2body = {a["entityName"] : a for a in context.get("architectures", [])}
        for e in context.get("entities", []):
            self.print_module_header(e)
            a = mod_head2body[e["name"]]
            self.print_module_body(a)


if __name__ == "__main__":
    import os
    import sys
    BASE_DIR = os.path.join(os.path.dirname(__file__), "..")
    SKBUILD_DIR = os.path.join(BASE_DIR, "_skbuild")
    # there should be only one directory with the name of the python configuration like linux-x86_64-3.7
    PY_CONFIG = os.listdir(SKBUILD_DIR)[0]
    SKBUILD_BUILD_DIR = os.path.join(SKBUILD_DIR, PY_CONFIG, "setuptools", "lib")
    sys.path.insert(1, SKBUILD_BUILD_DIR)

    TEST_DIR = os.path.join(BASE_DIR, 'tests', 'verilog')
    from hdlConvertor import hdlConvertor
    from hdlConvertor.language import Language
    c = hdlConvertor()
    filenames = [os.path.join(TEST_DIR, "sram.v")]
    d = c.parse(filenames, Language.VERILOG, [], False, False)
    tv = ToVerilog(sys.stdout)
    tv.apply(d)
