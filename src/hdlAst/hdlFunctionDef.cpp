#include <hdlConvertor/hdlAst/hdlFunctionDef.h>

namespace hdlConvertor {
namespace hdlAst {

HdlFunctionDef::HdlFunctionDef(const std::string &name, bool isOperator,
		std::unique_ptr<iHdlExprItem> returnT,
		std::unique_ptr<std::vector<std::unique_ptr<HdlIdDef>>> params) :
		HdlIdDef(name, nullptr, nullptr), returnT(move(returnT)), params(move(params)), is_operator(
				isOperator), is_static(false), is_virtual(false), is_task(
				false), is_declaration_only(true) {
	if (!params) {
		params =
				std::make_unique<std::vector<std::unique_ptr<HdlIdDef>>>();
	}
}

HdlFunctionDef::~HdlFunctionDef() {
}

}
}
