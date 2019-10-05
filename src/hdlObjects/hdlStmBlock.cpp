#include <hdlConvertor/hdlObjects/hdlStmBlock.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlStmBlock::HdlStmBlock(std::vector<std::unique_ptr<iHdlObj>> &_statements) :
		iHdlStatement(), statements(move(_statements)) {
}

HdlStmBlock::~HdlStmBlock() {
}

}
}
