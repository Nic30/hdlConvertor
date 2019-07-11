#pragma once

#include <iostream>
#include <fstream>
#include <functional>

#include <antlr4-runtime.h>

#include <hdlConvertor/hdlObjects/hdlContext.h>
#include <hdlConvertor/syntaxErrorLogger.h>
#include <hdlConvertor/notImplementedLogger.h>

namespace hdlConvertor {

template<class antlrLexerT, class antlrParserT, class hdlParserT>
class ParserContainer {
	SyntaxErrorLogger * syntaxErrLogger;
	antlrLexerT * lexer;
	antlr4::CommonTokenStream * tokens;
	antlrParserT * antlrParser;
	hdlParserT * hdlParser;

	void initParser(antlr4::ANTLRInputStream &input) {
		// create a lexer that feeds off of input CharStream
		lexer = new antlrLexerT(&input);

		// create a buffer of tokens pulled from the lexer
		tokens = new antlr4::CommonTokenStream(lexer);

		// create a parser that feeds off the tokens buffer
		antlrParser = new antlrParserT(tokens);

		antlrParser->removeErrorListeners();
		syntaxErrLogger = new SyntaxErrorLogger();
		// lexer->removeErrorListeners();
		// lexer->addErrorListener(syntaxErrLogger);
		antlrParser->removeErrorListeners();
		antlrParser->addErrorListener(syntaxErrLogger);
	}
public:
	/*
	 * :param context: if context is nullptr new context is generated
	 *                 otherwise specified context is used
	 * */
	ParserContainer(hdlObjects::HdlContext * context):
		syntaxErrLogger(nullptr), lexer(nullptr), tokens(nullptr),
		antlrParser(nullptr), hdlParser(nullptr), context(context) {
	}
	hdlObjects::HdlContext * context;
	void parseFile(
			antlr4::ANTLRInputStream &fileName,
			bool hierarchyOnly,
			std::function<
					void(
					    SyntaxErrorLogger * syntaxErrLogger,
					    antlrParserT * antlrParser,
						hdlParserT * hdlParser
					    )
				     > parseFn) {

		initParser(fileName);

		hdlParser = new hdlParserT(antlrParser->getTokenStream(), context,
				hierarchyOnly);
		// begin parsing at init rule
		parseFn(syntaxErrLogger, antlrParser, hdlParser);
		context = hdlParser->getContext();
		syntaxErrLogger->CheckErrors(); // Throw exception if errors

		delete hdlParser;
		hdlParser = nullptr;
		delete syntaxErrLogger;
		syntaxErrLogger = nullptr;
		delete antlrParser;
		antlrParser = nullptr;
		delete tokens;
		tokens = nullptr;
		delete lexer;
		lexer = nullptr;
	}
	virtual ~ParserContainer() {
		delete hdlParser;
		delete syntaxErrLogger;
		delete antlrParser;
		delete tokens;
		delete lexer;
	}
};

}
