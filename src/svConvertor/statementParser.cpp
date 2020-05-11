#include <hdlConvertor/svConvertor/statementParser.h>
#include <hdlConvertor/hdlAst/hdlStmCase.h>
#include <hdlConvertor/hdlAst/hdlStmExpr.h>
#include <hdlConvertor/hdlAst/hdlStmIf.h>
#include <hdlConvertor/hdlAst/hdlStmFor.h>
#include <hdlConvertor/hdlAst/hdlStmWhile.h>
#include <hdlConvertor/hdlAst/hdlStm_others.h>
#include <hdlConvertor/hdlAst/hdlDirection.h>

#include <hdlConvertor/createObject.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/svConvertor/exprParser.h>
#include <hdlConvertor/svConvertor/typeParser.h>
#include <hdlConvertor/svConvertor/attributeParser.h>
#include <hdlConvertor/svConvertor/exprPrimaryParser.h>
#include <hdlConvertor/svConvertor/eventExprParser.h>
#include <hdlConvertor/svConvertor/delayParser.h>
#include <hdlConvertor/svConvertor/declrParser.h>
#include <hdlConvertor/svConvertor/paramDefParser.h>
#include <hdlConvertor/svConvertor/literalParser.h>

using namespace std;
using sv2017Parser = sv2017_antlr::sv2017Parser;
using namespace hdlConvertor::hdlAst;

namespace hdlConvertor {
namespace sv {

void HdlStmIf_collapse_elifs(HdlStmIf &ifStm) {
	if (ifStm.ifFalse) {
		auto as_if = dynamic_cast<HdlStmIf*>(ifStm.ifFalse.get());
		if (as_if) {
			assert(ifStm.in_preproc == as_if->in_preproc);
			auto tmp = move(ifStm.ifFalse);
			// add if-then branch as if else
			auto c = move(as_if->cond);
			auto s = move(as_if->ifTrue);
			ifStm.elseIfs.push_back(HdlExprAndiHdlObj(move(c), move(s)));

			for (auto &elif : as_if->elseIfs) {
				ifStm.elseIfs.push_back(move(elif));
			}

			ifStm.ifFalse = move(as_if->ifFalse);
			// [todo] labels (if there was label for else, merge it with first label if there was any)
			//for (auto & l: as_if->labels) {
			//
			//}
			if (as_if->__doc__.size()) {
				if (ifStm.__doc__.size()) {
					ifStm.__doc__ += "\n";
				}
				ifStm.__doc__ += as_if->__doc__;
			}
		}
	}

}

VerStatementParser::VerStatementParser(SVCommentParser &commentParser) :
		commentParser(commentParser) {
}

unique_ptr<iHdlStatement> VerStatementParser::visitAlways_construct(
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

unique_ptr<iHdlStatement> VerStatementParser::visitSubroutine_call_statement(
		sv2017Parser::Subroutine_call_statementContext *ctx) {
	// subroutine_call_statement:
	//     ( KW_VOID APOSTROPHE LPAREN expression RPAREN ) SEMI;
	auto _e = ctx->expression();
	auto e0 = VerExprParser(commentParser).visitExpression(_e);
	auto e1 = create_object<HdlOp>(_e,
			create_object<HdlValueId>(ctx->KW_VOID(), "void"), HdlOpType::CALL,
			move(e0));
	return create_object_with_doc<HdlStmExpr>(ctx, commentParser, move(e1));
}

unique_ptr<iHdlStatement> VerStatementParser::visitJumpStatement(
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
			return create_object_with_doc<HdlStmReturn>(ctx, commentParser,
					move(e));
		} else {
			return create_object_with_doc<HdlStmReturn>(ctx, commentParser);
		}
	} else if (ctx->KW_BREAK()) {
		return create_object_with_doc<HdlStmBreak>(ctx, commentParser);
	} else {
		assert(ctx->KW_CONTINUE());
		return create_object_with_doc<HdlStmContinue>(ctx, commentParser);
	}
}

unique_ptr<iHdlStatement> VerStatementParser::visitStatement_item(
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
		return create_object_with_doc<HdlStmNop>(ctx, commentParser);
	}
	auto ide = ctx->inc_or_dec_expression();
	if (ide) {
		auto e = VerExprParser(commentParser).visitInc_or_dec_expression(ide);
		return create_object_with_doc<HdlStmExpr>(ctx, commentParser, move(e));
	}
	auto p = ctx->primary();
	if (p) {
		auto e = VerExprPrimaryParser(commentParser).visitPrimary(p);
		return create_object_with_doc<HdlStmExpr>(ctx, commentParser, move(e));
	}
	auto cd = ctx->clocking_drive();
	if (cd) {
		NotImplementedLogger::print(
				"VerStatementParser.visitStatement_item.clocking_drive", cd);
		return create_object_with_doc<HdlStmNop>(ctx, commentParser);
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
		return create_object_with_doc<HdlStmNop>(ctx, commentParser);
	}
	auto et = ctx->event_trigger();
	if (et) {
		// auto _et = VerExprParser::visitEvent_trigger(et);
		NotImplementedLogger::print(
				"VerStatementParser.visitStatement_item.event_trigger", et);
		return create_object_with_doc<HdlStmNop>(ctx, commentParser);
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
		return visitPar_block(pb);
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
		return create_object_with_doc<HdlStmNop>(ctx, commentParser);
	}
	auto pas = ctx->procedural_assertion_statement();
	if (pas) {
		NotImplementedLogger::print(
				"VerStatementParser.visitStatement_item.procedural_assertion_statement",
				pas);
		return create_object_with_doc<HdlStmNop>(ctx, commentParser);
	}
	auto rss = ctx->randsequence_statement();
	if (rss) {
		NotImplementedLogger::print(
				"VerStatementParser.visitStatement_item.procedural_assertion_statement",
				rss);
		return create_object_with_doc<HdlStmNop>(ctx, commentParser);
	}
	auto rcs = ctx->randcase_statement();
	if (rcs) {
		NotImplementedLogger::print(
				"VerStatementParser.visitStatement_item.randcase_statement",
				rcs);
		return create_object_with_doc<HdlStmNop>(ctx, commentParser);
	}
	auto eps = ctx->expect_property_statement();
	assert(eps);
	NotImplementedLogger::print(
			"VerStatementParser.visitStatement_item.expect_property_statement",
			pas);
	return create_object_with_doc<HdlStmNop>(ctx, commentParser);
}

unique_ptr<iHdlStatement> VerStatementParser::visitStatement(
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

unique_ptr<iHdlStatement> VerStatementParser::visitBlocking_assignment(
		sv2017Parser::Blocking_assignmentContext *ctx) {
	// blocking_assignment:
	//     variable_lvalue ASSIGN ( delay_or_event_control expression | dynamic_array_new )
	//     | package_or_class_scoped_hier_id_with_select ASSIGN class_new
	//     | operator_assignment
	// ;
	VerExprParser ep(commentParser);
	auto vlv = ctx->variable_lvalue();
	if (vlv) {
		auto dst = ep.visitVariable_lvalue(vlv);
		auto e = ctx->expression();
		if (e) {
			auto src = ep.visitExpression(e);
			auto dec = ctx->delay_or_event_control();
			auto d = VerDelayParser(commentParser).visitDelay_or_event_control(
					dec);
			return create_object_with_doc<HdlStmAssign>(ctx, commentParser,
					move(dst), move(src), move(d.first), move(d.second), true);
		} else {
			auto dan = ctx->dynamic_array_new();
			assert(dan);
			NotImplementedLogger::print(
					"VerStatementParser.visitBlocking_assignment.dynamic_array_new",
					dan);
			return create_object_with_doc<HdlStmNop>(ctx, commentParser);
		}
	} else {
		auto cn = ctx->class_new();
		if (cn) {
			NotImplementedLogger::print(
					"VerStatementParser.visitBlocking_assignment.class_new",
					cn);
			return create_object_with_doc<HdlStmNop>(ctx, commentParser);
		} else {
			auto oa = ctx->operator_assignment();
			assert(oa);
			auto ae = ep.visitOperator_assignment(oa);
			return create_object_with_doc<HdlStmExpr>(ctx, commentParser,
					move(ae));
		}
	}
}

unique_ptr<iHdlStatement> VerStatementParser::visitCase_statement(
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
	VerExprParser ep(commentParser);
	auto switchOn = ep.visitExpression(ctx->expression());
	std::vector<HdlExprAndiHdlObj> cases;
	unique_ptr<iHdlObj> default_ = nullptr;
	HdlStmCaseType case_t = HdlStmCaseType::CASE;
	if (ctx->KW_INSIDE()) {
		NotImplementedLogger::print(
				"VerStatementParser.visitCase_statement.inside", ctx);

	} else {
		auto ck = ctx->case_keyword();
		assert(ck);
		if (ck->KW_CASE()) {
			case_t = HdlStmCaseType::CASE;
		} else if (ck->KW_CASEX()) {
			case_t = HdlStmCaseType::CASEX;
		} else {
			assert(ck->KW_CASEZ());
			case_t = HdlStmCaseType::CASEZ;
		}
		auto _cases = ctx->case_item();
		cases.reserve(_cases.size());
		for (auto _c : _cases) {
			auto cs = visitCase_item(_c);
			for (auto &c : cs) {
				if (c.expr) {
					cases.push_back(move(c));
				} else {
					if (default_) {
						throw std::runtime_error(
								"VerStatementParser.visitCase_statement case with multiple default");
					}
					default_ = move(c.obj);
				}
			}
		}

	}
	return create_object_with_doc<HdlStmCase>(ctx, commentParser, case_t,
			move(switchOn), cases, move(default_));

}
std::vector<HdlExprAndiHdlObj> VerStatementParser::visitCase_item(
		sv2017Parser::Case_itemContext *ctx) {
	// case_item
	//    : expression (',' expression)* ':' statement_or_null
	//    | 'default' (':')? statement_or_null
	//    ;
	std::vector<HdlExprAndiHdlObj> res;
	auto conds = ctx->expression();
	auto stms = ctx->statement_or_null();
	if (conds.size()) {
		for (auto c : conds) {
			auto ce = VerExprParser(commentParser).visitExpression(c);
			// [TODO] it would be better to copy the statements instead of parsing again
			auto _stms = visitStatement_or_null(stms);
			auto o = HdlExprAndiHdlObj(move(ce), move(_stms));
			res.push_back(move(o));
		}
	} else {
		auto _stms = visitStatement_or_null(stms);
		res.push_back( { nullptr, move(_stms) });
	}
	return res;
}

unique_ptr<HdlStmAssign> VerStatementParser::visitVariable_assignment(
		sv2017Parser::Variable_assignmentContext *ctx) {
	// variable_assignment:
	//     variable_lvalue ASSIGN expression;
	VerExprParser ep(commentParser);
	auto _dst = ctx->variable_lvalue();
	auto dst = ep.visitVariable_lvalue(_dst);
	auto _src = ctx->expression();
	auto src = ep.visitExpression(_src);
	auto o = create_object_with_doc<HdlStmAssign>(ctx, commentParser, move(dst),
			move(src), true);
	return o;
}

unique_ptr<iHdlStatement> VerStatementParser::visitLoop_statement(
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
	unique_ptr<iHdlStatement> stm;
	auto _stm = ctx->statement();
	if (_stm)
		stm = visitStatement(_stm);
	else {
		auto sn = ctx->statement_or_null();
		assert(sn);
		stm = visitStatement_or_null(sn);
	}
	VerExprParser ep(commentParser);
	if (ctx->KW_FOREVER()) {
		return create_object_with_doc<HdlStmWhile>(ctx, commentParser,
				create_object<HdlValueInt>(ctx->KW_FOREVER(), 1), move(stm));

	} else if (ctx->KW_REPEAT()) {
		auto _e = ctx->expression();
		auto c = ep.visitExpression(_e);
		return create_object_with_doc<HdlStmRepeat>(ctx, commentParser, move(c),
				move(stm));

	} else if (ctx->KW_WHILE()) {
		auto _e = ctx->expression();
		auto c = ep.visitExpression(_e);
		return create_object_with_doc<HdlStmWhile>(ctx, commentParser, move(c),
				move(stm));

	} else if (ctx->KW_DO()) {
		auto _e = ctx->expression();
		auto c = ep.visitExpression(_e);
		return create_object_with_doc<HdlStmDoWhile>(ctx, commentParser,
				move(stm), move(c));

	} else if (ctx->KW_FOR()) {
		auto _init = ctx->for_initialization();
		auto _cond = ctx->expression();
		auto _step = ctx->for_step();

		auto init = create_object<HdlStmBlock>(ctx);
		if (_init)
			visitFor_initialization(_init,
					reinterpret_cast<vector<unique_ptr<iHdlStatement>>&>(init->statements));
		unique_ptr<iHdlExprItem> cond = nullptr;
		if (_cond)
			cond = ep.visitExpression(_cond);
		else
			cond = create_object<HdlValueInt>(nullptr, 1);

		auto step = create_object<HdlStmBlock>(ctx);
		if (_step)
			visitFor_step(_step,
					reinterpret_cast<vector<unique_ptr<iHdlStatement>>&>(step->statements));
		return create_object_with_doc<HdlStmFor>(ctx, commentParser, move(init),
				move(cond), move(step), move(stm));

	} else {
		assert(ctx->KW_FOREACH());
		// KW_FOREACH LPAREN package_or_class_scoped_hier_id_with_select
		//                   LSQUARE_BR loop_variables RSQUARE_BR RPAREN statement
		auto _collecton = ctx->package_or_class_scoped_hier_id_with_select();
		auto collecton = ep.visitPackage_or_class_scoped_hier_id_with_select(
				_collecton);
		auto _vars = ctx->loop_variables();
		std::vector<std::unique_ptr<iHdlObj>> var_defs;
		visitLoop_variables(_vars,
				reinterpret_cast<vector<unique_ptr<iHdlStatement>>&>(var_defs));
		return create_object_with_doc<HdlStmForIn>(ctx, commentParser, var_defs,
				move(collecton), move(stm));
	}
}

void VerStatementParser::visitFor_variable_declaration(
		sv2017Parser::For_variable_declarationContext *ctx,
		vector<unique_ptr<HdlIdDef>> &res) {
	// for_variable_declaration:
	//     ( KW_VAR )? data_type for_variable_declaration_var_assign
	//     ( COMMA for_variable_declaration_var_assign )*
	// ;
	auto _dt = ctx->data_type();
	VerTypeParser tp(commentParser);
	VerExprParser ep(commentParser);

	auto dt = tp.visitData_type(_dt);
	auto dt_tmp = dt.get();
	bool is_latched = ctx->KW_VAR() != nullptr;
	bool first = true;
	for (auto _fvdas : ctx->for_variable_declaration_var_assign()) {
		// for_variable_declaration_var_assign: identifier ASSIGN expression;
		auto name = ep.getIdentifierStr(_fvdas->identifier());
		if (first)
			first = false;
		else
			dt = dt_tmp->clone_uniq();
		auto _def_val = _fvdas->expression();
		auto def_val = ep.visitExpression(_def_val);
		auto vd = create_object<HdlIdDef>(_fvdas, name, move(dt), move(def_val),
				HdlDirection::DIR_INTERNAL, is_latched);
		res.push_back(move(vd));
	}
}

void VerStatementParser::visitFor_initialization(
		sv2017Parser::For_initializationContext *ctx,
		vector<unique_ptr<iHdlStatement>> &res) {
	// for_initialization:
	//     list_of_variable_assignments
	//     | for_variable_declaration ( COMMA for_variable_declaration )*
	// ;
	auto lva = ctx->list_of_variable_assignments();
	if (lva) {
		// list_of_variable_assignments: variable_assignment ( COMMA variable_assignment )*;
		for (auto _va : lva->variable_assignment()) {
			auto va = visitVariable_assignment(_va);
			res.push_back(move(va));
		}
	} else {
		auto fvds = ctx->for_variable_declaration();
		assert(fvds.size());
		for (auto _fvd : fvds) {
			visitFor_variable_declaration(_fvd,
					reinterpret_cast<vector<unique_ptr<HdlIdDef>>&>(res));
		}
	}

}

void VerStatementParser::visitFor_step(sv2017Parser::For_stepContext *ctx,
		vector<unique_ptr<iHdlStatement>> &res) {
	// for_step: sequence_match_item ( COMMA sequence_match_item )*;
	VerExprParser ep(commentParser);
	for (auto _smi : ctx->sequence_match_item()) {
		auto smi = visitSequence_match_item(_smi);
		res.push_back(move(smi));
	}
}

void VerStatementParser::visitLoop_variables(
		sv2017Parser::Loop_variablesContext *ctx,
		vector<unique_ptr<iHdlStatement>> &res) {
	// loop_variables: ( identifier )? ( COMMA ( identifier )? )*;
	VerExprParser ep(commentParser);
	for (auto _id : ctx->identifier()) {
		auto id = ep.visitIdentifier(_id);
		res.push_back(create_object<HdlStmExpr>(ctx, move(id)));
	}
}

unique_ptr<HdlStmAssign> VerStatementParser::visitNonblocking_assignment(
		sv2017Parser::Nonblocking_assignmentContext *ctx) {
	// nonblocking_assignment
	//    : variable_lvalue '<=' (delay_or_event_control)? expression
	//    ;
	auto vl = ctx->variable_lvalue();
	VerExprParser ep(commentParser);
	auto dst = ep.visitVariable_lvalue(vl);
	auto e = ctx->expression();
	auto src = ep.visitExpression(e);
	auto dec = ctx->delay_or_event_control();
	if (dec) {
		auto d = VerDelayParser(commentParser).visitDelay_or_event_control(dec);
		return create_object_with_doc<HdlStmAssign>(ctx, commentParser,
				move(dst), move(src), move(d.first), move(d.second), false);
	} else {
		return create_object_with_doc<HdlStmAssign>(ctx, commentParser,
				move(dst), move(src), false);
	}
}

unique_ptr<HdlStmBlock> VerStatementParser::visitSeq_block(
		sv2017Parser::Seq_blockContext *ctx) {
	// seq_block:
	//     KW_BEGIN ( COLON identifier | {_input->LA(1) != COLON}? )
	//         ( block_item_declaration )* ( statement_or_null )*
	//     KW_END (COLON identifier |  {_input->LA(1) != COLON}?);
	return visit_block(ctx);
}

HdlStmBlockJoinType visitJoin_keyword(sv2017Parser::Join_keywordContext *ctx) {
	// join_keyword:
	//     KW_JOIN
	//     | KW_JOIN_ANY
	//     | KW_JOIN_NONE
	// ;
	if (ctx->KW_JOIN())
		return HdlStmBlockJoinType::PAR_JOIN;
	else if (ctx->KW_JOIN_ANY())
		return HdlStmBlockJoinType::PAR_JOIN_ANY;
	else {
		assert(ctx->KW_JOIN_NONE());
		return HdlStmBlockJoinType::PAR_JOIN_NONE;
	}
}

unique_ptr<HdlStmBlock> VerStatementParser::visitPar_block(
		sv2017Parser::Par_blockContext *ctx) {
	// par_block:
	//     KW_FORK ( COLON identifier | {_input->LA(1) != COLON}? )
	//         ( block_item_declaration )* ( statement_or_null )*
	//     join_keyword ( COLON identifier |  {_input->LA(1) != COLON}? );
	auto b = visit_block(ctx);
	b->join_t = visitJoin_keyword(ctx->join_keyword());
	return b;
}

void VerStatementParser::visitBlock_item_declaration(
		sv2017Parser::Block_item_declarationContext *ctx,
		std::vector<unique_ptr<iHdlObj>> &res) {
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
	auto &res_var = reinterpret_cast<vector<unique_ptr<HdlIdDef>>&>(res);
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

unique_ptr<iHdlStatement> VerStatementParser::visitConditional_statement(
		sv2017Parser::Conditional_statementContext *ctx) {
	//conditional_statement:
	//    ( unique_priority )? KW_IF LPAREN cond_predicate RPAREN statement_or_null
	//    ( KW_ELSE statement_or_null | {_input->LA(1) != KW_ELSE}? );
	auto c = ctx->cond_predicate();
	auto s = ctx->statement_or_null();
	VerExprParser ep(commentParser);
	auto cond = ep.visitCond_predicate(c);

	auto ifTrue = visitStatement_or_null(s[0]);
	unique_ptr<iHdlStatement> ifFalse = nullptr;
	if (s.size() == 2) {
		ifFalse = visitStatement_or_null(s[1]);
	}
	auto ifStm = create_object<HdlStmIf>(ctx, move(cond), move(ifTrue),
			move(ifFalse));
	ifStm->__doc__ = commentParser.parse(ctx);
	HdlStmIf_collapse_elifs(*ifStm);
	return ifStm;
}

unique_ptr<HdlStmProcess> VerStatementParser::visitProcedural_timing_control_statement(
		sv2017Parser::Procedural_timing_control_statementContext *ctx) {
	// procedural_timing_control_statement: procedural_timing_control statement_or_null;

	auto ptc = ctx->procedural_timing_control();
	VerDelayParser dp(commentParser);
	auto sens_list = dp.visitProcedural_timing_control(ptc);
	auto stms = visitStatement_or_null(ctx->statement_or_null());
	if (sens_list.second) {
		assert(sens_list.first == nullptr && "no event and delay at once");
		return create_object_with_doc<HdlStmProcess>(ctx, commentParser,
				move(sens_list.second), move(stms));
	} else if (sens_list.first) {
		auto wait = create_object<HdlStmWait>(ctx, move(sens_list.first));
		// if not in the block, wrap it in the block stm
		auto stms_block = dynamic_cast<HdlStmBlock*>(stms.get());
		if (!stms_block) {
			auto b = create_object<HdlStmBlock>(ctx, move(stms));
			stms = move(b);
			stms_block = dynamic_cast<HdlStmBlock*>(stms.get());
		}
		// push_front
		stms_block->statements.push_back(move(wait));
		std::rotate(stms_block->statements.rbegin(),
				stms_block->statements.rbegin() + 1,
				stms_block->statements.rend());
		return create_object_with_doc<HdlStmProcess>(ctx, commentParser,
				nullptr, move(stms));
	} else {
		return create_object_with_doc<HdlStmProcess>(ctx, commentParser,
				nullptr, move(stms));
	}
}

unique_ptr<iHdlStatement> VerStatementParser::visitStatement_or_null(
		sv2017Parser::Statement_or_nullContext *ctx) {
	// statement_or_null:
	//     statement
	//     | ( attribute_instance )* SEMI
	// ;
	if (ctx == nullptr)
		return nullptr;
	auto s = ctx->statement();
	if (s) {
		return visitStatement(s);
	} else {
		VerAttributeParser::visitAttribute_instance(ctx->attribute_instance());
		return create_object<HdlStmNop>(ctx);
	}
}

void VerStatementParser::visitContinuous_assign(
		sv2017Parser::Continuous_assignContext *ctx,
		vector<unique_ptr<iHdlStatement>> &res) {
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
	// doc assigned from top
	for (auto _va : lva->variable_assignment()) {
		auto va = visitVariable_assignment(_va);
		va->is_blocking = false;
		res.push_back(move(va));
	}
}

unique_ptr<HdlStmProcess> VerStatementParser::visitInitial_construct(
		sv2017Parser::Initial_constructContext *ctx) {
	// initial_construct: KW_INITIAL statement_or_null;
	auto _stm = ctx->statement_or_null();
	auto body = visitStatement_or_null(_stm);

	// we are adding the wait statement at the end to not that this is an initiall process (construct)
	auto bl = dynamic_cast<HdlStmBlock*>(body.get());
	if (bl == nullptr) {
		body = create_object<HdlStmBlock>(ctx, move(body));
		bl = static_cast<HdlStmBlock*>(body.get());
	}
	auto w = create_object<HdlStmWait>(ctx);
	bl->statements.push_back(move(w));

	return create_object<HdlStmProcess>(ctx, nullptr, move(body));
}

unique_ptr<iHdlStatement> VerStatementParser::visitSequence_match_item(
		sv2017Parser::Sequence_match_itemContext *ctx) {
	// sequence_match_item:
	//     operator_assignment
	//     | expression
	// ;
	VerExprParser ep(commentParser);
	unique_ptr<iHdlExprItem> e;
	auto oa = ctx->operator_assignment();
	if (oa) {
		e = ep.visitOperator_assignment(oa);
	} else {
		auto _e = ctx->expression();
		assert(_e);
		e = ep.visitExpression(_e);
	}
	return create_object<HdlStmExpr>(ctx, move(e));
}

unique_ptr<iHdlStatement> VerStatementParser::visitElaboration_system_task(
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
	std::vector<unique_ptr<iHdlExprItem>> args;
	auto un = ctx->UNSIGNED_NUMBER();
	if (un) {
		args.push_back(VerLiteralParser::visitUNSIGNED_NUMBER(un));
	}
	auto la = ctx->list_of_arguments();
	if (la)
		VerExprParser(commentParser).visitList_of_arguments(la, args);

	auto e = HdlOp::call(ctx, create_object<HdlValueId>(ctx, name), args);
	return create_object<HdlStmExpr>(ctx, move(e));
}

}
}
