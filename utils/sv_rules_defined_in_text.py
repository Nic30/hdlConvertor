from antlr4grammar import Antlr4Rule, Antlr4Symbol, Antlr4Selection, \
    Antlr4Sequence, Antlr4Iteration, Antlr4Option


def add_string_literal_rules(p):
    string_char = Antlr4Rule("ANY_ASCII_CHARACTERS", Antlr4Selection([
        Antlr4Symbol('~["\\\\\\r\\n]', True, True),
        Antlr4Symbol('\\\n', True),
        Antlr4Symbol('\\\r\n', True),
        Antlr4Sequence([
            Antlr4Symbol("\\", True),
            Antlr4Symbol('[nt\\\\"vfa]', True, is_regex=True),
        ]),
        Antlr4Symbol("'\\\\' [0-9] [0-9]? [0-9]?", True, True),
        Antlr4Symbol("'\\\\' 'x' [0-9A-Fa-f] [0-9A-Fa-f]?", True, True),
        ]), is_fragment=True)
    p.rules.append(string_char)

    any_printable_ASCII_character_except_white_space = Antlr4Rule(
        "ANY_PRINTABLE_ASCII_CHARACTER_EXCEPT_WHITE_SPACE",
        Antlr4Symbol("'\\u0021'..'\\u007E'", True, True),
        is_fragment=True)
    p.rules.append(any_printable_ASCII_character_except_white_space)


def add_file_path_literal_rules(p):
    FILE_PATH_SPEC_CHAR = Antlr4Rule(
        "FILE_PATH_SPEC_CHAR",
        Antlr4Symbol(
            "[^ !$`&()+] | ( '\\\\' [ !$`&*()+] )",
            True, True),
        is_fragment=True)
    p.rules.append(FILE_PATH_SPEC_CHAR)

    file_spec_path = Antlr4Rule(
        "FILE_PATH_SPEC",
        Antlr4Iteration(Antlr4Sequence([
                Antlr4Symbol("FILE_PATH_SPEC_CHAR", False),
                Antlr4Option(Antlr4Sequence([
                    Antlr4Symbol('SEMI', False),
                    Antlr4Symbol("FILE_PATH_SPEC_CHAR", False),
                ])),
            ]),
            positive=True
        )
    )
    p.rules.append(file_spec_path)

