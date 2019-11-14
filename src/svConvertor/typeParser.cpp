#include <hdlConvertor/svConvertor/typeParser.h>

#include <hdlConvertor/createObject.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/hdlObjects/hdlOperatorType.h>
#include <hdlConvertor/svConvertor/utils.h>
#include <hdlConvertor/svConvertor/exprParser.h>

using namespace std;
using namespace hdlConvertor::hdlObjects;

namespace hdlConvertor {
namespace sv {

VerTypeParser::VerTypeParser(SVCommentParser &_commentParser) :
		commentParser(_commentParser) {
}

unique_ptr<iHdlExpr> VerTypeParser::visitType_reference(
		sv2017Parser::Type_referenceContext *ctx) {
	// type_reference:
	//     KW_TYPE LPAREN (
	//         expression
	//         | data_type
	//     ) RPAREN
	// ;
	unique_ptr<iHdlExpr> res = nullptr;
	auto e = ctx->expression();
	if (e) {
		VerExprParser ep(commentParser);
		res = ep.visitExpression(e);
	} else {
		auto dt = ctx->data_type();
		assert(dt);
		res = visitData_type(dt);
	}
	return create_object<iHdlExpr>(ctx, HdlOperatorType::TYPE_OF, move(res));
}

unique_ptr<iHdlExpr> VerTypeParser::visitInteger_type(
		sv2017Parser::Integer_typeContext *ctx) {
	// integer_type:
	//     integer_vector_type
	//     | integer_atom_type
	// ;
	auto ivt = ctx->integer_vector_type();
	if (ivt)
		return visitInteger_vector_type(ivt);
	auto iat = ctx->integer_atom_type();
	assert(iat);
	return visitInteger_atom_type(iat);
}

unique_ptr<iHdlExpr> VerTypeParser::visitNon_integer_type(
		sv2017Parser::Non_integer_typeContext *ctx) {
	// non_integer_type:
	//     KW_SHORTREAL
	//     | KW_REAL
	//     | KW_REALTIME
	// ;
	return iHdlExpr::ID(ctx->getText());
}
unique_ptr<iHdlExpr> VerTypeParser::visitInteger_atom_type(
		sv2017Parser::Integer_atom_typeContext *ctx) {
	// integer_atom_type:
	//     KW_BYTE
	//     | KW_SHORTINT
	//     | KW_INT
	//     | KW_LONGINT
	//     | KW_INTEGER
	//     | KW_TIME
	// ;
	return iHdlExpr::ID(ctx->getText());
}

unique_ptr<iHdlExpr> VerTypeParser::visitInteger_vector_type(
		sv2017Parser::Integer_vector_typeContext *ctx) {
	// integer_vector_type:
	//     KW_BIT
	//     | KW_LOGIC
	//     | KW_REG
	// ;
	return iHdlExpr::ID(ctx->getText());
}

unique_ptr<iHdlExpr> VerTypeParser::visitData_type_primitive(
		sv2017Parser::Data_type_primitiveContext *ctx) {
	// data_type_primitive:
	//     integer_type ( signing )?
	//     | non_integer_type
	// ;
	auto it = ctx->integer_type();
	if (it) {
		auto t = visitInteger_type(it);
		auto sig = ctx->signing();
		if (sig && visitSigning(sig)) {
			vector<unique_ptr<iHdlExpr>> args;
			args.push_back(
					create_object<iHdlExpr>(ctx, iHdlExpr::ID("signed"),
							HdlOperatorType::MAP_ASSOCIATION,
							iHdlExpr::INT(nullptr, 1)));
			t = iHdlExpr::parametrization(ctx, move(t), args);
		}
		return t;
	} else {
		auto nit = ctx->non_integer_type();
		assert(nit);
		return visitNon_integer_type(nit);
	}
}

unique_ptr<iHdlExpr> VerTypeParser::visitData_type(
		sv2017Parser::Data_typeContext *ctx) {
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
		NotImplementedLogger::print("VerTypeParser.visitData_type - virtual",
				ctx);
		auto ids = ctx->identifier();
		VerExprParser ep(commentParser);
		auto t = ep.visitIdentifier(ids[0]);
		auto pva = ctx->parameter_value_assignment();
		if (pva) {
			auto p = ep.visitParameter_value_assignment(pva);
			t = iHdlExpr::parametrization(ctx, move(t), p);
		}
		if (ids.size() == 2) {
			auto id = ep.visitIdentifier(ids[1]);
			t = create_object<iHdlExpr>(ids[1], move(t), HdlOperatorType::DOT, move(id));
		} else {
			assert(ids.size() == 1);
		}
		return t;
	}

	if (ctx->KW_EVENT())
		return iHdlExpr::ID("event");
	auto _tr = ctx->type_reference();
	if (_tr) {
		return visitType_reference(_tr);
	}

	auto dtp = ctx->data_type_primitive();
	unique_ptr<iHdlExpr> t = nullptr;
	if (dtp) {
		t = visitData_type_primitive(dtp);
	} else if (ctx->KW_ENUM()) {
		NotImplementedLogger::print("VerTypeParser.visitData_type - enum", ctx);
		t = iHdlExpr::null();
	} else if (ctx->struct_union()) {
		NotImplementedLogger::print(
				"VerTypeParser.visitData_type - struct or union", ctx);
		t = iHdlExpr::null();
	} else {
		VerExprParser ep(commentParser);
		auto _p = ctx->package_or_class_scoped_path();
		assert(_p);
		t = ep.visitPackage_or_class_scoped_path(_p);
	}
	VerTypeParser tp(commentParser);
	auto vds = ctx->variable_dimension();
	t = tp.applyVariable_dimension(move(t), vds);
	return t;
}

unique_ptr<iHdlExpr> VerTypeParser::visitData_type_or_implicit(
		sv2017Parser::Data_type_or_implicitContext *ctx,
		unique_ptr<iHdlExpr> net_type) {
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
	return visitImplicit_data_type(idt, move(net_type));
}

unique_ptr<iHdlExpr> VerTypeParser::visitUnpacked_dimension(
		sv2017Parser::Unpacked_dimensionContext *ctx) {
	// unpacked_dimension: LSQUARE_BR range_expression RSQUARE_BR;
	auto ra = ctx->range_expression();
	return VerExprParser(commentParser).visitRange_expression(ra);
}

unique_ptr<iHdlExpr> VerTypeParser::applyUnpacked_dimension(
		unique_ptr<iHdlExpr> base_expr,
		vector<sv2017Parser::Unpacked_dimensionContext*> &uds) {
	for (auto _ud : uds) {
		auto ud = visitUnpacked_dimension(_ud);
		base_expr = create_object<iHdlExpr>(_ud, move(base_expr),
				HdlOperatorType::INDEX, move(ud));
	}
	return base_expr;
}

unique_ptr<iHdlExpr> VerTypeParser::applyVariable_dimension(
		unique_ptr<iHdlExpr> base_expr,
		vector<sv2017Parser::Variable_dimensionContext*> &vds) {
	for (auto _vd : vds) {
		base_expr = visitVariable_dimension(_vd, move(base_expr));
	}
	return base_expr;
}

unique_ptr<iHdlExpr> VerTypeParser::visitPacked_dimension(
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

unique_ptr<iHdlExpr> VerTypeParser::visitImplicit_data_type(
		sv2017Parser::Implicit_data_typeContext *ctx,
		unique_ptr<iHdlExpr> net_type) {
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
	unique_ptr<iHdlExpr> e = nullptr;
	if (s) {
		is_signed = visitSigning(s);
	}
	auto it = pds.begin();
	if (it != pds.end()) {
		auto r0 = visitPacked_dimension(*it);
		e = Utils::mkWireT(*it, move(net_type), move(r0), is_signed);
		++it;
	} else {
		e = Utils::mkWireT(nullptr, iHdlExpr::null(), is_signed);
	}
	for (; it != pds.end(); ++it) {
		auto pd = visitPacked_dimension(*it);
		e = create_object<iHdlExpr>(*it, move(e), HdlOperatorType::INDEX, move(pd));
	}
	return e;
}

unique_ptr<iHdlExpr> VerTypeParser::visitVariable_dimension(
		sv2017Parser::Variable_dimensionContext *ctx,
		unique_ptr<iHdlExpr> selected_name) {
	// variable_dimension:
	//     LSQUARE_BR ( MUL
	//              | data_type
	//              | array_range_expression
	//               )? RSQUARE_BR
	// ;
	unique_ptr<iHdlExpr> index = nullptr;
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
	return create_object<iHdlExpr>(ctx, move(selected_name), HdlOperatorType::INDEX,
			move(index));
}
unique_ptr<iHdlExpr> VerTypeParser::visitNet_type(
		sv2017Parser::Net_typeContext *ctx) {
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
	return iHdlExpr::ID(ctx->getText());
}
unique_ptr<iHdlExpr> VerTypeParser::visitNet_port_type(
		sv2017Parser::Net_port_typeContext *ctx) {
	// net_port_type:
	//  KW_INTERCONNECT ( implicit_data_type )?
	//   | net_type ( data_type_or_implicit )?
	//   | data_type_or_implicit
	// ;
	if (!ctx)
		return Utils::mkWireT();

	if (ctx->KW_INTERCONNECT()) {
		NotImplementedLogger::print(
				"VerExprParser.visitNet_or_var_data_type.interconnect", ctx);
		auto idt = ctx->implicit_data_type();
		auto t = visitImplicit_data_type(idt, nullptr);
		return t;
	}
	unique_ptr<iHdlExpr> net_type = nullptr;
	auto _nt = ctx->net_type();
	if (_nt)
		net_type = visitNet_type(_nt);
	auto dti = ctx->data_type_or_implicit();
	return visitData_type_or_implicit(dti, move(net_type));
}
pair<unique_ptr<iHdlExpr>, bool> VerTypeParser::visitNet_or_var_data_type(
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
		return {move(t), false};
	}
	auto dti = ctx->data_type_or_implicit();
	if (ctx->KW_VAR()) {
		auto t = visitData_type_or_implicit(dti, nullptr);
		return {move(t), true};
	}
	auto nt = ctx->net_type();
	if (nt) {
		auto sub_t = visitNet_type(nt);
		auto t = visitData_type_or_implicit(dti, move(sub_t));
		return {move(t), false};
	}
	assert(dti);
	auto t = visitData_type_or_implicit(dti, nullptr);
	return {move(t), false};
}

bool VerTypeParser::visitLifetime(sv2017Parser::LifetimeContext *ctx) {
	// lifetime:
	//     KW_STATIC
	//     | KW_AUTOMATIC
	// ;
	return !ctx || ctx->KW_STATIC();
}

unique_ptr<iHdlExpr> VerTypeParser::visitData_type_or_void(
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
unique_ptr<iHdlExpr> VerTypeParser::visitVar_data_type(
		sv2017Parser::Var_data_typeContext *ctx) {
	// var_data_type:
	//   KW_VAR ( data_type_or_implicit )?
	//    | data_type
	// ;
	if (!ctx)
		return Utils::mkWireT();
	auto dti = ctx->data_type_or_implicit();
	if (dti)
		return visitData_type_or_implicit(dti, nullptr);
	auto dt = ctx->data_type();
	if (dt)
		return visitData_type(dt);
	else
		assert(ctx->KW_VAR());
	return Utils::mkWireT();
}

unique_ptr<iHdlExpr> VerTypeParser::visitFunction_data_type_or_implicit(
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
