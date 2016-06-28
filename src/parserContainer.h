#pragma once

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <functional>

#include "hdlObjects/context.h"
#include "antlr4-runtime.h"

using namespace antlr4;
using namespace vhdl;

enum ParserErrors {
	PERR_OK = 0, PERR_FILE
};

inline bool file_exists(const char * name) {
	if (FILE *file = fopen(name, "r")) {
		fclose(file);
		return true;
	} else {
		return false;
	}
}

template<class antlrLexerT, class antlrParserT, class hdlParserT>
class ParserContainer {
	ANTLRErrorListener * syntaxErrLogger;
	antlrLexerT * lexer;
	CommonTokenStream * tokens;
	antlrParserT * antlrParser;
	hdlParserT * hdlParser;

	void initParser(ANTLRFileStream * input) {
		// create a lexer that feeds off of input CharStream
		lexer = new antlrLexerT(input);

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
	ParserErrors parseFile(
			const char * fileName,
			bool hierarchyOnly,
			bool debug,
			std::function<
					void(antlrParserT * antlrParser, hdlParserT * hdlParser)> parseFn) {
		// create a CharStream that reads from standard input
		if (!file_exists(fileName))
			return PERR_FILE;

		ANTLRFileStream * input = new ANTLRFileStream(fileName);
		initParser(input);

		hdlParser = new hdlParserT(hierarchyOnly);

		// begin parsing at init rule
		parseFn(antlrParser, hdlParser);

		context = hdlParser->getContext();
		delete hdlParser;
		delete syntaxErrLogger;
		delete antlrParser;
		delete tokens;
		delete lexer;
		delete input;

		return PERR_OK;
	}
};
