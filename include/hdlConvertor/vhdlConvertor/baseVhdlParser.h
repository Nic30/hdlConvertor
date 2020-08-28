#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/commentParser.h>

namespace hdlConvertor {
namespace vhdl {

class BaseVhdlParser {
public:
	VhdlCommentParser &commentParser;
	bool hierarchyOnly;

	BaseVhdlParser(VhdlCommentParser &commentParser, bool _hierarchyOnly);
	BaseVhdlParser(BaseVhdlParser & parent);
};

}
}
