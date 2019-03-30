#include "statementParser.h"
#include "../notImplementedLogger.h"
#include "exprParser.h"

using namespace std;
using namespace Verilog2001;

Statement * VerStatementParser::visitAlways_construct(
		Verilog2001Parser::Always_constructContext * ctx) {
	// always_construct
	//    : 'always' statement
	//    ;
	return visitStatement(ctx->statement());
}
Statement * VerStatementParser::visitStatement(
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
		NotImplementedLogger::print("VerStatementParser.blocking_assignment");
		return nullptr;
	}
	auto cs = ctx->case_statement();
	if (cs) {
		NotImplementedLogger::print("VerStatementParser.case_statement");
		return nullptr;
	}
	auto conds = ctx->conditional_statement();
	if (conds) {
		NotImplementedLogger::print("VerStatementParser.conditional_statement");
		return nullptr;
	}
	auto d = ctx->disable_statement();
	if (d) {
		NotImplementedLogger::print("VerStatementParser.disable_statement");
		return nullptr;
	}
	auto et = ctx->event_trigger();
	if (et) {
		NotImplementedLogger::print("VerStatementParser.event_trigger");
		return nullptr;
	}
	auto ls = ctx->loop_statement();
	if (ls) {
		NotImplementedLogger::print("VerStatementParser.loop_statement");
		return nullptr;
	}
	auto nba = ctx->nonblocking_assignment();
	if (nba) {
		NotImplementedLogger::print(
				"VerStatementParser.nonblocking_assignment");
		return nullptr;
	}
	auto pb = ctx->par_block();
	if (pb) {
		NotImplementedLogger::print("VerStatementParser.par_block");
		return nullptr;
	}
	auto pca = ctx->procedural_continuous_assignments();
	if (pca) {
		NotImplementedLogger::print(
				"VerStatementParser.procedural_continuous_assignments");
		return nullptr;
	}
	auto ptcs = ctx->procedural_timing_control_statement();
	if (ptcs) {
		NotImplementedLogger::print(
				"VerStatementParser.procedural_timing_control_statement");
		return nullptr;
	}
	auto sb = ctx->seq_block();
	if (sb) {
		NotImplementedLogger::print("VerStatementParser.seq_block");
		return nullptr;
	}
	auto ste = ctx->system_task_enable();
	if (ste) {
		NotImplementedLogger::print("VerStatementParser.system_task_enable");
		return nullptr;
	}
	auto ta = ctx->task_enable();
	if (ta) {
		NotImplementedLogger::print("VerStatementParser.task_enable");
		return nullptr;
	}
	auto ws = ctx->wait_statement();
	if (ws) {
		NotImplementedLogger::print("VerStatementParser.wait_statement");
		return nullptr;
	}
	throw std::runtime_error(
			"VerStatementParser.visitStatement - probably unimplemented transition");
}

vector<Statement *> VerStatementParser::vistContinuous_assign(
		Verilog2001::Verilog2001Parser::Continuous_assignContext * ctx) {
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
	return res;
}

Statement* VerStatementParser::visitNet_assignment(
		Verilog2001Parser::Net_assignmentContext * ctx) {
	// net_assignment : net_lvalue '=' expression
	// ;
	return Statement::ASSIG(
			VerExprParser::vistiNet_lvalue(ctx->net_lvalue()),
			VerExprParser::visitExpression(ctx->expression()));
}
