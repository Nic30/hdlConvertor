#pragma once

#include <vector>
#include <hdlConvertor/hdlObjects/iHdlStatement.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * HDL AST node for assignment statement
 * */
class HdlStmAssign: public iHdlStatement {
public:
	bool is_blocking;
	HdlStmAssign(iHdlExpr *dst, iHdlExpr *src, bool _is_blocking);
	HdlStmAssign(iHdlExpr *dst, iHdlExpr *src, iHdlExpr *time_delay,
			std::vector<iHdlExpr*> *event_delay, bool _is_blocking = false);
};

}
}
