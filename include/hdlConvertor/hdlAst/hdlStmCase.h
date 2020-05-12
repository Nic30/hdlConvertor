#pragma once

#include <hdlConvertor/hdlAst/iHdlStatement.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>

namespace hdlConvertor {
namespace hdlAst {

enum HdlStmCaseType {
	CASE, CASEZ, CASEX,
};

const char * HdlStmCaseType_toString(HdlStmCaseType o);

/*
 * HDL AST node for switch-case statement
 * */
class HdlStmCase: public iHdlStatement {
public:
	HdlStmCaseType type;
	std::unique_ptr<iHdlExprItem> select_on;
	std::vector<HdlExprAndiHdlObj> cases;
	std::unique_ptr<iHdlObj> default_;

	HdlStmCase(HdlStmCaseType type, std::unique_ptr<iHdlExprItem> select_on,
			std::vector<HdlExprAndiHdlObj> &cases);
	HdlStmCase(HdlStmCaseType type, std::unique_ptr<iHdlExprItem> select_on,
			std::vector<HdlExprAndiHdlObj> &cases,
			std::unique_ptr<iHdlObj> _default_);
	HdlStmCase(std::unique_ptr<iHdlExprItem> select_on,
			std::vector<HdlExprAndiHdlObj> &cases);
	HdlStmCase(std::unique_ptr<iHdlExprItem> select_on,
			std::vector<HdlExprAndiHdlObj> &cases,
			std::unique_ptr<iHdlObj> _default_);

	virtual ~HdlStmCase() override;
};

}
}
