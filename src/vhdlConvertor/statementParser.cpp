#include "statementParser.h"
#include "exprParser.h"
#include "../notImplementedLogger.h"
#include "literalParser.h"
#include "referenceParser.h"


namespace hdlConvertor {
namespace vhdl {

using namespace std;
using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlObjects;


vector<Statement*> * StatementParser::visitSequence_of_statements(
		vhdlParser::Sequence_of_statementsContext* ctx) {
		// sequence_of_statements
		// : ( sequential_statement )*
		// ;
	vector<Statement*> * s = new vector<Statement*>();
	for (auto ss : ctx->sequential_statement()) {
		auto st = visitSequential_statement(ss);
		if (st) {
			st->position = Position(ss->getStart()->getLine(), ss->getStop()->getLine(), -1, -1);
			s->push_back(st);
	}
	}
	return s;
}

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
	// | ( label_colon )? NULL_SYM SEMI
	// | break_statement
	// | procedure_call_statement
	// ;

	auto ws = ctx->wait_statement();
	if (ws) {
		NotImplementedLogger::print(
				"StatementParser.visitSequential_statement - wait_statement");
		return nullptr;
	}

	auto as = ctx->assertion_statement();
	if (as) {
		// [todo] convert to regular call
		NotImplementedLogger::print(
				"StatementParser.visitSequential_statement - assertion_statement");
		return nullptr;
	}

	auto r = ctx->report_statement();
	if (r) {
		// [todo] convert to regular call
		NotImplementedLogger::print(
				"StatementParser.visitSequential_statement - report_statement");
		return nullptr;
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

	auto c = ctx->case_statement();
	if (c)
		return visitCase_statement(c);

	auto l = ctx->loop_statement();
	if (l)
		return visitLoop_statement(l);

	auto ns = ctx->next_statement();
	if (ns) {
		// [todo] convert to wait statement
		NotImplementedLogger::print(
				"StatementParser.visitSequential_statement - next_statement");
		return nullptr;
	}

	auto es = ctx->exit_statement();
	if (es) {
		// [todo] convert to regular call
		NotImplementedLogger::print(
				"StatementParser.visitSequential_statement - exit_statement");
		return nullptr;
	}

	auto rt = ctx->return_statement();
	if (rt)
		return visitReturn_statement(rt);


	auto nl = ctx->NULL_SYM();
	if (nl) {
		return nullptr;
	}

	auto bs = ctx->break_statement();
	if (bs) {
		return Statement::BREAK();
	}

	auto pcs = ctx->procedure_call_statement();
	assert(pcs);
	return Statement::EXPR(ExprParser::visitProcedure_call_statement(pcs));
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
		for (auto ch : ExprParser::visitChoices(a->choices())) {
			auto s = a->sequence_of_statements();
			auto stms = visitSequence_of_statements(s);
			if (ch == nullptr) {
				assert(_default == nullptr);
				_default = stms;
			} else {
				alternatives.push_back( { ch, stms });
			}
		}
	}
	auto cstm = Statement::CASE(e, alternatives, _default);
	cstm->position = Position(ctx->getStart()->getLine(), ctx->getStop()->getLine(), -1, -1);
	return cstm;
}

Statement * StatementParser::visitSignal_assignment_statement(
		vhdlParser::Signal_assignment_statementContext* ctx) {
	//signal_assignment_statement
	//  : ( label_colon )? simple_signal_assignment
	//  | ( label_colon )? conditional_signal_assignment
	//  | ( label_colon )? selected_signal_assignment
	//  ;
	if (ctx->label_colon())
		NotImplementedLogger::print(
				"StatementParser.visitSignal_assignment_statement - label_colon");

	if (ctx->simple_signal_assignment()) {
		return visitSimple_signal_assignment(ctx->simple_signal_assignment());
	}

	if (ctx->conditional_signal_assignment()) {
		return visitConditional_signal_assignment(ctx->conditional_signal_assignment());
	}

	assert(ctx->selected_signal_assignment());
	return visitSelected_signal_assignment(ctx->selected_signal_assignment());
}

Statement * StatementParser::visitSimple_signal_assignment(
		vhdlParser::Simple_signal_assignmentContext *ctx) {
	//simple_signal_assignment
	//  : simple_waveform_assignment
	//  | simple_force_assignment
	//  | simple_release_assignment
	//  ;

	if (ctx->simple_waveform_assignment()) {
		return visitSimple_waveform_assignment(ctx->simple_waveform_assignment());
	}

	if (ctx->simple_force_assignment()) {
		return visitSimple_force_assignment(ctx->simple_force_assignment());
	}

	assert(ctx->simple_release_assignment());
	return visitSimple_release_assignment(ctx->simple_release_assignment());
}

Statement * StatementParser::visitSimple_waveform_assignment(
		vhdlParser::Simple_waveform_assignmentContext *ctx) {
	//simple_waveform_assignment
	//  : target LE (delay_mechanism)? waveform SEMI
	//  ;

	if (ctx->delay_mechanism())
		NotImplementedLogger::print(
				"StatementParser.visitSimple_waveform_assignment - delay_mechanism");

	return Statement::ASSIG(ExprParser::visitTarget(ctx->target()),
			ExprParser::visitWaveform(ctx->waveform()));
}

Statement *  StatementParser::visitSimple_force_assignment(
		vhdlParser::Simple_force_assignmentContext *ctx) {
	//simple_force_assignment
	//  : target LE FORCE (force_mode)? expression SEMI

	if (ctx->force_mode())
		NotImplementedLogger::print(
				"StatementParser.visitSimple_force_assignment - force_mode");

	return Statement::ASSIG(ExprParser::visitTarget(ctx->target()),
			ExprParser::visitExpression(ctx->expression()));
}

Statement *  StatementParser::visitSimple_release_assignment(
		vhdlParser::Simple_release_assignmentContext *ctx) {
	//simple_release_assignment
	//  : target LE RELEASE (force_mode)? SEMI
	//  ;

	if (ctx->force_mode())
		NotImplementedLogger::print(
				"StatementParser.visitSimple_release_assignment - force_mode");

	return Statement::ASSIG(ExprParser::visitTarget(ctx->target()),
			Expr::null());

}


Statement * StatementParser::visitConditional_signal_assignment(
		vhdlParser::Conditional_signal_assignmentContext *ctx) {
	//conditional_signal_assignment
	//  : conditional_waveform_assignment
	//  | conditional_force_assignment
	//  ;

	if (ctx->conditional_waveform_assignment()) {
		return visitConditional_waveform_assignment(ctx->conditional_waveform_assignment());
	}

	auto cfa = ctx->conditional_force_assignment();
	assert(cfa);
	return visitConditional_force_assignment(cfa);
}

Statement * StatementParser::visitConditional_waveform_assignment(
		vhdlParser::Conditional_waveform_assignmentContext *ctx) {
	//conditional_waveform_assignment
	//  : target LE (delay_mechanism)? conditional_waveforms
	//  ;

	if (ctx->delay_mechanism())
		NotImplementedLogger::print(
				"StatementParser.visitConditional_waveform_assignment - delay_mechanism");

	NotImplementedLogger::print(
		"StatementParser.visitConditional_waveform_assignment - conditional_waveforms");

	return Statement::ASSIG(ExprParser::visitTarget(ctx->target()),
			Expr::null());

}


Statement * StatementParser::visitConditional_force_assignment(
		vhdlParser::Conditional_force_assignmentContext *ctx) {
	//conditional_force_assignment
	//  : target LE FORCE (force_mode)? conditional_expression
	//  ;

	if (ctx->force_mode())
		NotImplementedLogger::print(
				"StatementParser.visitConditional_force_assignment - force_mode");

	NotImplementedLogger::print(
		"StatementParser.visitConditional_force_assignment - conditional_expression");

	return Statement::ASSIG(ExprParser::visitTarget(ctx->target()),
			Expr::null());

}

Statement * StatementParser::visitSelected_signal_assignment(
		vhdlParser::Selected_signal_assignmentContext *ctx) {
	//selected_signal_assignment
	//  : WITH expression SELECT (TERNARY)? target LE opts selected_waveforms SEMI
	//  ;

	NotImplementedLogger::print(
				"StatementParser.visitSelected_signal_assignment");

	return nullptr;
}


Statement * StatementParser::visitVariable_assignment_statement(
		vhdlParser::Variable_assignment_statementContext* ctx) {
	//variable_assignment_statement
	//  : ( label_colon )? simple_variable_assignment
	//  | ( label_colon )? conditional_variable_assignment
	//  | ( label_colon )? selected_variable_assignment
	//  ;
	if (ctx->label_colon())
		NotImplementedLogger::print(
				"StatementParser.visitVariable_assignment_statement - label_colon");

	if (ctx->simple_variable_assignment()) {
		return visitSimple_variable_assignment(ctx->simple_variable_assignment());
	}

	if (ctx->conditional_variable_assignment()) {
		return visitConditional_variable_assignment(ctx->conditional_variable_assignment());
	}

	assert(ctx->selected_variable_assignment());
	return visitSelected_variable_assignment(ctx->selected_variable_assignment());
}

Statement * StatementParser::visitSimple_variable_assignment(
		vhdlParser::Simple_variable_assignmentContext *ctx) {
	//simple_variable_assignment
	//  : target VARASGN expression SEMI
	//  ;

	return Statement::ASSIG(ExprParser::visitTarget(ctx->target()),
			ExprParser::visitExpression(ctx->expression()));
}

Statement * StatementParser::visitConditional_variable_assignment(
		vhdlParser::Conditional_variable_assignmentContext *ctx) {
	//conditional_variable_assignment
	//  : target VARASGN conditional_expression SEMI
	//  ;

	NotImplementedLogger::print(
		"StatementParser.visitConditional_variable_assignment - conditional_expression");

	return Statement::ASSIG(ExprParser::visitTarget(ctx->target()),
			Expr::null());
}

Statement * StatementParser::visitSelected_variable_assignment(
		vhdlParser::Selected_variable_assignmentContext *ctx) {
	//selected_variable_assignment
	// : WITH expression SELECT (TERNARY)?
	// ;

	if (ctx->TERNARY())
		NotImplementedLogger::print(
				"StatementParser.visitSelected_variable_assignments - TERNARY");

	return Statement::ASSIG(ExprParser::visitExpression(ctx->expression()),
			Expr::null());
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
	Statement * ifStm = nullptr;
	if (sIt != s.end()) {
		ifStm = Statement::IF(cond, ifTrue, visitSequence_of_statements(*sIt));
	} else {
		ifStm = Statement::IF(cond, ifTrue);
	}
	ifStm->position = Position(ctx->getStart()->getLine(), ctx->getStop()->getLine(), -1, -1);
	return ifStm;
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

	Statement * loop;
	auto is = ctx->iteration_scheme();
	if (is) {
		// iteration_scheme
		// : WHILE condition
		// | FOR parameter_specification
		// ;
		if (ctx->iteration_scheme()->WHILE()) {
			loop = Statement::WHILE(visitCondition(is->condition()),
					visitSequence_of_statements(ctx->sequence_of_statements()));
		} else {
			auto args = visitParameter_specification(is->parameter_specification());
			loop = Statement::FOR(*args,
					visitSequence_of_statements(ctx->sequence_of_statements()));
			delete args;
		}
	} else {
		loop = Statement::WHILE(Expr::ID("True"),
				visitSequence_of_statements(ctx->sequence_of_statements()));
	}
	loop->position = Position(ctx->getStart()->getLine(), ctx->getStop()->getLine(), -1, -1);
	return loop;
}

Expr* StatementParser::visitCondition(vhdlParser::ConditionContext* ctx) {
	// condition
	// : expression
	// ;
	return ExprParser::visitExpression(ctx->expression());
}

vector<Expr*> * StatementParser::visitParameter_specification(
		vhdlParser::Parameter_specificationContext *ctx) {
	//parameter_specification
	//  : identifier IN discrete_range
	//  ;
	vector<Expr*> * e = new vector<Expr*>();
	e->push_back(LiteralParser::visitIdentifier(ctx->identifier()));
	e->push_back(ExprParser::visitDiscrete_range(ctx->discrete_range()));
	return e;
}

vector<Expr*> * StatementParser::visitChoices(vhdlParser::ChoicesContext *ctx) {
		//choices
		//	: choice ( BAR choice )*
		//	;
	vector<Expr*> * cs = new vector<Expr*>();
	for (auto c : ctx->choice()) {
		cs->push_back(visitChoice(c));
	}
	return cs;
}

Expr * StatementParser::visitChoice(vhdlParser::ChoiceContext *ctx) {
	//choice
	//  : identifier
	//  | discrete_range
	//  | simple_expression
	//  | OTHERS
	//  ;

	if (ctx->identifier())
		return LiteralParser::visitIdentifier(ctx->identifier());

	if (ctx->discrete_range())
		return ExprParser::visitDiscrete_range(ctx->discrete_range());

	if  (ctx->simple_expression())
		return ExprParser::visitSimple_expression(ctx->simple_expression());

	assert(ctx->OTHERS());
	return Expr::null();
}

Statement * StatementParser::visitProcess_statement(
		vhdlParser::Process_statementContext * ctx) {
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

}
}
