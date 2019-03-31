#pragma once

#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/expr.h"
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
};
