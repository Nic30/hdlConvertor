#pragma once

#include <vector>

#include "Verilog2001Parser/Verilog2001Parser.h"
#include "../hdlObjects/symbolType.h"
#include "../hdlObjects/expr.h"
#include "exprParser.h"
#include "moduleParser.h"
#include "../baseHdlParser/baseHdlParser.h"

class Source_textParser : public BaseHdlParser {
public:
	Source_textParser(antlr4::TokenStream* tokens, Context * ctx, bool _hierarchyOnly);
	void visitSource_text(Verilog2001::Verilog2001Parser::Source_textContext * ctx);
	void visitTiming_spec(Verilog2001::Verilog2001Parser::Timing_specContext* ctx);
	void visitDescription(Verilog2001::Verilog2001Parser::DescriptionContext* ctx);
};
