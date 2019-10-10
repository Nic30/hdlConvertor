#pragma once

#include <iostream>
#include <fstream>
#include <functional>
#include <memory>

#include <antlr4-runtime.h>

#include <hdlConvertor/hdlObjects/hdlContext.h>
#include <hdlConvertor/syntaxErrorLogger.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/universal_fs.h>
#include <hdlConvertor/verilogPreproc/macroDB.h>

namespace hdlConvertor {

template<class antlrLexerT, class antlrParserT, class hdlParserT>
class iParserContainer {
public:
	SyntaxErrorLogger syntaxErrLogger;
	std::unique_ptr<antlrLexerT> lexer;
	std::unique_ptr<antlr4::CommonTokenStream> tokens;
	std::unique_ptr<antlrParserT> antlrParser;
	std::unique_ptr<hdlParserT> hdlParser;
	Language lang;
	verilog_pp::MacroDB &defineDB;

	void initParser(antlr4::ANTLRInputStream &input_stream) {
		// create a lexer that feeds off of input CharStream
		lexer = std::make_unique<antlrLexerT>(&input_stream);

		// create a buffer of tokens pulled from the lexer
		tokens = std::make_unique<antlr4::CommonTokenStream>(lexer.get());

		// create a parser that feeds off the tokens buffer
		antlrParser = std::make_unique<antlrParserT>(tokens.get());

		antlrParser->removeErrorListeners();
		lexer->removeErrorListeners();
		lexer->addErrorListener(&syntaxErrLogger);
		antlrParser->removeErrorListeners();
		antlrParser->addErrorListener(&syntaxErrLogger);
	}
public:
	hdlObjects::HdlContext &context;

	/*
	 * :param context: if context is nullptr new context is generated
	 *                 otherwise specified context is used
	 * */
	iParserContainer(hdlObjects::HdlContext &context, Language _lang,
			verilog_pp::MacroDB &_defineDB) :
			syntaxErrLogger(), lexer(nullptr), tokens(nullptr), antlrParser(
					nullptr), hdlParser(nullptr), lang(_lang), defineDB(
					_defineDB), context(context) {
	}

	virtual void parseFn() = 0;

	void parse_file(const std::filesystem::path &file_name,
			bool hierarchyOnly) {
		antlr4::ANTLRFileStream input_stream(file_name.u8string());
		_parse(input_stream, hierarchyOnly);
	}

	void parse_str(const std::string &input_str, bool hierarchyOnly) {
		antlr4::ANTLRInputStream input_stream(input_str);
		input_stream.name = "<string>";
		_parse(input_stream, hierarchyOnly);
	}

	void _parse(antlr4::ANTLRInputStream &input_stream, bool hierarchyOnly) {
		initParser(input_stream);

		hdlParser = std::make_unique<hdlParserT>(*antlrParser->getTokenStream(),
				context, hierarchyOnly);
		// begin parsing at init rule
		try {
			parseFn();
		} catch (const antlr4::NoViableAltException &e) {
			// [todo] check if error really appeared in syntaxErrLogger
			throw;
		}

		syntaxErrLogger.error_prefix = "";
		syntaxErrLogger.check_errors(); // Throw exception if errors
	}

	virtual ~iParserContainer() {
	}
};

}
