#include <hdlConvertor/verilogPreproc/str_utils.h>
#include <hdlConvertor/conversion_exception.h>

using namespace std;

namespace hdlConvertor {
namespace verilog_pp {

string& rtrim(string &str, const string &chars) {
	str.erase(str.find_last_not_of(chars) + 1);
	return str;
}

string& ltrim(string &str, const string &chars) {
	str = str.erase(0, str.find_first_not_of(chars));
	return str;
}

string& trim(string &str, const string &chars) {
	return rtrim(ltrim(str, chars), chars);
}

void replaceStringInPlace(string &subject, const string &search,
		const string &replace) {
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != string::npos) {
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
}


void replace_substring(string &str, const string &s, const string &repl) {
	size_t start_pos = 0;
	while ((start_pos = str.find(s, start_pos)) != string::npos) {
		str.replace(start_pos, s.size(), repl);
		start_pos += repl.size();
	}
}

void unescape_string_dblquotes(string &str) {
	size_t start_pos = 0;
	auto npos = string::npos;
	size_t prev_start_pos = npos;
	while ((start_pos = str.find("`\"", start_pos)) != npos) {
		// if " is not part of `" or \"
		bool is_escaped = (start_pos != 0 && str[start_pos - 1] == '\\');
		if (!is_escaped) {
			// delete '`' before '"'
			str.erase(start_pos, 1);
			if (prev_start_pos == npos) {
				prev_start_pos = start_pos;
			} else {
				for (size_t in_str_i = prev_start_pos; in_str_i < start_pos;
						in_str_i++) {
					if (str[in_str_i] == '\n' && str[in_str_i - 1] != '\\') {
						// escape every non escaped newline in new string
						str.insert(in_str_i, 1, '\\');
						start_pos++;
					}
				}
				prev_start_pos = npos;
			}
		}
		start_pos++;
	}
	if (prev_start_pos != npos)
		throw ParseException("Unfinished `\" string");
}

}
}
