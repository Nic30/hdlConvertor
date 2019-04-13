#pragma once
#include "../hdlObjects/context.h"
#include <antlr4-runtime.h>

class BaseHdlParser {
public:
	bool hierarchyOnly;
	Context * context;
	antlr4::TokenStream* tokens;
	BaseHdlParser(antlr4::TokenStream* tokens, Context * ctx, bool _hierarchyOnly);
	Context * getContext();
};
