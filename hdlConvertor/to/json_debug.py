from hdlConvertor.to.json import ToJson
from hdlConvertor.hdlAst._bases import iHdlObj
from hdlConvertor.hdlAst._defs import HdlIdDef
from hdlConvertor.hdlAst._expr import HdlDirection


class ToJsonDebug(ToJson):
    """
    HdlConverto AST -> json (dict/list/str/int/None composed object)
    An ivalid object are converted to str using its __repr__()
    """
    def visit_HdlIdDef(self, o):
        try:
            return ToJson.visit_HdlIdDef(self, o)
        except Exception:
            if isinstance(o, HdlIdDef):
                raise
            return repr(o)

    def visit_HdlDirection(self, o):
        if not isinstance(o, HdlDirection):
            return repr(o)
        else:
            return super(ToJsonDebug, self).visit_HdlDirection(o)

    def visit_iHdlExpr(self, o):
        """
        :type o: iHdlExpr
        :return: iHdlExpr
        """
        try:
            return super(ToJsonDebug, self).visit_iHdlExpr(o)
        except Exception:
            if o.__class__.__repr__ is iHdlObj.__repr__:
                # in order to prevent infinite loop if there is something
                # wrong in serializer code itself
                raise
            return repr(o)


if __name__ == "__main__":
    import os
    from hdlConvertor.language import Language
    from hdlConvertor import HdlConvertor
    from pprint import pprint
    BASE_DIR = os.path.join(os.path.dirname(__file__), "..", "..")
    TEST_DIR = os.path.join(BASE_DIR, 'tests', 'verilog')
    c = HdlConvertor()
    filenames = [os.path.join(TEST_DIR, "arbiter_tb.v")]
    d = c.parse(filenames, Language.VERILOG, [], False, True)
    tv = ToJson()
    res = tv.visit_HdlContext(d)
    pprint(res)
