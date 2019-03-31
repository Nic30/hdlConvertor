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
	static Statement * visitProcedural_timing_control_statement(
			Verilog2001::Verilog2001Parser::Procedural_timing_control_statementContext * ctx);
	static Statement * visitStatement_or_null(
			Verilog2001::Verilog2001Parser::Statement_or_nullContext * ctx);
	static std::vector<Expr*> * visitDelay_or_event_control(
			Verilog2001::Verilog2001Parser::Delay_or_event_controlContext * ctx);
	// for event * returns nullptr as the explicit event list is not specified
	static std::vector<Expr*> * vistEvent_control(
			Verilog2001::Verilog2001Parser::Event_controlContext * ctx);
	static std::vector<Statement *> vistContinuous_assign(
			Verilog2001::Verilog2001Parser::Continuous_assignContext * ctx);
	static Statement* visitNet_assignment(
			Verilog2001::Verilog2001Parser::Net_assignmentContext * ctx);
};
