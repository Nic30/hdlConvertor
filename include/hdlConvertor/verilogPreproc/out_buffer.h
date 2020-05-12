#pragma once

#include <string>
#include <sstream>
#include <ostream>
#include <hdlConvertor/verilogPreproc/file_line_map.h>

#if defined(_MSC_VER)

#include <BaseTsd.h>
typedef SSIZE_T ssize_t;

#endif

namespace hdlConvertor {
namespace verilog_pp {

class VerilogPreprocOutBuffer: public std::stringstream {
	// if line directive changes the line and not a file
	// and the number of added lines is <= NEWLINE_TRESHOLD
	// add this lines directly instead of adding line directive to file_line_map
	static const size_t NEWLINE_TRESHOLD = 3;

public:
	VerilogPreprocOutBuffer(ssize_t input_line_begin);

	// set input line and optionally update line_offset and file_line_map
	void set_input_line(size_t line);
	void set_input_line(const std::string & file_name, size_t new_line_no);

	// (output line_no, filename, input line_no)
	FileLineMap file_line_map;
	// actual number of lines in buffer
	std::size_t output_line;
	// the offset from line number from original file
	// (output line_no + line_offset + input_line_begin == input line_no)
	ssize_t input_line_offset;
	ssize_t input_line_begin;

	VerilogPreprocOutBuffer& operator<<(const char* str) = delete;
	VerilogPreprocOutBuffer& operator<<(char c) = delete;
	VerilogPreprocOutBuffer& operator<<(const std::string & str);
	VerilogPreprocOutBuffer& operator<<(const VerilogPreprocOutBuffer& other);
	VerilogPreprocOutBuffer& operator<<(std::ostream& (*f)(std::ostream&));
};

}
}
