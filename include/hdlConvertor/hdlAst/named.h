#pragma once

#include <string>

#include <hdlConvertor/hdlAst/codePosition.h>

namespace hdlConvertor {
namespace hdlAst {

/*
 * Base class for HDL object with name
 * */
class Named {
public:
	std::string name;

	Named();
	Named(const std::string &name);
	virtual ~Named();
};

/*
 * Base class for HDL object with doc
 * */
class WithDoc {
public:
	std::string __doc__;
};

/*
 * Base class for HDL object with in code position specified
 * */
class WithPos {
public:
	CodePosition position;
};

/*
 * Base class for HDL object with name and doc
 * */
class WithNameAndDoc: public Named, public WithDoc, public WithPos {
public:
	WithNameAndDoc();
	WithNameAndDoc(const std::string &name);

};

}
}
