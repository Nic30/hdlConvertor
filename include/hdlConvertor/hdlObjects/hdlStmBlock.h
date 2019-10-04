#pragma once

#include <vector>
#include <hdlConvertor/hdlObjects/iHdlStatement.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * HDL AST node for block statement (begin-end in SV)
 * */
class HdlStmBlock: public iHdlStatement {
public:
	std::vector<iHdlObj*> statements;
	HdlStmBlock(const std::vector<iHdlObj*> &statements);
	virtual ~HdlStmBlock() override;
};

}
}
