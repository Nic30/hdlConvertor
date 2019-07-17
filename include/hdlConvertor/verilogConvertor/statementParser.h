#pragma once

#include <vector>

#include <hdlConvertor/verilogConvertor/Verilog2001Parser/Verilog2001Parser.h>

#include <hdlConvertor/hdlObjects/iHdlStatement.h>
#include <hdlConvertor/hdlObjects/hdlStmAssign.h>
#include <hdlConvertor/hdlObjects/hdlStmProcess.h>
#include <hdlConvertor/verilogConvertor/commentParser.h>

namespace hdlConvertor {
namespace verilog {

class VerStatementParser {
	CommentParser & commentParser;
public:
	using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;
	// single statement or many statements, only one is set at the time, other is nullptr
	using stm_or_block_t = std::pair<hdlObjects::iHdlStatement *, std::vector<hdlObjects::iHdlStatement*>*>;

	VerStatementParser(CommentParser & commentParser);

	stm_or_block_t visitAlways_construct(
			Verilog2001Parser::Always_constructContext * ctx);
	stm_or_block_t visitStatement(Verilog2001Parser::StatementContext * ctx);
	hdlObjects::iHdlStatement * visitSystem_task_enable(
			Verilog2001Parser::System_task_enableContext * ctx);
	std::vector<hdlObjects::iHdlStatement*> * visitStatement__as_block(
			Verilog2001Parser::StatementContext * ctx);
	hdlObjects::iHdlStatement * visitBlocking_assignment(
			Verilog2001Parser::Blocking_assignmentContext *ctx);
	hdlObjects::iHdlStatement * visitCase_statement(
			Verilog2001Parser::Case_statementContext * ctx);
	std::vector<hdlObjects::iHdlStatement::case_t> visitCase_item(
			Verilog2001Parser::Case_itemContext * ctx);
	hdlObjects::HdlStmAssign * visitVariable_assignment(
			Verilog2001Parser::Variable_assignmentContext *ctx);
	hdlObjects::iHdlStatement * visitLoop_statement(
			Verilog2001Parser::Loop_statementContext * ctx);
	hdlObjects::HdlStmAssign * visitNonblocking_assignment(
			Verilog2001Parser::Nonblocking_assignmentContext * ctx);
	std::vector<hdlObjects::iHdlStatement*> * visitSeq_block(
			Verilog2001Parser::Seq_blockContext * ctx);
	hdlObjects::iHdlStatement * visitConditional_statement(
			Verilog2001Parser::Conditional_statementContext * ctx);
	hdlObjects::HdlStmProcess * visitProcedural_timing_control_statement(
			Verilog2001Parser::Procedural_timing_control_statementContext * ctx);
	// utility function which ensures that the statements are always wrapped in vector
	std::vector<hdlObjects::iHdlStatement *> * visitStatement_or_null__as_block(
			Verilog2001Parser::Statement_or_nullContext * ctx);
	stm_or_block_t visitStatement_or_null(
			Verilog2001Parser::Statement_or_nullContext * ctx);
	// @returns <delay, events>
	static std::pair<hdlObjects::iHdlExpr*, std::vector<hdlObjects::iHdlExpr*>*> visitDelay_or_event_control(
			Verilog2001Parser::Delay_or_event_controlContext * ctx);
	// for event * returns nullptr as the explicit event list is not specified
	static std::vector<hdlObjects::iHdlExpr*> * vistEvent_control(
			Verilog2001Parser::Event_controlContext * ctx);
	std::vector<hdlObjects::iHdlStatement *> vistContinuous_assign(
			Verilog2001Parser::Continuous_assignContext * ctx);
	static hdlObjects::iHdlStatement* visitNet_assignment(
			Verilog2001Parser::Net_assignmentContext * ctx);
	hdlObjects::HdlStmProcess * visitInitial_construct(
			Verilog2001Parser::Initial_constructContext * ctx);
};

}
}
