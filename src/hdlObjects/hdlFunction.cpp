#include <hdlConvertor/hdlObjects/hdlFunction.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlFunction::HdlFunction(const std::string & name, bool isOperator,
		iHdlExpr * returnT, std::vector<HdlVariableDef*> * params) :
		WithNameAndDoc(name), returnT(returnT), params(params), is_operator(
				isOperator), declaration_only(true) {
}

HdlFunction::~HdlFunction() {
	for (auto p : *params)
		delete p;
	delete params;

	for (auto l : locals)
		delete l;

	for (auto b : body)
		delete b;

}

}
}
