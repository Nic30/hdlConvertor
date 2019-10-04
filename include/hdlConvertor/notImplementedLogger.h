#pragma once

#include <iostream>

#include <antlr4-runtime.h>

namespace hdlConvertor {

class NotImplementedLogger {
public:
	static bool ENABLE;

	static void print(const char *msg, antlr4::ParserRuleContext *ctx);
	static void print(const std::string &msg, antlr4::ParserRuleContext *ctx);
	static void print(const std::string &msg, antlr4::tree::TerminalNode *ctx);

};

}
