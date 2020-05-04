#include <hdlConvertor/hdlAst/hdlStmBlock.h>

namespace hdlConvertor {
namespace hdlAst {

HdlStmBlock::HdlStmBlock() :
		iHdlStatement(), join_t(HdlStmBlockJoinType::SEQ) {
}

HdlStmBlock::HdlStmBlock(std::vector<std::unique_ptr<iHdlObj>> &_statements) :
		iHdlStatement(), join_t(HdlStmBlockJoinType::SEQ), statements(move(_statements)) {
}

HdlStmBlock::HdlStmBlock(std::unique_ptr<iHdlObj> obj) :
		HdlStmBlock() {
	statements.push_back(move(obj));
}

HdlStmBlock::~HdlStmBlock() {
}

const char* HdlStmBlockJoinType_toString(HdlStmBlockJoinType o) {
	switch (o) {
	case HdlStmBlockJoinType::SEQ:
		return "SEQ";
	case HdlStmBlockJoinType::PAR_JOIN:
		return "PAR_JOIN";
	case HdlStmBlockJoinType::PAR_JOIN_ANY:
		return "PAR_JOIN_ANY";
	case HdlStmBlockJoinType::PAR_JOIN_NONE:
		return "PAR_JOIN_NONE";
	default:
		throw std::runtime_error("invalid value for HdlStmBlockJoinType");
	}
}

}
}
