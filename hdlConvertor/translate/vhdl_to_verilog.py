from hdlConvertor.hdlAst._structural import HdlContext, HdlModuleDef,\
    HdlModuleDec


def link_module_dec_def(context: HdlContext):
    objs = []
    last = None
    for o in context.objs:
        if isinstance(o, HdlModuleDef):
            assert isinstance(last, HdlModuleDec) \
                and o.module_name == last.name, (
                "Module body has to be behind the module header", last, o)
            last.body = o
        else:
            objs.append(o)
        last = o

    context.objs = objs
