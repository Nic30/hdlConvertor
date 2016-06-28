#pragma once

#include <Python.h>
#include "jsonable.h"

class Named {
public:
	char * name;
	Named();
	PyObject * toJson() const;
	void dump(int indent) const;
	~Named();
};
