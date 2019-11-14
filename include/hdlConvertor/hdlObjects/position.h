#pragma once
#include <stddef.h>
#include <limits>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * Container for position in code.
 * NOTE: stopXX are inclusive coordinates and not one beyond i.e. [startXXX, stopXXX] and not [startXXX, stopXXX)
 * Also, corrdinates are 1-based indexing i.e. first line and column is indexed as 1 and not 0.
 * */
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
	template<class ELEM_T>
	void update_from_elem(ELEM_T *elem) {
		startLine = elem->getStart()->getLine();
		stopLine = elem->getStop()->getLine();
		startColumn = elem->getStart()->getCharPositionInLine() + 1;
		stopColumn = elem->getStop()->getCharPositionInLine() +
				(elem->getStop()->getStopIndex() - elem->getStop()->getStartIndex()) + 1;
	}
	bool isKnown() const;
};

}
}
