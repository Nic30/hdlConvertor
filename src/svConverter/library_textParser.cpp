#include "library_textParser.h"

Library_textParser::Library_textParser(bool _hierarchyOnly) : BaseHdlParser(_hierarchyOnly) {}

void Library_textParser::visitLibrary_text(sv2012Parser::Library_textContext * ctx) {
	NotImplementedLogger::print("visitLibrary_text");
}
