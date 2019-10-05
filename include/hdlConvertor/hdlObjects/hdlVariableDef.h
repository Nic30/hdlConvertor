#pragma once

#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>
#include <hdlConvertor/hdlObjects/hdlDirection.h>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * HDL AST node for definition of
 * port, constant, signal, typedef, VHDL generic, Verilog param and localparam
 *
 * @note if variable is a port the direction is set to something else than Direction::DIR_INTERNAL
 * @note latched flag corresponds to verilog "reg" or vhdl variable
 * 		if this is a Verilog typedef the is_latched flag corresponds to a "reg" in typedef
 **/
class HdlVariableDef: public iHdlObj, public WithNameAndDoc {
public:
	std::unique_ptr<iHdlExpr> type;
	std::unique_ptr<iHdlExpr> value;
	bool is_latched;
	bool is_const;
	bool is_static;
	HdlDirection direction;

	HdlVariableDef(const std::string &id, std::unique_ptr<iHdlExpr> type,
			std::unique_ptr<iHdlExpr> val);
	HdlVariableDef(const std::string &id, std::unique_ptr<iHdlExpr> type,
			std::unique_ptr<iHdlExpr> val, HdlDirection direction,
			bool is_latched);

	virtual ~HdlVariableDef() override;
};

}
}
