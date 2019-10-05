#pragma once

#include <vector>

#include <hdlConvertor/hdlObjects/iHdlStatement.h>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * HDL AST node for block statement (begin-end in SV)
 * */
class HdlStmBlock: public iHdlStatement {
public:
	std::vector<std::unique_ptr<iHdlObj>> statements;
	HdlStmBlock(std::vector<std::unique_ptr<iHdlObj>> &statements);
	virtual ~HdlStmBlock() override;
};

}
}
