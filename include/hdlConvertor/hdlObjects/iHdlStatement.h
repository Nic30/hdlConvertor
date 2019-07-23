#pragma once

#include <vector>

#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/position.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>

namespace hdlConvertor {
namespace hdlObjects {

// @note the NOP statement is not required as it is represented by empty statement list
enum StatementType {
	s_EXPR,
	s_IF,
	s_CASE,
	s_WHILE,
	s_BREAK,
	s_RETURN,
	s_CONTINUE,
	s_FOR,
	s_FOR_IN,
	s_ASSIGNMENT,
	s_PROCESS,
	s_WAIT,
	s_IMPORT,
};

const char * StatementType_toString(StatementType type);
/*
 * Interface for statements which can appear in HDL AST
 *
 * [TODO] to separate classes
 *        iHdlStatement is not an interface yet but it is planed to make it an interface
 */
class iHdlStatement: public WithDoc, public WithPos, public iHdlObj {
public:
	using case_t = std::pair<iHdlExpr*, std::vector<iHdlObj*>*>;
	// an optional extra label specified in HDL
	std::vector<std::string> labels;
	StatementType type;
	std::vector<std::vector<iHdlObj*> *> sub_statements;
	/*
	 * for EXPR exprs contains only one item which is this value
	 * for IF exprs containst the main condition and conditions from the else ifs
	 * for CASE the first is the value of the switch the rest are values of the cases
	 * for RETURN exprs contains (optionaly) the return value
	 * for ASSIG exprs contains dst, src in this order
	 * for WHILE exprs contains the condition
	 * for PROCESS exprs contains the sensitivity list items, if sensitivity is not specified the re is only one time nullptr
	 */
	std::vector<iHdlExpr *> exprs;
	// if true the statement is part of VHDL generate or other compile time evaluated statement
	bool in_preproc;

	iHdlStatement(StatementType type);
	static iHdlStatement* EXPR(iHdlExpr * e);
	static iHdlStatement* IMPORT(const std::vector<iHdlExpr *> & path);
	static iHdlStatement* IF(iHdlExpr* cond, std::vector<iHdlObj*>* ifTrue);
	static iHdlStatement* IF(iHdlExpr* cond,
			std::vector<iHdlStatement*>* ifTrue);
	static iHdlStatement* IF(iHdlExpr* cond, std::vector<iHdlObj*>* ifTrue,
			std::vector<iHdlObj*>* ifFalse);
	static iHdlStatement* IF(iHdlExpr* cond,
			std::vector<iHdlStatement*>* ifTrue,
			std::vector<iHdlStatement*>* ifFalse);
	static iHdlStatement* IF(iHdlExpr* cond, std::vector<iHdlObj*>* ifTrue,
			const std::vector<case_t> & elseIfs,
			std::vector<iHdlObj*>* ifFalse);
	static iHdlStatement* IF(iHdlExpr* cond,
			std::vector<iHdlStatement*>* ifTrue,
			const std::vector<std::pair<iHdlExpr*, std::vector<iHdlStatement*>*>> & elseIfs,
			std::vector<iHdlStatement*>* ifFalse);
	static iHdlStatement* CASE(iHdlExpr* switchOn,
			const std::vector<case_t> cases, std::vector<iHdlObj*>* default_);
	static iHdlStatement* RETURN(iHdlExpr* val);
	static iHdlStatement* RETURN();
	static iHdlStatement* WAIT(const std::vector<iHdlExpr*> & val);
	static iHdlStatement* WHILE(iHdlExpr* cond,
			std::vector<iHdlStatement*>* body);
	static iHdlStatement* WHILE(iHdlExpr* cond, std::vector<iHdlObj*>* body);
	static iHdlStatement* BREAK();
	static iHdlStatement* CONTINUE();
	static iHdlStatement* FOR(iHdlStatement* init, iHdlExpr* cond,
			iHdlStatement* step, std::vector<iHdlObj*>* body);
	static iHdlStatement* FOR(iHdlStatement* init, iHdlExpr* cond,
			iHdlStatement* step, std::vector<iHdlStatement*>* body);
	static iHdlStatement* FOR_IN(iHdlStatement* var, iHdlExpr *collection,
			std::vector<iHdlObj*>* body);
	static iHdlStatement* FOR_IN(iHdlExpr* _var, iHdlExpr *collection,
			std::vector<iHdlObj*>* body);
	virtual ~iHdlStatement() override;
};

}
}
