#include "variable.h"

namespace hdlConvertor {
namespace hdlObjects {

Variable::Variable(std::string id, Expr * _type, Expr * val) {
	name = strdup(id.c_str());
	type = _type;
	value = val;
	latched = false;
}

Variable::~Variable() {
	if (value)
		delete value;
}

}
}
