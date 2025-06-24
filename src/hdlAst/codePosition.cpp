#include <hdlConvertor/hdlAst/codePosition.h>

namespace hdlConvertor {
namespace hdlAst {

CodePosition::CodePosition() :
		CodePosition(INVALID, INVALID, INVALID, INVALID,INVALID_STR) {
}

CodePosition::CodePosition(size_t startLine, size_t stopLine, size_t startColumn,
		size_t stopColumn,std::string fileName) {
	this->start_line = startLine;
	this->stop_line = stopLine;
	this->start_column = startColumn;
	this->stop_column = stopColumn;
	this->file_name = fileName;
}

bool CodePosition::isKnown() const {
	return start_line != INVALID || stop_line != INVALID || start_column != INVALID
			|| stop_column != INVALID || file_name != INVALID_STR;
}

}
}
