#include "library_textParser.h"

Library_textParser::Library_textParser(Context * ctx, bool _hierarchyOnly) : BaseHdlParser(ctx, _hierarchyOnly) {}

void Library_textParser::visitLibrary_text(sv2012Parser::Library_textContext * ctx) {
	NotImplementedLogger::print("visitLibrary_text");
}
