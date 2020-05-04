#pragma once

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>

#include <hdlConvertor/baseHdlParser/baseHdlParser.h>

namespace hdlConvertor {
namespace sv {

class Source_textParser: public BaseHdlParser {
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;

	Source_textParser(antlr4::TokenStream &tokens, hdlAst::HdlContext &ctx,
			bool _hierarchyOnly);
	void visitSource_text(sv2017Parser::Source_textContext *ctx);
	void visitTimeunits_declaration(
			sv2017Parser::Timeunits_declarationContext *ctx);
	void visitDescription(sv2017Parser::DescriptionContext *ctx);
};

}
}
