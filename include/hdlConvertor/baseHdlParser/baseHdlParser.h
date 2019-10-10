#pragma once

#include <antlr4-runtime.h>

#include <hdlConvertor/hdlObjects/hdlContext.h>

namespace hdlConvertor {

class BaseHdlParser {
public:
	antlr4::TokenStream &tokens;
	hdlObjects::HdlContext &context;
	bool hierarchyOnly;

	BaseHdlParser(antlr4::TokenStream &tokens, hdlObjects::HdlContext &ctx,
			bool _hierarchyOnly);
};

}
