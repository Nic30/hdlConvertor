from os import path
import unittest
try:
    from tests.test_constants import *
except ImportError:
    from test_constants import *

from hdlConvertor import ParseException, HdlConvertor
from hdlConvertor.language import Language

SV = Language.SYSTEM_VERILOG_2012


def _test_run(test_file, golden_file):
    c = HdlConvertor()

    incdirs = ['.', '..', path.join('sv_pp', 'src')]
    test_result = c.verilog_pp(
        test_file, incdirs, SV)

    with open(golden_file) as myfile:
        test_golden = myfile.read()

    return test_result, test_golden


def _test_run_rel(test_file, golden_file):
    return _test_run(
            path.join(TEST_DIR, 'sv_pp', 'src', test_file),
            path.join(TEST_DIR, 'sv_pp', 'expected', golden_file)
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

    def assertPPError(self, file, err_msg):
        with self.assertRaises(ParseException) as context:
            f = path.join(TEST_DIR, 'sv_pp', 'src', file)
            c = HdlConvertor()
            c.verilog_pp(
                f,
                ['.', '..', path.join('sv_pp', 'src')],
                SV
            )
        self.assertEqual(err_msg, context.exception.__str__())

    def test_2012_p644_2(self):
        # [TODO] platform dependent path
        self.assertPPError(
            '2012_p644_2.txt',
            '/home/mydir/myfile was not found in include directories\n'
        )

    def test_2012_p641_il1(self):
        self.assertPPError(
            '2012_p641_il1.txt',
            'Mismatch in number of argument macro declaration D (2) and macro usage (1)'
        )

    def test_2012_p641_il2(self):
        self.assertPPError(
            '2012_p641_il2.txt',
            'Mismatch in number of argument macro declaration D (2) and macro usage (0)'
        )

    def test_2012_p641_il3(self):
        self.assertPPError(
            '2012_p641_il3.txt',
            'Mismatch in number of argument macro declaration D (2) and macro usage (3)'
        )

    def test_2012_p642_il1(self):
        self.assertPPError(
            '2012_p642_il1.txt',
            'Mismatch in number of argument macro declaration MACRO1 (3) and macro usage (2)'
        )

    # `MACRO3 must have parentesis according to the SV specification.
    # Currently the code is not able to detect this issue
    def test_2012_p642_il2(self):
        self.assertPPError(
            '2012_p642_il2.txt',
            'Mismatch in number of argument macro declaration (3) and macro usage (0)'
        )

    # No check that string are not split
    @unittest.expectedFailure
    def test_2012_p642_il3(self):
        self.assertPPError(
            '2012_p642_il3.txt',
            'an error message'
        )

    def test_FILE_LINE(self):
        c = HdlConvertor()
        f = path.join(path.dirname(__file__), 'sv_pp', 'src', 'test_FILE_LINE.sv')
        incdirs = ['.', '..', path.join('sv_pp', 'src')]
        test_result = c.verilog_pp(f, incdirs, SV)
        expected_val = path.join(path.dirname(__file__),
                                 'sv_pp', 'src', 'test_FILE_LINE.sv'
                                 )
        test_golden = ("module tb();\n\ninitial\n\t$display("
                      "\"Internal error: null handle at %s, line %d.\",\n")
        test_golden += "\"" + expected_val + "\", 5);\n\n\nendmodule\n"
        self.assertEqual(test_result, test_golden)


class PreprocessorGrammar(unittest.TestCase):
    '''
    Non regression of grammar.
    '''

    def getTestName(self):
        testName = self.id().split(".")[-1]
        return testName

    def run_pp_by_methodname(self):
        test_name = self.getTestName()
        c = HdlConvertor()
        f = path.join(path.dirname(__file__), 'sv_pp', 'raw', test_name + '.txt')
        incdirs = ['.', '..', path.join('sv_pp', 'raw')]
        return c.verilog_pp(f, incdirs, SV)

    def check_pp_error_by_methodname(self, err_msg):
        with self.assertRaises(ParseException) as context:
            self.run_pp_by_methodname()

        self.assertTrue(err_msg == context.exception.__str__())

    def test_celldefine(self):
        self.run_pp_by_methodname()

    def test_comments(self):
        self.run_pp_by_methodname()

    def test_default_nettype(self):
        self.run_pp_by_methodname()

    def test_define1(self):
        self.run_pp_by_methodname()

    def test_define2(self):
        self.run_pp_by_methodname()

    def test_define3(self):
        self.run_pp_by_methodname()

    def test_define4(self):
        self.run_pp_by_methodname()

    def test_define5(self):
        self.run_pp_by_methodname()

    def test_define6(self):
        self.run_pp_by_methodname()

    def test_define7(self):
        self.run_pp_by_methodname()

    def test_define8(self):
        self.run_pp_by_methodname()

    def test_define9(self):
        self.run_pp_by_methodname()

    def test_define10(self):
        self.run_pp_by_methodname()

    def test_define11(self):
        self.run_pp_by_methodname()

    def test_define12(self):
        self.run_pp_by_methodname()

    def test_define13(self):
        self.run_pp_by_methodname()

    def test_ifdef(self):
        self.run_pp_by_methodname()

    def test_ifdef1(self):
        self.run_pp_by_methodname()

    def test_ifdef2(self):
        self.run_pp_by_methodname()

    def test_ifdef3(self):
        self.run_pp_by_methodname()

    def test_ifndef1(self):
        self.run_pp_by_methodname()

    def test_include(self):
        self.check_pp_error_by_methodname(
            'file1.txt was not found in include directories\n')

    def test_keywords1(self):
        self.run_pp_by_methodname()

    def test_keywords2(self):
        self.run_pp_by_methodname()

    def test_line_directive(self):
        self.run_pp_by_methodname()

    def test_pragma1(self):
        self.run_pp_by_methodname()

    def test_pragma2(self):
        self.run_pp_by_methodname()

    def test_real1(self):
        self.run_pp_by_methodname()

    def test_real2(self):
        self.run_pp_by_methodname()

    def test_timingspec(self):
        self.run_pp_by_methodname()

    def test_token1(self):
        self.check_pp_error_by_methodname('uvm_info is not defined')

    def test_token2(self):
        self.check_pp_error_by_methodname('uvm_info is not defined')

    def test_token3(self):
        self.check_pp_error_by_methodname('D is not defined')

    def test_token4(self):
        self.check_pp_error_by_methodname('D is not defined')

    def test_token5(self):
        self.check_pp_error_by_methodname('D is not defined')

    def test_token6(self):
        self.check_pp_error_by_methodname('D is not defined')

    def test_token7(self):
        self.check_pp_error_by_methodname('wordsize is not defined')

    def test_token8(self):
        self.check_pp_error_by_methodname('sum is not defined')

    def test_unconnected_drive(self):
        self.run_pp_by_methodname()

    def test_undef(self):
        self.run_pp_by_methodname()


if __name__ == "__main__":
    unittest.main()
