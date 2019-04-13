
#pragma once

#include "antlr4-runtime.h"
#include "verilogPreprocParser/verilogPreprocLexer.h"
#include "verilogPreprocParser/verilogPreprocParser.h"
#include "verilogPreprocParser/verilogPreprocBaseListener.h"
#include <string>
#include <map>
#include <sys/stat.h>

#include "../verilogPreproc/macroPrototype.h"
#include "../verilogPreproc/macroSymbol.h"
#include "exception.h"

using namespace antlr4;


/*
 * Verilog preprocessor
 * :ivar _defineDB: database of defines
 * :ivar _incdir: directories where to search for included files (last will be searched first)
 * :ivar _stack_incfile: stack of include files which are currently parsed (used for detection of cycle in includes)
 **/
class vPreprocessor : public  verilogPreprocBaseListener {
		macroSymbol & _defineDB;
		CommonTokenStream * _tokens;
		std::vector<std::string> _incdir;
		std::vector<std::string> _stack_incfile;
	public:
		size_t include_depth_limit;
		TokenStreamRewriter _rewriter;

		std::string genBlank(size_t n);

		vPreprocessor(TokenStream *tokens,
				std::vector<std::string> &incdir,
				macroSymbol & defineDB,
				size_t include_depth_limit=100);
		~vPreprocessor();

  		void enterDefine(verilogPreprocParser::DefineContext * ctx);
  		void enterUndef(verilogPreprocParser::UndefContext * ctx);

		void enterToken_id(verilogPreprocParser::Token_idContext * ctx);

  		void exitIfdef_directive(verilogPreprocParser::Ifdef_directiveContext * ctx);
  		void exitIfndef_directive(verilogPreprocParser::Ifndef_directiveContext * ctx);

		void enterInclude(verilogPreprocParser::IncludeContext * ctx);
};

std::string return_preprocessed(const std::string input_token,
		std::vector<std::string> &incdir,
		macroSymbol & defineDB);
