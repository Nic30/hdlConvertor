
class CodePosition(object):
    __slots__ = [
        "start_line",
        "start_column",
        "stop_line",
        "stop_column",
    ]

    def __init__(self):
        self.start_line = None
        self.start_column = None
        self.stop_line = None
        self.stop_column = None
