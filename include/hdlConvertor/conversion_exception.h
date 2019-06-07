#pragma once

#include <string>
#include <exception>

namespace hdlConvertor {

class ParseException: public std::exception {
private:
	std::string _msg;

public:
	ParseException(std::string msg) throw () :
			_msg(msg) {
	}
	virtual const char * what() const throw () {
		return _msg.c_str();
	}
};

extern const char* get_my_py_error_message();

}
