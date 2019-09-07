from cpython.version cimport PY_MAJOR_VERSION

IS_PY3 = PY_MAJOR_VERSION == 3

if IS_PY3:
    string_type = str

    def str_decode(s):
        return s.decode("utf-8")

    def str_encode(s):
        return s.encode("utf-8") 

else:
    string_type = basestring

    def str_decode(s):
        return s

    def str_encode(s):
        return s
