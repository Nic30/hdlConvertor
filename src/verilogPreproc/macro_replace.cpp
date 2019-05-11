#include "../verilogPreproc/macro_replace.h"

using namespace std;

namespace hdlConvertor {
namespace verilog_pp {

macro_replace::macro_replace(string macro_name, string replace,
		vector<string> arg) {
	data.tmplate_name = macro_name;
	data.tmplate = replace;
	data.args = arg;
}

macro_replace::~macro_replace() {
}

// return false to skip this find because it is 
// from an already substitution of the same macro replacement
bool macro_replace::check_interval(size_t start) {
	for (auto paire : _substituate) {
		//printf("{%li,%li}\n",paire.first,paire.second);
		if ((paire.first <= start) && (start < paire.first + paire.second)) {
			return true;
		}
	}
	return false;
}
/*
 * Look for String literal. In order to forbid them to be change by replacement
 */
void macro_replace::look4stringLiteral(string tmpl) {
	size_t start_pos = 0;
	auto npos = string::npos;
	size_t pos1 = npos;
	while ((start_pos = tmpl.find('"', start_pos)) != npos) {
		if (pos1 == npos
				&& ((start_pos != 0 && tmpl[start_pos - 1] != '`')
						|| start_pos == 0)) {
			pos1 = start_pos;
		} else if (pos1 != npos && tmpl[start_pos - 1] != '`') {
			size_t length = start_pos - pos1;
			_substituate.push_back(make_pair(pos1, length));
			pos1 = npos;
		}
		start_pos += 1;
	}
}

void macro_replace::replaceAll(string& str, const string& from,
		const string& to) {
	if (from.empty())
		return;
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != string::npos) {
		/*
		 printf("-->%s\n",str.c_str());
		 printf("-->%li %li\n",start_pos,from.length());
		 printf("-->%s\n",to.c_str());
		 */
		if (!((('a' <= str[start_pos + from.length()])
				&& (str[start_pos + from.length()] <= 'z'))
				|| (('A' <= str[start_pos + from.length()])
						&& (str[start_pos + from.length()] <= 'Z'))
				|| (('0' <= str[start_pos + from.length()])
						&& (str[start_pos + from.length()] <= '9'))
				|| ('_' == str[start_pos + from.length()])
				|| ('$' == str[start_pos + from.length()])
				|| ('(' == str[start_pos + from.length()])
				|| ('[' == str[start_pos + from.length()])
				|| ('{' == str[start_pos + from.length()]) ||

				check_interval(start_pos) //check the find is in the result of a substitution of the same macro_replacement

		)) {
			//printf("replacement\n");
			/*
			 * Test what is next character. If next character is part of [a-zA-Z0-9_$([{] then it is not what we have to replace.
			 * 19.3.1 `define
			 * The text specified for macro text shall not be split across the following lexical tokens:
			 *   Comments
			 *   Numbers
			 *   Strings
			 *   Identifiers
			 *   Keywords
			 *   Operators
			 * */
			str.replace(start_pos, from.length(), to);
			size_t i = 0;
			for (auto a : _substituate) {
				//printf("%li < %li\n",start_pos,a.first );
				if (start_pos < a.first) {
					//a->first += to.length();
					_substituate.at(i) = make_pair(a.first + to.length(),
							a.second);
				}
				i++;
			}
			//for (auto paire:_substituate) {
			//  printf("[%li,%li]\n",paire.first,paire.second);
			//}
			_substituate.push_back(make_pair(start_pos, to.length()));
		}
		start_pos += 1;
	}
}

string macro_replace::replace(vector<string> arg) {
	string returnString;

	if (!data.tmplate.empty()) {
		returnString = data.tmplate;

		if (arg.size() != data.args.size()) {
			string message =
					"Missmatch in number of argument macro declaration "
							+ data.tmplate_name + " ("
							+ to_string(data.args.size())
							+ ") and macro usage (" + to_string(arg.size())
							+ ')';
			throw ParseException(message);
		}
		_substituate.clear();
		vector<string>::iterator macro = data.args.begin();
		vector<string>::iterator instance = arg.begin();
		for (; macro != data.args.end(); macro++, instance++) {
			replaceAll(returnString, *macro, *instance);
		}
	} else {
		//Macro can be empty
		//Example `define MODE1
		returnString = "";
	}
	return returnString;

}

string macro_replace::replace() {
	vector<string> null_vector;
	return replace(null_vector);
}

}
}
