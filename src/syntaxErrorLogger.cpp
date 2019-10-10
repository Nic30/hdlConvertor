#include <hdlConvertor/syntaxErrorLogger.h>
#include <antlr4-runtime.h>

#include <hdlConvertor/conversion_exception.h>

#if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
#define UNUSED(x) x __attribute__((unused))
#elif defined(_MSC_VER)
#define UNUSED(x)
#endif


namespace hdlConvertor {
using namespace antlr4;
using namespace std;

void SyntaxErrorLogger::check_errors() {
	stringstream error_msg;
	error_msg << endl;
	for (auto & e : _errors) {
		error_msg << e._filename << ':' << e._line << ':'
				<< (uint32_t) e._charPosition << ":" << error_prefix << "SyntaxError:" << e._message
				<< endl;
	}
	if (_errors.size() > 0) {
		throw ParseException(error_msg.str());
	}

}

void SyntaxErrorLogger::syntaxError(Recognizer *recognizer,
		Token *UNUSED(offendingSymbol), size_t line,
		size_t charPositionInLine, const string &msg,
		exception_ptr UNUSED(e)) {

	error_data data;
	data._line = line;
	data._charPosition = charPositionInLine;
	data._filename = recognizer->getInputStream()->getSourceName();
	data._message = msg;

	_errors.push_back(data);
	//cerr << line << ":" << charPositionInLine << ":SyntaxError:" << msg << "\n";
}

void SyntaxErrorLogger::reportAmbiguity(
		Parser *UNUSED(recognizer),
		const dfa::DFA &UNUSED(dfa),
		size_t UNUSED(startIndex),
		size_t UNUSED(stopIndex),
		bool UNUSED(exact),
		const antlrcpp::BitSet &UNUSED(ambigAlts),
		atn::ATNConfigSet *UNUSED(configs)) {
	//cerr << ":Ambiguity:" << std::endl;
}

void SyntaxErrorLogger::reportContextSensitivity(
		Parser *UNUSED(recognizer),
		const dfa::DFA &UNUSED(dfa),
		size_t UNUSED(startIndex),
		size_t UNUSED(stopIndex),
		size_t UNUSED(prediction),
		atn::ATNConfigSet *UNUSED(configs)) {
	//cerr << ":ContextSensitivity:" << std::endl;
}

void SyntaxErrorLogger::reportAttemptingFullContext(
		Parser *UNUSED(recognizer),
		const dfa::DFA &UNUSED(dfa),
		size_t UNUSED(startIndex),
		size_t UNUSED(stopIndex),
		const antlrcpp::BitSet &UNUSED(conflictingAlts),
		atn::ATNConfigSet *UNUSED(configs)) {
	//cerr << ":AttemptingFullContext:" << std::endl;
}

}
