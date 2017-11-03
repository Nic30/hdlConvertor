#pragma once

enum Direction {
	DIR_IN, DIR_OUT, DIR_INOUT, DIR_BUFFER, DIR_LINKAGE, DIR_UNKNOWN,
};

inline const char * Direction_toString(Direction d) {
	switch (d) {
	case DIR_IN:
		return "IN";
	case DIR_OUT:
		return "OUT";
	case DIR_INOUT:
		return "INOUT";
	case DIR_BUFFER:
		return "BUFFER";
	case DIR_LINKAGE:
		return "LINKAGE";
	default:
		throw "Invalid direction value";
	}
}
