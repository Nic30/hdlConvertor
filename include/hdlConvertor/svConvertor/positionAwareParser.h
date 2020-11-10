#pragma once

#include <hdlConvertor/hdlAst/hdlOpType.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/svConvertor/commentParser.h>

namespace hdlConvertor {
namespace sv {

class VerPositionAwareParser {
public:
	SVCommentParser &commentParser;
	bool hierarchyOnly;
	using sv2017Parser = sv2017_antlr::sv2017Parser;
	VerPositionAwareParser(SVCommentParser &commentParser, bool hierarchyOnly);
	VerPositionAwareParser(VerPositionAwareParser * other);
};

}
}
