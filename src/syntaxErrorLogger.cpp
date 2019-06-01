#include "syntaxErrorLogger.h"
using namespace antlr4;
using namespace std;

namespace hdlConvertor {

void SyntaxErrorLogger::CheckErrors() {
	stringstream error_msg;
	error_msg << endl;
	for(
	vector<error_data>::iterator iter = _errors.begin();
	iter != _errors.end();
	iter++ ) {
		error_msg << iter->_filename
			<< ':' << (*iter)._line
			<< ':' << (uint32_t) iter->_charPosition
		        <<  ":SyntaxError:"
			<< iter->_message
			<< endl;
	}
	if (_errors.size() > 0) {
		throw ParseException(error_msg.str());
	}

}

void SyntaxErrorLogger::syntaxError(
		Recognizer *recognizer,
		Token *offendingSymbol,
		size_t line,
		size_t charPositionInLine,
		const string &msg,
		exception_ptr e __attribute__((unused))) {

	error_data data;
	data._line = line;
	data._charPosition = charPositionInLine;
	data._filename = recognizer->getInputStream()->getSourceName();
	data._message = msg;

	_errors.push_back(data);
	//cerr << line << ":" << charPositionInLine << ":Error:" << msg << "\n";
}

void SyntaxErrorLogger::reportAmbiguity(
		Parser *recognizer __attribute__((unused)),
		const dfa::DFA &dfa __attribute__((unused)),
		size_t startIndex __attribute__((unused)),
		size_t stopIndex __attribute__((unused)),
		bool exact __attribute__((unused)),
		const antlrcpp::BitSet &ambigAlts __attribute__((unused)),
		atn::ATNConfigSet *configs __attribute__((unused))) {

}

void SyntaxErrorLogger::reportContextSensitivity(
		Parser *recognizer __attribute__((unused)),
		const dfa::DFA &dfa __attribute__((unused)),
		size_t startIndex __attribute__((unused)),
		size_t stopIndex __attribute__((unused)),
		size_t prediction __attribute__((unused)),
		atn::ATNConfigSet *configs __attribute__((unused))) {

}

void SyntaxErrorLogger::reportAttemptingFullContext(
		Parser *recognizer __attribute__((unused)),
		const dfa::DFA &dfa __attribute__((unused)),
		size_t startIndex __attribute__((unused)),
		size_t stopIndex,
		const antlrcpp::BitSet &conflictingAlts __attribute__((unused)),
		atn::ATNConfigSet *configs __attribute__((unused))) {

}

}
