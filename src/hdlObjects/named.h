#pragma once

#include <assert.h>
#include "../debugConfig.h"
#include "jsonable.h"

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
