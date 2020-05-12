from libcpp cimport bool
from libcpp.string cimport string
from libcpp.vector cimport vector
from libcpp.cast cimport dynamic_cast
from libcpp.map cimport map
from cython.operator cimport dereference as deref
from cython.operator cimport preincrement as preinc
from enum import Enum

include "python_ver_independent_str.pyx"


cdef extern from "hdlConvertor/verilogPreproc/a_macro_def.h" namespace "hdlConvertor::verilog_pp":
    cdef cppclass aMacroDef:
        bool is_persistent
        string name
        string defined_in_file
        ssize_t defined_in_line_no

cdef extern from "hdlConvertor/verilogPreproc/macro_def_verilog.h" namespace "hdlConvertor::verilog_pp::MacroDefVerilog":
    cdef cppclass Fragment:
        ssize_t arg_no
        string str
    cdef struct param_info_t:
        string name
        bool has_def_val
        string def_val

cdef extern from "hdlConvertor/verilogPreproc/macro_def_verilog.h" namespace "hdlConvertor::verilog_pp":
    cdef cppclass MacroDefVerilog(aMacroDef):
        bool has_params
        vector[param_info_t] params
        vector[Fragment] body

        MacroDefVerilog(const string & name, bool has_params,
                        const vector[param_info_t] & params,
                        const string & body)

cdef extern from "hdlConvertor/verilogPreproc/macroDB.h" namespace "hdlConvertor::verilog_pp":
    ctypedef map[string, aMacroDef * ] MacroDB

# [TODO] use smart pointers as this potentially can cause segfault if used incorrectly
cdef class MacroDefVerilogProxy:
    """
    Proxy for MacroDefVerilog C++ object

    :attention: this object uses C++ object, It's lifetime depends on state of preprocessor
        from this reason this object can not accessed after the original object in preprocessor
        symbol database has been deleted

    :ivar ~.thisptr: C++ pointer on MacroDefVerilog object
    :ivar ~.is_reference_borrowed: flag which tells if the C++ object should be deallocated
        after this python proxy is deallocated
    """
    cdef MacroDefVerilog * thisptr
    cdef bint is_reference_borrowed 

    def __cinit__(self):
        self.thisptr = NULL
        self.is_reference_borrowed = False

    def get_body(self):
        """
        :return: string of macro body
        :rtype: str
        """
        cdef vector[Fragment].iterator it = self.thisptr.body.begin()
        buff = []
        while it != self.thisptr.body.end():
            arg_no = deref(it).arg_no
            if arg_no > 0:
                v = self.thisptr.params[arg_no].name
            else:
                v = deref(it).str
            v = str_decode(v) 
            buff.append(v)
            preinc(it)

        return "".join(buff)

    def get_params(self):
        """
        :return: None or list of parameters and it's default values if parameter has any
        :rtype: Optional[List[Union[str, Tuple[str, str]]]]
        """
        cdef vector[param_info_t].iterator it = self.thisptr.params.begin()
        if not self.thisptr.has_params:
            return None
        else:
            params = []
            while it != self.thisptr.params.end():
                if deref(it).has_def_val:
                    name = deref(it).name
                    def_val = deref(it).def_val
                    p = (str_decode(name),
                         str_decode(def_val))
                else:
                    p = str_decode(deref(it).name)
                params.append(p)
                preinc(it)

            return params

    @property
    def name(self):
        """
        :return: symbol name which represents this macro in preprocessor
        :rtype: str
        """
        return str_decode(self.thisptr.name)

    @property
    def is_persistent(self):
        return self.thisptr.is_persistent

    @is_persistent.setter
    def is_persistent(self, value):
        self.thisptr.is_persistent = value

    @property
    def defined_in_file(self):
        return str_decode(self.thisptr.defined_in_file)

    @defined_in_file.setter
    def defined_in_file(self, value):
        self.thisptr.defined_in_file = str_encode(value)

    @property
    def defined_in_line_no(self):
        return self.thisptr.defined_in_line_no

    @defined_in_line_no.setter
    def defined_in_line_no(self, value):
        self.thisptr.defined_in_line_no = value

    @classmethod
    def new(cls, name, params, body):
        """
        :type name: str
        :type params: Optional[List[Union[str, Tuple[str, str]]]
        :type body: str
        """
        self = cls()
        assert (< MacroDefVerilogProxy > self).thisptr == NULL, "This object is already bounded to a C++ object"
        name = str_encode(name)

        if body is None:
            body = ""
        body = str_encode(body)

        cdef vector[param_info_t] _params
        if params is not None:
            for p in params:
                if isinstance(p, tuple):
                    p_name, p_def_val = p
                    p_name = str_encode(p_name)
                    p_def_val = str_encode(p_def_val)
                    _params.push_back(param_info_t(p_name, True, p_def_val))
                else:
                    p = str_encode(p)

        (< MacroDefVerilogProxy > self).is_reference_borrowed = False
        (< MacroDefVerilogProxy > self).thisptr = new MacroDefVerilog(name, params is not None, _params, body)
        return self


class CppStdMapIteratorType(Enum):
    KEYS, VALUES, ITEMS = range(3)


class NonAccessibleCppObject:
    """
    Placeholder for C++ object which does not have any Python API
    """
    pass


ctypedef map[string, aMacroDef * ].iterator MacroDB_iterator

cdef MacroDB_iterator_key(MacroDB_iterator it):
    k = < object > deref(it).first
    k = str_decode(k)
    return k

# typedef because dynamc_cast type can not end with '*'
ctypedef MacroDefVerilog * MacroDefVerilogPtr 

cdef MacroDB_iterator_value(MacroDB_iterator it):
    cdef MacroDefVerilog * v_v
    v = deref(it).second
    assert v != NULL, "MacroDB contains nullptr, but it should not be there"
    v_v = dynamic_cast[MacroDefVerilogPtr](v)
    if v_v != NULL:
        p = MacroDefVerilogProxy()
        (< MacroDefVerilogProxy > p).thisptr = v_v
        (< MacroDefVerilogProxy > p).is_reference_borrowed = True
        return p

    # Backup case, if object is something unknown to this cython implementation
    return NonAccessibleCppObject()

cdef class CppStdMapIterator:
    cdef MacroDB_iterator it
    cdef MacroDB_iterator end
    cdef object t

    def __cinit__(self, object t):
        self.t = t

    def __iter__(self):
        return self

    def __next__(self):
        if self.it == self.end:
            raise StopIteration()
        else:
            if self.t == CppStdMapIteratorType.KEYS:
                res = MacroDB_iterator_key(self.it)
            elif self.t == CppStdMapIteratorType.VALUES:
                res = MacroDB_iterator_value(self.it)
            elif self.t == CppStdMapIteratorType.ITEMS:
                res = (MacroDB_iterator_key(self.it), MacroDB_iterator_value(self.it))
            else:
                raise AssertionError(self.t)

            preinc(self.it)
            return res

_RaiseKeyError = object()  # singleton for no-default behavior of CppStdMapProxy
cdef class CppStdMapProxy:
    cdef MacroDB * thisptr

    @staticmethod
    cdef from_ptr(MacroDB * thisptr):
        self = CppStdMapProxy()
        self.thisptr = thisptr
        return self
    def get(self, key, value=None):
        v = deref(self.thisptr).find(self.__keytransform__(key))
        if v == deref(self.thisptr).end():
            return value
        else:
            return MacroDB_iterator_value(v)

    def setdefault(self, k, default=None):
        v = deref(self.thisptr).find(self.__keytransform__(k))
        if v == deref(self.thisptr).end():
            self[k] = default
            return default
        else:
            return MacroDB_iterator_value(v)

    def pop(self, k, v=_RaiseKeyError):
        it = deref(self.thisptr).find(self.__keytransform__(k))
        if it == deref(self.thisptr).end():
            if v is _RaiseKeyError:
                raise KeyError()
            else:
                return v
        else:
            return MacroDB_iterator_value(it)

    def __getitem__(self, key):
        """
        :type key: str
        """
        v = deref(self.thisptr).find(self.__keytransform__(key))
        if v == deref(self.thisptr).end():
            raise KeyError()
        else:
            return MacroDB_iterator_value(v)

    def __contains__(self, key):
        v = deref(self.thisptr).find(self.__keytransform__(key))
        return v != deref(self.thisptr).end()

    def __setitem__(self, key, value):
        cdef aMacroDef * v = NULL
        v_v = None

        if isinstance(value, MacroDefVerilogProxy):
            v_v = value
        else:
            v_v = MacroDefVerilogProxy.new(key, None, value)

        if v_v is not None:
            v = (< MacroDefVerilogProxy > v_v).thisptr
            # the c++ object now belongs to the MacroDB object
            (< MacroDefVerilogProxy > v_v).is_reference_borrowed = True

        # [TODO] it may be better to let user specify this flag directly
        v.is_persistent = True
        deref(self.thisptr)[self.__keytransform__(key)] = v

    def __delitem__(self, key):
        # self.thisptr.erase(self.__keytransform__(key))
        v = deref(self.thisptr).find(self.__keytransform__(key))
        if v == deref(self.thisptr).end():
            raise KeyError()
        else:
            del deref(v).second
            deref(self.thisptr).erase(v)

    def __iter(self, t):
        cdef CppStdMapIterator self_it = CppStdMapIterator(t)
        self_it.it = deref(self.thisptr).begin()
        self_it.end = deref(self.thisptr).end()
        return self_it

    def items(self):
        return self.__iter(CppStdMapIteratorType.ITEMS)

    def values(self):
        return self.__iter(CppStdMapIteratorType.VALUES)

    def keys(self):
        return self.__iter(CppStdMapIteratorType.KEYS)

    def __len__(self):
        return deref(self.thisptr).size()

    def __keytransform__(self, key):
        return str_encode(key)

    def update(self, other_dict_like):
        for k, v in other_dict_like.items():
            self[k] = v

    def clear(self):
        for v in self.values():
            del v
        deref(self.thisptr).clear()

    def copy(self):
        raise AssertionError(
            "This object can not be copied because it may contain"
            " C++ objects which are tied to this object instance")

    def __repr__(self):
        return "<%s, {%s}>" % (
            self.__class__.__name__,
            ", ".join("%r: %r" % kv for kv in self.items()))
