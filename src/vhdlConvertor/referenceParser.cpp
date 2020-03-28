#include <hdlConvertor/vhdlConvertor/referenceParser.h>

#include <assert.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/hdlObjects/hdlOperatorType.h>
#include <hdlConvertor/vhdlConvertor/exprParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/createObject.h>

namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlObjects;

std::unique_ptr<iHdlExpr> VhdlReferenceParser::visitSelected_name(
		vhdlParser::Selected_nameContext *ctx) {
	// selected_name
	// : identifier (DOT suffix)*
	// ;
	std::unique_ptr<iHdlExpr> top = VhdlLiteralParser::visitIdentifier(
			ctx->identifier());
	for (auto s : ctx->suffix()) {
		top = create_object<iHdlExpr>(ctx, move(top), DOT, visitSuffix(s));
	}
	assert(top);
	return top;
}

std::unique_ptr<iHdlExpr> VhdlReferenceParser::visitSuffix(
		vhdlParser::SuffixContext *ctx) {
	//suffix:
	//      name_literal
	//      | KW_ALL
	//;
	auto nl = ctx->name_literal();
	if (nl) {
		return visitName_literal(nl);
	}
	assert(ctx->KW_ALL());
	return iHdlExpr::all();
}
std::unique_ptr<iHdlExpr> VhdlReferenceParser::visitName_literal(
		vhdlParser::Name_literalContext *ctx) {
	// name_literal:
	//         identifier     #nameSel1
	//        | operator_symbol   #nameOpSymb
	//        | CHARACTER_LITERAL #nameChar
	// ;
	auto id = ctx->identifier();
	if (id)
		return VhdlLiteralParser::visitIdentifier(id);

	auto n = ctx->CHARACTER_LITERAL();
	if (n)
		return VhdlLiteralParser::visitCHARACTER_LITERAL(n, n->getText());
	// operator_symbol: string_literal;
	auto o = ctx->operator_symbol();
	assert(o);
	auto sl = o->STRING_LITERAL();
	return VhdlLiteralParser::visitSTRING_LITERAL(sl, sl->getText());
}

std::unique_ptr<iHdlExpr> VhdlReferenceParser::visitName_slice_part(
		vhdlParser::Name_slice_partContext *ctx,
		std::unique_ptr<iHdlExpr> selected_name) {
	// name_slice_part:
	//     LPAREN explicit_range RPAREN
	// ;
	auto _er = ctx->explicit_range();
	auto er = VhdlExprParser::visitExplicit_range(_er);
	//TODO::return create_object<iHdlExpr>(ctx, move(selected_name), HdlOperatorType::INDEX, move(er));
	//
	//rhinton: a slicing, indexing operation has a "left" operand that's
	// the name, and "right" operand that's the range for the slice.  So
	// this is another place where it would be nice to wrap an HdlRange in
	// an expression.
	NotImplementedLogger::print("ExprParser.visitName_slice_part - name_slice_part", ctx);
	return nullptr;
}
std::unique_ptr<iHdlExpr> VhdlReferenceParser::visitName(
		vhdlParser::NameContext *ctx) {
	// name:
	//     name_literal
	//       | name (
	//             name_slice_part // name_index was removed as it is same as call
	//             | name_attribute_part
	//             | association_list
	//             | DOT suffix
	//         )
	//       | external_name
	// ;

	auto en = ctx->external_name();
	if (en) {
		NotImplementedLogger::print("ExprParser.visitName - external_name", en);
		return iHdlExpr::null();
	}
	auto nl = ctx->name_literal();
	if (nl) {
		return visitName_literal(nl);
	}
	auto _n = ctx->name();
	assert(_n);
	auto n = visitName(_n);
	auto nsp = ctx->name_slice_part();
	if (nsp) {
		return visitName_slice_part(nsp, move(n));
	}
	auto nap = ctx->name_attribute_part();
	if (nap) {
		return visitName_attribute_part(nap, move(n));
	}
	auto _s = ctx->suffix();
	if (_s) {
		auto s = visitSuffix(_s);
		return create_object<iHdlExpr>(ctx, move(n), HdlOperatorType::DOT, move(s));
	}
	auto _al = ctx->association_list();
	assert(_al);
	auto al = VhdlExprParser::visitAssociation_list(_al);
	assert(al);
	return iHdlExpr::call(_al, move(n), *al);
}

std::unique_ptr<iHdlExpr> VhdlReferenceParser::visitName_attribute_part(
		vhdlParser::Name_attribute_partContext *ctx,
		std::unique_ptr<iHdlExpr> selected_name) {
	// name_attribute_part:
	//     ( signature )? APOSTROPHE attribute_designator
	// ;
	auto s = ctx->signature();
	if (s)
		NotImplementedLogger::print(
				"ExprParser.visitAttribute_name - signature", s);
	auto ad = ctx->attribute_designator();
	return create_object<iHdlExpr>(ctx, move(selected_name),
			HdlOperatorType::APOSTROPHE, visitAttribute_designator(ad));
}

std::unique_ptr<iHdlExpr> VhdlReferenceParser::visitAttribute_name(
		vhdlParser::Attribute_nameContext *ctx) {
	// attribute_name:
	//  name name_attribute_part
	// ;
	auto n = ctx->name();
	auto prefix_expr = visitName(n);
	auto np = ctx->name_attribute_part();
	return visitName_attribute_part(np, move(prefix_expr));
}

std::unique_ptr<iHdlExpr> VhdlReferenceParser::visitAttribute_designator(
		vhdlParser::Attribute_designatorContext *ctx) {
	// attribute_designator: identifier | any_keyword;
	auto sn = ctx->identifier();
	if (sn)
		return VhdlLiteralParser::visitIdentifier(sn);
	else {
		std::string s = ctx->any_keyword()->getText();
		return iHdlExpr::ID(s);
	}
}

}
}
