#pragma once
#include <vector>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/expr.h>
#include <hdlConvertor/hdlObjects/variable.h>
#include <hdlConvertor/hdlObjects/statement.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>

namespace hdlConvertor {
namespace hdlObjects {

// [TODO] add definition_only flag
class Function: public WithNameAndDoc, public iHdlObj {
public:
	const bool isOperator;
	const Expr * returnT;
	const std::vector<Variable*> * params;
	std::vector<Variable*> locals;
	std::vector<Statement*> body;

	Function(const std::string & name, bool isOperator, Expr * returnT,
			std::vector<Variable*> * params);
	~Function();
};

}
}
