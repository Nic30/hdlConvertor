#pragma once
#include <vector>
#include "named.h"
#include "expr.h"
#include "variable.h"
#include "statement.h"

namespace hdlConvertor {
namespace hdlObjects {

class Function: public WithNameAndDoc {
public:
	const bool isOperator;
	const Expr * returnT;
	const std::vector<Variable*> * params;
	std::vector<Variable*> locals;
	std::vector<Statement*> body;

	Function(char * name, bool isOperator, Expr * returnT,
			std::vector<Variable*> * params);
	~Function();
};

}
}
