#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/iHdlStatement.h>
#include <hdlConvertor/hdlObjects/hdlStmAssign.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace vhdl {

// [TODO] make methods non static and parse code positions and comments
class StatementParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;
	bool hierarchyOnly;
	StatementParser(bool _hierarchyOnly);

	static hdlObjects::iHdlStatement * visitSequential_statement(
			vhdlParser::Sequential_statementContext* ctx);
	static hdlObjects::iHdlStatement * visitSignal_assignment_statement(
			vhdlParser::Signal_assignment_statementContext* ctx);
	static hdlObjects::HdlStmAssign * visitSimple_signal_assignment(
			vhdlParser::Simple_signal_assignmentContext *ctx);
	static hdlObjects::HdlStmAssign * visitSimple_waveform_assignment(
			vhdlParser::Simple_waveform_assignmentContext *ctx);
	static hdlObjects::HdlStmAssign * visitSimple_force_assignment(
			vhdlParser::Simple_force_assignmentContext *ctx);
	static hdlObjects::HdlStmAssign * visitSimple_release_assignment(
			vhdlParser::Simple_release_assignmentContext *ctx);
	static hdlObjects::iHdlStatement * visitConditional_signal_assignment(
			vhdlParser::Conditional_signal_assignmentContext *ctx);
	static hdlObjects::iHdlStatement * visitConditional_waveform_assignment(
			vhdlParser::Conditional_waveform_assignmentContext *ctx);
	static hdlObjects::iHdlStatement * visitConditional_force_assignment(
			vhdlParser::Conditional_force_assignmentContext *ctx);
	static hdlObjects::iHdlStatement * visitSelected_signal_assignment(
			vhdlParser::Selected_signal_assignmentContext *ctx);
	static hdlObjects::iHdlStatement * visitVariable_assignment_statement(
			vhdlParser::Variable_assignment_statementContext* ctx);
	static hdlObjects::iHdlStatement * visitIf_statement(
			vhdlParser::If_statementContext* ctx);
	static hdlObjects::HdlStmAssign * visitSimple_variable_assignment(
			vhdlParser::Simple_variable_assignmentContext *ctx);
	static hdlObjects::HdlStmAssign * visitConditional_variable_assignment(
			vhdlParser::Conditional_variable_assignmentContext *ctx);
	static hdlObjects::HdlStmAssign * visitSelected_variable_assignment(
			vhdlParser::Selected_variable_assignmentContext *ctx);
	static hdlObjects::iHdlStatement * visitReturn_statement(
			vhdlParser::Return_statementContext* ctx);
	static hdlObjects::iHdlStatement * visitLoop_statement(
			vhdlParser::Loop_statementContext* ctx);
	static std::pair<hdlObjects::iHdlExpr*, hdlObjects::iHdlExpr*> visitParameter_specification(
			vhdlParser::Parameter_specificationContext *ctx);
	static hdlObjects::iHdlStatement * visitSelected_waveforms(
			vhdlParser::Selected_waveformsContext *ctx,
			hdlObjects::iHdlExpr * sel, hdlObjects::iHdlExpr * dst,
			bool is_blocking);
	static hdlObjects::iHdlStatement * visitConcurrent_selected_signal_assignment(
			vhdlParser::Concurrent_selected_signal_assignmentContext * ctx);
	static hdlObjects::iHdlStatement * visitIteration_scheme(
			vhdlParser::Iteration_schemeContext* ctx);
	static hdlObjects::iHdlStatement * visitNull_statement(
			vhdlParser::Null_statementContext * ctx);
	static hdlObjects::iHdlStatement * visitAssertion_statement(
			vhdlParser::Assertion_statementContext * ctx);
	static hdlObjects::iHdlStatement * visitReport_statement(
			vhdlParser::Report_statementContext *ctx);
	static hdlObjects::iHdlStatement * visitWait_statement(
			vhdlParser::Wait_statementContext * ctx);
	static hdlObjects::iHdlStatement * visitCase_statement(
			vhdlParser::Case_statementContext* ctx);
	static std::vector<hdlObjects::iHdlObj*> * visitSequence_of_statements(
			vhdlParser::Sequence_of_statementsContext* ctx);
	static hdlObjects::iHdlStatement * visitConcurrent_signal_assignment_statement(
			vhdlParser::Concurrent_signal_assignment_statementContext * ctx);
	void visitConcurrent_statement(
			vhdlParser::Concurrent_statementContext * ctx,
			std::vector<hdlObjects::iHdlObj*> & stms);
};

}
}
