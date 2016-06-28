#pragma once
#include <Python.h>
#include "direction.h"
#include "variable.h"

class Port {
public:
	Direction direction;
	Variable * variable;

	PyObject * toJson() const;
	void dump(int indent) const;
};
