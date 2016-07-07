#pragma once

#include "named.h"
#include "expr.h"

class Variable: public Named {
public:
	Expr * type;
	Expr * value;

	Variable(std::string id, Expr * type, Expr * val);
#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
	void dump(int indent) const;
};
