#pragma once
#include <vector>
#include "named.h"
#include "expr.h"

class CompInstance: public Named {
public:
	Expr * entityName;
	std::vector<Expr*> genericMap;
	std::vector<Expr*> portMap;

	CompInstance(char * name, Expr * _entityName);
	PyObject * toJson() const;
};
