#pragma once

#include <string>
#include <exception>

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

void raise_py_error();
