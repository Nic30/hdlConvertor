#pragma once

#include <antlr4-runtime.h>
#include <vector>

#include "../VerilogParser/Verilog2001Parser.h"
#include "../hdlObjects/symbolType.h"
#include "../hdlObjects/expr.h"
#include "exprParser.h"
#include "moduleParser.h"

using namespace antlr4;
using namespace verilog;

class Source_textParser {
	bool hierarchyOnly;
	Context * context;
public:
	Source_textParser(bool _hierarchyOnly);
	Context * getContext();
	void visitSource_text(Ref<Verilog2001Parser::Source_textContext> ctx);
	void visitTiming_spec(Ref<Verilog2001Parser::Timing_specContext> ctx);
	void visitDescription(Ref<Verilog2001Parser::DescriptionContext> ctx);
};
