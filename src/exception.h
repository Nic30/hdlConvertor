#pragma once

#include <string>
#include <exception>

class parseException: public std::exception {

	private:
		std::string _msg;
	public:
		parseException(std::string msg) throw():_msg(msg) {};
		virtual const char * what() const throw() {
			return _msg.c_str();
		}
		virtual ~parseException() throw() {};

};


void raise_py_error();
