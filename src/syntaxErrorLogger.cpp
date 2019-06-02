#include "conversion_exception.h"
#include "syntaxErrorLogger.h"

namespace hdlConvertor {
using namespace antlr4;
using namespace std;

void SyntaxErrorLogger::CheckErrors() {
	stringstream error_msg;
	error_msg << endl;
	for (auto & e : _errors) {
		error_msg << e._filename << ':' << e._line << ':'
				<< (uint32_t) e._charPosition << ":SyntaxError:" << e._message
				<< endl;
	}
	if (_errors.size() > 0) {
		throw ParseException(error_msg.str());
	}

}

void SyntaxErrorLogger::syntaxError(Recognizer *recognizer,
		Token *offendingSymbol __attribute__((unused)), size_t line,
		size_t charPositionInLine, const string &msg,
		exception_ptr e __attribute__((unused))) {

	error_data data;
	data._line = line;
	data._charPosition = charPositionInLine;
	data._filename = recognizer->getInputStream()->getSourceName();
	data._message = msg;

	_errors.push_back(data);
	//cerr << line << ":" << charPositionInLine << ":SyntaxError:" << msg << "\n";
}

void SyntaxErrorLogger::reportAmbiguity(
		Parser *recognizer __attribute__((unused)),
		const dfa::DFA &dfa __attribute__((unused)),
		size_t startIndex __attribute__((unused)),
		size_t stopIndex __attribute__((unused)),
		bool exact __attribute__((unused)),
		const antlrcpp::BitSet &ambigAlts __attribute__((unused)),
		atn::ATNConfigSet *configs __attribute__((unused))) {
	//cerr << ":Ambiguity:" << std::endl;
}

void SyntaxErrorLogger::reportContextSensitivity(
		Parser *recognizer __attribute__((unused)),
		const dfa::DFA &dfa __attribute__((unused)),
		size_t startIndex __attribute__((unused)),
		size_t stopIndex __attribute__((unused)),
		size_t prediction __attribute__((unused)),
		atn::ATNConfigSet *configs __attribute__((unused))) {
	//cerr << ":ContextSensitivity:" << std::endl;
}

void SyntaxErrorLogger::reportAttemptingFullContext(
		Parser *recognizer __attribute__((unused)),
		const dfa::DFA &dfa __attribute__((unused)),
		size_t startIndex __attribute__((unused)),
		size_t stopIndex __attribute__((unused)),
		const antlrcpp::BitSet &conflictingAlts __attribute__((unused)),
		atn::ATNConfigSet *configs __attribute__((unused))) {
	//cerr << ":AttemptingFullContext:" << std::endl;
}

}
