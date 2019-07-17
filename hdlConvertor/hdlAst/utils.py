

class CodePosition(object):
    __slots__ = ["startLine", "stopLine", "startColumn", "stopColumn"]

    def __init__(self, startLine, stopLine, startColumn, stopColumn):
        self.startLine = startLine  # type: int
        self.stopLine = stopLine  # type: int
        self.startColumn = startColumn  # type: int
        self.stopColumn = stopColumn  # type: int
