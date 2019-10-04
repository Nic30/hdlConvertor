#pragma once

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>

#include <hdlConvertor/hdlObjects/iHdlStatement.h>
#include <hdlConvertor/hdlObjects/hdlStmAssign.h>
#include <hdlConvertor/hdlObjects/hdlStmProcess.h>
#include <hdlConvertor/hdlObjects/hdlStmBlock.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>
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

	hdlObjects::iHdlStatement* visitAlways_construct(
			sv2017Parser::Always_constructContext *ctx);
	hdlObjects::iHdlStatement* visitStatement_item(
			sv2017Parser::Statement_itemContext *ctx);
	hdlObjects::iHdlStatement* visitStatement(
			sv2017Parser::StatementContext *ctx);
	std::vector<hdlObjects::iHdlStatement*>* visitStatement__as_block(
			sv2017Parser::StatementContext *ctx);
	std::vector<hdlObjects::iHdlStatement*>* visitStatement_or_null__as_block(
			sv2017Parser::Statement_or_nullContext *ctx);
	hdlObjects::iHdlStatement* visitStatement_or_null(
			sv2017Parser::Statement_or_nullContext *ctx);
	hdlObjects::iHdlStatement* visitSubroutine_call_statement(
			sv2017Parser::Subroutine_call_statementContext *ctx);
	hdlObjects::iHdlStatement* visitJumpStatement(
			sv2017Parser::Jump_statementContext *ctx);
	hdlObjects::iHdlStatement* visitBlocking_assignment(
			sv2017Parser::Blocking_assignmentContext *ctx);
	hdlObjects::iHdlStatement* visitCase_statement(
			sv2017Parser::Case_statementContext *ctx);
	std::vector<hdlObjects::iHdlStatement::case_t> visitCase_item(
			sv2017Parser::Case_itemContext *ctx);
	hdlObjects::HdlStmAssign* visitVariable_assignment(
			sv2017Parser::Variable_assignmentContext *ctx);
	void visitFor_variable_declaration(
			sv2017Parser::For_variable_declarationContext *ctx,
			std::vector<hdlObjects::HdlVariableDef*> &res);
	void visitFor_initialization(sv2017Parser::For_initializationContext *ctx,
			std::vector<hdlObjects::iHdlStatement*> &res);
	void visitFor_step(sv2017Parser::For_stepContext *ctx,
			std::vector<hdlObjects::iHdlStatement*> &res);
	hdlObjects::iHdlStatement* visitLoop_statement(
			sv2017Parser::Loop_statementContext *ctx);
	std::vector<hdlObjects::iHdlExpr*>* visitLoop_variables(
			sv2017Parser::Loop_variablesContext *ctx);
	hdlObjects::HdlStmAssign* visitNonblocking_assignment(
			sv2017Parser::Nonblocking_assignmentContext *ctx);
	hdlObjects::HdlStmBlock* visitSeq_block(
			sv2017Parser::Seq_blockContext *ctx);
	void visitBlock_item_declaration(
			sv2017Parser::Block_item_declarationContext *ctx,
			std::vector<hdlObjects::iHdlObj*> &res);
	hdlObjects::iHdlStatement* visitConditional_statement(
			sv2017Parser::Conditional_statementContext *ctx);
	hdlObjects::HdlStmProcess* visitProcedural_timing_control_statement(
			sv2017Parser::Procedural_timing_control_statementContext *ctx);
	void visitContinuous_assign(sv2017Parser::Continuous_assignContext *ctx,
			std::vector<hdlObjects::iHdlStatement*> &res);
	hdlObjects::HdlStmProcess* visitInitial_construct(
			sv2017Parser::Initial_constructContext *ctx);
	hdlObjects::iHdlStatement* visitSequence_match_item(
			sv2017Parser::Sequence_match_itemContext *ctx);
	hdlObjects::iHdlStatement* visitElaboration_system_task(
			sv2017Parser::Elaboration_system_taskContext *ctx);

};

}
}
