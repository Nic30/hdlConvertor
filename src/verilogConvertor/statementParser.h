#pragma once

#include "Verilog2001Parser/Verilog2001Parser.h"
#include "../hdlObjects/statement.h"

class VerStatementParser {
public:
	static Statement * visitAlways_construct(
			Verilog2001::Verilog2001Parser::Always_constructContext * ctx);
	static Statement * visitStatement(Verilog2001::Verilog2001Parser::StatementContext * ctx);
};
