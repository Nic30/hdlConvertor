from copy import copy
from itertools import islice
from typing import Dict, List

from utils.antlr4.grammar import iAntlr4GramElem, Antlr4Symbol, Antlr4Option, \
    Antlr4Iteration, Antlr4Selection, Antlr4Sequence, iter_non_visuals


class Antlr4Query():

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
                _obj = list(iter_non_visuals(obj))
                _pattern = list(iter_non_visuals(pattern))
                assert len(_pattern) > 0
                if len(_obj) > len(_pattern):
                    offset = 0
                    while offset < len(_obj) - len(_pattern) + 1:
                        m = copy(current_match)
                        all_matches = True
                        for p, o in zip(_pattern, islice(_obj, offset, None)):
                            _, does_match = self._match(o, p, m, matches)
                            if not does_match:
                                all_matches = False
                                break

                        if all_matches:
                            matches.append(m)
                            offset += len(_pattern)
                        else:
                            offset += 1

            # try to find in any item
            for o in obj:
                m = copy(current_match)
                self._match(o, pattern, m, matches)
            return current_match, False

