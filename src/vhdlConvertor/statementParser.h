#pragma once

#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/expr.h"
#include "../hdlObjects/variable.h"
#include "../hdlObjects/statement.h"

class StatementParser {
public:
	static Statement * visitSequential_statement(
			vhdl::vhdlParser::Sequential_statementContext* ctx);
	static Statement * visitSignal_assignment_statement(
			vhdl::vhdlParser::Signal_assignment_statementContext* ctx);
	static Statement * visitVariable_assignment_statement(
			vhdl::vhdlParser::Variable_assignment_statementContext* ctx);
	static Statement * visitIf_statement(
			vhdl::vhdlParser::If_statementContext* ctx);
	static Statement * visitReturn_statement(
			vhdl::vhdlParser::Return_statementContext* ctx);
	static Statement * visitLoop_statement(
			vhdl::vhdlParser::Loop_statementContext* ctx);
	static Expr * visitCondition(vhdl::vhdlParser::ConditionContext* ctx);
	static Statement * visitIteration_scheme(
			vhdl::vhdlParser::Iteration_schemeContext* ctx);
	static std::vector<Statement*> * visitSequence_of_statements(
			vhdl::vhdlParser::Sequence_of_statementsContext* ctx);
	static Statement * visitProcess_statement(
			vhdl::vhdlParser::Process_statementContext * ctx);
	static void visitSensitivity_list(
			vhdl::vhdlParser::Sensitivity_listContext * ctx,
			std::vector<Expr*> & res);
	static std::vector<Variable*> visitProcess_declarative_part(
			vhdl::vhdlParser::Process_declarative_partContext * ctx);
	static void visitProcess_statement_part(
			vhdl::vhdlParser::Process_statement_partContext * ctx,
			std::vector<Statement*> & stms);
	static Statement * visitCase_statement(
			vhdl::vhdlParser::Case_statementContext * ctx);
	static std::pair<std::vector<Expr*>, std::vector<Statement*>*> visitCase_statement_alternative(
			vhdl::vhdlParser::Case_statement_alternativeContext * ctx);
};
