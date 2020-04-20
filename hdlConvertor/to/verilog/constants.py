from enum import Enum


class SIGNAL_TYPE(Enum):
    WIRE, REG, PORT_WIRE, PORT_REG = range(4)
