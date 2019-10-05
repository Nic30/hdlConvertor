#include <hdlConvertor/hdlObjects/hdlCompInstance.h>

#include <hdlConvertor/hdlObjects/hdlValue.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlCompInstance::HdlCompInstance(std::unique_ptr<iHdlExpr> _name,
		std::unique_ptr<iHdlExpr> _entityName) {
	entityName = move(_entityName);
	name = move(_name);
}

HdlCompInstance::~HdlCompInstance() {
}

}
}
