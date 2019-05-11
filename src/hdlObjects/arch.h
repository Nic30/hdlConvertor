#pragma once
#include <vector>
#include "named.h"
#include "compInstance.h"
#include "variable.h"
#include "process.h"

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
	std::vector<Statement*> statements;

	~Arch();
};

}
}
