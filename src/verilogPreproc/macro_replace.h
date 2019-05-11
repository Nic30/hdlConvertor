#pragma once

#include <string>
#include <vector>
#include <map>
#include "exception.h"

namespace hdlConvertor {
namespace verilog_pp {

/**
 * class macro_replace_data is the object to represent macro data.
 * Example:
 *  `define my_super_macro(a,b) a + b ;
 *  "a + b ;" is store in the tmplate property
 *  while args is a simple vector of string to store the list of argument is
 *  apparition order.
 */
class macro_replace_data {

public:
	std::string tmplate_name;
	std::string tmplate;
	std::vector<std::string> args;
	std::vector<std::string> default_arg;
};

/**
 * class macro_replace is an object to manipulate macro_replace_data
 */
class macro_replace {

protected:
	void replaceAll(std::string& str, const std::string& from,
			const std::string& to);
	std::vector<std::pair<size_t, size_t> > _substituate;
	bool check_interval(size_t start);
	void look4stringLiteral(std::string);

public:
	macro_replace_data data;
	// class constructor
	macro_replace(std::string, std::string, std::vector<std::string>);
	// class desctructor
	virtual ~macro_replace();
	// replace method
	virtual std::string replace();
	// replace method without argument
	virtual std::string replace(std::vector<std::string>);

};

}
}
