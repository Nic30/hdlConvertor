#pragma once
#include "../hdlObjects/context.h"
#include <antlr4-runtime.h>

namespace hdlConvertor {

class BaseHdlParser {
public:
	bool hierarchyOnly;
	hdlObjects::Context * context;
	antlr4::TokenStream* tokens;
	BaseHdlParser(antlr4::TokenStream* tokens, hdlObjects::Context * ctx,
			bool _hierarchyOnly);
	hdlObjects::Context * getContext();
};

}
