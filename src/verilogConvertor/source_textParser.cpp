#include <hdlConvertor/verilogConvertor/source_textParser.h>

#include <hdlConvertor/verilogConvertor/commentParser.h>
#include <hdlConvertor/verilogConvertor/moduleParser.h>
#include <hdlConvertor/notImplementedLogger.h>

namespace hdlConvertor {
namespace verilog {

using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;
using namespace hdlConvertor::hdlObjects;

Source_textParser::Source_textParser(antlr4::TokenStream* tokens,
		HdlContext * ctx, bool _hierarchyOnly) :
		BaseHdlParser(tokens, ctx, _hierarchyOnly) {
}

void Source_textParser::visitSource_text(
		Verilog2001Parser::Source_textContext* ctx) {
	//// START SYMBOL
	// source_text : timing_spec? description* EOF ;
	if (!hierarchyOnly) {
		auto t = ctx->timing_spec();
		if (t)
			visitTiming_spec(t);
	}
	for (auto d : ctx->description()) {
		visitDescription(d);
	}
}
void Source_textParser::visitTiming_spec(
		Verilog2001Parser::Timing_specContext* ctx) {
	// timing_spec : '`timescale' Time_Identifier '/' Time_Identifier;
	NotImplementedLogger::print("Source_textParser.visitTiming_spec", ctx);
}
void Source_textParser::visitDescription(
		Verilog2001Parser::DescriptionContext* ctx) {
	// description : module_declaration ;
	CommentParser cp(tokens);
	ModuleParser p(cp, context, hierarchyOnly);
	p.visitModule_declaration(ctx->module_declaration());
}

}
}
