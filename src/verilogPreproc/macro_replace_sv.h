#pragma once

#include "macro_replace.h"

namespace hdlConvertor {
namespace verilog_pp {

class macro_replace_sv: public macro_replace {
private:
	std::map<std::string, std::string> _default_map;

public:
	macro_replace_sv(std::string, std::string, std::vector<std::string>,
			std::map<std::string, std::string>);
	std::string replace();
	std::string replace(std::vector<std::string> arg);
};

}
}
