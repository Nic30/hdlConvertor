#include "compInstance.h"

CompInstance::CompInstance(char * _name, Expr * _entityName) {
	entityName = _entityName;
	name = _name;
}
#ifdef USE_PYTHON
PyObject * CompInstance::toJson() const {
	PyObject * d = Named::toJson();
	JSN_DEBUG("CompInstance - entityName")
	PyDict_SetItemString(d, "entityName", entityName->toJson());

	if (position) {
		JSN_DEBUG("CompInstance - position")
		PyDict_SetItemString(d, "position", position->toJson());
	} else {
		Py_IncRef (Py_None);
		PyDict_SetItemString(d, "position", Py_None);
	}

	JSN_DEBUG("CompInstance - genericMap")
	addJsonArrP(d, "genericMap", genericMap);

	JSN_DEBUG("CompInstance - portMap")
	addJsonArrP(d, "portMap", portMap);

	return d;
}
#endif

CompInstance::~CompInstance() {
	for (auto gm : genericMap)
		delete gm;

	for (auto pm : portMap)
		delete pm;
}
