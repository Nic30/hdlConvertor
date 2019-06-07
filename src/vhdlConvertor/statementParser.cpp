#include <hdlConvertor/vhdlConvertor/statementParser.h>
#include <hdlConvertor/vhdlConvertor/exprParser.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>
#include <hdlConvertor/vhdlConvertor/processParser.h>
#include <hdlConvertor/vhdlConvertor/generateStatementParser.h>
#include <hdlConvertor/vhdlConvertor/compInstanceParser.h>

namespace hdlConvertor {
namespace vhdl {

using namespace std;
using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlObjects;

StatementParser::StatementParser(bool _hierarchyOnly) :
		hierarchyOnly(_hierarchyOnly) {
}

vector<iHdlObj*> * StatementParser::visitSequence_of_statements(
		vhdlParser::Sequence_of_statementsContext* ctx) {
	// sequence_of_statements
	// : ( sequential_statement )*
	// ;
	auto s = new vector<iHdlObj*>();
	for (auto ss : ctx->sequential_statement()) {
		auto st = visitSequential_statement(ss);
		if (st) {
			st->position.update_from_elem(ctx);
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
	// sequential_statement:
	//       wait_statement
	//       | assertion_statement
	//       | report_statement
	//       | signal_assignment_statement
	//       | variable_assignment_statement
	//       | procedure_call_statement
	//       | if_statement
	//       | case_statement
	//       | loop_statement
	//       | next_statement
	//       | exit_statement
	//       | return_statement
	//       | null_statement
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

	auto pcs = ctx->procedure_call_statement();
	if (pcs)
		return Statement::EXPR(ExprParser::visitProcedure_call_statement(pcs));

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

	auto nl = ctx->null_statement();
	assert(nl);
	return visitNull_statement(nl);
}
Statement * StatementParser::visitNull_statement(
		vhdlParser::Null_statementContext * ctx) {
	// null_statement:
	//       ( label COLON )? NULL_SYM SEMI
	// ;
	if (ctx->label())
		NotImplementedLogger::print(
				"StatementParser.visitNull_statement - label");

	return nullptr;
}
Statement * StatementParser::visitCase_statement(
		vhdlParser::Case_statementContext * ctx) {
	// case_statement:
	//       ( label COLON )?
	//           CASE ( QUESTIONMARK )? expression IS
	//               case_statement_alternative
	//               ( case_statement_alternative )*
	//           END CASE ( QUESTIONMARK )? ( label )? SEMI
	// ;

	if (ctx->QUESTIONMARK().size()) {
		NotImplementedLogger::print(
				"StatementParser.visitCase_statement - QUESTIONMARK");
	}

	auto _e = ctx->expression();
	auto e = ExprParser::visitExpression(_e);
	vector<Statement::case_t> alternatives;
	vector<iHdlObj*>* _default = nullptr;
	for (auto a : ctx->case_statement_alternative()) {
		// case_statement_alternative
		//   : WHEN choices ARROW sequence_of_statements
		//   ;
		for (auto ch : ExprParser::visitChoices(a->choices())) {
			auto s = a->sequence_of_statements();
			auto stms = visitSequence_of_statements(s);
			auto _ch = dynamic_cast<Symbol*>(ch->data);
			if (_ch && _ch->type == SymbolType::symb_OTHERS) {
				delete ch;
				assert(_default == nullptr);
				_default = stms;
			} else {
				alternatives.push_back( { ch, stms });
			}
		}
	}
	auto cstm = Statement::CASE(e, alternatives, _default);
	auto labels = ctx->label();
	if (labels.size()) {
		cstm->labels.push_back(LiteralParser::visitLabel(labels[0]));
	}
	cstm->position.update_from_elem(ctx);
	return cstm;
}

Statement * StatementParser::visitSignal_assignment_statement(
		vhdlParser::Signal_assignment_statementContext* ctx) {
	//signal_assignment_statement
	//  : ( label_colon )? simple_signal_assignment
	//  | ( label_colon )? conditional_signal_assignment
	//  | ( label_colon )? selected_signal_assignment
	//  ;
	if (ctx->label())
		NotImplementedLogger::print(
				"StatementParser.visitSignal_assignment_statement - label_colon");

	if (ctx->simple_signal_assignment()) {
		return visitSimple_signal_assignment(ctx->simple_signal_assignment());
	}

	if (ctx->conditional_signal_assignment()) {
		return visitConditional_signal_assignment(
				ctx->conditional_signal_assignment());
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
		return visitSimple_waveform_assignment(
				ctx->simple_waveform_assignment());
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

Statement * StatementParser::visitSimple_force_assignment(
		vhdlParser::Simple_force_assignmentContext *ctx) {
	//simple_force_assignment
	//  : target LE FORCE (force_mode)? expression SEMI

	if (ctx->force_mode())
		NotImplementedLogger::print(
				"StatementParser.visitSimple_force_assignment - force_mode");

	return Statement::ASSIG(ExprParser::visitTarget(ctx->target()),
			ExprParser::visitExpression(ctx->expression()));
}

Statement * StatementParser::visitSimple_release_assignment(
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
		return visitConditional_waveform_assignment(
				ctx->conditional_waveform_assignment());
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
	if (ctx->label())
		NotImplementedLogger::print(
				"StatementParser.visitVariable_assignment_statement - label_colon");

	if (ctx->simple_variable_assignment()) {
		return visitSimple_variable_assignment(
				ctx->simple_variable_assignment());
	}

	if (ctx->conditional_variable_assignment()) {
		return visitConditional_variable_assignment(
				ctx->conditional_variable_assignment());
	}

	assert(ctx->selected_variable_assignment());
	return visitSelected_variable_assignment(
			ctx->selected_variable_assignment());
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
	// selected_variable_assignment:
	//       WITH expression SELECT ( QUESTIONMARK )?
	//           target VARASGN selected_expressions SEMI
	// ;

	NotImplementedLogger::print(
			"StatementParser.visitSelected_variable_assignments");

	return Statement::ASSIG(ExprParser::visitExpression(ctx->expression()),
			Expr::null());
}

Statement * StatementParser::visitIf_statement(
		vhdlParser::If_statementContext* ctx) {
	// if_statement:
	//       ( label COLON )?
	//           IF condition THEN
	//               sequence_of_statements
	//           ( ELSIF condition THEN
	//               sequence_of_statements )*
	//           ( ELSE
	//               sequence_of_statements )?
	//           END IF ( label )? SEMI

	auto c = ctx->condition();
	auto cIt = c.begin();
	auto s = ctx->sequence_of_statements();
	auto sIt = s.begin();

	Expr * cond = visitCondition(*cIt);
	vector<iHdlObj*> * ifTrue = visitSequence_of_statements(*sIt);
	++cIt;
	++sIt;
	std::vector<Statement::case_t> elseIfs;
	while (cIt != c.end()) {
		auto c = visitCondition(*cIt);
		auto stms = visitSequence_of_statements(*sIt);
		elseIfs.push_back( { c, stms });
		++cIt;
		++sIt;
	}
	++sIt;
	Statement * ifStm = nullptr;
	vector<iHdlObj*> * ifFalse = nullptr;
	if (sIt != s.end()) {
		ifFalse = visitSequence_of_statements(*sIt);
	}
	ifStm = Statement::IF(cond, ifTrue, elseIfs, ifFalse);
	ifStm->position.update_from_elem(ctx);
	auto labels = ctx->label();
	if (labels.size()) {
		ifStm->labels.push_back(LiteralParser::visitLabel(labels[0]));
	}
	return ifStm;
}

Statement * StatementParser::visitReturn_statement(
		vhdlParser::Return_statementContext* ctx) {
	// return_statement
	// : ( label_colon )? RETURN ( expression )? SEMI
	// ;
	if (ctx->label()) {
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
	// loop_statement:
	//       ( label COLON )?
	//           ( iteration_scheme )? LOOP
	//               sequence_of_statements
	//           END LOOP ( label )? SEMI
	// ;

	if (ctx->label().size()) {
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
			auto args = visitParameter_specification(
					is->parameter_specification());
			loop = Statement::FOR(*args,
					visitSequence_of_statements(ctx->sequence_of_statements()));
			delete args;
		}
	} else {
		loop = Statement::WHILE(Expr::ID("True"),
				visitSequence_of_statements(ctx->sequence_of_statements()));
	}
	loop->position.update_from_elem(ctx);
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

void StatementParser::visitConcurrent_statement(
		vhdlParser::Concurrent_statementContext * ctx,
		std::vector<iHdlObj*> & stms) {
	// concurrent_statement:
	//       block_statement
	//       | process_statement
	//       | concurrent_procedure_call_statement
	//       | concurrent_assertion_statement
	//       | concurrent_signal_assignment_statement
	//       | component_instantiation_statement
	//       | generate_statement
	//      ;

	auto b = ctx->block_statement();
	if (b) {
		NotImplementedLogger::print("ArchParser.visitBlock_statement");
		return;
	}
	auto p = ctx->process_statement();
	if (p) {
		auto _p = ProcessParser::visitProcess_statement(p);
		stms.push_back(_p);
		return;
	}
	auto cpc = ctx->concurrent_procedure_call_statement();
	if (cpc) {
		NotImplementedLogger::print(
				"ArchParser.visitConcurrent_procedure_call_statement");
		return;
	}
	auto ca = ctx->concurrent_assertion_statement();
	if (ca) {
		NotImplementedLogger::print(
				"ArchParser.visitConcurrent_assertion_statement");
		return;
	}
	auto csa = ctx->concurrent_signal_assignment_statement();
	if (csa) {
		NotImplementedLogger::print(
				"ArchParser.visitConcurrent_signal_assignment_statement");
		return;
	}

	auto ci = ctx->component_instantiation_statement();
	if (ci) {
		auto _ci = CompInstanceParser::visitComponent_instantiation_statement(
				ci);
		stms.push_back(_ci);
		return;
	}

	auto gs = ctx->generate_statement();
	assert(gs);
	GenerateStatementParser gsp(hierarchyOnly);
	auto _gs = gsp.visitGenerate_statement(gs);
	stms.push_back(_gs);
}

}
}
