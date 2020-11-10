#include <hdlConvertor/svConvertor/positionAwareParser.h>

namespace hdlConvertor {
namespace sv {

using namespace std;
using sv2017Parser = sv2017_antlr::sv2017Parser;
using namespace hdlConvertor::hdlAst;

VerPositionAwareParser::VerPositionAwareParser(SVCommentParser &_commentParser,
		bool _hierarchyOnly) :
		commentParser(_commentParser), hierarchyOnly(_hierarchyOnly) {
}

VerPositionAwareParser::VerPositionAwareParser(VerPositionAwareParser *other) :
		VerPositionAwareParser(other->commentParser, other->hierarchyOnly) {
}

}
}
