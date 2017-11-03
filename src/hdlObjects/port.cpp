#include "port.h"

Port::Port(Direction direction, Variable * variable) {
	this->direction = direction;
	this->variable = variable;
}

#ifdef USE_PYTHON
PyObject * Port::toJson() const {
	PyObject *d = PyDict_New();
	PyDict_SetItemString(d, "direction",
			PyUnicode_FromString(Direction_toString(direction)));
	PyDict_SetItemString(d, "variable", variable->toJson());
	return d;
}
#endif

void Port::dump(int indent) const {
	std::cout << "{\n";
	indent += INDENT_INCR;
	dumpVal("direction", indent, Direction_toString(direction)) << ",\n";
	dumpKey("variable", indent);
	variable->dump(indent);
	std::cout << "\n";
	mkIndent(indent - INDENT_INCR) << "}";
}

Port::~Port() {
	if (variable)
		delete variable;
}
