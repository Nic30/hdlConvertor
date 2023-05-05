#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import unittest

from hdlConvertor import ParseException
from hdlConvertorAst.language import Language
from hdlConvertorAst.hdlAst import HdlLibrary, HdlValueIdspace
from tests.hdl_parse_tc import HdlParseTC, parseFile as _parseFile


def parseFile(fname):
    return _parseFile(fname, Language.VHDL)


class VhdlConversionTC(HdlParseTC):

    def test_dump_mux(self):
        _, res = parseFile("mux.vhd")
        str(res)

    def test_package_array_const(self):
        _, res = parseFile("package_array_const.vhd")
        str(res)
        pkg = res.objs[0]
        self.assertIsInstance(pkg, HdlValueIdspace)
        self.assertEqual(pkg.name, 'array_const_pkg')

    def test_package_constants(self):
        _, res = self.parseWithRef("package_constants.vhd", Language.VHDL)
        str(res)
        pkg = res.objs[4]  # first 4 objects are libraries and 'use' clauses
        self.assertIsInstance(pkg, HdlValueIdspace)
        self.assertEqual(pkg.name, 'constants_pkg')

    def test_package_component(self):
        _, res = parseFile("package_component.vhd")
        str(res)
        pkg = res.objs[4]  # first 4 objects are libraries and 'use' clauses
        self.assertIsInstance(pkg, HdlValueIdspace)
        self.assertEqual(pkg.name, 'components_pkg')

    def test_package_enum(self):
        self.parseWithRef("package_enum.vhd", Language.VHDL)

    def test_json_package_enum(self):
        _, res = parseFile("package_enum.vhd")
        str(res)

    def test_package_record(self):
        self.parseWithRef("package_record.vhd", Language.VHDL)

    def test_fourbit_adder(self):
        _, res = parseFile("fourbit_adder.vhd")
        str(res)

    def test_mux2i(self):
        _, res = parseFile("mux2i.vhd")
        str(res)

    def test_ram(self):
        self.parseWithRef("ram.vhd", Language.VHDL)

    def test_malformed(self):
        with self.assertRaises(ParseException):
            parseFile("malformed.vhdl")

    def test_arch_with_assig(self):
        self.parseWithRef("arch_with_assig.vhd", Language.VHDL)

    def test_with_select(self):
        self.parseWithRef("with_select.vhd", Language.VHDL)

    def test_call(self):
        self.parseWithRef("call.vhd", Language.VHDL)

    def test_type_attribute_designator(self):
        self.parseWithRef("type_attribute_designator.vhd", Language.VHDL)

    def test_library_declaration(self):
        f, res = parseFile("ram.vhd")
        self.assertIsInstance(res.objs[0], HdlLibrary)
        self.assertEqual(res.objs[0].name, 'ieee')

    def test_operator_example(self):
        self.parseWithRef("operator_example.vhd", Language.VHDL)

    def test_record_in_record(self):
        self.parseWithRef("record_in_record.vhd", Language.VHDL)

    def test_enum(self):
        self.parseWithRef("enum.vhd", Language.VHDL)

    def test_array(self):
        self.parseWithRef("array.vhd", Language.VHDL)

    def test_subtype(self):
        self.parseWithRef("subtype.vhd", Language.VHDL)

    def test_generate_for(self):
        self.parseWithRef("generate_for.vhd", Language.VHDL)

    def test_generate_for_and_if(self):
        self.parseWithRef("generate_for_and_if.vhd", Language.VHDL)

    def test_entity_declarative_item(self):
        self.parseWithRef("entity_declarative_item.vhd", Language.VHDL)

    def test_carry_lookahead(self):
        self.parseWithRef("carry_lookahead.vhd", Language.VHDL)

    def test_package_typedefs(self):
        self.parseWithRef("package_typedefs.vhd", Language.VHDL)

    def test_package_FloPoCoLibRightShifter(self):
        self.parseWithRef("FloPoCoLibRightShifter.vhd", Language.VHDL_2008)

    def test_package_for_in(self):
        self.parseWithRef("for_in.vhd", Language.VHDL)

    def test_package_stm_nop(self):
        self.parseWithRef("stm_nop.vhd", Language.VHDL)

    def test_package_function_noarg(self):
        self.parseWithRef("function_noarg.vhd", Language.VHDL)

    def test_package_association_open(self):
        self.parseWithRef("association_open.vhd", Language.VHDL)

    def test_package_direct_instantiation(self):
        self.parseWithRef("direct_instantiation.vhd", Language.VHDL)

    def test_package_stm_exit(self):
        self.parseWithRef("stm_exit.vhd", Language.VHDL)

    def test_arch_signal_declr_identifier_list(self):
        self.parseWithRef("arch_signal_declr_identifier_list.vhd", Language.VHDL)

if __name__ == "__main__":
    testLoader = unittest.TestLoader()
    # suite = unittest.TestSuite([VhdlConversionTC("test_package_FloPoCoLibRightShifter")])
    suite = testLoader.loadTestsFromTestCase(VhdlConversionTC)

    runner = unittest.TextTestRunner(verbosity=3)
    runner.run(suite)
