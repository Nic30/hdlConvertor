#include <hdlConvertor/notImplementedLogger.h>
#include <antlr4-runtime.h>

namespace hdlConvertor {

bool NotImplementedLogger::ENABLE = true;

void NotImplementedLogger::print(const char *msg,
		antlr4::ParserRuleContext *ctx) {
	if (NotImplementedLogger::ENABLE) {
		auto t = ctx->getStart();
		auto is = t->getInputStream();
		auto file = is->getSourceName();
		auto line = t->getLine() - 1; // 1..n
		auto ch = t->getCharPositionInLine();
		std::cerr << file << ":" << line << ":" << ch << ": " << msg
				<< " Conversion to Python object not implemented" << std::endl;
		std::cerr << "    ..." << ctx->getText() << "..." << std::endl;
	}
}

void NotImplementedLogger::print(const std::string &msg,
		antlr4::ParserRuleContext *ctx) {
	NotImplementedLogger::print(msg.c_str(), ctx);
}
void NotImplementedLogger::print(const std::string &msg,
		antlr4::tree::TerminalNode *ctx) {
	if (NotImplementedLogger::ENABLE) {
		auto t = ctx->getSymbol();
		auto is = t->getInputStream();
		auto file = is->getSourceName();
		auto line = t->getLine() - 1; // 1..n
		auto ch = t->getCharPositionInLine();
		std::cerr << file << ":" << line << ":" << ch << ": " << msg
				<< " Conversion to Python object not implemented" << std::endl;
		std::cerr << "    ..." << ctx->getText() << "..." << std::endl;
	}
}
}
