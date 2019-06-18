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
	std::vector<std::pair<size_t, size_t> > _string_intervals;
	std::pair<size_t, size_t> * check_is_in_string(size_t start);
	void collect_string_intervals(const std::string & str);

public:
	/*
	 * Fragment of the macro body, can be string or reference to an argument of a macro
	 * */
	class Fragment {
	public:
		ssize_t arg_no;
		std::string str;

		Fragment(size_t _arg_no) :
				arg_no(_arg_no) {
		}
		Fragment(const std::string & _str) :
				arg_no(-1), str(_str) {
		}
	};

	std::string name;
	bool has_params;
	std::vector<std::string> params;
	std::map<std::string, std::string> default_args;
	std::vector<Fragment> body;

	// class constructor
	MacroDef(const std::string & name, bool has_params,
			const std::vector<std::string> & params,
			const std::map<std::string, std::string> & default_args,
			const std::string & body);
	void parse_body(const std::vector<std::string> & params,
			const std::string & body, std::vector<MacroDef::Fragment> & res);
	// class desctructor
	virtual ~MacroDef() = default;
	// replace method without argument
	virtual std::string replace(std::vector<std::string> args,
			bool args_specified = false);

};

}
}
