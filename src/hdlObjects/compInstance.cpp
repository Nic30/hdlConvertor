#include "compInstance.h"

CompInstance::CompInstance(char * _name, Expr * _entityName) {
	entityName = _entityName;
	name = _name;
}
#ifdef USE_PYTHON
PyObject * CompInstance::toJson() const {
	PyObject * d = Named::toJson();
	PyDict_SetItemString(d, "entityName", entityName->toJson());
	return d;
}
#endif
