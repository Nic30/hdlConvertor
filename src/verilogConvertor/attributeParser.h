#pragma once

#include <vector>

#include "Verilog2001Parser/Verilog2001Parser.h"
#include "../hdlObjects/expr.h"

class AttributeParser {
public:
	static std::vector<Expr*>* visitAttribute_instance(
			Verilog2001::Verilog2001Parser::Attribute_instanceContext * ctx);
};
