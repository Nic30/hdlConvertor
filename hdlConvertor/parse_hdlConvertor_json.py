import json

from hdlConvertor import hdlAst
from hdlConvertor.hdlAst import HdlContext, CodePosition, HdlBuiltinFn,\
    HdlDirection, HdlStmBlockJoinType
from hdlConvertor.py_ver_compatibility import is_str


KNOWN_NODES = {
    cls_name: getattr(hdlAst, cls_name)
    for cls_name in dir(hdlAst) if cls_name.startswith("Hdl")
}


def _parse_hdlConvertor_json(j):
    # handle primitive types
    if j is None:
        return j
    elif isinstance(j, (int, float)) or is_str(j):
        return j
    elif isinstance(j, list):
        return [_parse_hdlConvertor_json(_j) for _j in j]

    # load a hdlAst object
    cls = j["__class__"]
    cls = KNOWN_NODES[cls]
    consumed = {"__class__", }
    argc = cls.__init__.__code__.co_argcount
    if argc == 1:
        o = cls()
    else:
        # load argumets for __init__
        argv = []
        # 1st is self
        arg_names = cls.__init__.__code__.co_varnames[1:argc]
        for a in arg_names:
            v = j.get(a, None)
            if a == "fn":
                v = getattr(HdlBuiltinFn, v)
            else:
                v = _parse_hdlConvertor_json(v)
            argv.append(v)
            consumed.add(a)
        o = cls(*argv)

    if len(consumed) != len(j):
        # load rest of the properties which were not in __init__ params
        for k, v in j.items():
            if k in consumed:
                continue
            # there are few cases where object class is not specified specified
            # explicitely we have to handle them first
            if k == "position":
                _v = CodePosition()
                (
                    _v.start_line,
                    _v.start_column,
                    _v.stop_line,
                    _v.stop_column
                ) = v
            elif k == "direction":
                _v = getattr(HdlDirection, v)
            elif k == "join_t":
                _v = getattr(HdlStmBlockJoinType, v)
            else:
                _v = _parse_hdlConvertor_json(v)
            setattr(o, k, _v)

    return o


def parse_hdlConvertor_json(j):
    """
    Convert loaded json (structure composed of list, dict, str, int, float, None)

    :return: HdlContext
    """
    assert isinstance(j, list), j
    ctx = HdlContext()
    for jo in j:
        o = _parse_hdlConvertor_json(jo)
        ctx.objs.append(o)
    return ctx


def parse_hdlConvertor_json_str(j_str):
    j = json.loads(j_str)
    return parse_hdlConvertor_json(j)


def parse_hdlConvertor_json_file(file_name):
    with open(file_name) as f:
        j = json.load(f)
        return parse_hdlConvertor_json(j)


if __name__ == "__main__":
    import os
    f_name = os.path.join(os.path.dirname(__file__), "..",
                          "tests", "json", "dff_async_reset.json")
    print(parse_hdlConvertor_json_file(f_name))
