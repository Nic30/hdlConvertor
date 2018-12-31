#include "arch.h"

#ifdef USE_PYTHON
PyObject * Arch::toJson() const {
	PyObject * o = Named::toJson();
	JSN_DEBUG("Arch - name")
	PyDict_SetItemString(o, "name", PyUnicode_FromString(name));

	JSN_DEBUG("Arch - entityName")
	PyDict_SetItemString(o, "entityName", PyUnicode_FromString(entityName));

	if (position) {
		JSN_DEBUG("Arch - position")
		PyDict_SetItemString(o, "position", position->toJson());
	} else {
		Py_IncRef (Py_None);
		PyDict_SetItemString(o, "position", Py_None);
	}

	JSN_DEBUG("Arch - componentInstances")
	addJsonArrP(o, "componentInstances", componentInstances);

	JSN_DEBUG("Arch - components")
	addJsonArrP(o, "components", components);

	JSN_DEBUG("Arch - function_headers")
	addJsonArrP(o, "function_headers", function_headers);

	JSN_DEBUG("Arch - functions")
	addJsonArrP(o, "functions", functions);

	JSN_DEBUG("Arch - subtype_headers")
	addJsonArrP(o, "subtype_headers", subtype_headers);

	JSN_DEBUG("Arch - variables")
	addJsonArrP(o, "variables", variables);

	JSN_DEBUG("Arch - signals")
	addJsonArrP(o, "signals", signals);

	JSN_DEBUG("Arch - constants")
	addJsonArrP(o, "constants", constants);

	JSN_DEBUG("Arch - processes")
	addJsonArrP(o, "processes", processes);

	JSN_DEBUG("Arch - generates")
	addJsonArrP(o, "generates", generates);

	return o;
}
#endif

Arch::~Arch() {
	for (auto c : componentInstances)
		delete c;

	for (auto c : components)
		delete c;
	for (auto c : constants)
		delete c;		
	for (auto fh : function_headers)
		delete fh;
	for (auto f : functions)
		delete f;
	for (auto sh : subtype_headers)
		delete sh;				
	for (auto v : variables)
		delete v;	
	for (auto p : processes)
		delete p;	
	for (auto g : generates)
		delete g;			
}
