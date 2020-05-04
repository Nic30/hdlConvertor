from hdlConvertor.hdlAst import HdlValueId, HdlOp, HdlOpType
from hdlConvertor.hdlAst._expr import HdlTypeAuto


PRIMITIVE_TYPES = (
    HdlValueId("reg"),
    HdlValueId("wire"),
    HdlValueId("bit"),
    HdlValueId("logic"),
    HdlValueId("signed"),
    HdlValueId("unsigned"),
    HdlTypeAuto,
)

NULL = HdlValueId("null")


def collect_array_dims(t):
    array_dim = []
    while isinstance(t, HdlOp) and t.fn == HdlOpType.INDEX:
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
        is_signed = None
        if t == HdlValueId("signed"):
            is_signed = True
        elif t == HdlValueId("unsigned"):
            is_signed = False
        return t, None, is_signed, array_dim

    # 1b scala
    if not isinstance(t, HdlOp) or t.fn != HdlOpType.PARAMETRIZATION or len(t.ops) != 3:
        return None

    if t.ops[0] not in PRIMITIVE_TYPES:
        return None

    t, width, is_signed = t.ops
    if width == NULL:
        width = None
    if is_signed is None:
        is_signed = None
    else:
        is_signed = bool(is_signed)

    return t, width, is_signed, array_dim
