#include <hdlConvertor/hdlAst/hdlCompInst.h>

#include <hdlConvertor/hdlAst/hdlValue.h>

namespace hdlConvertor {
namespace hdlAst {

HdlCompInst::HdlCompInst(std::unique_ptr<iHdlExprItem> _name,
		std::unique_ptr<iHdlExprItem> _module_name) {
	module_name = move(_module_name);
	name = move(_name);
}

HdlCompInst::~HdlCompInst() {
}

}
}
