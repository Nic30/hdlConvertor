#include <hdlConvertor/hdlObjects/hdlStmWhile.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlStmWhile::HdlStmWhile(std::unique_ptr<iHdlExpr> _cond,
		std::unique_ptr<iHdlStatement> _body) :
		iHdlStatement(), cond(move(_cond)), body(move(_body)) {
}

HdlStmWhile::~HdlStmWhile() {
}

HdlStmDoWhile::HdlStmDoWhile(std::unique_ptr<iHdlStatement> _body,
		std::unique_ptr<iHdlExpr> _cond) :
		iHdlStatement(), body(move(_body)), cond(move(_cond)) {
}

HdlStmDoWhile::~HdlStmDoWhile() {
}

}
}
