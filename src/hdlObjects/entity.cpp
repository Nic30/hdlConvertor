#include "entity.h"

Entity::Entity() :
		Named() {
}

PyObject * Entity::toJson() const {
	PyObject * d = Named::toJson();
	addJsonArrP(d, "generics", generics);
	addJsonArrP(d, "ports", ports);
	Py_INCREF(d);
	return d;
}

void Entity::dump(int indent) const {
	Named::dump(indent);
	indent += INDENT_INCR;
	dumpArrP("generics", indent, generics) << ",\n";
	dumpArrP("ports", indent, ports) << "\n";
	mkIndent(indent - INDENT_INCR) << "}";
}
