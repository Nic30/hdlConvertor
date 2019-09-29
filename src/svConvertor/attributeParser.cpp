#include "../../include/hdlConvertor/svConvertor/attributeParser.h"

#include <hdlConvertor/notImplementedLogger.h>

namespace hdlConvertor {
namespace sv {

using namespace sv2017_antlr;
using namespace hdlConvertor::hdlObjects;

std::vector<iHdlExpr*>* VerAttributeParser::visitAttribute_instance(
		sv2017Parser::Attribute_instanceContext * ctx) {
	// attribute_instance : '(' '*' attr_spec ( ',' attr_spec )* '*' ')' ;
	NotImplementedLogger::print("AttributeParser.visitAttribute_instance", ctx);
	return nullptr;
}

}
}
