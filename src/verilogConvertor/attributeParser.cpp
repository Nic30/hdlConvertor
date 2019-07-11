#include <hdlConvertor/verilogConvertor/attributeParser.h>
#include <hdlConvertor/notImplementedLogger.h>

namespace hdlConvertor {
namespace verilog {

using namespace Verilog2001_antlr;
using namespace hdlConvertor::hdlObjects;

std::vector<iHdlExpr*>* AttributeParser::visitAttribute_instance(
		Verilog2001Parser::Attribute_instanceContext * ctx) {
	// attribute_instance : '(' '*' attr_spec ( ',' attr_spec )* '*' ')' ;
	NotImplementedLogger::print("AttributeParser.visitAttribute_instance", ctx);
	return nullptr;
}

}
}
