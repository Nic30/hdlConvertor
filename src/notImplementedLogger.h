#pragma once
#include <iostream>


class NotImplementedLogger {
public:
	static void print(const char * msg);
	static void print(const std::string & msg);

};
