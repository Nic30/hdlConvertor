#include <hdlConvertor/svConvertor/baseSvParser.h>

namespace hdlConvertor {
namespace sv {

using namespace std;
using sv2017Parser = sv2017_antlr::sv2017Parser;
using namespace hdlConvertor::hdlAst;

BaseSvParser::BaseSvParser(SVCommentParser &_commentParser,
		bool _hierarchyOnly) :
		commentParser(_commentParser), hierarchyOnly(_hierarchyOnly) {
}

BaseSvParser::BaseSvParser(BaseSvParser *other) :
		BaseSvParser(other->commentParser, other->hierarchyOnly) {
}

}
}
