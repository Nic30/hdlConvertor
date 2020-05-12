#include <hdlConvertor/verilogPreproc/out_buffer.h>
#include <assert.h>
#include <algorithm>

using namespace std;

namespace hdlConvertor {
namespace verilog_pp {

VerilogPreprocOutBuffer::VerilogPreprocOutBuffer(ssize_t _input_line_begin) :
		output_line(0), input_line_offset(0), input_line_begin(
				_input_line_begin) {
	assert(_input_line_begin >= 0);
}

void VerilogPreprocOutBuffer::set_input_line(const std::string &file_name,
		size_t input_line_no) {
	if (file_line_map.size() > 0) {
		const auto &last = file_line_map.back();
		if (last.file_override == file_name) {
			// we are already in this file, we need only set line
			set_input_line(input_line_no);
			return;
		}
	}

	FileLineMapItem item(output_line, file_name, input_line_no);
	file_line_map.push_back(item);
	input_line_offset = input_line_begin + input_line_no;
	input_line_offset -= output_line;
}

void VerilogPreprocOutBuffer::set_input_line(size_t input_line_no) {
	auto lines_to_add = input_line_no
			- (output_line + input_line_offset + input_line_begin);
	// lines_to_add can be negative e. g. for a code behind macro which was expanded
	// on larger number of lines
	if (lines_to_add > 0 && lines_to_add <= NEWLINE_TRESHOLD) {
		// fill missing lines
		for (size_t i = 0; i < lines_to_add; i++) {
			(*this) << endl;
		}
	} else {
		// update file_line_map
		assert(file_line_map.size() > 0);
		const auto &last = file_line_map.back();
		FileLineMapItem item(output_line, last.file_override, input_line_no);
		file_line_map.push_back(item);
		input_line_offset += lines_to_add;
	}
}

VerilogPreprocOutBuffer& VerilogPreprocOutBuffer::operator<<(
		const std::string &str) {
	auto lines = count(str.begin(), str.end(), '\n');
	output_line += lines;
	(*static_cast<stringstream*>(this)) << str;
	return *this;
}

VerilogPreprocOutBuffer& VerilogPreprocOutBuffer::operator<<(
		const VerilogPreprocOutBuffer &other) {
	(*this) << std::endl;
	(*static_cast<std::stringstream*>(this)) << other.str();
	for (auto &i : other.file_line_map) {
		FileLineMapItem i_new(i.line + output_line, i.file_override,
				i.line_override);
		file_line_map.push_back(i_new);
	}
	output_line += other.output_line;
	input_line_offset += other.input_line_offset;
	return *this;
}

VerilogPreprocOutBuffer& VerilogPreprocOutBuffer::operator<<(
		ostream& (*f)(ostream&)) {
	if (f
			== &std::endl<VerilogPreprocOutBuffer::char_type,
					VerilogPreprocOutBuffer::traits_type>) {
		output_line++;
	}
	(*static_cast<stringstream*>(this)) << f;
	return *this;
}

}
}
