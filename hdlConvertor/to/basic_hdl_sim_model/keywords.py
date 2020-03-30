import keyword

SIMMODEL_KEYWORDS = keyword.kwlist + [
    # BasicRtlSimModel properties
    'sim',
    '_interfaces',
    '_processes',
    '_units',
    '_outputs',
    '_init_body',
    '__init__',
    '__new__',
    '__getattr__',
    '__getattribute__',
    '__setattr__',
    '__setattribute__',
    # imports
    'pyMathBitPrecise',
    'pycocotb',
    'Array3t',
    'Array3val',
    'Bits3t',
    'Bits3val',
    'define_Enum3t',
    'BasicRtlSimModel',
    'BasicRtlSimProxy',
    'sensitivity',
    'connectSimPort',
    'sim_eval_cond',
    'slice',
]
