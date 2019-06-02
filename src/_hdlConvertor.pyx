# from libc cimport errno, string

from libc.string cimport strerror
from libc.errno cimport errno
from libcpp cimport bool
from libcpp.string cimport string
from libcpp.vector cimport vector
from cpython.ref cimport PyObject
from cpython.version cimport PY_MAJOR_VERSION
from hdlConvertor.language import Language as PyHdlLanguageEnum
from hdlConvertor.hdlAst import HdlContext
import sys

cdef extern from "hdlObjects/context.h" namespace "hdlConvertor::hdlObjects":
    cdef cppclass Context:
        pass

cdef extern from "toPy.h" namespace "hdlConvertor":
    cdef cppclass ToPy:
        ToPy()

        @staticmethod
        PyObject * toPy(const Context * c) except NULL

cdef extern from "conversion_exception.h" namespace "hdlConvertor":
    cdef const char * get_my_py_error_message()

cdef extern from "language.h" namespace "hdlConvertor":
    enum Language:
        VHDL, VERILOG, SYSTEM_VERILOG

cdef class ParseException(Exception):
    pass

cdef int raise_my_py_error() except * :
    PY3 = PY_MAJOR_VERSION == 3
    msg = get_my_py_error_message()
    if PY3:
        msg = msg.decode('utf-8')

    raise ParseException(msg)

cdef extern from "convertor.h" namespace "hdlConvertor":
    cdef cppclass Convertor:

        string filename
        Language lang
        bool hierarchyOnly

        Context * parse(vector[string],
                        Language,
                        vector[string],
                        bool,
                        bool) except +raise_my_py_error

        string verilog_pp(string filename, vector[string] incdirs, unsigned int) except +raise_my_py_error

cdef class HdlConvertor:
    """
    The container of the Convertor which parses HDL code to universal AST
    """

    cdef Convertor * thisptr
    def __cinit__(self):
        self.thisptr = new Convertor()

    def __dealloc__(self):
        del self.thisptr

    def parse(self, filenames, langue, incdirs, hierarchyOnly=False, debug=True):
        """
        :param filenames: sequence of strings or strig
        :param language: one of "verilog", "vhdl", "systemVerilog"
        :param incdirs: list of include directories
        :param hierarchyOnly: if True only names of components and modules are parsed
        :param debug: if True the debug logging is enabled
        :return: HdlContext instance
        """

        if langue == PyHdlLanguageEnum.VERILOG:
            langue_value = VERILOG
        elif langue == PyHdlLanguageEnum.VHDL:
            langue_value = VHDL
        elif langue == PyHdlLanguageEnum.SYSTEM_VERILOG:
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
            incdirs = [item.encode('utf8') for item in incdirs]

        cdef Context * c
        cdef object d_py
        cdef PyObject * d
        cdef ToPy toPy
        if filenames:
            c = self.thisptr.parse(
                filenames, langue_value, incdirs, hierarchyOnly, debug)

            toPy = ToPy()
            d = toPy.toPy(c)
            if not d:
                raise
            d_py = < object > d
            return d_py
        else:
            return HdlContext()

    def verilog_pp(self, filename, incdirs=['.'], mode=0):
        """
        Execute verilog preprocessor
        """
        PY3 = PY_MAJOR_VERSION == 3

        if PY3:
            string_type = str
        else:
            string_type = basestring

        if isinstance(filename, string_type):
            filenames = [filename, ]

        if PY3:
            filename = filename.encode('utf8')
            incdirs = [item.encode('utf8') for item in incdirs]

        data = self.thisptr.verilog_pp(filename, incdirs, mode)

        if PY3:
            data = data.decode('utf8')

        return data
