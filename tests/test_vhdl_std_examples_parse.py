import unittest

from hdlConvertor.language import Language

from tests.basic_tc import BasicTC, parseFile as _parseFile
import os

VHDL_2008_ROOT = os.path.join(os.path.dirname(__file__), "vhdl", "2008")


def parseFile(fname):
    return _parseFile(os.path.join(VHDL_2008_ROOT, fname), Language.VHDL_2008)


class Vhdl2008StdExamplesParseTC(BasicTC):

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


if __name__ == "__main__":
    suite = unittest.TestSuite()
    suite.addTest(Vhdl2008StdExamplesParseTC('test_types'))
    # suite.addTest(unittest.makeSuite(Vhdl2008StdExamplesParseTC))

    runner = unittest.TextTestRunner(verbosity=3)
    runner.run(suite)
