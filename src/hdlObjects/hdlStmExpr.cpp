#include <hdlConvertor/hdlObjects/hdlStmExpr.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlStmExpr::HdlStmExpr(std::unique_ptr<iHdlExprItem> _expr) :
		iHdlStatement(), expr(move(_expr)) {
}


}
}
