#include <hdlConvertor/hdlObjects/hdlCompInstance.h>

#include <hdlConvertor/hdlObjects/hdlValue.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlCompInstance::HdlCompInstance(std::unique_ptr<iHdlExprItem> _name,
		std::unique_ptr<iHdlExprItem> _module_name) {
	module_name = move(_module_name);
	name = move(_name);
}

HdlCompInstance::~HdlCompInstance() {
}

}
}
