#pragma once

#include <antlr4-runtime.h>
#include <vector>

#include "../VerilogParser/Verilog2001Parser.h"
#include "../hdlObjects/variable.h"
#include "../notImplementedLogger.h"

using namespace antlr4;
using namespace verilog;

class AttributeParser {
public:
	static std::vector<Variable*>* visitAttribute_instance(Ref<
			Verilog2001Parser::Attribute_instanceContext> ctx);
};
