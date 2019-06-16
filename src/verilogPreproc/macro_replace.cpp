#include <hdlConvertor/verilogPreproc/macro_replace.h>

using namespace std;

namespace hdlConvertor {
namespace verilog_pp {

macro_replace::macro_replace(const string & _name, bool _has_params,
		const vector<string> & _params,
		const std::map<std::string, std::string> & _default_args,
		const string & _body) :
		name(_name), has_params(_has_params), params(_params), default_args(
				_default_args), body(_body) {
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
		auto c = str[start_pos + from.length()];
		if (!((('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z'))
				|| (('0' <= c) && (c <= '9')) || ('_' == c) || ('$' == c)
				|| ('(' == c) || ('[' == c) || ('{' == c)
				|| check_interval(start_pos)
		//check the find is in the result of a substitution of the same
		// macro_replacement

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

string macro_replace::replace(vector<string> args, bool args_specified) {
	if (has_params && !args_specified) {
		string msg = "Macro " + name + " requires braces and expects ";
		if (default_args.size()) {
			msg += "(" + std::to_string(params.size() - default_args.size())
					+ " to ";
		} else {
			msg += "(";
		}
		msg += std::to_string(params.size()) + " arguments).";
		throw ParseException(msg);
	}
	if (!has_params && args_specified) {
		string msg = "Macro " + name
				+ " does not expect any argumets or braces.";
		throw ParseException(msg);
	}
	// resolve default args
	if (args.size() < params.size()) {
		for (size_t i = args.size(); i < params.size(); i++) {
			auto missing_arg = default_args.find(params[i]);
			if (missing_arg != default_args.end()) {
				args.push_back(missing_arg->second);
			} else {
				break;
			}
		}
	}

	//printf("before replacement: %s\n",returnString.c_str());

	// the number of provided argument is fewer than the number defined by the prototype.
	// So we complete the list with default value.
	if (args.size() < params.size()) {
		auto orig_args_cnt = args.size();
		for (size_t i = args.size(); i < params.size(); i++) {
			auto def = default_args.find(params[i]);
			if (def == default_args.end()) {
				string msg = "Macro " + name + " missing value for parameter "
						+ params[i] + " ";
				bool is_last = i == params.size() - 1;
				if (!is_last)
					msg += "and for parameters after ";
				if (default_args.size()) {
					msg += "("
							+ std::to_string(
									params.size() - default_args.size())
							+ " to ";
				} else {
					msg += "(";
				}
				msg += std::to_string(params.size())
						+ " arguments expected but " + to_string(orig_args_cnt)
						+ " provided).";
				throw ParseException(msg);
			}
			args.push_back(def->second);
		}
	} else if (args.size() > params.size()) {
		string msg = "Macro " + name + " expected ";
		if (default_args.size()) {
			msg += std::to_string(params.size() - default_args.size()) + " to ";
		}
		msg += std::to_string(params.size()) + " arguments but "
				+ to_string(args.size()) + " provided.";
		throw ParseException(msg);
	}

	if (!body.empty()) {
		string res = body;
		_substituate.clear();
		look4stringLiteral(res);

		vector<string>::iterator macro = params.begin();
		vector<string>::iterator instance = args.begin();
		for (; macro != params.end(); macro++, instance++) {
			string rpld_argument = *instance;
			// if no argument was provided we use the default argument
			if (rpld_argument == ""
					&& default_args.find(*macro) != default_args.end()) {
				rpld_argument = default_args[*macro];
			}
			//printf("%s@%s@%s\n",returnString.c_str(),(*macro).c_str(),rpld_argument.c_str() );
			replaceAll(res, *macro, rpld_argument);
		}
		//printf("after replacement: %s\n",returnString.c_str());
		return res;
	}
	return "";
}

}
}
