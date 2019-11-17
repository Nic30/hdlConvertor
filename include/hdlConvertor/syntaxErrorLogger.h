#pragma once

#include <sstream>
#include <string>
#include <vector>

#include <antlr4-runtime.h>
#include <hdlConvertor/verilogPreproc/file_line_map.h>

namespace hdlConvertor {

class ErrorData {
public:
	enum error_kind_t {
		SYNTAXERROR,
		REPORTAMBIGUITY,
		REPORTCONTEXTSENSITIVITY,
		REPORTATTEMPTINGFULLCONTEXT
	};
	enum error_kind_t error_kind;
	size_t line;
	size_t charPosition;
	std::string filename;
	std::string message;
};

/*
 * The class which implements ANTLR error listener which is installed in parser
 * and lexer and staging the errors for later check.
 * */
class SyntaxErrorLogger: public antlr4::ANTLRErrorListener {

private:
	std::vector<ErrorData> _errors;

public:
	std::string error_prefix;

	// vector of file_name, line_offset last item is used as a base
	// if empty filename from antlr is used instead
	// @note file_line_map is optional because for Verilog preprocessor
	//       we mostly want to have actual file in error
	//       for the parser we want to have the original file in error msg
	//       not a location in preprocessed string.
	verilog_pp::FileLineMap *file_line_map;

	SyntaxErrorLogger();

	void check_errors();
	void syntaxError(antlr4::Recognizer *recognizer,
			antlr4::Token *offendingSymbol, size_t line,
			size_t charPositionInLine, const std::string &msg,
			std::exception_ptr e);

	void reportAmbiguity(antlr4::Parser *recognizer,
			const antlr4::dfa::DFA &dfa, size_t startIndex, size_t stopIndex,
			bool exact, const antlrcpp::BitSet &ambigAlts,
			antlr4::atn::ATNConfigSet *configs);

	void reportContextSensitivity(antlr4::Parser *recognizer,
			const antlr4::dfa::DFA &dfa, size_t startIndex, size_t stopIndex,
			size_t prediction, antlr4::atn::ATNConfigSet *configs);

	void reportAttemptingFullContext(antlr4::Parser *recognizer,
			const antlr4::dfa::DFA &dfa, size_t startIndex, size_t stopIndex,
			const antlrcpp::BitSet &conflictingAlts,
			antlr4::atn::ATNConfigSet *configs);
};

// Swaps the file_line_map in logger and on destruction it will put it back.
class FileLineMapSwap {
	SyntaxErrorLogger &logger;
	verilog_pp::FileLineMap *original_file_line_map;
public:
	FileLineMapSwap(SyntaxErrorLogger &logger,
			verilog_pp::FileLineMap *new_file_line_map);
	~FileLineMapSwap();
};

}
