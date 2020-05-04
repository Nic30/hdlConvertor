#pragma once

#include <hdlConvertor/hdlAst/iHdlStatement.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>

namespace hdlConvertor {
namespace hdlAst {

/*
 * HDL AST node for switch-case statement
 * */
class HdlStmCase: public iHdlStatement {
public:
	std::unique_ptr<iHdlExprItem> select_on;
	std::vector<HdlExprAndStm> cases;
	std::unique_ptr<iHdlStatement> default_;

	HdlStmCase(std::unique_ptr<iHdlExprItem> select_on,
			std::vector<HdlExprAndStm> &cases);
	HdlStmCase(std::unique_ptr<iHdlExprItem> select_on,
			std::vector<HdlExprAndStm> &cases,
			std::unique_ptr<iHdlStatement> _default_);
	virtual ~HdlStmCase() override;
};

}
}
