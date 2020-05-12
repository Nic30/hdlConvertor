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
	std::unique_ptr<iHdlObj> ifTrue;
	std::vector<HdlExprAndiHdlObj> elseIfs;
	std::unique_ptr<iHdlObj> ifFalse;

	HdlStmIf(std::unique_ptr<iHdlExprItem> cond,
			std::unique_ptr<iHdlObj> ifTrue);
	HdlStmIf(std::unique_ptr<iHdlExprItem> cond,
			std::unique_ptr<iHdlObj> ifTrue,
			std::unique_ptr<iHdlObj> ifFalse);
	HdlStmIf(std::unique_ptr<iHdlExprItem> cond,
			std::unique_ptr<iHdlObj> ifTrue,
			std::vector<HdlExprAndiHdlObj> &elseIfs,
			std::unique_ptr<iHdlObj> ifFalse);
	virtual ~HdlStmIf() override;
};

}
}
