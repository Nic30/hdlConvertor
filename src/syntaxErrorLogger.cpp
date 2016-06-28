#include "syntaxErrorLogger.h"

void SyntaxErrorLogger::syntaxError(
		IRecognizer *recognizer,
		Token *offendingSymbol,
		size_t line,
		int charPositionInLine,
		const std::string &msg,
		std::exception_ptr e) {
	std::cerr << line << ":" << charPositionInLine << ":Error:" << msg << "\n";
}

void SyntaxErrorLogger::reportAmbiguity(
		Parser *recognizer,
		const dfa::DFA &dfa,
		size_t startIndex,
		size_t stopIndex,
		bool exact,
		const antlrcpp::BitSet &ambigAlts,
		atn::ATNConfigSet *configs) {

}

void SyntaxErrorLogger::reportContextSensitivity(
		Parser *recognizer,
		const dfa::DFA &dfa,
		size_t startIndex,
		size_t stopIndex,
		int prediction,
		atn::ATNConfigSet *configs) {

}

void SyntaxErrorLogger::reportAttemptingFullContext(
		Parser *recognizer,
		const dfa::DFA &dfa,
		size_t startIndex,
		size_t stopIndex,
		const antlrcpp::BitSet &conflictingAlts,
		atn::ATNConfigSet *configs) {

}
