from utils.antlr4.optionality_optimiser import _option_reduce_option
from utils.antlr4.selection_optimiser import char_options_to_regex, \
    _selection_reduce_optional, _selection_empty_option_to_optional, \
    _selection_options_to_sequnces, _selection_share_suffix,\
    _selection_share_prefix, _selection_only_unique,\
    _selection_propagate_optionality, _selection_flatten
from utils.antlr4._utils import replace_item_by_sequence
from utils.antlr4.grammar import Antlr4Selection, Antlr4Option, Antlr4Sequence
from utils.antlr4.sequence_optimiser import _sequence_flatten


class Antlr4GenericOptimizer():
    """
    Apply common optimization to ANTL4 rules
    """
    def __init__(self):
        self.modified = False

    def match_replace_fn(self, o):
        if isinstance(o, Antlr4Selection):
            _selection_options_to_sequnces(o)
            optimizations = [
                _selection_only_unique,
                _selection_reduce_optional,
                _selection_empty_option_to_optional,
                _selection_share_prefix,
                _selection_share_suffix,
                _selection_propagate_optionality,
                _selection_flatten,
                ]
            for opt in optimizations:
                o, changed = opt(o)
                self.modified |= changed
                if changed or not isinstance(o, Antlr4Selection):
                    return o
            return None
        elif isinstance(o, Antlr4Option):
            o, changed = _option_reduce_option(o)
            self.modified |= changed
            if changed:
                return o
            else:
                return None
        elif isinstance(o, Antlr4Sequence):
            o, changed = _sequence_flatten(o)
            self.modified |= changed
            if changed:
                return o
    
    def optimize(self, rules):
            
        for r in rules:
            first = True
            while first or self.modified:
                self.modified = False
                first = False
                replace_item_by_sequence(r, self.match_replace_fn)

            if r.is_lexer_rule():
                char_options_to_regex(r)
