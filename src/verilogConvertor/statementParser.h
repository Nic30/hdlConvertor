#pragma once

#include <vector>
#include "Verilog2001Parser/Verilog2001Parser.h"
#include "../hdlObjects/statement.h"

class VerStatementParser {
public:
	static Statement * visitAlways_construct(
			Verilog2001::Verilog2001Parser::Always_constructContext * ctx);
	static Statement * visitStatement(
			Verilog2001::Verilog2001Parser::StatementContext * ctx);
	static std::vector<Statement *> vistContinuous_assign(
			Verilog2001::Verilog2001Parser::Continuous_assignContext * ctx);
	static Statement* visitNet_assignment(
			Verilog2001::Verilog2001Parser::Net_assignmentContext * ctx);
};
