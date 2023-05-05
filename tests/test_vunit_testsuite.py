#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import unittest

from hdlConvertorAst.language import Language
from tests.extern_test_utils import generate_external_testcase_class, \
    ExternTestSpec, check_git_submodule
from tests.file_utils import find_files, get_file_name
from tests.time_logging_test_runner import TimeLoggingTestRunner


VUNIT_ROOT = os.path.join(os.path.dirname(__file__), "vunit")

# use this file to run tests in incremental maner,
# the test which passed in previous build will not be executed again
# SUCESSFULL_TEST_FILTER_FILE = "tests_passed.vunit"
SUCESSFULL_TEST_FILTER_FILE = None


def get_vunit_test_configs():
    check_git_submodule(VUNIT_ROOT)
    for vhdl_file in find_files(VUNIT_ROOT, "*.vhd"):
        fn = get_file_name(vhdl_file)
        should_fail = False
        lang = Language.VHDL_2008
        if fn in ["tb_deprecated",
                  # ? broken assert always  statement?
                  "fifo",
                  ]:
            should_fail = True

        defs = {}
        inc_dirs = []
        yield ExternTestSpec(vhdl_file, lang, defs, inc_dirs, should_fail)


VUnitTestsuiteTC = generate_external_testcase_class(
    'VUnitTestsuiteTC',
    get_vunit_test_configs(),
    SUCESSFULL_TEST_FILTER_FILE)

if __name__ == '__main__':
    # unittest.main(failfast=True)
    testLoader = unittest.TestLoader()
    # suite = unittest.TestSuite([VUnitTestsuiteTC("test_VHDL_2008_axi_lite_master_pkg")])
    suite = testLoader.loadTestsFromTestCase(VUnitTestsuiteTC)

    runner = TimeLoggingTestRunner(verbosity=3)
    runner.run(suite)
