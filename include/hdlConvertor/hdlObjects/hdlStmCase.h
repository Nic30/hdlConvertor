#pragma once

#include <hdlConvertor/hdlObjects/iHdlStatement.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * HDL AST node for switch-case statement
 * */
class HdlStmCase: public iHdlStatement {
public:
	std::unique_ptr<iHdlExpr> select_on;
	std::vector<HdlExprAndStm> cases;
	std::unique_ptr<iHdlStatement> default_;

	HdlStmCase(std::unique_ptr<iHdlExpr> select_on,
			std::vector<HdlExprAndStm> &cases);
	HdlStmCase(std::unique_ptr<iHdlExpr> select_on,
			std::vector<HdlExprAndStm> &cases,
			std::unique_ptr<iHdlStatement> _default_);
	virtual ~HdlStmCase() override;
};

}
}
