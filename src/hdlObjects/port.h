#pragma once
#include "direction.h"
#include "variable.h"

class Port {
public:
	Direction direction;
	Variable * variable;
#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
	void dump(int indent) const;
};
