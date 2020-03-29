from hdlConvertor.hdlAst._statements import HdlStmIf, HdlStmBlock


def elifs_to_if_then_else(stm):
    """
    Optionaly create if-then-else without else-ifs from this if-then-else statement

    :type stm: HdlStmIf
    :note: non recursive
    """
    if stm.elifs:
        # replace elifs with nested if statements
        ifFalse = HdlStmBlock()
        topIf = HdlStmIf(stm.cond, stm.if_true, ifFalse)

        for c, stms in stm.elifs:
            _ifFalse = HdlStmBlock()

            lastIf = HdlStmIf(c, stms, _ifFalse)

            ifFalse.append(lastIf)
            ifFalse = _ifFalse

        if stm.if_false is None:
            lastIf.if_false = HdlStmBlock()
        else:
            lastIf.if_false = stm.if_false

        return topIf
    return stm
