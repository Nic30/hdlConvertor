#include <hdlConvertor/hdlAst/hdlStmCase.h>

namespace hdlConvertor {
namespace hdlAst {

const char* HdlStmCaseType_toString(HdlStmCaseType o) {
	switch (o) {
	case HdlStmCaseType::CASE:
		return "CASE";
	case HdlStmCaseType::CASEX:
		return "CASEX";
	case HdlStmCaseType::CASEZ:
		return "CASEZ";
	default:
		throw std::runtime_error(
				"HdlStmCaseType_toString: invalid HdlStmCaseType value");
	}
}

HdlStmCase::HdlStmCase(HdlStmCaseType _type,
		std::unique_ptr<iHdlExprItem> _select_on,
		std::vector<HdlExprAndiHdlObj> &_cases) :
		iHdlStatement(), type(_type), select_on(move(_select_on)), cases(
				move(_cases)) {
}
HdlStmCase::HdlStmCase(HdlStmCaseType _type,
		std::unique_ptr<iHdlExprItem> _select_on,
		std::vector<HdlExprAndiHdlObj> &_cases,
		std::unique_ptr<iHdlObj> _default_) :
		iHdlStatement(), type(_type), select_on(move(_select_on)), cases(
				move(_cases)), default_(move(_default_)) {
}
HdlStmCase::HdlStmCase(std::unique_ptr<iHdlExprItem> _select_on,
		std::vector<HdlExprAndiHdlObj> &_cases) :
		HdlStmCase(HdlStmCaseType::CASE, move(_select_on), _cases) {
}
HdlStmCase::HdlStmCase(std::unique_ptr<iHdlExprItem> _select_on,
		std::vector<HdlExprAndiHdlObj> &_cases,
		std::unique_ptr<iHdlObj> _default_) :
		HdlStmCase(HdlStmCaseType::CASE, move(_select_on), _cases,
				move(_default_)) {
}
HdlStmCase::~HdlStmCase() {
}

}
}
