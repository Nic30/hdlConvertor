#include "notImplementedLogger.h"
#include "convertor.h"

void NotImplementedLogger::print(const char * msg) {
	if (Convertor::debug) {
		std::cerr << msg << "\n";
	}
}

void NotImplementedLogger::print(const std::string & msg) {
	if (Convertor::debug) {
		std::cerr << msg << "\n";
	}
}
