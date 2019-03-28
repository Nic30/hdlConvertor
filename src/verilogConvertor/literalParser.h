#pragma once

#include <antlr4-runtime.h>
#include <vector>
#include <string>
#include <algorithm>

#include "Verilog2001Parser/Verilog2001Parser.h"
#include "../hdlObjects/symbolType.h"
#include "../hdlObjects/expr.h"
#include "../notImplementedLogger.h"

using namespace antlr4;
using namespace Verilog2001;

class VerLiteralParser {
public:
	static Expr * visitNumber(Verilog2001Parser::NumberContext * ctx);
	static Expr * parseSimple_identifier(antlr4::tree::TerminalNode * n);
	static Expr * parseIntNumber(antlr4::tree::TerminalNode * n, int radix);
	static Expr * visitString(antlr4::tree::TerminalNode * n);
};
