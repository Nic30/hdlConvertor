#pragma once

#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/hdlAst/iHdlStatement.h>

namespace hdlConvertor {
namespace hdlAst {

/*
 * HDL AST node for HDL process construct
 * (Verilog always and assign constructs, VHDL process and top level assignments)
 *
 * @note the process may may be described only by statement in HDL
 * 		this means that it does not have to have name or sensitivity list
 * 		specified explicitly
 * */
class HdlStmProcess: public iHdlStatement {
public:

	std::unique_ptr<std::vector<std::unique_ptr<iHdlExprItem>>> sensitivity_list;
	std::unique_ptr<iHdlStatement> body;

	HdlStmProcess();
	HdlStmProcess(
			std::unique_ptr<std::vector<std::unique_ptr<iHdlExprItem>>> _sensitivity);
	HdlStmProcess(
			std::unique_ptr<std::vector<std::unique_ptr<iHdlExprItem>>> _sensitivity,
			std::unique_ptr<iHdlStatement> body);
	virtual ~HdlStmProcess() override;
};

}
}

