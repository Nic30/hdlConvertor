#include "aPackage.h"
#include "jsonable.h"

using namespace std;

aPackage::aPackage() :
		Named() {
}
#ifdef USE_PYTHON
PyObject * aPackage::toJson() const {
	PyObject *d = Named::toJson();
	addJsonArrP(d, "components", components);
	addJsonArrP(d, "functions", functions);
	addJsonArrP(d, "variables", variables);
	Py_INCREF(d);
	return d;
}
#endif
void aPackage::dump(int indent) const {
	Named::dump(indent);
	indent += INDENT_INCR;
	dumpArrP("components", indent, components) << ",\n";
	dumpArrP("functions", indent, functions) << "\n";
	dumpArrP("variables", indent, variables) << ",\n";
	indent -= INDENT_INCR;
	mkIndent(indent) << "}";
}

aPackage::~aPackage() {

	for (auto c : components)
		delete c;

	for (auto f : functions)
		delete f;

}
