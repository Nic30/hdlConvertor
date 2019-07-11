#include <hdlConvertor/hdlObjects/hdlCompInstance.h>

#include <hdlConvertor/hdlObjects/hdlValue.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlCompInstance::HdlCompInstance(iHdlExpr * _name, iHdlExpr * _entityName) {
	entityName = _entityName;
	name = _name;
}

HdlCompInstance::~HdlCompInstance() {
	for (auto gm : genericMap)
		delete gm;

	for (auto pm : portMap)
		delete pm;
}

}
}
