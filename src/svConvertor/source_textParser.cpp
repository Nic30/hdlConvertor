#include <hdlConvertor/svConvertor/source_textParser.h>

#include <hdlConvertor/svConvertor/commentParser.h>
#include <hdlConvertor/svConvertor/moduleParser.h>
#include <hdlConvertor/notImplementedLogger.h>

namespace hdlConvertor {
namespace sv {

using sv2017Parser = sv2017_antlr::sv2017Parser;
using namespace hdlConvertor::hdlObjects;

Source_textParser::Source_textParser(antlr4::TokenStream* tokens,
		HdlContext * ctx, bool _hierarchyOnly) :
		BaseHdlParser(tokens, ctx, _hierarchyOnly) {
}

void Source_textParser::visitSource_text(
		sv2017Parser::Source_textContext* ctx) {
	// /* The start rule */
	// source_text:
	//  ( timeunits_declaration )? ( description )* EOF;
	if (!hierarchyOnly) {
		auto t = ctx->timeunits_declaration();
		if (t)
			visitTimeunits_declaration(t);
	}
	for (auto d : ctx->description()) {
		visitDescription(d);
	}
}
void Source_textParser::visitTimeunits_declaration(
		sv2017Parser::Timeunits_declarationContext* ctx) {
	// timeunits_declaration:
	//  KW_TIMEUNIT TIME_LITERAL ( ( DIV
	//                               | SEMI KW_TIMEPRECISION
	//                               ) TIME_LITERAL )? SEMI
	//   | KW_TIMEPRECISION TIME_LITERAL SEMI ( KW_TIMEUNIT TIME_LITERAL SEMI )?
	//  ;
	NotImplementedLogger::print("Source_textParser.visitTimeunits_declaration", ctx);
}
void Source_textParser::visitDescription(
		sv2017Parser::DescriptionContext* ctx) {
	// description : module_declaration ;
	SVCommentParser cp(tokens);
	ModuleParser p(cp, context, hierarchyOnly);
	p.visitModule_declaration(ctx->module_declaration());
}

}
}
