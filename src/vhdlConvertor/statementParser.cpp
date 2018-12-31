#include "statementParser.h"

std::vector<Statement*> * StatementParser::visitSequence_of_statements(
		vhdlParser::Sequence_of_statementsContext* ctx) {
		// sequence_of_statements
		// : ( sequential_statement )*
		// ;	
	std::vector<Statement*> * s = new std::vector<Statement*>();
	for (auto ss : ctx->sequential_statement()) {
		auto st = visitSequential_statement(ss);
		if (st) {
			st->position = new Position(ss->getStart()->getLine(), ss->getStop()->getLine(), NULL, NULL);
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
		return Statement::NONE();
	}

	auto as = ctx->assertion_statement();
	if (as) {
		NotImplementedLogger::print(
				"StatementParser.visitSequential_statement - assertion_statement");
		return Statement::NONE();
	}

	auto r = ctx->report_statement();
	if (r) {
		NotImplementedLogger::print(
				"StatementParser.visitSequential_statement - report_statement");
		return Statement::NONE();
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
		NotImplementedLogger::print(
				"StatementParser.visitSequential_statement - next_statement");
		return Statement::NONE();
	}

	auto es = ctx->exit_statement();
	if (es) {
		NotImplementedLogger::print(
				"StatementParser.visitSequential_statement - exit_statement");
		return Statement::NONE();
	}

	auto rt = ctx->return_statement();
	if (rt)
		return visitReturn_statement(rt);

	auto nl = ctx->NULL_SYM();
	if (nl) {
		NotImplementedLogger::print(
				"StatementParser.visitSequential_statement - NULL_SYM");
		return Statement::NONE();
	}

	auto bs = ctx->break_statement();
	if (bs) {
		NotImplementedLogger::print(
				"StatementParser.visitSequential_statement - break_statement");
		return Statement::NONE();
	}

	auto pcs = ctx->procedure_call_statement();
	if (pcs) {
		NotImplementedLogger::print(
				"StatementParser.visitSequential_statement - procedure_call_statement");
		return Statement::NONE();
	}

	NotImplementedLogger::print(
			"StatementParser.visitSequential_statement");
	return Statement::NONE();
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

	if (ctx->selected_signal_assignment()) {
		return visitSelected_signal_assignment(ctx->selected_signal_assignment());
	}
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

	if (ctx->simple_release_assignment()) {
		return visitSimple_release_assignment(ctx->simple_release_assignment());
	}
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

	if (ctx->conditional_force_assignment()) {
		return visitConditional_force_assignment(ctx->conditional_force_assignment());
	}
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

	return Statement::NONE();
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

	if (ctx->selected_variable_assignment()) {
		return visitSelected_variable_assignment(ctx->selected_variable_assignment());
	}
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

	std::vector<Statement*> * ifStates = new std::vector<Statement*>();

	auto c = ctx->condition();
	auto cIt = c.begin();
	auto s = ctx->sequence_of_statements();
	auto sIt = s.begin();

	while (sIt != s.end()) {
		
		if (sIt == s.begin()) {
			Expr * cond = visitCondition(*cIt);
			std::vector<Statement*> * ifState = visitSequence_of_statements(*sIt);
			auto ifS = Statement::IF(cond, ifState);
			ifS->position = new Position((*sIt)->getStart()->getLine(), (*sIt)->getStop()->getLine(), NULL, NULL);
			ifStates->push_back(ifS);
			++cIt;
			++sIt;
		} else if (cIt == c.end() && ctx->ELSE()) {
			std::vector<Statement*> * ifState = visitSequence_of_statements(*sIt);
			auto elseS = Statement::ELSE(ifState);
			elseS->position = new Position((*sIt)->getStart()->getLine(), (*sIt)->getStop()->getLine(), NULL, NULL);
			ifStates->push_back(elseS);
			++sIt;
		} else {
			Expr * cond = visitCondition(*cIt);
			std::vector<Statement*> * ifState = visitSequence_of_statements(*sIt);
			auto elsifS = Statement::ELSIF(cond, ifState);
			elsifS->position = new Position((*sIt)->getStart()->getLine(), (*sIt)->getStop()->getLine(), NULL, NULL);
			ifStates->push_back(elsifS);
			++cIt;
			++sIt;
		} 		
	} 

	auto ifS = Statement::IFBODY(ifStates);
	ifS->position = new Position(ctx->getStart()->getLine(), ctx->getStop()->getLine(), NULL, NULL);
	return ifS;
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
	if (ctx->iteration_scheme())
		// iteration_scheme
		// : WHILE condition
		// | FOR parameter_specification
		// ;
		if (ctx->iteration_scheme()->WHILE()) {
			loop = Statement::WHILE(visitCondition(ctx->iteration_scheme()->condition()), 
					visitSequence_of_statements(ctx->sequence_of_statements()));
		} else {
			loop = Statement::FOR(visitParameter_specification(ctx->iteration_scheme()->parameter_specification()), 
					visitSequence_of_statements(ctx->sequence_of_statements()));
		}
	else {
		loop = Statement::WHILE(Expr::ID("True"),
				visitSequence_of_statements(ctx->sequence_of_statements()));
	}
	loop->position = new Position(ctx->getStart()->getLine(), ctx->getStop()->getLine(), NULL, NULL);
	return loop;
}

Expr* StatementParser::visitCondition(vhdlParser::ConditionContext* ctx) {
	// condition
	// : expression
	// ;
	return ExprParser::visitExpression(ctx->expression());
}

std::vector<Expr*> * StatementParser::visitParameter_specification(
		vhdlParser::Parameter_specificationContext *ctx) {
	//parameter_specification
	//  : identifier IN discrete_range
	//  ;
	std::vector<Expr*> * e = new std::vector<Expr*>();
	e->push_back(LiteralParser::visitIdentifier(ctx->identifier()));
	e->push_back(ExprParser::visitDiscrete_range(ctx->discrete_range()));
	return e;
}

Statement * StatementParser::visitCase_statement(
		vhdlParser::Case_statementContext* ctx) {
		//case_statement
		//  : ( label_colon )? CASE expression IS
		//    ( case_statement_alternative )+
		//    END CASE ( identifier )? SEMI
		//  ;
	if (ctx->label_colon()) {
		NotImplementedLogger::print(
				"StatementParser.case_statement - label_colon");
	}
	
	std::vector<Statement*> * cas = new std::vector<Statement*>();
	for (auto ca : ctx->case_statement_alternative()) {
		cas->push_back(visitCase_statement_alternative(ca));
	}

	auto e = ctx->expression();
	return Statement::CASE(ExprParser::visitExpression(e), cas);
}

Statement * StatementParser::visitCase_statement_alternative(
		vhdlParser::Case_statement_alternativeContext* ctx) {
		//case_statement_alternative
		//  : WHEN choices ARROW sequence_of_statements
		//  ;

	return Statement::CASE(visitChoices(ctx->choices()), 
				visitSequence_of_statements(ctx->sequence_of_statements()));
}

std::vector<Expr*> * StatementParser::visitChoices(vhdlParser::ChoicesContext *ctx) {
		//choices
		//	: choice ( BAR choice )*
		//	;
	std::vector<Expr*> * cs = new std::vector<Expr*>();
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

	if (ctx->OTHERS())
		return Expr::null();	
		
}
