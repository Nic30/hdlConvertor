#pragma once

#include <string>
#include <map>
#include <vector>

#include <hdlConvertor/language.h>
#include <hdlConvertor/verilogPreproc/a_macro_def.h>

namespace hdlConvertor {
namespace verilog_pp {

/**
 * Container to store all the defined macro.
 */
typedef std::map<std::string, aMacroDef*> MacroDB;

}
}
