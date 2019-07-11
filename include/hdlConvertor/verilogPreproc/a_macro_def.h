#pragma once

#include <string>
#include <vector>
#include <map>

#include <antlr4-common.h>

#include <hdlConvertor/conversion_exception.h>

namespace hdlConvertor {
namespace verilog_pp {

class VerilogPreproc;
/**
 * class aMacroDef is abstract class of an object to to store a verilog preprocessor macro definition
 * and to perform it's function
 */
class aMacroDef {
protected:
	void throw_doest_not_support_args();

public:

	std::string name;

	// class constructor
	aMacroDef(const std::string & name);
	// class desctructor
	virtual ~aMacroDef() = default;
	// replace method without argument
	virtual std::string replace(std::vector<std::string> args,
			bool args_specified, VerilogPreproc * pp,
			antlr4::ParserRuleContext * ctx) = 0;
};

}
}
