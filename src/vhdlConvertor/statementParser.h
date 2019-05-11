#pragma once

#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/expr.h"
#include "../hdlObjects/variable.h"
#include "../hdlObjects/statement.h"

namespace hdlConvertor {
namespace vhdl {

class StatementParser {
public:
	using Statement = hdlObjects::Statement;
	using Expr = hdlObjects::Expr;
	using Variable = hdlObjects::Variable;
	using vhdlParser = vhdl_antlr::vhdlParser;

	static Statement * visitSequential_statement(
			vhdlParser::Sequential_statementContext* ctx);
	static Statement * visitSignal_assignment_statement(
			vhdlParser::Signal_assignment_statementContext* ctx);
	static Statement * visitVariable_assignment_statement(
			vhdlParser::Variable_assignment_statementContext* ctx);
	static Statement * visitIf_statement(vhdlParser::If_statementContext* ctx);
	static Statement * visitReturn_statement(
			vhdlParser::Return_statementContext* ctx);
	static Statement * visitLoop_statement(
			vhdlParser::Loop_statementContext* ctx);
	static Expr * visitCondition(vhdlParser::ConditionContext* ctx);
	static Statement * visitIteration_scheme(
			vhdlParser::Iteration_schemeContext* ctx);
	static std::vector<Statement*> * visitSequence_of_statements(
			vhdlParser::Sequence_of_statementsContext* ctx);
	static Statement * visitProcess_statement(
			vhdlParser::Process_statementContext * ctx);
	static void visitSensitivity_list(vhdlParser::Sensitivity_listContext * ctx,
			std::vector<Expr*> & res);
	static std::vector<Variable*> visitProcess_declarative_part(
			vhdlParser::Process_declarative_partContext * ctx);
	static void visitProcess_statement_part(
			vhdlParser::Process_statement_partContext * ctx,
			std::vector<Statement*> & stms);
	static Statement * visitCase_statement(
			vhdlParser::Case_statementContext * ctx);
	static std::pair<std::vector<Expr*>, std::vector<Statement*>*> visitCase_statement_alternative(
			vhdlParser::Case_statement_alternativeContext * ctx);
};

}
}
