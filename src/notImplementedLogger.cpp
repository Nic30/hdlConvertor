#include "notImplementedLogger.h"
#include "convertor.h"

namespace hdlConvertor {

void NotImplementedLogger::print(const char * msg) {
	if (Convertor::debug) {
		std::cerr << "Conversion to Python object not implemented: " << msg
				<< std::endl;
	}
}

void NotImplementedLogger::print(const std::string & msg) {
	print(msg.c_str());
}

}
