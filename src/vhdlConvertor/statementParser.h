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
			Ref<vhdlParser::Sequential_statementContext> ctx);
	static Statement * visitSignal_assignment_statement(
			Ref<vhdlParser::Signal_assignment_statementContext> ctx);
	static Statement * visitVariable_assignment_statement(
			Ref<vhdlParser::Variable_assignment_statementContext> ctx);
	static Statement * visitIf_statement(
			Ref<vhdlParser::If_statementContext> ctx);
	static Statement * visitReturn_statement(
			Ref<vhdlParser::Return_statementContext> ctx);
	static Statement * visitLoop_statement(
			Ref<vhdlParser::Loop_statementContext> ctx);
	static Expr * visitCondition(Ref<vhdlParser::ConditionContext> ctx);
	static Statement * visitIteration_scheme(
			Ref<vhdlParser::Iteration_schemeContext> ctx);
	static std::vector<Statement*> * visitSequence_of_statements(
			Ref<vhdlParser::Sequence_of_statementsContext> ctx);
};
