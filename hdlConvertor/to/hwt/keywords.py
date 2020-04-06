import keyword


HWT_KEYWORDS = keyword.kwlist + [
    # imports
    'hwt', 'Unit', "Param", "Signal",
    'power', 'Concat',
    "power", "Concat", "If", "Switch",
    "HArray", "HArrayVal", "Bits", "INT", "SLICE",
    'Bits', "HEnum", "SliceVal",
    "_",
]
