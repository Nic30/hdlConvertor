#pragma once

#include "Verilog2001Parser/Verilog2001Parser.h"
#include "../hdlObjects/expr.h"

namespace hdlConvertor {
namespace verilog {

class Utils {
public:
	using Expr = hdlObjects::Expr;
	static Expr* mkStringT();

	// wire type is represented by wire id or call wire(range, signed)
	static Expr* mkWireT();
	static Expr* mkWireT(Expr * range, bool signed_);
	static Expr* mkWireT(Verilog2001_antlr::Verilog2001Parser::Range_Context * range,
			bool signed_);

	static bool is_signed(antlr4::ParserRuleContext * ctx);
	static bool is_reg(antlr4::ParserRuleContext * ctx);
};

}
}
