#pragma once
#include "../baseHdlParser/baseHdlParser.h"
#include "sv2012Parser/sv2012Parser.h"

namespace hdlConvertor {
namespace sv {

class source_textParser: public BaseHdlParser {
public:
	typedef sv2012_antlr::sv2012Parser sv2012Parser;
	source_textParser(antlr4::TokenStream* tokens, hdlObjects::Context * ctx,
			bool _hierarchyOnly);
	void visitSource_text(sv2012Parser::Source_textContext *ctx);
};

}
}
