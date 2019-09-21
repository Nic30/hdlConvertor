# import sys
from itertools import chain
import os
import unittest

from hdlConvertor import HdlConvertor
from hdlConvertor.language import Language
from tests.file_utils import find_files, TestFilter, generate_test_method_name, \
    get_file_name
from tests.time_logging_test_runner import TimeLoggingTestRunner

YOSYS_ROOT = os.path.join(os.path.dirname(__file__), "yosys")

# use this file to run tests in incremental maner,
# the test which passed in previous build will not be executed again
#SUCESSFULL_TEST_FILTER_FILE = "tests_passed.yosys"
SUCESSFULL_TEST_FILTER_FILE = None


def get_yosys_test_config():
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

        yield verilog_file, lang, should_fail, defs


# https://stackoverflow.com/questions/32899/how-do-you-generate-dynamic-parameterized-unit-tests-in-python
class YosysTestsuiteMeta(type):

    def __new__(cls, name, bases, _dict):
        test_filter = TestFilter(SUCESSFULL_TEST_FILTER_FILE)

        def gen_test(sv_file, should_fail, verilog_version, defs):
            """
            :param defs: definitions for preprocessor
            """

            def test(self):
                debug = False
                c = HdlConvertor()
                c.preproc_macro_db.update(defs)
                incdirs = [] 
                # print(c.verilog_pp(sv_file, verilog_version, incdirs))
                try:
                    c.parse([sv_file, ], verilog_version, incdirs, debug=debug)
                except Exception:
                    if should_fail:
                        # [TODO] some expected erros in this test suite are not related to synatax
                        #        need to check maually if the error really means syntax error and
                        #        if this library is raising it correctly
                        pass
                    else:
                        raise
                test_filter.mark_test_as_passed(self)

            return test

        for file_name, lang, should_fail, defs in sorted(
                get_yosys_test_config(),
                key=lambda x: x[0]):
            fn = get_file_name(file_name)
            test_name = generate_test_method_name(fn, lang, _dict)

            if not test_filter.is_dissabled_test(test_name):
                _dict[test_name] = gen_test(file_name, should_fail, lang, defs)

        return type.__new__(cls, name, bases, _dict)


# https://www.oipapio.com/question-219175 , python2/3 compatible specification of metatype for class
YosysTestsuiteTC = YosysTestsuiteMeta('YosysTestsuiteTC', (unittest.TestCase,), {})

if __name__ == '__main__':
    # unittest.main(failfast=True)
    suite = unittest.TestSuite()

    # suite.addTest(YosysTestsuiteTC('test_SYSTEM_VERILOG_2009_gate2lut'))
    suite.addTest(unittest.makeSuite(YosysTestsuiteTC))

    runner = TimeLoggingTestRunner(verbosity=3)
    runner.run(suite)
