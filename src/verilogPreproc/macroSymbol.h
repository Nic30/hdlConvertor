#pragma once

#include <string>
#include <map>
#include <vector>

#include "../verilogPreproc/macro_replace.h"

class macroSymbol: public std::map<std::string, macro_replace*> {

public:
	void insert(const std::pair<std::string, macro_replace*>,
			std::vector<std::string> &);

};
