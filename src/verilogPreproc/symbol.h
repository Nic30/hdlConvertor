#pragma once


#include "antlr4-runtime.h"
#include "macroPrototype.h"
#include "verilogPreprocParser/verilogPreprocSymbolBaseListener.h"


using namespace antlr4;

class symbol :  public verilogPreprocSymbolBaseListener {

	public:
	macroPrototype data;

  	void enterPattern(verilogPreprocSymbolParser::PatternContext *ctx);

};
