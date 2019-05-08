import sys
import traceback
from os import path
from pprint import pprint
import unittest

try:
    from .use_build_version import *
except ImportError:
    from use_build_version import *

from hdlConvertor import verilog_pp
from hdlConvertor import ParseException
from hdlConvertor.language import Language
SV = Language.SYSTEM_VERILOG_2012.value


def _test_run(test_file, golden_file):
    test_result = verilog_pp(
        path.join(TEST_DIR, test_file),
        ['.', '..', path.join('sv_pp', 'src')],
        SV)
    with open(path.join(TEST_DIR, golden_file), 'r') as myfile:
        test_golden = myfile.read()
    myfile.close()
    return test_result, test_golden


def _test_run_rel(test_file, golden_file):
    return _test_run(
            path.join('sv_pp', 'src', test_file),
            path.join('sv_pp', 'expected', golden_file)
    )


class PreprocessorTC(unittest.TestCase):

    def assertPPWorks(self, test_file):
        golden_file = test_file  # same name but will get a diffent folder

        result, ref = _test_run_rel(test_file, golden_file)
        self.assertEqual(result, ref)

    def test_2012_p641(self):
        self.assertPPWorks('2012_p641.txt')

    def test_2012_p642(self):
        self.assertPPWorks('2012_p642.txt')

    def test_2012_p642_2(self):
        self.assertPPWorks('2012_p642_2.txt')

    def test_2012_p643(self):
        self.assertPPWorks('2012_p643.txt')

    def test_2012_p643_2(self):
        self.assertPPWorks('2012_p643_2.txt')

    def test_2012_p643_3(self):
        self.assertPPWorks('2012_p643_3.txt')

    def test_2012_p644(self):
        self.assertPPWorks('2012_p644.txt')

    def assertPPError(self, file, err_msg, use_rel_path=False):
        with self.assertRaises(ParseException) as context:
            f = path.join(TEST_DIR, 'sv_pp', 'src', file)
            result = verilog_pp(
                f,
                ['.', '..', path.join('sv_pp', 'src')],
                SV
            )
        self.assertEqual(err_msg, context.exception.__str__())

    def test_2012_p644_2(self):
        self.assertPPError(
            '2012_p644_2.txt',
            '/home/mydir/myfile was not found in include directories\n'
        )

    def test_2012_p641_il1(self):
        self.assertPPError(
            '2012_p641_il1.txt',
            'Missmatch in number of argument macro declaration D (2) and macro usage (1)'
        )

    def test_2012_p641_il2(self):
        self.assertPPError(
            '2012_p641_il2.txt',
            'Missmatch in number of argument macro declaration D (2) and macro usage (0)'
        )

    def test_2012_p641_il3(self):
        self.assertPPError(
            '2012_p641_il3.txt',
            'Missmatch in number of argument macro declaration D (2) and macro usage (3)'
        )

    def test_2012_p642_il1(self):
        self.assertPPError(
            '2012_p642_il1.txt',
            'Missmatch in number of argument macro declaration MACRO1 (3) and macro usage (2)'
        )

    # `MACRO3 must have parentesis according to the SV specification.
    # Currently the code is not able to detect this issue
    @unittest.expectedFailure
    def test_2012_p642_il2(self):
        self.assertPPError(
            '2012_p642_il2.txt',
            'Missmatch in number of argument macro declaration (3) and macro usage (0)'
        )

    # No check that string are not split
    @unittest.expectedFailure
    def test_2012_p642_il3(self):
        self.assertPPError(
            '2012_p642_il3.txt',
            'an error message'
        )

    def test_FILE_LINE(self):
        test_result = verilog_pp(
            path.join(path.dirname(__file__),'sv_pp', 'src', 'test_FILE_LINE.sv'),
            ['.', '..', path.join('sv_pp', 'src')],
            SV
        )
        test_golden = "module tb();\n\ninitial\n\t$display(\"Internal error: null handle at %s, line %d.\",\n"
        test_golden += "\"" + path.join(path.dirname(__file__),
                      'sv_pp', 'src', 'test_FILE_LINE.sv'
                     ) + "\", 5);\n\n\nendmodule\n"
        self.assertEqual(test_result, test_golden)


class PreprocessorGrammar(unittest.TestCase):
    '''
    Non regression of grammar.
    '''

    def getTestName(self):
        testName = self.id().split(".")[-1]
        return testName

    def run_pp_by_testname(self):
        test_name = self.getTestName()
        verilog_pp(path.join(path.dirname(__file__), 'sv_pp', 'raw', test_name + '.txt'),
                   ['.', '..', path.join('sv_pp', 'raw')],
                   SV
        )
    def check_pp_error_by_testname(self, err_msg):
        with self.assertRaises(ParseException) as context:
            self.run_pp_by_testname()
        # print ('|'+context.exception.__str__()+'|')
        self.assertTrue(err_msg == context.exception.__str__())

    def test_celldefine(self):
        self.run_pp_by_testname()

    def test_comments(self):
        self.run_pp_by_testname()

    def test_default_nettype(self):
        self.run_pp_by_testname()

    def test_define1(self):
        self.run_pp_by_testname()

    def test_define2(self):
        self.run_pp_by_testname()

    def test_define3(self):
        self.run_pp_by_testname()

    def test_define4(self):
        self.run_pp_by_testname()

    def test_define5(self):
        self.run_pp_by_testname()

    def test_define6(self):
        self.run_pp_by_testname()

    def test_define7(self):
        self.run_pp_by_testname()

    def test_define8(self):
        self.run_pp_by_testname()

    def test_define9(self):
        self.run_pp_by_testname()

    def test_define10(self):
        self.run_pp_by_testname()

    def test_define11(self):
        self.run_pp_by_testname()

    def test_define12(self):
        self.run_pp_by_testname()

    def test_define13(self):
        self.run_pp_by_testname()

    def test_ifdef(self):
        self.run_pp_by_testname()

    def test_ifdef1(self):
        self.run_pp_by_testname()

    def test_ifdef2(self):
        self.run_pp_by_testname()

    def test_ifdef3(self):
        self.run_pp_by_testname()

    def test_ifndef1(self):
        self.run_pp_by_testname()

    def test_include(self):
        self.check_pp_error_by_testname('file1.txt was not found in include directories\n')

    def test_keywords1(self):
        self.run_pp_by_testname()

    def test_keywords2(self):
        self.run_pp_by_testname()

    def test_line_directive(self):
        self.run_pp_by_testname()

    def test_pragma1(self):
        self.run_pp_by_testname()

    def test_pragma2(self):
        self.run_pp_by_testname()

    def test_real1(self):
        self.run_pp_by_testname()

    def test_real2(self):
        self.run_pp_by_testname()

    def test_timingspec(self):
        self.run_pp_by_testname()

    def test_token1(self):
        self.check_pp_error_by_testname('uvm_info is not defined')

    def test_token2(self):
        self.check_pp_error_by_testname('uvm_info is not defined')

    def test_token3(self):
        self.check_pp_error_by_testname('D is not defined')

    def test_token4(self):
        self.check_pp_error_by_testname('D is not defined')

    def test_token5(self):
        self.check_pp_error_by_testname('D is not defined')

    def test_token6(self):
        self.check_pp_error_by_testname('D is not defined')

    def test_token7(self):
        self.check_pp_error_by_testname('wordsize is not defined')

    def test_token8(self):
        self.check_pp_error_by_testname('sum is not defined')

    def test_unconnected_drive(self):
        self.run_pp_by_testname()

    def test_undef(self):
        self.run_pp_by_testname()


if __name__ == "__main__":
    unittest.main()
