#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/hdlAst/iHdlStatement.h>
#include <hdlConvertor/hdlAst/hdlStmAssign.h>
#include <hdlConvertor/hdlAst/hdlStmBlock.h>
#include <hdlConvertor/hdlAst/hdlIdDef.h>
#include <hdlConvertor/vhdlConvertor/commentParser.h>

namespace hdlConvertor {
namespace vhdl {

// [TODO] make methods non static and parse code positions and comments
class VhdlStatementParser {
	VhdlCommentParser & commentParser;
public:
	using vhdlParser = vhdl_antlr::vhdlParser;
	bool hierarchyOnly;
	VhdlStatementParser(VhdlCommentParser & _commentParser, bool _hierarchyOnly);

	static std::unique_ptr<hdlAst::iHdlStatement> visitSequential_statement(
			vhdlParser::Sequential_statementContext *ctx);
	static std::unique_ptr<hdlAst::iHdlStatement> visitSignal_assignment_statement(
			vhdlParser::Signal_assignment_statementContext *ctx);
	static std::unique_ptr<hdlAst::HdlStmAssign> visitSimple_signal_assignment(
			vhdlParser::Simple_signal_assignmentContext *ctx);
	static std::unique_ptr<hdlAst::HdlStmAssign> visitSimple_waveform_assignment(
			vhdlParser::Simple_waveform_assignmentContext *ctx);
	static std::unique_ptr<hdlAst::HdlStmAssign> visitSimple_force_assignment(
			vhdlParser::Simple_force_assignmentContext *ctx);
	static std::unique_ptr<hdlAst::HdlStmAssign> visitSimple_release_assignment(
			vhdlParser::Simple_release_assignmentContext *ctx);
	static std::unique_ptr<hdlAst::iHdlStatement> visitConditional_signal_assignment(
			vhdlParser::Conditional_signal_assignmentContext *ctx);
	static std::unique_ptr<hdlAst::iHdlStatement> visitConditional_waveform_assignment(
			vhdlParser::Conditional_waveform_assignmentContext *ctx);
	static std::unique_ptr<hdlAst::iHdlStatement> visitConditional_force_assignment(
			vhdlParser::Conditional_force_assignmentContext *ctx);
	static std::unique_ptr<hdlAst::iHdlStatement> visitSelected_signal_assignment(
			vhdlParser::Selected_signal_assignmentContext *ctx);
	static std::unique_ptr<hdlAst::iHdlStatement> visitVariable_assignment_statement(
			vhdlParser::Variable_assignment_statementContext *ctx);
	static std::unique_ptr<hdlAst::iHdlStatement> visitIf_statement(
			vhdlParser::If_statementContext *ctx);
	static std::unique_ptr<hdlAst::HdlStmAssign> visitSimple_variable_assignment(
			vhdlParser::Simple_variable_assignmentContext *ctx);
	static std::unique_ptr<hdlAst::HdlStmAssign> visitConditional_variable_assignment(
			vhdlParser::Conditional_variable_assignmentContext *ctx);
	static std::unique_ptr<hdlAst::HdlStmAssign> visitSelected_variable_assignment(
			vhdlParser::Selected_variable_assignmentContext *ctx);
	static std::unique_ptr<hdlAst::iHdlStatement> visitReturn_statement(
			vhdlParser::Return_statementContext *ctx);
	static std::unique_ptr<hdlAst::iHdlStatement> visitLoop_statement(
			vhdlParser::Loop_statementContext *ctx);
	static std::pair<std::unique_ptr<hdlAst::iHdlExprItem>, std::unique_ptr<hdlAst::iHdlExprItem>> visitParameter_specification(
			vhdlParser::Parameter_specificationContext *ctx);
	static std::unique_ptr<hdlAst::iHdlStatement> visitSelected_waveforms(
			vhdlParser::Selected_waveformsContext *ctx,
			std::unique_ptr<hdlAst::iHdlExprItem> sel, std::unique_ptr<hdlAst::iHdlExprItem> dst,
			bool is_blocking);
	static std::unique_ptr<hdlAst::iHdlStatement> visitConcurrent_selected_signal_assignment(
			vhdlParser::Concurrent_selected_signal_assignmentContext *ctx);
	static std::unique_ptr<hdlAst::iHdlStatement> visitIteration_scheme(
			vhdlParser::Iteration_schemeContext *ctx);
	static std::unique_ptr<hdlAst::iHdlStatement> visitNull_statement(
			vhdlParser::Null_statementContext *ctx);
	static std::unique_ptr<hdlAst::iHdlStatement> visitAssertion(
			vhdlParser::AssertionContext *ctx);
	static std::unique_ptr<hdlAst::iHdlStatement> visitAssertion_statement(
			vhdlParser::Assertion_statementContext *ctx);
	static std::unique_ptr<hdlAst::iHdlStatement> visitConcurrent_assertion_statement(
			vhdlParser::Concurrent_assertion_statementContext *ctx);
	static std::unique_ptr<hdlAst::iHdlStatement> visitReport_statement(
			vhdlParser::Report_statementContext *ctx);
	static std::unique_ptr<hdlAst::iHdlStatement> visitWait_statement(
			vhdlParser::Wait_statementContext *ctx);
	static std::unique_ptr<hdlAst::iHdlStatement> visitCase_statement(
			vhdlParser::Case_statementContext *ctx);
	static std::unique_ptr<hdlAst::HdlStmBlock> visitSequence_of_statements(
			vhdlParser::Sequence_of_statementsContext *ctx);
	static std::unique_ptr<hdlAst::iHdlStatement> visitConcurrent_signal_assignment_statement(
			vhdlParser::Concurrent_signal_assignment_statementContext *ctx);
	void visitConcurrent_statement(vhdlParser::Concurrent_statementContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlObj>> &stms);
	std::unique_ptr<hdlAst::iHdlStatement> visitConcurrent_statement_with_optional_label(
			vhdlParser::Concurrent_statement_with_optional_labelContext *ctx);
};

}
}
