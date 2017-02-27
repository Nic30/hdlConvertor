#pragma once

#include <vector>
#include <stdlib.h>
#include "../VhdlParser/vhdlParser.h"
#include "../notImplementedLogger.h"
#include "../hdlObjects/operatorType.h"
#include "../hdlObjects/symbolType.h"
#include "../hdlObjects/expr.h"
#include "../hdlObjects/statement.h"
#include "exprParser.h"

using namespace antlr4;
using namespace vhdl;

class StatementParser {
public:
	static Statement * visitSequential_statement(
			vhdlParser::Sequential_statementContext* ctx);
	static Statement * visitSignal_assignment_statement(
			vhdlParser::Signal_assignment_statementContext* ctx);
	static Statement * visitVariable_assignment_statement(
			vhdlParser::Variable_assignment_statementContext* ctx);
	static Statement * visitIf_statement(
			vhdlParser::If_statementContext* ctx);
	static Statement * visitReturn_statement(
			vhdlParser::Return_statementContext* ctx);
	static Statement * visitLoop_statement(
			vhdlParser::Loop_statementContext* ctx);
	static Expr * visitCondition(vhdlParser::ConditionContext* ctx);
	static Statement * visitIteration_scheme(
			vhdlParser::Iteration_schemeContext* ctx);
	static std::vector<Statement*> * visitSequence_of_statements(
			vhdlParser::Sequence_of_statementsContext* ctx);
};
