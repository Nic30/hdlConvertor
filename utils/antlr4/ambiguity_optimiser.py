from utils.antlr4.query import Antlr4SyntCmp
from copy import copy
from utils.antlr4.grammar import Antlr4Symbol, Antlr4Sequence, Antlr4Selection, \
    Antlr4Rule, Antlr4Option
from utils.antlr4.longest_common_subsequence import longets_common_subsequence
from utils.antlr4.sequence_optimiser import _sequence_expand_optionality, \
    _is_optional


def is_non_lexical_nonterm(x):
    return not x.is_lexer_nonterminal()


def cut_off_subsequence(a, sub_seq):
    """
    :return: prefix, suffix
    """
    start = a.index(sub_seq[0])
    end = start + len(sub_seq)
    return Antlr4Sequence(a[:start]), Antlr4Sequence(a[end:])


def extract_common_from_sequences_from_part(
        part, prefix, suffix,
        extracted_rule_name,
        prefix_to_non_optional):
    part.clear()
    if prefix:
        prefix_choices = []
        prefix_optional = False
        for p in _sequence_expand_optionality(prefix):
            if p:
                prefix_choices.append(p)
            else:
                prefix_optional = True

        if len(prefix_choices) > 1:
            prefix_choices = Antlr4Selection(prefix_choices)
        else:
            prefix_choices = prefix_choices[0]

        if prefix_to_non_optional and prefix_optional:
            # because if the parts do not have different suffix
            # the prefix is there to distinguish between them
            prefix_choices = Antlr4Option(prefix_choices)

        part.append(prefix_choices)

    part.append(Antlr4Symbol(extracted_rule_name, False))
    if suffix:
        part.extend(suffix)

    
def extract_common_from_sequences(a: Antlr4Sequence, b: Antlr4Sequence, extracted_rule_name: str):
    """
    a b c0, a b c1 -> common c0, common c1, common: a b
    a b, (a)? a b  -> common, a common, common: a b
    a b, (a0)? (a1)? a b  -> common, (a0 (a1)? | a1) common, common: a b
    a b, c d ->  a b, c d, None
    a0 b, (a0 | a1) b -> common, common | a1 b, common: a0 b
    """
    common = longets_common_subsequence(a, b)
    if not common:
        return a, b, None
    return _extract_common_from_sequences(a, b, common, extracted_rule_name)


def _extract_common_from_sequences(a: Antlr4Sequence, b: Antlr4Sequence, common, extracted_rule_name: str):
    # try to find longes common sequence
    # if the sequence is more complex than 1 symbol
    # extract it to the new rule

    common_rule = Antlr4Sequence([x[0] for x in common])
    if len(common_rule) == 1:
        common_rule = common_rule[0]
    common_rule = Antlr4Rule(extracted_rule_name, common_rule)

    a_prefix, a_suffix = cut_off_subsequence(a, [x[0] for x in common])
    b_prefix, b_suffix = cut_off_subsequence(b, [x[1] for x in common])
    differs_in_suffix = a_suffix or b_suffix
    a_prefix_to_non_optional = not _is_optional(b_prefix) and not (differs_in_suffix)
    b_prefix_to_non_optional = not _is_optional(a_prefix) and not (differs_in_suffix)
    
    # if two sequences differs only in optional items
    # convert this items to non optinal variant 
    # (because the variant wihout this items is the extracted rule)
    extract_common_from_sequences_from_part(
        a, a_prefix, a_suffix, extracted_rule_name,
        a_prefix_to_non_optional)
    
    extract_common_from_sequences_from_part(
        b, b_prefix, b_suffix, extracted_rule_name,
        b_prefix_to_non_optional)
    return a, b, common_rule


def extract_common_from_selection(
        a: Antlr4Selection, b: Antlr4Selection,
        extracted_rule_name: str):
    """
    a | b, a | b | c -> common, common | c, common: a | b
    a | b | b0, a | b | c -> common | b0, common | c, common: a | b
    a | b , c | d -> a | b, c | d, None
    """
    raise NotImplementedError()


def extract_common_from_selection_and_sequence(
        a: Antlr4Selection, b:Antlr4Sequence,
        extracted_rule_name: str):
    assert isinstance(a, Antlr4Selection)
    assert isinstance(b, Antlr4Sequence)
    commons = []
    for i, c in enumerate(a):
        common = longets_common_subsequence(c, b)
        if common:
            commons.append((i, c, common))
    if not commons:
        return

    max_common = max(commons, key=lambda x: len(x[2]))
    _a, _b, common = _extract_common_from_sequences(
        max_common[1], b, max_common[2], extracted_rule_name)
    a[max_common[0]] = _a
    return a, _b, common


def extract_common_from_rule_clusters(
        rules, rule_map,
        new_cluster_name_extracted):
    """
    :param rule_map: names of rules which which coresponds to each other in 
    :param new_cluster_name_extracted: prefix for rules in extracted claster
    :note: if there is mapping of rule to same rule, the rule stays as it is
    :note: all used rules has to be in mapping
    """
    rule_dict = {r.name: r for r in rules}
    final_names = {}
    _rule_map = copy(rule_map)
    while rule_map:
        r_c0, r_c1 = rule_map.popitem()
        
        if r_c0 == r_c1:
            assert r_c0 not in final_names, r_c0
            final_names[r_c0] = r_c0
            continue
        
        r0 = rule_dict[r_c0]
        r1 = rule_dict[r_c1]
        eq_symbols = copy(_rule_map)
        s_eq = Antlr4SyntCmp().eq(
            r0.body, r1.body,
            eq_symbols=eq_symbols,
            can_rename=is_non_lexical_nonterm,
        )
        if s_eq:
            # same rule or just renamed symbols
            # make new rule for extracted cluster from r0 and delete r1
            new_name = new_cluster_name_extracted + r0.name 
            assert new_name not in final_names, new_name
            assert new_name not in final_names, new_name
            del rule_dict[r0.name]
            del rule_dict[r1.name]
            rules.remove(r1)
            final_names[r0.name] = new_name
            final_names[r1.name] = new_name
            r0.name = new_name
            rule_dict[new_name] = r0
        else:
            new_common_rule_name = new_cluster_name_extracted + r0.name
            if isinstance(r0.body, Antlr4Sequence):
                if isinstance(r1.body, Antlr4Sequence):
                    r0.body, r1.body, common = extract_common_from_sequences(
                        r0.body, r1.body, new_common_rule_name)
                elif isinstance(r1.body, Antlr4Selection):
                    r1.body, r0.body, common = extract_common_from_selection_and_sequence(
                        r1.body, r0.body, new_common_rule_name)
                else:
                    raise NotImplementedError()

            elif isinstance(r0.body, Antlr4Selection):
                if isinstance(r1.body, Antlr4Sequence):
                    r0.body, r1.body, common = extract_common_from_selection_and_sequence(
                        r0.body, r1.body, new_common_rule_name)
                elif isinstance(r1.body, Antlr4Selection):
                    r0.body, r1.body, common = extract_common_from_selection(
                        r0.body, r1.body, new_common_rule_name)
                else:
                    raise NotImplementedError()

            else:    
                raise NotImplementedError()

            if common is not None:
                rules.insert(rules.index(r0), common)
            
            ncrn = Antlr4Symbol(new_common_rule_name, False)
            if r0.body == ncrn or (len(r0.body) == 1 and r0.body[0] == ncrn):
                rules.remove(r0)
                final_names[r0.name] = new_common_rule_name
            if r1.body == ncrn or (len(r1.body) == 1 and r1.body[0] == ncrn):
                rules.remove(r1)
                final_names[r1.name] = new_common_rule_name

        # try find all completly same rules (depends on resolved symbols or on them selfs
        # and have same structure, and may have only renamed symbols)
        # and extract them while deleting all variants from 0./1. cluster
        
        # if rule difers in structure or rule using the symbol which has to be different in all clusters
        # if rules have something common extract it to newly created cluster
        # for cluster in cluster 0./1. check generate a specialized rule if required
    def update_names(obj):
        if isinstance(obj, Antlr4Symbol):
            new_name = final_names.get(obj.symbol, None)
            if new_name is None or new_name == obj.symbol:
                return
            
            obj.symbol = new_name

    for r in rules:
        r.body.walk(update_names)
