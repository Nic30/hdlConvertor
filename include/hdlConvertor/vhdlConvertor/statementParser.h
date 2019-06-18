#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/hdlObjects/expr.h>
#include <hdlConvertor/hdlObjects/variable.h>
#include <hdlConvertor/hdlObjects/statement.h>

namespace hdlConvertor {
namespace vhdl {

// [TODO] make methods non static and parse code positions and comments
class StatementParser {
public:
	using Statement = hdlObjects::Statement;
	using Expr = hdlObjects::Expr;
	using Variable = hdlObjects::Variable;
	using vhdlParser = vhdl_antlr::vhdlParser;
	bool hierarchyOnly;
	StatementParser(bool _hierarchyOnly);

	static Statement * visitSequential_statement(
			vhdlParser::Sequential_statementContext* ctx);
	static Statement * visitSignal_assignment_statement(
			vhdlParser::Signal_assignment_statementContext* ctx);
	static Statement * visitSimple_signal_assignment(
			vhdlParser::Simple_signal_assignmentContext *ctx);
	static Statement * visitSimple_waveform_assignment(
			vhdlParser::Simple_waveform_assignmentContext *ctx);
	static Statement * visitSimple_force_assignment(
			vhdlParser::Simple_force_assignmentContext *ctx);
	static Statement * visitSimple_release_assignment(
			vhdlParser::Simple_release_assignmentContext *ctx);
	static Statement * visitConditional_signal_assignment(
			vhdlParser::Conditional_signal_assignmentContext *ctx);
	static Statement * visitConditional_waveform_assignment(
			vhdlParser::Conditional_waveform_assignmentContext *ctx);
	static Statement * visitConditional_force_assignment(
			vhdlParser::Conditional_force_assignmentContext *ctx);
	static Statement * visitSelected_signal_assignment(
			vhdlParser::Selected_signal_assignmentContext *ctx);
	static Statement * visitVariable_assignment_statement(
			vhdlParser::Variable_assignment_statementContext* ctx);
	static Statement * visitIf_statement(vhdlParser::If_statementContext* ctx);
	static Statement * visitSimple_variable_assignment(
			vhdlParser::Simple_variable_assignmentContext *ctx);
	static Statement * visitConditional_variable_assignment(
			vhdlParser::Conditional_variable_assignmentContext *ctx);
	static Statement * visitSelected_variable_assignment(
			vhdlParser::Selected_variable_assignmentContext *ctx);
	static Statement * visitReturn_statement(
			vhdlParser::Return_statementContext* ctx);
	static Statement * visitLoop_statement(
			vhdlParser::Loop_statementContext* ctx);
	static std::vector<Expr*> * visitParameter_specification(
			vhdlParser::Parameter_specificationContext *ctx);
	static Statement * visitSelected_waveforms(
			vhdlParser::Selected_waveformsContext *ctx, Expr * sel, Expr * dst);
	static Statement * visitConcurrent_selected_signal_assignment(
			vhdlParser::Concurrent_selected_signal_assignmentContext * ctx);
	static Statement * visitIteration_scheme(
			vhdlParser::Iteration_schemeContext* ctx);
	static Statement * visitNull_statement(
			vhdlParser::Null_statementContext * ctx);
	static Statement * visitAssertion_statement(
			vhdlParser::Assertion_statementContext * ctx);
	static Statement * visitReport_statement(
			vhdlParser::Report_statementContext *ctx);
	static Statement * visitWait_statement(
			vhdlParser::Wait_statementContext * ctx);
	static Statement * visitCase_statement(
			vhdlParser::Case_statementContext* ctx);
	static std::vector<hdlObjects::iHdlObj*> * visitSequence_of_statements(
			vhdlParser::Sequence_of_statementsContext* ctx);
	static Statement * visitConcurrent_signal_assignment_statement(
			vhdlParser::Concurrent_signal_assignment_statementContext * ctx);
	void visitConcurrent_statement(
			vhdlParser::Concurrent_statementContext * ctx,
			std::vector<hdlObjects::iHdlObj*> & stms);
};

}
}
