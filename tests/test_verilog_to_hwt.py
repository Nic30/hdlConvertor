#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import unittest

from hdlConvertorAst.language import Language
from hdlConvertorAst.to.hwt import ToHwt
from hdlConvertorAst.translate.verilog_to_hwt import verilog_to_hwt
from tests.hdl_parse_tc import HdlParseTC


def _default_to_hdl(context, language, buff):
    if language != Language.VERILOG:
        raise NotImplementedError()
    context, name_scope = verilog_to_hwt(context)
    tv = ToHwt(buff)
    tv.visit_HdlContext(context)


class VerilogToHwtTC(HdlParseTC):

    def parseWithRef(self, fname,
                     language=Language.VERILOG,
                     input_dir=None, output_dir="hwt",
                     ref_fname=None, to_hdl=_default_to_hdl):
        if ref_fname is None:
            ref_fname = os.path.basename(fname).replace(".v", ".py.txt")
        return HdlParseTC.parseWithRef(self, fname, language,
                                       input_dir=input_dir, output_dir=output_dir,
                                       ref_fname=ref_fname, to_hdl=to_hdl)

    def test_decoder_using_case(self):
        self.parseWithRef("decoder_using_case.v")

    # def test_dsp48e1(self):
    #     self.parseWithRef("dsp48e1.v")

    # def test_MMCME2_ADV(self):
    #     self.parseWithRef("MMCME2_ADV.v")

    def test_uart(self):
        self.parseWithRef("uart.v")


if __name__ == "__main__":
    testLoader = unittest.TestLoader()
    # suite = unittest.TestSuite([VerilogToHwtTC("test_MMCME2_ADV")])
    suite = testLoader.loadTestsFromTestCase(VerilogToHwtTC)

    runner = unittest.TextTestRunner(verbosity=3)
    runner.run(suite)
