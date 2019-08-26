# import sys
import fnmatch
import os
import unittest

from hdlConvertor import HdlConvertor
from hdlConvertor.language import Language
from tests.time_logging_test_runner import TimeLoggingTestRunner

HDL_CONVERTOR_ROOT = os.path.join(os.path.dirname(__file__), "..")
IVTEST_ROOT = os.path.join(HDL_CONVERTOR_ROOT, "tests", "ivtest")

IV_VERILOG_VERSION_OPTS = [
    ("-g1995", Language.VERILOG_1995),
    ("-g2001", Language.VERILOG_2001),
    ("-g2001-noconfig", Language.VERILOG_2001_NOCONFIG),
    ("-g2005", Language.VERILOG_2005),
    ("-g2005-sv", Language.SYSTEM_VERILOG_2005),
    ("-g2009", Language.SYSTEM_VERILOG_2009),
    ("-g2012", Language.SYSTEM_VERILOG_2012),
    ("-g2017", Language.SYSTEM_VERILOG_2017),
]


def find_files(directory, pattern):
    for root, _, files in os.walk(directory):
        for basename in files:
            if fnmatch.fnmatch(basename, pattern):
                filename = os.path.join(root, basename)
                yield filename


def get_test_default_config():
    def_config = {}

    def parse_record(line):
        columns = line.split()
        name = columns[0]
        args = columns[1]
        for iv_ver, ver in IV_VERILOG_VERSION_OPTS:
            if iv_ver in args:
                def_config[name] = (ver, "CE" in args)
                break

    for file_name in find_files(IVTEST_ROOT, "regress-*.list"):
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
                    parse_record(line)
                    buff = ""
            if buff:
                parse_record(line)

    return def_config


def get_file_name(f):
    return os.path.splitext(os.path.basename(f))[0]


# https://stackoverflow.com/questions/32899/how-do-you-generate-dynamic-parameterized-unit-tests-in-python
class IcarusVerilogTestsuiteMeta(type):

    def __new__(cls, name, bases, _dict):

        def gen_test(sv_file, should_fail, verilog_version):

            def test(self):
                debug = False
                c = HdlConvertor()
                incdirs = []
                try:
                    c.parse([sv_file, ], verilog_version, incdirs, debug=debug)
                except:
                    if should_fail:
                        # [TODO] some expected erros in this test suite are not related to synatax
                        #        need to check maually if the error really means syntax error and
                        #        if this library is raising it correctly
                        pass
                    else:
                        raise
                    
            return test

        conf = get_test_default_config()
        for sv_file in find_files(IVTEST_ROOT, '*.v'):
            fn = get_file_name(sv_file)
            if fn in ["comp1000", "comp1001"]:
                # this files currently taking too loong
                continue
            if fn in ["pr1520314", "pr1695257"]:
                # will be fixed in antlr4.7.2+ cpp runtime
                # https://github.com/antlr/antlr4/issues/2550
                continue
            if fn in ["pr377", "contrib8.2"]:
                # non-ANSI specialities
                continue

            verilog_version, should_fail = conf.get(fn, (Language.VERILOG_2005, False))
            test_name = "test_%s" % fn
            t = gen_test(sv_file, should_fail, verilog_version)
            i = 1
            while test_name in _dict:
                test_name = "test_%d_%s" % (i, fn)
                i += 1
            _dict[test_name] = t 
        return type.__new__(cls, name, bases, _dict)


# https://www.oipapio.com/question-219175 , python2/3 compatible specification of metatype for class
IcarusVerilogTestsuiteTC = IcarusVerilogTestsuiteMeta('IcarusVerilogTestsuiteTC', (unittest.TestCase,), {})

if __name__ == '__main__':
    suite = unittest.TestSuite()

    # suite.addTest(IcarusVerilogTestsuiteTC('test_br_gh26'))
    # suite.addTest(IcarusVerilogTestsuiteTC('test_pr377'))
    suite.addTest(unittest.makeSuite(IcarusVerilogTestsuiteTC))

    runner = TimeLoggingTestRunner(verbosity=3)
    runner.run(suite)
