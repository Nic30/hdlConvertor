#include <hdlConvertor/hdlObjects/hdlStmBlock.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlStmBlock::HdlStmBlock() :
		iHdlStatement() {
}

HdlStmBlock::HdlStmBlock(std::vector<std::unique_ptr<iHdlObj>> &_statements) :
		iHdlStatement(), statements(move(_statements)) {
}

HdlStmBlock::HdlStmBlock(std::unique_ptr<iHdlObj> obj) :
		iHdlStatement() {
	statements.push_back(move(obj));
}

HdlStmBlock::~HdlStmBlock() {
}

}
}
