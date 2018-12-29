#pragma once


#include "antlr4-runtime.h"
#include "macroPrototype.h"
#include "../vpp/symbolBaseListener.h"


using namespace antlr4;

class symbol :  public symbolBaseListener {

	public:
	macroPrototype data;

  	void enterPattern(symbolParser::PatternContext *ctx);

};
