#pragma once

#include <vector>

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>

#include <hdlConvertor/hdlObjects/iHdlStatement.h>
#include <hdlConvertor/hdlObjects/hdlStmAssign.h>
#include <hdlConvertor/hdlObjects/hdlStmProcess.h>
#include <hdlConvertor/svConvertor/commentParser.h>

namespace hdlConvertor {
namespace sv {

class VerStatementParser {
	SVCommentParser &commentParser;
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;
	// single statement or many statements, only one is set at the time, other is nullptr
	using stm_or_block_t = std::pair<hdlObjects::iHdlStatement *, std::vector<hdlObjects::iHdlStatement*>*>;

	VerStatementParser(SVCommentParser &commentParser);

	stm_or_block_t visitAlways_construct(
			sv2017Parser::Always_constructContext *ctx);
	stm_or_block_t visitStatement(sv2017Parser::StatementContext *ctx);
	std::vector<hdlObjects::iHdlStatement*>* visitStatement__as_block(
			sv2017Parser::StatementContext *ctx);
	hdlObjects::iHdlStatement* visitBlocking_assignment(
			sv2017Parser::Blocking_assignmentContext *ctx);
	hdlObjects::iHdlStatement* visitCase_statement(
			sv2017Parser::Case_statementContext *ctx);
	std::vector<hdlObjects::iHdlStatement::case_t> visitCase_item(
			sv2017Parser::Case_itemContext *ctx);
	hdlObjects::HdlStmAssign* visitVariable_assignment(
			sv2017Parser::Variable_assignmentContext *ctx);
	hdlObjects::iHdlStatement* visitLoop_statement(
			sv2017Parser::Loop_statementContext *ctx);
	hdlObjects::HdlStmAssign* visitNonblocking_assignment(
			sv2017Parser::Nonblocking_assignmentContext *ctx);
	std::vector<hdlObjects::iHdlStatement*>* visitSeq_block(
			sv2017Parser::Seq_blockContext *ctx);
	hdlObjects::iHdlStatement* visitConditional_statement(
			sv2017Parser::Conditional_statementContext *ctx);
	hdlObjects::HdlStmProcess* visitProcedural_timing_control_statement(
			sv2017Parser::Procedural_timing_control_statementContext *ctx);
	// utility function which ensures that the statements are always wrapped in vector
	std::vector<hdlObjects::iHdlStatement*>* visitStatement_or_null__as_block(
			sv2017Parser::Statement_or_nullContext *ctx);
	stm_or_block_t visitStatement_or_null(
			sv2017Parser::Statement_or_nullContext *ctx);
	// @returns <delay, events>
	static std::pair<hdlObjects::iHdlExpr*, std::vector<hdlObjects::iHdlExpr*>*> visitDelay_or_event_control(
			sv2017Parser::Delay_or_event_controlContext *ctx);
	// for event * returns nullptr as the explicit event list is not specified
	static std::vector<hdlObjects::iHdlExpr*>* vistEvent_control(
			sv2017Parser::Event_controlContext *ctx);
	std::vector<hdlObjects::iHdlStatement*> vistContinuous_assign(
			sv2017Parser::Continuous_assignContext *ctx);
	static hdlObjects::iHdlStatement* visitNet_assignment(
			sv2017Parser::Net_assignmentContext *ctx);
	hdlObjects::HdlStmProcess* visitInitial_construct(
			sv2017Parser::Initial_constructContext *ctx);
};

}
}
