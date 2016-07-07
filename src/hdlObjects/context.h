#pragma once

#include <vector>
#include "jsonable.h"
#include "expr.h"
#include "entity.h"
#include "arch.h"
#include "package.h"
#include "packageHeader.h"

class Context {
public:
	std::vector<Expr*> imports;
	std::vector<Entity*> entities;
	std::vector<Arch*> architectures;
	std::vector<Package*> packages;
	std::vector<PackageHeader*> packageHeaders;
	std::vector<Variable*> variables; // not ideal - variable can be type, constant, signal etc...
#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
	void dump(int indent) const;
	~Context();
};
