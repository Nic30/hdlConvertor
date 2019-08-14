#include <hdlConvertor/svConvertor/library_textParser.h>


namespace hdlConvertor {
namespace sv {

using namespace sv2017_antlr;
using namespace hdlConvertor::hdlObjects;

Library_textParser::Library_textParser(antlr4::TokenStream* tokens,
		HdlContext * ctx, bool _hierarchyOnly) :
		BaseHdlParser(tokens, ctx, _hierarchyOnly) {
}

void Library_textParser::visitLibrary_text(
		sv2017Parser::Library_textContext * ctx) {
	NotImplementedLogger::print("visitLibrary_text", ctx);
}

}
}
