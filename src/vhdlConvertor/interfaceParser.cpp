#include "interfaceParser.h"
#include "exprParser.h"
#include "directionParser.h"
#include "../notImplementedLogger.h"

namespace hdlConvertor {
namespace vhdl {

using std::vector;
using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlObjects;

vector<Variable*> * InterfaceParser::extractVariables(
		vhdlParser::Identifier_listContext* identifier_list,
		vhdlParser::Subtype_indicationContext* subType,
		vhdlParser::ExpressionContext* _expr) {
	vector<Variable*> * vl = new vector<Variable*>();
	Expr * _type = ExprParser::visitSubtype_indication(subType);
	Expr * expr = NULL;
	if (_expr)
		expr = ExprParser::visitExpression(_expr);

	bool firstIt = true;
	for (auto i : identifier_list->identifier()) {
		// identifier_list
		// : identifier ( COMMA identifier )*
		// ;
		if (!firstIt)
			_type = new Expr(*_type);
		Expr * __expr;
		if (!expr) {
			__expr = nullptr;
			firstIt = false;
		} else if (firstIt) {
			firstIt = false;
			__expr = expr;
		} else {
			__expr = new Expr(*expr);
		}
		Variable * v = new Variable(i->getText(), _type, __expr);
		vl->push_back(v);
	}
	return vl;
}
vector<Port*> * InterfaceParser::visitInterface_port_declaration(
		vhdlParser::Interface_port_declarationContext* ctx) {
	vector<Port*> * pl = new vector<Port*>();
	// interface_port_declaration
	// : identifier_list COLON signal_mode subtype_indication
	// ( BUS )? ( VARASGN expression )?
	// ;
	vector<Variable*>* vl = extractVariables(ctx->identifier_list(),
			ctx->subtype_indication(), ctx->expression());
	// signal_mode
	// : IN
	// | OUT
	// | INOUT
	// | BUFFER
	// | LINKAGE
	// ;
	Direction d = Direction_from(ctx->signal_mode());
	for (auto v : *vl) {
		Port * p = new Port(d, v);
		pl->push_back(p);
	}
	delete vl;
	return pl;
}
vector<Variable*> * InterfaceParser::visitInterface_constant_declaration(
		vhdlParser::Interface_constant_declarationContext* ctx) {
	// interface_constant_declaration
	// : ( CONSTANT )? identifier_list COLON ( IN )? subtype_indication
	// ( VARASGN expression )?
	// ;
	return extractVariables(ctx->identifier_list(), ctx->subtype_indication(),
			ctx->expression());

}
vector<Variable*> * InterfaceParser::visitInterface_signal_declaration(
		vhdlParser::Interface_signal_declarationContext* ctx) {
	// interface_signal_declaration
	// : SIGNAL identifier_list COLON subtype_indication
	// ( BUS )? ( VARASGN expression )?
	// ;
	return new vector<Variable*>();
}
vector<Variable*> * InterfaceParser::visitInterface_variable_declaration(
		vhdlParser::Interface_variable_declarationContext* ctx) {
	// interface_variable_declaration
	// : ( VARIABLE )? identifier_list COLON
	// ( signal_mode )? subtype_indication ( VARASGN expression )?
	// ;
	NotImplementedLogger::print(
			"InterfaceParser.visitInterface_variable_declaration");
	return new vector<Variable*>();
}
vector<Variable*> * InterfaceParser::visitInterface_file_declaration(
		vhdlParser::Interface_file_declarationContext* ctx) {
	// interface_file_declaration
	// : FILE identifier_list COLON subtype_indication
	// ;
	NotImplementedLogger::print(
			"InterfaceParser.visitInterface_file_declaration");
	return new vector<Variable*>();
}
vector<Variable*> * InterfaceParser::visitInterface_terminal_declaration(
		vhdlParser::Interface_terminal_declarationContext* ctx) {
	// interface_terminal_declaration
	// : TERMINAL identifier_list COLON subnature_indication
	// ;
	NotImplementedLogger::print(
			"InterfaceParser.visitInterface_terminal_declaration");
	return new vector<Variable*>();
}
vector<Variable*> * InterfaceParser::visitInterface_quantity_declaration(
		vhdlParser::Interface_quantity_declarationContext* ctx) {
	// interface_quantity_declaration
	// : QUANTITY identifier_list COLON ( IN | OUT )? subtype_indication
	// ( VARASGN expression )?
	// ;
	NotImplementedLogger::print(
			"InterfaceParser.visitInterface_quantity_declaration");
	return new vector<Variable*>();
}
vector<Variable*> * InterfaceParser::visitInterface_declaration(
		vhdlParser::Interface_declarationContext* ctx) {
	// interface_declaration
	// : interface_constant_declaration
	// | interface_signal_declaration
	// | interface_variable_declaration
	// | interface_file_declaration
	// | interface_terminal_declaration
	// | interface_quantity_declaration
	// ;
	auto c = ctx->interface_constant_declaration();
	if (c) {
		return visitInterface_constant_declaration(c);
	}
	auto s = ctx->interface_signal_declaration();
	if (s) {
		return visitInterface_signal_declaration(s);
	}
	auto v = ctx->interface_variable_declaration();
	if (v) {
		return visitInterface_variable_declaration(v);
	}
	auto f = ctx->interface_file_declaration();
	if (f) {
		return visitInterface_file_declaration(f);
	}
	auto t = ctx->interface_terminal_declaration();
	if (t) {
		return visitInterface_terminal_declaration(t);
	} else {
		auto q = ctx->interface_quantity_declaration();
		assert(q);
		return visitInterface_quantity_declaration(q);
	}
}
vector<Variable*> * InterfaceParser::visitInterface_list(
		vhdlParser::Interface_listContext* ctx) {
	// interface_list
	// : interface_element ( SEMI interface_element )*
	// ;
	vector<Variable*> * elems = new vector<Variable*>();
	for (auto ie : ctx->interface_element()) {
		vector<Variable*> *_elements = visitInterface_element(ie);
		for (auto e : *_elements) {
			elems->push_back(e);
		}
		delete _elements;
	}
	return elems;
}
vector<Variable*> * InterfaceParser::visitInterface_element(
		vhdlParser::Interface_elementContext* ctx) {
	// interface_element
	// : interface_declaration
	// ;
	auto intfDec = ctx->interface_declaration();
	return visitInterface_declaration(intfDec);
}

}
}
