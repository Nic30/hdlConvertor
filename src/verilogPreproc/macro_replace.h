#pragma once

#include "../verilogPreproc/macroPrototype.h"

/**
 * class macro_replace_data is the object to represent macro data.
 * Example:
 *  `define my_super_macro(a,b) a + b ;
 *  "a + b ;" is store in the tmplate property
 *  while args is a simple vector of string to store the list of argument is
 *  apparition order.
 */
class macro_replace_data {

public:
	std::string tmplate;
	std::vector<std::string> args;
};

/**
 * class macro_replace is an object to manipulate macro_replace_data
 */
class macro_replace {

	void replaceAll(std::string& str, const std::string& from,
			const std::string& to);

public:
	macro_replace_data data;
    // class constructor
	macro_replace(std::string, std::vector<std::string>);
    // class desctructor
	virtual ~macro_replace();
	// replace method
    virtual std::string replace();
    // replace method without argument
	virtual std::string replace(std::vector<std::string>);

};
