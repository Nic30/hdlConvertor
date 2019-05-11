#include "attributeParser.h"
#include "../notImplementedLogger.h"

using namespace Verilog2001_antlr;
using namespace hdlConvertor::hdlObjects;

namespace hdlConvertor {
namespace verilog {

std::vector<Expr*>* AttributeParser::visitAttribute_instance(
		Verilog2001Parser::Attribute_instanceContext * ctx) {
	// attribute_instance : '(' '*' attr_spec ( ',' attr_spec )* '*' ')' ;
	NotImplementedLogger::print("AttributeParser.visitAttribute_instance");
	return nullptr;
}

}
}
