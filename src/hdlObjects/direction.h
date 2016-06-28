#pragma once

enum Direction {
	IN, OUT, INOUT, BUFFER, LINKAGE
};

inline const char * Direction_toString(Direction d) {
	switch (d) {
	case IN:
		return "IN";
	case OUT:
		return "OUT";
	case INOUT:
		return "INOUT";
	case BUFFER:
		return "BUFFER";
	case LINKAGE:
		return "LINKAGE";
	default:
		throw "Invalid direction value";
	}
}
