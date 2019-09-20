#include <cctype>
#include <algorithm>
#include <sstream>
#include <assert.h>
#include <iostream>

#include <hdlConvertor/verilogPreproc/macro_def_verilog.h>

namespace hdlConvertor {
namespace verilog_pp {

using namespace std;

MacroDefVerilog::MacroDefVerilog(const string &_name, bool _has_params,
		const vector<param_info_t> &_params, const string &_body) :
		aMacroDef(_name), has_params(_has_params), params(_params) {
	parse_body(_params, _body, body);
}

std::pair<size_t, size_t> MacroDefVerilog::get_possible_arg_cnt() const {
	size_t max_arg_cnt = params.size();
	size_t optional_arg_cnt = 0;
	for (auto &p : params) {
		if (p.has_def_val)
			optional_arg_cnt++;
	}
	return {max_arg_cnt- optional_arg_cnt, max_arg_cnt};
}
string MacroDefVerilog::get_possible_arg_cnt_str() const {
	auto cnt = get_possible_arg_cnt();
	if (cnt.first != cnt.second) {
		return std::to_string(cnt.first) + " to " + std::to_string(cnt.second);
	} else {
		return std::to_string(cnt.second);
	}
}

void MacroDefVerilog::parse_body(const std::vector<param_info_t> &params,
		const std::string &body, std::vector<MacroDefVerilog::Fragment> &res) {
	collect_string_intervals(body);
	bool no_body = body.size() == 0;
	if (no_body || params.size() == 0) {
		if (!no_body)
			res.push_back(body);
		return;
	}

	// {position, param_index}
	vector<pair<size_t, size_t>> found_param_usage;
	found_param_usage.reserve(params.size());

	for (size_t p_i = 0; p_i < params.size(); p_i++) {
		const auto &p = params[p_i];
		size_t start_pos = 0;
		while ((start_pos = body.find(p.name, start_pos)) != string::npos) {
			if (start_pos > 0) {
				auto c_pre = body[start_pos - 1];
				auto is_part_of_literal = isalnum(c_pre) || '_' == c_pre
						|| '$' == c_pre;
				if (is_part_of_literal) {
					start_pos += 1;
					continue;
				}
			}
			auto c_post = body[start_pos + p.name.length()];

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
			auto is_part_of_literal = isalnum(c_post) || '_' == c_post
					|| '$' == c_post || '(' == c_post || '[' == c_post
					|| '{' == c_post;
			//check the find is in the result of a substitution of the same
			// macro_replacement

			if (is_part_of_literal) {
				start_pos += 1;
				continue;
			}
			auto s = check_is_in_string(start_pos);
			if (s) {
				assert(start_pos < s->first + s->second);
				start_pos = s->first + s->second;
				continue;
			}
			found_param_usage.push_back( { start_pos, p_i });
			start_pos += 1;
		}
	}
	sort(found_param_usage.begin(), found_param_usage.end());
	size_t start = 0;
	for (auto fp : found_param_usage) {
		if (start < fp.first) {
			// add string before param usage
			auto s = body.substr(start, fp.first - start);
			res.push_back(Fragment(s));
		}
		res.push_back(Fragment(fp.second));
		start = fp.first + params[fp.second].name.length();
	}
	if (start != body.length()) {
		auto s = body.substr(start);
		res.push_back(Fragment(s));
	}
}

// return false to skip this find because it is
// from an already substitution of the same macro replacement
std::pair<size_t, size_t>* MacroDefVerilog::check_is_in_string(size_t start) {
	for (auto &p : _string_intervals) {
		if ((p.first <= start) && (start < p.first + p.second)) {
			return &p;
		}
	}
	return nullptr;
}
/*
 * Look for String literal. In order to forbid them to be change by replacement
 */
void MacroDefVerilog::collect_string_intervals(const string &tmpl) {
	size_t start_pos = 0;
	auto npos = string::npos;
	size_t prev_start_pos = npos;
	while ((start_pos = tmpl.find('"', start_pos)) != npos) {
		// if " is not part of `" or \"
		bool is_escaped = (start_pos != 0
				&& (tmpl[start_pos - 1] == '`' || tmpl[start_pos - 1] == '\\'));
		if (!is_escaped) {
			if (prev_start_pos == npos) {
				prev_start_pos = start_pos;
			} else {
				size_t length = start_pos - prev_start_pos;
				_string_intervals.push_back(make_pair(prev_start_pos, length));
				prev_start_pos = npos;
			}
		}
		start_pos += 1;
	}
	if (prev_start_pos != npos)
		throw ParseException(
				"Unfinished string in definition of macro " + name + ".");
}

bool MacroDefVerilog::requires_args() {
	return has_params;
}

string MacroDefVerilog::replace(std::vector<std::string> args,
		bool args_specified, VerilogPreproc*, antlr4::ParserRuleContext*) {
	if (has_params && !args_specified) {
		string msg = "Macro " + name + " requires braces and expects ";
		msg += get_possible_arg_cnt_str() + " arguments.";
		throw ParseException(msg);
	}
	if (!has_params && args_specified) {
		throw_doest_not_support_args();
	}

	// the number of provided argument is fewer than the number defined by the prototype.
	// So we complete the list with default value.
	if (args.size() <= params.size()) {
		auto orig_args_cnt = args.size();
		for (size_t i = 0; i < params.size(); i++) {
			bool value_required = i >= orig_args_cnt;
			bool use_defult_value = value_required || args[i].length() == 0;
			if (use_defult_value) {
				const auto &p = params[i];
				if (!p.has_def_val) {
					if (!value_required)
						continue;
					if (args.size() == 0) {
						// `macro() -> there is actualy arg ""
						args.push_back("");
						continue;
					}
					string msg = "Macro " + name
							+ " missing value for parameter " + p.name + " ";
					bool is_last = i == params.size() - 1;
					if (!is_last)
						msg += "and for parameters after ";
					msg += "(" + get_possible_arg_cnt_str()
							+ " arguments expected but "
							+ to_string(orig_args_cnt) + " provided).";
					throw ParseException(msg);
				}
				if (i < orig_args_cnt) {
					args[i] = p.def_val;
				} else {
					args.push_back(p.def_val);
				}

			}
		}
	} else if (args.size() > params.size()) {
		string msg = "Macro " + name + " expected " + get_possible_arg_cnt_str()
				+ " arguments but " + to_string(args.size()) + " provided.";
		throw ParseException(msg);
	}

	if (!body.empty()) {
		stringstream res;
		for (const auto &elem : body) {
			if (elem.arg_no < 0) {
				res << elem.str;
			} else {
				res << args.at(elem.arg_no);
			}
		}
		return res.str();
	}
	return "";
}

}
}
