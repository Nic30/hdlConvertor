#pragma once
#include "direction.h"
#include "variable.h"
#include "position.h"

class Port {
public:
	Direction direction;
	Variable * variable;
	Position * position = NULL;

	Port(Direction direction, Variable * variable);

#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
	void dump(int indent) const;
	~Port();
};
