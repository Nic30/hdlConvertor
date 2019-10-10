#include <hdlConvertor/hdlObjects/hdlFunctionDef.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlFunctionDef::HdlFunctionDef(const std::string &name, bool isOperator,
		std::unique_ptr<iHdlExpr> returnT,
		std::unique_ptr<std::vector<std::unique_ptr<HdlVariableDef>>> params) :
		WithNameAndDoc(name), returnT(move(returnT)), params(move(params)), is_operator(
				isOperator), is_static(false), is_virtual(false), is_task(
				false), is_declaration_only(true) {
	if (!params) {
		params =
				std::make_unique<std::vector<std::unique_ptr<HdlVariableDef>>>();
	}
}

HdlFunctionDef::~HdlFunctionDef() {
}

}
}
