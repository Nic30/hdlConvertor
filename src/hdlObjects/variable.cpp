#include "variable.h"

namespace hdlConvertor {
namespace hdlObjects {

Variable::Variable(std::string id, Expr * _type, Expr * val) {
	name = strdup(id.c_str());
	type = _type;
	value = val;
	latched = false;
}

#ifdef USE_PYTHON
PyObject* Variable::toJson() const {
	PyObject * d = WithNameAndDoc::toJson();
	if (!type)
		throw std::runtime_error("Variable has no type");

	PyDict_SetItemString(d, "type", type->toJson());

	if (value) {
		PyDict_SetItemString(d, "value", value->toJson());
	} else {
		Py_IncRef(Py_None);
		PyDict_SetItemString(d, "value", Py_None);
	}
	if (latched) {
		Py_IncRef(Py_True);
		PyDict_SetItemString(d, "latched", Py_True);
	}
	return d;
}
#endif

void Variable::dump(int indent) const {
	WithNameAndDoc::dump(indent);
	indent += INDENT_INCR;
	dumpKey("type", indent);
	type->dump(indent);
	std::cout << ",\n";

	if (value) {
		dumpKey("value", indent) << "\n";
		value->dump(indent);
	} else {
		dumpVal("value", indent, "None");
	}
	mkIndent(indent - INDENT_INCR) << "}";
}

Variable::~Variable() {
	if (value)
		delete value;
}

}
}
