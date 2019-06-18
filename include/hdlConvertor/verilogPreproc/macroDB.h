#pragma once

#include <string>
#include <map>
#include <vector>

#include <hdlConvertor/language.h>
#include <hdlConvertor/verilogPreproc/a_macro_def.h>

namespace hdlConvertor {
namespace verilog_pp {

/**
 * class to store all the defined macro. The class herite from the
 * std::map<std:string, macro_replace*>
 */
class MacroDB: public std::map<std::string, aMacroDef*> {
public:

	virtual ~MacroDB();
};

}
}
