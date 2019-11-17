#pragma once

#include <string>
#include <vector>

namespace hdlConvertor {
namespace verilog_pp {

class FileLineMapItem {
public:
	FileLineMapItem(size_t line, const std::string &file_override,
			size_t line_override);
	size_t line;
	std::string file_override;
	size_t line_override;
};

// Container of information about offsets in code positions for error logging and code analysis
using FileLineMap = std::vector<FileLineMapItem>;

}
}
