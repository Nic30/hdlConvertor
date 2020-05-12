#pragma once

#include <vector>
#include <memory>

#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/hdlAst/named.h>
#include <hdlConvertor/hdlAst/iHdlObj.h>
#include <hdlConvertor/hdlAst/codePosition.h>

namespace hdlConvertor {
namespace hdlAst {

/*
 * Interface for statements which can appear in HDL AST
 *
 * [TODO] to separate classes
 *        iHdlStatement is not an interface yet but it is planed to make it an interface
 */
class iHdlStatement: public WithDoc, public WithPos, public iHdlObj {
public:

	// an optional extra label specified in HDL
	std::vector<std::string> labels;
	// if true the statement is part of VHDL generate or other compile time evaluated statement
	bool in_preproc;

	iHdlStatement();
	virtual ~iHdlStatement() override;
};

class HdlExprAndiHdlObj {
public:
	std::unique_ptr<iHdlExprItem> expr;
	std::unique_ptr<iHdlObj> obj;
	HdlExprAndiHdlObj();
	HdlExprAndiHdlObj(std::unique_ptr<iHdlExprItem> expr,
			std::unique_ptr<iHdlObj> stm);

};

}
}
