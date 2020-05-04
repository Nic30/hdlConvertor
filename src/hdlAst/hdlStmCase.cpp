#include <hdlConvertor/hdlAst/hdlStmCase.h>

namespace hdlConvertor {
namespace hdlAst {

HdlStmCase::HdlStmCase(std::unique_ptr<iHdlExprItem> _select_on,
		std::vector<HdlExprAndiHdlObj> &_cases) :
		iHdlStatement(), select_on(move(_select_on)), cases(move(_cases)) {
}
HdlStmCase::HdlStmCase(std::unique_ptr<iHdlExprItem> _select_on,
		std::vector<HdlExprAndiHdlObj> &_cases,
		std::unique_ptr<iHdlObj> _default_) :
		iHdlStatement(), select_on(move(_select_on)), cases(move(_cases)), default_(
				move(_default_)) {
}

HdlStmCase::~HdlStmCase() {
}

}
}
