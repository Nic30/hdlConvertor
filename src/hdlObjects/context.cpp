#include "context.h"

#ifdef USE_PYTHON
PyObject * Context::toJson() const {
	PyObject * c = PyDict_New();

	JSN_DEBUG("Context - imports")
	addJsonArrP(c, "imports", imports);

	JSN_DEBUG("Context - entities")
	addJsonArrP(c, "entities", entities);

	JSN_DEBUG("Context - architectures")
	addJsonArrP(c, "architectures", architectures);

	JSN_DEBUG("Context - packages")
	addJsonArrP(c, "packages", packages);

	JSN_DEBUG("Context - packageHeaders")
	addJsonArrP(c, "packageHeaders", packageHeaders);

	JSN_DEBUG("Context - variables")
	addJsonArrP(c, "variables", variables);
	Py_IncRef(c);
	return c;
}
#endif

void Context::dump(int indent) const {
	mkIndent(indent) << "{\n";
	indent += INDENT_INCR;
	dumpArrP("imports", indent, imports) << ",\n";
	dumpArrP("entities", indent, entities) << ",\n";
	dumpArrP("architectures", indent, architectures) << ",\n";
	dumpArrP("packages", indent, packages) << ",\n";
	dumpArrP("packageHeaders", indent, packageHeaders) << ",\n";
	dumpArrP("variables", indent, variables) << ",\n";
	indent -= INDENT_INCR;
	mkIndent(indent) << "}";
}

Context::~Context() {
	for (auto i : imports) {
		delete i;
	}
	for (auto i : entities) {
		delete i;
	}
	for (auto i : architectures) {
		delete i;
	}
	for (auto i : packages) {
		delete i;
	}
	for (auto i : packageHeaders) {
		delete i;
	}
}
