#include "statementParser.h"
#include "exprParser.h"
#include "../notImplementedLogger.h"
#include "literalParser.h"
#include "referenceParser.h"

using namespace std;
using namespace vhdl;

Statement * StatementParser::visitSequential_statement(
		vhdlParser::Sequential_statementContext* ctx) {
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
		return visitCase_statement(c);
	}

	auto l = ctx->loop_statement();
	if (l)
		return visitLoop_statement(l);

	NotImplementedLogger::print("StatementParser.visitSequential_statement");
	return NULL;

}
Statement * StatementParser::visitCase_statement(
		vhdlParser::Case_statementContext * ctx) {
	// case_statement
	//   : ( label_colon )? CASE expression IS
	//     ( case_statement_alternative )+
	//     END CASE ( identifier )? SEMI
	//   ;
	auto _e = ctx->expression();
	auto e = ExprParser::visitExpression(_e);
	vector<Statement::case_t> alternatives;
	vector<Statement*>* _default = nullptr;
	for (auto a : ctx->case_statement_alternative()) {
		// case_statement_alternative
		//   : WHEN choices ARROW sequence_of_statements
		//   ;
		for (auto ch: ExprParser::visitChoices(a->choices())) {
			auto s = a->sequence_of_statements();
			auto stms = visitSequence_of_statements(s);
			if (ch == nullptr) {
				assert(_default == nullptr);
				_default = stms;
			} else {
				alternatives.push_back({ch, stms});
			}
		}
	}
	return Statement::CASE(e, alternatives, _default);
}

Statement * StatementParser::visitSignal_assignment_statement(
		vhdlParser::Signal_assignment_statementContext* ctx) {
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
		vhdlParser::Variable_assignment_statementContext* ctx) {
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
		vhdlParser::If_statementContext* ctx) {
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
	vector<Statement*> * ifTrue = visitSequence_of_statements(*sIt);
	++sIt;
	if (sIt != s.end()) {
		return Statement::IF(cond, ifTrue, visitSequence_of_statements(*sIt));
	} else {
		return Statement::IF(cond, ifTrue);
	}
}
Statement * StatementParser::visitReturn_statement(
		vhdlParser::Return_statementContext* ctx) {
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
		vhdlParser::Loop_statementContext* ctx) {
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
Expr * StatementParser::visitCondition(vhdlParser::ConditionContext* ctx) {
	// condition
	// : expression
	// ;
	return ExprParser::visitExpression(ctx->expression());
}
Statement * StatementParser::visitIteration_scheme(
		vhdlParser::Iteration_schemeContext* ctx) {
	// iteration_scheme
	// : WHILE condition
	// | FOR parameter_specification
	// ;
	if (ctx->WHILE()) {
		return Statement::WHILE(visitCondition(ctx->condition()),
				new vector<Statement*>(0));
	} else {
		NotImplementedLogger::print(
				"StatementParser.visitIteration_scheme - FOR");
		return NULL;
	}

}
vector<Statement*> * StatementParser::visitSequence_of_statements(
		vhdlParser::Sequence_of_statementsContext* ctx) {
	// sequence_of_statements
	// : ( sequential_statement )*
	// ;
	vector<Statement*> * s = new vector<Statement*>();
	for (auto ss : ctx->sequential_statement()) {
		s->push_back(visitSequential_statement(ss));
	}
	return s;
}

Statement * StatementParser::visitProcess_statement(
		vhdl::vhdlParser::Process_statementContext * ctx) {
	// process_statement
	//   : ( label_colon )? ( POSTPONED )? PROCESS
	//     ( LPAREN sensitivity_list RPAREN )? ( IS )?
	//     process_declarative_part
	//     BEGIN
	//     process_statement_part
	//     END ( POSTPONED )? PROCESS ( identifier )? SEMI
	//   ;
	string name;
	auto lc = ctx->label_colon();
	auto sensitivity_list = new vector<Expr*>;
	auto stms = new vector<Statement*>;
	if (lc) {
		char * _name = LiteralParser::visitLabel_colon(lc);
		name = _name;
		free(_name);
	}
	if (ctx->POSTPONED().size()) {
		NotImplementedLogger::print(
				"StatementParser.visitProcess_statement - POSTPONED");
	}
	auto sl = ctx->sensitivity_list();
	if (sl) {
		visitSensitivity_list(sl, *sensitivity_list);
	}
	auto declr = ctx->process_declarative_part();
	visitProcess_declarative_part(declr);
	visitProcess_statement_part(ctx->process_statement_part(), *stms);

	auto p = Statement::PROCESS(sensitivity_list, stms);
	p->label = name;
	return p;
}
void StatementParser::visitSensitivity_list(
		vhdlParser::Sensitivity_listContext * ctx, vector<Expr*> & res) {
	// sensitivity_list
	//   : name ( COMMA name )*
	//   ;
	for (auto n : ctx->name()) {
		res.push_back(ReferenceParser::visitName(n));
	}
}
vector<Variable*> StatementParser::visitProcess_declarative_part(
		vhdlParser::Process_declarative_partContext * ctx) {
	//process_declarative_part
	//  : ( process_declarative_item )*
	//  ;
	for (auto i : ctx->process_declarative_item()) {
		NotImplementedLogger::print(
				"StatementParser.visitProcess_declarative_part - process_declarative_item");
	}
	return {};
}
void StatementParser::visitProcess_statement_part(
		vhdlParser::Process_statement_partContext * ctx,
		vector<Statement*> & stms) {
	//process_statement_part
	//  : ( sequential_statement )*
	//  ;
	for (auto s : ctx->sequential_statement()) {
		stms.push_back(visitSequential_statement(s));
	}
}

