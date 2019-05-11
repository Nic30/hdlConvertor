#pragma once

#include <assert.h>
#include "../debugConfig.h"
#include "jsonable.h"

namespace hdlConvertor {
namespace hdlObjects {

/*
 * Base class for HDL object with name
 * */
class Named {
public:
	char * name;

	Named();
#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
	void dump(int indent) const;
	~Named();
};

/*
 * Base class for HDL object with doc
 * */
class WithDoc {
public:
	std::string __doc__;
#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
	void dump(int indent) const;
};

/*
 * Base class for HDL object with name and doc
 * */
class WithNameAndDoc: public Named, public WithDoc {
public:
	WithNameAndDoc();
#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
	void dump(int indent) const;
};

}
}
