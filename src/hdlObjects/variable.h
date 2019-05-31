#pragma once

#include "named.h"
#include "expr.h"

namespace hdlConvertor {
namespace hdlObjects {

class Variable: public WithNameAndDoc {
public:
	Expr * type;
	Expr * value;
	bool latched;

	Variable(std::string id, Expr * type, Expr * val);
	~Variable();
};

}
}
