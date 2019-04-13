#pragma once
#include "../hdlObjects/context.h"

class BaseHdlParser {
public:
	bool hierarchyOnly;
	Context * context;
	BaseHdlParser(Context * ctx, bool _hierarchyOnly);
	Context * getContext();
};
