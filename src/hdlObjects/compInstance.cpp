#include "compInstance.h"
#include "../hdlObjects/symbolType.h"

namespace hdlConvertor {
namespace hdlObjects {

CompInstance::CompInstance(Expr * _name, Expr * _entityName) {
	entityName = _entityName;
	name = _name;
}

#ifdef USE_PYTHON
PyObject * CompInstance::toJson() const {
	PyObject * d = WithDoc::toJson();
	char * name_str = nullptr;
	Symbol * name_lit = dynamic_cast<Symbol*>(name->data);
	if (name_lit && name_lit->type == SymbolType::symb_ID) {
		name_str = name_lit->value._str;
	}
	if (name_str)
		PyDict_SetItemString(d, "name", PyUnicode_FromString(name_str));
	else
		PyDict_SetItemString(d, "name", name->toJson());

	PyDict_SetItemString(d, "entityName", entityName->toJson());
	addJsonArrP(d, "portMap", portMap);
	addJsonArrP(d, "genericMap", genericMap);

	return d;
}
#endif

CompInstance::~CompInstance() {
	for (auto gm : genericMap)
		delete gm;

	for (auto pm : portMap)
		delete pm;
}

}
}
