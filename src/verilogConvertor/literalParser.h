#pragma once

#include <antlr4-runtime.h>
#include <vector>
#include <string>
#include <algorithm>

#include "../VerilogParser/Verilog2001Parser.h"
#include "../hdlObjects/symbolType.h"
#include "../hdlObjects/expr.h"
#include "../notImplementedLogger.h"

using namespace antlr4;
using namespace verilog;

class VerLiteralParser {
public:
	static Expr * visitNumber(Ref<Verilog2001Parser::NumberContext> ctx);
	static Expr * parseSimple_identifier(Ref<antlr4::tree::TerminalNode> n);
	static Expr * parseIntNumber(Ref<antlr4::tree::TerminalNode> n, int radix);
	static Expr * visitString(Ref<antlr4::tree::TerminalNode> n);
};
