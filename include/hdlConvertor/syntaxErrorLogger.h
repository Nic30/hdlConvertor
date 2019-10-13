#pragma once

#include <sstream>
#include <string>

#include <antlr4-runtime.h>

namespace hdlConvertor {

enum error_kind_t {
	SYNTAXERROR,
	REPORTAMBIGUITY,
	REPORTCONTEXTSENSITIVITY,
	REPORTATTEMPTINGFULLCONTEXT
};

class error_data {
public:
	enum error_kind_t _error_kind;
	size_t _line;
	size_t _charPosition;
	std::string _filename;
	std::string _message;
};

class SyntaxErrorLogger: public antlr4::ANTLRErrorListener {

	class error_data {
	public:
		enum error_kind_t _error_kind;
		size_t _line;
		size_t _charPosition;
		std::string _filename;
		std::string _message;
	};

private:
	std::vector<error_data> _errors;

public:
	std::string error_prefix;
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

}
