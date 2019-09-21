# import sys
from itertools import chain
import os
import unittest

from hdlConvertor import HdlConvertor
from hdlConvertor.language import Language
from tests.time_logging_test_runner import TimeLoggingTestRunner
from tests.file_utils import find_files, get_file_name, \
    generate_test_method_name, TestFilter

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


def get_test_configs(default_verilog_version):
    # (filename, version, should_fail)
    tests = []

    def parse_record(line, dir_name):
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
        std = default_verilog_version
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

        tests.append((f, std, should_fail))

    for file_name in chain(find_files(IVTEST_ROOT, "regress-*.list"),
                           find_files(IVTEST_ROOT, "*_regress.list")):
        if file_name.endswith("regress-vams.list"):
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
                    parse_record(line, dir_name)
                    buff = ""
            if buff:
                parse_record(line, dir_name)

    return tests


# https://stackoverflow.com/questions/32899/how-do-you-generate-dynamic-parameterized-unit-tests-in-python
class IcarusVerilogTestsuiteMeta(type):

    def __new__(cls, name, bases, _dict):
        test_filter = TestFilter(SUCESSFULL_TEST_FILTER_FILE)

        def gen_test(sv_file, should_fail, verilog_version):

            def test(self):
                debug = False
                c = HdlConvertor()
                incdirs = [IVTEST_ROOT, ]
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

        for sv_file, verilog_version, should_fail in get_test_configs(Language.VERILOG_2005):
            fn = get_file_name(sv_file)
            # if fn in ["comp1000", "comp1001"]:
            #     # this files currently taking too loong
            #     continue
            # if fn in ["pr377", "contrib8.2"]:
            #     # non-ANSI specialities
            #     continue
            if fn in [  # '``'
                      "pr622",
                      "pr639",
                      "pr1741212",
                      "pr1912112",
                      "pr1925360",
                      # "br979", "br_gh105a", "br_gh105b",  "pr622", , 
                      # "macro_str_esc", "macro_with_args", "mangle",
                      # ``celldefine
                      "macro_str_esc",
                      # comment between macro and its args
                      "macro_with_args",
                      # '`' in string
                      # "localparam_type2", "parameter_type2", "sv_macro2", "clog2", "pr1925360", "pr1960548",
                      # `elseif withou args, `else multipletimes
                      "elsif_test",
                      # `unconnected_drive
                      "uncon_drive",
                      ]:
                # unfinished preproc
                continue
            if fn in ["array_packed_write_read", "func_init_var3", "task_init_var3"]:
                # ?? antlr parser works under java, but fails under c++
                continue
            if fn in ["br988"]:
                # block in block in generate: not in standard but it seems to be supported by Synopsys, Cadence and Aldec
                continue
            if fn in ["pr1877743", "specify_01"]:
                # problems with specify block
                continue
            if fn in ["pr3194155", "z1", "z2"]:
                # delay in module instantiation
                continue
            if fn in ["specparam2"]:
                # problems in specparam
                continue
            if fn in ["sv_unit2a", "sv_unit3a"]:
                # problem with module
                continue
            if fn in ["sv_unit4a"]:
                # problem with const in class property
                continue
            if fn in ["vhdl_xor104_stdlogic"]:
                # problems with int unsigned
                continue
            if fn in ["wiresl2"]:
                # problems with wstring_convert::from_bytes, non utf-8 byte dump in file
                continue
            if fn in ["display_bug"]:
                # int as bit vector size
                continue

            if fn in [
                    # checked by emming of errors instead of return code
                    "br_gh72a", "br_gh72b", "pr1758122",
                    # marked as to fail even in comments instead of file, but should pass in icarus tests?
                    "sf1289",
                    # the files which are used indirectly from test and this does not have own test record
                    # and are not marked to fail
                    "sv_timeunit_prec_fail1a",
                    "sv_timeunit_prec_fail1b",
                    "sv_timeunit_prec_fail1c",
                    "sv_timeunit_prec_fail1d",
                    "sv_timeunit_prec_fail1e",
                    "sv_timeunit_prec_fail2a",
                    "sv_timeunit_prec_fail2b",
                    "sv_timeunit_prec_fail2c",

                    # non-std binary ~&, ~| which does not exitst in std.
                    "binary_nand", "binary_nor",
                    "blif01b", "blif01b_tb",
                    "blif02b", "blif02b_tb",
                    # non-std "" ports
                    "pr1716276",
                    # non-std "" args
                    "pr1787423",
                    # non-std pulldown/up with multiple params
                    "pr1787423b",
                    "pr1787423b_std",
                    "pr1787423b-v0.9",
                    "pr2834340",
                    "pr2834340b",
                    # non-std macro in include
                    "pr3012758",
                    # non standard `suppress_faults
                    "pr1467825",
                    # missing __ICARUS__ define
                    "pr3539372",
                    # non-std `protect `endprotect
                    "pr478",
                    # non-std "" in concat 
                    "pr904",
                    # non-std scaled real
                    "scaled_real",
                    # non-std $attribute
                    "sqrt",
                    # missing macro defs
                    "sv_unit1a",
                    # missng constants.vams
                    "test_va_math",
                    "test_vams_math",
                    # usage of undefined symbol
                    "undef",
                    # non-std from/exclude
                    "value_range1",
                    "value_range2",

                    # non-std req/wire with type icarus extension
                    "bool1",
                    "br974c",
                    "compare_bool_reg",
                    "constfunc8",
                    "pr1861212a",
                    "pr1861212c",
                    "pr1861212d",
                    "real8",
                    "size_cast2",
                    "struct_packed_array",
                    "struct_packed_array2",
                    "sv-2val-nets",
                    "enum_ports",
                    # non-std combination of unsigned, wire and bit vector size spec
                    "vhdl_xor104_stdlogic",

                    # analog extension which is currently not supported
                    "analog1", "analog2"
                    ]:
                should_fail = True

            if fn in ["fileline", "fileline2", ]:  # missing `__FILE__ (wrong standard specified)
                verilog_version = Language.SYSTEM_VERILOG_2009

            test_name = generate_test_method_name(fn, verilog_version, _dict)
            if not test_filter.is_dissabled_test(test_name):
                _dict[test_name] = gen_test(sv_file, should_fail, verilog_version)

        return type.__new__(cls, name, bases, _dict)


# https://www.oipapio.com/question-219175 , python2/3 compatible specification of metatype for class
IcarusVerilogTestsuiteTC = IcarusVerilogTestsuiteMeta('IcarusVerilogTestsuiteTC', (unittest.TestCase,), {})

if __name__ == '__main__':
    # unittest.main(failfast=True)

    suite = unittest.TestSuite()

    # suite.addTest(IcarusVerilogTestsuiteTC('test_br_gh26'))
    # suite.addTest(IcarusVerilogTestsuiteTC('test_VERILOG_2005_logp2'))
    suite.addTest(unittest.makeSuite(IcarusVerilogTestsuiteTC))

    runner = TimeLoggingTestRunner(verbosity=3)
    runner.run(suite)
