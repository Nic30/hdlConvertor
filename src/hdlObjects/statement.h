#pragma once

#include <vector>
#include "statement.h"
#include "expr.h"
#include "named.h"
#include "position.h"

namespace hdlConvertor {
namespace hdlObjects {

// @note the NOP statement is not required as it is represented by empty statement list
enum StatementType {
	s_EXPR, s_IF, s_CASE, s_WHILE, s_BREAK, s_RETURN, s_FOR, s_ASSIGMENT, s_PROCESS
};

const char * StatementType_toString(StatementType type);

class Statement : public WithDoc, public WithPos {
public:
	using case_t = std::pair<Expr*, std::vector<Statement*>*>;
	// an optional extra label specified in HDL
	std::string label;
	StatementType type;
	std::vector<std::vector<Statement*> *> sub_statements;
	/*
	 * for EXPR exprs contains only one item which is this value
	 * for IF exprs containst the main condition and conditions from the else ifs
	 * for CASE the first is the value of the switch the rest are values of the cases
	 * for RETURN exprs contains (optionaly) the return value
	 * for ASSIG exprs contains dst, src in this order
	 * for WHILE exprs contains the condition
	 * for PROCESS exprs contains the sensitivity list items, if sensitivity is not specified the re is only one time nullptr
	 */
	std::vector<Expr *> exprs;

	Statement(StatementType type);
	static Statement* EXPR(Expr * e);
	static Statement* IF(Expr * cond, std::vector<Statement*> * ifTrue);
	static Statement* IF(Expr * cond, std::vector<Statement*>* ifTrue,
			std::vector<Statement*>* ifFalse);
	static Statement* IF(Expr * cond, std::vector<Statement*>* ifTrue,
			const std::vector<case_t> & elseIfs,
			std::vector<Statement*>* ifFalse);
	static Statement* CASE(Expr * switchOn, const std::vector<case_t> cases,
			std::vector<Statement*>* default_);
	static Statement* RETURN(Expr * val);
	static Statement* RETURN();
	static Statement* ASSIG(Expr * dst, Expr * src);
	static Statement* WHILE(Expr * cond, std::vector<Statement*>* body);
	static Statement* BREAK();
	static Statement* PROCESS(std::vector<Expr*> * sensitivity,
			std::vector<Statement*>* body);
	static Statement* FOR(const std::vector<Expr*> & cond, std::vector<Statement*>* body);
	~Statement();
};

}
}
