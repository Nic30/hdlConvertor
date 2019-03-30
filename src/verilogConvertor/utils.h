#pragma once

#include <antlr4-runtime.h>
#include <vector>

#include "Verilog2001Parser/Verilog2001Parser.h"
#include "Verilog2001Parser/Verilog2001Lexer.h"
#include "../hdlObjects/symbolType.h"
#include "../hdlObjects/expr.h"

using namespace antlr4;
using namespace Verilog2001;

class Utils {
public:
	static Expr* mkStringT();

	// wire type is represented by wire id or call wire(range, signed)
	static Expr* mkWireT();
	static Expr* mkWireT(Expr * range, bool signed_);
	static Expr* mkWireT(Verilog2001Parser::Range_Context * range, bool signed_);

	static bool is_signed(antlr4::ParserRuleContext * ctx) {
		//assert(strcmp(Verilog2001Lexer::getVocabulary() == "signed") == 0)
		auto st = ctx->getToken(Verilog2001Lexer::T__25, 0);
		assert(st->getText() == "signed");
		bool signed_ = st != nullptr;
		return signed_;
	}
};
