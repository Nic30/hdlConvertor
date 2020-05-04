#pragma once

#include <hdlConvertor/hdlAst/iHdlStatement.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>

namespace hdlConvertor {
namespace hdlAst {

/*
 * HDL AST node for conditional statement
 * */
class HdlStmIf: public iHdlStatement {
public:
	std::unique_ptr<iHdlExprItem> cond;
	std::unique_ptr<iHdlStatement> ifTrue;
	std::vector<HdlExprAndStm> elseIfs;
	std::unique_ptr<iHdlStatement> ifFalse;

	HdlStmIf(std::unique_ptr<iHdlExprItem> cond,
			std::unique_ptr<iHdlStatement> ifTrue);
	HdlStmIf(std::unique_ptr<iHdlExprItem> cond,
			std::unique_ptr<iHdlStatement> ifTrue,
			std::unique_ptr<iHdlStatement> ifFalse);
	HdlStmIf(std::unique_ptr<iHdlExprItem> cond,
			std::unique_ptr<iHdlStatement> ifTrue,
			std::vector<HdlExprAndStm> &elseIfs,
			std::unique_ptr<iHdlStatement> ifFalse);
	virtual ~HdlStmIf() override;
};

}
}
