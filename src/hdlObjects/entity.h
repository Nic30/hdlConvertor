#pragma once
#include "named.h"
#include "variable.h"
#include "port.h"

class Entity: public Named {
public:
	std::vector<Variable*> generics;
	std::vector<Port*> ports;
	Entity();

	PyObject * toJson() const;
	void dump(int indent) const;
};
