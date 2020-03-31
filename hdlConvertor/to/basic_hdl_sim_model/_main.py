from itertools import chain

from hdlConvertor.hdlAst import HdlVariableDef, iHdlExpr, HdlCall, HdlBuiltinFn,\
    HdlDirection, HdlName, HdlStmProcess, HdlComponentInst, HdlModuleDec,\
    HdlEnumDef, HdlClassDef
from hdlConvertor.to.basic_hdl_sim_model.stm import BasicHdlSimModelStm
from hdlConvertor.to.hdlUtils import Indent, iter_with_last
from hdlConvertor.to.basic_hdl_sim_model.utils import sensitivityByOp


DEFAULT_IMPORTS = """\
from pyMathBitPrecise.array3t import Array3t, Array3val
from pyMathBitPrecise.bits3t import Bits3t, Bits3val
from pyMathBitPrecise.enum3t import define_Enum3t

from pycocotb.basic_hdl_simulator.model import BasicRtlSimModel
from pycocotb.basic_hdl_simulator.model_utils import sensitivity, connectSimPort
from pycocotb.basic_hdl_simulator.proxy import BasicRtlSimProxy
from pycocotb.basic_hdl_simulator.sim_utils import sim_eval_cond
"""


class ToBasicHdlSimModel(BasicHdlSimModelStm):
    """
    Convert hdlObject AST to BasicHdlSimModel
 (Python simulation model used by pycocotb simulator)
    """

    def visit_doc(self, obj):
        return super(ToBasicHdlSimModel, self).visit_doc(obj, "#")

    def visit_HdlModuleDec(self, mod):
        """
        :type mod: HdlModuleDec
        """
        w = self.out.write
        assert mod.body is not None, mod
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
            w('if "%s" not in locals(): # support for all models in single file\n' %
              c.module_name)
            with Indent(self.out):
                w('from .%s import %s\n' % (c.module_name, c.module_name))

        self.visit_doc(mod)
        w("class ")
        w(mod.name)
        w("(BasicRtlSimModel):\n")
        assert not mod.params, "generic should be already resolved for this format"

        with Indent(self.out):
            for t in extra_types:
                self.visit_type_declr(t)

            w('def __init__(self, sim: "BasicRtlSimulator", name="')
            w(mod.name)
            w('"):\n')
            with Indent(self.out):
                w('BasicRtlSimModel.__init__(self, sim, name=name)\n')
                w('# ports\n')
                for port in mod.ports:
                    self.visit_HdlVariableDef(port)
                w("# internal signals\n")
                for v in private_vars:
                    self.visit_HdlVariableDef(v)
                w("# component instances\n")
                for c in components:
                    w("self.")
                    w(c.name)
                    w(" = ")
                    w(c.module_name)
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
                        assert isinstance(
                            connected_sig, HdlName), connected_sig
                        self.visit_iHdlExpr(connected_sig)
                        w('", "')
                        assert isinstance(mod_port, HdlName), mod_port
                        self.visit_iHdlExpr(mod_port)
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
                    for last, s in iter_with_last(proc.sensitivity):
                        if isinstance(s, HdlCall):
                            w("(")
                            w(str(sensitivityByOp(s.fn)))
                            w(", self.io.")
                            self.visit_iHdlExpr(s.ops[0])
                            w(')')
                        else:
                            w("self.io.")
                            self.visit_iHdlExpr(s)
                        if not last:
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
                self.visit_HdlStmProcess(p)
                # extra line to separate a process functions
                w("\n")

    def visit_HdlVariableDef(self, var):
        """
        :type var: HdlVariableDef
        """
        self.visit_doc(var)
        w = self.out.write
        w("self.io.")
        w(var.name)
        w(' = BasicRtlSimProxy(\n')
        with Indent(self.out):
            w('sim, self, "')
            w(var.name)
            w('",\n')
            self.visit_type(var.type)
            w(", None")
        if var.value is None:
            w(")\n")
        else:
            w(".init_def_val(")
            w(var.value)
            w("\n")

    def visit_HdlContext(self, context, stm_outputs):
        """
        :type context: HdlContext
        :type stm_outputs: Dict[HdlStm, List[HdlName]]
        """
        self.stm_outputs = stm_outputs
        return super(ToBasicHdlSimModel, self).visit_HdlContext(context)


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
    d, stm_outputs, ns = verilog_to_basic_hdl_sim_model(d)
    tv = ToBasicHdlSimModel(sys.stdout)
    tv.visit_HdlContext(d, stm_outputs)
