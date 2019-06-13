#pragma once

#include <string>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * Container of the bitstring or the exact integer value
 *
 * @note if bitstring_base == INVALID_BASE the integer value "val" is used
 * 		otherwise the "bitstring" is used
 * */
class BigInteger {
public:
	static constexpr int INVALID_BASE = -1;
	int64_t val;
	std::string bitstring;
	int bitstring_base;

	BigInteger(int64_t v);
	BigInteger(const std::string & _bit_string, int base);

	bool is_bitstring() const;
};


}
}
