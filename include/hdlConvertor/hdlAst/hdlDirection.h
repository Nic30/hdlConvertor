#pragma once

namespace hdlConvertor {
namespace hdlAst {

enum HdlDirection {
	DIR_IN,
	DIR_OUT,
	DIR_INOUT,
	DIR_BUFFER,
	DIR_LINKAGE,
	DIR_INTERNAL,
	DIR_UNKNOWN,
};

inline const char* HdlDirection_toString(HdlDirection d) {
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
	case DIR_INTERNAL:
		return "INTERNAL";
	default:
		throw std::runtime_error("Invalid direction value");
	}
}

}
}
