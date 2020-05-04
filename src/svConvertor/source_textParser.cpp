#include <hdlConvertor/svConvertor/source_textParser.h>

#include <hdlConvertor/svConvertor/commentParser.h>
#include <hdlConvertor/svConvertor/moduleParser.h>
#include <hdlConvertor/notImplementedLogger.h>

namespace hdlConvertor {
namespace sv {

using sv2017Parser = sv2017_antlr::sv2017Parser;
using namespace hdlConvertor::hdlAst;

Source_textParser::Source_textParser(antlr4::TokenStream &tokens,
		HdlContext &ctx, bool _hierarchyOnly) :
		BaseHdlParser(tokens, ctx, _hierarchyOnly) {
}

void Source_textParser::visitSource_text(
		sv2017Parser::Source_textContext *ctx) {
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
		sv2017Parser::Timeunits_declarationContext *ctx) {
	// timeunits_declaration:
	//  KW_TIMEUNIT TIME_LITERAL ( ( DIV
	//                               | SEMI KW_TIMEPRECISION
	//                               ) TIME_LITERAL )? SEMI
	//   | KW_TIMEPRECISION TIME_LITERAL SEMI ( KW_TIMEUNIT TIME_LITERAL SEMI )?
	//  ;
	NotImplementedLogger::print("Source_textParser.visitTimeunits_declaration",
			ctx);
}
void Source_textParser::visitDescription(
		sv2017Parser::DescriptionContext *ctx) {
	// description:
	//    module_declaration
	//    | udp_declaration
	//    | interface_declaration
	//    | program_declaration
	//    | package_declaration
	//    | ( attribute_instance )* ( package_item | bind_directive )
	//    | config_declaration
	// ;

	SVCommentParser cp(tokens);
	VerModuleParser p(cp, hierarchyOnly);
	{
		auto o = ctx->module_declaration();
		if (o) {
			p.visitModule_declaration(o, context.objs);
			return;
		}
	}
	{
		auto o = ctx->udp_declaration();
		if (o) {
			NotImplementedLogger::print(
					"Source_textParser.visitDescription.udp_declaration", o);
			return;
		}
	}
	{
		auto o = ctx->interface_declaration();
		if (o) {
			NotImplementedLogger::print(
					"Source_textParser.visitDescription.interface_declaration",
					o);
			return;
		}
	}
	{
		auto o = ctx->program_declaration();
		if (o) {
			NotImplementedLogger::print(
					"Source_textParser.visitDescription.program_declaration",
					o);
			return;
		}
	}
	{
		auto o = ctx->package_declaration();
		if (o) {
			NotImplementedLogger::print(
					"Source_textParser.visitDescription.package_declaration",
					o);
			return;
		}
	}
	{
		auto o = ctx->package_item();
		if (o) {
			NotImplementedLogger::print(
					"Source_textParser.visitDescription.package_item", o);
			return;
		}
	}
	{
		auto o = ctx->bind_directive();
		if (o) {
			NotImplementedLogger::print(
					"Source_textParser.visitDescription.bind_directive", o);
			return;
		}
	}
	auto o = ctx->config_declaration();
	assert(o);
	NotImplementedLogger::print(
			"Source_textParser.visitDescription.config_declaration", o);
}

}
}
