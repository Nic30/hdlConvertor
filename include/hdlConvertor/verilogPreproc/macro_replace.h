#pragma once

#include <string>
#include <vector>
#include <map>
#include <hdlConvertor/conversion_exception.h>

namespace hdlConvertor {
namespace verilog_pp {

/**
 * class macro_replace is an object to to store a verilog preprocessor macro definition
 * and to perform it's function

 * Example:
 *  `define my_super_macro(a,b) a + b ;
 *  "a + b ;" is store in the tmplate property
 *  while args is a simple vector of string to store the list of argument is
 *  apparition order.
 */
class macro_replace {

protected:
	void replaceAll(std::string& str, const std::string& from,
			const std::string& to);
	std::vector<std::pair<size_t, size_t> > _substituate;
	bool check_interval(size_t start);
	void look4stringLiteral(std::string);

public:
	std::string name;
	std::string body;
	std::vector<std::string> params;
	std::map<std::string, std::string> default_args;

	// class constructor
	macro_replace(std::string name, std::string body,
			std::vector<std::string> params,
			std::map<std::string, std::string> default_args);
	// class desctructor
	virtual ~macro_replace();
	// replace method
	virtual std::string replace();
	// replace method without argument
	virtual std::string replace(std::vector<std::string>);

};

}
}
