#pragma once

#include <string>
#include <vector>
#include <map>

// antlr4-runtime/
#include <ParserRuleContext.h>

#include <hdlConvertor/conversion_exception.h>

#if defined(_MSC_VER)

#include <BaseTsd.h>
typedef SSIZE_T ssize_t;

#endif


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
	// flag which tells if the macro definition should remain in MacroDB from previous run
	// or if the definitions should be removed as it was only for previous set of files
	bool is_persistent;
	// preprocessor symbol name which is used for this macro definition
	std::string name;
	std::string defined_in_file;
	ssize_t defined_in_line_no;


	aMacroDef(const std::string &name);
	virtual ~aMacroDef() = default;

	virtual bool requires_args() = 0;
	virtual std::string replace(std::vector<std::string> args,
			bool args_specified, VerilogPreproc *pp,
			antlr4::ParserRuleContext *ctx) = 0;
};

}
}
