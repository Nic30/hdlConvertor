import unittest


try:
    from tests.test_verilog_preproc import VerilogPreprocTC
    from tests.test_verilog_preproc_grammar import VerilogPreprocGrammarTC
    from tests.test_verilog_preproc_include import VerilogPreprocIncludeTC
    from tests.test_verilog_conversion import VerilogConversionTC
    from tests.test_vhdl_conversion import VhdlConversionTC
except ImportError:
    from test_verilog_preproc import VerilogPreprocTC
    from test_verilog_preproc_grammar import VerilogPreprocGrammarTC
    from test_verilog_preproc_include import VerilogPreprocIncludeTC
    from test_verilog_conversion import VerilogConversionTC
    from test_vhdl_conversion import VhdlConversionTC


if __name__ == "__main__":
    suite = unittest.TestSuite()
    tcs = [
        VerilogPreprocGrammarTC,
        VerilogPreprocTC,
        VerilogPreprocIncludeTC,
        VerilogConversionTC,
        VhdlConversionTC,
    ]
    for tc in tcs:
        suite.addTest(unittest.makeSuite(tc))

    runner = unittest.TextTestRunner(verbosity=3)
    runner.run(suite)
