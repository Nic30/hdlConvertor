#pragma once

#include <vector>
#include <hdlConvertor/hdlObjects/iHdlStatement.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * HDL AST node for expression statement, wrapper around expression which adds label, code position etc.
 * */
class HdlStmExpr: public iHdlStatement {
public:
	std::unique_ptr<iHdlExpr> expr;
	HdlStmExpr(std::unique_ptr<iHdlExpr> expr);
};
}
}
