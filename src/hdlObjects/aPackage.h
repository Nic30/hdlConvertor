#pragma once

#include <vector>
#include <assert.h>
#include <string>

#include "named.h"
#include "entity.h"
#include "function.h"
#include "variable.h"

namespace hdlConvertor {
namespace hdlObjects {

class aPackage: public WithNameAndDoc {
public:
	std::vector<Entity*> components;
	std::vector<Function*> functions;
	std::vector<Variable*> variables;

	aPackage();
	~aPackage();
};

}
}
