#include "attributeParser.h"
#include "../notImplementedLogger.h"

using namespace Verilog2001;

std::vector<Expr*>* AttributeParser::visitAttribute_instance(
		Verilog2001Parser::Attribute_instanceContext * ctx) {
	// attribute_instance : '(' '*' attr_spec ( ',' attr_spec )* '*' ')' ;
	NotImplementedLogger::print("AttributeParser.visitAttribute_instance");
	return nullptr;
}
