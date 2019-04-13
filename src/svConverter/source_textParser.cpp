#include "source_textParser.h"

source_textParser::source_textParser(antlr4::TokenStream* tokens, Context * ctx,
		bool _hierarchyOnly) :
		BaseHdlParser(tokens, ctx, _hierarchyOnly) {
}

void source_textParser::visitSource_text(
		sv2012Parser::Source_textContext *ctx) {
	NotImplementedLogger::print("visitLibrary_text");
}
