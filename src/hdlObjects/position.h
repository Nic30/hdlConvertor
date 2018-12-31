#pragma once

#include <vector>
#include "jsonable.h"
#include <assert.h>
#include "named.h"

class Position {
public:
	size_t startLine;
	size_t stopLine;
	size_t startColumn;
	size_t stopColumn;

Position(size_t startLine, size_t stopLine, size_t startColumn, size_t stopColumn);
#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
	void dump(int indent) const;
	~Position();
};
