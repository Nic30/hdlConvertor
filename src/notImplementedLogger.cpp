#include <hdlConvertor/notImplementedLogger.h>

namespace hdlConvertor {

bool NotImplementedLogger::ENABLE = true;

void NotImplementedLogger::print(const char * msg) {
	if (NotImplementedLogger::ENABLE) {
		std::cerr << "Conversion to Python object not implemented: " << msg
				<< std::endl;
	}
}

void NotImplementedLogger::print(const std::string & msg) {
	NotImplementedLogger::print(msg.c_str());
}

}
