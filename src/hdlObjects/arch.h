#pragma once
#include <vector>
#include "named.h"
#include "compInstance.h"
#include "jsonable.h"
#include "variable.h"
#include "process.h"

class Arch: public Named {
public:
	const char * entityName;
	std::vector<Variable*> varialbles;
	std::vector<CompInstance*> componentInstances;
	std::vector<Statement*> statements;

#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
	~Arch();
};
