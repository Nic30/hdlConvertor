#include "portParser.h"
#include "../notImplementedLogger.h"
#include "utils.h"
#include "exprParser.h"

using namespace std;
using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;
using namespace hdlConvertor::hdlObjects;

namespace hdlConvertor {
namespace verilog {

PortParser::PortParser(CommentParser & commentParser) :
		commentParser(commentParser) {
}

vector<Port*>* PortParser::addTypeSpecToPorts(Direction direction,
		Verilog2001Parser::Net_typeContext* net_type, bool signed_, bool reg_,
		string doc, Verilog2001Parser::Range_Context* range_,
		vector<Port*> * ports) {
	if ((net_type != nullptr) && (net_type->getText() != "wire")) {
		NotImplementedLogger::print(
				"PortParser.addTypeSpecToPorts.net_type different than wire");
	}
	bool first = true;
	for (auto p : *ports) {
		assert(!p->variable->type);
		if (first)
			p->variable->__doc__ = doc + p->variable->__doc__;
		p->variable->type = Utils::mkWireT(range_, signed_);
		p->direction = direction;
		p->variable->latched = reg_;
	}
	return ports;
}

vector<Port*>* PortParser::visitList_of_ports(
		Verilog2001Parser::List_of_portsContext* ctx) {
	// list_of_ports : '(' port ( ',' port )* ')' ;
	vector<Port*>* ports = new vector<Port*>();
	for (auto p : ctx->port()) {
		auto ps = visitPort(p);
		for (unsigned i = 0; i < ps->size(); i++) {
			ports->push_back((*ps)[i]);
		}
		delete ps;
	}
	return ports;
}
vector<Port*> * PortParser::visitPort(Verilog2001Parser::PortContext* ctx) {
	// port: port_expression?
	// | '.' port_identifier '(' ( port_expression )? ')'
	// ;
	auto pi = ctx->port_identifier();
	if (pi) {
		NotImplementedLogger::print(
				"Source_textParser.visitPort - port identifier");
		return new vector<Port*>();
	} else {
		return visitPort_expression(ctx->port_expression());
	}
}
vector<Port*> *PortParser::visitPort_expression(
		Verilog2001Parser::Port_expressionContext* ctx) {
	// port_expression :
	// port_reference
	// | '{' port_reference ( ',' port_reference )* '}'
	// ;
	vector<Port*> *ports = new vector<Port*>();
	if (ctx) {
		for (auto pr : ctx->port_reference()) {
			ports->push_back(visitPort_reference(pr));
		}
	}
	return ports;
}
Port * PortParser::visitPort_reference(
		Verilog2001Parser::Port_referenceContext* ctx) {
	// port_reference :
	// port_identifier
	// | port_identifier '[' constant_expression ']'
	// | port_identifier '[' range_expression ']'
	// ;
	// port_identifier : identifier ;

	Expr * t = NULL;
	auto c = ctx->constant_expression();
	if (c) {
		t = VerExprParser::visitConstant_expression(c);
	}
	auto r = ctx->range_expression();
	if (r)
		t = VerExprParser::visitRange_expression(r);

	auto variable = new Variable(
			ctx->port_identifier()->identifier()->getText().c_str(), t, NULL);
	return new Port(DIR_UNKNOWN, variable);

}
vector<Port*>* PortParser::visitList_of_port_declarations(
		Verilog2001Parser::List_of_port_declarationsContext* ctx) {
	// list_of_port_declarations
	// : '(' port_declaration ( ',' port_declaration )* ')'
	// | '(' ')'
	// ;
	auto ports = new vector<Port*>();
	for (auto pd : ctx->port_declaration()) {
		auto pds = visitPort_declaration(pd);
		for (unsigned i = 0; i < pds->size(); i++)
			ports->push_back((*pds)[i]);
		delete pds;
	}
	return ports;
}
vector<Port*> * PortParser::visitPort_declaration(
		Verilog2001Parser::Port_declarationContext* ctx) {
	// port_declaration :
	// attribute_instance* inout_declaration
	// | attribute_instance* input_declaration
	// | attribute_instance* output_declaration
	// ;
	string doc = commentParser.parse(ctx);
	// [TODO] attribs
	auto attribs = ctx->attribute_instance();
	if (attribs.size() > 0) {
		NotImplementedLogger::print(
				"ModuleParser.visitPort_declaration - attribs not implemented");
	}

	bool signed_ = Utils::is_signed(ctx);
	bool reg_ = false;
	{
		// inout_declaration : 'inout' ( net_type )? ( 'signed' )? ( range_ )?
		// list_of_port_identifiers ;
		auto inout = ctx->inout_declaration();
		if (inout) {
			auto ports = visitList_of_port_identifiers(
					inout->list_of_port_identifiers());
			return addTypeSpecToPorts(DIR_INOUT, inout->net_type(), signed_,
					reg_, doc, inout->range_(), ports);
		}
	}
	{
		// input_declaration : 'input' ( net_type )? ( 'signed' )? ( range_ )?
		//                      list_of_port_identifiers ;
		auto input = ctx->input_declaration();
		if (input) {
			auto ports = visitList_of_port_identifiers(
					input->list_of_port_identifiers());
			return addTypeSpecToPorts(DIR_IN, input->net_type(), signed_, reg_,
					doc, input->range_(), ports);
		}
	}
	{
		// output_declaration
		//    : 'output' (net_type)? ('signed')? (range_)? list_of_port_identifiers
		//    | 'output' ('reg')? ('signed')? (range_)? list_of_port_identifiers
		//    | 'output' 'reg' ('signed')? (range_)? list_of_variable_port_identifiers
		//    | 'output' (output_variable_type)? list_of_port_identifiers
		//    | 'output' output_variable_type list_of_variable_port_identifiers
		//    ;
		auto od = ctx->output_declaration();
		reg_ = Utils::is_reg(od);
		signed_ = Utils::is_signed(od);
		vector<Port*> * ports;
		auto lovpi = od->list_of_variable_port_identifiers();
		if (lovpi) {
			ports = visitList_of_variable_port_identifiers(lovpi);
		} else {
			ports = visitList_of_port_identifiers(
					od->list_of_port_identifiers());
		}
		return addTypeSpecToPorts(DIR_OUT, od->net_type(), signed_, reg_, doc,
				od->range_(), ports);
	}
}
vector<Port*> * PortParser::visitList_of_port_identifiers(
		Verilog2001Parser::List_of_port_identifiersContext* ctx) {
	// list_of_port_identifiers :
	// port_identifier ( ',' port_identifier )*
	// ;
	vector<Port*> * ports = new vector<Port*>();
	for (auto pi : ctx->port_identifier()) {
		ports->push_back(visitPort_identifier(pi));
	}
	return ports;
}
Port * PortParser::visitPort_identifier(
		Verilog2001Parser::Port_identifierContext* ctx) {
	// port_identifier : identifier ;
	Variable * v = new Variable(ctx->identifier()->getText(), NULL, NULL);
	return new Port(DIR_UNKNOWN, v);
}
vector<Port*> *PortParser::visitList_of_variable_port_identifiers(
		Verilog2001Parser::List_of_variable_port_identifiersContext* ctx) {
	// list_of_variable_port_identifiers :
	// port_identifier ( '=' constant_expression )? ( ',' port_identifier (
	// '=' constant_expression )? )* ;
	vector<Port*>* ports = new vector<Port*>();
	Port * last = NULL;
	for (auto n : ctx->children) {
		auto cec =
				dynamic_cast<Verilog2001Parser::Constant_expressionContext*>(n);
		if (cec) {
			last->variable->value = VerExprParser::visitConstant_expression(
					cec);
		} else {
			auto pic =
					dynamic_cast<Verilog2001Parser::Port_identifierContext*>(n);
			last = visitPort_identifier(pic);
			ports->push_back(last);
		}
	}
	return ports;
}

}
}
