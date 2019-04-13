#pragma once
#include "../baseHdlParser/baseHdlParser.h"
#include "sv2012Parser/sv2012Parser.h"
#include "../notImplementedLogger.h"

using namespace sv2012;

class Library_textParser: public BaseHdlParser {
public:
	Library_textParser(antlr4::TokenStream* tokens, Context * ctx, bool _hierarchyOnly);
	void visitLibrary_text(sv2012Parser::Library_textContext * ctx);
};
