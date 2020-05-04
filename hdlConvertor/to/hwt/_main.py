from hdlConvertor.hdlAst import HdlIdDef, iHdlExpr, HdlOp, HdlOpType,\
    HdlDirection, HdlValueId, HdlStmProcess, HdlCompInst, HdlModuleDec,\
    HdlEnumDef, HdlClassDef
from hdlConvertor.to.hdlUtils import Indent, iter_with_last
from hdlConvertor.to.hwt.stm import ToHwtStm
from hdlConvertor.to.basic_hdl_sim_model._main import ToBasicHdlSimModel
from hdlConvertor.to.common import ToHdlCommon
from hdlConvertor.hdlAst._statements import ALL_STATEMENT_CLASSES


DEFAULT_IMPORTS = """\
from hwt.code import power, If, Switch, Concat
from hwt.hdl.types.array import HArray
from hwt.hdl.types.bits import Bits
from hwt.hdl.types.defs import INT, SLICE
from hwt.hdl.types.enum import HEnum
from hwt.interfaces.std import Signal
from hwt.synthesizer.param import Param
from hwt.synthesizer.unit import Unit
"""


class ToHwt(ToHwtStm):
    """
    Convert hdlObject AST to BasicHdlSimModel
    (Python simulation model used by pycocotb simulator)

    :ivar _is_param: flag which specifies if the current HdlIdDef is a param/generic
    :ivar _is_port: flag which specifies if the current HdlIdDef is a port
    """
    ALL_STATEMENT_CLASSES = ALL_STATEMENT_CLASSES

    def __init__(self, out_stream):
        ToHdlCommon.__init__(self, out_stream)
        self.module_path_prefix = None
        self.add_imports = True
        self._is_port = False
        self._is_param = False

    def visit_doc(self, obj):
        return super(ToHwt, self).visit_doc(obj, "#")

    def visit_HdlModuleDef(self, mod_def):
        """
        :type mod_def: HdlModuleDef
        """
        mod_dec = mod_def.dec 
        assert mod_dec is not None, mod_def
        w = self.out.write
        w(DEFAULT_IMPORTS)
        w("\n")

        types, variables, processes, components = \
            ToBasicHdlSimModel.split_HdlModuleDefObjs(self, mod_def.objs)

        self.visit_doc(mod_dec)
        ToBasicHdlSimModel.visit_component_imports(self, components)

        w("class ")
        w(mod_dec.name)
        w("(Unit):\n")
        port_params_comp_names = []
        with Indent(self.out):
            if mod_dec.params:
                w('def _config(self):\n')
                with Indent(self.out):
                    try:
                        self._is_param = True
                        for p in mod_dec.params:
                            self.visit_HdlIdDef(p)
                            port_params_comp_names.append(p.name)
                    finally:
                        self._is_param = False

            for t in types:
                self.visit_type_declr(t)

            w('def _declr(self):\n')
            with Indent(self.out):
                w('# ports\n')
                try:
                    self._is_port = True
                    for p in mod_dec.ports:
                        self.visit_HdlIdDef(p)
                        port_params_comp_names.append(p.name)
                finally:
                    self._is_port = False

                w("# component instances\n")
                for c in components:
                    w("self.")
                    w(c.name.val)
                    w(" = ")
                    w(c.module_name.val)
                    w('()\n')
                    port_params_comp_names.append(c.name.val)

            w("def _impl(self):\n")
            with Indent(self.out):
                w("# internal signals\n")
                if port_params_comp_names:
                    # ports and params to locals
                    for last, name in iter_with_last(port_params_comp_names):
                        w(name)
                        if not last:
                            w(", ")
                    w(" = \\\n")
                    for last, name in iter_with_last(port_params_comp_names):
                        w("self.")
                        w(name)
                        if not last:
                            w(", ")
                    w("\n")
                for v in variables:
                    self.visit_HdlIdDef(v)

                for c in components:
                    for pm in c.port_map:
                        w("connectSimPort(self, self.")
                        w(c.name.val)
                        w(', "')
                        assert isinstance(pm, HdlOp) and\
                            pm.fn == HdlOpType.MAP_ASSOCIATION, pm
                        mod_port, connected_sig = pm.ops
                        assert isinstance(
                            connected_sig, HdlValueId), connected_sig
                        self.visit_iHdlExpr(connected_sig)
                        w('", "')
                        assert isinstance(mod_port, HdlValueId), mod_port
                        self.visit_iHdlExpr(mod_port)
                        w('", ')
                        p = mod_port.obj
                        assert p is not None, (
                            "HdlValueId to module ports "
                            "shoudl have been discovered before")
                        d = p.direction
                        assert d in (HdlDirection.IN, HdlDirection.OUT), d
                        w(str(d == HdlDirection.IN))
                        w(')\n')

                for p in processes:
                    self.visit_iHdlStatement(p)
                    # extra line to separate a process functions
                    w("\n")

    def visit_HdlIdDef(self, var):
        """
        :type var: HdlIdDef
        """
        self.visit_doc(var)
        w = self.out.write
        if self._is_port or self._is_param:
            w("self.")
        w(var.name)
        if self._is_port:
            w(" = Signal(")
            self.visit_type(var.type)
            w(")")
            if var.direction == HdlDirection.OUT:
                w("._m()\n")
            else:
                w("\n")
                assert var.direction == HdlDirection.IN, var.direction
        elif self._is_param:
            raise NotImplementedError()
        else:
            # body signal
            w(' = self._sig(')
            with Indent(self.out):
                w('"')
                w(var.name)
                w('", ')
                self.visit_type(var.type)
            if var.value is None:
                w(")\n")
            else:
                w(", def_val=")
                self.visit_iHdlExpr(var.value)
                w(")\n")


if __name__ == "__main__":
    import os
    import sys
    from hdlConvertor.language import Language
    from hdlConvertor import HdlConvertor
    from hdlConvertor.translate.verilog_to_hwt import\
        verilog_to_hwt

    BASE_DIR = os.path.join(os.path.dirname(__file__), "..", "..", "..")
    TEST_DIR = os.path.join(BASE_DIR, 'tests', 'verilog')

    c = HdlConvertor()
    filenames = [os.path.join(TEST_DIR, "arbiter.v")]
    d = c.parse(filenames, Language.VERILOG, [], False, True)
    d, name_scope = verilog_to_hwt(d)
    tv = ToHwt(sys.stdout)
    tv.visit_HdlContext(d)
