from libc.string cimport strerror
from libc.errno cimport errno
from libcpp cimport bool
from libcpp.string cimport string
from libcpp.vector cimport vector
from cpython.ref cimport PyObject
from cpython.version cimport PY_MAJOR_VERSION
from hdlConvertor.language import Language as PyHdlLanguageEnum
from hdlConvertor.hdlAst import HdlContext as PyHdlContext
import sys

cdef extern from "hdlConvertor/hdlObjects/hdlContext.h" namespace "hdlConvertor::hdlObjects":
    cdef cppclass HdlContext:
        pass

cdef extern from "toPy.h" namespace "hdlConvertor":
    cdef cppclass ToPy:
        ToPy()

        @staticmethod
        PyObject * toPy(const HdlContext * c) except NULL

cdef extern from "hdlConvertor/conversion_exception.h" namespace "hdlConvertor":
    cdef const char * get_my_py_error_message()

cdef extern from "hdlConvertor/language.h" namespace "hdlConvertor":
    enum Language:
        VHDL, VERILOG, SYSTEM_VERILOG, VERILOG2001, VERILOG2005, SV2012, SV2017

cdef class ParseException(Exception):
    pass

cdef int raise_my_py_error() except * :
    PY3 = PY_MAJOR_VERSION == 3
    msg = get_my_py_error_message()
    if PY3:
        msg = msg.decode('utf-8')

    raise ParseException(msg)

cdef extern from "hdlConvertor/convertor.h" namespace "hdlConvertor":
    cdef cppclass Convertor:

        HdlContext * parse(const vector[string] & hdl_file_names,
                        Language language,
                        vector[string] include_dirs,
                        bool hierarchy_only,
                        bool debug) except +raise_my_py_error

        HdlContext * parse_str(const string & hdl_str,
                        Language language,
                        vector[string] include_dirs,
                        bool hierarchy_only,
                        bool debug) except +raise_my_py_error

        string verilog_pp(const string & filename,
                          vector[string] incdirs,
                          Language mode) except +raise_my_py_error

        string verilog_pp_str(const string & verilog_str,
                          vector[string] incdirs,
                          Language mode) except +raise_my_py_error

cdef class HdlConvertor:
    """
    The container of the Convertor which parses HDL code to universal AST
    """

    cdef Convertor * thisptr
    def __cinit__(self):
        self.thisptr = new Convertor()

    def __dealloc__(self):
        del self.thisptr

    @staticmethod
    def _translate_Language_enum(langue):
        if langue == PyHdlLanguageEnum.VERILOG:
            return VERILOG
        elif langue == PyHdlLanguageEnum.VHDL:
            return VHDL
        elif langue == PyHdlLanguageEnum.SYSTEM_VERILOG:
            return SYSTEM_VERILOG
        else:
            raise ValueError(langue + " is not recognized (expected verilog, vhdl or systemVerilog)")

    @staticmethod
    def _get_verilog_pp_mode(mode):
        L = PyHdlLanguageEnum
        if mode == L.VERILOG or mode == L.VERILOG_2001:
            return VERILOG2001
        elif mode == L.VERILOG_2005:
            return VERILOG2005
        elif mode == L.SYSTEM_VERILOG_2012 or mode == L.SYSTEM_VERILOG:
            return SV2012
        elif mode == L.SYSTEM_VERILOG_2017:
            return SV2017
        else:
            raise ValueError(mode + " is not recognized (expected " + repr(PyHdlLanguageEnum) + ")")

    def parse(self, filenames, langue, incdirs, hierarchyOnly=False, debug=True):
        """
        :param filenames: sequence of filenames or filename
        :type filename: Union[str, List[str]]
        :param language: hdlConvertor.language.Language enum value
        :param incdirs: list of include directories
        :param hierarchyOnly: if True only names of components and modules are parsed
        :param debug: if True the debug logging is enabled
        :return: HdlContext instance
        """
        langue_value = self._translate_Language_enum(langue)
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

        cdef HdlContext * c
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
            return PyHdlContext()

    def parse_str(self, hdl_str, langue, incdirs, hierarchyOnly=False, debug=True):
        """
        :param hdl_str: HDL string to parse
        :type filename: str
        :param language: hdlConvertor.language.Language enum value
        :param incdirs: list of include directories
        :param hierarchyOnly: if True only names of components and modules are parsed
        :param debug: if True the debug logging is enabled
        :return: HdlContext instance
        """
        langue_value = self._translate_Language_enum(langue)
        PY3 = PY_MAJOR_VERSION == 3

        if PY3:
            hdl_str = hdl_str.encode('utf8')
            incdirs = [item.encode('utf8') for item in incdirs]

        cdef HdlContext * c
        cdef object d_py
        cdef PyObject * d
        cdef ToPy toPy
        if hdl_str:
            c = self.thisptr.parse_str(
                hdl_str, langue_value, incdirs, hierarchyOnly, debug)

            toPy = ToPy()
            d = toPy.toPy(c)
            if not d:
                raise
            d_py = < object > d
            return d_py
        else:
            return PyHdlContext()

    def verilog_pp(self, filename, incdirs=['.'], mode=PyHdlLanguageEnum.VERILOG):
        """
        Execute Verilog preprocessor

        :type filename: Union[str, List[str]]
        :return: string output from verilog preprocessor
        """
        mode_value = self._get_verilog_pp_mode(mode)
        PY3 = PY_MAJOR_VERSION == 3

        if PY3:
            filename = filename.encode('utf8')
            incdirs = [item.encode('utf8') for item in incdirs]

        data = self.thisptr.verilog_pp(filename, incdirs, mode_value)

        if PY3:
            data = data.decode('utf8')

        return data

    def verilog_pp_str(self, verilog_str, incdirs=['.'], mode=PyHdlLanguageEnum.VERILOG):
        """
        Execute Verilog preprocessor

        :return: string output from verilog preprocessor
        """
        mode_value = self._get_verilog_pp_mode(mode)
        PY3 = PY_MAJOR_VERSION == 3
        if PY3:
            verilog_str = verilog_str.encode('utf8')
            incdirs = [item.encode('utf8') for item in incdirs]

        data = self.thisptr.verilog_pp_str(verilog_str, incdirs, mode_value)

        if PY3:
            data = data.decode('utf8')

        return data
