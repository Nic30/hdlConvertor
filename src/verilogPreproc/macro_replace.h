#pragma once

#include  "macroPrototype.h"

class macro_replace_data {

	public:
	std::string tmplate;
	std::vector<std::string> args;
};

class macro_replace {


	void replaceAll(std::string& str, const std::string& from, const std::string& to);

	public:
	macro_replace_data data;
		macro_replace(std::string,std::vector<std::string>);
		~macro_replace();
		virtual std::string replace();
		virtual std::string replace(std::vector<std::string>);
		std::string getTmplate();

};
