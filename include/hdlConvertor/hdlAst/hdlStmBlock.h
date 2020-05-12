#pragma once

#include <vector>

#include <hdlConvertor/hdlAst/iHdlStatement.h>

namespace hdlConvertor {
namespace hdlAst {

enum HdlStmBlockJoinType {
    SEQ,  // sequential block
    PAR_JOIN,  // parallel block where we are waiting on all threads
    PAR_JOIN_ANY,  // parallel block where we are waiting on first finished thread
    PAR_JOIN_NONE,  // parallel block where we are are not waiting on any thread
};

/*
 * HDL AST node for block statement (begin-end in SV)
 * */
class HdlStmBlock: public iHdlStatement {
public:
	// [todo] rename to obs
	HdlStmBlockJoinType join_t;
	std::vector<std::unique_ptr<iHdlObj>> statements;

	HdlStmBlock();
	HdlStmBlock(std::vector<std::unique_ptr<iHdlObj>> &statements);
	HdlStmBlock(std::unique_ptr<iHdlObj> obj);
	virtual ~HdlStmBlock() override;
};

const char * HdlStmBlockJoinType_toString(HdlStmBlockJoinType o);

}
}
