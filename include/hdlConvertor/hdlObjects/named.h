#pragma once

#include <string>
#include <hdlConvertor/hdlObjects/position.h>

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
	Position position;
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
