#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import unittest

from hdlConvertor import HdlConvertor
from hdlConvertorAst.language import Language


class VerilogPreprocMacroDbApiTC(unittest.TestCase):

    def test_can_update(self):
        c = HdlConvertor()
        db = c.preproc_macro_db
        db["SYMBOL0"] = "0"
        db["SYMBOL1"] = "1"
        db["SYMBOL2"] = "2"

        keys = list(db.keys())
        values = [(v.name, v.get_body()) for v in db.values()]
        items = [(i[0], i[1].get_body()) for i in db.items()]
        # [note] we know order as the std::map is ordered
        self.assertEqual(keys, ["SYMBOL%d" % i for i in range(3)])
        ref_values = [("SYMBOL%d" % i, "%d" % i) for i in range(3)]
        self.assertEqual(values, ref_values)
        self.assertEqual(items, ref_values)

        # test_result = c.verilog_pp(
        #     test_file, Language.SYSTEM_VERILOG, incdirs)
        del db["SYMBOL2"]
        keys = list(db.keys())
        self.assertEqual(keys, ["SYMBOL%d" % i for i in range(2)])

        db.update({
            "SYMBOL2": "2",
            "SYMBOL3": "3",
        })
        keys = list(db.keys())
        self.assertEqual(keys, ["SYMBOL%d" % i for i in range(4)])
        self.assertIn("SYMBOL1", db)
        self.assertNotIn("SYMBOL_9", db)

        db.clear()
        keys = list(db.keys())
        self.assertEqual(keys, [])

    def test_define_and_use_in_preproc(self):
        c = HdlConvertor()
        db = c.preproc_macro_db
        db["S0"] = "0"
        res = c.verilog_pp_str("`S0", Language.SYSTEM_VERILOG)
        self.assertEqual(res, "0")

    def test_can_recover_defines_from_verilog(self):
        c = HdlConvertor()
        c.verilog_pp_str("`define TEST_SYMBOL\n", Language.SYSTEM_VERILOG)
        db = c.preproc_macro_db
        self.assertIn("TEST_SYMBOL", db)

    def test_dos_crlf(self):
        c = HdlConvertor()
        c.verilog_pp_str("`define P0 1\r\n`define P1 2\r\n`define TEST_SYMBOL `P0\\\r\n `P1\r\n", Language.SYSTEM_VERILOG)
        db = c.preproc_macro_db
        self.assertIn("TEST_SYMBOL", db)
        self.assertEqual(db["TEST_SYMBOL"].get_body(), "1\r\n 2")


if __name__ == "__main__":
    testLoader = unittest.TestLoader()
    # suite = unittest.TestSuite([VerilogPreprocMacroDbApiTC("test_can_recover_defines_from_verilog")])
    suite = testLoader.loadTestsFromTestCase(VerilogPreprocMacroDbApiTC)

    runner = unittest.TextTestRunner(verbosity=3)
    runner.run(suite)
