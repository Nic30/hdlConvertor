#include "compInstance.h"
#include "../hdlObjects/symbolType.h"

namespace hdlConvertor {
namespace hdlObjects {

CompInstance::CompInstance(Expr * _name, Expr * _entityName) {
	entityName = _entityName;
	name = _name;
}

CompInstance::~CompInstance() {
	for (auto gm : genericMap)
		delete gm;

	for (auto pm : portMap)
		delete pm;
}

}
}
