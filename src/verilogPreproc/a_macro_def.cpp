#include <hdlConvertor/verilogPreproc/a_macro_def.h>

namespace hdlConvertor {
namespace verilog_pp {

aMacroDef::aMacroDef(const std::string &_name) :
		is_persistent(false), name(_name), defined_in_file("<UNKNOWN>"), defined_in_line_no(
				-1) {
}

void aMacroDef::throw_doest_not_support_args() {
	std::string msg = "Macro " + name
			+ " does not expect any arguments or braces.";
	throw ParseException(msg);
}

}
}
