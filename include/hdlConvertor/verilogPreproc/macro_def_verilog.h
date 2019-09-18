#pragma once

#include <string>
#include <vector>
#include <map>
#include <hdlConvertor/conversion_exception.h>
#include <hdlConvertor/verilogPreproc/a_macro_def.h>

namespace hdlConvertor {
namespace verilog_pp {

class VerilogPreproc;
/**
 * class MacroDefVerilog is an object to to store a verilog preprocessor macro definition
 * and to perform it's function

 * Example:
 *  `define my_super_macro(a,b) a + b ;
 *  "a + b ;" is store in the tmplate property
 *  while args is a simple vector of string to store the list of argument is
 *  apparition order.
 */
class MacroDefVerilog: public aMacroDef {

protected:
	std::vector<std::pair<size_t, size_t> > _string_intervals;
	std::pair<size_t, size_t> * check_is_in_string(size_t start);
	void collect_string_intervals(const std::string & str);

public:
	struct param_info_t {
		std::string name;
		bool has_def_val;
		std::string def_val;
	};
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

	bool has_params;
	std::vector<param_info_t> params;
	std::vector<Fragment> body;

	// class constructor
	MacroDefVerilog(const std::string & name, bool has_params,
			const std::vector<param_info_t> & params, const std::string & body);
	void parse_body(const std::vector<param_info_t> & params,
			const std::string & body,
			std::vector<MacroDefVerilog::Fragment> & res);
	std::pair<size_t, size_t> get_possible_arg_cnt() const;
	std::string get_possible_arg_cnt_str() const;
	virtual bool requires_args() override;
	// replace method without argument
	virtual std::string replace(std::vector<std::string> args,
			bool args_specified, VerilogPreproc * pp,
			antlr4::ParserRuleContext * ctx) override;

};

}
}
