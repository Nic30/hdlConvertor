#from libc cimport errno,string

from libc.string cimport strerror
from libc.errno cimport errno
from libcpp cimport bool
from libcpp cimport string
from cpython.ref cimport PyObject
from cpython.version cimport PY_MAJOR_VERSION
from convertor cimport Context, VHDL, VERILOG, SYSTEM_VERILOG, Convertor as _Convertor

class parseException(Exception):
    pass

cdef public PyObject * parseExceptionerror = <PyObject*> parseException

cdef class hdlConvertor:
    cdef _Convertor * thisptr

    def __cinit__(self):
        self.thisptr = new _Convertor()
    
    def __dealloc__(self):
        del self.thisptr

    def parse(self,filename,langue,incdir,hierarchyOnly,debug):

        cdef Context* c
        if langue == "verilog":
            langue_value = VERILOG
        elif langue == "vhdl":
            langue_value = VHDL
        elif langue == "systemVerilog":
            langue_value = SYSTEM_VERILOG
        else:
            raise ValueError(langue +  " is not reconnized")

        if PY_MAJOR_VERSION == 3 :
            filename = filename.encode('utf8')
            incdir = [item.encode('utf8') for item in incdir ]

        c = self.thisptr.parse(filename,langue_value,incdir,hierarchyOnly,debug)

        cdef PyObject * d
        d = NULL
        d = c.toJson()
        cdef object d_py
        d_py = <object> d
        return d_py
    
    def test(self, filename, incdir=['.']):
        self.thisptr.test(filename,incdir)
    

def parse(filename,langue,incdir=['.'],hierarchyOnly=False,debug=False):
    cdef hdlConvertor obj
    cdef object context
    obj = hdlConvertor()
    context = obj.parse(filename,langue,incdir,hierarchyOnly,debug)
    return context

def test(filename,incdir=['.']):
    cdef hdlConvertor obj
    obj = hdlConvertor()
    obj.test(filename,incdir)

