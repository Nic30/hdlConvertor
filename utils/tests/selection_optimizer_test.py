from itertools import islice
from typing import Tuple
import unittest
from unittest.runner import TextTestRunner
from unittest.suite import TestSuite

from utils.antlr4.grammar import Antlr4Selection, Antlr4Sequence, Antlr4Option,\
    Antlr4Rule
from utils.antlr4.simple_parser import Antlr4parser
from utils.antlr4.selection_optimiser import _selection_share_prefix,\
    _selection_empty_option_to_optional,\
    _selection_share_suffix, _selection_options_to_sequnces
from utils.antlr4.sequence_optimiser import _sequence_flatten
from utils.antlr4.generic_optimiser import Antlr4GenericOptimizer


    
class SelectionOptimizerTC(unittest.TestCase):

    def assertTextEq(self, a, b, msg=None):
        """
        Assert test equal, while ignoring whitespaces
        """
        trans = str.maketrans({
            " ": "",
            "\n": ""
            })
        a = a.translate(trans)
        b = b.translate(trans)
        
        self.assertEqual(a, b, msg=msg)

    def test_common_suffix_dual(self):
        r_str = "a c | b c | x0 y | x1 y"
        expec = "( a | b ) c | ( x0 | x1 ) y"
        r = Antlr4parser().from_str(r_str)
        res, _ = _selection_share_suffix(r)
        self.assertTextEq(expec, res.toAntlr4())

    def test_common_suffix(self):
        r_str = """
         x0 a b c
        | d
        | x1 ( x2 )? a b c
        """
        expected = """
        (
             x0 a b
            | x1 ( x2 )? a b
        ) c
        | d
        """
        r = Antlr4parser().from_str(r_str)
        _selection_options_to_sequnces(r)
        res, _ = _selection_share_suffix(r)
        self.assertTextEq(expected, res.toAntlr4())
    
    def test_common_prefix(self):
        r_str = """
        a ( b c d )? 
        | a b e
        | a b f 
        """
        expected0 = """
        a (
            ( b c d )? 
            | b e
            | b f
        ) 
        """
        expected1 = """
            ( b c d )? 
            | b ( e | f )
        """
        r = Antlr4parser().from_str(r_str)
        _selection_options_to_sequnces(r)
        res, _ = _selection_share_prefix(r)
        self.assertTextEq(expected0, res.toAntlr4())

        res, _ = _selection_share_prefix(res[1])
        self.assertTextEq(expected1, res.toAntlr4())

    def test_common_prefix_empty(self):
        r_str = "a | a b"
        expec = "a ( | b )"
        r = Antlr4parser().from_str(r_str)
        _selection_options_to_sequnces(r)
        res, _ = _selection_share_prefix(r)
        self.assertTextEq(expec, res.toAntlr4())

    def test_sequence_flatten(self):
        r_str = "a b c ( d e f ) ( ) ( g ) ( h | i )"
        expec = "a b c d e f g ( h | i )"
        r = Antlr4parser().from_str(r_str)
        res, _ = _sequence_flatten(r)
        self.assertTextEq(expec, res.toAntlr4())

    def test_empty_option_to_optional_selection(self):
        r_str = "a | | c"
        expec = "( a | c )?"
        r = Antlr4parser().from_str(r_str)
        _selection_options_to_sequnces(r)
        res, _ = _selection_empty_option_to_optional(r)
        self.assertTextEq(expec, res.toAntlr4())

    def test_optimize0(self):
        # data_type rule
        r_str = """
            a ( b )? ( c )* 
             | d ( b )? 
             | e 
             | f ( kw0 ( b )? )? kw1 f0 ( f0 )* kw2 ( c )* 
             | kw3 ( a0 )? kw1 a1 ( kw4 a1 )* kw2 ( c )* 
             | kw5 
             | kw6 
             | kw7 ( kw8 )? a2 ( a3 )? ( kw8 a2 )? 
             | ( a4 | a5 )? a2 ( c )* 
             | a6
             | kw9 
             | a7
             | a8
        """
        exp0 = """
             ( a ( b )? 
               | f ( kw0 ( b )? )? kw1 f0 ( f0 )* kw2
               | kw3 ( a0 )? kw1 a1 ( kw4 a1 )* kw2
               | ( a4 | a5 )? a2
             ) ( c )* 
             | d ( b )? 
             | e 
             | kw5 
             | kw6 
             | kw7 ( kw8 )? a2 ( a3 )? ( kw8 a2 )? 
             | a6
             | kw9 
             | a7
             | a8
        """ 
        r = Antlr4parser().from_str(r_str)
        _selection_options_to_sequnces(r)
        res, _ = _selection_share_suffix(r)
        self.assertTextEq(exp0, res.toAntlr4())
        
        exp1 = """
            a ( b )?
            | ( f ( kw0 ( b )? )? kw1 f0 ( f0 )*
                | kw3 ( a0 )? kw1 a1 ( kw4 a1 )* 
              ) kw2
            | ( a4 | a5 )? a2
        """
        _selection_options_to_sequnces(r[0][0])
        res, _ = _selection_share_suffix(r[0][0])
        self.assertTextEq(exp1, res.toAntlr4())
        exp2 = """
             ( a ( b )?
              | ( f ( kw0 ( b )? )? kw1 f0 ( f0 )*
                  | kw3 ( a0 )? kw1 a1 ( kw4 a1 )* 
                ) kw2
              | ( a4 | a5 )? a2
             ) ( c )* 
             | d ( b )? 
             | e 
             | kw5 
             | kw6 
             | kw7 ( kw8 )? a2 ( a3 )? ( kw8 a2 )? 
             | a6
             | kw9 
             | a7
             | a8
        """ 
        r = Antlr4parser().from_str(r_str)
        Antlr4GenericOptimizer().optimize([Antlr4Rule("tmp", r), ])
        self.assertTextEq(exp2, r.toAntlr4())


if __name__ == '__main__':
    suite = TestSuite()
    # suite.addTest(SelectionOptimizerTC('test_p584'))
    
    suite.addTest(unittest.makeSuite(SelectionOptimizerTC))

    runner = TextTestRunner(verbosity=3)
    runner.run(suite)
