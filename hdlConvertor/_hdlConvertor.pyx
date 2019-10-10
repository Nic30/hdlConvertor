import sys

from cpython.ref cimport PyObject
from cython.operator cimport dereference as deref
from cython.operator cimport preincrement as preinc
from libcpp.memory cimport unique_ptr
from libc.string cimport strerror
from libc.errno cimport errno
from libcpp cimport bool
from libcpp.string cimport string
from libcpp.vector cimport vector
from libcpp.pair cimport pair

from hdlConvertor.hdlAst import HdlContext as PyHdlContext
from hdlConvertor.language import Language as PyHdlLanguageEnum

include "verilogPreproc.pyx"

cdef extern from "hdlConvertor/hdlObjects/hdlContext.h" namespace "hdlConvertor::hdlObjects":
    cdef cppclass HdlContext:
        HdlContext()

cdef extern from "toPy.h" namespace "hdlConvertor":
    cdef cppclass ToPy:
        ToPy()

        @staticmethod
        PyObject * toPy(const HdlContext * c) except NULL

cdef extern from "hdlConvertor/conversion_exception.h" namespace "hdlConvertor":
    cdef const char * get_cpp_py_error_message()

cdef extern from "hdlConvertor/language.h" namespace "hdlConvertor":
    enum Language:
        VHDL, VERILOG1995, VERILOG2001, VERILOG2001_NOCONFIG, \
            VERILOG2005, SV2005, SV2009, SV2012, SV2017

cdef class ParseException(Exception):
    pass

cdef int raise_cpp_py_error() except *:
    msg = get_cpp_py_error_message()
    msg = str_decode(msg)

    raise ParseException(msg)

cdef extern from "hdlConvertor/convertor.h" namespace "hdlConvertor":
    cdef cppclass Convertor:
        unique_ptr[HdlContext] c
        MacroDB defineDB

        Convertor(HdlContext & _c)

        void parse(
            const vector[string] & hdl_file_names,
            Language language,
            vector[string] include_dirs,
            bool hierarchy_only,
            bool debug) except +raise_cpp_py_error

        void parse_str(
            const string & hdl_str,
            Language language,
            vector[string] include_dirs,
            bool hierarchy_only,
            bool debug) except +raise_cpp_py_error

        string verilog_pp(
            const string & filename,
            vector[string] incdirs,
            Language mode) except +raise_cpp_py_error

        string verilog_pp_str(
            const string & verilog_str,
            vector[string] incdirs,
            Language mode) except +raise_cpp_py_error

cdef class HdlConvertor:
    """
    The container of the Convertor which parses HDL code to universal AST

    :ivar thisptr: pointer on Convertor instance which is a wrapper around the parsers
    :ivar proproc_macro_db: dictinary of symbols defined in preprocessor
    """

    cdef unique_ptr[Convertor] thisptr
    cdef HdlContext context
    cdef public CppStdMapProxy preproc_macro_db

    # cdef map[string, object] proproc_macro_db;
    def __cinit__(self):
        self.thisptr.reset(new Convertor(self.context))
        self.preproc_macro_db = CppStdMapProxy.from_ptr(&self.thisptr.get().defineDB)

    @staticmethod
    def _translate_Language_enum(langue):
        if langue == PyHdlLanguageEnum.VHDL:
            return VHDL
        else:
            return HdlConvertor._translate_verilog_enum(langue)

    @staticmethod
    def _translate_verilog_enum(lang):
        L = PyHdlLanguageEnum
        if lang == L.VERILOG_1995:
            return VERILOG1995
        elif lang == L.VERILOG_2001:
            return VERILOG2001
        elif lang == L.VERILOG_2001_NOCONFIG:
            return VERILOG2001_NOCONFIG
        elif lang == L.VERILOG_2005:
            return VERILOG2005
        elif lang == L.SYSTEM_VERILOG_2005:
            return SV2005
        elif lang == L.SYSTEM_VERILOG_2009:
            return SV2009
        elif lang == L.SYSTEM_VERILOG_2012:
            return SV2012
        elif lang == L.SYSTEM_VERILOG_2017:
            return SV2017
        else:
            raise ValueError(repr(lang) + " is not recognized"
                             " (expected hdlConvertor.language.Language value)")

    def parse(self, filenames, langue, incdirs, hierarchyOnly=False, debug=True):
        """
        :param filenames: sequence of filenames or filename
        :type filename: Union[str, List[str]]
        :param langue: hdlConvertor.language.Language enum value
        :param incdirs: list of include directories
        :param hierarchyOnly: if True only names of components and modules are parsed
        :param debug: if True the debug logging is enabled
        :return: HdlContext instance
        """
        langue_value = self._translate_Language_enum(langue)

        if isinstance(filenames, string_type):
            filenames = [filenames, ]

        filenames = [str_encode(item) for item in filenames]
        incdirs = [str_encode(item) for item in incdirs]

        cdef object d_py
        cdef PyObject * d
        cdef ToPy toPy
        if filenames:
            self.thisptr.get().parse(
                filenames, langue_value, incdirs, hierarchyOnly, debug)

            toPy = ToPy()
            d = toPy.toPy(&self.context)
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
        :param langue: hdlConvertor.language.Language enum value
        :param incdirs: list of include directories
        :param hierarchyOnly: if True only names of components and modules are parsed
        :param debug: if True the debug logging is enabled
        :return: HdlContext instance
        """
        langue_value = self._translate_Language_enum(langue)

        hdl_str = str_encode(hdl_str)
        incdirs = [str_encode(item) for item in incdirs]

        cdef object d_py
        cdef PyObject * d
        cdef ToPy toPy
        if hdl_str:
            self.thisptr.get().parse_str(
                hdl_str, langue_value, incdirs, hierarchyOnly, debug)

            toPy = ToPy()
            d = toPy.toPy(&self.context)
            if not d:
                raise
            d_py = < object > d
            return d_py
        else:
            return PyHdlContext()

    def verilog_pp(self, filename, lang, incdirs=['.']):
        """
        Execute Verilog preprocessor

        :type filename: Union[str, List[str]]
        :return: string output from verilog preprocessor
        """
        langue_value = self._translate_verilog_enum(lang)

        filename = str_encode(filename)
        incdirs = [str_encode(item) for item in incdirs]

        data = self.thisptr.get().verilog_pp(filename, incdirs, langue_value)
        data = str_decode(data)

        return data

    def verilog_pp_str(self, verilog_str, lang, incdirs=['.']):
        """
        Execute Verilog preprocessor

        :return: string output from verilog preprocessor
        """
        langue_value = self._translate_verilog_enum(lang)

        verilog_str = str_encode(verilog_str)
        incdirs = [str_encode(item) for item in incdirs]

        data = self.thisptr.get().verilog_pp_str(verilog_str, incdirs, langue_value)
        data = str_decode(data)

        return data
