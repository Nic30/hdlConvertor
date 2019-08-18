from copy import copy
from itertools import islice
from typing import Dict, List

from utils.antlr4.grammar import iAntlr4GramElem, Antlr4Symbol, Antlr4Option, \
    Antlr4Iteration, Antlr4Selection, Antlr4Sequence


class Antlr4SyntCmp():
    """
    Compare expressions and allow symbols to be renamed in other sequence
    """

    def __init__(self):
        self.eq_symbols = {}
    
    def _eq(self, a, b):
        if type(a) != type(b):
            return False
        if isinstance(a, Antlr4Symbol):
            a_replace = self.eq_symbols.get(a.symbol, None)
            if a_replace is None:
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
            raise NotImplementedError()

    def eq(self, a, b, eq_symbols=None):
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

