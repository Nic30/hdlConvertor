import unittest

from hdlConvertor import ParseException
from hdlConvertor.language import Language

try:
    from tests.basic_tc import BasicTC, parseFile as _parseFile
except ImportError:
    from basic_tc import BasicTC, parseFile as _parseFile


def parseFile(fname):
    return _parseFile(fname, Language.VHDL)


class VhdlConversionTC(BasicTC):

    def test_vhld_dump_mux(self):
        f, res = parseFile("mux.vhd")
        str(res)

    def test_vhdl_package_array_const(self):
        f, res = parseFile("package_array_const.vhd")
        str(res)

    def test_vhdl_package_component(self):
        f, res = parseFile("package_component.vhd")
        str(res)

    def test_vhdl_package_constants(self):
        f, res = parseFile("package_constants.vhd")
        str(res)

    def test_vhdl_fourbit_adder(self):
        f, res = parseFile("fourbit_adder.vhd")
        str(res)

    def test_vhdl_mux2i(self):
        f, res = parseFile("mux2i.vhd")
        str(res)

    def test_vhdl_ram(self):
        self.parseWithRef("ram.vhd", Language.VHDL)

    def test_vhdl_malformed(self):
        with self.assertRaises(ParseException):
            f, res = parseFile("malformed.vhdl")


if __name__ == "__main__":
    suite = unittest.TestSuite()
    # suite.addTest(BasicTC('test_read'))
    suite.addTest(unittest.makeSuite(VhdlConversionTC))

    runner = unittest.TextTestRunner(verbosity=3)
    runner.run(suite)
