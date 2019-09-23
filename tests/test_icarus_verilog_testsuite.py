# import sys
from copy import copy
from itertools import chain
import os
import unittest

from hdlConvertor.language import Language
from tests.extern_test_utils import ExternTestSpec, \
    generate_external_testcase_class
from tests.file_utils import find_files
from tests.time_logging_test_runner import TimeLoggingTestRunner


IVTEST_ROOT = os.path.join(os.path.dirname(__file__), "ivtest")

# use this file to run tests in incremental maner,
# the test which passed in previous build will not be executed again
# SUCESSFULL_TEST_FILTER_FILE = "tests_passed.ivtest"
SUCESSFULL_TEST_FILTER_FILE = None

IV_VERILOG_VERSION_OPTS = [
    ("-g1995", Language.VERILOG_1995),
    ("-g2001-noconfig", Language.VERILOG_2001_NOCONFIG),
    ("-g2001", Language.VERILOG_2001),
    ("-g2005-sv", Language.SYSTEM_VERILOG_2005),
    ("-g2005", Language.VERILOG_2005),
    ("-g2009", Language.SYSTEM_VERILOG_2009),
    ("-g2012", Language.SYSTEM_VERILOG_2012),
    ("-g2017", Language.SYSTEM_VERILOG_2017),
]

ICARUS_DEFAULT_PREPROC_DEFS = {"__ICARUS__": "1"}
ICARUS_DEFAULT_INC_DIRS = [IVTEST_ROOT, ]


def parse_verilator_record(line, dir_name):
    std = Language.VERILOG_2005
    preproc_defs = copy(ICARUS_DEFAULT_PREPROC_DEFS)
    inc_dirs = copy(ICARUS_DEFAULT_INC_DIRS)
    columns = line.split()

    name = columns[0]
    name_fix = {
        "br_ml201801012a": "br_ml20181012a",
        "br_ml201801012b": "br_ml20181012b",
        "br_ml201801012c": "br_ml20181012c",
        "br_ml201801012d": "br_ml20181012d",
        "struct_packe_write_read": "struct_packed_write_read",
        "struct_packe_write_read2": "struct_packed_write_read2",
        "sv_string_index": "string_index",
        "sv_timeunit_prec": "sv_timeunit_prec1",
        "sv_timeunit_prec_fail": "sv_timeunit_prec_fail1",
    }
    name = name_fix.get(name, name)
    args = columns[1]
    not_implemented = "NI" in args
    should_fail = "CE" in args or not_implemented

    if ":" in name or name in {"sv_casting"}:
        return

    for iv_ver, ver in IV_VERILOG_VERSION_OPTS:
        if iv_ver in args:
            std = ver
            break

    f = os.path.join(IVTEST_ROOT, dir_name, name + ".v")
    if not os.path.exists(f):
        f = os.path.join(IVTEST_ROOT, columns[2], name + ".v")
    assert os.path.exists(f), f
    # if fn in ["comp1000", "comp1001"]:
    #     # this files currently taking too loong
    #     continue
    # if fn in ["pr377", "contrib8.2"]:
    #     # non-ANSI specialities
    #     continue
    if name in [  # '``'
             # "pr622",
             # "pr639",
             "pr1741212",
             # "pr1912112",
             # "pr1925360",
             # # "br979", "br_gh105a", "br_gh105b",  "pr622", , 
             # # "macro_str_esc", "macro_with_args", "mangle",
             # # ``celldefine
             # "macro_str_esc",
             # # comment between macro and its args
             # "macro_with_args",
             # # '`' in string
             # # "localparam_type2", "parameter_type2", "sv_macro2", "clog2", "pr1925360", "pr1960548",
             # `elseif withou args, `else multipletimes
             "elsif_test",
              ]:
        # unfinished preproc
        return
    # if name in ["array_packed_write_read", "func_init_var3", "task_init_var3"]:
    #    # ?? antlr parser works under java, but fails under c++
    #    return
    # if name in ["br988"]:
    #    # block in block in generate: not in standard but it seems to be supported by Synopsys, Cadence and Aldec
    #    return
    if name in ["pr1877743", "specify_01"]:
        # problems with specify block
        # from std it seems that full path spec should have *> instead of =>, maybe it is bug in std
        return
    if name in ["pr3194155", "z1", "z2"]:
        # delay in module instantiation
        return
    # if fn in ["specparam2"]:
    #    # problems in specparam
    #    return
    # if fn in ["sv_unit2a", "sv_unit3a"]:
    #    # problem with module
    #    return
    # if fn in ["sv_unit4a"]:
    #    # problem with const in class property
    #    return
    # if fn in ["vhdl_xor104_stdlogic"]:
    #    # problems with int unsigned
    #    return
    if name in ["wiresl2"]:
        # problems with wstring_convert::from_bytes, non utf-8 byte dump in file
        return
    # if name in ["display_bug"]:
    #    # int as bit vector size
    #    return
    if name == "uncon_drive":
        # `unconnected_drive
        return
    if name in [
            # checked by emming of errors instead of return code
            "br_gh72a", "br_gh72b", "pr1758122",
            # marked as to fail even in comments instead of file, but should pass in icarus tests?
            "sf1289",

            # # non-std binary ~&, ~| which does not exitst in std.
            "binary_nand",
            "binary_nor",
            # "blif01b", "blif01b_tb",
            # "blif02b", "blif02b_tb",
            # non-std "" parameters
            "pr1716276",
            # non-std pulldown/up with multiple params
            "pr1787423",
            "pr1787423b",
            "pr1787423b_std",
            "pr1787423b-v0.9",
            "pr2834340",
            "pr2834340b",
            # # non-std macro in include
            # "pr3012758",
            # non standard `suppress_faults
            "pr1467825",
            # # missing __ICARUS__ define
            # "pr3539372",
            # non-std `protect `endprotect
            "pr478",
            # # non-std "" in concat 
            # "pr904",
            # # non-std scaled real
            # "scaled_real",
            # # non-std $attribute
            # "sqrt",
            # # missing macro defs
            # "sv_unit1a",
            # # missng constants.vams
            # "test_va_math",
            # "test_vams_math",
            # usage of undefined symbol
            "undef",
            # # non-std from/exclude
            # "value_range1",
            # "value_range2",
            #
            # # non-std req/wire with type icarus extension
            # "bool1",
            "br974c",
            # "compare_bool_reg",
            # "constfunc8",
            "pr1861212a",
            # "pr1861212c",
            # "pr1861212d",
            # "real8",
            "size_cast2",
            "struct_packed_array",
            "struct_packed_array2",
            "sv-2val-nets",
            "enum_ports",
            # # non-std combination of unsigned, wire and bit vector size spec
            # "vhdl_xor104_stdlogic",
            ]:
        should_fail = True

    if name == "pr3012758":
        std = Language.SYSTEM_VERILOG_2005
    return ExternTestSpec(f, std, preproc_defs, inc_dirs, should_fail)


def get_icarus_test_configs():
    tests = []

    for file_name in chain(find_files(IVTEST_ROOT, "regress-*.list"),
                           find_files(IVTEST_ROOT, "*_regress.list")):
        if os.path.basename(file_name) in ["regress-vams.list",
                                           "regress-ivl1.list",
                                           "regress-ivl2.list"]:
            continue
        
        if file_name.endswith("vpi_regress.list"):
            dir_name = "vpi"
        else:
            dir_name = "ivltests"

        with open(file_name) as f:
            buff = ""
            for line in f:
                line = line.split("#")[0]
                line = line.strip()
                if not line:
                    continue
                line = buff + line
                if line[-1] == "\\":
                    line = line[:-1]
                    buff = line
                    continue
                else:
                    tr = parse_verilator_record(line, dir_name)
                    if tr is not None:
                        tests.append(tr)
                    buff = ""
            if buff:
                tr = parse_verilator_record(line, dir_name)
                if tr is not None:
                        tests.append(tr)

    for fn in ["fileline", "fileline2", ]:
        # defined in icarus extensions with older std. with missing `__FILE__
        std = Language.SYSTEM_VERILOG_2009
        f = os.path.join(IVTEST_ROOT, "ivltests", fn + ".v")
        tests.append(ExternTestSpec(f, std, copy(ICARUS_DEFAULT_PREPROC_DEFS), copy(ICARUS_DEFAULT_INC_DIRS), False))

    return tests


IcarusVerilogTestsuiteTC = generate_external_testcase_class(
    'IcarusVerilogTestsuiteTC',
    get_icarus_test_configs(),
    SUCESSFULL_TEST_FILTER_FILE)


if __name__ == '__main__':
    # unittest.main(failfast=True)

    suite = unittest.TestSuite()

    # suite.addTest(IcarusVerilogTestsuiteTC('test_br_gh26'))
    # suite.addTest(IcarusVerilogTestsuiteTC('test_VERILOG_2005_logp2'))
    suite.addTest(unittest.makeSuite(IcarusVerilogTestsuiteTC))

    runner = TimeLoggingTestRunner(verbosity=3)
    runner.run(suite)
