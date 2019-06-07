#include <hdlConvertor/hdlObjects/position.h>

namespace hdlConvertor {
namespace hdlObjects {

Position::Position() :
		Position(INVALID, INVALID, INVALID, INVALID) {
}

Position::Position(size_t startLine, size_t stopLine, size_t startColumn,
		size_t stopColumn) {
	this->startLine = startLine;
	this->stopLine = stopLine;
	this->startColumn = startColumn;
	this->stopColumn = stopColumn;
}

bool Position::isKnown() const {
	return startLine != INVALID || stopLine != INVALID || startColumn != INVALID
			|| stopColumn != INVALID;
}

}
}
