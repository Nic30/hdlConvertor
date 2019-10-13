#pragma once

#include <hdlConvertor/hdlObjects/iHdlStatement.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * HDL AST node for while-statement
 * */
class HdlStmWhile: public iHdlStatement {
public:
	std::unique_ptr<iHdlExpr> cond;
	std::unique_ptr<iHdlStatement> body;

	HdlStmWhile(std::unique_ptr<iHdlExpr> cond,
			std::unique_ptr<iHdlStatement> body);
	virtual ~HdlStmWhile() override;
};

/*
 * HDL AST node for do-while-statement
 * */
class HdlStmDoWhile: public iHdlStatement {
public:
	std::unique_ptr<iHdlStatement> body;
	std::unique_ptr<iHdlExpr> cond;

	HdlStmDoWhile(std::unique_ptr<iHdlStatement> body,
			std::unique_ptr<iHdlExpr> cond);
	virtual ~HdlStmDoWhile() override;
};
}
}
