import sys
from hdlConvertor.hdlAst._expr import HdlIntValue


class Indent(object):
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


def iter_with_last(it):
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


def bit_string(v, width, vld_mask=None):
    """
    :type v: int
    :type width: int
    :type vld_mask: Optional[int]
    :param v: integer value of bitstring
    :param widht: number of bits in value
    :param vld_mask: mask which has 1 for every valid bit in value
    :return: HdlIntValue
    """
    all_mask = (1 << width) - 1
    if vld_mask is None:
        vld_mask = all_mask

    # if vld_mask == 0:
    #     if width % 4 == 0:
    #         base = 16
    #         bit_string = "".join(["x" for _ in range(width//4)])
    #     else:
    #         base = 2
    #         bit_string = "".join(["x" for _ in range(width)])

    elif width % 4 == 0 and vld_mask == (1 << width) - 1:
        # hex full valid
        base = 16
        bit_string = ("%0" + str(width // 4) + 'x') % (v)
    else:
        # binary
        base = 2
        buff = []
        for i in range(width - 1, -1, -1):
            mask = (1 << i)
            b = v & mask

            if vld_mask & mask:
                s = "1" if b else "0"
            else:
                s = "x"
            buff.append(s)
        bit_string = "".join(buff)
    return HdlIntValue(bit_string, width, base)
