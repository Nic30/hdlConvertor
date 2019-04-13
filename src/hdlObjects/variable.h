#pragma once

#include "named.h"
#include "expr.h"
#include <memory>

class Variable: public Named {
public:
	std::shared_ptr<Expr> type;
	Expr * value;

	Variable(std::string id, const std::shared_ptr<Expr> & type, Expr * val);
#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
	void dump(int indent) const;
	~Variable();
};
