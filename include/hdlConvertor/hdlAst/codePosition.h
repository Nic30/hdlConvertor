#pragma once
#include <stddef.h>
#include <limits>

namespace hdlConvertor {
namespace hdlAst {

/*
 * Container for position in code.
 * NOTE: stopXX are inclusive coordinates and not one beyond i.e. [startXXX, stopXXX] and not [startXXX, stopXXX)
 * Also, coordinates are 1-based indexing i.e. first line and column is indexed as 1 and not 0.
 * */
class CodePosition {
public:
	static constexpr size_t INVALID = std::numeric_limits<size_t>::max();

	size_t start_line;
	size_t stop_line;
	size_t start_column;
	size_t stop_column;

	CodePosition();
	CodePosition(size_t startLine, size_t stopLine, size_t startColumn,
			size_t stopColumn);
	template<class ELEM_T>
	void update_from_elem(ELEM_T *elem) {
		start_line = elem->getStart()->getLine();
		stop_line = elem->getStop()->getLine();
		start_column = elem->getStart()->getCharPositionInLine() + 1;
		stop_column = elem->getStop()->getCharPositionInLine() +
				(elem->getStop()->getStopIndex() - elem->getStop()->getStartIndex()) + 1;
	}
	bool isKnown() const;
};

}
}
