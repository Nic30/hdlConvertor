#pragma once

#include <antlr4-runtime.h>
#include <vector>

#include "../VerilogParser/Verilog2001Parser.h"
#include "../hdlObjects/symbolType.h"
#include "../hdlObjects/expr.h"
#include "exprParser.h"
#include "moduleParser.h"
#include "../baseHdlParser/baseHdlParser.h"

using namespace antlr4;
using namespace verilog;

class Source_textParser : public BaseHdlParser {
public:
	Source_textParser(bool _hierarchyOnly);
	void visitSource_text(Verilog2001Parser::Source_textContext * ctx);
	void visitTiming_spec(Verilog2001Parser::Timing_specContext* ctx);
	void visitDescription(Verilog2001Parser::DescriptionContext* ctx);
};
