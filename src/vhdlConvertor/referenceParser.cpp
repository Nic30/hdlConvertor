#include <hdlConvertor/vhdlConvertor/referenceParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/exprParser.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/hdlObjects/hdlOperatorType.h>

namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlObjects;

iHdlExpr * ReferenceParser::visitSelected_name(
		vhdlParser::Selected_nameContext* ctx) {
	// selected_name
	// : identifier (DOT suffix)*
	// ;
	iHdlExpr * top = LiteralParser::visitIdentifier(ctx->identifier());
	for (auto s : ctx->suffix()) {
		top = new iHdlExpr(top, DOT, visitSuffix(s));
	}
	assert(top);
	return top;
}

iHdlExpr * ReferenceParser::visitSuffix(vhdlParser::SuffixContext* ctx) {
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
	return iHdlExpr::all();
}

iHdlExpr * ReferenceParser::visitName(vhdlParser::NameContext* ctx) {
	// name:
	//       name_part ( DOT name_part)*
	//       | external_name
	// ;
	auto en = ctx->external_name();
	if (en) {
		NotImplementedLogger::print("ExprParser.visitName - external_name", en);
		return nullptr;
	}
	auto np = ctx->name_part();
	iHdlExpr * op0 = NULL;
	for (auto it = np.begin(); it != np.end(); ++it) {
		auto n = *it;
		if (!op0) {
			op0 = visitName_part(n);
		} else {
			iHdlExpr * op1 = visitName_part(n);
			op0 = new iHdlExpr(op0, DOT, op1);
		}
	}
	assert(op0);
	return op0;
}

iHdlExpr * ReferenceParser::visitName_attribute_part(
		vhdlParser::Name_attribute_partContext* ctx) {
	// name_attribute_part
	// : APOSTROPHE attribute_designator ( expression ( COMMA expression )* )?
	// ;
	auto expressions = ctx->expression();
	if (expressions.size() > 0)
		NotImplementedLogger::print(
				"ExprParser.visitName_attribute_part - expression", ctx);
	return visitAttribute_designator(ctx->attribute_designator());
}
iHdlExpr* ReferenceParser::visitAttribute_name(
		vhdlParser::Attribute_nameContext *ctx) {
	// attribute_name:
	//       prefix ( signature )? APOSTROPHE attribute_designator ( LPAREN expression RPAREN )?
	// ;
	iHdlExpr * p = ExprParser::visitPrefix(ctx->prefix());
	auto s = ctx->signature();
	if (s)
		NotImplementedLogger::print(
				"ExprParser.visitAttribute_name - signature", s);
	auto ad = ctx->attribute_designator();
	iHdlExpr * res = new iHdlExpr(p, HdlOperatorType::APOSTROPHE, visitAttribute_designator(ad));
	auto e = ctx->expression();
	if (e)
		res = new iHdlExpr(res, HdlOperatorType::INDEX,
				ExprParser::visitExpression(e));

	return res;
}

iHdlExpr * ReferenceParser::visitAttribute_designator(
		vhdlParser::Attribute_designatorContext* ctx) {
	// attribute_designator: simple_name | any_keyword;
	auto sn = ctx->simple_name();
	if (sn)
		return visitSimple_name(sn);
	else {
		std::string s = ctx->any_keyword()->getText();
		return iHdlExpr::ID(s);
	}
}

iHdlExpr * ReferenceParser::visitName_part_specificator(iHdlExpr * selectedName,
		vhdlParser::Name_part_specificatorContext* ctx) {
	// name_part_specificator:
	//      name_attribute_part
	//    | LPAREN (name_function_call_or_indexed_part | name_slice_part) RPAREN
	//    ;
	auto na = ctx->name_attribute_part();
	if (na) {
		return new iHdlExpr(selectedName, HdlOperatorType::APOSTROPHE,
				visitName_attribute_part(na));
	}
	auto callOrIndx = ctx->name_function_call_or_indexed_part();
	if (callOrIndx) {
		// name_function_call_or_indexed_part:  actual_parameter_part?;
		auto args = ExprParser::visitActual_parameter_part(
				callOrIndx->actual_parameter_part());
		auto c = iHdlExpr::call(selectedName, *args);
		delete args;
		return c;
	}
	auto ns = ctx->name_slice_part();
	if (ns) {
		auto args = visitName_slice_part(ns);
		auto s = iHdlExpr::slice(selectedName, *args);
		delete args;
		return s;
	}
	return iHdlExpr::null();
}

iHdlExpr * ReferenceParser::visitName_part(vhdlParser::Name_partContext* ctx) {
	// name_part
	// : selected_name (name_part_specificator)*
	// ;
	iHdlExpr * sn = visitSelected_name(ctx->selected_name());
	for (auto sp : ctx->name_part_specificator()) {
		sn = visitName_part_specificator(sn, sp);
	}
	return sn;
}

std::vector<iHdlExpr*> * ReferenceParser::visitName_slice_part(
		vhdlParser::Name_slice_partContext *ctx) {
	// name_slice_part
	//   : LPAREN explicit_range ( COMMA explicit_range )* RPAREN
	//   ;
	std::vector<iHdlExpr*> * sp = new std::vector<iHdlExpr*>();
	for (auto er : ctx->explicit_range()) {
		sp->push_back(ExprParser::visitExplicit_range(er));
	}
	return sp;
}

iHdlExpr * ReferenceParser::visitSimple_name(vhdlParser::Simple_nameContext * ctx) {
	// simple_name: identifier;
	return LiteralParser::visitIdentifier(ctx->identifier());
}

}
}
