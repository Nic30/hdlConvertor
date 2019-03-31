#include "arch.h"

#ifdef USE_PYTHON
PyObject * Arch::toJson() const {
	JSN_DEBUG("Arch - name")
	PyObject * o = Named::toJson();

	JSN_DEBUG("Arch - entityName")
	if (entityName)
		PyDict_SetItemString(o, "entityName", PyUnicode_FromString(entityName));

	JSN_DEBUG("Arch - variables")
	addJsonArrP(o, "variables", varialbles);

	JSN_DEBUG("Arch - componentInstances")
	addJsonArrP(o, "componentInstances", componentInstances);

	JSN_DEBUG("Arch - statements")
	addJsonArrP(o, "statements", statements);

	return o;
}
#endif

Arch::~Arch() {
	for (auto c : componentInstances)
		delete c;
	for (auto s : statements)
		delete s;
	for (auto v : varialbles)
		delete v;
}
