#pragma once
#include <vector>
#include "named.h"
#include "expr.h"
#include "position.h"

class CompInstance: public Named {
public:
	Expr * entityName;
	Position * position = NULL;	
	std::vector<Expr*> genericMap;
	std::vector<Expr*> portMap;

	CompInstance(char * name, Expr * _entityName);
#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
	~CompInstance();
};
