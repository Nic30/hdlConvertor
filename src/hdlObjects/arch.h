#pragma once
#include <vector>
#include "named.h"
#include "compInstance.h"
#include "variable.h"
#include "process.h"
#include "entity.h"
#include "function.h"
#include "variable.h"
#include "process.h"
#include "position.h"
#include "generate.h"

namespace hdlConvertor {
namespace hdlObjects {

/*
 * The container for the vhdl architecture or the body of the module in verilog
 * */
class Arch: public WithNameAndDoc {
public:
	const char * entityName;

	std::vector<Variable*> variables;
	std::vector<CompInstance*> componentInstances;
	std::vector<Entity*> components;
	std::vector<Function*> function_headers;
	std::vector<Function*> functions;
	std::vector<Variable*> subtype_headers;
	std::vector<Variable*> signals;
	std::vector<Variable*> constants;

	std::vector<Statement*> statements;
	std::vector<Process*> processes;
	std::vector<Generate*> generates;

	~Arch();
};

}
}
