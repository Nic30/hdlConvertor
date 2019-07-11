#pragma once
#include <hdlConvertor/baseHdlParser/baseHdlParser.h>
#include <hdlConvertor/svConvertor/sv2012Parser/sv2012Parser.h>
#include <hdlConvertor/notImplementedLogger.h>

namespace hdlConvertor {
namespace sv {

class Library_textParser: public BaseHdlParser {
public:
	Library_textParser(antlr4::TokenStream* tokens, hdlObjects::HdlContext * ctx,
			bool _hierarchyOnly);
	void visitLibrary_text(sv2012_antlr::sv2012Parser::Library_textContext * ctx);
};

}
}
