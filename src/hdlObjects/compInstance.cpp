#include "compInstance.h"

CompInstance::CompInstance(Expr * _name, Expr * _entityName) {
	entityName = _entityName;
	name = _name;
}

#ifdef USE_PYTHON
PyObject * CompInstance::toJson() const {
	PyObject * d = WithDoc::toJson();
	PyDict_SetItemString(d, "name", name->toJson());
	PyDict_SetItemString(d, "entityName", entityName->toJson());
	return d;
}
#endif

CompInstance::~CompInstance() {
	for (auto gm : genericMap)
		delete gm;

	for (auto pm : portMap)
		delete pm;
}
