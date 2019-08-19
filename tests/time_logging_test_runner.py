import sys
if sys.version_info[0] == 2:
    from future.builtins import super
 
import time
import unittest
from unittest.runner import TextTestResult



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
        if kwargs.get("resultclass", None) is None:
            kwargs["resultclass"] = TimeLoggingTestResult
        if "verbosity" not in kwargs:
            kwargs["verbosity"] = 3
        return super(TimeLoggingTestRunner, self).__init__(
            *args,
            **kwargs
        )
