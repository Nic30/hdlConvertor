#pragma once

#include <antlr4-runtime.h>

#include <hdlConvertor/hdlObjects/hdlContext.h>

namespace hdlConvertor {

class BaseHdlParser {
public:
	bool hierarchyOnly;
	hdlObjects::HdlContext * context;
	antlr4::TokenStream* tokens;
	BaseHdlParser(antlr4::TokenStream* tokens, hdlObjects::HdlContext * ctx,
			bool _hierarchyOnly);
	hdlObjects::HdlContext * getContext();
};

}
