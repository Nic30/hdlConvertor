
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

class vPreprocessor : public  verilogPreprocBaseListener {

		static macroSymbol _defineDB;
		CommonTokenStream * _tokens;
		std::vector<std::string> _incdir;
		static std::vector<std::string> _stack_incfile;
	public:
		TokenStreamRewriter * _rewriter;

		std::string genBlank(size_t n);

		vPreprocessor(TokenStream *tokens,
				std::vector<std::string> &incdir,
				bool eraseDB);
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
		bool eraseDB);
