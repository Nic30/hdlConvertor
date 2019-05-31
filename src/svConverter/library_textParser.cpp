#include "library_textParser.h"

using namespace sv2012_antlr;
using namespace hdlConvertor::hdlObjects;

namespace hdlConvertor {
namespace sv {

Library_textParser::Library_textParser(antlr4::TokenStream* tokens,
		Context * ctx, bool _hierarchyOnly) :
		BaseHdlParser(tokens, ctx, _hierarchyOnly) {
}

void Library_textParser::visitLibrary_text(
		sv2012Parser::Library_textContext * ctx) {
	NotImplementedLogger::print("visitLibrary_text");
}

}
}
