from os import path
import unittest

from hdlConvertor import HdlConvertor
from hdlConvertor.language import Language

SV = Language.SYSTEM_VERILOG_2012
RAW_DIR = path.join(path.dirname(__file__), 'sv_pp', 'raw')
EXPECTED_DIR = path.join(path.dirname(__file__), 'sv_pp', 'expected')


class VerilogPreprocIncludeTC(unittest.TestCase):
    '''
    Non regression of grammar.
    '''

    def run_test(self, file, incdirs):
        c = HdlConvertor()
        if not isinstance(file, list):
            file = [file, ]
        f = path.join(RAW_DIR, *file)
        res = c.verilog_pp(f, incdirs, SV)
        ref_file = path.join(EXPECTED_DIR, *file)
        with open(ref_file) as exp_f:
            expected = exp_f.read()

        self.assertEqual(res, expected)

    # def check_pp_error_by_methodname(self, err_msg):
    #     with self.assertRaises(ParseException) as context:
    #         self.run_pp_by_methodname()
    #
    #     self.assertTrue(err_msg == context.exception.__str__())

    def test_basic_include(self):
        self.run_test(["include_same_dir", "basic_include.txt"], [])

    def test_basic_include2times(self):
        self.run_test(["include_same_dir", "basic_include2times.txt"], [])


if __name__ == "__main__":
    suite = unittest.TestSuite()
    # suite.addTest(VerilogPreprocGrammarTC('test_undef'))
    suite.addTest(unittest.makeSuite(VerilogPreprocIncludeTC))

    runner = unittest.TextTestRunner(verbosity=3)
    runner.run(suite)
