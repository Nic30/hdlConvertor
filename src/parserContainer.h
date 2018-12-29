#pragma once

#include <iostream>
#include <fstream>
#include <functional>

#include "hdlObjects/context.h"
#include "syntaxErrorLogger.h"
#include "antlr4-runtime.h"

using namespace antlr4;

template<class antlrLexerT, class antlrParserT, class hdlParserT>
class ParserContainer {
	SyntaxErrorLogger * syntaxErrLogger;
	antlrLexerT * lexer;
	CommonTokenStream * tokens;
	antlrParserT * antlrParser;
	hdlParserT * hdlParser;

	void initParser(ANTLRInputStream &input) {
		// create a lexer that feeds off of input CharStream
		lexer = new antlrLexerT(&input);

		// create a buffer of tokens pulled from the lexer
		tokens = new CommonTokenStream(lexer);

		// create a parser that feeds off the tokens buffer
		antlrParser = new antlrParserT(tokens);

		antlrParser->removeErrorListeners();
		syntaxErrLogger = new SyntaxErrorLogger();
		antlrParser->addErrorListener(syntaxErrLogger);
	}
public:
	Context * context;
	void parseFile(
			ANTLRInputStream &fileName,
			bool hierarchyOnly,
			bool debug,
			std::function<
					void(
						antlrParserT * antlrParser,
						hdlParserT * hdlParser
					    )
				     > parseFn) {

		initParser(fileName);

		hdlParser = new hdlParserT(hierarchyOnly);

		// begin parsing at init rule
		parseFn(antlrParser, hdlParser);

		context = hdlParser->getContext();
		syntaxErrLogger->CheckErrors(); // Throw exception if errors
		delete hdlParser;
		delete syntaxErrLogger;
		delete antlrParser;
		delete tokens;
		delete lexer;

	}
};

