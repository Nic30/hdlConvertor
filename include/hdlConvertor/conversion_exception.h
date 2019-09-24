#pragma once

#include <string>
#include <exception>

namespace hdlConvertor {

class ParseException: public std::exception {
private:
	std::string _msg;

public:
	ParseException(std::string msg) throw ();
	virtual const char* what() const throw ();
};

}
