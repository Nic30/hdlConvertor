#include "referenceParser.h"
#include "literalParser.h"
#include "exprParser.h"
#include "../notImplementedLogger.h"
#include "../hdlObjects/operatorType.h"

namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlObjects;

Expr * ReferenceParser::visitSelected_name(
		vhdlParser::Selected_nameContext* ctx) {
	// selected_name
	// : identifier (DOT suffix)*
	// ;
	Expr * top = LiteralParser::visitIdentifier(ctx->identifier());
	for (auto s : ctx->suffix()) {
		top = new Expr(top, DOT, visitSuffix(s));
	}
	assert(top);
	return top;
}

Expr * ReferenceParser::visitSuffix(vhdlParser::SuffixContext* ctx) {
	//suffix:
	//      simple_name
	//      | character_literal
	//      | operator_symbol
	//      | ALL
	//;

	auto id = ctx->simple_name();
	if (id)
		return ReferenceParser::visitSimple_name(id);

	auto n = ctx->CHARACTER_LITERAL();
	if (n)
		return LiteralParser::visitCharacter_literal(n->getText());
	// operator_symbol: string_literal;
	auto o = ctx->operator_symbol();
	if (o) {
		auto sl = o->STRING_LITERAL();
		return LiteralParser::visitString_literal(sl->getText());
	}
	return Expr::all();
}

Expr * ReferenceParser::visitName(vhdlParser::NameContext* ctx) {
	// name
	//   : name_part ( DOT name_part)*
	//   | external_name
	//   ;
	auto en = ctx->external_name();
	if (en) {
		NotImplementedLogger::print("ExprParser.visitName - external_name");
		return nullptr;
	}
	auto np = ctx->name_part();
	Expr * op0 = NULL;
	for (auto it = np.begin(); it != np.end(); ++it) {
		auto n = *it;
		if (!op0) {
			op0 = visitName_part(n);
		} else {
			Expr * op1 = visitName_part(n);
			op0 = new Expr(op0, DOT, op1);
		}
	}
	assert(op0);
	return op0;
}

Expr * ReferenceParser::visitName_attribute_part(
		vhdlParser::Name_attribute_partContext* ctx) {
	// name_attribute_part
	// : APOSTROPHE attribute_designator ( expression ( COMMA expression )* )?
	// ;
	auto expressions = ctx->expression();
	if (expressions.size() > 0)
		NotImplementedLogger::print(
				"ExprParser.visitName_attribute_part - expression");
	return visitAttribute_designator(ctx->attribute_designator());
}
Expr* ReferenceParser::visitAttribute_name(
		vhdlParser::Attribute_nameContext *ctx) {
	// attribute_name:
	//       prefix ( signature )? APOSTROPHE attribute_designator ( LPAREN expression RPAREN )?
	// ;
	Expr * p = ExprParser::visitPrefix(ctx->prefix());
	auto s = ctx->signature();
	if (s)
		NotImplementedLogger::print(
				"ExprParser.visitAttribute_name - signature");
	auto ad = ctx->attribute_designator();
	Expr * res = new Expr(p, OperatorType::DOT, visitAttribute_designator(ad));
	auto e = ctx->expression();
	if (e)
		res = new Expr(res, OperatorType::INDEX,
				ExprParser::visitExpression(e));

	return res;
}

Expr * ReferenceParser::visitAttribute_designator(
		vhdlParser::Attribute_designatorContext* ctx) {
	// attribute_designator: simple_name;
	return visitSimple_name(ctx->simple_name());
}

Expr * ReferenceParser::visitName_part_specificator(Expr * selectedName,
		vhdlParser::Name_part_specificatorContext* ctx) {
	// name_part_specificator
	// : name_attribute_part
	// | name_function_call_or_indexed_part
	// | name_slice_part
	// ;

	auto na = ctx->name_attribute_part();
	if (na) {
		return new Expr(selectedName, OperatorType::DOT,
				visitName_attribute_part(na));
	}
	auto callOrIndx = ctx->name_function_call_or_indexed_part();
	if (callOrIndx) {
		// name_function_call_or_indexed_part
		// : LPAREN actual_parameter_part? RPAREN
		// ;
		auto args = ExprParser::visitActual_parameter_part(
				callOrIndx->actual_parameter_part());
		auto c = Expr::call(selectedName, *args);
		delete args;
		return c;
	}
	auto ns = ctx->name_slice_part();
	if (ns) {
		auto args = visitName_slice_part(ns);
		auto s = Expr::slice(selectedName, *args);
		delete args;
		return s;
	}
	return Expr::null();
}

Expr * ReferenceParser::visitName_part(vhdlParser::Name_partContext* ctx) {
	// name_part
	// : selected_name (name_part_specificator)*
	// ;
	Expr * sn = visitSelected_name(ctx->selected_name());
	for (auto sp : ctx->name_part_specificator()) {
		sn = visitName_part_specificator(sn, sp);
	}
	return sn;
}

std::vector<Expr*> * ReferenceParser::visitName_slice_part(
		vhdlParser::Name_slice_partContext *ctx) {
	// name_slice_part
	//   : LPAREN explicit_range ( COMMA explicit_range )* RPAREN
	//   ;
	std::vector<Expr*> * sp = new std::vector<Expr*>();
	for (auto er : ctx->explicit_range()) {
		sp->push_back(ExprParser::visitExplicit_range(er));
	}
	return sp;
}

Expr * ReferenceParser::visitSimple_name(vhdlParser::Simple_nameContext * ctx) {
	// simple_name: identifier;
	return LiteralParser::visitIdentifier(ctx->identifier());
}

}
}
