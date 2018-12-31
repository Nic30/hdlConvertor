#include "aPackage.h"
#include "jsonable.h"

using namespace std;

aPackage::aPackage() :
		Named() {
}
#ifdef USE_PYTHON
PyObject * aPackage::toJson() const {
	PyObject *d = Named::toJson();
	JSN_DEBUG("aPackage - components")
	addJsonArrP(d, "components", components);

	JSN_DEBUG("aPackage - function_headers")
	addJsonArrP(d, "function_headers", function_headers);

	JSN_DEBUG("aPackage - functions")
	addJsonArrP(d, "functions", functions);

	JSN_DEBUG("aPackage - subtype_headers")
	addJsonArrP(d, "subtype_headers", subtype_headers);

	JSN_DEBUG("aPackage - constants")
	addJsonArrP(d, "signals", signals);

	JSN_DEBUG("aPackage - constants")
	addJsonArrP(d, "constants", constants);

	JSN_DEBUG("aPackage - variable")
	addJsonArrP(d, "variables", variables);

	Py_INCREF(d);
	return d;
}
#endif
void aPackage::dump(int indent) const {
	Named::dump(indent);
	indent += INDENT_INCR;
	dumpArrP("components", indent, components) << ",\n";
	dumpArrP("function_headers", indent, function_headers) << ",\n";
	dumpArrP("functions", indent, functions) << ",\n";
	dumpArrP("subtype_headers", indent, subtype_headers) << ",\n";
	dumpArrP("signals", indent, signals) << ",\n";			
	dumpArrP("constants", indent, constants) << ",\n";
	dumpArrP("variables", indent, variables) << ",\n";
	indent -= INDENT_INCR;
	mkIndent(indent) << "}";
}

aPackage::~aPackage() {
	for (auto c : components)
		delete c;
	for (auto f : function_headers)
		delete f;
	for (auto f : functions)
		delete f;
	for (auto s: subtype_headers)
		delete s;		
	for (auto f : variables)
		delete f;
	for (auto s : signals)
		delete s;	
}
