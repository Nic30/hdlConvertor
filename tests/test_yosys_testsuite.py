# import sys
from itertools import chain
import os
import unittest

from hdlConvertor.language import Language
from tests.file_utils import find_files, get_file_name
from tests.time_logging_test_runner import TimeLoggingTestRunner
from tests.extern_test_utils import generate_external_testcase_class, \
    ExternTestSpec

YOSYS_ROOT = os.path.join(os.path.dirname(__file__), "yosys")

# use this file to run tests in incremental maner,
# the test which passed in previous build will not be executed again
# SUCESSFULL_TEST_FILTER_FILE = "tests_passed.yosys"
SUCESSFULL_TEST_FILTER_FILE = None


def get_yosys_test_configs():
    assert os.path.exists(YOSYS_ROOT) and len(os.listdir(YOSYS_ROOT)) > 0, "Yosys repo not downloaded correctly"
    for verilog_file in chain(find_files(YOSYS_ROOT, "*.v"), find_files(YOSYS_ROOT, "*.sv")):
        fn = get_file_name(verilog_file)
        should_fail = False
        lang = Language.SYSTEM_VERILOG_2009
        defs = {}
        if fn in [
                # c defined macros
                "xilinx_srl",
                "tff_extract",
                "shregmap",
                "cells_latch",
                "abc_map",
                "cells_latch",
                "cells_map",
                
                # not a verilog file
                "xcu_cells_xtra",
                "xc7_cells_xtra",
                "xc6v_cells_xtra",
                "xc6s_cells_xtra",
                "sumprod",
                "pack1",
                "pack1p",
                "pack2",
                "pack2p",
                "pack3p",
                "pack3",
                "opt_expr_cmp",
                "map_and",
                "map_xor",
                "map_or",
                "map_not",
                "map_mux",
                "map_cmp",
                "flowp",
                "flow",
                "constmsk_testmap",
                
                # depends on generated file
                "xc7_brams_map",
                "xc6s_brams_map",
                "brams_map",
                # (2**i)'b0
                "techmap",
                
                # error example
                "syntax_err11",
                "syntax_err08",
                "syntax_err07",
                "small",
                
                # incorrect escaped id
                "svinterface_at_top_wrapper",
                
                # non std? +/- after specify_input_terminal_descriptor
                "specify",
                
                # non std? extra , in module port list
                "opt_share_add_sub",
                "opt_share_cat",
                "opt_share_cat_multiuser",
                "mul",
                "dffs",
                "memory",

                # non std ID'd1
                "mulshift_map",
                
                # non std binary ~&/|
                "logic",
                
                # non std based digit starting with _
                "gate2lut",
                "cmp2lut",
                ]:
            should_fail = True
        if fn in ["test_dsp_model", "eagle_bb", "drams_map"]:
            lang = Language.VERILOG_2005
        if fn == "mux_map":
            defs["MIN_MUX_INPUTS"] = "32"
        if fn in ["gate2lut", "cmp2lut"]:
            defs["LUT_WIDTH"] = "8"
        if fn in ["code_verilog_tutorial_fsm_full_tb", "code_verilog_tutorial_first_counter_tb", "code_verilog_tutorial_counter_tb",
                  "code_hdl_models_arbiter_tb", ]:
            defs["outfile"] = "tmp/outfile"

        inc_dirs = []
        yield ExternTestSpec(verilog_file, lang, defs, inc_dirs, should_fail)


YosysTestsuiteTC = generate_external_testcase_class(
    'YosysTestsuiteTC',
    get_yosys_test_configs(),
    SUCESSFULL_TEST_FILTER_FILE)

if __name__ == '__main__':
    # unittest.main(failfast=True)
    suite = unittest.TestSuite()

    # suite.addTest(YosysTestsuiteTC('test_SYSTEM_VERILOG_2009_gate2lut'))
    suite.addTest(unittest.makeSuite(YosysTestsuiteTC))

    runner = TimeLoggingTestRunner(verbosity=3)
    runner.run(suite)
