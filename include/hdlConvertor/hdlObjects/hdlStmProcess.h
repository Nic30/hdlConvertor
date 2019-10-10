#pragma once

#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/iHdlStatement.h>

namespace hdlConvertor {
namespace hdlObjects {

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

	std::unique_ptr<std::vector<std::unique_ptr<iHdlExpr>>> sensitivity_list;
	std::unique_ptr<iHdlStatement> body;

	HdlStmProcess();
	HdlStmProcess(
			std::unique_ptr<std::vector<std::unique_ptr<iHdlExpr>>> _sensitivity);
	HdlStmProcess(
			std::unique_ptr<std::vector<std::unique_ptr<iHdlExpr>>> _sensitivity, std::unique_ptr<iHdlStatement> body);
	virtual ~HdlStmProcess() override;
};

}
}

