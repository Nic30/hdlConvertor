import sys

# [TODO] merge with py_ver_independent_str

if sys.version_info[0] <= 2:
    def is_str(x):
        return isinstance(x, (basestring, unicode))
else:
    def is_str(x):
        return isinstance(x, str)
