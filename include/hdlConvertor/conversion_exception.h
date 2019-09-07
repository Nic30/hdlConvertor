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

// [todo] move to python module
extern const char* get_cpp_py_error_message();

}
