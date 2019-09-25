#pragma once

#include <vector>

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>

namespace hdlConvertor {
namespace sv {

class AttributeParser {
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;

	static std::vector<hdlObjects::iHdlExpr*>* visitAttribute_instance(
			sv2017Parser::Attribute_instanceContext * ctx);
};

}
}
