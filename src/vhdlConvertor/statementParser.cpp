#include <hdlConvertor/vhdlConvertor/referenceParser.h>

#include <assert.h>

#include <hdlConvertor/createObject.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/hdlAst/hdlStmExpr.h>
#include <hdlConvertor/hdlAst/hdlStm_others.h>
#include <hdlConvertor/hdlAst/hdlStmFor.h>
#include <hdlConvertor/hdlAst/hdlStmWhile.h>
#include <hdlConvertor/vhdlConvertor/compInstanceParser.h>
#include <hdlConvertor/vhdlConvertor/exprParser.h>
#include <hdlConvertor/vhdlConvertor/generateStatementParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/processParser.h>
#include <hdlConvertor/vhdlConvertor/statementParser.h>

using namespace std;
using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlAst;

namespace hdlConvertor {
namespace vhdl {

bool is_others(unique_ptr<iHdlExprItem> &e) {
	auto _e = dynamic_cast<HdlValueSymbol*>(e.get());
	return (_e && _e->symb == HdlValueSymbol_t::symb_OTHERS);
}

unique_ptr<HdlStmBlock> VhdlStatementParser::visitSequence_of_statements(
		vhdlParser::Sequence_of_statementsContext *ctx) {
	// sequence_of_statements
	// : ( sequential_statement )*
	// ;
	auto b = create_object<HdlStmBlock>(ctx);
	for (auto ss : ctx->sequential_statement()) {
		auto st = visitSequential_statement(ss);
		assert(st);
		b->statements.push_back(move(st));
	}
	return b;
}

unique_ptr<iHdlStatement> VhdlStatementParser::visitSequential_statement(
		vhdlParser::Sequential_statementContext *ctx) {
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
		return visitWait_statement(ws);
	}

	auto as = ctx->assertion_statement();
	if (as)
		return visitAssertion_statement(as);

	auto r = ctx->report_statement();
	if (r)
		return visitReport_statement(r);

	auto sas = ctx->signal_assignment_statement();
	if (sas)
		return visitSignal_assignment_statement(sas);

	auto vas = ctx->variable_assignment_statement();
	if (vas)
		return visitVariable_assignment_statement(vas);

	auto pcs = ctx->procedure_call_statement();
	if (pcs)
		return create_object<HdlStmExpr>(ctx,
				VhdlExprParser::visitProcedure_call_statement(pcs));

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
				"VhdlStatementParser.visitSequential_statement - next_statement",
				ns);
		return create_object<HdlStmNop>(ctx);
	}

	auto es = ctx->exit_statement();
	if (es) {
		// [todo] convert to regular call
		NotImplementedLogger::print(
				"VhdlStatementParser.visitSequential_statement - exit_statement",
				es);
		return create_object<HdlStmNop>(ctx);
	}

	auto rt = ctx->return_statement();
	if (rt)
		return visitReturn_statement(rt);

	auto nl = ctx->null_statement();
	assert(nl);
	return visitNull_statement(nl);
}

unique_ptr<iHdlStatement> VhdlStatementParser::visitAssertion_statement(
		vhdlParser::Assertion_statementContext *ctx) {
	// assertion_statement: assertion SEMI;
	return visitAssertion(ctx->assertion());
}
unique_ptr<iHdlStatement> VhdlStatementParser::visitAssertion(
			vhdlParser::AssertionContext *ctx) {
	// assertion:
	//       ASSERT condition
	//           ( REPORT expression )?
	//           ( SEVERITY expression )?
	// ;

	vector<unique_ptr<iHdlExprItem>> args;
	auto fn_name = create_object<HdlValueId>(ctx->KW_ASSERT(), "assert");

	auto c = VhdlExprParser::visitCondition(ctx->condition());
	args.push_back(move(c));
	auto exprs = ctx->expression();
	for (auto _e : exprs) {
		// [FIXME] not correct it is not possible to distinguish between report and severity
		auto e = VhdlExprParser::visitExpression(_e);
		args.push_back(move(e));
	}
	auto call = HdlOp::call(ctx, move(fn_name), args);
	return create_object<HdlStmExpr>(ctx, move(call));
}
unique_ptr<iHdlStatement> VhdlStatementParser::visitConcurrent_assertion_statement(
		vhdlParser::Concurrent_assertion_statementContext *ctx) {
	// concurrent_assertion_statement:
	//       ( KW_POSTPONED )? assertion SEMI
	// ;
	if (ctx->KW_POSTPONED()) {
		NotImplementedLogger::print(
				"VhdlStatementParser.visitConcurrent_selected_signal_assignment - KW_POSTPONED",
				ctx);
	}
	return VhdlStatementParser::visitAssertion(ctx->assertion());
}

unique_ptr<iHdlStatement> VhdlStatementParser::visitReport_statement(
		vhdlParser::Report_statementContext *ctx) {
	// report_statement:
	//           REPORT expression
	//               ( SEVERITY expression )? SEMI
	// ;
	auto fn_name = create_object<HdlValueId>(ctx->KW_REPORT(), "report");

	vector<unique_ptr<iHdlExprItem>> args;
	auto exprs = ctx->expression();
	for (auto _e : exprs) {
		auto e = VhdlExprParser::visitExpression(_e);
		args.push_back(move(e));
	}
	auto c = HdlOp::call(ctx, move(fn_name), args);
	return create_object<HdlStmExpr>(ctx, move(c));
}

unique_ptr<iHdlStatement> VhdlStatementParser::visitWait_statement(
		vhdlParser::Wait_statementContext *ctx) {
	// wait_statement:
	//        WAIT ( sensitivity_clause )? ( condition_clause )? ( timeout_clause )? SEMI
	// ;

	auto sc = ctx->sensitivity_clause();
	auto cc = ctx->condition_clause();
	auto tc = ctx->timeout_clause();

	vector<unique_ptr<iHdlExprItem>> sens;
	if (sc) {
		// sensitivity_clause: ON sensitivity_list;
		// sensitivity_list: name ( COMMA name )*;
		VhdlProcessParser pp(commentParser, hierarchyOnly);
		pp.visitSensitivity_list(sc->sensitivity_list(), sens);
	}
	if (cc) {
		// condition_clause: UNTIL condition;
		auto e = VhdlExprParser::visitCondition(cc->condition());
		e = create_object<HdlOp>(cc, HdlOpType::NEG, move(e));
		sens.push_back(move(e));
	}

	if (tc) {
		// timeout_clause: FOR expression;
		auto e = VhdlExprParser::visitExpression(tc->expression());
		sens.push_back(move(e));
	}
	return create_object<HdlStmWait>(ctx, sens);
}

unique_ptr<iHdlStatement> VhdlStatementParser::visitNull_statement(
		vhdlParser::Null_statementContext *ctx) {
	// null_statement:
	//        NULL_SYM SEMI
	// ;
	return create_object<HdlStmExpr>(ctx, HdlValueSymbol::null());
}

unique_ptr<iHdlStatement> VhdlStatementParser::visitCase_statement(
		vhdlParser::Case_statementContext *ctx) {
	// case_statement:
	//           CASE ( QUESTIONMARK )? expression IS
	//               case_statement_alternative
	//               ( case_statement_alternative )*
	//           END CASE ( QUESTIONMARK )? ( label )? SEMI
	// ;

	if (ctx->QUESTIONMARK().size()) {
		NotImplementedLogger::print(
				"VhdlStatementParser.visitCase_statement - QUESTIONMARK", ctx);
	}

	auto _e = ctx->expression();
	auto e = VhdlExprParser::visitExpression(_e);
	vector<HdlExprAndiHdlObj> alternatives;
	unique_ptr<iHdlStatement> _default = nullptr;
	for (auto a : ctx->case_statement_alternative()) {
		// case_statement_alternative
		//   : WHEN choices ARROW sequence_of_statements
		//   ;
		for (auto &ch : VhdlExprParser::visitChoices(a->choices())) {
			auto s = a->sequence_of_statements();
			auto stms = visitSequence_of_statements(s);
			if (is_others(ch)) {
				assert(_default == nullptr);
				_default = move(stms);
			} else {
				alternatives.push_back(HdlExprAndiHdlObj(move(ch), move(stms)));
			}
		}
	}
	auto cstm = create_object<HdlStmCase>(ctx, move(e), alternatives,
			move(_default));
	auto label = ctx->label();
	if (label) {
		cstm->labels.push_back(VhdlLiteralParser::visitLabel(label));
	}
	return cstm;
}

unique_ptr<iHdlStatement> VhdlStatementParser::visitSignal_assignment_statement(
		vhdlParser::Signal_assignment_statementContext *ctx) {
	//signal_assignment_statement
	//  : simple_signal_assignment
	//  | conditional_signal_assignment
	//  | selected_signal_assignment
	//  ;

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

unique_ptr<HdlStmAssign> VhdlStatementParser::visitSimple_signal_assignment(
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

unique_ptr<HdlStmAssign> VhdlStatementParser::visitSimple_waveform_assignment(
		vhdlParser::Simple_waveform_assignmentContext *ctx) {
	//simple_waveform_assignment
	//  : target LE (delay_mechanism)? waveform SEMI
	//  ;

	if (ctx->delay_mechanism())
		NotImplementedLogger::print(
				"VhdlStatementParser.visitSimple_waveform_assignment - delay_mechanism",
				ctx);

	auto dst = VhdlExprParser::visitTarget(ctx->target());
	auto src = VhdlExprParser::visitWaveform(ctx->waveform());
	return create_object<HdlStmAssign>(ctx, move(dst), move(src), false);
}

unique_ptr<HdlStmAssign> VhdlStatementParser::visitSimple_force_assignment(
		vhdlParser::Simple_force_assignmentContext *ctx) {
	//simple_force_assignment
	//  : target LE FORCE (force_mode)? expression SEMI

	if (ctx->force_mode())
		NotImplementedLogger::print(
				"VhdlStatementParser.visitSimple_force_assignment - force_mode",
				ctx);

	return create_object<HdlStmAssign>(ctx,
			VhdlExprParser::visitTarget(ctx->target()),
			VhdlExprParser::visitExpression(ctx->expression()), false);
}

unique_ptr<HdlStmAssign> VhdlStatementParser::visitSimple_release_assignment(
		vhdlParser::Simple_release_assignmentContext *ctx) {
	//simple_release_assignment
	//  : target LE RELEASE (force_mode)? SEMI
	//  ;

	if (ctx->force_mode())
		NotImplementedLogger::print(
				"VhdlStatementParser.visitSimple_release_assignment - force_mode",
				ctx);

	return create_object<HdlStmAssign>(ctx,
			VhdlExprParser::visitTarget(ctx->target()),
			create_object<HdlExprNotImplemented>(ctx), false);

}

unique_ptr<iHdlStatement> VhdlStatementParser::visitConditional_signal_assignment(
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

unique_ptr<iHdlStatement> VhdlStatementParser::visitConditional_waveform_assignment(
		vhdlParser::Conditional_waveform_assignmentContext *ctx) {
	//conditional_waveform_assignment
	//  : target LE (delay_mechanism)? conditional_waveforms
	//  ;

	if (ctx->delay_mechanism())
		NotImplementedLogger::print(
				"VhdlStatementParser.visitConditional_waveform_assignment - delay_mechanism",
				ctx);

	auto src = VhdlExprParser::visitTarget(ctx->target());
	auto dst = VhdlExprParser::visitConditional_waveforms(
			ctx->conditional_waveforms());
	return create_object<HdlStmAssign>(ctx, move(src), move(dst), false);

}

unique_ptr<iHdlStatement> VhdlStatementParser::visitConditional_force_assignment(
		vhdlParser::Conditional_force_assignmentContext *ctx) {
	//conditional_force_assignment
	//  : target LE FORCE (force_mode)? conditional_expression
	//  ;

	if (ctx->force_mode())
		NotImplementedLogger::print(
				"VhdlStatementParser.visitConditional_force_assignment - force_mode",
				ctx);

	NotImplementedLogger::print(
			"VhdlStatementParser.visitConditional_force_assignment - conditional_expression",
			ctx);

	return create_object<HdlStmAssign>(ctx,
			VhdlExprParser::visitTarget(ctx->target()),
			create_object<HdlExprNotImplemented>(ctx), false);

}

unique_ptr<iHdlStatement> VhdlStatementParser::visitSelected_signal_assignment(
		vhdlParser::Selected_signal_assignmentContext *ctx) {
	//selected_signal_assignment
	//  : WITH expression SELECT (TERNARY)? target LE opts selected_waveforms SEMI
	//  ;

	NotImplementedLogger::print(
			"VhdlStatementParser.visitSelected_signal_assignment", ctx);

	return nullptr;
}

unique_ptr<iHdlStatement> VhdlStatementParser::visitVariable_assignment_statement(
		vhdlParser::Variable_assignment_statementContext *ctx) {
	// variable_assignment_statement:
	//           simple_variable_assignment
	// 	      | conditional_variable_assignment
	// 	      | selected_variable_assignment
	// ;

	if (ctx->simple_variable_assignment()) {
		return visitSimple_variable_assignment(
				ctx->simple_variable_assignment());
	}

	if (ctx->conditional_variable_assignment()) {
		return visitConditional_variable_assignment(
				ctx->conditional_variable_assignment());
	}

	assert(ctx->selected_variable_assignment());
	auto sva = ctx->selected_variable_assignment();
	return visitSelected_variable_assignment(sva);
}

unique_ptr<HdlStmAssign> VhdlStatementParser::visitSimple_variable_assignment(
		vhdlParser::Simple_variable_assignmentContext *ctx) {
	//simple_variable_assignment
	//  : target VARASGN expression SEMI
	//  ;

	return create_object<HdlStmAssign>(ctx,
			VhdlExprParser::visitTarget(ctx->target()),
			VhdlExprParser::visitExpression(ctx->expression()), true);
}

unique_ptr<HdlStmAssign> VhdlStatementParser::visitConditional_variable_assignment(
		vhdlParser::Conditional_variable_assignmentContext *ctx) {
	//conditional_variable_assignment
	//  : target VARASGN conditional_expression SEMI
	//  ;

	NotImplementedLogger::print(
			"VhdlStatementParser.visitConditional_variable_assignment - conditional_expression",
			ctx);

	return create_object<HdlStmAssign>(ctx,
			VhdlExprParser::visitTarget(ctx->target()),
			create_object<HdlExprNotImplemented>(ctx), true);
}

unique_ptr<HdlStmAssign> VhdlStatementParser::visitSelected_variable_assignment(
		vhdlParser::Selected_variable_assignmentContext *ctx) {
	// selected_variable_assignment:
	//       WITH expression SELECT ( QUESTIONMARK )?
	//           target VARASGN selected_expressions SEMI
	// ;

	NotImplementedLogger::print(
			"VhdlStatementParser.visitSelected_variable_assignments", ctx);

	return create_object<HdlStmAssign>(ctx,
			VhdlExprParser::visitExpression(ctx->expression()),
			create_object<HdlExprNotImplemented>(ctx), true);
}

unique_ptr<iHdlStatement> VhdlStatementParser::visitIf_statement(
		vhdlParser::If_statementContext *ctx) {
	// if_statement:
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

	auto cond = VhdlExprParser::visitCondition(*cIt);
	auto ifTrue = visitSequence_of_statements(*sIt);
	++cIt;
	++sIt;
	vector<HdlExprAndiHdlObj> elseIfs;
	while (cIt != c.end()) {
		auto c = VhdlExprParser::visitCondition(*cIt);
		auto stms = visitSequence_of_statements(*sIt);
		elseIfs.push_back(HdlExprAndiHdlObj(move(c), move(stms)));
		++cIt;
		++sIt;
	}
	unique_ptr<iHdlStatement> ifStm = nullptr;
	unique_ptr<iHdlStatement> ifFalse = nullptr;
	if (sIt != s.end()) {
		ifFalse = visitSequence_of_statements(*sIt);
	}
	ifStm = create_object<HdlStmIf>(ctx, move(cond), move(ifTrue), elseIfs,
			move(ifFalse));
	auto label = ctx->label();
	if (label) {
		ifStm->labels.push_back(VhdlLiteralParser::visitLabel(label));
	}
	return ifStm;
}

unique_ptr<iHdlStatement> VhdlStatementParser::visitReturn_statement(
		vhdlParser::Return_statementContext *ctx) {
	// return_statement
	// : RETURN ( expression )? SEMI
	// ;
	auto e = ctx->expression();
	if (e) {
		return create_object<HdlStmReturn>(ctx,
				VhdlExprParser::visitExpression(e));
	} else {
		return create_object<HdlStmReturn>(ctx);
	}
}

unique_ptr<iHdlStatement> VhdlStatementParser::visitLoop_statement(
		vhdlParser::Loop_statementContext *ctx) {
	// loop_statement:
	//           ( iteration_scheme )? LOOP
	//               sequence_of_statements
	//           END LOOP ( label )? SEMI
	// ;

	unique_ptr<iHdlStatement> loop;
	auto is = ctx->iteration_scheme();
	if (is) {
		// iteration_scheme
		// : WHILE condition
		// | FOR parameter_specification
		// ;
		if (ctx->iteration_scheme()->KW_WHILE()) {
			auto c = VhdlExprParser::visitCondition(is->condition());
			auto body = visitSequence_of_statements(
					ctx->sequence_of_statements());
			loop = create_object<HdlStmWhile>(ctx, move(c), move(body));
		} else {
			auto args = visitParameter_specification(
					is->parameter_specification());
			auto stms = visitSequence_of_statements(
					ctx->sequence_of_statements());
			loop = create_object<HdlStmForIn>(ctx, move(args.first),
					move(args.second), move(stms));
		}
	} else {
		loop = create_object<HdlStmWhile>(ctx, make_unique<HdlValueId>("True"),
				visitSequence_of_statements(ctx->sequence_of_statements()));
	}

	auto label = ctx->label();
	if (label) {
		loop->labels.push_back(VhdlLiteralParser::visitLabel(label));
	}
	return loop;
}

pair<unique_ptr<iHdlExprItem>, unique_ptr<iHdlExprItem>> VhdlStatementParser::visitParameter_specification(
		vhdlParser::Parameter_specificationContext *ctx) {
	//parameter_specification
	//  : identifier IN discrete_range
	//  ;
	auto i = VhdlLiteralParser::visitIdentifier(ctx->identifier());
	auto r = VhdlExprParser::visitDiscrete_range(ctx->discrete_range());
	return {move(i), move(r)};
}
unique_ptr<iHdlStatement> VhdlStatementParser::visitSelected_waveforms(
		vhdlParser::Selected_waveformsContext *ctx,
		unique_ptr<iHdlExprItem> sel, unique_ptr<iHdlExprItem> dst,
		bool is_blocking) {
	// selected_waveforms:
	//       ( waveform WHEN choices COMMA )*
	//       waveform WHEN choices
	// ;
	auto waveforms = ctx->waveform();
	auto choices_vec = ctx->choices();
	vector<HdlExprAndiHdlObj> cases;
	unique_ptr<iHdlStatement> default_ = nullptr;
	auto dst_tmp = dst.get();

	auto wf = waveforms.begin();
	for (auto _choices : choices_vec) {
		auto choices = VhdlExprParser::visitChoices(_choices);
		for (auto &c : choices) {
			auto wf_expr = VhdlExprParser::visitWaveform(*wf);
			if (cases.size()) {
				// use original dst only for first assignment and for later use unique instance
				// so dst instance is not shared between statements
				dst = dst_tmp->clone_uniq();
			}
			auto assig = create_object<HdlStmAssign>(_choices, move(dst),
					move(wf_expr), is_blocking);
			if (is_others(c)) {
				default_ = move(assig);
			} else {
				cases.push_back( { move(c), move(assig) });
			}
		}
		++wf;
	}

	return create_object<HdlStmCase>(ctx, move(sel), cases, move(default_));
}
unique_ptr<iHdlStatement> VhdlStatementParser::visitConcurrent_selected_signal_assignment(
		vhdlParser::Concurrent_selected_signal_assignmentContext *ctx) {
	// concurrent_selected_signal_assignment:
	//       WITH expression SELECT ( QUESTIONMARK )?
	//           target CONASGN ( GUARDED )? ( delay_mechanism )? selected_waveforms SEMI
	// ;

	// convert with select code construct to case statement

	if (ctx->QUESTIONMARK()) {
		NotImplementedLogger::print(
				"VhdlStatementParser.visitConcurrent_selected_signal_assignment - QUESTIONMARK",
				ctx);
	}
	if (ctx->KW_GUARDED()) {
		NotImplementedLogger::print(
				"VhdlStatementParser.visitConcurrent_selected_signal_assignment - GUARDED",
				ctx);
	}
	if (ctx->delay_mechanism()) {
		NotImplementedLogger::print(
				"VhdlStatementParser.visitConcurrent_selected_signal_assignment - delay_mechanism",
				ctx);
	}
	auto sel = VhdlExprParser::visitExpression(ctx->expression());
	auto dst = VhdlExprParser::visitTarget(ctx->target());
	auto case_stm = visitSelected_waveforms(ctx->selected_waveforms(),
			move(sel), move(dst), false);
	return case_stm;
}

unique_ptr<iHdlStatement> VhdlStatementParser::visitConcurrent_signal_assignment_statement(
		vhdlParser::Concurrent_signal_assignment_statementContext *ctx) {
	//concurrent_signal_assignment_statement:
	//      ( POSTPONED )? (
	//          concurrent_signal_assignment_any
	//	      | concurrent_selected_signal_assignment
	//      )
	//;

	if (ctx->KW_POSTPONED()) {
		NotImplementedLogger::print(
				"VhdlStatementParser.visitConcurrent_signal_assignment_statement - POSTPONED",
				ctx);
	}

	auto cssa = ctx->concurrent_selected_signal_assignment();
	if (cssa) {
		return visitConcurrent_selected_signal_assignment(cssa);
	}

	auto csaa = ctx->concurrent_signal_assignment_any();
	// concurrent_signal_assignment_any:
	// 	  target CONASGN ( GUARDED )? ( delay_mechanism )?
	//  	  ( waveform | conditional_waveforms ) SEMI
	// ;
	if (csaa->KW_GUARDED()) {
		NotImplementedLogger::print(
				"VhdlStatementParser.visitConcurrent_signal_assignment_statement - GUARDED",
				csaa);
	}
	if (csaa->delay_mechanism()) {
		NotImplementedLogger::print(
				"VhdlStatementParser.visitConcurrent_signal_assignment_statement - delay_mechanism",
				csaa);
	}

	auto t = csaa->target();
	auto dst = VhdlExprParser::visitTarget(t);
	auto wf = csaa->waveform();
	unique_ptr<iHdlExprItem> src = nullptr;
	if (wf) {
		src = VhdlExprParser::visitWaveform(wf);
	} else {
		auto cwf = csaa->conditional_waveforms();
		assert(cwf);
		src = VhdlExprParser::visitConditional_waveforms(cwf);
	}
	return create_object<HdlStmAssign>(t, move(dst), move(src), false);
}

unique_ptr<iHdlStatement> VhdlStatementParser::visitConcurrent_statement_with_optional_label(
		vhdlParser::Concurrent_statement_with_optional_labelContext *ctx) {
	// concurrent_statement_with_optional_label:
	//       process_statement
	//       | concurrent_procedure_call_statement
	//       | concurrent_assertion_statement
	//       | concurrent_signal_assignment_statement;

	auto p = ctx->process_statement();
	if (p) {
		VhdlProcessParser pp(commentParser, hierarchyOnly);
		return pp.visitProcess_statement(p);
	}
	auto cpc = ctx->concurrent_procedure_call_statement();
	if (cpc) {
		NotImplementedLogger::print(
				"VhdlStatementParser.visitConcurrent_procedure_call_statement", cpc);
		return nullptr;
	}
	auto ca = ctx->concurrent_assertion_statement();
	if (ca) {
		VhdlStatementParser sp(commentParser, hierarchyOnly);
		return sp.visitConcurrent_assertion_statement(ca);
	}
	auto csa = ctx->concurrent_signal_assignment_statement();
	assert(csa);
	return visitConcurrent_signal_assignment_statement(csa);
}

void VhdlStatementParser::visitConcurrent_statement(
		vhdlParser::Concurrent_statementContext *ctx,
		vector<unique_ptr<iHdlObj>> &stms) {
	// concurrent_statement:
	//       label COLON (block_statement
	//                    | component_instantiation_statement
	//                    | generate_statement
	//                    | concurrent_statement_with_optional_label)
	//       | concurrent_statement_with_optional_label
	//       ;
	auto _label = ctx->label();
	if (_label) {
		auto label = VhdlLiteralParser::visitLabel(_label);
		auto b = ctx->block_statement();
		if (b) {
			NotImplementedLogger::print("VhdlStatementParser.visitBlock_statement",
					b);
			return;
		}
		auto ci = ctx->component_instantiation_statement();
		if (ci) {
			auto _ci =
					VhdlCompInstParser::visitComponent_instantiation_statement(
							ci, label);
			stms.push_back(move(_ci));
			return;
		}

		auto gs = ctx->generate_statement();
		if (gs) {
			VhdlGenerateStatementParser gsp(commentParser, hierarchyOnly);
			auto _gs = gsp.visitGenerate_statement(gs);
			_gs->labels.insert(_gs->labels.begin(), label);
			stms.push_back(move(_gs));
			return;
		}
		auto cs = ctx->concurrent_statement_with_optional_label();
		assert(cs);
		auto _cs = visitConcurrent_statement_with_optional_label(cs);
		if (_cs) {
			_cs->labels.insert(_cs->labels.begin(), label);
			stms.push_back(move(_cs));
		}
	} else {
		auto cs = ctx->concurrent_statement_with_optional_label();
		auto _cs = visitConcurrent_statement_with_optional_label(cs);
		if (_cs)
			stms.push_back(move(_cs));
	}
}

}
}
