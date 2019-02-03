# from libc cimport errno,string

from libc.string cimport strerror
from libc.errno cimport errno
from libcpp cimport bool
from libcpp cimport string
from cpython.ref cimport PyObject
from cpython.version cimport PY_MAJOR_VERSION
from convertor cimport Context, VHDL, VERILOG, SYSTEM_VERILOG, Convertor as _Convertor
import sys


class parseException(Exception):
    pass


cdef public PyObject * parseExceptionerror = < PyObject *> parseException

cdef class hdlConvertor:
    cdef _Convertor * thisptr

    def __cinit__(self):
        self.thisptr = new _Convertor()
    
    def __dealloc__(self):
        del self.thisptr

    def parse(self, filenames, langue, incdir, hierarchyOnly, debug):
        """
        :param filenames: sequence of strings or strig
        :param language: one of "verilog", "vhdl", "systemVerilog"
        """

        cdef Context * c

        if langue == "verilog":
            langue_value = VERILOG
        elif langue == "vhdl":
            langue_value = VHDL
        elif langue == "systemVerilog":
            langue_value = SYSTEM_VERILOG
        else:
            raise ValueError(langue + " is not recognized (expected verilog, vhdl or systemVerilog)")

        PY3 = PY_MAJOR_VERSION == 3

        if PY3:
            string_type = str
        else:
            string_type = basestring
        
        if isinstance(filenames, string_type):
            filenames = [filenames, ]

        if PY3:
            filenames = [item.encode('utf8') for item in filenames]
            incdir = [item.encode('utf8') for item in incdir]

        c = self.thisptr.parse(filenames, langue_value, incdir, hierarchyOnly, debug)

        cdef PyObject * d
        d = NULL
        d = c.toJson()
        cdef object d_py
        d_py = < object > d
        return d_py
    
    def test(self, filename, incdir=['.'],mode=0):
        PY3 = PY_MAJOR_VERSION == 3

        if PY3:
            string_type = str
        else:
            string_type = basestring
        
        if isinstance(filename, string_type):
            filenames = [filename, ]

        if PY3:
            filename = [item.encode('utf8') for item in filename]
            incdir = [item.encode('utf8') for item in incdir]
        
        return self.thisptr.test(filename, incdir, mode)
    

def parse(filenames, langue, incdir=['.'], hierarchyOnly=False, debug=False):
    cdef hdlConvertor obj
    cdef object context
    obj = hdlConvertor()
    context = obj.parse(filenames, langue, incdir, hierarchyOnly, debug)
    return context


def test(filename, incdir=['.'], mode=0):
    cdef hdlConvertor obj
    obj = hdlConvertor()
    return obj.test(filename, incdir,mode)

