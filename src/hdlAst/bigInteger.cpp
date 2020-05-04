#include <hdlConvertor/hdlAst/bigInteger.h>

namespace hdlConvertor {
namespace hdlAst {

BigInteger::BigInteger(int64_t v) :
		val(v), bitstring(), bitstring_base(INVALID_BASE) {
}

BigInteger::BigInteger(const std::string & _bit_string, int base) :
		val(0), bitstring(_bit_string), bitstring_base(base) {
}

bool BigInteger::is_bitstring() const {
	return bitstring_base != BigInteger::INVALID_BASE;
}

}
}
