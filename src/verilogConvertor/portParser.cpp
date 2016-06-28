#include "portParser.h"

std::vector<Port*>* PortParser::addTypeSpecToPorts(
		Direction direction,
		Ref<Verilog2001Parser::Net_typeContext> net_type,
		bool _signed,
		Ref<Verilog2001Parser::RangeContext> range,
		std::vector<Port*> * ports) {
	// [TODO] signed, net_type
	Expr* t = Utils::mkWireT(range);

	for (auto p : *ports) {
		assert(!p->variable->type);
		p->variable->type = t;
		p->direction = direction;
	}
	return ports;
}

std::vector<Port*>* PortParser::visitList_of_ports(
		Ref<Verilog2001Parser::List_of_portsContext> ctx) {
	// list_of_ports : '(' port ( ',' port )* ')' ;
	std::vector<Port*>* ports = new std::vector<Port*>();
	for (auto p : ctx->port()) {
		auto ps = visitPort(p);
		for (unsigned i = 0; i < ps->size(); i++) {
			ports->push_back((*ps)[i]);
		}
		delete ps;
	}
	return ports;
}
std::vector<Port*> * PortParser::visitPort(
		Ref<Verilog2001Parser::PortContext> ctx) {
	// port: port_expression?
	// | '.' port_identifier '(' ( port_expression )? ')'
	// ;
	auto pi = ctx->port_identifier();
	if (pi) {
		NotImplementedLogger::print(
				"Source_textParser.visitPort - port identifier");
		return new std::vector<Port*>();
	} else {
		return visitPort_expression(ctx->port_expression());
	}
}
std::vector<Port*> *PortParser::visitPort_expression(
		Ref<Verilog2001Parser::Port_expressionContext> ctx) {
	// port_expression :
	// port_reference
	// | '{' port_reference ( ',' port_reference )* '}'
	// ;
	std::vector<Port*> *ports = new std::vector<Port*>();
	for (auto pr : ctx->port_reference()) {
		ports->push_back(visitPort_reference(pr));
	}
	return ports;
}
Port * PortParser::visitPort_reference(
		Ref<Verilog2001Parser::Port_referenceContext> ctx) {
	// port_reference :
	// port_identifier
	// | port_identifier '[' constant_expression ']'
	// | port_identifier '[' range_expression ']'
	// ;
	// port_identifier : identifier ;
	Port * p = new Port();

	Expr * t = NULL;
	auto c = ctx->constant_expression();
	if (c) {
		t = VerExprParser::visitConstant_expression(c);
	}
	auto r = ctx->range_expression();
	if (r)
		t = VerExprParser::visitRange_expression(r);

	p->variable = new Variable(
			ctx->port_identifier()->identifier()->getText().c_str(), t, NULL);
	return p;

}
std::vector<Port*>* PortParser::visitList_of_port_declarations(
		Ref<Verilog2001Parser::List_of_port_declarationsContext> ctx) {
	// list_of_port_declarations
	// : '(' port_declaration ( ',' port_declaration )* ')'
	// | '(' ')'
	// ;
	auto ports = new std::vector<Port*>();
	for (auto pd : ctx->port_declaration()) {
		auto pds = visitPort_declaration(pd);
		for (unsigned i = 0; i < pds->size(); i++)
			ports->push_back((*pds)[i]);
		delete pds;
	}
	return ports;
}
std::vector<Port*> * PortParser::visitPort_declaration(
		Ref<Verilog2001Parser::Port_declarationContext> ctx) {
	// port_declaration :
	// attribute_instance* inout_declaration
	// | attribute_instance* input_declaration
	// | attribute_instance* output_declaration
	// ;

	// [TODO] signed, attribs
	auto attribs = ctx->attribute_instance();
	if (attribs.size() > 0) {
		NotImplementedLogger::print(
				"ModuleParser.visitPort_declaration - attribs not implemented");
	}

	// inout_declaration : 'inout' ( net_type )? ( 'signed' )? ( range )?
	// list_of_port_identifiers ;
	auto inout = ctx->inout_declaration();
	if (inout)
		return addTypeSpecToPorts(INOUT, inout->net_type(), false,
				inout->range(),
				visitList_of_port_identifiers(
						inout->list_of_port_identifiers()));

	// input_declaration : 'input' ( net_type )? ( 'signed' )? ( range )?
	// list_of_port_identifiers ;
	auto input = ctx->input_declaration();
	if (input)
		return addTypeSpecToPorts(IN, input->net_type(), false, input->range(),
				visitList_of_port_identifiers(
						input->list_of_port_identifiers()));

	// output_declaration :
	// 'output' ( net_type )? ( 'signed' )? ( range )?
	// list_of_port_identifiers
	// | 'output' ( 'reg' )? ( 'signed' )? ( range )?
	// list_of_port_identifiers
	// | 'output' 'reg' ( 'signed' )? ( range )?
	// list_of_variable_port_identifiers
	// | 'output' ( output_variable_type )? list_of_port_identifiers
	// | 'output' output_variable_type list_of_variable_port_identifiers
	// ;
	auto output = ctx->output_declaration();
	std::vector<Port*> * ports;
	if (output->list_of_variable_port_identifiers()) {
		ports = visitList_of_variable_port_identifiers(
				output->list_of_variable_port_identifiers());
	} else {
		ports = visitList_of_port_identifiers(
				output->list_of_port_identifiers());
	}

	return addTypeSpecToPorts(OUT, output->net_type(), false, output->range(),
			ports);
}
std::vector<Port*> * PortParser::visitList_of_port_identifiers(
		Ref<Verilog2001Parser::List_of_port_identifiersContext> ctx) {
	// list_of_port_identifiers :
	// port_identifier ( ',' port_identifier )*
	// ;
	std::vector<Port*> * ports = new std::vector<Port*>();
	for (auto pi : ctx->port_identifier()) {
		ports->push_back(visitPort_identifier(pi));
	}
	return ports;
}
Port * PortParser::visitPort_identifier(
		Ref<Verilog2001Parser::Port_identifierContext> ctx) {
	// port_identifier : identifier ;
	Variable * v = new Variable(ctx->identifier()->getText(), NULL, NULL);
	Port * p = new Port();
	p->variable = v;
	return p;
}
std::vector<Port*> *PortParser::visitList_of_variable_port_identifiers(
		Ref<Verilog2001Parser::List_of_variable_port_identifiersContext> ctx) {
	// list_of_variable_port_identifiers :
	// port_identifier ( '=' constant_expression )? ( ',' port_identifier (
	// '=' constant_expression )? )* ;
	std::vector<Port*>* ports = new std::vector<Port*>();
	Port * last = NULL;
	for (auto n : ctx->children) {
		auto cec = std::dynamic_pointer_cast<
				Verilog2001Parser::Constant_expressionContext>(n);
		if (cec) {
			last->variable->value = VerExprParser::visitConstant_expression(
					cec);
		} else {
			auto pic = std::dynamic_pointer_cast<
					Verilog2001Parser::Port_identifierContext>(n);
			last = visitPort_identifier(pic);
			ports->push_back(last);
		}
	}
	return ports;
}
