#pragma once

#include <vector>
#include "jsonable.h"
#include "statement.h"
#include "expr.h"

enum StatementType {
	s_EXPR, s_IF, s_WHILE, s_RETURN, s_ASSIGMENT
};

class Statement {
public:
	StatementType type;
	std::vector< std::vector<Statement*> * > * ops;
	Expr* op0; // expr, cond, return, dst
	Expr* op1; // src

	Statement(StatementType type);
	static Statement* EXPR(Expr * e);
	static Statement* IF(Expr * cond, std::vector<Statement*> * ifTrue);
	static Statement* IF(
			Expr * cond,
			std::vector<Statement*>* ifTrue,
			std::vector<Statement*>* ifFalse);
	static Statement* RETURN(Expr * val);
	static Statement* RETURN();
	static Statement* ASSIG(Expr * dst, Expr * src);
	static Statement* WHILE(Expr * cond, std::vector<Statement*>* body);
#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
};
