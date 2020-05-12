#pragma once

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>

#include <hdlConvertor/hdlAst/iHdlStatement.h>
#include <hdlConvertor/hdlAst/hdlStmAssign.h>
#include <hdlConvertor/hdlAst/hdlStmProcess.h>
#include <hdlConvertor/hdlAst/hdlStmBlock.h>
#include <hdlConvertor/hdlAst/hdlStmIf.h>
#include <hdlConvertor/hdlAst/hdlIdDef.h>
#include <hdlConvertor/svConvertor/commentParser.h>
#include <hdlConvertor/svConvertor/exprParser.h>
#include <hdlConvertor/createObject.h>


namespace hdlConvertor {
namespace sv {

class VerStatementParser {
	SVCommentParser &commentParser;
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;
	// single statement or many statements, only one is set at the time, other is nullptr

	VerStatementParser(SVCommentParser &commentParser);

	std::unique_ptr<hdlAst::iHdlStatement> visitAlways_construct(
			sv2017Parser::Always_constructContext *ctx);
	std::unique_ptr<hdlAst::iHdlStatement> visitStatement_item(
			sv2017Parser::Statement_itemContext *ctx);
	std::unique_ptr<hdlAst::iHdlStatement>  visitStatement(
			sv2017Parser::StatementContext *ctx);
	std::unique_ptr<hdlAst::iHdlStatement> visitStatement_or_null(
			sv2017Parser::Statement_or_nullContext *ctx);
	std::unique_ptr<hdlAst::iHdlStatement> visitSubroutine_call_statement(
			sv2017Parser::Subroutine_call_statementContext *ctx);
	std::unique_ptr<hdlAst::iHdlStatement>  visitJumpStatement(
			sv2017Parser::Jump_statementContext *ctx);
	std::unique_ptr<hdlAst::iHdlStatement> visitBlocking_assignment(
			sv2017Parser::Blocking_assignmentContext *ctx);
	std::unique_ptr<hdlAst::iHdlStatement> visitCase_statement(
			sv2017Parser::Case_statementContext *ctx);
	std::vector<hdlAst::HdlExprAndiHdlObj> visitCase_item(
			sv2017Parser::Case_itemContext *ctx);
	std::unique_ptr<hdlAst::HdlStmAssign> visitVariable_assignment(
			sv2017Parser::Variable_assignmentContext *ctx);
	void visitFor_variable_declaration(
			sv2017Parser::For_variable_declarationContext *ctx,
			std::vector<std::unique_ptr<hdlAst::HdlIdDef>> &res);
	void visitFor_initialization(sv2017Parser::For_initializationContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlStatement>> &res);
	void visitFor_step(sv2017Parser::For_stepContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlStatement>> &res);
	std::unique_ptr<hdlAst::iHdlStatement> visitLoop_statement(
			sv2017Parser::Loop_statementContext *ctx);
	void visitLoop_variables(sv2017Parser::Loop_variablesContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlStatement>> &res);
	std::unique_ptr<hdlAst::HdlStmAssign> visitNonblocking_assignment(
			sv2017Parser::Nonblocking_assignmentContext *ctx);
	template<typename BLOCK_T>
	std::unique_ptr<hdlAst::HdlStmBlock> visit_block(BLOCK_T* ctx) {
		//     X ( COLON identifier | {_input->LA(1) != COLON}? )
		//         ( block_item_declaration )* ( statement_or_null )*
		//     X (COLON identifier |  {_input->LA(1) != COLON}?);
		auto _label = ctx->identifier(0);
		std::vector<std::unique_ptr<hdlAst::iHdlObj>> items;
		for (auto bid : ctx->block_item_declaration()) {
			visitBlock_item_declaration(bid, items);
		}
		for (auto stm : ctx->statement_or_null()) {
			auto i = visitStatement_or_null(stm);
			items.push_back(move(i));
		}
		auto b = create_object_with_doc<hdlAst::HdlStmBlock>(ctx, commentParser, items);
		if (_label) {
			VerExprParser ep(commentParser);
			b->labels.push_back(ep.getIdentifierStr(_label));
		}
		return b;
	}
	std::unique_ptr<hdlAst::HdlStmBlock> visitSeq_block(
			sv2017Parser::Seq_blockContext *ctx);
	std::unique_ptr<hdlAst::HdlStmBlock> visitPar_block(
				sv2017Parser::Par_blockContext *ctx);
	void visitBlock_item_declaration(
			sv2017Parser::Block_item_declarationContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlObj>> &res);
	std::unique_ptr<hdlAst::iHdlStatement> visitConditional_statement(
			sv2017Parser::Conditional_statementContext *ctx);
	std::unique_ptr<hdlAst::HdlStmProcess> visitProcedural_timing_control_statement(
			sv2017Parser::Procedural_timing_control_statementContext *ctx);
	void visitContinuous_assign(sv2017Parser::Continuous_assignContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlStatement>> &res);
	std::unique_ptr<hdlAst::HdlStmProcess> visitInitial_construct(
			sv2017Parser::Initial_constructContext *ctx);
	std::unique_ptr<hdlAst::iHdlStatement> visitSequence_match_item(
			sv2017Parser::Sequence_match_itemContext *ctx);
	std::unique_ptr<hdlAst::iHdlStatement>  visitElaboration_system_task(
			sv2017Parser::Elaboration_system_taskContext *ctx);

};

void HdlStmIf_collapse_elifs(hdlAst::HdlStmIf &ifStm);

}
}
