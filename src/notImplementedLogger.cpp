#include "notImplementedLogger.h"
#include "convertor.h"

void NotImplementedLogger::print(const char * msg) {
	if (Convertor::debug) {
		std::cerr << msg << "\n";
	}
}
