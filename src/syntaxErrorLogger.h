#pragma once
#include "antlr4-runtime.h"
#include "exception.h"
#include <sstream>
#include <string>

using namespace antlr4;

enum error_kind_t {SYNTAXERROR,REPORTAMBIGUITY,REPORTCONTEXTSENSITIVITY,REPORTATTEMPTINGFULLCONTEXT};

class error_data {
	public:
	enum error_kind_t _error_kind;
	size_t _line;
	size_t _charPosition;
	std::string _filename;
	std::string _message;
};


class SyntaxErrorLogger: public ANTLRErrorListener {


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
	void CheckErrors();
	void syntaxError(
			Recognizer *recognizer,
			Token *offendingSymbol,
			size_t line,
			size_t charPositionInLine,
			const std::string &msg,
			std::exception_ptr e);

	void reportAmbiguity(
			Parser *recognizer,
			const dfa::DFA &dfa,
			size_t startIndex,
			size_t stopIndex,
			bool exact,
			const antlrcpp::BitSet &ambigAlts,
			atn::ATNConfigSet *configs);
	void reportContextSensitivity(
			Parser *recognizer,
			const dfa::DFA &dfa,
			size_t startIndex,
			size_t stopIndex,
			size_t prediction,
			atn::ATNConfigSet *configs);

	void reportAttemptingFullContext(
			Parser *recognizer,
			const dfa::DFA &dfa,
			size_t startIndex,
			size_t stopIndex,
			const antlrcpp::BitSet &conflictingAlts,
			atn::ATNConfigSet *configs);

};
