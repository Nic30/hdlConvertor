#pragma once
#include "../baseHdlParser/baseHdlParser.h"
#include "../SVParser/sv2012Parser.h"
#include "../notImplementedLogger.h"

using namespace sv;

class source_textParser : public BaseHdlParser {

	public:
		source_textParser(bool _hierarchyOnly);
		void visitSource_text(sv2012Parser::Source_textContext *ctx);
};
