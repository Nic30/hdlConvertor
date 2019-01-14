
from libcpp cimport bool
from libcpp.vector cimport vector
from libcpp.string cimport string
from cpython.ref cimport PyObject


cdef extern from "hdlObjects/context.h":
    cdef cppclass Context:
        PyObject * toJson()

cdef extern from "exception.h":
    cdef void raise_py_error()

cdef extern from "langue.h":
    enum Langue:
        VHDL, VERILOG, SYSTEM_VERILOG

cdef extern from "convertor.h":
    cdef cppclass Convertor:

        string filename
        Langue lang
        bool hierarchyOnly

        Context * parse(vector[string],
                        Langue,
                        vector[string],
                        bool,
                        bool) except +raise_py_error

        void test(string filename, vector[string] incdir) except +raise_py_error

