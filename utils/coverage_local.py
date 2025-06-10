#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os

from coverage.cmdline import main as coverage_main
"""
Script which generates HTML coverage report in $REPO/htmlcov folder.
"""

if __name__ == "__main__":
    os.chdir(os.path.join(os.path.dirname(__file__), ".."))
    coverage_main(["run", "--source", "hdlConvertor", "-m", "tests.all", "--singlethread"])
    coverage_main(["report", "-m"])
    coverage_main(["html"])
    # lcov --capture --directory . --output-file coverage.info
    # lcov --remove coverage.info.raw -o coverage.info '/usr/*';
    # genhtml coverage.info --output-directory out
    
