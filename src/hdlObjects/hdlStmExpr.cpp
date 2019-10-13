#include <hdlConvertor/hdlObjects/hdlStmExpr.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlStmExpr::HdlStmExpr(std::unique_ptr<iHdlExpr> _expr) :
		iHdlStatement(), expr(move(_expr)) {
}


}
}
