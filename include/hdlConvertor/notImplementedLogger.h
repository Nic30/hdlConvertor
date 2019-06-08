#pragma once
#include <iostream>

namespace hdlConvertor {

class NotImplementedLogger {
public:
	static bool ENABLE;
	static void print(const char * msg);
	static void print(const std::string & msg);
};

}
