#pragma once

#include <vector>
#include <hdlConvertor/hdlAst/iHdlStatement.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>

namespace hdlConvertor {
namespace hdlAst {

/*
 * HDL AST node for expression statement, wrapper around expression which adds label, code position etc.
 * */
class HdlStmExpr: public iHdlStatement {
public:
	std::unique_ptr<iHdlExprItem> expr;
	HdlStmExpr(std::unique_ptr<iHdlExprItem> expr);
};
}
}
