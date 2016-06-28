#pragma once

#include <antlr4-runtime.h>
#include <vector>

#include "../VerilogParser/Verilog2001Parser.h"
#include "../hdlObjects/symbolType.h"
#include "../hdlObjects/expr.h"


using namespace antlr4;
using namespace verilog;

class Utils {
public:
	static Expr* mkStringT();
	static Expr* mkWireT();
	static Expr* mkWireT(Expr * range);
	static Expr* mkWireT(Ref<Verilog2001Parser::RangeContext> range);
};
