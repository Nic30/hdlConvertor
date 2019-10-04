#include <hdlConvertor/svConvertor/typeParser.h>

#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/hdlObjects/hdlOperatorType.h>
#include <hdlConvertor/svConvertor/utils.h>
#include <hdlConvertor/svConvertor/exprParser.h>

namespace hdlConvertor {
namespace sv {

using namespace hdlConvertor::hdlObjects;

VerTypeParser::VerTypeParser(SVCommentParser &_commentParser) :
		commentParser(_commentParser) {
}

iHdlExpr* VerTypeParser::visitType_reference(
		sv2017Parser::Type_referenceContext *ctx) {
	// type_reference:
	//     KW_TYPE LPAREN (
	//         expression
	//         | data_type
	//     ) RPAREN
	// ;
	auto e = ctx->expression();
	if (e) {
		VerExprParser ep(commentParser);
		return ep.visitExpression(e);
	}
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
	VerExprParser ep(commentParser);
	VerTypeParser tp(commentParser);
	auto p = ep.visitPackage_or_class_scoped_path(_p);
	auto vds = ctx->variable_dimension();
	p = tp.applyVariable_dimension(p, vds);
	return p;
}

iHdlExpr* VerTypeParser::visitData_type_or_implicit(
		sv2017Parser::Data_type_or_implicitContext *ctx, iHdlExpr *net_type) {
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
	return visitImplicit_data_type(idt, net_type);
}

iHdlExpr* VerTypeParser::visitUnpacked_dimension(
		sv2017Parser::Unpacked_dimensionContext *ctx) {
	// unpacked_dimension: LSQUARE_BR range_expression RSQUARE_BR;
	auto ra = ctx->range_expression();
	return VerExprParser(commentParser).visitRange_expression(ra);
}
iHdlExpr* VerTypeParser::applyUnpacked_dimension(iHdlExpr *base_expr,
		std::vector<sv2017Parser::Unpacked_dimensionContext*> &uds) {
	for (auto _ud : uds) {
		auto ud = visitUnpacked_dimension(_ud);
		base_expr = new iHdlExpr(base_expr, HdlOperatorType::INDEX, ud);
	}
	return base_expr;
}
iHdlExpr* VerTypeParser::applyVariable_dimension(iHdlExpr *base_expr,
		std::vector<sv2017Parser::Variable_dimensionContext*> &vds) {
	for (auto _vd : vds) {
		base_expr = visitVariable_dimension(_vd, base_expr);
	}
	return base_expr;
}
iHdlExpr* VerTypeParser::visitPacked_dimension(
		sv2017Parser::Packed_dimensionContext *ctx) {
	// packed_dimension: LSQUARE_BR  ( range_expression )? RSQUARE_BR;
	auto ra = ctx->range_expression();
	if (ra)
		return VerExprParser(commentParser).visitRange_expression(ra);
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
		sv2017Parser::Implicit_data_typeContext *ctx, iHdlExpr *net_type) {
	// implicit_data_type:
	//     signing ( packed_dimension )*
	//     | ( packed_dimension )+
	// ;
	if (!ctx) {
		if (net_type)
			return net_type;
		else
			return Utils::mkWireT();
	}
	auto s = ctx->signing();
	bool is_signed = false;
	auto pds = ctx->packed_dimension();
	iHdlExpr *e = nullptr;
	if (s) {
		is_signed = visitSigning(s);
	}
	auto it = pds.begin();
	if (it != pds.end()) {
		auto r0 = visitPacked_dimension(*it);
		e = Utils::mkWireT(net_type, r0, is_signed);
	} else {
		e = Utils::mkWireT(iHdlExpr::null(), is_signed);
	}
	++it;
	for (; it != pds.end(); ++it) {
		auto pd = visitPacked_dimension(*it);
		e = new iHdlExpr(e, HdlOperatorType::INDEX, pd);
	}
	return e;
}

iHdlExpr* VerTypeParser::visitVariable_dimension(
		sv2017Parser::Variable_dimensionContext *ctx, iHdlExpr *selected_name) {
	// variable_dimension:
	//     LSQUARE_BR ( MUL
	//              | data_type
	//              | array_range_expression
	//               )? RSQUARE_BR
	// ;
	iHdlExpr *index = nullptr;
	if (ctx->MUL()) {
		NotImplementedLogger::print(
				"VerExprParser.visitVariable_dimension - MUL", ctx);
		return selected_name;
	}
	auto dt = ctx->data_type();
	if (dt) {
		index = VerTypeParser(commentParser).visitData_type(dt);
	} else {
		auto are = ctx->array_range_expression();
		if (are) {
			index = VerExprParser(commentParser).visitArray_range_expression(
					are);
		} else {
			index = iHdlExpr::null();
		}
	}
	return new iHdlExpr(selected_name, HdlOperatorType::INDEX, index);
}
iHdlExpr* VerTypeParser::visitNet_type(sv2017Parser::Net_typeContext *ctx) {
	// net_type:
	//     KW_SUPPLY0
	//     | KW_SUPPLY1
	//     | KW_TRI
	//     | KW_TRIAND
	//     | KW_TRIOR
	//     | KW_TRIREG
	//     | KW_TRI0
	//     | KW_TRI1
	//     | KW_UWIRE
	//     | KW_WIRE
	//     | KW_WAND
	//     | KW_WOR
	// ;
	auto t = iHdlExpr::ID(ctx->getText());
	return t;
}
iHdlExpr* VerTypeParser::visitNet_port_type(
		sv2017Parser::Net_port_typeContext *ctx) {
	// net_port_type:
	//  KW_INTERCONNECT ( implicit_data_type )?
	//   | net_type ( data_type_or_implicit )?
	//   | data_type_or_implicit
	// ;
	if (ctx->KW_INTERCONNECT()) {
		NotImplementedLogger::print(
				"VerExprParser.visitNet_or_var_data_type.interconnect", ctx);
		auto idt = ctx->implicit_data_type();
		auto t = visitImplicit_data_type(idt, nullptr);
		return t;
	}
	iHdlExpr *net_type = nullptr;
	auto _nt = ctx->net_type();
	if (_nt)
		net_type = visitNet_type(_nt);
	auto dti = ctx->data_type_or_implicit();
	return visitData_type_or_implicit(dti, net_type);
}
std::pair<iHdlExpr*, bool> VerTypeParser::visitNet_or_var_data_type(
		sv2017Parser::Net_or_var_data_typeContext *ctx) {
	// net_or_var_data_type:
	//  KW_INTERCONNECT ( implicit_data_type )?
	//   | KW_VAR ( data_type_or_implicit )?
	//   | net_type ( data_type_or_implicit )?
	//   | data_type_or_implicit
	// ;
	if (!ctx)
		return {Utils::mkWireT(), false};
	if (ctx->KW_INTERCONNECT()) {
		NotImplementedLogger::print(
				"VerExprParser.visitNet_or_var_data_type.interconnect", ctx);
		auto idt = ctx->implicit_data_type();
		auto t = visitImplicit_data_type(idt, nullptr);
		return {t, false};
	}
	auto dti = ctx->data_type_or_implicit();
	if (ctx->KW_VAR()) {
		auto t = visitData_type_or_implicit(dti, nullptr);
		return {t, true};
	}
	auto nt = ctx->net_type();
	if (nt) {
		auto sub_t = visitNet_type(nt);
		auto t = visitData_type_or_implicit(dti, sub_t);
		return {t, false};
	}
	assert(dti);
	auto t = visitData_type_or_implicit(dti, nullptr);
	return {t, false};
}

bool VerTypeParser::visitLifetime(sv2017Parser::LifetimeContext *ctx) {
	// lifetime:
	//     KW_STATIC
	//     | KW_AUTOMATIC
	// ;
	return !ctx || ctx->KW_STATIC();
}

iHdlExpr* VerTypeParser::visitData_type_or_void(
		sv2017Parser::Data_type_or_voidContext *ctx) {
	// data_type_or_void:
	//    KW_VOID
	//    | data_type
	// ;
	if (ctx->KW_VOID()) {
		return iHdlExpr::ID("void");
	} else {
		auto dt = ctx->data_type();
		return visitData_type(dt);
	}
}

hdlObjects::iHdlExpr* VerTypeParser::visitFunction_data_type_or_implicit(
		sv2017Parser::Function_data_type_or_implicitContext *ctx) {
	// function_data_type_or_implicit:
	//     data_type_or_void
	//     | implicit_data_type
	// ;
	if (!ctx)
		return Utils::mkWireT();

	auto dtv = ctx->data_type_or_void();
	if (dtv) {
		return visitData_type_or_void(dtv);
	} else {
		auto idt = ctx->implicit_data_type();
		assert(idt);
		return visitImplicit_data_type(idt, nullptr);
	}

}

}
}
