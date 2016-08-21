#include "baseHdlParser.h"

BaseHdlParser::BaseHdlParser(bool _hierarchyOnly) {
	context = new Context();
	hierarchyOnly = _hierarchyOnly;
}
Context * BaseHdlParser::getContext() {
	return context;
}
