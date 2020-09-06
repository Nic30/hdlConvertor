#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import os
from setuptools import find_packages
from skbuild import setup
import sys


this_directory = os.path.abspath(os.path.dirname(__file__))
with open(os.path.join(this_directory, "README.md")) as f:
    long_description = f.read()

deps = ["typing", "future"] if sys.version_info[0] == 2 else []


setup(
    cmake_args=[
        # '-DCMAKE_BUILD_TYPE=Debug'
    ],
    name='hdlConvertor',
    version='2.1',
    description='VHDL and System Verilog parser written in c++',
    long_description=long_description,
    long_description_content_type="text/markdown",
    url='https://github.com/Nic30/hdlConvertor',
    author='Michal Orsak',
    author_email='michal.o.socials@gmail.com',
    keywords=['hdl', 'vhdl', 'verilog', 'system verilog',
              'parser', 'preprocessor', 'antlr4'],
    classifiers=[
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'Intended Audience :: Science/Research',
        'Operating System :: OS Independent',
        'Topic :: Software Development :: Build Tools',
        'Programming Language :: C++',
        'Programming Language :: Cython',
        'Programming Language :: Python :: Implementation :: CPython',
        'Programming Language :: Python :: 2.7',
        'Programming Language :: Python :: 3',
        'Topic :: Scientific/Engineering :: Electronic Design Automation (EDA)',
    ],
    install_requires=[
        'hdlConvertorAst>=0.5',
    ] + deps,
    license="MIT",
    packages=[p for p in find_packages() if p != "tests"],
    test_suite="tests.main_test_suite",
    test_runner="tests:TimeLoggingTestRunner",
    tests_require=deps,
)
