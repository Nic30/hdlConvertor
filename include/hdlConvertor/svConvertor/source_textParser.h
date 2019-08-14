#pragma once
#include <hdlConvertor/baseHdlParser/baseHdlParser.h>
#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>

namespace hdlConvertor {
namespace sv {

class source_textParser: public BaseHdlParser {
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;
	source_textParser(antlr4::TokenStream* tokens, hdlObjects::HdlContext * ctx,
			bool _hierarchyOnly);
	void visitSource_text(sv2017Parser::Source_textContext *ctx);
};

}
}
