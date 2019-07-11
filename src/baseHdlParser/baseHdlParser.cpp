#include <hdlConvertor/baseHdlParser/baseHdlParser.h>

namespace hdlConvertor {

using namespace hdlConvertor::hdlObjects;

BaseHdlParser::BaseHdlParser(antlr4::TokenStream* tokens, HdlContext * ctx, bool _hierarchyOnly) {
	if (ctx == nullptr)
		context = new HdlContext();
	else
		context = ctx;
	this->tokens = tokens;
	hierarchyOnly = _hierarchyOnly;
}
HdlContext * BaseHdlParser::getContext() {
	return context;
}

}
