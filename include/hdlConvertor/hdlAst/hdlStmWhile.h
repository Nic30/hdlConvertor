#pragma once

#include <hdlConvertor/hdlAst/iHdlStatement.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>

namespace hdlConvertor {
namespace hdlAst {

/*
 * HDL AST node for while-statement
 * */
class HdlStmWhile: public iHdlStatement {
public:
	std::unique_ptr<iHdlExprItem> cond;
	std::unique_ptr<iHdlStatement> body;

	HdlStmWhile(std::unique_ptr<iHdlExprItem> cond,
			std::unique_ptr<iHdlStatement> body);
	virtual ~HdlStmWhile() override;
};

/*
 * HDL AST node for do-while-statement
 * */
class HdlStmDoWhile: public iHdlStatement {
public:
	std::unique_ptr<iHdlStatement> body;
	std::unique_ptr<iHdlExprItem> cond;

	HdlStmDoWhile(std::unique_ptr<iHdlStatement> body,
			std::unique_ptr<iHdlExprItem> cond);
	virtual ~HdlStmDoWhile() override;
};
}
}
