import unittest

from hdlConvertor import ParseException
from hdlConvertor.language import Language

from tests.basic_tc import BasicTC, parseFile as _parseFile


def parseFile(fname):
    return _parseFile(fname, Language.VHDL)


class VhdlConversionTC(BasicTC):

    def test_dump_mux(self):
        f, res = parseFile("mux.vhd")
        str(res)

    def test_package_array_const(self):
        f, res = parseFile("package_array_const.vhd")
        str(res)

    def test_package_component(self):
        f, res = parseFile("package_component.vhd")
        str(res)

    def test_package_constants(self):
        f, res = parseFile("package_constants.vhd")
        str(res)

    def test_fourbit_adder(self):
        f, res = parseFile("fourbit_adder.vhd")
        str(res)

    def test_mux2i(self):
        f, res = parseFile("mux2i.vhd")
        str(res)

    def test_ram(self):
        self.parseWithRef("ram.vhd", Language.VHDL)

    def test_malformed(self):
        with self.assertRaises(ParseException):
            f, res = parseFile("malformed.vhdl")

    def test_arch_with_assig(self):
        self.parseWithRef("arch_with_assig.vhd", Language.VHDL)

    def test_with_select(self):
        self.parseWithRef("with_select.vhd", Language.VHDL)

    def test_call(self):
        self.parseWithRef("call.vhd", Language.VHDL)

    def test_type_attribute_designator(self):
        self.parseWithRef("type_attribute_designator.vhd", Language.VHDL)


if __name__ == "__main__":
    suite = unittest.TestSuite()
    # suite.addTest(VhdlConversionTC('test_with_select'))
    suite.addTest(unittest.makeSuite(VhdlConversionTC))

    runner = unittest.TextTestRunner(verbosity=3)
    runner.run(suite)
