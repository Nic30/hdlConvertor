#pragma once

#include <Python.h>
#include <vector>
#include <assert.h>

#include "named.h"
#include "entity.h"
#include "function.h"
#include "variable.h"

class aPackage: public Named {
public:
	std::vector<Entity*> components;
	std::vector<Function*> functions;
	std::vector<Variable*> variables;

	aPackage();

	PyObject * toJson() const;
	void dump(int indent) const;
	~aPackage();
};
