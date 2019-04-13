# from libc cimport errno,string

from libc.string cimport strerror
from libc.errno cimport errno
from libcpp cimport bool
from libcpp cimport string
from cpython.ref cimport PyObject
from cpython.version cimport PY_MAJOR_VERSION
import sys


from convertor cimport Context, VHDL, VERILOG, SYSTEM_VERILOG, Convertor as _Convertor

cdef class ParseException(Exception):
    pass


cdef public PyObject * ParseExceptionT = < PyObject *> ParseException

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
    
    def verilog_pp(self, filename, incdir=['.'],mode=0):
        PY3 = PY_MAJOR_VERSION == 3

        if PY3:
            string_type = str
        else:
            string_type = basestring
        
        if isinstance(filename, string_type):
            filenames = [filename, ]

        if PY3:
            filename = filename.encode('utf8')
            incdir = [item.encode('utf8') for item in incdir]
        
        data = self.thisptr.verilog_pp(filename, incdir, mode)
        
        if PY3:
            data = data.decode('utf8')

        return data

    

def parse(filenames, langue, incdir=['.'], hierarchyOnly=False, debug=False):
    cdef hdlConvertor obj
    cdef object context
    obj = hdlConvertor()
    context = obj.parse(filenames, langue, incdir, hierarchyOnly, debug)
    return context


def verilog_pp(filename, incdir=['.'], mode="verilog2001"):
    """
    :param filename: object of verilog preprocess
    :param incdir: list of include directories
    :param language: one of "verilog2001", "verilog2005", "sv2012"
    """
    cdef hdlConvertor obj
    cdef int mode_value
    if mode == "verilog2001" :
        mode_value = 0
    elif mode == "verilog2005" :
        mode_value = 1
    elif mode == "sv2012" :
        mode_value = 2
    else:
        raise ValueError(mode + " is not recognized (expected verilog2001, verilog2005 or sv2012)")
    obj = hdlConvertor()
    return obj.verilog_pp(filename, incdir,mode_value)

