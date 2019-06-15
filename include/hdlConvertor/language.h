#pragma once

namespace hdlConvertor {

enum Language {
	VHDL, VERILOG, SYSTEM_VERILOG,
	VERILOG2001, VERILOG2005, SV2012, SV2017,

	// [note] the size of this enum is made larger than 1B in order to avoid warnings
	// in cython generated code
	INVALID=1<<31
};

}
