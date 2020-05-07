#pragma once

#include <hdlConvertor/hdlAst/iHdlStatement.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/hdlAst/hdlIdDef.h>

namespace hdlConvertor {
namespace hdlAst {

/*
 * HDL AST node for for-statement
 * */
class HdlStmFor: public iHdlStatement {
public:
	std::unique_ptr<iHdlStatement> init;
	std::unique_ptr<iHdlExprItem> cond;
	std::unique_ptr<iHdlStatement> step;
	std::unique_ptr<iHdlObj> body;

	HdlStmFor(std::unique_ptr<iHdlStatement> init,
			std::unique_ptr<iHdlExprItem> cond, std::unique_ptr<iHdlStatement> step,
			std::unique_ptr<iHdlObj> body);

	virtual ~HdlStmFor() override;
};

/*
 * HDL AST node for for-in-statement
 * */
class HdlStmForIn: public iHdlStatement {
public:
	// definition of variable(s) which will be used for iteration
	std::vector<std::unique_ptr<iHdlObj>> var_defs;
	// collection which will be iterated over
	std::unique_ptr<iHdlExprItem> collection;
	std::unique_ptr<iHdlObj> body;

	HdlStmForIn(std::unique_ptr<HdlIdDef> var,
			std::unique_ptr<iHdlExprItem> collection,
			std::unique_ptr<iHdlObj> body);
	HdlStmForIn(std::vector<std::unique_ptr<iHdlObj>> &vars,
			std::unique_ptr<iHdlExprItem> collection,
			std::unique_ptr<iHdlObj> body);
	HdlStmForIn(std::vector<std::unique_ptr<iHdlExprItem>> &vars,
			std::unique_ptr<iHdlExprItem> collection,
			std::unique_ptr<iHdlObj> body);
	HdlStmForIn(std::unique_ptr<iHdlExprItem> var,
			std::unique_ptr<iHdlExprItem> collection,
			std::unique_ptr<iHdlObj> body);

	virtual ~HdlStmForIn() override;
};

/*
 * HDL AST node for repeat-statement
 * */
class HdlStmRepeat: public iHdlStatement {
public:
	std::unique_ptr<iHdlExprItem> n;
	std::unique_ptr<iHdlObj> body;
	HdlStmRepeat(std::unique_ptr<iHdlExprItem> n,
			std::unique_ptr<iHdlObj> body);
	virtual ~HdlStmRepeat() override;
};

}
}
