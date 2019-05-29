#include "simultaneousStatementParser.h"

#include <assert.h>

#include "notImplementedLogger.h"
#include "exprParser.h"
#include "statementParser.h"

namespace hdlConvertor {
namespace vhdl {
using namespace std;
using namespace hdlObjects;

Statement * SimultaneousStatementParser::visitSimple_simultaneous_statement(
		vhdlParser::Simple_simultaneous_statementContext * ctx) {
	// simple_simultaneous_statement
	//   : ( label_colon )?
	//     simple_expression ASSIGN simple_expression ( tolerance_aspect )? SEMI
	//   ;
	if (ctx->label_colon()) {
		NotImplementedLogger::print(
				"SimultaneousStatementParser.visitSimple_simultaneous_statement - label_colon");
	}
	auto se = ctx->simple_expression();
	Expr * dst = ExprParser::visitSimple_expression(se[0]);
	Expr * src = ExprParser::visitSimple_expression(se[1]);
	if (ctx->tolerance_aspect()) {
		NotImplementedLogger::print(
				"SimultaneousStatementParser.visitSimple_simultaneous_statement - tolerance_aspect");
	}
	return Statement::ASSIG(dst, src);
}

Statement * SimultaneousStatementParser::visitSimultaneous_case_statement(
		vhdlParser::Simultaneous_case_statementContext * ctx) {
	// simultaneous_case_statement
	//   : ( label_colon )? CASE expression USE
	//     ( simultaneous_alternative )+
	//     END CASE ( identifier )? SEMI
	//   ;
	if (ctx->label_colon()) {
		NotImplementedLogger::print(
				"SimultaneousStatementParser.visitSimultaneous_case_statement - label_colon");
	}
	if (ctx->identifier()) {
		NotImplementedLogger::print(
				"SimultaneousStatementParser.visitSimultaneous_case_statement - identifier");
	}
	auto _e = ctx->expression();
	auto e = ExprParser::visitExpression(_e);
	vector<Statement::case_t> alternatives;
	vector<Statement*>* _default = nullptr;
	for (auto a : ctx->simultaneous_alternative()) {
		// simultaneous_alternative
		//   : WHEN choices ARROW simultaneous_statement_part
		//   ;
		for (auto ch : ExprParser::visitChoices(a->choices())) {
			auto s = a->simultaneous_statement_part();
			auto stms = visitSimultaneous_statement_part(s);
			if (ch == nullptr) {
				assert(_default == nullptr);
				_default = stms;
			} else {
				alternatives.push_back( { ch, stms });
			}
		}
	}
	auto cstm = Statement::CASE(e, alternatives, _default);
	cstm->position = Position(ctx->getStart()->getLine(),
			ctx->getStop()->getLine(), -1, -1);
	return cstm;
}
Statement * SimultaneousStatementParser::visitSimultaneous_if_statement(
		vhdlParser::Simultaneous_if_statementContext * ctx) {
	// simultaneous_if_statement
	//   : ( label_colon )? IF condition USE
	//     simultaneous_statement_part
	//     ( ELSIF condition USE simultaneous_statement_part )*
	//     ( ELSE simultaneous_statement_part )?
	//     END USE ( identifier )? SEMI
	//   ;

	// if_statement :
	// ( label_colon )? IF condition THEN
	// sequence_of_statements
	// ( ELSIF condition THEN sequence_of_statements )*
	// ( ELSE sequence_of_statements )?
	// END IF ( identifier )? SEMI
	// ;
	if (ctx->label_colon())
		NotImplementedLogger::print(
				"SimultaneousStatementParser.visitSimultaneous_if_statement - label_colon");

	auto c = ctx->condition();
	auto cIt = c.begin();
	auto s = ctx->simultaneous_statement_part();
	auto sIt = s.begin();

	Expr * cond = StatementParser::visitCondition(*cIt);
	++cIt;
	if (cIt != c.end()) {
		NotImplementedLogger::print(
				"SimultaneousStatementParser.visitSimultaneous_if_statement - ELSIF");
	}
	vector<Statement*> * ifTrue = visitSimultaneous_statement_part(*sIt);
	++sIt;
	Statement * ifStm = nullptr;
	if (sIt != s.end()) {
		ifStm = Statement::IF(cond, ifTrue,
				visitSimultaneous_statement_part(*sIt));
	} else {
		ifStm = Statement::IF(cond, ifTrue);
	}
	ifStm->position = Position(ctx->getStart()->getLine(),
			ctx->getStop()->getLine(), -1, -1);
	return ifStm;

}
Statement * SimultaneousStatementParser::visitSimultaneous_procedural_statement(
		vhdlParser::Simultaneous_procedural_statementContext * ctx) {
	// simultaneous_procedural_statement
	//   : ( label_colon )? PROCEDURAL ( IS )?
	//     procedural_declarative_part BEGIN
	//     procedural_statement_part
	//     END PROCEDURAL ( identifier )? SEMI
	//   ;
	if (ctx->label_colon())
		NotImplementedLogger::print(
				"SimultaneousStatementParser.visitSimultaneous_procedural_statement - label_colon");
	NotImplementedLogger::print(
			"SimultaneousStatementParser.visitSimultaneous_procedural_statement");

	return nullptr;
}
Statement * SimultaneousStatementParser::visitSimultaneous_statement(
		vhdlParser::Simultaneous_statementContext * ctx) {
	// simultaneous_statement
	//   : simple_simultaneous_statement
	//   | simultaneous_if_statement
	//   | simultaneous_case_statement
	//   | simultaneous_procedural_statement
	//   | ( label_colon )? NULL_SYM SEMI
	//   ;
	auto ss = ctx->simple_simultaneous_statement();
	if (ss) {
		return visitSimple_simultaneous_statement(ss);
	}
	auto si = ctx->simultaneous_if_statement();
	if (si) {
		return visitSimultaneous_if_statement(si);
	}
	auto sc = ctx->simultaneous_case_statement();
	if (sc) {
		return visitSimultaneous_case_statement(sc);
	}
	auto sp = ctx->simultaneous_procedural_statement();
	if (sp) {
		return visitSimultaneous_procedural_statement(sp);
	}
	if (ctx->label_colon()) {
		NotImplementedLogger::print(
				"SimultaneousStatementParser.visitSimultaneous_statement - label_colon");
	}
	assert(ctx->NULL_SYM());
	return nullptr;
}

vector<Statement *> * SimultaneousStatementParser::visitSimultaneous_statement_part(
		vhdlParser::Simultaneous_statement_partContext * ctx) {
	// simultaneous_statement_part
	//   : ( simultaneous_statement )*
	//   ;
	auto res = new vector<Statement*>;
	for (auto _s : ctx->simultaneous_statement()) {
		auto s = visitSimultaneous_statement(_s);
		res->push_back(s);
	}
	return res;
}

}
}
