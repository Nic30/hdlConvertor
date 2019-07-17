#include <hdlConvertor/vhdlConvertor/interfaceParser.h>

#include <hdlConvertor/vhdlConvertor/exprParser.h>
#include <hdlConvertor/vhdlConvertor/directionParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/notImplementedLogger.h>

namespace hdlConvertor {
namespace vhdl {

using std::vector;
using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlObjects;

vector<HdlVariableDef*> * InterfaceParser::extractVariables(
		vhdlParser::Identifier_listContext* identifier_list,
		vhdlParser::Subtype_indicationContext* subType,
		vhdlParser::ExpressionContext* _expr) {
	vector<HdlVariableDef*> * vl = new vector<HdlVariableDef*>();
	iHdlExpr * _type = ExprParser::visitSubtype_indication(subType);
	iHdlExpr * expr = NULL;
	if (_expr)
		expr = ExprParser::visitExpression(_expr);

	bool firstIt = true;
	for (auto i : identifier_list->identifier()) {
		// identifier_list
		// : identifier ( COMMA identifier )*
		// ;
		if (!firstIt)
			_type = new iHdlExpr(*_type);
		iHdlExpr * __expr;
		if (!expr) {
			__expr = nullptr;
			firstIt = false;
		} else if (firstIt) {
			firstIt = false;
			__expr = expr;
		} else {
			__expr = new iHdlExpr(*expr);
		}
		HdlVariableDef * v = new HdlVariableDef(i->getText(), _type, __expr);
		vl->push_back(v);
	}
	return vl;
}
vector<HdlVariableDef*> * InterfaceParser::visitInterface_constant_declaration(
		vhdlParser::Interface_constant_declarationContext* ctx) {
	// interface_constant_declaration:
	//       ( CONSTANT )? identifier_list COLON ( IN )? subtype_indication ( VARASGN expression )?
	// ;
	auto consts = extractVariables(ctx->identifier_list(),
			ctx->subtype_indication(), ctx->expression());
	for (auto c : *consts)
		c->is_const = true;
	return consts;
}
vector<HdlVariableDef*> * InterfaceParser::visitInterface_signal_declaration(
		vhdlParser::Interface_signal_declarationContext* ctx) {
	// interface_signal_declaration:
	//       ( SIGNAL )? identifier_list COLON ( signal_mode )? subtype_indication ( BUS )? ( VARASGN expression )?
	// ;
	if (ctx->BUS()) {
		NotImplementedLogger::print(
				"InterfaceParser.visitInterface_signal_declaration - BUS", ctx);
	}
	auto sigs = extractVariables(ctx->identifier_list(),
			ctx->subtype_indication(), ctx->expression());
	auto m = visitSignalMode(ctx->signal_mode());
	for (auto s : *sigs)
		s->direction = m;
	return sigs;
}
vector<HdlVariableDef*> * InterfaceParser::visitInterface_variable_declaration(
		vhdlParser::Interface_variable_declarationContext* ctx) {
	// interface_variable_declaration:
	//       ( VARIABLE )? identifier_list COLON ( signal_mode )? subtype_indication ( VARASGN expression )?
	// ;
	auto vars = extractVariables(ctx->identifier_list(),
			ctx->subtype_indication(), ctx->expression());
	auto m = visitSignalMode(ctx->signal_mode());
	for (auto v : *vars) {
		v->direction = m;
		v->is_latched = true;
	}
	return vars;
}
vector<HdlVariableDef*> * InterfaceParser::visitInterface_file_declaration(
		vhdlParser::Interface_file_declarationContext* ctx) {
	// interface_file_declaration:
	//       FILE identifier_list COLON subtype_indication
	// ;
	NotImplementedLogger::print(
			"InterfaceParser.visitInterface_file_declaration", ctx);
	return new vector<HdlVariableDef*>();
}

vector<HdlVariableDef*> * InterfaceParser::visitInterface_declaration(
		vhdlParser::Interface_declarationContext* ctx) {
	// interface_declaration:
	//       interface_object_declaration
	//       | interface_type_declaration
	//       | interface_subprogram_declaration
	//       | interface_package_declaration
	// ;
	auto iod = ctx->interface_object_declaration();
	if (iod) {
		return visitInterface_object_declaration(iod);
	}
	do {
		auto itd = ctx->interface_type_declaration();
		if (itd) {
			auto t = visitInterface_type_declaration(itd);
			delete t;
			NotImplementedLogger::print(
					"InterfaceParser.visitInterface_declaration - interface_type_declaration",
					itd);
			break;
		}
		auto isd = ctx->interface_subprogram_declaration();
		if (isd) {
			NotImplementedLogger::print(
					"InterfaceParser.visitInterface_declaration - interface_subprogram_declaration",
					isd);
			break;
		}
		auto ipd = ctx->interface_package_declaration();
		if (ipd) {
			NotImplementedLogger::print(
					"InterfaceParser.visitInterface_declaration - interface_package_declaration",
					ipd);
			break;
		}
	} while (0);

	return new vector<HdlVariableDef*>();
}
iHdlExpr * InterfaceParser::visitInterface_type_declaration(
		vhdlParser::Interface_type_declarationContext * ctx) {
	// interface_type_declaration:
	//       interface_incomplete_type_declaration
	// ;
	// interface_incomplete_type_declaration: TYPE identifier;
	return LiteralParser::visitIdentifier(
			ctx->interface_incomplete_type_declaration()->identifier());
}
std::vector<HdlVariableDef*> * InterfaceParser::visitInterface_object_declaration(
		vhdlParser::Interface_object_declarationContext * ctx) {
	// interface_object_declaration:
	//       interface_constant_declaration
	//       | interface_signal_declaration
	//       | interface_variable_declaration
	//       | interface_file_declaration
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
	assert(f);
	return visitInterface_file_declaration(f);
}
vector<HdlVariableDef*> * InterfaceParser::visitInterface_list(
		vhdlParser::Interface_listContext* ctx) {
	// interface_list:
	//       interface_element ( SEMI interface_element )*
	// ;
	vector<HdlVariableDef*> * elems = new vector<HdlVariableDef*>();
	for (auto ie : ctx->interface_element()) {
		vector<HdlVariableDef*> *_elements = visitInterface_element(ie);
		for (auto e : *_elements) {
			elems->push_back(e);
		}
		delete _elements;
	}
	return elems;
}
vector<HdlVariableDef*> * InterfaceParser::visitInterface_element(
		vhdlParser::Interface_elementContext* ctx) {
	// interface_element: interface_declaration;
	auto intfDec = ctx->interface_declaration();
	return visitInterface_declaration(intfDec);
}

}
}
