import unittest

from tests.test_sv_std_examples_parse import SvStdExamplesParseTC
from tests.test_verilog_conversion import VerilogConversionTC
from tests.test_verilog_preproc import VerilogPreprocTC
from tests.test_verilog_preproc_grammar import VerilogPreprocGrammarTC
from tests.test_verilog_preproc_include import VerilogPreprocIncludeTC
from tests.test_verilog_preproc_macro_db_api import VerilogPreprocMacroDbApiTC
from tests.test_vhdl_conversion import VhdlConversionTC
from tests.time_logging_test_runner import TimeLoggingTestRunner


def main_test_suite():
    suite = unittest.TestSuite()
    tcs = [
        VerilogPreprocGrammarTC,
        VerilogPreprocTC,
        VerilogPreprocIncludeTC,
        VerilogPreprocMacroDbApiTC,
        VerilogConversionTC,
        VhdlConversionTC,
        SvStdExamplesParseTC,
    ]
    for tc in tcs:
        suite.addTest(unittest.makeSuite(tc))
    return suite


if __name__ == "__main__":
    suite = main_test_suite()
    runner = TimeLoggingTestRunner(verbosity=3)
    runner.run(suite)
