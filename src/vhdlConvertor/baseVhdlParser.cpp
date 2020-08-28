#include <hdlConvertor/vhdlConvertor/baseVhdlParser.h>

namespace hdlConvertor {
namespace vhdl {

BaseVhdlParser::BaseVhdlParser(VhdlCommentParser &_commentParser,
		bool _hierarchyOnly) :
		commentParser(_commentParser), hierarchyOnly(_hierarchyOnly) {
}
BaseVhdlParser::BaseVhdlParser(BaseVhdlParser &parent) :
		commentParser(parent.commentParser), hierarchyOnly(parent.hierarchyOnly) {
}

}
}
