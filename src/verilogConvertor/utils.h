#pragma once

#include <antlr4-runtime.h>
#include <vector>

#include "Verilog2001Parser/Verilog2001Parser.h"
#include "../hdlObjects/symbolType.h"
#include "../hdlObjects/expr.h"


using namespace antlr4;
using namespace Verilog2001;

class Utils {
public:
	static Expr* mkStringT();
	static Expr* mkWireT();
	static Expr* mkWireT(Expr * range);
	static Expr* mkWireT(Verilog2001Parser::Range_Context * range);
};
