#pragma once
#include <vector>
#include "named.h"
#include "compInstance.h"
#include "entity.h"
#include "function.h"
#include "variable.h"
#include "jsonable.h"
#include "process.h"
#include "position.h"

enum GenerateType {
	g_NONE, g_IF, g_ELSIF, g_ELSE, g_CASE, g_WHILE, g_FOR
};

class Generate {
public:
	const char * name = NULL;
	Position * position = NULL;
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
#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
	void dump(int indent) const;
	~Generate();
};
