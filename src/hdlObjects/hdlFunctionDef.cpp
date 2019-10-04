#include <hdlConvertor/hdlObjects/hdlFunctionDef.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlFunctionDef::HdlFunctionDef(const std::string &name, bool isOperator,
		iHdlExpr *returnT, std::vector<HdlVariableDef*> *params) :
		WithNameAndDoc(name), returnT(returnT), params(params), is_operator(
				isOperator), is_static(false), is_virtual(false), is_task(
				false), is_declaration_only(true) {
}

HdlFunctionDef::~HdlFunctionDef() {
	for (auto p : *params)
		delete p;
	delete params;

	for (auto b : body)
		delete b;

}

}
}
