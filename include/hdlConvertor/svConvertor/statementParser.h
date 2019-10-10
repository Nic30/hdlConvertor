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

	VerStatementParser(SVCommentParser &commentParser);

	std::unique_ptr<hdlObjects::iHdlStatement> visitAlways_construct(
			sv2017Parser::Always_constructContext *ctx);
	std::unique_ptr<hdlObjects::iHdlStatement> visitStatement_item(
			sv2017Parser::Statement_itemContext *ctx);
	std::unique_ptr<hdlObjects::iHdlStatement>  visitStatement(
			sv2017Parser::StatementContext *ctx);
	std::unique_ptr<hdlObjects::iHdlStatement> visitStatement_or_null(
			sv2017Parser::Statement_or_nullContext *ctx);
	std::unique_ptr<hdlObjects::iHdlStatement> visitSubroutine_call_statement(
			sv2017Parser::Subroutine_call_statementContext *ctx);
	std::unique_ptr<hdlObjects::iHdlStatement>  visitJumpStatement(
			sv2017Parser::Jump_statementContext *ctx);
	std::unique_ptr<hdlObjects::iHdlStatement> visitBlocking_assignment(
			sv2017Parser::Blocking_assignmentContext *ctx);
	std::unique_ptr<hdlObjects::iHdlStatement> visitCase_statement(
			sv2017Parser::Case_statementContext *ctx);
	std::vector<hdlObjects::HdlExprAndStm> visitCase_item(
			sv2017Parser::Case_itemContext *ctx);
	std::unique_ptr<hdlObjects::HdlStmAssign> visitVariable_assignment(
			sv2017Parser::Variable_assignmentContext *ctx);
	void visitFor_variable_declaration(
			sv2017Parser::For_variable_declarationContext *ctx,
			std::vector<std::unique_ptr<hdlObjects::HdlVariableDef>> &res);
	void visitFor_initialization(sv2017Parser::For_initializationContext *ctx,
			std::vector<std::unique_ptr<hdlObjects::iHdlStatement>> &res);
	void visitFor_step(sv2017Parser::For_stepContext *ctx,
			std::vector<std::unique_ptr<hdlObjects::iHdlStatement>> &res);
	std::unique_ptr<hdlObjects::iHdlStatement> visitLoop_statement(
			sv2017Parser::Loop_statementContext *ctx);
	void visitLoop_variables(sv2017Parser::Loop_variablesContext *ctx,
			std::vector<std::unique_ptr<hdlObjects::iHdlStatement>> &res);
	std::unique_ptr<hdlObjects::HdlStmAssign> visitNonblocking_assignment(
			sv2017Parser::Nonblocking_assignmentContext *ctx);
	std::unique_ptr<hdlObjects::HdlStmBlock> visitSeq_block(
			sv2017Parser::Seq_blockContext *ctx);
	void visitBlock_item_declaration(
			sv2017Parser::Block_item_declarationContext *ctx,
			std::vector<std::unique_ptr<hdlObjects::iHdlObj>> &res);
	std::unique_ptr<hdlObjects::iHdlStatement> visitConditional_statement(
			sv2017Parser::Conditional_statementContext *ctx);
	std::unique_ptr<hdlObjects::HdlStmProcess> visitProcedural_timing_control_statement(
			sv2017Parser::Procedural_timing_control_statementContext *ctx);
	void visitContinuous_assign(sv2017Parser::Continuous_assignContext *ctx,
			std::vector<std::unique_ptr<hdlObjects::iHdlStatement>> &res);
	std::unique_ptr<hdlObjects::HdlStmProcess> visitInitial_construct(
			sv2017Parser::Initial_constructContext *ctx);
	std::unique_ptr<hdlObjects::iHdlStatement> visitSequence_match_item(
			sv2017Parser::Sequence_match_itemContext *ctx);
	std::unique_ptr<hdlObjects::iHdlStatement>  visitElaboration_system_task(
			sv2017Parser::Elaboration_system_taskContext *ctx);

};

}
}
