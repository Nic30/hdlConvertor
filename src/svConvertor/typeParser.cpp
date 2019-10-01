#include <hdlConvertor/svConvertor/typeParser.h>
#include <hdlConvertor/svConvertor/exprParser.h>
#include <hdlConvertor/svConvertor/utils.h>
#include <hdlConvertor/hdlObjects/hdlOperatorType.h>

namespace hdlConvertor {
namespace sv {

using namespace hdlConvertor::hdlObjects;

iHdlExpr* VerTypeParser::visitType_reference(
		sv2017Parser::Type_referenceContext *ctx) {
	// type_reference:
	//     KW_TYPE LPAREN (
	//         expression
	//         | data_type
	//     ) RPAREN
	// ;
	auto e = ctx->expression();
	if (e)
		return VerExprParser::visitExpression(e);
	auto dt = ctx->data_type();
	assert(dt);
	return visitData_type(dt);
}

iHdlExpr* VerTypeParser::visitData_type(sv2017Parser::Data_typeContext *ctx) {
	// data_type:
	//     KW_STRING
	//     | KW_CHANDLE
	//     | KW_VIRTUAL ( KW_INTERFACE )? identifier ( parameter_value_assignment )? ( DOT identifier )?
	//     | KW_EVENT
	//     | ( data_type_primitive
	//         | KW_ENUM ( enum_base_type )?
	//            LBRACE enum_name_declaration  ( COMMA enum_name_declaration )* RBRACE
	//         | struct_union ( KW_PACKED ( signing )? )?
	//             LBRACE ( struct_union_member )+ RBRACE
	//         | package_or_class_scoped_path
	//       ) ( variable_dimension )*
	//     | type_reference
	// ;
	if (ctx->KW_STRING())
		return iHdlExpr::ID("string");
	if (ctx->KW_CHANDLE())
		return iHdlExpr::ID("chandle");
	if (ctx->KW_VIRTUAL()) {
		NotImplementedLogger::print("VerTypeParser::visitData_type - virtual",
				ctx);
		return iHdlExpr::null();
	}
	if (ctx->KW_EVENT())
		return iHdlExpr::ID("event");

	if (ctx->data_type_primitive()) {
		NotImplementedLogger::print(
				"VerTypeParser::visitData_type - data_type_primitive", ctx);
		return iHdlExpr::null();
	}
	if (ctx->KW_ENUM()) {
		NotImplementedLogger::print("VerTypeParser::visitData_type - enum",
				ctx);
		return iHdlExpr::null();
	}
	if (ctx->struct_union()) {
		NotImplementedLogger::print(
				"VerTypeParser::visitData_type - struct or union", ctx);
		return iHdlExpr::null();
	}
	auto _p = ctx->package_or_class_scoped_path();
	auto p = VerExprParser::visitPackage_or_class_scoped_path(_p);
	for (auto vd : ctx->variable_dimension()) {
		p = VerExprParser::visitVariable_dimension(vd, p);
	}
	return p;
}

iHdlExpr* VerTypeParser::visitData_type_or_implicit(
		sv2017Parser::Data_type_or_implicitContext *ctx) {
	// data_type_or_implicit:
	//     data_type
	//     | implicit_data_type
	// ;
	if (!ctx)
		return Utils::mkWireT();

	auto dt = ctx->data_type();
	if (dt)
		return visitData_type(dt);
	auto idt = ctx->implicit_data_type();
	assert(idt);
	return visitImplicit_data_type(idt);
}

iHdlExpr* VerTypeParser::visitUnpacked_dimension(sv2017Parser::Unpacked_dimensionContext* ctx) {
	// unpacked_dimension: LSQUARE_BR range_expression RSQUARE_BR;
	auto ra = ctx->range_expression();
	return VerExprParser::visitRange_expression(ra);
}

iHdlExpr* VerTypeParser::visitPacked_dimension(sv2017Parser::Packed_dimensionContext* ctx) {
	// packed_dimension: LSQUARE_BR  ( range_expression )? RSQUARE_BR;
	auto ra = ctx->range_expression();
	if (ra)
		return VerExprParser::visitRange_expression(ra);
	return iHdlExpr::null();
}

bool VerTypeParser::visitSigning(sv2017Parser::SigningContext *ctx) {
	// signing:
	//     KW_SIGNED
	//     | KW_UNSIGNED
	// ;
	if (ctx->KW_SIGNED()) {
		return true;
	} else {
		assert(ctx->KW_UNSIGNED());
		return false;
	}
}

iHdlExpr* VerTypeParser::visitImplicit_data_type(
		sv2017Parser::Implicit_data_typeContext *ctx) {
	// implicit_data_type:
	//     signing ( packed_dimension )*
	//     | ( packed_dimension )+
	// ;
	if (!ctx)
		return Utils::mkWireT();
	auto s = ctx->signing();
	bool is_signed = false;
	auto pds = ctx->packed_dimension();
	iHdlExpr * e = nullptr;
	if (s) {
		is_signed = visitSigning(s);
	}
	auto it = pds.begin();
	if (it != pds.end()) {
		auto r0 = visitPacked_dimension(*it);
		e = Utils::mkWireT(r0, is_signed);
	} else {
		e = Utils::mkWireT(iHdlExpr::null(), is_signed);
	}
	++it;
	for (; it != pds.end(); ++it) {
		auto pd = visitPacked_dimension(*it);
		e = new iHdlExpr(e, HdlOperatorType::INDEX, pd);
	}
}

}
}
