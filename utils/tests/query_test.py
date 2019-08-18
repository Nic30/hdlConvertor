import unittest

from utils.antlr4.query import Antlr4SyntCmp
from utils.antlr4.simple_parser import Antlr4parser


class Antlr4QueryTC(unittest.TestCase):

    def run_cmp(self, a: str, b: str):
        a = Antlr4parser().from_str(a)
        b = Antlr4parser().from_str(b)
        
        cmp = Antlr4SyntCmp()
        return cmp.eq(a, b), cmp.eq_symbols
        
    def test_single_symbol(self):
        a = "a"
        b = "b"
        eq, eq_symbols = self.run_cmp(a, b)
        self.assertTrue(eq)
        self.assertDictEqual(eq_symbols, {"a": "b"})

    def test_single_symbol2(self):
        a = "a"
        b = "a"
        eq, eq_symbols = self.run_cmp(a, b)
        self.assertTrue(eq)
        self.assertDictEqual(eq_symbols, {"a": "a"})

    def test_single_sequence(self):
        a = "a a b"
        b = "b b a"
        eq, eq_symbols = self.run_cmp(a, b)
        self.assertTrue(eq)
        self.assertDictEqual(eq_symbols, {"a": "b", "b": "a"})

    def test_single_sequence2(self):
        a = "a a b a"
        b = "b b a c"
        eq, _ = self.run_cmp(a, b)
        self.assertFalse(eq)

    def test_single_sequence3(self):
        a = "a a b a"
        b = "a a c c"
        eq, _ = self.run_cmp(a, b)
        self.assertFalse(eq)

    def test_single_sequence4(self):
        a = "a a b"
        b = "a a b c"
        eq, _ = self.run_cmp(a, b)
        self.assertFalse(eq)

    def test_single_selection(self):
        a = "( a | b ) a"
        b = "( d | e ) f"
        eq, eq_symbols = self.run_cmp(a, b)
        self.assertFalse(eq)

    def test_single_selection2(self):
        a = "( a | b ) c"
        b = "( d | e ) f"
        eq, eq_symbols = self.run_cmp(a, b)
        self.assertTrue(eq)
        self.assertDictEqual(eq_symbols, {"a": "d", "b": "e", "c": "f"})


if __name__ == '__main__':
    unittest.main()
