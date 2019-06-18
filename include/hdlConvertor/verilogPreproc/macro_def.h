#pragma once

#include <string>
#include <vector>
#include <map>
#include <hdlConvertor/conversion_exception.h>

namespace hdlConvertor {
namespace verilog_pp {

/**
 * class MacroDef is an object to to store a verilog preprocessor macro definition
 * and to perform it's function

 * Example:
 *  `define my_super_macro(a,b) a + b ;
 *  "a + b ;" is store in the tmplate property
 *  while args is a simple vector of string to store the list of argument is
 *  apparition order.
 */
class MacroDef {

protected:
	void replaceAll(std::string& str, const std::string& from,
			const std::string& to);
	std::vector<std::pair<size_t, size_t> > _substituate;
	bool check_interval(size_t start);
	void look4stringLiteral(std::string);

public:
	std::string name;
	bool has_params;
	std::vector<std::string> params;
	std::map<std::string, std::string> default_args;
	std::string body;

	// class constructor
	MacroDef(const std::string & name, bool has_params,
			const std::vector<std::string> & params,
			const std::map<std::string, std::string> & default_args,
			const std::string & body);
	// class desctructor
	virtual ~MacroDef();
	// replace method without argument
	virtual std::string replace(std::vector<std::string> args,
			bool args_specified = false);

};

}
}
