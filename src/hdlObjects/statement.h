#pragma once

#include <vector>
#include "jsonable.h"
#include "statement.h"
#include "expr.h"

enum StatementType {
	s_EXPR, s_IF, s_WHILE, s_RETURN, s_ASSIGMENT, s_PROCESS
};

class Statement {
public:
	// an optional extra label specified in HDL
	std::string label;
	StatementType type;
	std::vector< std::vector<Statement*> * > sub_statements;
	/*
	 * for EXPR exprs contains only one item which is this value
	 * for IF exprs containst the main condition and conditions from the else ifs
	 * for RETURN exprs contains (optionaly) the return value
	 * for ASSIG exprs contains dst, src in this order
	 * for WHILE exprs contains the condition
	 * for PROCESS exprs contains the sensitivity list items, if sensitivity is not specified the re is only one time nullptr
	 */
	std::vector< Expr *> exprs;

	Statement(StatementType type);
	static Statement* EXPR(Expr * e);
	static Statement* IF(Expr * cond, std::vector<Statement*> * ifTrue);
	static Statement* IF(
			Expr * cond,
			std::vector<Statement*>* ifTrue,
			std::vector<Statement*>* ifFalse);
	static Statement* IF(
			Expr * cond,
			std::vector<Statement*>* ifTrue,
			const std::vector<std::pair<Expr*, std::vector<Statement*>*>> & elseIfs,
			std::vector<Statement*>* ifFalse);
	static Statement* RETURN(Expr * val);
	static Statement* RETURN();
	static Statement* ASSIG(Expr * dst, Expr * src);
	static Statement* WHILE(Expr * cond, std::vector<Statement*>* body);
	static Statement* PROCESS(std::vector<Expr*> * sensitivity, std::vector<Statement*>* body);
#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
	~Statement();
};
