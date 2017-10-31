#include "syntaxErrorLogger.h"

void SyntaxErrorLogger::syntaxError(Recognizer *recognizer,
		Token *offendingSymbol, size_t line, size_t charPositionInLine,
		const std::string &msg, std::exception_ptr e) {
	std::cerr << line << ":" << charPositionInLine << ":Error:" << msg << "\n";
}

void SyntaxErrorLogger::reportAmbiguity(Parser *recognizer, const dfa::DFA &dfa,
		size_t startIndex, size_t stopIndex, bool exact,
		const antlrcpp::BitSet &ambigAlts, atn::ATNConfigSet *configs) {

}

void SyntaxErrorLogger::reportContextSensitivity(Parser *recognizer,
		const dfa::DFA &dfa, size_t startIndex, size_t stopIndex,
		size_t prediction, atn::ATNConfigSet *configs) {

}

void SyntaxErrorLogger::reportAttemptingFullContext(Parser *recognizer,
		const dfa::DFA &dfa, size_t startIndex, size_t stopIndex,
		const antlrcpp::BitSet &conflictingAlts, atn::ATNConfigSet *configs) {

}
