import sys


class Indent():
    """
    indentation context
    """

    def __init__(self, autoIndentStream):
        self.s = autoIndentStream
        self.original_indent = None

    def __enter__(self):
        s = self.s
        self.original_indent = s.indent_str
        s.indent_cnt += 1
        s.indent_str = s.indent_str + s.INDENT_STEP

    def __exit__(self, exception_type, exception_value, traceback):
        s = self.s
        s.indent_cnt -= 1
        s.indent_str = self.original_indent


class UnIndent():
    """
    unindentation context
    """

    def __init__(self, autoIndentStream):
        self.s = autoIndentStream
        self.original_indent = None

    def __enter__(self):
        s = self.s
        self.original_indent = s.indent_str
        assert s.indent_cnt > 0
        s.indent_cnt -= 1
        s.indent_str = s.indent_str[0:len(s.indent_str) - len(s.INDENT_STEP)]

    def __exit__(self, exception_type, exception_value, traceback):
        s = self.s
        s.indent_cnt += 1
        s.indent_str = self.original_indent


class AutoIndentingStream():

    def __init__(self, stream, indent_step):
        """
        :param stream: output stream
        :param indent_step: string of indent
        """

        self.INDENT_STEP = indent_step
        self.stream = stream
        self.requires_indent = True
        self.indent_cnt = 0
        self.indent_str = ""

    def write(self, s):
        w = self.stream.write
        if self.requires_indent:
            w(self.indent_str)
        w(s)
        self.requires_indent = s.endswith("\n")


def iter_with_last_flag(it):
    # Ensure it's an iterator and get the first field
    it = iter(it)
    try:
        prev = next(it)
    except StopIteration:
        return
    for item in it:
        # Lag by one item so I know I'm not at the end
        yield False, prev
        prev = item

    # Last item
    yield True, prev


if sys.version_info[0] <= 2:
    def is_str(x):
        return isinstance(x, basestring)
else:
    def is_str(x):
        return isinstance(x, str)
