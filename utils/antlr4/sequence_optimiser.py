from copy import deepcopy
from typing import Tuple

from utils.antlr4.grammar import Antlr4Sequence, Antlr4Option, Antlr4Iteration, \
    Antlr4Selection
from itertools import islice


def _is_optional(o):
    if isinstance(o, Antlr4Option) or (
        isinstance(o, Antlr4Iteration) and not o.positive):
        return True
    elif isinstance(o, Antlr4Sequence):
        for x in o:
            if _is_optional(x):
                continue
            else:
                return False
        return True
    elif isinstance(o, Antlr4Selection):
        for x in o:
            if _is_optional(x):
                return True
            else:
                continue

        return len(o) == 0
    return False


def _to_non_optional(o):
    """
    Create non optional variant of element (a)? -> a  and (a)* -> (a)+
    """
    if isinstance(o, Antlr4Option):
        return deepcopy(o.body)
    elif isinstance(o, Antlr4Iteration):
        o = deepcopy(o)
        o.positive = True
        return o
    else:
        raise TypeError(o.__class__)


def _sequence_flatten(seq: Antlr4Sequence) -> Tuple[Antlr4Sequence, bool]:
    """
    Inline subsequences
    """
    sequences = []
    for i, e in enumerate(seq):
        if isinstance(e, Antlr4Sequence):
            sequences.append((i, e))
    
    offset = 0
    for i0, e0 in sequences:
        first = True
        for i1, e1 in enumerate(e0):
            i = offset + i0 + i1
            if first:
                assert seq[i] is e0 
                seq[i] = e1
                first = False
            else:
                seq.insert(i, e1)
        if not e0:
            del seq[offset + i0]
        offset += len(e0) - 1 
    changed = bool(sequences)
    return seq, changed


def _sequence_expand_optionality(obj):
    """
    (a0)? (a1)* b -> a0 (a1)* b, (a1)+ b
    (a0)? -> a0, eps

    :attention: only prefix is expanded, if first non optional item is met the expansion ends
    """
    variant_sequences = []
    is_last = False
    for i, o in enumerate(obj):
        if not _is_optional(o):
            variant_sequences.append(Antlr4Sequence([deepcopy(x) for x in obj[i:]]))
            break

        o = _to_non_optional(o)
        is_last = i == len(obj) - 1
        if is_last:
            no = o
        else:
            no = Antlr4Sequence([o, ] + [deepcopy(x) for x in obj[i + 1:]])
        variant_sequences.append(no)

    if is_last:
        variant_sequences.append(Antlr4Sequence([]))
        
    return variant_sequences


def _sequence_extract_positive_iterations(obj):
    """
    a b c ( b c )* -> a ( b c )+
    """
    assert isinstance(obj, Antlr4Sequence)
    found = []
    for i, e in enumerate(obj):
        if isinstance(e, Antlr4Iteration):
            body = e.body
            if isinstance(e.body, Antlr4Sequence):
                body_len = len(e.body)
            else:
                body_len = 1
                body = [body, ]
            if e.positive or i < body_len:
                continue
            prev_items_same_as_body = True
            prev_items = islice(obj, i - body_len, None)
            for e2, e3 in zip(prev_items, body):
                if not e2.eq_relaxed(e3):
                    prev_items_same_as_body = False
                    break
            if prev_items_same_as_body:
                found.append((i, body_len, e))
    
    offset = 0
    for i, body_len, e in found:
        del obj[i + offset - body_len:i + offset]
        e.positive = True
        offset -= body_len
    
    if len(obj) == 1:
        obj = obj[0]
    
    return obj, bool(found)
    
