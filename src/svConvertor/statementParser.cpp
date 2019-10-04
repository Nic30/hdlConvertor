#include <hdlConvertor/svConvertor/statementParser.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/hdlObjects/hdlDirection.h>
#include <hdlConvertor/svConvertor/exprParser.h>
#include <hdlConvertor/svConvertor/typeParser.h>
#include <hdlConvertor/svConvertor/attributeParser.h>
#include <hdlConvertor/svConvertor/exprPrimaryParser.h>
#include <hdlConvertor/svConvertor/eventExprParser.h>
#include <hdlConvertor/svConvertor/delayParser.h>
#include <hdlConvertor/svConvertor/declrParser.h>
#include <hdlConvertor/svConvertor/paramDefParser.h>
#include <hdlConvertor/svConvertor/literalParser.h>

namespace hdlConvertor {
namespace sv {

using namespace std;
using sv2017Parser = sv2017_antlr::sv2017Parser;
using namespace hdlConvertor::hdlObjects;

VerStatementParser::VerStatementParser(SVCommentParser &commentParser) :
		commentParser(commentParser) {
}
iHdlStatement* VerStatementParser::visitAlways_construct(
		sv2017Parser::Always_constructContext *ctx) {
	// always_construct:
	//     always_keyword statement;
	//
	if (!ctx->always_keyword()->KW_ALWAYS()) {
		NotImplementedLogger::print(
				"VerStatementParser.visitAlways_construct.always_keyword - non pure always",
				ctx->always_keyword());
	}
	auto stm = ctx->statement();
	return visitStatement(stm);
}

iHdlStatement* VerStatementParser::visitSubroutine_call_statement(
		sv2017Parser::Subroutine_call_statementContext *ctx) {
	// subroutine_call_statement:
	//     ( KW_VOID APOSTROPHE LPAREN expression RPAREN ) SEMI;
	auto _e = ctx->expression();
	auto e0 = VerExprParser(commentParser).visitExpression(_e);
	auto e1 = new iHdlExpr(iHdlExpr::ID("void"), HdlOperatorType::CALL, e0);
	return iHdlStatement::EXPR(e1);
}

iHdlStatement* VerStatementParser::visitJumpStatement(
		sv2017Parser::Jump_statementContext *ctx) {
	// jump_statement:
	//     ( KW_RETURN ( expression )?
	//       | KW_BREAK
	//       | KW_CONTINUE
	//     ) SEMI;
	if (ctx->KW_RETURN()) {
		auto _e = ctx->expression();
		if (_e) {
			auto e = VerExprParser(commentParser).visitExpression(_e);
			return iHdlStatement::RETURN(e);
		} else {
			return iHdlStatement::RETURN();
		}
	} else if (ctx->KW_BREAK()) {
		return iHdlStatement::BREAK();
	} else {
		assert(ctx->KW_CONTINUE());
		return iHdlStatement::CONTINUE();
	}
}
iHdlStatement* VerStatementParser::visitStatement_item(
		sv2017Parser::Statement_itemContext *ctx) {
	// statement_item:
	//   ( blocking_assignment
	//     | nonblocking_assignment
	//     | procedural_continuous_assignment
	//     | inc_or_dec_expression
	//     | primary
	//     | clocking_drive
	//   ) SEMI
	//   | case_statement
	//   | conditional_statement
	//   | subroutine_call_statement
	//   | disable_statement
	//   | event_trigger
	//   | loop_statement
	//   | jump_statement
	//   | par_block
	//   | procedural_timing_control_statement
	//   | seq_block
	//   | wait_statement
	//   | procedural_assertion_statement
	//   | randsequence_statement
	//   | randcase_statement
	//   | expect_property_statement
	// ;

	auto ba = ctx->blocking_assignment();
	if (ba) {
		return visitBlocking_assignment(ba);
	}
	auto nba = ctx->nonblocking_assignment();
	if (nba) {
		return visitNonblocking_assignment(nba);
	}
	auto pca = ctx->procedural_continuous_assignment();
	if (pca) {
		NotImplementedLogger::print(
				"VerStatementParser.visitStatement_item.procedural_continuous_assignment",
				pca);
		return iHdlStatement::NOP();
	}
	auto ide = ctx->inc_or_dec_expression();
	if (ide) {
		auto e = VerExprParser(commentParser).visitInc_or_dec_expression(ide);
		return iHdlStatement::EXPR(e);
	}
	auto p = ctx->primary();
	if (p) {
		auto e = VerExprPrimaryParser(commentParser).visitPrimary(p);
		return iHdlStatement::EXPR(e);
	}
	auto cd = ctx->clocking_drive();
	if (cd) {
		NotImplementedLogger::print(
				"VerStatementParser.visitStatement_item.clocking_drive", cd);
		return iHdlStatement::NOP();
	}
	auto cs = ctx->case_statement();
	if (cs) {
		return visitCase_statement(cs);
	}
	auto conds = ctx->conditional_statement();
	if (conds) {
		return visitConditional_statement(conds);
	}
	auto scs = ctx->subroutine_call_statement();
	if (scs) {
		return visitSubroutine_call_statement(scs);
	}
	auto d = ctx->disable_statement();
	if (d) {
		NotImplementedLogger::print(
				"VerStatementParser.visitStatement_item.disable_statement", d);
		return iHdlStatement::NOP();
	}
	auto et = ctx->event_trigger();
	if (et) {
		// auto _et = VerExprParser::visitEvent_trigger(et);
		NotImplementedLogger::print(
				"VerStatementParser.visitStatement_item.event_trigger", et);
		return iHdlStatement::NOP();
	}
	auto ls = ctx->loop_statement();
	if (ls) {
		return visitLoop_statement(ls);
	}
	auto js = ctx->jump_statement();
	if (js) {
		return visitJumpStatement(js);
	}
	auto pb = ctx->par_block();
	if (pb) {
		NotImplementedLogger::print(
				"VerStatementParser.visitStatement_item.par_block", pb);
		return iHdlStatement::NOP();
	}
	auto ptcs = ctx->procedural_timing_control_statement();
	if (ptcs) {
		return visitProcedural_timing_control_statement(ptcs);
	}
	auto sb = ctx->seq_block();
	if (sb) {
		return visitSeq_block(sb);
	}
	auto ws = ctx->wait_statement();
	if (ws) {
		NotImplementedLogger::print(
				"VerStatementParser.visitStatement_item.wait_statement", ws);
		return iHdlStatement::NOP();
	}
	auto pas = ctx->procedural_assertion_statement();
	if (pas) {
		NotImplementedLogger::print(
				"VerStatementParser.visitStatement_item.procedural_assertion_statement",
				pas);
		return iHdlStatement::NOP();
	}
	auto rss = ctx->randsequence_statement();
	if (rss) {
		NotImplementedLogger::print(
				"VerStatementParser.visitStatement_item.procedural_assertion_statement",
				rss);
		return iHdlStatement::NOP();
	}
	auto rcs = ctx->randcase_statement();
	if (rcs) {
		NotImplementedLogger::print(
				"VerStatementParser.visitStatement_item.randcase_statement",
				rcs);
		return iHdlStatement::NOP();
	}
	auto eps = ctx->expect_property_statement();
	assert(eps);
	NotImplementedLogger::print(
			"VerStatementParser.visitStatement_item.expect_property_statement",
			pas);
	return iHdlStatement::NOP();
}

hdlObjects::iHdlStatement* VerStatementParser::visitStatement(
		sv2017Parser::StatementContext *ctx) {
	// statement: ( identifier COLON )? ( attribute_instance )* statement_item;

	auto ai = ctx->attribute_instance();
	VerAttributeParser::visitAttribute_instance(ai);
	auto _stm = ctx->statement_item();
	auto stm = visitStatement_item(_stm);
	auto _label = ctx->identifier();
	if (_label) {
		auto label = _label->getText();
		stm->labels.insert(stm->labels.begin(), label);
	}
	return stm;
}

iHdlStatement* VerStatementParser::visitBlocking_assignment(
		sv2017Parser::Blocking_assignmentContext *ctx) {
	// blocking_assignment:
	//     variable_lvalue ASSIGN ( delay_or_event_control expression | dynamic_array_new )
	//     | package_or_class_scoped_hier_id_with_select ASSIGN class_new
	//     | operator_assignment
	// ;
	VerExprParser ep(commentParser);
	auto vlv = ctx->variable_lvalue();
	iHdlStatement *assig = nullptr;
	if (vlv) {
		auto dst = ep.visitVariable_lvalue(vlv);
		auto e = ctx->expression();
		if (e) {
			auto src = ep.visitExpression(e);
			auto dec = ctx->delay_or_event_control();
			auto d = VerDelayParser(commentParser).visitDelay_or_event_control(
					dec);
			assig = new HdlStmAssign(dst, src, d.first, d.second, true);
		} else {
			auto dan = ctx->dynamic_array_new();
			assert(dan);
			NotImplementedLogger::print(
					"VerStatementParser.visitBlocking_assignment.dynamic_array_new",
					dan);
			assig = iHdlStatement::NOP();
			//assig = new HdlStmAssign(dst, src, true);
		}
	} else {
		auto cn = ctx->class_new();
		if (cn) {
			NotImplementedLogger::print(
					"VerStatementParser.visitBlocking_assignment.class_new",
					cn);
			assig = iHdlStatement::NOP();
		} else {
			auto oa = ctx->operator_assignment();
			assert(oa);
			NotImplementedLogger::print(
					"VerStatementParser.visitBlocking_assignment.operator_assignment",
					oa);
			assig = iHdlStatement::NOP();
		}
	}
	assig->__doc__ = commentParser.parse(ctx);
	return assig;
}

iHdlStatement* VerStatementParser::visitCase_statement(
		sv2017Parser::Case_statementContext *ctx) {
	// case_statement:
	//     ( unique_priority )?
	//     ( KW_CASE LPAREN expression RPAREN KW_INSIDE ( case_inside_item )+
	//       | case_keyword LPAREN expression RPAREN
	//         ( KW_MATCHES ( case_pattern_item )+
	//           | ( case_item )+
	//         )
	//     ) KW_ENDCASE;
	// case_keyword:
	//     KW_CASE
	//     | KW_CASEZ
	//     | KW_CASEX
	// ;
	if (ctx->unique_priority()) {
		NotImplementedLogger::print(
				"VerStatementParser.visitCase_statement.unique_priority", ctx);
	}
	auto switchOn = VerExprParser(commentParser).visitExpression(
			ctx->expression());
	std::vector<iHdlStatement::case_t> cases;
	vector<iHdlObj*> *default_ = nullptr;
	if (ctx->KW_INSIDE()) {
		NotImplementedLogger::print(
				"VerStatementParser.visitCase_statement.inside", ctx);

	} else {
		auto ck = ctx->case_keyword();
		assert(ck);
		if (ck->KW_CASE()) {
			auto _cases = ctx->case_item();
			cases.reserve(_cases.size());
			for (auto _c : _cases) {
				auto cs = visitCase_item(_c);
				for (auto c : cs) {
					if (c.first) {
						cases.push_back(c);
					} else {
						if (default_) {
							delete switchOn;
							delete c.second;
							for (auto ca: cases) {
								delete ca.first;
								for (auto s: *ca.second)
									delete s;
								delete ca.second;
							}
							delete default_;
							throw std::runtime_error("VerStatementParser.visitCase_statement case with multiple default");
						}
						default_ = c.second;
					}
				}
			}
		} else if (ck->KW_CASEX()) {
			NotImplementedLogger::print(
					"VerStatementParser.visitCase_statement.casex", ctx);
		} else {
			assert(ck->KW_CASEZ());
			NotImplementedLogger::print(
					"VerStatementParser.visitCase_statement.casez", ctx);
		}
	}
	auto cs = iHdlStatement::CASE(switchOn, cases, default_);
	cs->__doc__ = commentParser.parse(ctx);
	return cs;

}
std::vector<iHdlStatement::case_t> VerStatementParser::visitCase_item(
		sv2017Parser::Case_itemContext *ctx) {
	// case_item
	//    : expression (',' expression)* ':' statement_or_null
	//    | 'default' (':')? statement_or_null
	//    ;
	std::vector<iHdlStatement::case_t> res;
	auto conds = ctx->expression();
	auto stms = ctx->statement_or_null();
	if (conds.size()) {
		for (auto c : conds) {
			auto ce = VerExprParser(commentParser).visitExpression(c);
			// [TODO] it would be better to copy the statements instead of parsing again
			auto _stms =
					reinterpret_cast<vector<iHdlObj*>*>(visitStatement_or_null__as_block(
							stms));
			res.push_back( { ce, _stms });
		}
	} else {
		auto _stms =
				reinterpret_cast<vector<iHdlObj*>*>(visitStatement_or_null__as_block(
						stms));
		res.push_back( { nullptr, _stms });
	}
	return res;
}

HdlStmAssign* VerStatementParser::visitVariable_assignment(
		sv2017Parser::Variable_assignmentContext *ctx) {
	// variable_assignment:
	//     variable_lvalue ASSIGN expression;
	VerExprParser ep(commentParser);
	auto _dst = ctx->variable_lvalue();
	auto dst = ep.visitVariable_lvalue(_dst);
	auto _src = ctx->expression();
	auto src = ep.visitExpression(_src);
	return new HdlStmAssign(dst, src, true);
}

iHdlStatement* VerStatementParser::visitLoop_statement(
		sv2017Parser::Loop_statementContext *ctx) {
	// loop_statement:
	//  ( KW_FOREVER
	//       | ( ( KW_REPEAT
	//               | KW_WHILE
	//               ) LPAREN expression
	//           | KW_FOR LPAREN ( for_initialization )? SEMI ( expression )? SEMI ( for_step )?
	//           ) RPAREN
	//       ) statement_or_null
	//   | KW_DO statement_or_null KW_WHILE LPAREN expression RPAREN SEMI
	//   | KW_FOREACH LPAREN package_or_class_scoped_hier_id_with_select LSQUARE_BR loop_variables
	//   RSQUARE_BR RPAREN statement
	// ;
	vector<iHdlStatement*> *stm;
	auto _stm = ctx->statement();
	if (_stm)
		stm = visitStatement__as_block(_stm);
	else {
		auto sn = ctx->statement_or_null();
		assert(sn);
		stm = visitStatement_or_null__as_block(sn);
	}
	VerExprParser ep(commentParser);
	if (ctx->KW_FOREVER()) {
		return iHdlStatement::WHILE(iHdlExpr::INT(1), stm);

	} else if (ctx->KW_REPEAT()) {
		NotImplementedLogger::print(
				"VerStatementParser.visitLoop_statement.repeat", ctx);
		return iHdlStatement::NOP();

	} else if (ctx->KW_WHILE()) {
		auto _e = ctx->expression();
		auto c = ep.visitExpression(_e);
		return iHdlStatement::WHILE(c, stm);

	} else if (ctx->KW_WHILE()) {
		auto _e = ctx->expression();
		auto c = ep.visitExpression(_e);
		return iHdlStatement::DO_WHILE(c, stm);

	} else if (ctx->KW_FOR()) {
		auto _init = ctx->for_initialization();
		auto _cond = ctx->expression();
		auto _step = ctx->for_step();

		auto init = new vector<iHdlStatement*>();
		if (_init)
			visitFor_initialization(_init, *init);
		iHdlExpr *cond = nullptr;
		if (_cond)
			cond = ep.visitExpression(_cond);
		else
			cond = iHdlExpr::INT(1);

		auto step = new vector<iHdlStatement*>();
		if (_step)
			visitFor_step(_step, *step);
		return iHdlStatement::FOR(init, cond, step, stm);

	} else {
		assert(ctx->KW_FOREACH());
		// KW_FOREACH LPAREN package_or_class_scoped_hier_id_with_select
		//                   LSQUARE_BR loop_variables RSQUARE_BR RPAREN statement
		auto _collecton = ctx->package_or_class_scoped_hier_id_with_select();
		auto collecton = ep.visitPackage_or_class_scoped_hier_id_with_select(
				_collecton);
		auto _vars = ctx->loop_variables();
		auto vars = visitLoop_variables(_vars);
		auto fi = iHdlStatement::FOR_IN(*vars, collecton,
				reinterpret_cast<std::vector<iHdlObj*>*>(stm));
		delete vars;
		return fi;
	}
}

void VerStatementParser::visitFor_variable_declaration(
		sv2017Parser::For_variable_declarationContext *ctx,
		vector<HdlVariableDef*> &res) {
	// for_variable_declaration:
	//     ( KW_VAR )? data_type for_variable_declaration_var_assign
	//     ( COMMA for_variable_declaration_var_assign )*
	// ;
	auto _dt = ctx->data_type();
	VerTypeParser tp(commentParser);
	VerExprParser ep(commentParser);

	auto dt = tp.visitData_type(_dt);
	bool is_latched = ctx->KW_VAR() != nullptr;
	bool first = true;
	for (auto _fvdas : ctx->for_variable_declaration_var_assign()) {
		// for_variable_declaration_var_assign: identifier ASSIGN expression;
		auto name = ep.getIdentifierStr(_fvdas->identifier());
		if (first)
			first = false;
		else
			dt = new iHdlExpr(*dt);
		auto _def_val = _fvdas->expression();
		auto def_val = ep.visitExpression(_def_val);
		auto vd = new HdlVariableDef(name, dt, def_val,
				HdlDirection::DIR_INTERNAL, is_latched);
		res.push_back(vd);
	}
}

void VerStatementParser::visitFor_initialization(
		sv2017Parser::For_initializationContext *ctx,
		vector<iHdlStatement*> &res) {
	// for_initialization:
	//     list_of_variable_assignments
	//     | for_variable_declaration ( COMMA for_variable_declaration )*
	// ;
	auto lva = ctx->list_of_variable_assignments();
	if (lva) {
		// list_of_variable_assignments: variable_assignment ( COMMA variable_assignment )*;
		for (auto _va : lva->variable_assignment()) {
			auto va = visitVariable_assignment(_va);
			res.push_back(va);
		}
	} else {
		auto fvds = ctx->for_variable_declaration();
		assert(fvds.size());
		for (auto _fvd : fvds) {
			visitFor_variable_declaration(_fvd,
					*reinterpret_cast<vector<HdlVariableDef*>*>(&res));
		}
	}

}
void VerStatementParser::visitFor_step(sv2017Parser::For_stepContext *ctx,
		std::vector<hdlObjects::iHdlStatement*> &res) {
	// for_step: sequence_match_item ( COMMA sequence_match_item )*;
	VerExprParser ep(commentParser);
	for (auto _smi : ctx->sequence_match_item()) {
		auto smi = visitSequence_match_item(_smi);
		res.push_back(smi);
	}
}

vector<iHdlExpr*>* VerStatementParser::visitLoop_variables(
		sv2017Parser::Loop_variablesContext *ctx) {
	auto vars = new vector<iHdlExpr*>();
	// loop_variables: ( identifier )? ( COMMA ( identifier )? )*;
	VerExprParser ep(commentParser);
	for (auto _id : ctx->identifier()) {
		auto id = ep.visitIdentifier(_id);
		vars->push_back(id);
	}
	return vars;
}
HdlStmAssign* VerStatementParser::visitNonblocking_assignment(
		sv2017Parser::Nonblocking_assignmentContext *ctx) {
	// nonblocking_assignment
	//    : variable_lvalue '<=' (delay_or_event_control)? expression
	//    ;
	auto vl = ctx->variable_lvalue();
	VerExprParser ep(commentParser);
	auto dst = ep.visitVariable_lvalue(vl);
	auto e = ctx->expression();
	auto src = ep.visitExpression(e);
	HdlStmAssign *a;
	auto dec = ctx->delay_or_event_control();
	if (dec) {
		auto d = VerDelayParser(commentParser).visitDelay_or_event_control(dec);
		a = new HdlStmAssign(dst, src, d.first, d.second, false);
	} else {
		a = new HdlStmAssign(dst, src, false);
	}
	a->__doc__ = commentParser.parse(ctx);
	return a;
}

HdlStmBlock* VerStatementParser::visitSeq_block(
		sv2017Parser::Seq_blockContext *ctx) {
	// seq_block:
	//     KW_BEGIN ( COLON identifier | {_input->LA(1) != COLON}? )
	//         ( block_item_declaration )* ( statement_or_null )*
	//     KW_END (COLON identifier |  {_input->LA(1) != COLON}?);
	auto _label = ctx->identifier(0);
	vector<iHdlObj*> items;
	for (auto bid : ctx->block_item_declaration()) {
		visitBlock_item_declaration(bid, items);
	}
	for (auto stm : ctx->statement_or_null()) {
		auto i = visitStatement_or_null(stm);
		items.push_back(reinterpret_cast<iHdlObj*>(i));
	}
	auto b = new HdlStmBlock(items);
	if (_label) {
		VerExprParser ep(commentParser);
		b->labels.push_back(ep.getIdentifierStr(_label));
	}
	return b;
}

void VerStatementParser::visitBlock_item_declaration(
		sv2017Parser::Block_item_declarationContext *ctx,
		std::vector<hdlObjects::iHdlObj*> &res) {
	// block_item_declaration:
	//     ( attribute_instance )* (
	//         data_declaration
	//         | ( local_parameter_declaration
	//             | parameter_declaration
	//             ) SEMI
	//         | let_declaration
	//     )
	// ;
	VerAttributeParser::visitAttribute_instance(ctx->attribute_instance());
	auto dd = ctx->data_declaration();
	if (dd) {
		VerDeclrParser dp(commentParser);
		dp.visitData_declaration(dd, res);
		return;
	}
	VerParamDefParser pdp(commentParser);
	auto &res_var = *reinterpret_cast<vector<HdlVariableDef*>*>(&res);
	auto lpd = ctx->local_parameter_declaration();
	if (lpd) {
		pdp.visitLocal_parameter_declaration(lpd, res_var);
		return;
	}
	auto pd = ctx->parameter_declaration();
	if (pd) {
		pdp.visitParameter_declaration(pd, res_var);
		return;
	}
	auto ld = ctx->let_declaration();
	assert(ld);
	NotImplementedLogger::print(
			"VerStatementParser.visitBlock_item_declarartion.let_declaration",
			ld);
}

iHdlStatement* VerStatementParser::visitConditional_statement(
		sv2017Parser::Conditional_statementContext *ctx) {
	//conditional_statement:
	//    ( unique_priority )? KW_IF LPAREN cond_predicate RPAREN statement_or_null
	//    ( KW_ELSE statement_or_null | {_input->LA(1) != KW_ELSE}? );
	auto c = ctx->cond_predicate();
	auto s = ctx->statement_or_null();
	VerExprParser ep(commentParser);
	auto cond = ep.visitCond_predicate(c);

	auto ifTrue = visitStatement_or_null__as_block(s[0]);
	vector<iHdlStatement*> *ifFalse = nullptr;
	if (s.size() == 2) {
		ifFalse = visitStatement_or_null__as_block(s[1]);
	}
	auto ifStm = iHdlStatement::IF(cond,
			reinterpret_cast<vector<iHdlObj*>*>(ifTrue),
			reinterpret_cast<vector<iHdlObj*>*>(ifFalse));
	ifStm->position.update_from_elem(ctx);
	ifStm->__doc__ = commentParser.parse(ctx);
	return ifStm;
}

HdlStmProcess* VerStatementParser::visitProcedural_timing_control_statement(
		sv2017Parser::Procedural_timing_control_statementContext *ctx) {
	// procedural_timing_control_statement: procedural_timing_control statement_or_null;

	auto ptc = ctx->procedural_timing_control();
	auto sens_list =
			VerDelayParser(commentParser).visitProcedural_timing_control(ptc);
	auto stms =
			reinterpret_cast<std::vector<iHdlObj*>*>(visitStatement_or_null__as_block(
					ctx->statement_or_null()));
	HdlStmProcess *p;
	if (sens_list.second) {
		assert(sens_list.first == nullptr && "no event and delay at once");
		p = new HdlStmProcess(sens_list.second, stms);
	} else if (sens_list.first) {
		auto wait = iHdlStatement::WAIT( { sens_list.first, });
		// push_front
		stms->push_back(wait);
		std::rotate(stms->rbegin(), stms->rbegin() + 1, stms->rend());

		p = new HdlStmProcess(nullptr, stms);
	} else {
		p = new HdlStmProcess(nullptr, stms);
	}
	p->__doc__ = commentParser.parse(ctx);
	return p;
}
vector<iHdlStatement*>* VerStatementParser::visitStatement__as_block(
		sv2017Parser::StatementContext *ctx) {
	auto stm = visitStatement(ctx);
	auto res = new vector<iHdlStatement*>();
	auto block = dynamic_cast<HdlStmBlock*>(stm);
	if (block && block->labels.size() == 0) {
		if (block->statements.size())
			res->reserve(block->statements.size());
		for (auto i : block->statements) {
			res->push_back(reinterpret_cast<iHdlStatement*>(i));
		}
		block->statements.clear();
		delete block;
	} else {
		res->push_back(stm);
	}

	return res;
}

vector<iHdlStatement*>* VerStatementParser::visitStatement_or_null__as_block(
		sv2017Parser::Statement_or_nullContext *ctx) {
	// statement_or_null:
	//     statement
	//     | ( attribute_instance )* SEMI
	// ;
	if (ctx == nullptr)
		return nullptr;
	auto stm = ctx->statement();
	if (stm) {
		return visitStatement__as_block(stm);
	}
	return new vector<iHdlStatement*>();

}
iHdlStatement* VerStatementParser::visitStatement_or_null(
		sv2017Parser::Statement_or_nullContext *ctx) {
	// statement_or_null:
	//     statement
	//     | ( attribute_instance )* SEMI
	// ;
	auto s = ctx->statement();
	if (s) {
		return visitStatement(s);
	} else {
		VerAttributeParser::visitAttribute_instance(ctx->attribute_instance());
		return iHdlStatement::NOP();
	}
}

void VerStatementParser::visitContinuous_assign(
		sv2017Parser::Continuous_assignContext *ctx,
		vector<iHdlStatement*> &res) {
	// continuous_assign:
	//  KW_ASSIGN ( ( drive_strength )? ( delay3 )? list_of_variable_assignments
	//               | delay_control list_of_variable_assignments
	//               ) SEMI;
	auto ds = ctx->drive_strength();
	if (ds) {
		NotImplementedLogger::print(
				"VerStatementParser.vistContinuous_assign.drive_strength", ds);
	}
	auto del = ctx->delay3();
	if (del) {
		NotImplementedLogger::print(
				"VerStatementParser.vistContinuous_assign.delay3", del);
	}
	auto dc = ctx->delay_control();
	if (dc) {
		NotImplementedLogger::print(
				"VerStatementParser.vistContinuous_assign.delay_control", dc);
	}
	auto lva = ctx->list_of_variable_assignments();
	// list_of_variable_assignments: variable_assignment ( COMMA variable_assignment )*;
	bool first = true;
	for (auto _va : lva->variable_assignment()) {
		auto va = visitVariable_assignment(_va);
		if (first) {
			va->__doc__ = commentParser.parse(ctx) + va->__doc__;
			first = false;
		}
		va->is_blocking = false;
		res.push_back(va);
	}
}

HdlStmProcess* VerStatementParser::visitInitial_construct(
		sv2017Parser::Initial_constructContext *ctx) {
	// initial_construct: KW_INITIAL statement_or_null;
	auto _stm = ctx->statement_or_null();
	vector<iHdlStatement*> *body = visitStatement_or_null__as_block(_stm);
	return new HdlStmProcess(nullptr, reinterpret_cast<vector<iHdlObj*>*>(body));
}

iHdlStatement* VerStatementParser::visitSequence_match_item(
		sv2017Parser::Sequence_match_itemContext *ctx) {
	// sequence_match_item:
	//     operator_assignment
	//     | expression
	// ;
	auto oa = ctx->operator_assignment();
	if (oa) {
		NotImplementedLogger::print(
				"VerExprParser.visitSequence_match_item.operator_assignment",
				ctx);
		return iHdlStatement::NOP();
	}
	auto _e = ctx->expression();
	assert(_e);
	auto e = VerExprParser(commentParser).visitExpression(_e);
	return iHdlStatement::EXPR(e);
}

hdlObjects::iHdlStatement* VerStatementParser::visitElaboration_system_task(
		sv2017Parser::Elaboration_system_taskContext *ctx) {
	// elaboration_system_task:
	//     ( KW_DOLAR_FATAL ( LPAREN UNSIGNED_NUMBER ( COMMA ( list_of_arguments )? )? RPAREN )?
	//      | ( KW_DOLAR_ERROR
	//          | KW_DOLAR_WARNING
	//          | KW_DOLAR_INFO
	//          ) ( LPAREN ( list_of_arguments )? RPAREN )?
	//     ) SEMI
	// ;
	string name;
	if (ctx->KW_DOLAR_FATAL()) {
		name = "$fatal";
	} else if (ctx->KW_DOLAR_ERROR()) {
		name = "$error";
	} else if (ctx->KW_DOLAR_WARNING()) {
		name = "$warning";
	} else {
		assert(ctx->KW_DOLAR_INFO());
		name = "$info";
	}
	std::vector<iHdlExpr*> args;
	auto un = ctx->UNSIGNED_NUMBER();
	if (un) {
		args.push_back(VerLiteralParser::visitUNSIGNED_NUMBER(un));
	}
	auto la = ctx->list_of_arguments();
	if (la)
		VerExprParser(commentParser).visitList_of_arguments(la, args);

	auto e = iHdlExpr::call(iHdlExpr::ID(name), args);
	return iHdlStatement::EXPR(e);
}

}
}
