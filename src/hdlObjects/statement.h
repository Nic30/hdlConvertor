#pragma once

#include <vector>
#include "jsonable.h"
#include "statement.h"
#include "expr.h"
#include "position.h"

enum StatementType {
	s_NONE, s_EXPR, s_IFBODY, s_IF, s_ELSIF, s_ELSE, s_CASE, s_WHILE, s_FOR, s_RETURN, s_ASSIGMENT
};

class Statement {
public:
	StatementType type;
	std::vector< std::vector<Statement*> * > * ops;
	std::vector<Expr*> op;
	Expr* op0; // expr, cond, return, dst
	Expr* op1; // src
	Position * position = NULL;

	Statement(StatementType type);
	static Statement* NONE();
	static Statement* EXPR(Expr * e);
	static Statement* IFBODY(std::vector<Statement*> * body);
	static Statement* IF(Expr * cond, std::vector<Statement*> * body);
	static Statement* ELSIF(Expr * cond, std::vector<Statement*> * body);
	static Statement* ELSE(std::vector<Statement*> * body);
	static Statement* CASE(Expr * cond, std::vector<Statement*>* body);
	static Statement* CASE(std::vector<Expr*> * cond, std::vector<Statement*>* body);		
	static Statement* RETURN(Expr * val);
	static Statement* RETURN();
	static Statement* ASSIG(Expr * dst, Expr * src);
	static Statement* WHILE(Expr * cond, std::vector<Statement*>* body);
	static Statement* FOR(std::vector<Expr*> * cond, std::vector<Statement*>* body);	
#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
	~Statement();
};
