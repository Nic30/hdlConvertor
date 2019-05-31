#pragma once

#include <string>
#include <map>
#include <sys/stat.h>
#include <typeinfo>

#include "verilogPreprocParser/verilogPreprocLexer.h"
#include "verilogPreprocParser/verilogPreprocParser.h"
#include "verilogPreprocParser/verilogPreprocParserBaseVisitor.h"

#include "macroPrototype.h"
#include "macroSymbol.h"
#include "exception.h"

#include "../syntaxErrorLogger.h"

namespace hdlConvertor {
namespace verilog_pp {

/*
 * Verilog preprocessor
 * :ivar _defineDB: database of defines
 * :ivar _incdir: directories where to search for included files (last will be searched first)
 * :ivar _stack_incfile: stack of include files which are currently parsed (used for detection of cycle in includes)
 **/
class vPreprocessor: public verilogPreprocParserBaseVisitor {
	macroSymbol & _defineDB;
	antlr4::CommonTokenStream * _tokens;
	std::vector<std::string> _incdir;
	std::vector<std::string> & _stack_incfile;
	unsigned int _mode = VERILOG2001;

	void remove_comment(antlr4::Token * start, antlr4::Token * end,
			std::string * str);
	std::string genBlank(size_t n);
	void replace_context_by_bank(antlr4::ParserRuleContext * ctx);

public:
	enum {
		VERILOG2001, VERILOG2005, SV2012
	};
	size_t include_depth_limit;
	antlr4::TokenStreamRewriter _rewriter;

	vPreprocessor(antlr4::TokenStream *tokens, std::vector<std::string> &incdir,
			macroSymbol & defineDB, std::vector<std::string> &stack_incfile,
			unsigned int mode = VERILOG2001, size_t include_depth_limit = 100);
	virtual ~vPreprocessor();

	virtual antlrcpp::Any visitResetall(
			verilogPreprocParser::ResetallContext * ctx);
	virtual antlrcpp::Any visitCelldefine(
			verilogPreprocParser::CelldefineContext * ctx);
	virtual antlrcpp::Any visitEndcelldefine(
			verilogPreprocParser::EndcelldefineContext * ctx);

	virtual antlrcpp::Any visitTiming_spec(
			verilogPreprocParser::Timing_specContext * ctx);
	virtual antlrcpp::Any visitDefault_nettype(
			verilogPreprocParser::Default_nettypeContext * ctx);
	virtual antlrcpp::Any visitUnconnected_drive(
			verilogPreprocParser::Unconnected_driveContext * ctx);
	virtual antlrcpp::Any visitNounconnected_drive(
			verilogPreprocParser::Nounconnected_driveContext * ctx);
	virtual antlrcpp::Any visitLine_directive(
			verilogPreprocParser::Line_directiveContext * ctx);

	virtual antlrcpp::Any visitDefine(
			verilogPreprocParser::DefineContext * ctx);
	virtual antlrcpp::Any visitUndef(verilogPreprocParser::UndefContext * ctx);

	virtual antlrcpp::Any visitToken_id(
			verilogPreprocParser::Token_idContext * ctx);

	virtual antlrcpp::Any visitIfdef_directive(
			verilogPreprocParser::Ifdef_directiveContext * ctx);
	virtual antlrcpp::Any visitIfndef_directive(
			verilogPreprocParser::Ifndef_directiveContext * ctx);

	virtual antlrcpp::Any visitStringLiteral(
			verilogPreprocParser::StringLiteralContext *ctx);
	virtual antlrcpp::Any visitInclude(
			verilogPreprocParser::IncludeContext * ctx);

	virtual antlrcpp::Any visitKeywords_directive(
			verilogPreprocParser::Keywords_directiveContext * ctx);
	virtual antlrcpp::Any visitEndkeywords_directive(
			verilogPreprocParser::Endkeywords_directiveContext * ctx);

	virtual antlrcpp::Any visitPragma(
			verilogPreprocParser::PragmaContext * ctx);

	virtual antlrcpp::Any visitUndefineall(
			verilogPreprocParser::UndefineallContext * ctx);

	virtual antlrcpp::Any visitFile_nb(
			verilogPreprocParser::File_nbContext * ctx);
	virtual antlrcpp::Any visitLine_nb(
			verilogPreprocParser::Line_nbContext * ctx);

};

//call the preprocessor tool.
//argument are
// a string token
// a list of include directory (std::vector<std::string>)
// a object representing the list of already defined macro
std::string return_preprocessed(const std::string input_token,
		std::vector<std::string> &incdir, macroSymbol & defineDB,
		std::vector<std::string> & stack_incfile, unsigned int mode = 0);

std::string return_preprocessed_file(const std::string fileName,
		std::vector<std::string> &incdir, macroSymbol & defineDB,
		std::vector<std::string> & stack_incfile, unsigned int mode = 0);

std::string& rtrim(std::string& str, const std::string& chars = " \t\n\r");
std::string& ltrim(std::string& str, const std::string& chars = " \t\n\r");
std::string& trim(std::string& str, const std::string& chars = " \t\n\r");

}
}
