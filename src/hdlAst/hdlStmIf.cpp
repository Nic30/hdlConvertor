#include <hdlConvertor/hdlAst/hdlStmIf.h>

namespace hdlConvertor {
namespace hdlAst {

HdlStmIf::HdlStmIf(std::unique_ptr<iHdlExprItem> _cond,
		std::unique_ptr<iHdlObj> _ifTrue) :
		iHdlStatement(), cond(move(_cond)), ifTrue(move(_ifTrue)) {
}

HdlStmIf::HdlStmIf(std::unique_ptr<iHdlExprItem> _cond,
		std::unique_ptr<iHdlObj> _ifTrue,
		std::unique_ptr<iHdlObj> _ifFalse) :
		iHdlStatement(), cond(move(_cond)), ifTrue(move(_ifTrue)), ifFalse(
				move(_ifFalse)) {
}

HdlStmIf::HdlStmIf(std::unique_ptr<iHdlExprItem> _cond,
		std::unique_ptr<iHdlObj> _ifTrue,
		std::vector<HdlExprAndiHdlObj> &_elseIfs,
		std::unique_ptr<iHdlObj> _ifFalse) :
		iHdlStatement(), cond(move(_cond)), ifTrue(move(_ifTrue)), elseIfs(
				move(_elseIfs)), ifFalse(move(_ifFalse)) {
}

HdlStmIf::~HdlStmIf() {
}

}
}
