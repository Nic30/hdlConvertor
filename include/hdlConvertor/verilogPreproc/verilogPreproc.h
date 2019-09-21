#pragma once

#include <string>
#include <map>
#include <sys/stat.h>
#include <typeinfo>

#include <hdlConvertor/verilogPreproc/verilogPreprocParser/verilogPreprocLexer.h>
#include <hdlConvertor/verilogPreproc/verilogPreprocParser/verilogPreprocParser.h>
#include <hdlConvertor/verilogPreproc/verilogPreprocParser/verilogPreprocParserBaseVisitor.h>

#include <hdlConvertor/verilogPreproc/verilogPreprocContainer.h>
#include <hdlConvertor/conversion_exception.h>

namespace hdlConvertor {
namespace verilog_pp {

/*
 * Verilog preprocessor
 *
 * :ivar _defineDB: database of defines
 * :ivar _incdir: directories where to search for included files
 * 		    (last will be searched first, unique items)
 * :ivar added_incdir: true if the new incdir was added exactly for this file
 * 			and last incdir should be removed before processing of new file
 * :ivar _stack_incfile: stack of include files which are
 * 			currently parsed (used for detection of cycle in includes)
 * :ivar did_added_incdir: the flag which tells if the directory of this folder
 * 			was added to include directories and thus should be removed after parser ends
 **/
class VerilogPreproc: public verilogPreproc_antlr::verilogPreprocParserBaseVisitor {

	void remove_comment(antlr4::Token *start, antlr4::Token *end,
			std::string *str);
	void replace_context_by_bank(antlr4::ParserRuleContext *ctx);

public:
	using verilogPreprocParser = verilogPreproc_antlr::verilogPreprocParser;
	VerilogPreprocContainer &container;
	antlr4::CommonTokenStream &_tokens;
	bool added_incdir;
	size_t include_depth_limit;
	antlr4::TokenStreamRewriter _rewriter;

	VerilogPreproc(VerilogPreprocContainer &container,
			antlr4::TokenStream &tokens, bool added_incdir,
			size_t include_depth_limit = 100);

	virtual ~VerilogPreproc();

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

std::string& rtrim(std::string &str, const std::string &chars = " \t\n\r");
std::string& ltrim(std::string &str, const std::string &chars = " \t\n\r");
std::string& trim(std::string &str, const std::string &chars = " \t\n\r");

}
}
