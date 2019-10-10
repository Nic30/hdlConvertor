#pragma once

#include <hdlConvertor/hdlObjects/iHdlStatement.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * HDL AST node for conditional statement
 * */
class HdlStmIf: public iHdlStatement {
public:
	std::unique_ptr<iHdlExpr> cond;
	std::unique_ptr<iHdlStatement> ifTrue;
	std::vector<HdlExprAndStm> elseIfs;
	std::unique_ptr<iHdlStatement> ifFalse;

	HdlStmIf(std::unique_ptr<iHdlExpr> cond,
			std::unique_ptr<iHdlStatement> ifTrue);
	HdlStmIf(std::unique_ptr<iHdlExpr> cond,
			std::unique_ptr<iHdlStatement> ifTrue,
			std::unique_ptr<iHdlStatement> ifFalse);
	HdlStmIf(std::unique_ptr<iHdlExpr> cond,
			std::unique_ptr<iHdlStatement> ifTrue,
			std::vector<HdlExprAndStm> &elseIfs,
			std::unique_ptr<iHdlStatement> ifFalse);
	virtual ~HdlStmIf() override;
};

}
}
