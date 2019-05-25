#pragma once

#include <vector>
#include "named.h"
#include "statement.h"
#include "statement.h"
#include "function.h"
#include "variable.h"
#include "position.h"

namespace hdlConvertor {
namespace hdlObjects {

/*
 * Class for representation of the process in HDL
 * @note the process may may be described only by statement in HDL
 * 		this means that it does not have to have name or sensitivity list
 * 		specified explicitly
 * */
class Process: public WithNameAndDoc {
public:

	bool sensitivity_list_specified;
	std::vector<Expr*> sensitivity_list;
	std::vector<Statement*> statements;

	std::vector<Function*> function_headers;
	std::vector<Function*> functions;
	std::vector<Variable*> subtype_headers;
	std::vector<Variable*> constants;
	std::vector<Variable*> variables;

	Process();
	~Process();
};

}
}


