from itertools import chain

from hdlConvertor.hdlAst._defs import HdlVariableDef
from hdlConvertor.hdlAst._expr import iHdlExpr, HdlCall, HdlBuiltinFn,\
    HdlDirection, HdlName
from hdlConvertor.hdlAst._statements import HdlStmProcess
from hdlConvertor.hdlAst._structural import HdlComponentInst, HdlModuleDec
from hdlConvertor.hdlAst._typeDefs import HdlEnumDef, HdlClassDef
from hdlConvertor.to.basic_hdl_sim_model.stm import BasicHdlSimModelStm
from hdlConvertor.to.hdlUtils import Indent


DEFAULT_IMPORTS = """\
from pyMathBitPrecise.array3t import Array3t, Array3val
from pyMathBitPrecise.bits3t import Bits3t, Bits3val
from pyMathBitPrecise.enum3t import define_Enum3t

from pycocotb.basic_hdl_simulator.model import BasicRtlSimModel
from pycocotb.basic_hdl_simulator.model_utils import sensitivity, connectSimPort
from pycocotb.basic_hdl_simulator.proxy import BasicRtlSimProxy
from pycocotb.basic_hdl_simulator.sim_utils import sim_eval_cond
"""


def isOp(e: iHdlExpr):
    if isinstance(e, HdlCall):
        return True


def sensitivityByOp(op: HdlBuiltinFn):
    """
    get sensitivity type for operator
    """
    if op == HdlBuiltinFn.RISING:
        return (True, False)
    elif op == HdlBuiltinFn.FALLING:
        return (False, True)
    else:
        raise TypeError(op)


class ToBasicHdlSimModel(BasicHdlSimModelStm):
    """
    Convert hdlObject AST to BasicHdlSimModel (Python simulation model used by pycocotb simulator)

    :ivar ~.mod: actually processed module 
    """
    def __init__(self, out_stream):
        super(ToBasicHdlSimModel, self).__init__(out_stream)
        self.mod = None

    def print_doc(self, obj):
        return super(ToBasicHdlSimModel, self).print_doc(obj, "#")

    def print_type(self, t):
        """
        :type t: iHdlExpr
        """
        self.print_iHdlExpr(t)

    def print_HdlModuleDec(self, mod):
        """
        :type mod: HdlModuleDec
        """
        w = self.out.write
        assert mod.body is not None, mod
        self.mod = mod
        try:
            w(DEFAULT_IMPORTS)
            w("\n")

            extra_types = []
            components = []
            private_vars = []
            processes = []
            for o in mod.body.objs:
                if isinstance(o, (HdlClassDef, HdlEnumDef)):
                    extra_types.append(o)
                elif isinstance(o, HdlVariableDef):
                    private_vars.append(o)
                elif isinstance(o, HdlStmProcess):
                    processes.append(o)
                elif isinstance(o, HdlComponentInst):
                    components.append(o)
                else:
                    raise NotImplementedError(o)

            for c in components:
                w('if "%s" not in locals(): # support for all models in single file\n' % c.name)
                with Indent(self.out):
                    w('from .%s import %s' % (c.name, c.name))

            self.print_doc(mod)
            w("class ")
            w(mod.name)
            w("(BasicRtlSimModel):\n")
            assert not mod.params, "generic should be already resolved for this format"

            with Indent(self.out):
                for t in extra_types:
                    self.print_type_declr(t)

                w('def __init__(self, sim: "BasicRtlSimulator", name="')
                w(mod.name)
                w('"):\n')
                with Indent(self.out):
                    w('BasicRtlSimModel.__init__(self, sim, name=name)\n')
                    w('#ports\n')
                    for port in mod.ports:
                        self.print_HdlVariableDef(port)
                    w("# internal signals\n")
                    for v in private_vars:
                        self.print_HdlVariableDef(v)
                    w("# component instances\n")
                    for c in components:
                        w("self.")
                        w(c.name)
                        w(" = ")
                        w(c.name)
                        w('(sim, "')
                        w(c.name)
                        w('")\n')

                w("def _init_body(self):\n")
                with Indent(self.out):
                    for c in components:
                        for pm in c.port_map:
                            w("connectSimPort(self, self.")
                            w(c.name)
                            w(', "')
                            assert isinstance(pm, HdlCall) and\
                                pm.fn == HdlBuiltinFn.MAP_ASSOCIATION, pm
                            mod_port, connected_sig = pm.ops
                            assert isinstance(connected_sig, HdlName), connected_sig
                            self.print_iHdlExpr(connected_sig)
                            w('", "')
                            assert isinstance(mod_port, HdlName), mod_port
                            self.print_iHdlExpr(mod_port)
                            w('", ')
                            p = mod_port.obj
                            assert p is not None, (
                                "HdlName to module ports "
                                "shoudl have been discovered before")
                            d = p.direction
                            assert d in (HdlDirection.IN, HdlDirection.OUT), d
                            w(str(d == HdlDirection.IN))
                            w(')\n')

                    w('self._interfaces = (\n')
                    with Indent(self.out):
                        for p in chain(mod.ports, private_vars):
                            w("self.io.")
                            w(p.name)
                            w(',\n')
                    w(')\n')

                    w('self._processes = (\n')
                    with Indent(self.out):
                        for p in processes:
                            w("self.")
                            w(p.labels[0])
                            w(",\n")
                    w(")\n")
                    w('self._units = (')
                    with Indent(self.out):
                        for c in components:
                            w("self.")
                            w(c.name)
                            w(",\n")
                    w(")\n")

                    for proc in processes:
                        w("sensitivity(self.")
                        w(proc.labels[0])
                        w(', ')
                        for s in proc.sensitivity:
                            if isOp(s):
                                w("(")
                                w(str(sensitivityByOp(s.fn)))
                                w(", self.io.")
                                self.print_iHdlExpr(s.ops[0])
                                w(')')
                            else:
                                w("self.io.")
                                self.print_iHdlExpr(s)
                            w(", ")
                        w(")\n")
                        w("self._outputs[self.")
                        w(proc.labels[0])
                        w("] = (\n")
                        outputs = self.stm_outputs[proc]
                        with Indent(self.out):
                            for outp in outputs:
                                w("self.io.")
                                w(outp)
                                w(",\n")
                        w(")\n")
                    w("for u in self._units:\n")
                    w("    u._init_body()\n\n")
                for p in processes:
                    self.print_HdlStmProcess(p)
                    # extra line to separate a process functions
                    w("\n")
        finally:
            self.mod = None

    def print_main_obj(self, o):
        if isinstance(o, HdlModuleDec):
            self.print_HdlModuleDec(o)
        else:
            raise NotImplementedError(o)

    def print_HdlVariableDef(self, var):
        """
        :type var: HdlVariableDef
        """
        self.print_doc(var)
        w = self.out.write
        w("self.io.")
        w(var.name)
        w(' = BasicRtlSimProxy(sim, self, "')
        w(var.name)
        w('",\n')
        w("    ")
        self.print_type(var.type)
        w(", ")
        if var.value is None:
            w("None")
        else:
            w(var.value)
        w(")\n")

    def print_HdlContext(self, context, stm_outputs):
        """
        :type context: HdlContext
        :type stm_outputs: Dict[HdlStm, List[HdlName]]
        """
        self.stm_outputs = stm_outputs
        return super(ToBasicHdlSimModel, self).print_HdlContext(context)


if __name__ == "__main__":
    import os
    import sys
    from hdlConvertor.language import Language
    from hdlConvertor import HdlConvertor
    from hdlConvertor.translate.verilog_to_basic_hdl_sim_model import\
        verilog_to_basic_hdl_sim_model

    BASE_DIR = os.path.join(os.path.dirname(__file__), "..", "..", "..")
    TEST_DIR = os.path.join(BASE_DIR, 'tests', 'verilog')

    c = HdlConvertor()
    filenames = [os.path.join(TEST_DIR, "arbiter.v")]
    d = c.parse(filenames, Language.VERILOG, [], False, True)
    d, stm_outputs = verilog_to_basic_hdl_sim_model(d)
    tv = ToBasicHdlSimModel(sys.stdout)
    tv.print_HdlContext(d, stm_outputs)
