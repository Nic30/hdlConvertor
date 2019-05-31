#pragma once

#include <vector>
#include "named.h"
#include "iHdlObj.h"

namespace hdlConvertor {
namespace hdlObjects {

// [TODO] change to namespace
class aPackage: public WithNameAndDoc, public iHdlObj {
public:

	std::vector<iHdlObj*> objs;
	//std::vector<Entity*> components;
	//std::vector<Function*> function_headers;
	//std::vector<Function*> functions;
	//std::vector<Variable*> subtype_headers;
	//std::vector<Variable*> signals;
	//std::vector<Variable*> constants;
	//std::vector<Variable*> variables;

	aPackage();
	~aPackage();
};

}
}
