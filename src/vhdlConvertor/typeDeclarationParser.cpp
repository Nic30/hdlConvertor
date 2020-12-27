#include <hdlConvertor/vhdlConvertor/typeDeclarationParser.h>

#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/vhdlConvertor/exprParser.h>
#include <hdlConvertor/vhdlConvertor/interfaceParser.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>
#include <hdlConvertor/createObject.h>

#include <assert.h>

namespace hdlConvertor {
namespace vhdl {

using namespace std;
using namespace hdlConvertor::hdlAst;

unique_ptr<HdlIdDef> VhdlTypeDeclarationParser::visitType_declaration(
		vhdlParser::Type_declarationContext *ctx) {
	//type_declaration:
	//      full_type_declaration
	//      | incomplete_type_declaration
	//;
	auto ftd = ctx->full_type_declaration();
	if (ftd)
		return visitFull_type_declaration(ftd);
	else
		return visitIncomplete_type_declaration(
				ctx->incomplete_type_declaration());
}

unique_ptr<HdlIdDef> VhdlTypeDeclarationParser::visitIncomplete_type_declaration(
		vhdlParser::Incomplete_type_declarationContext *ctx) {
	//incomplete_type_declaration: KW_TYPE identifier SEMI;
	auto id = VhdlLiteralParser::getIdentifierStr(ctx->identifier());
	return create_object<HdlIdDef>(ctx, move(id), HdlValueSymbol::type(),
			nullptr);
}

unique_ptr<HdlIdDef> VhdlTypeDeclarationParser::visitFull_type_declaration(
		vhdlParser::Full_type_declarationContext *ctx) {
	//full_type_declaration:
	//      KW_TYPE identifier KW_IS type_definition SEMI
	//;
	auto td = ctx->type_definition();
	auto id = VhdlLiteralParser::getIdentifierStr(ctx->identifier());
	return visitType_definition(move(id), td);
}

unique_ptr<HdlIdDef> VhdlTypeDeclarationParser::visitType_definition(
		string &&name, vhdlParser::Type_definitionContext *ctx) {
	//type_definition:
	//      scalar_type_definition
	//      | composite_type_definition
	//      | access_type_definition
	//      | file_type_definition
	//      | protected_type_definition
	//;
	unique_ptr<iHdlExprItem> t;
	auto scl = ctx->scalar_type_definition();
	if (scl) {
		t = visitScalar_type_definition(scl);
	} else {
		auto cmp = ctx->composite_type_definition();
		if (cmp) {
			t = visitComposite_type_definition(cmp);
		} else {
			auto acc = ctx->access_type_definition();
			if (acc) {
				t = visitAccess_type_definition(acc);
			} else {
				auto fil = ctx->file_type_definition();
				if (fil) {
					t = visitFile_type_definition(fil);
				} else {
					auto pro = ctx->protected_type_definition();
					assert(pro);
					t = visitProtected_type_definition(pro);
				}
			}
		}
	}
	return create_object<HdlIdDef>(ctx, move(name), HdlValueSymbol::type(),
			move(t));
}

unique_ptr<iHdlExprItem> VhdlTypeDeclarationParser::visitScalar_type_definition(
		vhdlParser::Scalar_type_definitionContext *ctx) {
	//scalar_type_definition:
	//      enumeration_type_definition
	//      | integer_type_definition
	//      | floating_type_definition
	//      | physical_type_definition
	//;
	auto e = ctx->enumeration_type_definition();
	if (e)
		return visitEnumeration_type_definition(e);
	auto i = ctx->integer_type_definition();
	if (i)
		return visitInteger_type_definition(i);
	auto f = ctx->floating_type_definition();
	if (f)
		return visitFloating_type_definition(f);
	auto p = ctx->physical_type_definition();
	assert(p);
	return visitPhysical_type_definition(p);
}

unique_ptr<iHdlExprItem> VhdlTypeDeclarationParser::visitComposite_type_definition(
		vhdlParser::Composite_type_definitionContext *ctx) {
	//composite_type_definition:
	//      array_type_definition
	//      | record_type_definition
	//;
	auto arr = ctx->array_type_definition();
	if (arr)
		return visitArray_type_definition(arr);
	auto rec = ctx->record_type_definition();
	assert(rec);
	return visitRecord_type_definition(rec);
}

unique_ptr<iHdlExprItem> VhdlTypeDeclarationParser::visitAccess_type_definition(
		vhdlParser::Access_type_definitionContext *ctx) {
	NotImplementedLogger::print("TypeDeclarationParser.access_type_definition",
			ctx);
	return create_object<HdlExprNotImplemented>(ctx);
}

unique_ptr<iHdlExprItem> VhdlTypeDeclarationParser::visitFile_type_definition(
		vhdlParser::File_type_definitionContext *ctx) {

	NotImplementedLogger::print("TypeDeclarationParser.file_type_definition",
			ctx);
	return create_object<HdlExprNotImplemented>(ctx);;
}

unique_ptr<iHdlExprItem> VhdlTypeDeclarationParser::visitProtected_type_definition(
		vhdlParser::Protected_type_definitionContext *ctx) {
	NotImplementedLogger::print(
			"TypeDeclarationParser.protected_type_definition", ctx);
	return create_object<HdlExprNotImplemented>(ctx);
}

unique_ptr<HdlEnumDef> VhdlTypeDeclarationParser::visitEnumeration_type_definition(
		vhdlParser::Enumeration_type_definitionContext *ctx) {
	//enumeration_type_definition:
	//      LPAREN enumeration_literal ( COMMA enumeration_literal )* RPAREN
	//;
	auto tdecl = make_unique<HdlEnumDef>();
	for (auto lit : ctx->enumeration_literal()) {
		// enumeration_literal: identifier | CHARACTER_LITERAL;
		auto _id = lit->identifier();
		if (_id) {
			auto id = VhdlLiteralParser::getIdentifierStr(_id);
			tdecl->values.push_back( { make_unique<string>(id), nullptr });
		} else {
			auto _cl = lit->CHARACTER_LITERAL();
			assert(_cl);
			auto cl = VhdlLiteralParser::visitCHARACTER_LITERAL(_cl,
					_cl->getText());
			tdecl->values.push_back( { nullptr, move(cl) });
		}
	}
	return tdecl;
}

unique_ptr<iHdlExprItem> VhdlTypeDeclarationParser::visitRange_constraint(
		vhdlParser::Range_constraintContext *ctx) {
	// range_constraint
	// : RANGE range
	// ;
	return VhdlExprParser::visitRange(ctx->range());
}

unique_ptr<iHdlExprItem> VhdlTypeDeclarationParser::visitInteger_type_definition(
		vhdlParser::Integer_type_definitionContext *ctx) {
	// integer_type_definition: range_constraint;
	auto r = ctx->range_constraint();
	auto rc = visitRange_constraint(r);
	return create_object<HdlOp>(ctx, HdlOpType::RANGE, move(rc));
}

unique_ptr<iHdlExprItem> VhdlTypeDeclarationParser::visitFloating_type_definition(
		vhdlParser::Floating_type_definitionContext *ctx) {
	// floating_type_definition: range_constraint;
	auto r = ctx->range_constraint();
	auto rc = visitRange_constraint(r);
	return create_object<HdlOp>(ctx, HdlOpType::RANGE, move(rc));
}

unique_ptr<HdlPhysicalDef> VhdlTypeDeclarationParser::visitPhysical_type_definition(
		vhdlParser::Physical_type_definitionContext *ctx) {
	// physical_type_definition:
	//   range_constraint
	//       KW_UNITS
	//           primary_unit_declaration
	//           ( secondary_unit_declaration )*
	//       KW_END KW_UNITS ( identifier )?
	// ;
	auto r = ctx->range_constraint();
	auto rop = visitRange_constraint(r);

	auto pdecl = make_unique<HdlPhysicalDef>();
	pdecl->range = create_object<HdlOp>(ctx, HdlOpType::RANGE, move(rop));
	// primary_unit_declaration: identifier SEMI;
	auto _pu = ctx->primary_unit_declaration()->identifier();
	auto pu = VhdlLiteralParser::getIdentifierStr(_pu);
	pdecl->members.push_back( { pu, nullptr });
	// secondary_unit_declaration: identifier EQ physical_literal SEMI;
	for (auto uit : ctx->secondary_unit_declaration()) {
		auto _su = uit->identifier();
		auto su = VhdlLiteralParser::getIdentifierStr(_su);
		auto val = VhdlLiteralParser::visitPhysical_literal(
				uit->physical_literal());
		pdecl->members.push_back( { su, move(val) });
	}
	return pdecl;
}

unique_ptr<iHdlExprItem> VhdlTypeDeclarationParser::visitArray_type_definition(
		vhdlParser::Array_type_definitionContext *ctx) {
	//array_type_definition:
	//      unbounded_array_definition | constrained_array_definition
	//;
	auto ub = ctx->unbounded_array_definition();
	if (ub)
		return visitUnbounded_array_definition(ub);
	auto con = ctx->constrained_array_definition();
	assert(con);
	return visitConstrained_array_definition(con);
}

unique_ptr<iHdlExprItem> VhdlTypeDeclarationParser::visitUnbounded_array_definition(
		vhdlParser::Unbounded_array_definitionContext *ctx) {
	//unbounded_array_definition:
	//      KW_ARRAY LPAREN index_subtype_definition ( COMMA index_subtype_definition )* RPAREN
	//          KW_OF subtype_indication
	//;
	auto element_t = visitSubtype_indication(ctx->subtype_indication());
	auto tdef = make_unique<HdlOp>(HdlOpType::INDEX, move(element_t));
	for (auto isd : ctx->index_subtype_definition()) {
		auto i = visitIndex_subtype_definition(isd);
		tdef->operands.push_back(move(i));
	}
	return tdef;
}

unique_ptr<iHdlExprItem> VhdlTypeDeclarationParser::visitIndex_subtype_definition(
		vhdlParser::Index_subtype_definitionContext *ctx) {
	// index_subtype_definition: type_mark KW_RANGE BOX;
	auto _tm = ctx->type_mark();
	auto tm = VhdlExprParser::visitType_mark(_tm);
	return create_object<HdlOp>(ctx, move(tm), HdlOpType::RANGE,
			HdlValueSymbol::open());
}

unique_ptr<iHdlExprItem> VhdlTypeDeclarationParser::visitConstrained_array_definition(
		vhdlParser::Constrained_array_definitionContext *ctx) {
	//constrained_array_definition:
	//      KW_ARRAY index_constraint KW_OF subtype_indication
	//;
	auto element_t = visitSubtype_indication(ctx->subtype_indication());
	return visitIndex_constraint(move(element_t), ctx->index_constraint());
}

unique_ptr<HdlClassDef> VhdlTypeDeclarationParser::visitRecord_type_definition(
		vhdlParser::Record_type_definitionContext *ctx) {
	//record_type_definition:
	//      KW_RECORD
	//          ( element_declaration )+
	//      KW_END KW_RECORD ( identifier )?
	//;
	auto c = create_object<HdlClassDef>(ctx);
	c->type = HdlClassType::STRUCT;
	for (auto _ed : ctx->element_declaration()) {
		auto vars = visitElement_declaration(_ed);
		for (auto &v : *vars) {
			c->members.push_back(move(v));
		}
	}

	return c;
}
std::unique_ptr<vector<std::unique_ptr<HdlIdDef>>> VhdlTypeDeclarationParser::visitElement_declaration(
		vhdlParser::Element_declarationContext *ctx) {
	// element_declaration:
	//       identifier_list COLON element_subtype_definition SEMI
	// ;
	// element_subtype_definition: subtype_indication;
	auto id_list = ctx->identifier_list();
	auto st = ctx->element_subtype_definition()->subtype_indication();

	return VhdlInterfaceParser::extractVariables(id_list, st, nullptr);
}

std::unique_ptr<HdlIdDef> VhdlTypeDeclarationParser::visitSubtype_declaration(
		vhdlParser::Subtype_declarationContext *ctx) {
	//subtype_declaration
	//  : SUBTYPE identifier IS subtype_indication SEMI
	//  ;
	auto t = visitSubtype_indication(ctx->subtype_indication());
	auto v = create_object<HdlIdDef>(ctx,
			VhdlLiteralParser::getIdentifierStr(ctx->identifier()),
			HdlValueSymbol::type_subtype(), std::move(t));
	return v;
}

unique_ptr<iHdlExprItem> VhdlTypeDeclarationParser::visitSubtype_indication(
		vhdlParser::Subtype_indicationContext *ctx) {
	// subtype_indication:
	//       ( resolution_indication )? type_mark ( constraint )?
	// ;

	auto _ri = ctx->resolution_indication();
	unique_ptr<iHdlExprItem> ri = nullptr;
	if (_ri) {
		ri = VhdlExprParser::visitResolution_indication(_ri);
	}

	// type_mark: name;
	auto e = VhdlExprParser::visitType_mark(ctx->type_mark());
	auto c = ctx->constraint();
	if (c) {
		e = visitConstraint(move(e), c);
	}
	if (ri) {
		return create_object<HdlOp>(ctx, move(ri), HdlOpType::DEFINE_RESOLVER,
				move(e));
	} else {
		return e;
	}
}

/*
 * @return element_type, dimension indexes
 * */
unique_ptr<iHdlExprItem> VhdlTypeDeclarationParser::visitArray_constraint(
		unique_ptr<iHdlExprItem> selectedName,
		vhdlParser::Array_constraintContext *ctx) {
	// array_constraint:
	//       index_constraint ( array_element_constraint )?
	//       | LPAREN OPEN RPAREN ( array_element_constraint )?
	// ;
	auto ic = ctx->index_constraint();
	unique_ptr<iHdlExprItem> res;
	if (ic) {
		res = visitIndex_constraint(move(selectedName), ic);
	} else {
		res = create_object<HdlOp>(ctx, move(selectedName), HdlOpType::INDEX,
				HdlValueSymbol::all());
	}
	auto aec = ctx->array_element_constraint();
	if (aec) {
		res = visitArray_element_constraint(move(res), aec);
	}

	return res;
}

unique_ptr<iHdlExprItem> VhdlTypeDeclarationParser::visitIndex_constraint(
		unique_ptr<iHdlExprItem> selectedName,
		vhdlParser::Index_constraintContext *ctx) {
	// index_constraint
	// : LPAREN discrete_range ( COMMA discrete_range )* RPAREN
	// ;
	unique_ptr<iHdlExprItem> res = move(selectedName);
	vector<unique_ptr<iHdlExprItem>> indexes;
	for (auto dr_ctx : ctx->discrete_range()) {
		indexes.push_back(VhdlExprParser::visitDiscrete_range(dr_ctx));
	}
	res = HdlOp::index(ctx, move(res), indexes);
	return res;
}

unique_ptr<iHdlExprItem> VhdlTypeDeclarationParser::visitArray_element_constraint(
		unique_ptr<iHdlExprItem> selectedName,
		vhdlParser::Array_element_constraintContext *ctx) {
	// array_element_constraint: element_constraint;
	return visitElement_constraint(move(selectedName),
			ctx->element_constraint());
}

unique_ptr<iHdlExprItem> VhdlTypeDeclarationParser::visitElement_constraint(
		unique_ptr<iHdlExprItem> selectedName,
		vhdlParser::Element_constraintContext *ctx) {
	// element_constraint:
	//       array_constraint
	//       | record_constraint
	// ;
	auto i = ctx->array_constraint();
	if (i) {
		return visitArray_constraint(move(selectedName), i);
	} else {
		auto rc = ctx->record_constraint();
		return visitRecord_constraint(rc);
	}
}

unique_ptr<iHdlExprItem> VhdlTypeDeclarationParser::visitConstraint(
		unique_ptr<iHdlExprItem> selectedName,
		vhdlParser::ConstraintContext *ctx) {
	// constraint:
	//       range_constraint
	//       | element_constraint
	// ;

	auto r = ctx->range_constraint();
	if (r) {
		auto rc = visitRange_constraint(r);
		return create_object<HdlOp>(r, move(selectedName), HdlOpType::RANGE,
				move(rc));
	} else {
		auto ec = ctx->element_constraint();
		return visitElement_constraint(move(selectedName), ec);
	}
}

unique_ptr<iHdlExprItem> VhdlTypeDeclarationParser::visitRecord_constraint(
		vhdlParser::Record_constraintContext *ctx) {
	NotImplementedLogger::print(
			"VhdlTypeDeclarationParser.visitRecord_constraint", ctx);
	return create_object<HdlExprNotImplemented>(ctx);
}

}
}
