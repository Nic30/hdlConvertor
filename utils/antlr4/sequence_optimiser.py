from typing import Tuple

from utils.antlr4.grammar import Antlr4Sequence


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
