#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import sys
import unittest

from hdlConvertorAst.language import Language
from tests.extern_test_utils import generate_external_testcase_class, \
    ExternTestSpec, check_git_submodule
from tests.file_utils import find_files
from tests.time_logging_test_runner import TimeLoggingTestRunner

if sys.version_info.major == 2:
    FileNotFoundError = IOError
    from io import open


GHDL_ROOT = os.path.join(os.path.dirname(__file__), "ghdl")

# use this file to run tests in incremental maner,
# the test which passed in previous build will not be executed again
# SUCESSFULL_TEST_FILTER_FILE = "tests_passed.vunit"
SUCESSFULL_TEST_FILTER_FILE = None


def get_ghdl_test_configs(path):
    check_git_submodule(GHDL_ROOT)
    for vhdl_file in find_files(os.path.join(GHDL_ROOT, *path.split("/")), "*.vhdl"):
        should_fail = False
        testsuite_sh = os.path.join(os.path.dirname(vhdl_file), "testsuite.sh")
        try:
            with open(testsuite_sh) as f:
                t = f.read()
                if "--expect-failure" in t or "analyze_failure " + os.path.basename(vhdl_file) in t:
                    should_fail = True
        except FileNotFoundError:
            pass
        
        # because of windows
        _vhdl_file = vhdl_file.replace("\\", "/")
        if _vhdl_file.endswith("issue300/test_bench.vhdl") or \
                _vhdl_file.endswith("synth48/test.vhdl") or \
                _vhdl_file.endswith("issue626/repro.vhdl") or \
                _vhdl_file.endswith("issue626/top.vhdl") or \
                _vhdl_file.endswith("issue634/top.vhdl") or \
                _vhdl_file.endswith("issue983/test.vhdl") or \
                _vhdl_file.endswith("issue1367/issue.vhdl") or \
                _vhdl_file.endswith("issue1345/issue.vhdl") or \
                _vhdl_file.endswith("issue1322/issue.vhdl") or \
                _vhdl_file.endswith("issue1321/issue.vhdl") or \
                _vhdl_file.endswith("issue1314/issue.vhdl") or \
                _vhdl_file.endswith("issue1347/issue.vhdl") or \
                _vhdl_file.endswith("synth27/dff.vhdl") or \
                _vhdl_file.endswith("issue1295/issue.vhdl") or \
                _vhdl_file.endswith("issue1292/issue.vhdl") or \
                _vhdl_file.endswith("issue1288/issue.vhdl"):
            # keyword as architecture name
            should_fail = True
        elif "testsuite/gna/bug030" in _vhdl_file:
            # keyword as signal name
            should_fail = True
        elif "testsuite/synth/psl" in _vhdl_file or _vhdl_file.endswith("issue1390/aes_enc.vhdl"):
            # PSL default clock
            should_fail = True
        elif _vhdl_file.endswith("issue662/psl_stable.vhdl") or\
                _vhdl_file.endswith("issue662/psl_rose.vhdl") or \
                _vhdl_file.endswith("issue662/psl_prev.vhdl") or \
                _vhdl_file.endswith("issue1292/psl_next_event_e.vhdl") or \
                _vhdl_file.endswith("issue1295/psl_next_event_a.vhdl") or \
                _vhdl_file.endswith("issue662/psl_fell.vhdl") or \
                _vhdl_file.endswith("bug051/tb2.vhdl"):
            # PSL
            should_fail = True
        elif _vhdl_file.endswith("gna/bug096/reader.vhdl"):
            # error in file spec, in ghdl it is just discovered after
            should_fail = True
        elif "gna/bug090/" in _vhdl_file or "gna/bug0100/" in _vhdl_file:
            # error, but it is described in testsuite.sh in format which can not be parsed
            should_fail = True
        elif _vhdl_file.endswith("gna/issue106/ent3.vhdl"):
            # missing case when value
            should_fail = True
        elif _vhdl_file.endswith("gna/issue520/lrm.vhdl"):
            # missing ; after last item in block stm
            should_fail = True
        elif _vhdl_file.endswith("bug0105/econcat2_87.vhdl") or \
                _vhdl_file.endswith("bug0105/econcat2.vhdl") or \
                _vhdl_file.endswith("bug0105/econcat1_87.vhdl") or \
                _vhdl_file.endswith("bug0105/econcat1.vhdl") or \
                _vhdl_file.endswith("std/textio-body.vhdl"):
            # std87 obscure relicts
            should_fail = True
        
        elif _vhdl_file.endswith("bug031/ams1.vhdl") or \
                _vhdl_file.endswith("004all08/ams08.vhdl"):
            # AMS extension
            should_fail = True
        elif _vhdl_file.endswith("issue106/ent2.vhdl"):
            # block in generate has to have label
            should_fail = True
        
        lang = Language.VHDL_2008
        defs = {}
        inc_dirs = []
        
        if "utf8" in vhdl_file:
            encoding = "utf-8"
        elif "utf16" in vhdl_file:
            encoding = "utf-16"
        else:
            encoding = "iso-8859-1"
        with open(vhdl_file, encoding=encoding) as f:
            d = f.read()
            if d.startswith("vunit"):
                continue

        yield ExternTestSpec(vhdl_file, lang, defs, inc_dirs, should_fail, encoding=encoding)


GhdlTestsuiteTestsuiteTC = generate_external_testcase_class(
    'GhdlTestsuiteTestsuiteTC',
    get_ghdl_test_configs("testsuite"),
    SUCESSFULL_TEST_FILTER_FILE)

GHDL_LIBS = [
    "ieee", "openieee", "std", "vendors", "vital95",
    "ieee2008", "mentor", "synopsys", "vital2000",
]
GhdlTestsuiteTCs = [
        generate_external_testcase_class(
            'Ghdl_%s_TestsuiteTC' % lib,
            get_ghdl_test_configs("libraries/" + lib),
            SUCESSFULL_TEST_FILTER_FILE)
          for lib in GHDL_LIBS
    ] + [
        GhdlTestsuiteTestsuiteTC
]

if __name__ == '__main__':
    # unittest.main(failfast=True)
    testLoader = unittest.TestLoader()
    # suite = unittest.TestSuite([GhdlIEEETestsuiteTC("test_VHDL_2008_numeric_bit")])
    suite = unittest.TestSuite([testLoader.loadTestsFromTestCase(tc) for tc in GhdlTestsuiteTCs])

    runner = TimeLoggingTestRunner(verbosity=3)
    runner.run(suite)
