#include <hdlConvertor/baseHdlParser/baseHdlParser.h>

namespace hdlConvertor {

using namespace hdlConvertor::hdlAst;

BaseHdlParser::BaseHdlParser(antlr4::TokenStream &_tokens, HdlContext &ctx,
		bool _hierarchyOnly) :
		tokens(_tokens), context(ctx), hierarchyOnly(_hierarchyOnly) {
}

}
