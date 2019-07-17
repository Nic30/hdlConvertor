#pragma once

#include <hdlConvertor/verilogConvertor/Verilog2001Parser/Verilog2001Parser.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>

namespace hdlConvertor {
namespace verilog {

class Utils {
public:
	static hdlObjects::iHdlExpr* mkStringT();

	static hdlObjects::iHdlExpr* mkIntT();
	// wire type is represented by wire id or call wire(range, signed)
	static hdlObjects::iHdlExpr* mkWireT();
	static hdlObjects::iHdlExpr* mkWireT(hdlObjects::iHdlExpr * range,
			bool signed_);
	static hdlObjects::iHdlExpr* mkWireT(
			Verilog2001_antlr::Verilog2001Parser::Range_Context * range,
			bool signed_);

	static bool is_signed(antlr4::ParserRuleContext * ctx);
	static bool is_reg(antlr4::ParserRuleContext * ctx);
};

}
}
