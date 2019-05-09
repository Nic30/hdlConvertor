#pragma once
#include <vector>
#include "named.h"
#include "expr.h"

class CompInstance: public WithDoc {
public:
	Expr * name;
	Expr * entityName;
	std::vector<Expr*> genericMap;
	std::vector<Expr*> portMap;

	CompInstance(Expr * name, Expr * _entityName);
#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
	~CompInstance();
};
