#pragma once
#include <hdlConvertor/baseHdlParser/baseHdlParser.h>
#include <hdlConvertor/svConvertor/sv2012Parser/sv2012Parser.h>

namespace hdlConvertor {
namespace sv {

class source_textParser: public BaseHdlParser {
public:
	typedef sv2012_antlr::sv2012Parser sv2012Parser;
	source_textParser(antlr4::TokenStream* tokens, hdlObjects::HdlContext * ctx,
			bool _hierarchyOnly);
	void visitSource_text(sv2012Parser::Source_textContext *ctx);
};

}
}
