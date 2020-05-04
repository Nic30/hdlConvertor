#pragma once

#include <vector>

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>

namespace hdlConvertor {
namespace sv {

class VerAttributeParser {
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;

	static void visitAttribute_instance(
			sv2017Parser::Attribute_instanceContext *ctx);
	static void visitAttribute_instance(
			std::vector<sv2017Parser::Attribute_instanceContext*> ctx);
};

}
}
