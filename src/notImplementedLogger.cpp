#include "notImplementedLogger.h"
#include "convertor.h"

void NotImplementedLogger::print(const char * msg) {
	if (Convertor::debug) {
		std::cerr << msg << std::endl;
	}
}

void NotImplementedLogger::print(const std::string & msg) {
	print(msg.c_str());
}
