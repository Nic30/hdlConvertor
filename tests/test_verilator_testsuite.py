# import sys
import os
import re
import unittest

from hdlConvertor.language import Language
from tests.file_utils import find_files, get_file_name
from tests.time_logging_test_runner import TimeLoggingTestRunner
from tests.extern_test_utils import generate_external_testcase_class, \
    ExternTestSpec

VERILATOR_ROOT = os.path.join(os.path.dirname(__file__), "verilator")
VERILATOR_TEST_ROOT = os.path.join(VERILATOR_ROOT, "test_regress", "t")

# use this file to run tests in incremental maner,
# the test which passed in previous build will not be executed again
# SUCESSFULL_TEST_FILTER_FILE = "tests_passed.verilator"
SUCESSFULL_TEST_FILTER_FILE = None


def get_verilator_test_configs():
    RE_TOPFILENAME = re.compile('top_filename\("\s*([^"]+)"\s*\)', re.MULTILINE)
    for test_script_name in find_files(VERILATOR_TEST_ROOT, "*.pl"):
        do_ignore = False
        for ignored in ["t_flag_", "t_dist_", "t_vlcov_",
                        "t_verilated_all_oldest.pl", "bootstrap.pl",
                        "t_driver_random.pl",
                        "t_debug_",
                        ]:
            if ignored in test_script_name:
                do_ignore = True
                break
        if do_ignore:
            continue
        with open(test_script_name) as f:
            s = f.read()
        should_fail = "fails => 1" in s
        main_file = RE_TOPFILENAME.search(s)
        if main_file is not None:
            main_file = main_file.group(1)
            if "$Self->{obj_dir}" in main_file:
                continue
            assert main_file.startswith("t/") or main_file.startswith("t_"), main_file
            main_file = os.path.basename(main_file)
        else:
            verilog_file = test_script_name.replace(".pl", ".v")
            if os.path.exists(verilog_file):
                main_file = os.path.basename(verilog_file)
            else:
                verilog_file = test_script_name.replace(".pl", ".sv")
                if os.path.exists(verilog_file):
                    main_file = os.path.basename(verilog_file)
                else:
                    raise NotImplementedError(test_script_name)

        lang = Language.SYSTEM_VERILOG_2009
        fn = get_file_name(main_file)
        if fn in {
                # non std {} initializer
                "t_struct_init",
                # should fail but fail value not parsed in script correctly
                "t_var_bad_sv",
                "t_mem_multi_ref_bad",
                "t_langext_order",
                "t_inst_missing",
                # requires additional preproc definitions
                "t_tri_gate",
                "t_extend_class",
                "t_dpi_var",
                "t_dpi_sys",
                "t_dpi_display",
                "t_dpi_threads",
                "t_interface_down_gen",
                "t_gen_missing",
                # "t_sys_fread",
                # "t_preproc_undefineall",
                # "t_lint_unused",
                # "t_interface_down_gen",
                # "t_case_write1",
                # not a verilog files
                "t_preproc_persist",
                "t_preproc_noline",
                "t_preproc_kwd",
                "t_preproc_def09",
                "t_preproc",
                "t_pp_display",
                "t_pp_pragmas",
                "t_pipe_filter",
                # non std. primitive with assign
                "t_trace_primitive",
                # non std. numbers starting with _
                "t_stream",
                # = #100'b0
                "t_parse_delay",
                # non std.? parameters without the parenthesis?
                "t_param_no_parentheses",
                # non std. ordered and named port list mixed syntax 
                "t_interface_modportlist",
                # non std. missing return type of function
                "t_interface_modport_export",
                # non std. mpodport can be only in interface
                "t_interface_gen",
                # non std. case without items
                "t_case_wild",
                
                # /dev/null is not present under windows
                "t_lint_incabspath",
                }:
            should_fail = True
        if fn == "t_var_rsvd":
            lang = Language.SYSTEM_VERILOG_2005
        preproc_defs = {
            "TEST_OBJ_DIR": "obj/",
            "PREDEF_COMMAND_LINE": '$display("PREDEF_COMMAND_LINE");'
        }
        incdirs = [VERILATOR_TEST_ROOT, os.path.join(VERILATOR_ROOT, "include")]

        yield ExternTestSpec(os.path.join(VERILATOR_TEST_ROOT, main_file), lang, preproc_defs, incdirs, should_fail)


VerilatorTestsuiteTC = generate_external_testcase_class(
    'VerilatorTestsuiteTC',
    get_verilator_test_configs(),
    SUCESSFULL_TEST_FILTER_FILE)

if __name__ == '__main__':
    # unittest.main(failfast=True)
    suite = unittest.TestSuite()

    # suite.addTest(VerilatorTestsuiteTC('test_SYSTEM_VERILOG_2009_t_preproc_undefineall'))
    suite.addTest(unittest.makeSuite(VerilatorTestsuiteTC))

    runner = TimeLoggingTestRunner(verbosity=3)
    runner.run(suite)
