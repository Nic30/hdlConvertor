#include <hdlConvertor/hdlObjects/hdlStmCase.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlStmCase::HdlStmCase(std::unique_ptr<iHdlExpr> _select_on,
		std::vector<HdlExprAndStm> &_cases) :
		iHdlStatement(), select_on(move(_select_on)), cases(move(_cases)) {
}

HdlStmCase::~HdlStmCase() {
}

}
}
