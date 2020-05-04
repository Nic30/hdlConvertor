from hdlConvertor.hdlAst._structural import HdlContext, HdlModuleDef,\
    HdlModuleDec
from hdlConvertor.hdlAst._expr import HdlValueId


def link_module_dec_def(context):
    """
    :type context: HdlContext
    """
    objs = []
    last = None
    for o in context.objs:
        if isinstance(o, HdlModuleDef) and o.dec is None:
            assert isinstance(last, HdlModuleDec) \
                and o.module_name == HdlValueId(last.name), (
                "Module body has to be behind the module header", last, o)
            o.dec = last
            objs.append(o)
            last = None
        else:
            if last is not None:
                objs.append(last)
            last = o
    if last is not None:
        objs.append(last)

    context.objs = objs
