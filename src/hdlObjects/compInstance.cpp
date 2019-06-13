#include <hdlConvertor/hdlObjects/compInstance.h>

#include <hdlConvertor/hdlObjects/literalVal.h>

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
