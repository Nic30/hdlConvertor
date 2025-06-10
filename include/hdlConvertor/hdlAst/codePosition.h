#pragma once
#include <stddef.h>
#include <limits>

#include <hdlConvertor/hdlConvertorToken.h>

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
	static constexpr char INVALID_STR[] = "<INVSTR>";

	size_t start_line;
	size_t stop_line;
	size_t start_column;
	size_t stop_column;
	std::string file_name;

	CodePosition();
	CodePosition(size_t startLine, size_t stopLine, size_t startColumn,
			size_t stopColumn, std::string fileName);
	template<class ELEM_T>
	void update_from_elem(ELEM_T *elem) {
		/*
		 * Cast antlr4::CommonToken to our custum hdlConvertorToken
		 * So we can retrive the file name information of origin of
		 * current token.
		 */
		hdlConvertor::hdlConvertorToken * tokenStart_ptr = dynamic_cast<hdlConvertor::hdlConvertorToken *>(elem->getStart());
		hdlConvertor::hdlConvertorToken * tokenStop_ptr = dynamic_cast<hdlConvertor::hdlConvertorToken *>(elem->getStop());
		
		/* pick up data from token */
		start_line = tokenStart_ptr->getLine();
		stop_line = tokenStop_ptr->getLine();
		start_column = tokenStart_ptr->getCharPositionInLine() + 1;
		stop_column = tokenStop_ptr->getCharPositionInLine() +
				(tokenStop_ptr->getStopIndex() - tokenStop_ptr->getStartIndex()) + 1;
		file_name = tokenStart_ptr->getSrcName();
	}
	bool isKnown() const;
};

}
}
