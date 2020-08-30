#pragma once

#include <string>
#include <map>
#include <sys/stat.h>
#include <typeinfo>

// antlr4-runtime/
#include <CommonTokenStream.h>
#include <TokenStream.h>
#include <support/Any.h>

#include <hdlConvertor/verilogPreproc/verilogPreprocParser/verilogPreprocLexer.h>
#include <hdlConvertor/verilogPreproc/verilogPreprocParser/verilogPreprocParser.h>
#include <hdlConvertor/verilogPreproc/verilogPreprocParser/verilogPreprocParserBaseVisitor.h>

#include <hdlConvertor/verilogPreproc/verilogPreprocContainer.h>
#include <hdlConvertor/verilogPreproc/out_buffer.h>
#include <hdlConvertor/verilogPreproc/str_utils.h>
#include <hdlConvertor/conversion_exception.h>

namespace hdlConvertor {
namespace verilog_pp {

/*
 * Verilog preprocessor
 *
 * :ivar added_incdir: true if the new incdir was added exactly for this file
 * 			and last incdir should be removed before processing of new file
 * :ivar preproc_out: output stream where output should be put
 **/
class VerilogPreproc: public verilogPreproc_antlr::verilogPreprocParserBaseVisitor {

	void remove_comment(antlr4::Token *start, antlr4::Token *end,
			std::string *str);
public:
	using verilogPreprocParser = verilogPreproc_antlr::verilogPreprocParser;
	VerilogPreprocContainer &container;
	antlr4::CommonTokenStream &_tokens;
	bool added_incdir;
	size_t include_depth_limit;
	VerilogPreprocOutBuffer &preproc_out;
	const std::string encoding;

	VerilogPreproc(VerilogPreprocContainer &container,
			VerilogPreprocOutBuffer &preproc_out, antlr4::TokenStream &tokens,
			bool added_incdir, const std::string encoding,
			size_t include_depth_limit = 100);

	virtual ~VerilogPreproc();

	virtual antlrcpp::Any visitText(verilogPreprocParser::TextContext *ctx)
			override;
	virtual antlrcpp::Any visitResetall(
			verilogPreprocParser::ResetallContext *ctx) override;
	virtual antlrcpp::Any visitCelldefine(
			verilogPreprocParser::CelldefineContext *ctx) override;
	virtual antlrcpp::Any visitEndcelldefine(
			verilogPreprocParser::EndcelldefineContext *ctx) override;

	virtual antlrcpp::Any visitTiming_spec(
			verilogPreprocParser::Timing_specContext *ctx) override;
	virtual antlrcpp::Any visitDefault_nettype(
			verilogPreprocParser::Default_nettypeContext *ctx) override;
	virtual antlrcpp::Any visitUnconnected_drive(
			verilogPreprocParser::Unconnected_driveContext *ctx) override;
	virtual antlrcpp::Any visitNounconnected_drive(
			verilogPreprocParser::Nounconnected_driveContext *ctx) override;
	virtual antlrcpp::Any visitLine_directive(
			verilogPreprocParser::Line_directiveContext *ctx) override;

	virtual antlrcpp::Any visitDefine_args_with_def_val(
			verilogPreprocParser::Define_args_with_def_valContext *ctx)
					override;
	virtual antlrcpp::Any visitDefine_args_basic(
			verilogPreprocParser::Define_args_basicContext *ctx) override;
	virtual antlrcpp::Any visitDefine(verilogPreprocParser::DefineContext *ctx)
			override;

	virtual antlrcpp::Any visitUndef(verilogPreprocParser::UndefContext *ctx)
			override;
	virtual antlrcpp::Any visitUndefineall(
			verilogPreprocParser::UndefineallContext *ctx) override;

	void parse_macro_args(verilogPreprocParser::Macro_callContext *ctx,
			std::vector<std::string> &args);
	// :param add_to_output: tells if result should be added to output stream
	//        or only returned
	virtual antlrcpp::Any visitMacro_call(
			verilogPreprocParser::Macro_callContext *ctx, bool add_to_output);
	virtual antlrcpp::Any visitMacro_call(
			verilogPreprocParser::Macro_callContext *ctx) override;

	virtual antlrcpp::Any visitIfdef_directive(
			verilogPreprocParser::Ifdef_directiveContext *ctx) override;
	virtual antlrcpp::Any visitIfndef_directive(
			verilogPreprocParser::Ifndef_directiveContext *ctx) override;

	virtual antlrcpp::Any visitInclude(
			verilogPreprocParser::IncludeContext *ctx) override;

	virtual antlrcpp::Any visitKeywords_directive(
			verilogPreprocParser::Keywords_directiveContext *ctx) override;
	virtual antlrcpp::Any visitEndkeywords_directive(
			verilogPreprocParser::Endkeywords_directiveContext *ctx) override;

	virtual antlrcpp::Any visitPragma(verilogPreprocParser::PragmaContext *ctx)
			override;

	// thorw an error with a file location prompt
	void throw_input_caused_error(antlr4::ParserRuleContext *ctx,
			const std::string &msg);
};

}
}
