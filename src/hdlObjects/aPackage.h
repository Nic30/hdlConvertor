#pragma once

#include <vector>
#include <assert.h>
#include "entity.h"
#include "named.h"
#include "expr.h"
#include "function.h"
#include "variable.h"
#include "statement.h"

namespace hdlConvertor {
namespace hdlObjects {

class aPackage: public WithNameAndDoc {
public:
	std::vector<Entity*> components;
	std::vector<Function*> function_headers;
	std::vector<Function*> functions;
	std::vector<Variable*> subtype_headers;
	std::vector<Variable*> signals;
	std::vector<Variable*> constants;
	std::vector<Variable*> variables;

	aPackage();
	~aPackage();
};

}
}
