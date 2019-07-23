#pragma once
#include <stddef.h>
#include <limits>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * Container for position in code
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
	}
	bool isKnown() const;
};

}
}
