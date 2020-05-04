#pragma once

#include <hdlConvertor/hdlAst/named.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/hdlAst/iHdlObj.h>
#include <hdlConvertor/hdlAst/hdlDirection.h>

namespace hdlConvertor {
namespace hdlAst {

/*
 * HDL AST node for definition of
 * port, constant, signal, typedef, VHDL generic, Verilog param and localparam
 *
 * @note if variable is a port the direction is set to something else than Direction::DIR_INTERNAL
 * @note latched flag corresponds to verilog "reg" or vhdl variable
 * 		if this is a Verilog typedef the is_latched flag corresponds to a "reg" in typedef
 **/
class HdlIdDef: public iHdlObj, public WithNameAndDoc {
public:
	std::unique_ptr<iHdlExprItem> type;
	std::unique_ptr<iHdlExprItem> value;
	bool is_latched;
	bool is_const;
	bool is_static;
	HdlDirection direction;

	HdlIdDef(const std::string &id, std::unique_ptr<iHdlExprItem> type,
			std::unique_ptr<iHdlExprItem> val);
	HdlIdDef(const std::string &id, std::unique_ptr<iHdlExprItem> type,
			std::unique_ptr<iHdlExprItem> val, HdlDirection direction,
			bool is_latched);

	virtual ~HdlIdDef() override;
};

}
}
