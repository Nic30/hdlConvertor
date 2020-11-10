#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import unittest
from tests.hdl_parse_tc import HdlParseTC, VERILOG
from hdlConvertorAst.to.basic_hdl_sim_model._main import ToBasicHdlSimModel
from hdlConvertorAst.translate.verilog_to_basic_hdl_sim_model import\
    verilog_to_basic_hdl_sim_model


def _to_basic_hdl_sim_model(context, language, buff):
    if language != VERILOG:
        raise NotImplementedError()
    context, stm_outputs, _ = verilog_to_basic_hdl_sim_model(context)
    tv = ToBasicHdlSimModel(buff)
    tv.visit_HdlContext(context, stm_outputs)


class BasicHdlSimModelFromVerilogTC(HdlParseTC):

    def testSimpleSubunit(self):
        self.parseWithRef("simple_subunit.v", VERILOG,
                          input_dir="verilog",
                          output_dir="basic_hdl_sim_model",
                          ref_fname="simple_subunit.py.txt",
                          to_hdl=_to_basic_hdl_sim_model)


if __name__ == '__main__':
    unittest.main()