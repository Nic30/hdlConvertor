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

from hdlConvertorAst.hdlAst import HdlContext as PyHdlContext
from hdlConvertorAst.language import Language as PyHdlLanguageEnum
from hdlConvertorAst.parse_hdlConvertor_json import \
    parse_hdlConvertor_json_file, parse_hdlConvertor_json_str


include "verilogPreproc.pyx"

cdef extern from "hdlConvertor/hdlAst/hdlContext.h" namespace "hdlConvertor::hdlAst":
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

cdef extern from "hdlConvertor/hdlConvertor.h" namespace "hdlConvertor":
    cdef cppclass HdlConvertor:
        unique_ptr[HdlContext] c
        MacroDB defineDB

        HdlConvertor(HdlContext & _c)

        void parse(
            const vector[string] & hdl_file_names,
            Language language,
            vector[string] include_dirs,
            const string & encoding,
            bool hierarchy_only,
            bool debug) except +raise_cpp_py_error

        void parse_str(
            const string & hdl_str,
            Language language,
            vector[string] include_dirs,
            const string & encoding,
            bool hierarchy_only,
            bool debug) except +raise_cpp_py_error

        string verilog_pp(
            const string & filename,
            vector[string] incdirs,
            Language mode,
            const string & encoding) except +raise_cpp_py_error

        string verilog_pp_str(
            const string & verilog_str,
            vector[string] incdirs,
            Language mode,
            const string & encoding) except +raise_cpp_py_error


cdef class HdlConvertorPy:
    """
    The container of the HdlConvertor which parses HDL code to universal AST

    :ivar ~.thisptr: pointer on HdlConvertor instance which is a wrapper around the parsers
    :ivar ~.proproc_macro_db: dictinary of symbols defined in preprocessor
    """

    cdef unique_ptr[HdlConvertor] thisptr
    cdef HdlContext context
    cdef public CppStdMapProxy preproc_macro_db

    # cdef map[string, object] proproc_macro_db;
    def __cinit__(self):
        self.thisptr.reset(new HdlConvertor(self.context))
        self.preproc_macro_db = CppStdMapProxy.from_ptr(&self.thisptr.get().defineDB)

    @staticmethod
    def _translate_Language_enum(language):
        if language == PyHdlLanguageEnum.VHDL:
            return VHDL
        else:
            return HdlConvertorPy._translate_verilog_enum(language)

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

    def parse(self, filenames, language, incdirs, encoding="utf-8", hierarchyOnly=False, debug=True):
        """
        :param filenames: sequence of filenames or filename
        :type filename: Union[str, List[str]]
        :param language: hdlConvertor.language.Language enum value
        :param incdirs: list of include directories
        :param encoding: character encoding of input data
        :param hierarchyOnly: if True only names of components and modules are parsed
        :param debug: if True the debug logging is enabled
        :return: HdlContext instance
        """
        if language == PyHdlLanguageEnum.HDLCONVERTOR_JSON:
            # merge object from all files to a single PyHdlContext
            res = None
            for f_name in filenames:
                _res = parse_hdlConvertor_json_file(f_name)
                if res is None:
                    res = _res
                else:
                    res.objs.extend(_res.objs)
            if res is None:
                return PyHdlContext()
            else:
                return res

        language_value = self._translate_Language_enum(language)

        if isinstance(filenames, string_type):
            filenames = [filenames, ]

        filenames = [str_encode(item) for item in filenames]
        incdirs = [str_encode(item) for item in incdirs]

        cdef object d_py
        cdef PyObject * d
        cdef ToPy toPy
        if filenames:
            self.thisptr.get().parse(
                filenames, language_value, incdirs, str_encode(encoding),
                hierarchyOnly, debug)

            toPy = ToPy()
            d = toPy.toPy(&self.context)
            if not d:
                raise
            d_py = < object > d
            return d_py
        else:
            return PyHdlContext()

    def parse_str(self, hdl_str, language, incdirs, encoding="utf-8", hierarchyOnly=False, debug=True):
        """
        :param hdl_str: HDL string to parse
        :type filename: str
        :param language: hdlConvertor.language.Language enum value
        :param incdirs: list of include directories
        :param encoding: character encoding of input data
        :param hierarchyOnly: if True only names of components and modules are parsed
        :param debug: if True the debug logging is enabled
        :return: HdlContext instance
        """
        if language == PyHdlLanguageEnum.HDLCONVERTOR_JSON:
            return parse_hdlConvertor_json_str(hdl_str)

        language_value = self._translate_Language_enum(language)

        hdl_str = str_encode(hdl_str)
        incdirs = [str_encode(item) for item in incdirs]

        cdef object d_py
        cdef PyObject * d
        cdef ToPy toPy
        if hdl_str:
            self.thisptr.get().parse_str(
                hdl_str, language_value, incdirs, str_encode(encoding),
                hierarchyOnly, debug)

            toPy = ToPy()
            d = toPy.toPy(&self.context)
            if not d:
                raise
            d_py = < object > d
            return d_py
        else:
            return PyHdlContext()

    def verilog_pp(self, filename, lang, incdirs=['.'], encoding="utf-8"):
        """
        Execute Verilog preprocessor

        :type filename: Union[str, List[str]]
        :param encoding: character encoding of input data
        :return: string output from verilog preprocessor
        """
        language_value = self._translate_verilog_enum(lang)

        filename = str_encode(filename)
        incdirs = [str_encode(item) for item in incdirs]

        data = self.thisptr.get().verilog_pp(filename, incdirs,
                                             language_value, str_encode(encoding))
        data = str_decode(data)

        return data

    def verilog_pp_str(self, verilog_str, lang, incdirs=['.'], encoding="utf-8"):
        """
        Execute Verilog preprocessor

        :param encoding: character encoding of input data
        :return: string output from verilog preprocessor
        """
        language_value = self._translate_verilog_enum(lang)

        verilog_str = str_encode(verilog_str)
        incdirs = [str_encode(item) for item in incdirs]

        data = self.thisptr.get().verilog_pp_str(verilog_str, incdirs,
                                                 language_value, str_encode(encoding))
        data = str_decode(data)

        return data
