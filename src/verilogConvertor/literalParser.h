#pragma once

#include <antlr4-runtime.h>
#include <vector>
#include <string>
#include <algorithm>

#include "Verilog2001Parser/Verilog2001Parser.h"
#include "../hdlObjects/expr.h"


class VerLiteralParser {
public:
	static Expr * visitNumber(Verilog2001::Verilog2001Parser::NumberContext * ctx);
	static Expr * parseSimple_identifier(antlr4::tree::TerminalNode * n);
	static Expr * parseEscaped_identifier(antlr4::tree::TerminalNode* n);
	static Expr * parseIntNumber(antlr4::tree::TerminalNode * n, int radix);
	static Expr * visitString(antlr4::tree::TerminalNode * n);
};
