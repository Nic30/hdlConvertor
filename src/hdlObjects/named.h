#pragma once
#include <string>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * Base class for HDL object with name
 * */
class Named {
public:
	char * name;

	Named();
	Named(char * name);
	~Named();
};

/*
 * Base class for HDL object with doc
 * */
class WithDoc {
public:
	std::string __doc__;
};

/*
 * Base class for HDL object with name and doc
 * */
class WithNameAndDoc: public Named, public WithDoc {
public:
	WithNameAndDoc();
	WithNameAndDoc(char * name);

};

}
}
