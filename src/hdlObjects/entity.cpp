#include "entity.h"

Entity::Entity() :
		Named() {
}
Port * Entity::getPortByName(const char * name) {
	for (auto p : ports) {
		assert(p->variable->name);
		if (strcmp(p->variable->name, name) == 0)
			return p;
	}
	return NULL;
}

#ifdef USE_PYTHON
PyObject * Entity::toJson() const {
	PyObject * d = Named::toJson();
	addJsonArrP(d, "generics", generics);
	addJsonArrP(d, "ports", ports);
	return d;
}
#endif

void Entity::dump(int indent) const {
	Named::dump(indent);
	indent += INDENT_INCR;
	dumpArrP("generics", indent, generics) << ",\n";
	dumpArrP("ports", indent, ports) << "\n";
	mkIndent(indent - INDENT_INCR) << "}";
}

Entity::~Entity() {
	for (auto g : generics)
		delete g;
	for (auto p : ports)
		delete p;
}
