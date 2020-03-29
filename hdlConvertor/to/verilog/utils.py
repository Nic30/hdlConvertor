from hdlConvertor.hdlAst import HdlName, HdlCall, HdlBuiltinFn


PRIMITIVE_TYPES = {
    HdlName("reg"),
    HdlName("wire")
}


def collect_array_dims(t):
    array_dim = []
    prev_t = t
    while isinstance(t, HdlCall) and t.fn == HdlBuiltinFn.INDEX:
        array_dim.append(t.ops[1])
        prev_t = t
        t = t.ops[0]
    if array_dim:
        if (isinstance(t, HdlName) and t in PRIMITIVE_TYPES) \
            or (isinstance(t, HdlCall)
                and t.fn == HdlBuiltinFn.PARAMETRIZATION
                and t.ops[0] in PRIMITIVE_TYPES):
            # this dimensions is actually size of the vector
            array_dim.pop()
            t = prev_t
        array_dim.reverse()
    return t, array_dim


def get_wire_t_params(t):

    t, array_dim = collect_array_dims(t)

    if t == HdlName('wire') or t == HdlName('reg'):
        return t, None, False, array_dim

    if isinstance(t, HdlCall) and t.fn == HdlBuiltinFn.INDEX:
        width = t.ops[1]
        t = t.ops[0]

    is_signed = False
    if not isinstance(t, HdlName) or t not in PRIMITIVE_TYPES:
        if not isinstance(t, HdlCall) or t.fn != HdlBuiltinFn.PARAMETRIZATION:
            return None

        if t.ops[0] != HdlName('wire') and t.ops != HdlName('reg'):
            return None

        _, is_signed = t.ops
        t = t.ops[0]

    is_signed = bool(is_signed)

    if width == 1:
        width = None

    return t, width, is_signed, array_dim
