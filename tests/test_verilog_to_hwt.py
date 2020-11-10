import unittest

from hdlConvertorAst.language import Language
from tests.hdl_parse_tc import HdlParseTC, get_to_hdl_cls
from hdlConvertorAst.to.hwt import ToHwt
from hdlConvertorAst.translate.verilog_to_hwt import verilog_to_hwt


def _default_to_hdl(context, language, buff):
    if language != Language.VERILOG:
        raise NotImplementedError()
    context, name_scope = verilog_to_hwt(context)
    tv = ToHwt(buff)
    tv.visit_HdlContext(context)


class VerilogToHwtTC(HdlParseTC):

    def test_decoder_using_case(self):
        self.parseWithRef("decoder_using_case.v", Language.VERILOG,
                          ref_fname="decoder_using_case.py.txt",
                          to_hdl=_default_to_hdl)


if __name__ == "__main__":
    suite = unittest.TestSuite()
    #suite.addTest(VhdlConversionTC('test_package_constants'))
    suite.addTest(unittest.makeSuite(VerilogToHwtTC))

    runner = unittest.TextTestRunner(verbosity=3)
    runner.run(suite)