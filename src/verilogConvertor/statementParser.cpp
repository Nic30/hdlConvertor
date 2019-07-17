#include <hdlConvertor/verilogConvertor/statementParser.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/verilogConvertor/exprParser.h>

namespace hdlConvertor {
namespace verilog {

using namespace std;
using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;
using namespace hdlConvertor::hdlObjects;

VerStatementParser::VerStatementParser(CommentParser & commentParser) :
		commentParser(commentParser) {
}
VerStatementParser::stm_or_block_t VerStatementParser::visitAlways_construct(
		Verilog2001Parser::Always_constructContext * ctx) {
	// always_construct
	//    : 'always' statement
	//    ;
	return visitStatement(ctx->statement());
}
VerStatementParser::stm_or_block_t VerStatementParser::visitStatement(
		Verilog2001Parser::StatementContext * ctx) {
	//statement
	//   : attribute_instance* blocking_assignment ';'
	//   | attribute_instance* case_statement
	//   | attribute_instance* conditional_statement
	//   | attribute_instance* disable_statement
	//   | attribute_instance* event_trigger
	//   | attribute_instance* loop_statement
	//   | attribute_instance* nonblocking_assignment ';'
	//   | attribute_instance* par_block
	//   | attribute_instance* procedural_continuous_assignments ';'
	//   | attribute_instance* procedural_timing_control_statement
	//   | attribute_instance* seq_block
	//   | attribute_instance* system_task_enable
	//   | attribute_instance* task_enable
	//   | attribute_instance* wait_statement
	//   ;
	auto ai = ctx->attribute_instance();
	if (ai.size()) {
		NotImplementedLogger::print(
				"VerStatementParser.visitStatement.attribute_instance", ai[0]);
	}
	auto ba = ctx->blocking_assignment();
	if (ba) {
		return {visitBlocking_assignment(ba), nullptr};
	}
	auto cs = ctx->case_statement();
	if (cs) {
		return {visitCase_statement(cs), nullptr};
	}
	auto conds = ctx->conditional_statement();
	if (conds) {
		return {visitConditional_statement(conds), nullptr};
	}
	auto d = ctx->disable_statement();
	if (d) {
		NotImplementedLogger::print("VerStatementParser.disable_statement", d);
		return {nullptr, nullptr};
	}
	auto et = ctx->event_trigger();
	if (et) {
		NotImplementedLogger::print("VerStatementParser.event_trigger", et);
		return {nullptr, nullptr};
	}
	auto ls = ctx->loop_statement();
	if (ls) {
		auto loop = visitLoop_statement(ls);
		return {loop, nullptr};
	}
	auto nba = ctx->nonblocking_assignment();
	if (nba) {
		return {visitNonblocking_assignment(nba), nullptr};
	}
	auto pb = ctx->par_block();
	if (pb) {
		NotImplementedLogger::print("VerStatementParser.par_block", pb);
		return {nullptr, nullptr};
	}
	auto pca = ctx->procedural_continuous_assignments();
	if (pca) {
		NotImplementedLogger::print(
				"VerStatementParser.procedural_continuous_assignments", pca);
		return {nullptr, nullptr};
	}
	auto ptcs = ctx->procedural_timing_control_statement();
	if (ptcs) {
		return {visitProcedural_timing_control_statement(ptcs), nullptr};
	}
	auto sb = ctx->seq_block();
	if (sb) {
		return {nullptr, visitSeq_block(sb)};
	}
	auto ste = ctx->system_task_enable();
	if (ste) {
		return {visitSystem_task_enable(ste), nullptr};
	}
	auto ta = ctx->task_enable();
	if (ta) {
		NotImplementedLogger::print("VerStatementParser.task_enable", ta);
		return {nullptr, nullptr};
	}
	auto ws = ctx->wait_statement();
	if (ws) {
		NotImplementedLogger::print("VerStatementParser.wait_statement", ws);
		return {nullptr, nullptr};
	}
	throw std::runtime_error(
			"VerStatementParser.visitStatement - probably unimplemented transition");
}

iHdlStatement * VerStatementParser::visitSystem_task_enable(
		Verilog2001Parser::System_task_enableContext * ctx) {
	// system_task_enable
	//    : system_task_identifier ('(' (expression (',' expression)*)? ')')? ';'
	//    ;
	auto _id = ctx->system_task_identifier();
	auto id = VerExprParser::visitSystem_task_identifier(_id);
	auto _args = ctx->expression();
	vector<iHdlExpr*> args(_args.size());
	size_t i = 0;
	for (auto _a : _args) {
		auto a = VerExprParser::visitExpression(_a);
		args[i] = a;
		i++;
	}
	auto c = iHdlExpr::call(id, args);
	return iHdlStatement::EXPR(c);
}

iHdlStatement * VerStatementParser::visitBlocking_assignment(
		Verilog2001Parser::Blocking_assignmentContext *ctx) {
	// blocking_assignment
	//    : variable_lvalue '=' (delay_or_event_control)? expression
	//    ;
	auto dst = VerExprParser::visitVariable_lvalue(ctx->variable_lvalue());
	auto src = VerExprParser::visitExpression(ctx->expression());
	auto dec = ctx->delay_or_event_control();
	iHdlStatement * assig;
	if (dec) {
		auto d = visitDelay_or_event_control(dec);
		assig = new HdlStmAssign(dst, src, d.first, d.second, true);
	} else {
		assig = new HdlStmAssign(dst, src, true);
	}
	assig->__doc__ = commentParser.parse(ctx);
	return assig;
}

iHdlStatement * VerStatementParser::visitCase_statement(
		Verilog2001Parser::Case_statementContext * ctx) {
	// case_statement
	//    : 'case' '(' expression ')' case_item (case_item)* 'endcase'
	//    | 'casez' '(' expression ')' case_item (case_item)* 'endcase'
	//    | 'casex' '(' expression ')' case_item (case_item)* 'endcase'
	//    ;
	if (ctx->children[0]->getText() != "case") {
		NotImplementedLogger::print(
				"VerStatementParser.visitCase_statement "
						+ ctx->children[0]->getText(), ctx);
		return nullptr;
	}
	auto switchOn = VerExprParser::visitExpression(ctx->expression());
	std::vector<iHdlStatement::case_t> cases;
	vector<iHdlObj*> * default_ = nullptr;
	auto _cases = ctx->case_item();
	cases.reserve(_cases.size());
	for (auto _c : _cases) {
		auto cs = visitCase_item(_c);
		for (auto c : cs) {
			if (c.first) {
				cases.push_back(c);
			} else {
				assert(default_ == nullptr);
				default_ = c.second;
			}
		}
	}
	auto cs = iHdlStatement::CASE(switchOn, cases, default_);
	cs->__doc__ = commentParser.parse(ctx);
	return cs;

}
std::vector<iHdlStatement::case_t> VerStatementParser::visitCase_item(
		Verilog2001Parser::Case_itemContext * ctx) {
	// case_item
	//    : expression (',' expression)* ':' statement_or_null
	//    | 'default' (':')? statement_or_null
	//    ;
	std::vector<iHdlStatement::case_t> res;
	auto conds = ctx->expression();
	auto stms = ctx->statement_or_null();
	if (conds.size()) {
		for (auto c : conds) {
			auto ce = VerExprParser::visitExpression(c);
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
HdlStmAssign * VerStatementParser::visitVariable_assignment(
		Verilog2001Parser::Variable_assignmentContext *ctx) {
	// variable_assignment
	//    : variable_lvalue '=' expression
	//    ;
	auto _vl = ctx->variable_lvalue();
	auto _e = ctx->expression();
	auto vl = VerExprParser::visitVariable_lvalue(_vl);
	auto e = VerExprParser::visitExpression(_e);
	return new HdlStmAssign(vl, e, true);
}
iHdlStatement * VerStatementParser::visitLoop_statement(
		Verilog2001Parser::Loop_statementContext * ctx) {
	// loop_statement
	//    : 'forever' statement
	//    | 'repeat' '(' expression ')' statement
	//    | 'while' '(' expression ')' statement
	//    | 'for' '(' variable_assignment ';' expression ';' variable_assignment ')' statement
	//    ;
	auto _stm = ctx->statement();
	auto stm = visitStatement__as_block(_stm);
	auto name = ctx->children[0]->getText();
	if (name == "forever") {
		return iHdlStatement::WHILE(iHdlExpr::INT(1), stm);
	} else if (name == "repeat") {
		NotImplementedLogger::print(
				"VerStatementParser.visitLoop_statement.repeat", ctx);
		return nullptr;
	} else if (name == "while") {
		auto _e = ctx->expression();
		auto c = VerExprParser::visitExpression(_e);
		return iHdlStatement::WHILE(c, stm);
	} else if (name == "for") {
		auto _va = ctx->variable_assignment();
		assert(_va.size() == 2);
		auto _e = ctx->expression();
		auto va0 = visitVariable_assignment(_va.at(0));
		auto e = VerExprParser::visitExpression(_e);
		auto va1 = visitVariable_assignment(_va.at(1));

		return iHdlStatement::FOR(va0, e, va1, stm);
	}
	assert(false && "unknown statement");
	return nullptr;
}

HdlStmAssign * VerStatementParser::visitNonblocking_assignment(
		Verilog2001Parser::Nonblocking_assignmentContext * ctx) {
	// nonblocking_assignment
	//    : variable_lvalue '<=' (delay_or_event_control)? expression
	//    ;
	auto vl = ctx->variable_lvalue();
	auto dst = VerExprParser::visitVariable_lvalue(vl);
	auto e = ctx->expression();
	auto src = VerExprParser::visitExpression(e);
	HdlStmAssign * a;
	auto dec = ctx->delay_or_event_control();
	if (dec) {
		auto d = visitDelay_or_event_control(dec);
		a = new HdlStmAssign(dst, src, d.first, d.second, false);
	} else {
		a = new HdlStmAssign(dst, src, false);
	}
	a->__doc__ = commentParser.parse(ctx);
	return a;
}
std::vector<iHdlStatement*> * VerStatementParser::visitSeq_block(
		Verilog2001Parser::Seq_blockContext * ctx) {
	// seq_block
	//    : 'begin' (':' block_identifier (block_item_declaration)*)? (statement)* 'end'
	//    ;
	auto bi = ctx->block_identifier();
	if (bi) {
		NotImplementedLogger::print(
				"VerStatementParser.visitSeq_block.block_identifier", bi);
	}
	auto bd = ctx->block_item_declaration();
	if (bd.size()) {
		NotImplementedLogger::print(
				"VerStatementParser.visitSeq_block.block_item_declaration",
				bd[0]);
	}
	auto _stms = ctx->statement();
	auto stms = new vector<iHdlStatement*>;
	stms->reserve(_stms.size());
	for (auto stm : _stms) {
		auto r = visitStatement(stm);
		if (r.first) {
			stms->push_back(r.first);
		} else if (r.second) {
			// [fixme] block variables can get mixed together
			for (auto s : *r.second)
				stms->push_back(s);
			delete r.second;
		}
	}
	return stms;
}
iHdlStatement * VerStatementParser::visitConditional_statement(
		Verilog2001Parser::Conditional_statementContext * ctx) {
	// conditional_statement
	// : 'if' '(' expression ')' statement_or_null
	//   ('else' 'if' '(' expression ')' statement_or_null)*
	//   ('else' statement_or_null)?
	// ;
	//
	auto c = ctx->expression();
	auto cIt = c.begin();
	auto s = ctx->statement_or_null();
	auto sIt = s.begin();

	auto cond = VerExprParser::visitExpression(*cIt);
	auto ifTrue = visitStatement_or_null__as_block(*sIt);
	++cIt;
	++sIt;
	std::vector<iHdlStatement::case_t> elseIfs;
	while (cIt != c.end()) {
		auto c = VerExprParser::visitExpression(*cIt);
		auto stms = visitStatement_or_null__as_block(*sIt);
		elseIfs.push_back( { c, reinterpret_cast<vector<iHdlObj*>*>(stms) });
		++cIt;
		++sIt;
	}
	iHdlStatement * ifStm = nullptr;
	vector<iHdlStatement*> * ifFalse = nullptr;
	if (sIt != s.end()) {
		ifFalse = visitStatement_or_null__as_block(*sIt);
	}
	ifStm = iHdlStatement::IF(cond, reinterpret_cast<vector<iHdlObj*>*>(ifTrue),
			elseIfs, reinterpret_cast<vector<iHdlObj*>*>(ifFalse));
	ifStm->position.update_from_elem(ctx);
	ifStm->__doc__ = commentParser.parse(ctx);
	return ifStm;
}

HdlStmProcess * VerStatementParser::visitProcedural_timing_control_statement(
		Verilog2001Parser::Procedural_timing_control_statementContext * ctx) {
	// procedural_timing_control_statement
	//    : delay_or_event_control statement_or_null
	//    ;
	auto sens_list = visitDelay_or_event_control(ctx->delay_or_event_control());
	auto stms =
			reinterpret_cast<std::vector<iHdlObj*>*>(visitStatement_or_null__as_block(
					ctx->statement_or_null()));
	HdlStmProcess * p;
	if (sens_list.second) {
		assert(sens_list.first == nullptr && "no event and delay at one");
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

vector<iHdlStatement *> * VerStatementParser::visitStatement_or_null__as_block(
		Verilog2001Parser::Statement_or_nullContext * ctx) {
	if (ctx == nullptr)
		return nullptr;
	auto stm = visitStatement_or_null(ctx);
	if (stm.first) {
		auto body = new vector<iHdlStatement*>();
		body->push_back(stm.first);
		return body;
	} else if (stm.second) {
		return stm.second;
	} else {
		return new vector<iHdlStatement*>();
	}

}
VerStatementParser::stm_or_block_t VerStatementParser::visitStatement_or_null(
		Verilog2001Parser::Statement_or_nullContext * ctx) {
	// statement_or_null
	//    : statement
	//    | attribute_instance* ';'
	//    ;
	auto s = ctx->statement();
	if (s) {
		return visitStatement(s);
	} else {
		auto ai = ctx->attribute_instance();
		if (ai.size())
			NotImplementedLogger::print(
					"VerStatementParser.visitStatement_or_null.attribute_instance for nop",
					ctx);
		return {nullptr, nullptr};
	}
}

pair<iHdlExpr*, vector<iHdlExpr*>*> VerStatementParser::visitDelay_or_event_control(
		Verilog2001Parser::Delay_or_event_controlContext * ctx) {
	// delay_or_event_control
	//    : delay_control
	//    | event_control
	//    | 'repeat' '(' expression ')' event_control
	//    ;
	auto _d = ctx->delay_control();
	if (_d) {
		auto d = VerExprParser::visitDelay_control(_d);
		return {d, nullptr};
	}
	auto ec = ctx->event_control();
	auto e = ctx->expression();
	if (e) {
		NotImplementedLogger::print(
				"VerStatementParser.visitDelay_or_event_control - repeat", e);
	}
	return {nullptr, vistEvent_control(ec)};
}

vector<iHdlExpr*> * VerStatementParser::vistEvent_control(
		Verilog2001Parser::Event_controlContext * ctx) {
	//event_control
	//   : '@' event_identifier
	//   | '@' '(' event_expression ')'
	//   | '@' '*'
	//   | '@' '(' '*' ')'
	//   ;
	auto ei = ctx->event_identifier();
	if (ei) {
		// event_identifier
		//    : identifier
		//    ;
		auto res = new vector<iHdlExpr*>;
		res->push_back(VerExprParser::visitIdentifier(ei->identifier()));
		return res;
	}
	auto ee = ctx->event_expression();
	if (ee) {
		return VerExprParser::visitEvent_expression(ee);
	}
	auto res = new vector<iHdlExpr*>;
	res->push_back(iHdlExpr::all());
	return res;
}

vector<iHdlStatement *> VerStatementParser::vistContinuous_assign(
		Verilog2001Parser::Continuous_assignContext * ctx) {
	// continuous_assign
	//    : 'assign' (drive_strength)? (delay3)? list_of_net_assignments ';'
	//    ;
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
	auto lna = ctx->list_of_net_assignments();
	// list_of_net_assignments
	//    : net_assignment (',' net_assignment)*
	//    ;
	vector<iHdlStatement*> res;
	for (auto na : lna->net_assignment()) {
		auto stm = visitNet_assignment(na);
		res.push_back(stm);
	}
	res[0]->__doc__ = commentParser.parse(ctx);
	return res;
}

iHdlStatement* VerStatementParser::visitNet_assignment(
		Verilog2001Parser::Net_assignmentContext * ctx) {
	// net_assignment : net_lvalue '=' expression
	// ;
	auto nv = VerExprParser::visitNet_lvalue(ctx->net_lvalue());
	auto e = VerExprParser::visitExpression(ctx->expression());
	return new HdlStmAssign(nv, e, true);
}
vector<iHdlStatement*> * VerStatementParser::visitStatement__as_block(
		Verilog2001Parser::StatementContext * ctx) {
	auto stm = visitStatement(ctx);
	if (stm.first) {
		auto body = new vector<iHdlStatement*>();
		body->push_back(stm.first);
		return body;
	} else if (stm.second) {
		return stm.second;
	} else {
		return new vector<iHdlStatement*>();
	}
}
HdlStmProcess * VerStatementParser::visitInitial_construct(
		Verilog2001Parser::Initial_constructContext * ctx) {
	// initial_construct
	//    : 'initial' statement
	//    ;
	auto _stm = ctx->statement();
	vector<iHdlStatement*> * body = visitStatement__as_block(_stm);
	return new HdlStmProcess(nullptr,
			reinterpret_cast<vector<iHdlObj*>*>(body));
}

}
}
