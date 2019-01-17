#pragma once

#include <antlr4-runtime.h>
#include "verilogPreprocParser/verilogPreprocSymbolLexer.h"
#include "verilogPreprocParser/verilogPreprocSymbolParser.h"
#include <string>
#include <vector>

/**
 *  class that represent the macro name and  the list of argument
 *  TODO integrate this capture in to a single grammar
 */
class macroPrototype {
	public:
	std::string macroName;
	std::vector<std::string> args;
};

//return the macro prototype aka the macro name and the value of various
//argument
macroPrototype return_prototype(std::string input_token);

