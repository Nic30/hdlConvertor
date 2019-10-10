import unittest
from unittest.case import expectedFailure

from utils.antlr4.ambiguity_optimiser import extract_common_from_rule_clusters, \
    extract_common_from_sequences
from utils.antlr4.grammar import Antlr4Rule, iAntlr4GramElem
from utils.antlr4.selection_optimiser import _selection_options_to_sequnces
from utils.antlr4.simple_parser import Antlr4parser
from utils.antlr4.generic_optimiser import Antlr4GenericOptimizer


def p(s):
    return Antlr4parser().from_str(s)


def rule_from_str(rule_str):
    name, body = rule_str.split(":")
    return Antlr4Rule(name.strip(), Antlr4parser().from_str(body))


def rules_from_str(rules_str):
    rules = [rule_from_str(r) for r in rules_str.split(";") if r.strip()]
    return rules


class AmbiguityOptimiserTC(unittest.TestCase):

    def assertTextEq(self, a, b, msg=None):
        """
        Assert test equal, while ignoring whitespaces
        """
        trans = str.maketrans({
            " ": "",
            "\n": ""
        })

        if isinstance(a, iAntlr4GramElem):
            a = a.toAntlr4()

        if isinstance(b, iAntlr4GramElem):
            b = b.toAntlr4()

        a = a.translate(trans)
        b = b.translate(trans)
        
        self.assertEqual(a, b, msg=msg)

    def assertSameRules(self, rules, rules_str):
        gold_rules = rules_from_str(rules_str)
        self.assertEqual(len(rules), len(gold_rules))
        for a, b in zip(rules, gold_rules):
            self.assertTextEq(a, b)
        
    def test_same(self):
        rules = rules_from_str("""
            a: b c;
            d: b c;
            g: b0 c0;
            h: a d b c;
            """)
        
        rule_map = {
            "a": "d",
            "b": "b",
            "c": "c"
        }
        extract_common_from_rule_clusters(rules, rule_map, "new_")

        self.assertEqual(3, len(rules))
        self.assertTextEq(rules[0], "new_a: b c;")
        self.assertTextEq(rules[1], "g: b0 c0;")
        self.assertTextEq(rules[2], "h: new_a new_a b c;")

    def test_extract_common_from_sequences0(self):
        """
        a b c0, a b c1 -> common c0, common c1, common: a b
        """
        a, b, c = extract_common_from_sequences(
            p("a b c0"), p("a b c1"), "common")
        self.assertTextEq(a, "common c0")
        self.assertTextEq(b, "common c1")
        self.assertTextEq(c, "common: a b;")

    def test_extract_common_from_sequences1(self):
        """
        a b, (a)? a b  -> common, a common, common: a b
        """
        a, b, c = extract_common_from_sequences(
            p("a b"), p("( a )? a b"), "common")
        self.assertTextEq(a, "common")
        self.assertTextEq(b, "a common")
        self.assertTextEq(c, "common: a b;")

    def test_extract_common_from_sequences2(self):
        """
        a b, (a0)? (a1)? a b  -> common, (a0 (a1)? | a1) common, common: a b
        """
        a, b, c = extract_common_from_sequences(
            p("a b"), p("( a0 )? ( a1 )? a b"), "common")
        self.assertTextEq(a, "common")
        self.assertTextEq(b, "( a0 ( a1 )? | a1 ) common")
        self.assertTextEq(c, "common: a b;")

    def test_extract_common_from_sequences3(self):
        """
        a b, c d ->  a b, c d, None
        """
        a, b, c = extract_common_from_sequences(
            p("a b"), p("c d"), "common")
        self.assertTextEq(a, "a b")
        self.assertTextEq(b, "c d")
        self.assertIs(c, None)

    @expectedFailure
    def test_extract_common_from_sequences4(self):
        """
        a0 b, (a0 | a1) b -> common, common | a1 b, common: a0 b
        """
        a, b, c = extract_common_from_sequences(
            p("a0 b"), p("( a0 | a1 ) b"), "common")
        self.assertTextEq(a, "common")
        self.assertTextEq(b, "common | a1 b")
        self.assertIs(c, "common: a0 b")

    def test_same_transitive(self):
        rules = rules_from_str("""
            a: a_tmp b;
            a_tmp: b c;
            d: d_tmp b;
            d_tmp: b c;
            g: b0 c0;
            h: a d b c;
            """)
        
        rule_map = {
            "a": "d",
            "a_tmp": "d_tmp",
            "b": "b",
            "c": "c",
        }
        extract_common_from_rule_clusters(rules, rule_map, "new_")

        self.assertEqual(4, len(rules), rules)
        self.assertTextEq(rules[0], "new_a: new_a_tmp b;")
        self.assertTextEq(rules[1], "new_a_tmp: b c;")
        self.assertTextEq(rules[2], "g: b0 c0;")
        self.assertTextEq(rules[3], "h: new_a new_a b c;")

    def test_extra_option(self):
        rules = rules_from_str("""
            a: b c | c1;
            d: b c;
            g: b0 c0;
            h: a d b c;
            """)
        
        rule_map = {
            "a": "d",
            "b": "b",
            "c": "c",
            "c1": "c1",
        }
        _selection_options_to_sequnces(rules[0].body)
        extract_common_from_rule_clusters(rules, rule_map, "new_")
        
        self.assertEqual(4, len(rules))
        self.assertTextEq(rules[0], "new_a: b c;")
        self.assertTextEq(rules[1], "a: new_a | c1;")
        self.assertTextEq(rules[2], "g: b0 c0;")
        self.assertTextEq(rules[3], "h: a new_a b c;")
    
    def test_const_non_const_expr(self):
        rules = rules_from_str("""
            e: e1 ( ( LT | GT ) e )*;
            e1: e0 ( ( PLUS | MINUS ) e1 )*;
            e0: p ( ( MUL | DIV ) e0 )*;
            p: LP e RP
                  | INT
                  | ( INCR | DECR )? ID;
            c_e: c_e1 ( ( LT | GT ) c_e )*;
            c_e1: c_e0 ( ( PLUS | MINUS ) c_e1 )*;
            c_e0: c_p ( ( MUL | DIV ) c_e0 )*;
            c_p: LP c_e RP
                  | INT
                  | ID;                  
        """)
        expected = """
        e: gen_e | e1 ( ( LT | GT ) e )*;
        gen_e: gen_e1 ( ( LT | GT ) gen_e )*;

        e1: gen_e1 | e0 ( ( PLUS | MINUS ) e1 )*;
        gen_e1: gen_e0 ( ( PLUS | MINUS ) gen_e1 )*;

        e0: gen_e0 | p ( ( MUL | DIV ) e0 )*;
        gen_e0: gen_p ( ( MUL | DIV ) gen_e0 )*;

        p: gen_p
            | LP e RP
            | ( INCR | DECR ) ID;
        gen_p: LP gen_e RP
            | INT
            | ID;

        c_e: gen_e;
        c_e1: gen_e1;
        c_e0: gen_e0;
        c_p: gen_p;
        """
        
        rule_map = {
            "e": "c_e",
            "e0": "c_e0",
            "e1": "c_e1",
            "e2": "c_e2",
            "p": "c_p",
        }
        for t in ["GT", "LT", "PLUS", "MINUS", "MUL", "DIV",
                  "LP", "RP", "INCR", "DECR", "INT", "ID", ]:
            rule_map[t] = t

        Antlr4GenericOptimizer().optimize(rules)
        extract_common_from_rule_clusters(rules, rule_map, "gen_")
        
        self.assertSameRules(rules, expected)
        

if __name__ == '__main__':
    suite = unittest.TestSuite()
    suite.addTest(AmbiguityOptimiserTC('test_const_non_const_expr'))
    # suite.addTest(unittest.makeSuite(AmbiguityOptimiserTC))

    runner = unittest.TextTestRunner(verbosity=3)
    runner.run(suite)
