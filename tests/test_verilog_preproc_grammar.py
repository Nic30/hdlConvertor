from os import path
import unittest

from hdlConvertor import HdlConvertor, ParseException
from hdlConvertor.language import Language


class VerilogPreprocGrammarTC(unittest.TestCase):
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
        incdirs = [path.join('sv_pp', 'raw'), ]
        res = c.verilog_pp(f, Language.SYSTEM_VERILOG, incdirs)
        return res

    def check_pp_error_by_methodname(self, err_msg):
        with self.assertRaises(ParseException) as context:
            self.run_pp_by_methodname()

        e = str(context.exception)
        # print(e)
        self.assertGreaterEqual(len(e), len(err_msg))
        _e = e[-len(err_msg):]
        if err_msg != _e:
            # print whole error if there is some problem
            self.assertEqual(err_msg, e)
        else:
            self.assertEqual(err_msg, _e)

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
            'Error: "file1.txt" was not found in include directories\n')

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

    def test_space_between_comments(self):
        self.run_pp_by_methodname()


if __name__ == "__main__":
    suite = unittest.TestSuite()
    # suite.addTest(VerilogPreprocGrammarTC('test_comments'))
    suite.addTest(unittest.makeSuite(VerilogPreprocGrammarTC))

    runner = unittest.TextTestRunner(verbosity=3)
    runner.run(suite)
