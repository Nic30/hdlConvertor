#include <hdlConvertor/svConvertor/typeParser.h>

#include <hdlConvertor/createObject.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/hdlAst/hdlOpType.h>
#include <hdlConvertor/svConvertor/utils.h>
#include <hdlConvertor/svConvertor/exprParser.h>
#include <hdlConvertor/hdlAst/hdlOp.h>

using namespace std;
using namespace hdlConvertor::hdlAst;

namespace hdlConvertor {
namespace sv {

VerTypeParser::VerTypeParser(SVCommentParser &_commentParser) :
		commentParser(_commentParser) {
}

unique_ptr<iHdlExprItem> VerTypeParser::visitType_reference(
		sv2017Parser::Type_referenceContext *ctx) {
	// type_reference:
	//     KW_TYPE LPAREN (
	//         expression
	//         | data_type
	//     ) RPAREN
	// ;
	unique_ptr<iHdlExprItem> res = nullptr;
	auto e = ctx->expression();
	if (e) {
		VerExprParser ep(commentParser);
		res = ep.visitExpression(e);
	} else {
		auto dt = ctx->data_type();
		assert(dt);
		res = visitData_type(dt);
	}
	return create_object<HdlOp>(ctx, HdlOpType::TYPE_OF, move(res));
}

unique_ptr<iHdlExprItem> VerTypeParser::visitInteger_type(
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

unique_ptr<iHdlExprItem> VerTypeParser::visitNon_integer_type(
		sv2017Parser::Non_integer_typeContext *ctx) {
	// non_integer_type:
	//     KW_SHORTREAL
	//     | KW_REAL
	//     | KW_REALTIME
	// ;
	return create_object<HdlValueId>(ctx, ctx->getText());
}
unique_ptr<iHdlExprItem> VerTypeParser::visitInteger_atom_type(
		sv2017Parser::Integer_atom_typeContext *ctx) {
	// integer_atom_type:
	//     KW_BYTE
	//     | KW_SHORTINT
	//     | KW_INT
	//     | KW_LONGINT
	//     | KW_INTEGER
	//     | KW_TIME
	// ;
	return create_object<HdlValueId>(ctx, ctx->getText());
}

unique_ptr<iHdlExprItem> VerTypeParser::visitInteger_vector_type(
		sv2017Parser::Integer_vector_typeContext *ctx) {
	// integer_vector_type:
	//     KW_BIT
	//     | KW_LOGIC
	//     | KW_REG
	// ;
	return Utils::mkWireT(ctx, create_object<HdlValueId>(ctx, ctx->getText()),
			HdlValueSymbol::null(), SIGNING_VAL::NO_SIGN);
}

unique_ptr<iHdlExprItem> VerTypeParser::visitData_type_primitive(
		sv2017Parser::Data_type_primitiveContext *ctx) {
	// data_type_primitive:
	//     integer_type ( signing )?
	//     | non_integer_type
	// ;
	auto it = ctx->integer_type();
	if (it) {
		auto t = visitInteger_type(it);
		auto sig = ctx->signing(); // [TODO] wire in correct format (parametrization <t, widt, sign>)
		if (sig) {
			auto _sig = visitSigning(sig);
			if (_sig != SIGNING_VAL::NO_SIGN) {
				auto c = dynamic_cast<HdlOp*>(t.get());
				auto sign = Utils::signing(_sig);
				if (c && c->op == HdlOpType::PARAMETRIZATION
						&& c->operands.size() == 3) {
					// fill up sign flag for wire/reg types
					c->operands[2] = move(sign);
				} else {
					// specify sign for rest of the types
					vector<unique_ptr<iHdlExprItem>> args;
					args.push_back(
							create_object<HdlOp>(ctx,
									make_unique<HdlValueId>("signed"),
									HdlOpType::MAP_ASSOCIATION, move(sign)));
					t = HdlOp::parametrization(ctx, move(t), args);
				}
			}
		}
		return t;
	} else {
		auto nit = ctx->non_integer_type();
		assert(nit);
		return visitNon_integer_type(nit);
	}
}

unique_ptr<iHdlExprItem> VerTypeParser::visitData_type(
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
	auto _s = ctx->KW_STRING();
	if (_s)
		return create_object<HdlValueId>(_s, "string");

	auto _c = ctx->KW_CHANDLE();
	if (_c)
		return create_object<HdlValueId>(_c, "chandle");

	if (ctx->KW_VIRTUAL()) {
		NotImplementedLogger::print("VerTypeParser.visitData_type - virtual",
				ctx);
		auto ids = ctx->identifier();
		VerExprParser ep(commentParser);
		auto t = ep.visitIdentifier(ids[0]);
		auto pva = ctx->parameter_value_assignment();
		if (pva) {
			auto p = ep.visitParameter_value_assignment(pva);
			t = HdlOp::parametrization(ctx, move(t), p);
		}
		if (ids.size() == 2) {
			auto id = ep.visitIdentifier(ids[1]);
			t = create_object<HdlOp>(ids[1], move(t), HdlOpType::DOT, move(id));
		} else {
			assert(ids.size() == 1);
		}
		return t;
	}

	auto _e = ctx->KW_EVENT();
	if (_e)
		return create_object<HdlValueId>(_e, "event");
	auto _tr = ctx->type_reference();
	if (_tr) {
		return visitType_reference(_tr);
	}

	auto dtp = ctx->data_type_primitive();
	unique_ptr<iHdlExprItem> t = nullptr;
	if (dtp) {
		t = visitData_type_primitive(dtp);
	} else if (ctx->KW_ENUM()) {
		NotImplementedLogger::print("VerTypeParser.visitData_type - enum", ctx);
		t = create_object<HdlExprNotImplemented>(ctx);
	} else if (ctx->struct_union()) {
		NotImplementedLogger::print(
				"VerTypeParser.visitData_type - struct or union", ctx);
		t = create_object<HdlExprNotImplemented>(ctx);
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

unique_ptr<iHdlExprItem> VerTypeParser::visitData_type_or_implicit(
		sv2017Parser::Data_type_or_implicitContext *ctx,
		unique_ptr<iHdlExprItem> net_type) {
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

unique_ptr<iHdlExprItem> VerTypeParser::visitUnpacked_dimension(
		sv2017Parser::Unpacked_dimensionContext *ctx) {
	// unpacked_dimension: LSQUARE_BR range_expression RSQUARE_BR;
	auto ra = ctx->range_expression();
	return VerExprParser(commentParser).visitRange_expression(ra);
}

unique_ptr<iHdlExprItem> VerTypeParser::applyUnpacked_dimension(
		unique_ptr<iHdlExprItem> base_expr,
		vector<sv2017Parser::Unpacked_dimensionContext*> &uds) {
	for (auto _ud : uds) {
		auto ud = visitUnpacked_dimension(_ud);
		base_expr = create_object<HdlOp>(_ud, move(base_expr), HdlOpType::INDEX,
				move(ud));
	}
	return base_expr;
}

unique_ptr<iHdlExprItem> VerTypeParser::applyVariable_dimension(
		unique_ptr<iHdlExprItem> base_expr,
		vector<sv2017Parser::Variable_dimensionContext*> &vds) {
	// optionally fill up width of wire/reg datatypes
	auto wire_reg_parametrization = dynamic_cast<HdlOp*>(base_expr.get());
	if (wire_reg_parametrization) {
		if (wire_reg_parametrization->op != HdlOpType::PARAMETRIZATION) {
			wire_reg_parametrization = nullptr;
		} else if (wire_reg_parametrization->operands.size() != 3) {
			wire_reg_parametrization = nullptr;

		} else {
			auto w =
					dynamic_cast<HdlValueSymbol*>(wire_reg_parametrization->operands[1].get());
			if (w) {
				if (w->symb != HdlValueSymbol_t::symb_NULL)
					wire_reg_parametrization = nullptr;
			} else {
				wire_reg_parametrization = nullptr;
			}
		}
	}

	for (auto _vd : vds) {
		if (wire_reg_parametrization) {
			auto d = _visitVariable_dimension(_vd);
			if (d == nullptr)
				d = HdlValueSymbol::null();
			wire_reg_parametrization->operands[1] = move(d);

			wire_reg_parametrization = nullptr;
			continue;
		}
		base_expr = visitVariable_dimension(_vd, move(base_expr));
	}
	return base_expr;
}

unique_ptr<iHdlExprItem> VerTypeParser::visitPacked_dimension(
		sv2017Parser::Packed_dimensionContext *ctx) {
	// packed_dimension: LSQUARE_BR  ( range_expression )? RSQUARE_BR;
	auto ra = ctx->range_expression();
	if (ra)
		return VerExprParser(commentParser).visitRange_expression(ra);
	return nullptr;
}

SIGNING_VAL VerTypeParser::visitSigning(sv2017Parser::SigningContext *ctx) {
	// signing:
	//     KW_SIGNED
	//     | KW_UNSIGNED
	// ;
	if (ctx->KW_SIGNED()) {
		return SIGNING_VAL::SIGNED;
	} else {
		assert(ctx->KW_UNSIGNED());
		return SIGNING_VAL::UNSIGNED;
	}
}

unique_ptr<iHdlExprItem> VerTypeParser::visitImplicit_data_type(
		sv2017Parser::Implicit_data_typeContext *ctx,
		unique_ptr<iHdlExprItem> net_type) {
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
	SIGNING_VAL is_signed = SIGNING_VAL::NO_SIGN;
	auto pds = ctx->packed_dimension();
	if (s) {
		is_signed = visitSigning(s);
	}
	unique_ptr<iHdlExprItem> e = nullptr;
	auto it = pds.begin();
	if (it != pds.end()) {
		auto r0 = visitPacked_dimension(*it);
		if (r0 == nullptr)
			r0 = HdlValueSymbol::null();
		e = Utils::mkWireT(*it, move(net_type), move(r0), is_signed);
		++it;
	} else {
		e = Utils::mkWireT(nullptr, HdlValueSymbol::null(), is_signed);
	}
	for (; it != pds.end(); ++it) {
		auto pd = visitPacked_dimension(*it);
		if (pd) {
			e = create_object<HdlOp>(*it, move(e), HdlOpType::INDEX, move(pd));
		} else {
			e = create_object<HdlOp>(*it, HdlOpType::INDEX, move(e));

		}
	}
	return e;
}
unique_ptr<iHdlExprItem> VerTypeParser::_visitVariable_dimension(
		sv2017Parser::Variable_dimensionContext *ctx) {
	// variable_dimension:
	//     LSQUARE_BR ( MUL
	//              | data_type
	//              | array_range_expression
	//               )? RSQUARE_BR
	// ;
	unique_ptr<iHdlExprItem> index = nullptr;
	if (ctx->MUL()) {
		NotImplementedLogger::print(
				"VerExprParser.visitVariable_dimension - MUL", ctx);
		return nullptr;
	}
	auto dt = ctx->data_type();
	if (dt) {
		index = VerTypeParser(commentParser).visitData_type(dt);
	} else {
		auto are = ctx->array_range_expression();
		if (are) {
			index = VerExprParser(commentParser).visitArray_range_expression(
					are);
		}
	}
	return index;
}
unique_ptr<iHdlExprItem> VerTypeParser::visitVariable_dimension(
		sv2017Parser::Variable_dimensionContext *ctx,
		unique_ptr<iHdlExprItem> selected_name) {
	auto index = _visitVariable_dimension(ctx);
	if (index == nullptr) {
		return create_object<HdlOp>(ctx, HdlOpType::INDEX, move(selected_name));
	} else {
		return create_object<HdlOp>(ctx, move(selected_name), HdlOpType::INDEX,
				move(index));
	}
}
unique_ptr<iHdlExprItem> VerTypeParser::visitNet_type(
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
	return create_object<HdlValueId>(ctx, ctx->getText());
}
unique_ptr<iHdlExprItem> VerTypeParser::visitNet_port_type(
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
	unique_ptr<iHdlExprItem> net_type = nullptr;
	auto _nt = ctx->net_type();
	if (_nt)
		net_type = visitNet_type(_nt);
	auto dti = ctx->data_type_or_implicit();
	return visitData_type_or_implicit(dti, move(net_type));
}
pair<unique_ptr<iHdlExprItem>, bool> VerTypeParser::visitNet_or_var_data_type(
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

unique_ptr<iHdlExprItem> VerTypeParser::visitData_type_or_void(
		sv2017Parser::Data_type_or_voidContext *ctx) {
	// data_type_or_void:
	//    KW_VOID
	//    | data_type
	// ;
	if (ctx->KW_VOID()) {
		return create_object<HdlValueId>(ctx, "void");
	} else {
		auto dt = ctx->data_type();
		return visitData_type(dt);
	}
}
unique_ptr<iHdlExprItem> VerTypeParser::visitVar_data_type(
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

unique_ptr<iHdlExprItem> VerTypeParser::visitFunction_data_type_or_implicit(
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
