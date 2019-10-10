from copy import deepcopy

from utils.antlr4.grammar import Antlr4Symbol, Antlr4LexerAction, rule_by_name, \
    iAntlr4GramElem, Antlr4Rule
from utils.sv.rule2Antlr4Rule import SvRule2Antlr4Rule


def replace_rule(rule_name, replace_rule_name, names_to_replace, parser):
    parser.rules = [p for p in parser.rules if p.name != rule_name]
    names_to_replace[rule_name] = replace_rule_name


def mark_regex(obj: iAntlr4GramElem):
    if isinstance(obj, Antlr4Symbol) and obj.symbol in [
            '[a-zA-Z_]', '[a-zA-Z0-9_$]', '[a-zA-Z0-9_]']:
        obj.is_regex = True


def collect_keywords(rules):
    keywords = set()

    def _collect_keywords(obj):
        if isinstance(obj, Antlr4Symbol) and obj.is_terminal:
            s = obj.symbol
            keywords.add(s)

    for r in rules:
        if not r.is_lexer_rule():
            r.walk(_collect_keywords)
    return keywords


def extract_keywords_to_specific_rule(p: SvRule2Antlr4Rule):
    keywords = collect_keywords(p.rules)

    def get_kw_name(k):
        return "KW_" + k.replace("$", "DOLAR_").upper()

    def renamer(obj: iAntlr4GramElem):
        if isinstance(obj, Antlr4Symbol) and obj.is_terminal\
                and obj.symbol in keywords:
            obj.is_terminal = False
            obj.symbol = get_kw_name(obj.symbol)

    for r in p.rules:
        if not r.is_lexer_rule():
            r.walk(renamer)

    for k in sorted(keywords):
        kw_name = get_kw_name(k)
        kw_rule = Antlr4Rule(kw_name, Antlr4Symbol(k, True))
        p.rules.append(kw_rule)
        # if not re.match("^[A-Za-z0-9_]*$", k):
        #    print(k)
    return keywords


def get_all_used_lexer_tokens(rules, rule_name):
    tokens = set()
    seen = set()
    used_parser_rules = {rule_name, }

    def walk(obj: iAntlr4GramElem):
        if isinstance(obj, Antlr4Symbol) and not obj.symbol in seen:
            if obj.is_lexer_nonterminal():
                tokens.add(obj.symbol)
            elif not obj.is_terminal:
                used_parser_rules.add(obj.symbol)

    while used_parser_rules:
        r_name = used_parser_rules.pop()
        r = rule_by_name(rules, r_name)
        seen.add(r.name)
        r.walk(walk)

    return tokens


def wrap_in_lexer_mode(rules, mode_name, enter_tokens, exit_tokens, tokens, shared_tokens):
    for enter_token in enter_tokens:
        enter_rule = rule_by_name(rules, enter_token)
        enter_rule.lexer_actions.append(Antlr4LexerAction.pushMode(mode_name))

    for t_name in sorted(tokens.union(shared_tokens)):
        t_rule = rule_by_name(rules, t_name)
        if t_name in shared_tokens:
            # copy the rule
            # translate mode specific token to a original token
            actions = deepcopy(t_rule.lexer_actions)
            if not Antlr4LexerAction.skip() in actions:
                actions.append(Antlr4LexerAction.type(t_name))
            mode_specific_t_rule = Antlr4Rule(
                mode_name + "_" + t_name, deepcopy(t_rule.body),
                lexer_mode=mode_name,
                lexer_actions=actions
            )
            rules.append(mode_specific_t_rule)
            t_rule = mode_specific_t_rule

        t_rule.lexer_mode = mode_name
        if t_name in sorted(exit_tokens):
            t_rule.lexer_actions.append(Antlr4LexerAction.popMode())


def pretify_regex(rules):

    def _pretify_regex(o):
        if isinstance(o, Antlr4Symbol) and o.is_regex:
            for orig, repl in [
                    ("0123456789", "0-9"),
                    ("01234567", "0-7"),
                    ("123456789", "1-9"),
                    ("abcdef", "a-f"),
                    ("ABCDEF", "A-F"),
                    ]:
                o.symbol = o.symbol.replace(orig, repl)

    for r in rules:
        if r.is_lexer_rule():
            r.walk(_pretify_regex)
