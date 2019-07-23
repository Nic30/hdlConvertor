#pragma once

#include <vector>
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

	bool sensitivity_list_specified;

	std::vector<iHdlExpr*> & sensitivity_list();
	std::vector<iHdlObj*> & objs();

	const std::vector<iHdlExpr*> & sensitivity_list() const;
	const std::vector<iHdlObj*> & objs() const;

	HdlStmProcess();
	HdlStmProcess(std::vector<iHdlExpr*> * sensitivity, std::vector<iHdlObj*> * body);
};

}
}

