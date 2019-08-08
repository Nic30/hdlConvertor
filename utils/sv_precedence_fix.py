
"""
Utils for fixing of binary operator precedence in system verilog grammars
"""


def get_bin_op_precedence(symbol_names):
    # :note: left/right associativity is important only
    # for the operators from same priority group and 
    # ach operator is used in rule expr -> <term> (<op> <expr>)*
    # so we can resolve asociativity while parsing this array like expression
    symb_to_name = {v:k for k, v in symbol_names.items()}
    # sv 1800-2017 table 11-2 p. 257
    # () [] :: .
    # unary operators
    bin_op_precedence_groups = [
        s.split("") for s in [
            "**",
            "* / %",
            "+ -",
            "<< >> <<< >>>",
            "< <= > >= inside dist",
            "== != === !== ==? !=?",
            "&",
            "^ ~^ ^~",
            "|",
            "&&",
            "||",
            "?:",
            "-> <->",
        ]
    ]
    return [
        [ symb_to_name[s] for s in group ]
        for group in bin_op_precedence_groups 
    ]

