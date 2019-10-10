from copy import copy
from itertools import islice
from typing import Dict, List, Set

from utils.antlr4.grammar import iAntlr4GramElem, Antlr4Symbol, Antlr4Option, \
    Antlr4Iteration, Antlr4Selection, Antlr4Sequence, Antlr4Rule
from utils.antlr4.left_recurse_remove import transitive_closure


def collect_dependencies_in_parser(rules: List[Antlr4Rule]) -> Dict[str, Set[str]]:
    """
    :attention: ignore dependencies on lexer tokens
    """
    deps = {}
    for r in rules:
        if r.is_lexer_rule():
            continue

        _deps = set()

        def find_deps(o):
            if isinstance(o, Antlr4Symbol) and not o.is_lexer_nonterminal():
                _deps.add(o.symbol)

        r.walk(find_deps)
        deps[r.name] = _deps

    return deps


def find_parser_claster(rules, start_rule_name):
    """
    Find all rules which can be used by this rule
    """
    deps = collect_dependencies_in_parser(rules)
    deps = transitive_closure(deps)
    
    return deps[start_rule_name]


def find_dependet_on(rules, rule_name):
    deps = collect_dependencies_in_parser(rules)
    deps = transitive_closure(deps)
    return set([k for k, v in deps.items() if rule_name in v])


class Antlr4SyntCmp():
    """
    Compare expressions and allow symbols to be renamed in other sequence
    """

    def __init__(self):
        self.eq_symbols = {}
        self.can_rename = lambda x: True
    
    def _eq(self, a, b):
        if type(a) != type(b):
            return False
        if isinstance(a, Antlr4Symbol):
            a_replace = self.eq_symbols.get(a.symbol, None)
            if a_replace is None:
                if (not self.can_rename(a) or not self.can_rename(b)) and a.symbol != b.symbol:
                    return False
                self.eq_symbols[a.symbol] = b.symbol
                return True
            if a_replace == b.symbol:
                return True
            
            return False 
        if isinstance(a, Antlr4Iteration):
            if a.positive != b.positive:
                return False
            else:
                return self._eq(a.body, b.body)
        elif isinstance(a, Antlr4Option):
            return self._eq(a.body, b.body)
        elif isinstance(a, (Antlr4Sequence, Antlr4Selection)):
            if len(a) != len(b):
                return False
            else:
                for _a, _b in zip(a, b):
                    if not self._eq(_a, _b):
                        return False
                return True
        else:
            raise NotImplementedError(a.__class__)

    def eq(self, a, b, eq_symbols=None, can_rename=lambda x: True):
        self.can_rename = can_rename
        if eq_symbols is not None:
            self.eq_symbols = eq_symbols
        else:
            self.eq_symbols.clear()
        return self._eq(a, b)


class Antlr4Query():
    """
    Search all sub expressions whith are equviavalent with a pattern
    
    :attention: if pattern is sequence the items may be found separately in match and match of this pattern
        sequence may not be in result match as the matched sequence is inlined in something
    """

    def __init__(self, pattern):
        self.pattern = pattern
        
    def match(self, obj) -> List[Dict[int, iAntlr4GramElem]]:
        """
        :return: list of matches where match is dict {obj id: pattern obj}
        """
        matches = []
        self._match(obj, self.pattern, {}, matches)
        return matches

    def _match(self, obj, pattern, current_match, matches):
        if obj == pattern:
            current_match[id(obj)] = pattern
            if pattern is self.pattern:
                matches.append(current_match)
            return current_match, True

        if self.pattern is not pattern:
            # the pattern does not match 
            return current_match, False
        
        # now we are deciding if we should search pattern inside of obj    
        if isinstance(obj, Antlr4Symbol):
            return current_match, False
        if isinstance(obj, (Antlr4Option, Antlr4Iteration)):
            return self._match(obj.body, pattern, current_match, matches)
        elif isinstance(obj, Antlr4Selection):
            # try to find in any sub option
            for o in obj:
                m = copy(current_match)
                self._match(o, pattern, m, matches)
            return current_match, False
        elif isinstance(obj, Antlr4Sequence):
            if isinstance(pattern, Antlr4Sequence):
                # try to find sub sequence
                assert len(pattern) > 0
                if len(obj) > len(pattern):
                    offset = 0
                    while offset < len(obj) - len(pattern) + 1:
                        m = copy(current_match)
                        all_matches = True
                        for p, o in zip(pattern, islice(obj, offset, None)):
                            _, does_match = self._match(o, p, m, matches)
                            if not does_match:
                                all_matches = False
                                break

                        if all_matches:
                            matches.append(m)
                            offset += len(pattern)
                        else:
                            offset += 1

            # try to find in any item
            for o in obj:
                m = copy(current_match)
                self._match(o, pattern, m, matches)
            return current_match, False

