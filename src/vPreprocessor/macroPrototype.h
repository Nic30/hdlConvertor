#pragma once

#include "antlr4-runtime.h"
#include "../vpp/symbolLexer.h"
#include "../vpp/symbolParser.h"
#include <string>
#include <vector>

class macroPrototype {
	public:
	std::string macroName;
	std::vector<std::string> args;
};

macroPrototype return_prototype(std::string input_token);
