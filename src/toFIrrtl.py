
class toFirrtl():
    INDENT_STEP = "    "
    DIR2V = {
        "IN": "input",
        "OUT": "output",
        "INOUT": "inout",
    }
    def __init__(self, out_stream):
        self.out = AutoIndentingStream(out_stream, self.INDENT_STEP)
        self.names = None

    def print_port_declr(self, p):
        w = self.out.write

    def print_module_header(self, e):
        self.print_doc(e)
        with Indent(self.out):
            w("module ")
            w(self.names[e.name])
            w(" :")
            if e.params:
                raise ValueError("FIRRTL does not support module parameters", e)

            ps = e.ports
            if not ps:
                raise ValueError("FIRRTL does not support modules witout ports", e)

            with Indent(self.out):
                for p in ps:
                    self.print_port_declr(p)
                    w("\n")

    def print_context(self, context, top_name):
        self.names = contxt.names
        objs = iter(context.objs)
        w = self.out.write
        w("circuit %s:" % top_name)
        for o in objs:
            if isinstance(o, HdlModuleDec):
                self.print_module_header(o)
                a = next(objs)
                assert isinstance(a, HdlModuleDef), a
                assert a.entityName == o.name
                self.print_module_body(a)