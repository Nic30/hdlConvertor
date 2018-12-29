#pragma once

#include "macro_replace.h"
#include <string>
#include <map>
class macroSymbol : public std::map<std::string,macro_replace*> {

	public:
		void insert (const std::pair<std::string,macro_replace*>,std::vector<std::string> &);

};
