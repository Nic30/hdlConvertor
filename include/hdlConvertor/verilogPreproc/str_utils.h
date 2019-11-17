#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

namespace hdlConvertor {
namespace verilog_pp {

std::string& rtrim(std::string &str, const std::string &chars = " \t\n\r");
std::string& ltrim(std::string &str, const std::string &chars = " \t\n\r");
std::string& trim(std::string &str, const std::string &chars = " \t\n\r");

void replaceStringInPlace(std::string &subject, const std::string &search,
		const std::string &replace);
void replace_substring(std::string &str, const std::string &s,
		const std::string &repl);
void unescape_string_dblquotes(std::string &str);

template<typename T>
std::string vector_to_string(const std::vector<T> &vec) {
	std::ostringstream oss;
	oss << "[";
	if (!vec.empty()) {
		// Convert all but the last element to avoid a trailing ","
		std::copy(vec.begin(), vec.end() - 1,
				std::ostream_iterator<T>(oss, ","));

		// Now add the last element with no delimiter
		oss << vec.back();
	}
	oss << "]";
	return oss.str();
}

}
}
