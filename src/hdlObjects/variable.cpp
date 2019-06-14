#include <hdlConvertor/hdlObjects/variable.h>

namespace hdlConvertor {
namespace hdlObjects {

Variable::Variable(const std::string & id, Expr * _type, Expr * val) {
	name = id;
	type = _type;
	value = val;
	latched = false;
	is_const = false;
	direction = Direction::DIR_INTERNAL;
}

Variable::~Variable() {
	if (value)
		delete value;
}

}
}
