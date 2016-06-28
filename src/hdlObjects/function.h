#pragma once
#include <vector>
#include "named.h"
#include "expr.h"
#include "variable.h"
#include "statement.h"

class Function: public Named {
	bool isOperator;
	Expr * returnT;
	std::vector<Variable*> * params;
public:
	std::vector<Variable*> locals;
	std::vector<Statement*> body;

	Function(
			char * name,
			bool isOperator,
			Expr * returnT,
			std::vector<Variable*> * params);

	PyObject * toJson() const;
};
