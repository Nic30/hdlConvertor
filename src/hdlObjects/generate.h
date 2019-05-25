#pragma once

#include <vector>
#include "named.h"
#include "compInstance.h"
#include "entity.h"
#include "function.h"
#include "variable.h"
#include "process.h"
#include "position.h"

namespace hdlConvertor {
namespace hdlObjects {

enum GenerateType {
	g_NONE, g_IF, g_ELSIF, g_ELSE, g_CASE, g_WHILE, g_FOR
};
const char * GenerateType_toString(GenerateType type);

// [TODO] use regular statement but set compile time flag
class Generate : public WithNameAndDoc {
public:
	GenerateType type;
	std::vector<CompInstance*> componentInstances;
	std::vector<Entity*> components;
	std::vector<Function*> function_headers;
	std::vector<Function*> functions;
	std::vector<Variable*> subtype_headers;
	std::vector<Variable*> variables;
	std::vector<Variable*> signals;
	std::vector<Variable*> constants;
	std::vector<Process*> processes;
    std::vector<Generate*> generates;
    Generate();
    ~Generate();
};

}
}
