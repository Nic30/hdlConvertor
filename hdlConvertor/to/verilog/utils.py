from hdlConvertor.hdlAst import HdlName, HdlCall, HdlBuiltinFn
from hdlConvertor.hdlAst._expr import HdlTypeAuto


PRIMITIVE_TYPES = (
    HdlName("reg"),
    HdlName("wire"),
    HdlTypeAuto,
)

NULL = HdlName("null")


def collect_array_dims(t):
    array_dim = []
    while isinstance(t, HdlCall) and t.fn == HdlBuiltinFn.INDEX:
        array_dim.append(t.ops[1])
        t = t.ops[0]
    array_dim.reverse()
    return t, array_dim


def get_wire_t_params(t):
    """
    wire/reg type is actually stored as: t#(width, is_signed)
    This function extracts t, width, is_signed and potential array dimmensions
    if this type is an array.
    """
    t, array_dim = collect_array_dims(t)

    if t in PRIMITIVE_TYPES:
        return t, None, False, array_dim

    # 1b scala
    width = None
    is_signed = False
    if not isinstance(t, HdlName) or t not in PRIMITIVE_TYPES:
        if not isinstance(t, HdlCall) or t.fn != HdlBuiltinFn.PARAMETRIZATION:
            return None

        if t.ops[0] not in PRIMITIVE_TYPES:
            return None

        t, width, is_signed = t.ops
        if width == NULL:
            width = None
        if is_signed == NULL:
            is_signed = None
        else:
            is_signed = bool(is_signed)

    return t, width, is_signed, array_dim
