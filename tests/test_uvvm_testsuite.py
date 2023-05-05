#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import unittest

from hdlConvertorAst.language import Language
from tests.extern_test_utils import generate_external_testcase_class, \
    ExternTestSpec, check_git_submodule
from tests.file_utils import find_files
from tests.time_logging_test_runner import TimeLoggingTestRunner

UVVM_ROOT = os.path.join(os.path.dirname(__file__), "UVVM")

# use this file to run tests in incremental maner,
# the test which passed in previous build will not be executed again
# SUCESSFULL_TEST_FILTER_FILE = "tests_passed.vunit"
SUCESSFULL_TEST_FILTER_FILE = None


def get_uvvm_test_configs():
    check_git_submodule(UVVM_ROOT)
    for vhdl_file in find_files(UVVM_ROOT, "*.vhd"):
        should_fail = False

        lang = Language.VHDL_2008
        defs = {}
        inc_dirs = []
        
        yield ExternTestSpec(vhdl_file, lang, defs, inc_dirs, should_fail)


UVVMTestsuite = generate_external_testcase_class(
            "UVVMTestsuite",
            get_uvvm_test_configs(),
            SUCESSFULL_TEST_FILTER_FILE)

if __name__ == '__main__':
    # unittest.main(failfast=True)
    suite = unittest.TestSuite()
    testLoader = unittest.TestLoader()
    suite = testLoader.loadTestsFromTestCase(UVVMTestsuite)
    runner = TimeLoggingTestRunner(verbosity=3)
    runner.run(suite)
