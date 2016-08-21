#pragma once
#include "../hdlObjects/context.h"

class BaseHdlParser {
public:
	bool hierarchyOnly;
	Context * context;
	BaseHdlParser(bool _hierarchyOnly);
	Context * getContext();
};
