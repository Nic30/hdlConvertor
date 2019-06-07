#include <hdlConvertor/baseHdlParser/baseHdlParser.h>

namespace hdlConvertor {

using namespace hdlConvertor::hdlObjects;

BaseHdlParser::BaseHdlParser(antlr4::TokenStream* tokens, Context * ctx, bool _hierarchyOnly) {
	if (ctx == nullptr)
		context = new Context();
	else
		context = ctx;
	this->tokens = tokens;
	hierarchyOnly = _hierarchyOnly;
}
Context * BaseHdlParser::getContext() {
	return context;
}

}
