#pragma once

#include <vector>
#include <memory>

#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/position.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>

namespace hdlConvertor {
namespace hdlObjects {

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

class HdlExprAndStm {
public:
	std::unique_ptr<iHdlExpr> expr;
	std::unique_ptr<iHdlStatement> stm;
	HdlExprAndStm();
	HdlExprAndStm(std::unique_ptr<iHdlExpr> expr,
			std::unique_ptr<iHdlStatement> stm);

};

}
}
