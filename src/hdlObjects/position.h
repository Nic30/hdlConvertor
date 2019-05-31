#pragma once
#include <stddef.h>
#include <limits>


namespace hdlConvertor {
namespace hdlObjects {

class Position {
public:
	static constexpr size_t INVALID = std::numeric_limits<size_t>::max();

	size_t startLine;
	size_t stopLine;
	size_t startColumn;
	size_t stopColumn;

	Position();
	Position(size_t startLine, size_t stopLine, size_t startColumn,
			size_t stopColumn);
	bool isKnown() const;
};

}
}
