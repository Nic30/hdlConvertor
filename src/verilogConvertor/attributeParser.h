#pragma once

#include <antlr4-runtime.h>
#include <vector>

#include "Verilog2001Parser/Verilog2001Parser.h"
#include "../hdlObjects/variable.h"
#include "../notImplementedLogger.h"

using namespace antlr4;
using namespace Verilog2001;

class AttributeParser {
public:
	static std::vector<Variable*>* visitAttribute_instance(Verilog2001Parser::Attribute_instanceContext * ctx);
};
