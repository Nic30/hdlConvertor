#pragma once

#include <vector>
#include "jsonable.h"
#include <assert.h>
#include "named.h"
#include "expr.h"
#include "function.h"
#include "variable.h"
#include "statement.h"
#include "position.h"

class Process {
public:
	const char * name = NULL;
	Position * position = NULL;

	std::vector<Function*> function_headers;
	std::vector<Function*> functions;
	std::vector<Variable*> subtype_headers;
	std::vector<Variable*> constants;
	std::vector<Variable*> variables;
	std::vector<Expr*> sensitivities;
	std::vector<Statement*> body;

	Process();
#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
	void dump(int indent) const;
	~Process();
};
