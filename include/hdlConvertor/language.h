#pragma once

namespace hdlConvertor {

enum Language {
	VHDL,
	VERILOG1995,
	VERILOG2001,
	VERILOG2001_NOCONFIG,
	VERILOG2005,
	VERILOG = VERILOG2001,
	SV2005,
	SV2009,
	SV2012,
	SV2017,
	SYSTEM_VERILOG = SV2017,
	// [note] the size of this enum is made larger than 1B in order to avoid warnings
	// in cython generated code
	INVALID = 1 << 31
};

}
