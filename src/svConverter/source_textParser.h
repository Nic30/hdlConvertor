#pragma once
#include "../baseHdlParser/baseHdlParser.h"
#include "sv2012Parser/sv2012Parser.h"
#include "../notImplementedLogger.h"

using namespace sv2012;

class source_textParser : public BaseHdlParser {

	public:
		source_textParser(Context * ctx, bool _hierarchyOnly);
		void visitSource_text(sv2012Parser::Source_textContext *ctx);
};
