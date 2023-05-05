#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import unittest

from hdlConvertorAst.language import Language
from tests.hdl_parse_tc import HdlParseTC, parseFile as _parseFile


VHDL_2008_ROOT = os.path.join(os.path.dirname(__file__), "vhdl", "std2008")


def parseFile(fname):
    return _parseFile(os.path.join(VHDL_2008_ROOT, fname), Language.VHDL_2008)


class Vhdl2008StdExamplesParseTC(HdlParseTC):

    def test_arch(self):
        parseFile("arch.vhd")

    def test_configuration(self):
        parseFile("configuration.vhd")

    def test_declarations(self):
        parseFile("declarations.vhd")

    def test_entity(self):
        parseFile("entity.vhd")

    def test_package(self):
        parseFile("package.vhd")

    def test_subprograms(self):
        parseFile("subprograms.vhd")

    def test_types(self):
        parseFile("types.vhd")

    def test_units(self):
        parseFile("units.vhd")


if __name__ == "__main__":
    testLoader = unittest.TestLoader()
    # suite = unittest.TestSuite([Vhdl2008StdExamplesParseTC("test_types")])
    suite = testLoader.loadTestsFromTestCase(Vhdl2008StdExamplesParseTC)

    runner = unittest.TextTestRunner(verbosity=3)
    runner.run(suite)
