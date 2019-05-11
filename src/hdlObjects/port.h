#pragma once
#include "direction.h"
#include "variable.h"

namespace hdlConvertor {
namespace hdlObjects {

class Port {
public:
	Direction direction;
	Variable * variable;

	Port(Direction direction, Variable * variable);

#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
	void dump(int indent) const;
	~Port();
};

}
}
