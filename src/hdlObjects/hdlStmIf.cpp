#include <hdlConvertor/hdlObjects/hdlStmIf.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlStmIf::HdlStmIf(std::unique_ptr<iHdlExpr> _cond,
		std::unique_ptr<iHdlStatement> _ifTrue) :
		iHdlStatement(), cond(move(_cond)), ifTrue(move(_ifTrue)) {
}

HdlStmIf::HdlStmIf(std::unique_ptr<iHdlExpr> _cond,
		std::unique_ptr<iHdlStatement> _ifTrue,
		std::unique_ptr<iHdlStatement> _ifFalse) :
		iHdlStatement(), cond(move(_cond)), ifTrue(move(_ifTrue)), ifFalse(
				move(_ifFalse)) {
}

HdlStmIf::HdlStmIf(std::unique_ptr<iHdlExpr> _cond,
		std::unique_ptr<iHdlStatement> _ifTrue,
		std::vector<HdlExprAndStm> &_elseIfs,
		std::unique_ptr<iHdlStatement> _ifFalse) :
		iHdlStatement(), cond(move(_cond)), ifTrue(move(_ifTrue)), elseIfs(
				move(_elseIfs)), ifFalse(move(_ifFalse)) {
}

HdlStmIf::~HdlStmIf() {
}

}
}
