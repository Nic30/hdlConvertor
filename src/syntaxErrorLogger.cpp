#include <hdlConvertor/syntaxErrorLogger.h>

#include <antlr4-runtime.h>
#include <assert.h>
#include <hdlConvertor/conversion_exception.h>

#if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
#define UNUSED(x) x __attribute__((unused))
#elif defined(_MSC_VER)
#define UNUSED(x)
#endif

using namespace antlr4;
using namespace std;

namespace hdlConvertor {

SyntaxErrorLogger::SyntaxErrorLogger() :
		ANTLRErrorListener(), file_line_map(nullptr) {
}

void SyntaxErrorLogger::check_errors() {
	stringstream error_msg;
	error_msg << endl;
	for (auto &e : _errors) {
		error_msg << e.filename << ':' << e.line << ':'
				<< (uint32_t) e.charPosition << ":" << error_prefix
				<< "SyntaxError:" << e.message << endl;
	}
	if (_errors.size() > 0) {
		throw ParseException(error_msg.str());
	}
}

void SyntaxErrorLogger::syntaxError(Recognizer *recognizer,
		Token *UNUSED(offendingSymbol), size_t line, size_t charPositionInLine,
		const string &msg, exception_ptr UNUSED(e)) {

	ErrorData err;
	// use offsets and overrides from file_line_map if available
	if (file_line_map && !file_line_map->empty()) {
		const auto &lm = file_line_map->back();
		assert(line >= lm.line);
		err.line = lm.line_override + (line - lm.line);
		err.filename = lm.file_override;
	} else {
		err.line = line;
		err.filename = recognizer->getInputStream()->getSourceName();
	}
	err.charPosition = charPositionInLine;
	err.message = msg;

	_errors.push_back(err);
	//cerr << line << ":" << charPositionInLine << ":SyntaxError:" << msg << "\n";
}

void SyntaxErrorLogger::reportAmbiguity(Parser *UNUSED(recognizer),
		const dfa::DFA &UNUSED(dfa), size_t UNUSED(startIndex),
		size_t UNUSED(stopIndex), bool UNUSED(exact),
		const antlrcpp::BitSet &UNUSED(ambigAlts),
		atn::ATNConfigSet *UNUSED(configs)) {
	//cerr << ":Ambiguity:" << std::endl;
}

void SyntaxErrorLogger::reportContextSensitivity(Parser *UNUSED(recognizer),
		const dfa::DFA &UNUSED(dfa), size_t UNUSED(startIndex),
		size_t UNUSED(stopIndex), size_t UNUSED(prediction),
		atn::ATNConfigSet *UNUSED(configs)) {
	//cerr << ":ContextSensitivity:" << std::endl;
}

void SyntaxErrorLogger::reportAttemptingFullContext(Parser *UNUSED(recognizer),
		const dfa::DFA &UNUSED(dfa), size_t UNUSED(startIndex),
		size_t UNUSED(stopIndex),
		const antlrcpp::BitSet &UNUSED(conflictingAlts),
		atn::ATNConfigSet *UNUSED(configs)) {
	//cerr << ":AttemptingFullContext:" << std::endl;
}

FileLineMapSwap::FileLineMapSwap(SyntaxErrorLogger &_logger,
		verilog_pp::FileLineMap *new_file_line_map) :
		logger(_logger), original_file_line_map(logger.file_line_map) {
	logger.file_line_map = new_file_line_map;
}

FileLineMapSwap::~FileLineMapSwap() {
	logger.file_line_map = original_file_line_map;
}

}
