#include <hdlConvertor/hdlAst/hdlStmExpr.h>

namespace hdlConvertor {
namespace hdlAst {

HdlStmExpr::HdlStmExpr(std::unique_ptr<iHdlExprItem> _expr) :
		iHdlStatement(), expr(move(_expr)) {
}


}
}
