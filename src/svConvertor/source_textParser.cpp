#include <hdlConvertor/svConvertor/source_textParser.h>

#include <hdlConvertor/notImplementedLogger.h>


namespace hdlConvertor {
namespace sv {

using namespace hdlConvertor::hdlObjects;

source_textParser::source_textParser(antlr4::TokenStream* tokens, HdlContext * ctx,
		bool _hierarchyOnly) :
		BaseHdlParser(tokens, ctx, _hierarchyOnly) {
}

void source_textParser::visitSource_text(
		sv2012Parser::Source_textContext *ctx) {
	NotImplementedLogger::print("visitLibrary_text", ctx);
}

}
}
