#pragma once

#include "named.h"
#include "expr.h"
#include <memory>

class Variable: public WithNameAndDoc {
public:
	Expr * type;
	Expr * value;
	bool latched;

	Variable(std::string id, Expr * type, Expr * val);
#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
	void dump(int indent) const;
	~Variable();
};
