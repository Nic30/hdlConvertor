#pragma once

#include <vector>
#include "Verilog2001Parser/Verilog2001Parser.h"
#include "../hdlObjects/statement.h"
#include "commentParser.h"

namespace hdlConvertor {
namespace verilog {

class VerStatementParser {
	CommentParser & commentParser;
public:
	using Statement = hdlObjects::Statement;
	using Expr = hdlObjects::Expr;
	using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;
	// single statement or many statements, only one is set at the time, other is nullptr
	using stm_or_block_t = std::pair<Statement *, std::vector<Statement*>*>;

	VerStatementParser(CommentParser & commentParser);

	static stm_or_block_t visitAlways_construct(
			Verilog2001Parser::Always_constructContext * ctx);
	static stm_or_block_t visitStatement(
			Verilog2001Parser::StatementContext * ctx);
	static Statement * visitBlocking_assignment(
			Verilog2001Parser::Blocking_assignmentContext *ctx);
	static Statement * visitCase_statement(
			Verilog2001Parser::Case_statementContext * ctx);
	static std::vector<Statement::case_t> visitCase_item(
			Verilog2001Parser::Case_itemContext * ctx);
	static Statement * visitNonblocking_assignment(
			Verilog2001Parser::Nonblocking_assignmentContext * ctx);
	static std::vector<Statement*> * visitSeq_block(
			Verilog2001Parser::Seq_blockContext * ctx);
	static Statement * visitConditional_statement(
			Verilog2001Parser::Conditional_statementContext * ctx);
	static Statement * visitProcedural_timing_control_statement(
			Verilog2001Parser::Procedural_timing_control_statementContext * ctx);
	// utility function which ensures that the statements are always wrapped in vector
	static std::vector<Statement *> * visitStatement_or_null__wrapped(
			Verilog2001Parser::Statement_or_nullContext * ctx);
	static stm_or_block_t visitStatement_or_null(
			Verilog2001Parser::Statement_or_nullContext * ctx);
	static std::vector<Expr*> * visitDelay_or_event_control(
			Verilog2001Parser::Delay_or_event_controlContext * ctx);
	// for event * returns nullptr as the explicit event list is not specified
	static std::vector<Expr*> * vistEvent_control(
			Verilog2001Parser::Event_controlContext * ctx);
	std::vector<Statement *> vistContinuous_assign(
			Verilog2001Parser::Continuous_assignContext * ctx);
	static Statement* visitNet_assignment(
			Verilog2001Parser::Net_assignmentContext * ctx);
};

}
}
