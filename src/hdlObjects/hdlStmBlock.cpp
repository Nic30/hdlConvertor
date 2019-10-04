#include <hdlConvertor/hdlObjects/hdlStmBlock.h>
#include <stdexcept>

namespace hdlConvertor {
namespace hdlObjects {

HdlStmBlock::HdlStmBlock(const std::vector<iHdlObj*> &_statements) :
		iHdlStatement(StatementType::s_BLOCK), statements(_statements) {
}

HdlStmBlock::~HdlStmBlock() {
	for (auto stm : statements) {
		delete stm;
	}
}
}
}
