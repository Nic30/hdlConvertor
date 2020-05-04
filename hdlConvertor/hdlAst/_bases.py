from typing import Union, List


try:
    # python2
    from StringIO import StringIO
except ImportError:
    # python3
    from io import StringIO


class iHdlObj(object):
    """
    Object with direct representation in HDL

    :ivar ~.doc: doc from the HDL related probably to this object
    :ivar ~.origin: an object which is responsible for this HdlObject
        (not used by this library, used in user code)
    """
    __slots__ = ["doc", "position", "origin"]

    def __init__(self):
        self.doc = ""  # type: str
        self.position = None  # type: Optional[CodePosition]
        self.origin = None

    def __repr__(self):
        from hdlConvertor.to.json_debug import ToJsonDebug
        from pprint import pprint
        to = ToJsonDebug()
        d = getattr(to, "visit_" + self.__class__.__name__)(self)
        s = StringIO()
        pprint(d, stream=s, depth=None)
        return s.getvalue()


class iHdlObjWithName(iHdlObj):
    """
    :ivar ~.name: reference to name of the object
    """
    __slots__ = ["name"]

    def __init__(self):
        super(iHdlObjWithName, self).__init__()
        self.name = None  # type: HdlValueId


class iHdlObjInModule(iHdlObj):
    """
    Object which can appear in the module body
    """
    __slots__ = []


class iHdlStatement(iHdlObjInModule):
    """
    :ivar ~.labels: list of labels, the first label is for this statement
        the others are for it's branches
    :ivar ~.in_preproc: if True the statement is VHDL generate
            or other different of type of statement which should be evaluated
            compile time (note that this correspond s to VHDL generate statements
            and not to Verilog preprocessor ifdefs as they are processed before
            Verilog code parsing and are not present in code read by parser
            in the first place)
    """
    __slots__ = ["labels", "in_prepoc"]

    def __init__(self):
        iHdlObjInModule.__init__(self)
        self.labels = []  # type: List[HdlValueId]
        self.in_prepoc = False  # type: bool
