#include <hdlConvertor/hdlObjects/hdlCompInstance.h>

#include <hdlConvertor/hdlObjects/hdlValue.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlCompInstance::HdlCompInstance(const std::string & _name,
		std::unique_ptr<iHdlExpr> _module_name): WithNameAndDoc(_name) {
	module_name = move(_module_name);
}

HdlCompInstance::~HdlCompInstance() {
}

}
}
