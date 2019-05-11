#include "../verilogPreproc/macro_replace_sv.h"

using namespace std;

namespace hdlConvertor {
namespace verilog_pp {

macro_replace_sv::macro_replace_sv(string macro_name, string replace,
		vector<string> arg, map<string, string> default_maps) :
		macro_replace(macro_name, replace, arg) {
	_default_map = default_maps;
}

string macro_replace_sv::replace() {
	vector<string> null_vector;
	return replace(null_vector);
}

string macro_replace_sv::replace(vector<string> arg) {
	/*
	 printf("---------------\n");
	 for (auto a:arg) {
	 printf("  =%s*\n",a.c_str());
	 }

	 for (auto a:_default_map) {
	 printf("%s : %s\n",a.first.c_str(),a.second.c_str());
	 }
	 printf("---------------\n");

	 */
	string returnString;

	if (arg.size() < data.args.size()) {
		for (size_t i = arg.size(); i < data.args.size(); i++) {
			auto missing_arg = _default_map.find(data.args[i]);
			if (missing_arg != _default_map.end()) {
				arg.push_back(missing_arg->second);
			} else {
				goto exit_label;
			}
		}
	}

	exit_label: if (!data.tmplate.empty()) {
		returnString = data.tmplate;

		//printf("before replacement: %s\n",returnString.c_str());

		if (arg.size() != data.args.size()) {
			string message =
					"Missmatch in number of argument macro declaration "
							+ data.tmplate_name + " ("
							+ to_string(data.args.size())
							+ ") and macro usage (" + to_string(arg.size())
							+ ')';
			throw ParseException(message);
		}

		// the number of provided argument is fewer than the number defined by the prototype.
		// So we complete the list with default value.
		if (arg.size() < data.args.size()) {
			size_t i;
			if (arg.size() > 0) {
				i = arg.size();
			} else {
				i = 0;
			}

			for (; i < data.args.size(); i++) {
				if (_default_map.find(data.args[i]) == _default_map.end()) {
					//throw
				}
				arg.push_back(_default_map[data.args[i]]);
			}
		} else if (arg.size() > data.args.size()) {
			//throw
		}

		_substituate.clear();
		look4stringLiteral(returnString);

		vector<string>::iterator macro = data.args.begin();
		vector<string>::iterator instance = arg.begin();
		for (; macro != data.args.end(); macro++, instance++) {
			string rpld_argument = *instance;
			// if no argument was provided we use the default argument
			if (rpld_argument == ""
					&& _default_map.find(*macro) != _default_map.end()) {
				rpld_argument = _default_map[*macro];
			}
			//printf("%s@%s@%s\n",returnString.c_str(),(*macro).c_str(),rpld_argument.c_str() );
			replaceAll(returnString, *macro, rpld_argument);
		}
		//printf("after replacement: %s\n",returnString.c_str());
	} else {
		//Macro can be empty
		//Example `define MODE1
		returnString = "";
	}
	return returnString;

}

}
}
