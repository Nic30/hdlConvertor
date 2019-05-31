#include "statementParser.h"
#include "../notImplementedLogger.h"
#include "exprParser.h"

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
				"VerStatementParser.visitStatement.attribute_instance");
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
		NotImplementedLogger::print("VerStatementParser.disable_statement");
		return {nullptr, nullptr};
	}
	auto et = ctx->event_trigger();
	if (et) {
		NotImplementedLogger::print("VerStatementParser.event_trigger");
		return {nullptr, nullptr};
	}
	auto ls = ctx->loop_statement();
	if (ls) {
		NotImplementedLogger::print("VerStatementParser.loop_statement");
		return {nullptr, nullptr};
	}
	auto nba = ctx->nonblocking_assignment();
	if (nba) {
		return {visitNonblocking_assignment(nba), nullptr};
	}
	auto pb = ctx->par_block();
	if (pb) {
		NotImplementedLogger::print("VerStatementParser.par_block");
		return {nullptr, nullptr};
	}
	auto pca = ctx->procedural_continuous_assignments();
	if (pca) {
		NotImplementedLogger::print(
				"VerStatementParser.procedural_continuous_assignments");
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
		NotImplementedLogger::print("VerStatementParser.system_task_enable");
		return {nullptr, nullptr};
	}
	auto ta = ctx->task_enable();
	if (ta) {
		NotImplementedLogger::print("VerStatementParser.task_enable");
		return {nullptr, nullptr};
	}
	auto ws = ctx->wait_statement();
	if (ws) {
		NotImplementedLogger::print("VerStatementParser.wait_statement");
		return {nullptr, nullptr};
	}
	throw std::runtime_error(
			"VerStatementParser.visitStatement - probably unimplemented transition");
}

Statement * VerStatementParser::visitBlocking_assignment(
		Verilog2001Parser::Blocking_assignmentContext *ctx) {
	// blocking_assignment
	//    : variable_lvalue '=' (delay_or_event_control)? expression
	//    ;
	auto dec = ctx->delay_or_event_control();
	if (dec) {
		NotImplementedLogger::print(
				"VerStatementParser.visitBlocking_assignment.delay_or_event_control");
	}
	auto dst = VerExprParser::visitVariable_lvalue(ctx->variable_lvalue());
	auto src = VerExprParser::visitExpression(ctx->expression());
	return Statement::ASSIG(dst, src);
}

Statement * VerStatementParser::visitCase_statement(
		Verilog2001Parser::Case_statementContext * ctx) {
	// case_statement
	//    : 'case' '(' expression ')' case_item (case_item)* 'endcase'
	//    | 'casez' '(' expression ')' case_item (case_item)* 'endcase'
	//    | 'casex' '(' expression ')' case_item (case_item)* 'endcase'
	//    ;
	if (ctx->children[0]->getText() != "case") {
		NotImplementedLogger::print(
				"VerStatementParser.visitCase_statement "
						+ ctx->children[0]->getText());
		return nullptr;
	}
	auto switchOn = VerExprParser::visitExpression(ctx->expression());
	std::vector<Statement::case_t> cases;
	vector<Statement*> * default_ = nullptr;
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
	return Statement::CASE(switchOn, cases, default_);

}
std::vector<Statement::case_t> VerStatementParser::visitCase_item(
		Verilog2001Parser::Case_itemContext * ctx) {
	// case_item
	//    : expression (',' expression)* ':' statement_or_null
	//    | 'default' (':')? statement_or_null
	//    ;
	std::vector<Statement::case_t> res;
	auto conds = ctx->expression();
	auto stms = ctx->statement_or_null();
	if (conds.size()) {
		for (auto c : conds) {
			auto ce = VerExprParser::visitExpression(c);
			// [TODO] it would be better to copy the statements instead of parsing again
			res.push_back( { ce, visitStatement_or_null__wrapped(stms) });
		}
	} else {
		res.push_back( { nullptr, visitStatement_or_null__wrapped(stms) });
	}
	return res;
}
Statement * VerStatementParser::visitNonblocking_assignment(
		Verilog2001Parser::Nonblocking_assignmentContext * ctx) {
	// nonblocking_assignment
	//    : variable_lvalue '<=' (delay_or_event_control)? expression
	//    ;
	auto dec = ctx->delay_or_event_control();
	if (dec) {
		NotImplementedLogger::print(
				"VerStatementParser.visitNonblocking_assignment.delay_or_event_control");
	}
	auto dst = VerExprParser::visitVariable_lvalue(ctx->variable_lvalue());
	auto src = VerExprParser::visitExpression(ctx->expression());
	return Statement::ASSIG(dst, src);
}
std::vector<Statement*> * VerStatementParser::visitSeq_block(
		Verilog2001Parser::Seq_blockContext * ctx) {
	// seq_block
	//    : 'begin' (':' block_identifier (block_item_declaration)*)? (statement)* 'end'
	//    ;
	auto bi = ctx->block_identifier();
	if (bi) {
		NotImplementedLogger::print(
				"VerStatementParser.visitSeq_block.block_identifier");
	}
	auto bd = ctx->block_item_declaration();
	if (bd.size()) {
		NotImplementedLogger::print(
				"VerStatementParser.visitSeq_block.block_item_declaration");
	}
	auto _stms = ctx->statement();
	auto stms = new vector<Statement*>;
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
Statement * VerStatementParser::visitConditional_statement(
		Verilog2001Parser::Conditional_statementContext * ctx) {
	// conditional_statement
	//    : 'if' '(' expression ')' statement_or_null ('else' statement_or_null)?
	//    | if_else_if_statement
	//    ;
	//
	auto e = ctx->expression();
	if (e) {
		auto cond = VerExprParser::visitExpression(e);
		auto ifTrue = visitStatement_or_null__wrapped(
				ctx->statement_or_null(0));
		auto ifFalse = ctx->statement_or_null(1);
		return Statement::IF(cond, ifTrue,
				visitStatement_or_null__wrapped(ifFalse));
	}

	// if_else_if_statement
	//    : 'if' '(' expression ')' statement_or_null ('else' 'if' '(' expression ')' statement_or_null)* ('else' statement_or_null)?
	//    ;
	NotImplementedLogger::print(
			"VerStatementParser.conditional_statement.if_else_if_statement");
	return nullptr;
}
Statement * VerStatementParser::visitProcedural_timing_control_statement(
		Verilog2001Parser::Procedural_timing_control_statementContext * ctx) {
	// procedural_timing_control_statement
	//    : delay_or_event_control statement_or_null
	//    ;
	auto sens_list = visitDelay_or_event_control(ctx->delay_or_event_control());
	auto stms = visitStatement_or_null__wrapped(ctx->statement_or_null());
	return Statement::PROCESS(sens_list, stms);
}

vector<Statement *> * VerStatementParser::visitStatement_or_null__wrapped(
		Verilog2001Parser::Statement_or_nullContext * ctx) {
	if (ctx == nullptr)
		return nullptr;
	auto r = visitStatement_or_null(ctx);
	if (r.first) {
		auto res = new vector<Statement*>(1);
		(*res)[0] = r.first;
		return res;
	} else {
		return r.second;
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
		NotImplementedLogger::print(
				"VerStatementParser.procedural_timing_control_statement");
		return {nullptr, nullptr};
	}
}

vector<Expr*>* VerStatementParser::visitDelay_or_event_control(
		Verilog2001Parser::Delay_or_event_controlContext * ctx) {
	// delay_or_event_control
	//    : delay_control
	//    | event_control
	//    | 'repeat' '(' expression ')' event_control
	//    ;
	auto d = ctx->delay_control();
	if (d) {
		NotImplementedLogger::print(
				"VerStatementParser.visitDelay_or_event_control.delay_control");
		return nullptr;
	}
	auto e = ctx->expression();
	if (e) {
		NotImplementedLogger::print(
				"VerStatementParser.visitDelay_or_event_control.expression");
		return nullptr;
	}
	return vistEvent_control(ctx->event_control());
}

vector<Expr*> * VerStatementParser::vistEvent_control(
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
		auto res = new vector<Expr*>;
		res->push_back(VerExprParser::visitIdentifier(ei->identifier()));
		return res;
	}
	auto ee = ctx->event_expression();
	if (ee) {
		return VerExprParser::visitEvent_expression(ee);
	}
	auto res = new vector<Expr*>;
	res->push_back(Expr::all());
	return res;
}

vector<Statement *> VerStatementParser::vistContinuous_assign(
		Verilog2001Parser::Continuous_assignContext * ctx) {
	// continuous_assign
	//    : 'assign' (drive_strength)? (delay3)? list_of_net_assignments ';'
	//    ;
	auto ds = ctx->drive_strength();
	if (ds) {
		NotImplementedLogger::print(
				"VerStatementParser.vistContinuous_assign.drive_strength");
	}
	auto del = ctx->delay3();
	if (del) {
		NotImplementedLogger::print(
				"VerStatementParser.vistContinuous_assign.delay3");
	}
	auto lna = ctx->list_of_net_assignments();
	// list_of_net_assignments
	//    : net_assignment (',' net_assignment)*
	//    ;
	vector<Statement*> res;
	for (auto na : lna->net_assignment()) {
		auto stm = visitNet_assignment(na);
		res.push_back(stm);
	}
	res[0]->__doc__ = commentParser.parse(ctx);
	return res;
}

Statement* VerStatementParser::visitNet_assignment(
		Verilog2001Parser::Net_assignmentContext * ctx) {
	// net_assignment : net_lvalue '=' expression
	// ;
	return Statement::ASSIG(VerExprParser::visitNet_lvalue(ctx->net_lvalue()),
			VerExprParser::visitExpression(ctx->expression()));
}

}
}
