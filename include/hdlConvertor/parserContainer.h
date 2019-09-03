#pragma once

#include <iostream>
#include <fstream>
#include <functional>

#include <antlr4-runtime.h>

#include <hdlConvertor/hdlObjects/hdlContext.h>
#include <hdlConvertor/syntaxErrorLogger.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/universal_fs.h>

namespace hdlConvertor {

template<class antlrLexerT, class antlrParserT, class hdlParserT>
class iParserContainer {
public:
	SyntaxErrorLogger syntaxErrLogger;
	antlrLexerT *lexer;
	antlr4::CommonTokenStream *tokens;
	antlrParserT *antlrParser;
	hdlParserT *hdlParser;
	Language lang;

	void initParser(antlr4::ANTLRInputStream &input_stream) {
		// create a lexer that feeds off of input CharStream
		lexer = new antlrLexerT(&input_stream);

		// create a buffer of tokens pulled from the lexer
		tokens = new antlr4::CommonTokenStream(lexer);

		// create a parser that feeds off the tokens buffer
		antlrParser = new antlrParserT(tokens);

		antlrParser->removeErrorListeners();
		// lexer->removeErrorListeners();
		// lexer->addErrorListener(syntaxErrLogger);
		antlrParser->removeErrorListeners();
		antlrParser->addErrorListener(&syntaxErrLogger);
	}
public:
	hdlObjects::HdlContext *context;

	/*
	 * :param context: if context is nullptr new context is generated
	 *                 otherwise specified context is used
	 * */
	iParserContainer(hdlObjects::HdlContext *context, Language _lang) :
			syntaxErrLogger(), lexer(nullptr), tokens(nullptr), antlrParser(
					nullptr), hdlParser(nullptr), lang(_lang), context(context) {
	}

	virtual void parseFn() = 0;

	void parse_file(const std::filesystem::path &file_name, bool hierarchyOnly) {
		antlr4::ANTLRFileStream input_stream(file_name.u8string());
		_parse(input_stream, hierarchyOnly);
	}

	void parse_str(const std::string &input_str, bool hierarchyOnly) {
		antlr4::ANTLRInputStream input_stream(input_str);
		input_stream.name = "<string>";
		_parse(input_stream, hierarchyOnly);
	}

	void _parse(antlr4::ANTLRInputStream & input_stream, bool hierarchyOnly) {
		initParser(input_stream);

		hdlParser = new hdlParserT(antlrParser->getTokenStream(), context,
				hierarchyOnly);
		// begin parsing at init rule
		try {
			parseFn();
		} catch (const antlr4::NoViableAltException & e) {
			// [todo] check if error really appeared in syntaxErrLogger
			throw;
		}
		context = hdlParser->getContext();

		delete hdlParser;
		hdlParser = nullptr;
		delete antlrParser;
		antlrParser = nullptr;
		delete tokens;
		tokens = nullptr;
		delete lexer;
		lexer = nullptr;

		syntaxErrLogger.CheckErrors(); // Throw exception if errors
	}

	virtual ~iParserContainer() {
		delete hdlParser;
		delete antlrParser;
		delete tokens;
		delete lexer;
	}
};


}
