# import sys
import os
from glob import glob
from hdlConvertor.language import Language
from hdlConvertor import HdlConvertor

# if sys.version_info[0] == 2:
#    import unittest2 as unittest
# else:
import unittest
import time
from unittest.runner import TextTestResult

HDL_CONVERTOR_ROOT = os.path.join(os.path.dirname(__file__), "..")
SV2017_ROOT = os.path.join(HDL_CONVERTOR_ROOT, "tests", "sv_test", "std2017")
sv_files = [f for f in glob(os.path.join(SV2017_ROOT, '*.sv'))]


def get_file_name(f):
    return os.path.splitext(os.path.basename(f))[0]


class TimeLoggingTestResult(TextTestResult):

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.test_timings = []

    def startTest(self, test):
        self._test_started_at = time.time()
        super().startTest(test)

    def addSuccess(self, test):
        elapsed = time.time() - self._test_started_at
        name = self.getDescription(test)
        self.test_timings.append((name, elapsed))
        super(TextTestResult, self).addSuccess(test)
        if self.showAll:
            self.stream.write("ok")
            self.stream.writeln(" {:.03}s".format(elapsed))
        elif self.dots:
            self.stream.write('.')
            self.stream.flush()

    def getTestTimings(self):
        return self.test_timings


class TimeLoggingTestRunner(unittest.TextTestRunner):
    
    def __init__(self, *args, **kwargs):
        return super().__init__(
            resultclass=TimeLoggingTestResult,
            *args,
            **kwargs,
        )


# https://stackoverflow.com/questions/32899/how-do-you-generate-dynamic-parameterized-unit-tests-in-python
class SvStdExamplesParseMeta(type):

    def __new__(cls, name, bases, _dict):

        def gen_test(sv_file):

            def test(self):
                c = HdlConvertor()
                incdirs = []
                c.parse([sv_file, ], Language.SYSTEM_VERILOG_2017, incdirs, debug=False)

            return test

        for sv_file in sv_files:
            test_name = "test_%s" % get_file_name(sv_file)
            _dict[test_name] = gen_test(sv_file)
        return type.__new__(cls, name, bases, _dict)


# https://www.oipapio.com/question-219175
SvStdExamplesParseTC = SvStdExamplesParseMeta('SvStdExamplesParseTC', (unittest.TestCase,), {})

# class SvStdExamplesParseTC(unittest.TestCase):
#
#    def test_upper(self):
#        tests = [
#            # file name without extension
#            (get_file_name(f), f)
#            for f in sv_files
#        ]
#        for test_name, sv_file_name in tests:
#            with self.subTest(file=test_name):
#                c = HdlConvertor()
#                incdirs = []
#                c.parse([sv_file_name, ], Language.SYSTEM_VERILOG_2017, incdirs, debug=False)

if __name__ == '__main__':
    suite = unittest.TestSuite()

    # suite.addTest(SvStdExamplesParseTC('test_p552'))
    suite.addTest(unittest.makeSuite(SvStdExamplesParseTC))

    runner = TimeLoggingTestRunner(verbosity=3)
    runner.run(suite)
