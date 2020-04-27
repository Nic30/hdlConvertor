#pragma once

#include <string>

#include <hdlConvertor/hdlObjects/codePosition.h>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * Base class for HDL object with name
 * */
class Named {
public:
	std::string name;

	Named();
	Named(const std::string &name);
	~Named();
};

/*
 * Base class for HDL object with doc
 * */
class WithDoc {
public:
	std::string __doc__;
	~WithDoc();
};

/*
 * Base class for HDL object with in code position specified
 * */
class WithPos {
public:
	CodePosition position;
	~WithPos();
};

/*
 * Base class for HDL object with name and doc
 * */
class WithNameAndDoc: public WithPos, public WithDoc, public Named {
public:
	WithNameAndDoc();
	WithNameAndDoc(const std::string &name);
	~WithNameAndDoc();
};

}
}
