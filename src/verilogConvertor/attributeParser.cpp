#include "attributeParser.h"

std::vector<Variable*>* AttributeParser::visitAttribute_instance(
		Ref<Verilog2001Parser::Attribute_instanceContext> ctx) {
	// attribute_instance : '(' '*' attr_spec ( ',' attr_spec )* '*' ')' ;
	NotImplementedLogger::print("AttributeParser.visitAttribute_instance");
	return new std::vector<Variable*>();
}
