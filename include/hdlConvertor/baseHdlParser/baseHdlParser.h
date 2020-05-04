#pragma once

#include <antlr4-runtime.h>

#include <hdlConvertor/hdlAst/hdlContext.h>

namespace hdlConvertor {

class BaseHdlParser {
public:
	antlr4::TokenStream &tokens;
	hdlAst::HdlContext &context;
	bool hierarchyOnly;

	BaseHdlParser(antlr4::TokenStream &tokens, hdlAst::HdlContext &ctx,
			bool _hierarchyOnly);
};

}
