#pragma once

namespace hdlConvertor {

enum Language {
	VHDL=0,
	VERILOG1995=1,
	VERILOG2001=2,
	VERILOG2001_NOCONFIG=3,
	VERILOG2005=4,
	VERILOG = VERILOG2001,
	SV2005=5,
	SV2009=6,
	SV2012=7,
	SV2017=8,
	SYSTEM_VERILOG = SV2017,
	// [note] the size of this enum is made larger than 1B in order to avoid warnings
	// in cython generated code
	INVALID = 1 << 31
};

}
