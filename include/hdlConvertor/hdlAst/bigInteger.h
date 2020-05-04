#pragma once

#include <string>
#include <stdint.h>

namespace hdlConvertor {
namespace hdlAst {

/*
 * Container of the bitstring or the exact integer value
 *
 * @note if bitstring_base == INVALID_BASE the integer value "val" is used
 * 		otherwise the "bitstring" is used
 * */
class BigInteger {
public:
	static constexpr int INVALID_BASE = -1;
	static constexpr int BIN_BASE = 2;
	static constexpr int OCT_BASE = 8;
	static constexpr int DEC_BASE = 10;
	static constexpr int HEX_BASE = 16;
	static constexpr int CHAR_BASE = 256;

	int64_t val;
	std::string bitstring;
	int bitstring_base;

	BigInteger(int64_t v);
	BigInteger(const std::string & _bit_string, int base);

	bool is_bitstring() const;
};


}
}
