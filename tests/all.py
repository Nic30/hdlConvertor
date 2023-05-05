#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import sys
import unittest

from tests.test_basic_hdl_sim_model_from_verilog import BasicHdlSimModelFromVerilogTC
from tests.test_ghdl_testsuite import GhdlTestsuiteTCs
from tests.test_icarus_verilog_testsuite import IcarusVerilogTestsuiteTC
from tests.test_notebook import NotebookTC
from tests.test_sv2017_std_examples_parse import Sv2017StdExamplesParseTC
from tests.test_uvvm_testsuite import UVVMTestsuite
from tests.test_verilator_testsuite import VerilatorTestsuiteTC
from tests.test_verilog_conversion import VerilogConversionTC
from tests.test_verilog_preproc import VerilogPreprocTC
from tests.test_verilog_preproc_grammar import VerilogPreprocGrammarTC
from tests.test_verilog_preproc_include import VerilogPreprocIncludeTC
from tests.test_verilog_preproc_macro_db_api import VerilogPreprocMacroDbApiTC
from tests.test_verilog_to_hwt import VerilogToHwtTC
from tests.test_vhdl_conversion import VhdlConversionTC
from tests.test_vhdl_std_examples_parse import Vhdl2008StdExamplesParseTC
from tests.test_vunit_testsuite import VUnitTestsuiteTC
from tests.test_yosys_testsuite import YosysTestsuiteTC
from tests.time_logging_test_runner import TimeLoggingTestRunner


def main_test_suite():
    tcs = [
        VerilogPreprocGrammarTC,
        VerilogPreprocTC,
        VerilogPreprocIncludeTC,
        VerilogPreprocMacroDbApiTC,
        VerilogConversionTC,
        VhdlConversionTC,
        Sv2017StdExamplesParseTC,
        Vhdl2008StdExamplesParseTC,
        IcarusVerilogTestsuiteTC,
        VerilatorTestsuiteTC,
        YosysTestsuiteTC,
        VUnitTestsuiteTC,
        UVVMTestsuite,
        BasicHdlSimModelFromVerilogTC,
        VerilogToHwtTC,
    ] + GhdlTestsuiteTCs
    if os.name != 'nt':
        tcs.append(NotebookTC)
    for tc in tcs:
        tc._multiprocess_can_split_ = True
    loader = unittest.TestLoader()
    suite = unittest.TestSuite([loader.loadTestsFromTestCase(tc) for tc in tcs])
    # suite.addTest(VerilogPreprocTC("test_2012_p641"))
    # suite.addTest(VerilatorTestsuiteTC("test_SYSTEM_VERILOG_2009_t_math_cond_huge"))

    return suite


suite = main_test_suite()

if __name__ == "__main__":
    # import tracemalloc
    #
    # tracemalloc.start()
    runner = TimeLoggingTestRunner(verbosity=3)

    try:
        from concurrencytest import ConcurrentTestSuite, fork_for_tests
        useParallerlTest = True
    except ImportError:
        # concurrencytest is not installed, use regular test runner
        useParallerlTest = False
        sys.stderr.write("[Warning]: concurrencytest not installed running test in single thread\n")
    # useParallerlTest = False

    if useParallerlTest:
        # Run same tests across 4 processes
        concurrent_suite = ConcurrentTestSuite(suite, fork_for_tests())
        res = runner.run(concurrent_suite)
    else:
        res = runner.run(suite)

    # snapshot = tracemalloc.take_snapshot()
    # top_stats = snapshot.statistics('lineno')
    #
    # for stat in top_stats:
    #    if "hdlConvertor" in repr(stat):
    #        print(stat)
    if not res.wasSuccessful():
        sys.exit(1)
