#include <hdlConvertor/verilogPreproc/a_macro_def.h>

namespace hdlConvertor {
namespace verilog_pp {

aMacroDef::aMacroDef(const std::string & _name) :
		name(_name) {
}

void aMacroDef::throw_doest_not_support_args() {
	std::string msg = "Macro " + name
			+ " does not expect any argumets or braces.";
	throw ParseException(msg);
}

}
}
