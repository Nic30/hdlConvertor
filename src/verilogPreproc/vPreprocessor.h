
#pragma once

#include "antlr4-runtime.h"
#include "../vpp/vppLexer.h"
#include "../vpp/vppParser.h"
#include "../vpp/vppBaseListener.h"
#include "macroSymbol.h"
#include "macroPrototype.h"
#include <string>
#include <map>
#include <sys/stat.h>
#include "exception.h"

using namespace antlr4;

class vPreprocessor : public  vppBaseListener {

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

  		void enterDefine(vppParser::DefineContext * ctx);
  		void enterUndef(vppParser::UndefContext * ctx);

		void enterToken_id(vppParser::Token_idContext * ctx);

  		void exitIfdef_directive(vppParser::Ifdef_directiveContext * ctx);
  		void exitIfndef_directive(vppParser::Ifndef_directiveContext * ctx);

		void enterInclude(vppParser::IncludeContext * ctx);
};

std::string return_preprocessed(const std::string input_token,
		std::vector<std::string> &incdir,
		bool eraseDB);
