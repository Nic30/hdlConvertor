#include "baseHdlParser.h"

BaseHdlParser::BaseHdlParser(Context * ctx, bool _hierarchyOnly) {
	if (ctx == nullptr)
		context = new Context();
	else
		context = ctx;
	hierarchyOnly = _hierarchyOnly;
}
Context * BaseHdlParser::getContext() {
	return context;
}
