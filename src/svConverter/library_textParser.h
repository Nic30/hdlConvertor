#pragma once
#include "../baseHdlParser/baseHdlParser.h"
#include "../SVParser/sv2012Parser.h"
#include "../notImplementedLogger.h"

using namespace sv;

class Library_textParser: public BaseHdlParser {
public:
	Library_textParser(bool _hierarchyOnly);
	void visitLibrary_text(sv2012Parser::Library_textContext * ctx);
};
