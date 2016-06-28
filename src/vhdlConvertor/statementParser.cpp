#include "statementParser.h"

Statement * StatementParser::visitSequential_statement(
		Ref<vhdlParser::Sequential_statementContext> ctx) {
	// sequential_statement :
	// wait_statement
	// | assertion_statement
	// | report_statement
	// | signal_assignment_statement
	// | variable_assignment_statement
	// | if_statement
	// | case_statement
	// | loop_statement
	// | next_statement
	// | exit_statement
	// | return_statement
	// | ( label_colon )? NULL SEMI
	// | break_statement
	// | procedure_call_statement
	// ;
	auto as = ctx->assertion_statement();
	if (as) {
		NotImplementedLogger::print(
				"StatementParser.visitSequential_statement - assertion_statement");
		return NULL;
	}

	auto r = ctx->report_statement();
	if (r) {
		NotImplementedLogger::print(
				"StatementParser.visitSequential_statement - report_statement");
		return NULL;
	}

	auto sas = ctx->signal_assignment_statement();
	if (sas)
		return visitSignal_assignment_statement(sas);

	auto vas = ctx->variable_assignment_statement();
	if (vas)
		return visitVariable_assignment_statement(vas);

	auto ifStm = ctx->if_statement();
	if (ifStm)
		return visitIf_statement(ifStm);

	auto rt = ctx->return_statement();
	if (rt)
		return visitReturn_statement(rt);

	auto c = ctx->case_statement();
	if (c) {
		NotImplementedLogger::print(
				"StatementParser.visitSequential_statement - case_statement");
		return NULL;
	}

	auto l = ctx->loop_statement();
	if (l)
		return visitLoop_statement(l);

	NotImplementedLogger::print("StatementParser.visitSequential_statement");
	return NULL;

}
Statement * StatementParser::visitSignal_assignment_statement(
		Ref<vhdlParser::Signal_assignment_statementContext> ctx) {
	// signal_assignment_statement :
	// ( label_colon )?
	// target LE ( delay_mechanism )? waveform SEMI
	// ;
	if (ctx->label_colon())
		NotImplementedLogger::print(
				"StatementParser.visitSignal_assignment_statement - label_colon");
	if (ctx->delay_mechanism())
		NotImplementedLogger::print(
				"StatementParser.visitSignal_assignment_statement - delay_mechanism");

	return Statement::ASSIG(ExprParser::visitTarget(ctx->target()),
			ExprParser::visitWaveform(ctx->waveform()));

}
Statement * StatementParser::visitVariable_assignment_statement(
		Ref<vhdlParser::Variable_assignment_statementContext> ctx) {
	// variable_assignment_statement :
	// ( label_colon )? target VARASGN expression SEMI
	// ;
	if (ctx->label_colon())
		NotImplementedLogger::print(
				"StatementParser.visitSignal_assignment_statement - label_colon");

	return Statement::ASSIG(ExprParser::visitTarget(ctx->target()),
			ExprParser::visitExpression(ctx->expression()));
}
Statement * StatementParser::visitIf_statement(
		Ref<vhdlParser::If_statementContext> ctx) {
	// if_statement :
	// ( label_colon )? IF condition THEN
	// sequence_of_statements
	// ( ELSIF condition THEN sequence_of_statements )*
	// ( ELSE sequence_of_statements )?
	// END IF ( identifier )? SEMI
	// ;
	if (ctx->label_colon())
		NotImplementedLogger::print(
				"StatementParser.visitIf_statement - label_colon");

	auto c = ctx->condition();
	auto cIt = c.begin();
	auto s = ctx->sequence_of_statements();
	auto sIt = s.begin();

	Expr * cond = visitCondition(*cIt);
	++cIt;
	if (cIt != c.end()) {
		NotImplementedLogger::print(
				"StatementParser.visitIf_statement - ELSIF");
	}
	std::vector<Statement*> * ifTrue = visitSequence_of_statements(*sIt);
	++sIt;
	if (sIt != s.end()) {
		return Statement::IF(cond, ifTrue, visitSequence_of_statements(*sIt));
	} else {
		return Statement::IF(cond, ifTrue);
	}
}
Statement * StatementParser::visitReturn_statement(
		Ref<vhdlParser::Return_statementContext> ctx) {
	// return_statement
	// : ( label_colon )? RETURN ( expression )? SEMI
	// ;
	if (ctx->label_colon()) {
		NotImplementedLogger::print(
				"StatementParser.visitReturn_statement - label_colon");
	}
	auto e = ctx->expression();
	if (e) {
		return Statement::RETURN(ExprParser::visitExpression(e));
	} else {
		return Statement::RETURN();
	}

}
Statement * StatementParser::visitLoop_statement(
		Ref<vhdlParser::Loop_statementContext> ctx) {
	// loop_statement :
	// ( label_colon )? ( iteration_scheme )?
	// LOOP
	// sequence_of_statements
	// END LOOP ( identifier )? SEMI
	// ;
	if (ctx->label_colon()) {
		NotImplementedLogger::print(
				"StatementParser.visitLoop_statement - label_colon");
	}
	auto is = ctx->iteration_scheme();
	Statement * loop;

	if (is)
		loop = visitIteration_scheme(is);
	else {
		loop = Statement::WHILE(Expr::ID("True"),
				visitSequence_of_statements(ctx->sequence_of_statements()));
	}
	return loop;
}
Expr * StatementParser::visitCondition(Ref<vhdlParser::ConditionContext> ctx) {
	// condition
	// : expression
	// ;
	return ExprParser::visitExpression(ctx->expression());
}
Statement * StatementParser::visitIteration_scheme(
		Ref<vhdlParser::Iteration_schemeContext> ctx) {
	// iteration_scheme
	// : WHILE condition
	// | FOR parameter_specification
	// ;
	if (ctx->WHILE()) {
		return Statement::WHILE(visitCondition(ctx->condition()), new std::vector<Statement*>(0));
	} else {
		NotImplementedLogger::print(
				"StatementParser.visitIteration_scheme - FOR");
		return NULL;
	}

}
std::vector<Statement*> * StatementParser::visitSequence_of_statements(
		Ref<vhdlParser::Sequence_of_statementsContext> ctx) {
// sequence_of_statements
// : ( sequential_statement )*
// ;
	std::vector<Statement*> * s = new std::vector<Statement*>();
	for (auto ss : ctx->sequential_statement()) {
		s->push_back(visitSequential_statement(ss));
	}
	return s;
}
