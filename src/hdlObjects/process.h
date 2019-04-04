#pragma once

#include <vector>
#include "named.h"
#include "jsonable.h"
#include "statement.h"

/*
 * Class for representation of the process in HDL
 * @note the process may may be described only by statement in HDL
 * 		this means that it does not have to have name or sensitivity list
 * 		specified explicitly
 * */
class Process: public Named {
public:
	bool sensitivity_list_specified;
	std::vector<Expr*> sensitivity_list;
	std::vector<Statement*> statements;

	Process();
#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
	~Process();
};
