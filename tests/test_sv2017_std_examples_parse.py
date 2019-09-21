# import sys
from glob import glob
import os
import unittest

from hdlConvertor import HdlConvertor
from hdlConvertor.language import Language

from tests.time_logging_test_runner import TimeLoggingTestRunner
from tests.file_utils import get_file_name

HDL_CONVERTOR_ROOT = os.path.join(os.path.dirname(__file__), "..")
SV2017_ROOT = os.path.join(HDL_CONVERTOR_ROOT, "tests", "sv_test", "std2017")
sv_files = [f for f in glob(os.path.join(SV2017_ROOT, '*.sv'))]


# https://stackoverflow.com/questions/32899/how-do-you-generate-dynamic-parameterized-unit-tests-in-python
class Sv2017StdExamplesParseMeta(type):

    def __new__(cls, name, bases, _dict):

        def gen_test(sv_file):

            def test(self):
                c = HdlConvertor()
                incdirs = []
                c.parse([sv_file, ], Language.SYSTEM_VERILOG_2017, incdirs, debug=False)

            return test

        for sv_file in sv_files:
            fn = get_file_name(sv_file)
            test_name = "test_%s" % fn
            t = gen_test(sv_file)
            _dict[test_name] = t 
        return type.__new__(cls, name, bases, _dict)


# https://www.oipapio.com/question-219175 , python2/3 compatible specification of metatype for class
Sv2017StdExamplesParseTC = Sv2017StdExamplesParseMeta('Sv2017StdExamplesParseTC', (unittest.TestCase,), {})

if __name__ == '__main__':
    suite = unittest.TestSuite()

    # suite.addTest(Sv2017StdExamplesParseTC('test_p552'))
    suite.addTest(unittest.makeSuite(Sv2017StdExamplesParseTC))

    runner = TimeLoggingTestRunner(verbosity=3)
    runner.run(suite)
