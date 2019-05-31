#pragma once

#include <string>
#include <map>
#include <vector>

#include "macro_replace.h"
#include "macro_replace_sv.h"

namespace hdlConvertor {
namespace verilog_pp {

/**
 * class to store all the defined macro. The class herite from the
 * std::map<std:string, macro_replace*>
 */
class macroSymbol: public std::map<std::string, macro_replace*> {

public:

	// specialisation of the insert method to add element in the map.
	// The list of include directory is required to be able to register a
	// template where already presented macro are already expended
	void insert(const std::pair<std::string, macro_replace*> item,
			std::vector<std::string> & incdir,
			std::vector<std::string> & stack_incfile, unsigned int mode);

};

}
}
