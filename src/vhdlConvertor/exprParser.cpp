#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/vhdlConvertor/operatorTypeParser.h>
#include <hdlConvertor/hdlAst/hdlOp.h>
#include <hdlConvertor/vhdlConvertor/directionParser.h>
#include <hdlConvertor/vhdlConvertor/exprParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>
#include <hdlConvertor/vhdlConvertor/typeDeclarationParser.h>
#include <hdlConvertor/createObject.h>
#include <assert.h>

namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlAst;
using namespace std;

unique_ptr<vector<unique_ptr<iHdlExprItem>>> VhdlExprParser::visitAssociation_list(
		vhdlParser::Association_listContext *ctx) {
	// association_list:
	//       association_element ( COMMA association_element )*
	// ;
	auto ae = make_unique<vector<unique_ptr<iHdlExprItem>>>();
	for (auto e : ctx->association_element()) {
		ae->push_back(visitAssociation_element(e));
	}
	return ae;
}

unique_ptr<iHdlExprItem> VhdlExprParser::visitAssociation_element(
		vhdlParser::Association_elementContext *ctx) {
	// association_element:
	//       ( formal_part ARROW )? actual_part
	// ;
	auto _ap = ctx->actual_part();
	auto ap = visitActual_part(_ap);
	auto fp = ctx->formal_part();
	if (fp) {
		return create_object<HdlOp>(ctx, visitFormal_part(fp), ARROW,
				move(ap));
	}
	return ap;
}

unique_ptr<iHdlExprItem> VhdlExprParser::visitFormal_part(
		vhdlParser::Formal_partContext *ctx) {
	// formal_part:
	//       formal_designator
	//       | name LPAREN formal_designator RPAREN
	//       | type_mark LPAREN formal_designator RPAREN
	// ;
	// formal_part:
	//       name (LPAREN name RPAREN)?
	// ;
	auto names = ctx->name();
	auto id = VhdlReferenceParser::visitName(names[0]);
	if (names.size() > 1) {
		vector<unique_ptr<iHdlExprItem>> args;
		args.push_back(VhdlReferenceParser::visitName(names[1]));
		return HdlOp::call(ctx, move(id), args);
	} else {
		return id;
	}
}

unique_ptr<HdlOp> VhdlExprParser::visitExplicit_range(
		vhdlParser::Explicit_rangeContext *ctx) {
	// explicit_range
	// : simple_expression direction simple_expression
	// ;
	HdlOpType op;
	if (ctx->direction()->KW_DOWNTO()) {
		op = DOWNTO;
	} else {
		op = TO;
	}
	return create_object<HdlOp>(ctx,
			visitSimple_expression(ctx->simple_expression(0)), op,
			visitSimple_expression(ctx->simple_expression(1)));
}

unique_ptr<iHdlExprItem> VhdlExprParser::visitRange(
		vhdlParser::RangeContext *ctx) {
	//range:
	//      attribute_name
	//      | simple_expression direction simple_expression
	//;
	auto an = ctx->attribute_name();
	if (an)
		return VhdlReferenceParser::visitAttribute_name(an);
	auto se = ctx->simple_expression();
	auto a = visitSimple_expression(se[0]);
	auto o = visitDirection(ctx->direction());
	auto b = visitSimple_expression(se[1]);
	return create_object<HdlOp>(ctx, move(a), o, move(b));
}

unique_ptr<iHdlExprItem> VhdlExprParser::visitActual_part(
		vhdlParser::Actual_partContext *ctx) {
	// actual_part:
	//       name LPAREN actual_designator RPAREN
	//       | actual_designator
	// ;

	auto name = ctx->name();
	auto _ad = ctx->actual_designator();
	unique_ptr<iHdlExprItem> ad = visitActual_designator(_ad);
	if (name) {
		vector<unique_ptr<iHdlExprItem>> ops;
		ops.push_back(move(ad));
		return HdlOp::call(ctx, VhdlReferenceParser::visitName(name), ops);
	}
	return ad;
}
unique_ptr<iHdlExprItem> VhdlExprParser::visitActual_designator(
		vhdlParser::Actual_designatorContext *ctx) {
	//actual_designator:
	//      ( INERTIAL )? expression
	//      | subtype_indication
	//      | OPEN
	//;
	if (ctx->KW_OPEN())
		return update_code_position(HdlValueSymbol::open(), ctx);
	auto sti = ctx->subtype_indication();
	if (sti)
		return VhdlTypeDeclarationParser::visitSubtype_indication(sti);
	return visitExpression(ctx->expression());
}

unique_ptr<iHdlExprItem> VhdlExprParser::visitResolution_indication(
		vhdlParser::Resolution_indicationContext *ctx) {
	// resolution_indication:
	//       name | LPAREN element_resolution RPAREN
	// ;
	// element_resolution: array_element_resolution | record_resolution;
	auto n = ctx->name();
	if (n) {
		return VhdlReferenceParser::visitName(n);
	}

	NotImplementedLogger::print(
			"ExprParser.visitResolution_indication - element_resolution", ctx);
	return create_object<HdlExprNotImplemented>(ctx);
}

unique_ptr<iHdlExprItem> VhdlExprParser::visitDiscrete_range(
		vhdlParser::Discrete_rangeContext *ctx) {
	// discrete_range
	// : range
	// | subtype_indication
	// ;
	auto r = ctx->range();
	if (r)
		return visitRange(r);
	return VhdlTypeDeclarationParser::visitSubtype_indication(ctx->subtype_indication());
}

HdlOpType VhdlExprParser::visitSign(vhdlParser::SignContext *ctx) {
	// sign: PLUS | MINUS;
	if (ctx->MINUS()) {
		return HdlOpType::SUB;
	} else {
		assert(ctx->PLUS());
		return HdlOpType::ADD;
	}
}

void aggregate_to_parenthesis(unique_ptr<iHdlExprItem> &o) {
	auto v = dynamic_cast<HdlValueArr*>(o.get());
	if (v && v->_arr && v->_arr->size() == 1) {
		o = move(v->_arr->at(0));
	}
}

unique_ptr<iHdlExprItem> VhdlExprParser::visitSimple_expression(
		vhdlParser::Simple_expressionContext *ctx) {
	// simple_expression:
	//       primary ( DOUBLESTAR primary )?
	//       | ( KW_ABS | KW_NOT | logical_operator | sign ) simple_expression
	//       | simple_expression multiplying_operator simple_expression
	//       | simple_expression adding_operator simple_expression
	// ;
	auto _primary = ctx->primary();
	if (_primary.size() == 1) {
		return visitPrimary(_primary[0]);
	} else if (_primary.size() == 2) {
		auto p0 = visitPrimary(_primary[0]);
		aggregate_to_parenthesis(p0);
		auto p1 = visitPrimary(_primary[1]);
		aggregate_to_parenthesis(p1);
		assert(ctx->DOUBLESTAR());
		return create_object<HdlOp>(ctx, move(p0), HdlOpType::POW,
				move(p1));
	}
	auto se = ctx->simple_expression();
	HdlOpType op;
	if (se.size() == 1) {
		if (ctx->KW_ABS()) {
			op = HdlOpType::ABS;
		} else if (ctx->KW_NOT()) {
			op = HdlOpType::NEG;
		} else {
			auto lo = ctx->logical_operator();
			if (lo) {
				op = HdlOpType_from(lo);
			} else {
				auto s = ctx->sign();
				assert(s);
				op = HdlOpType_from(s);
			}
			op = HdlOpType_toUnary(op);
		}
		auto se0 = visitSimple_expression(se[0]);
		aggregate_to_parenthesis(se0);
		return create_object<HdlOp>(ctx, op, move(se0));
	} else {
		assert(se.size() == 2);
		auto mo = ctx->multiplying_operator();
		if (mo) {
			op = HdlOpType_from(mo);
		} else {
			auto ao = ctx->adding_operator();
			assert(ao);
			op = HdlOpType_from(ao);
		}

		auto se0 = visitSimple_expression(se[0]);
		aggregate_to_parenthesis(se0);
		auto se1 = visitSimple_expression(se[1]);
		aggregate_to_parenthesis(se1);
		return create_object<HdlOp>(ctx, move(se0), op, move(se1));
	}
}
unique_ptr<iHdlExprItem> VhdlExprParser::visitExpression(
		vhdlParser::ExpressionContext *ctx) {
	// expression:
	//       COND_OP primary
	//       | simple_expression
	//       | expression shift_operator expression
	//       | expression relational_operator expression
	//       | expression logical_operator expression
	// ;

	if (ctx->COND_OP()) {
		NotImplementedLogger::print(
				"ExprParser.visitExpression - CONDITION_OPERATOR", ctx);
		auto p = ctx->primary();
		assert(p);
		auto vp = visitPrimary(p);
		aggregate_to_parenthesis(vp);
		return vp;
	}
	auto _se = ctx->simple_expression();
	if (_se) {
		return visitSimple_expression(_se);
	}
	auto _ops = ctx->expression();
	assert(_ops.size() == 2);
	auto op0 = visitExpression(_ops[0]);
	auto op1 = visitExpression(_ops[1]);
	auto so = ctx->shift_operator();
	HdlOpType op;
	if (so) {
		op = HdlOpType_from(so);
	} else {
		auto ro = ctx->relational_operator();
		if (ro) {
			op = HdlOpType_from(ro);
		} else {
			auto lo = ctx->logical_operator();
			assert(lo);
			op = HdlOpType_from(lo);
		}
	}
	return create_object<HdlOp>(ctx, move(op0), op, move(op1));
}

unique_ptr<iHdlExprItem> VhdlExprParser::visitPrimary(
		vhdlParser::PrimaryContext *ctx) {
	//primary:
	//      numeric_literal             #primaryNum
	//      | BIT_STRING_LITERAL        #primaryBitStr
	//      | KW_NULL                   #primaryLiteral
	//      | allocator                 #primaryAllocator
	//      | aggregate                 #primaryAggregate
	//      | qualified_expression      #primaryQualifiedExpr
	//;
	auto nl = ctx->numeric_literal();
	if (nl)
		return VhdlLiteralParser::visitNumeric_literal(nl);

	if (ctx->KW_NULL())
		return update_code_position(HdlValueSymbol::null(), ctx);

	auto bsl = ctx->BIT_STRING_LITERAL();
	if (bsl) {
		return VhdlLiteralParser::visitBIT_STRING_LITERAL(bsl, bsl->getText());
	}
	auto al = ctx->allocator();
	if (al)
		return visitAllocator(al);
	auto ag = ctx->aggregate();
	if (ag) {
		return visitAggregate(ag);
	}
	auto qe = ctx->qualified_expression();
	assert(qe);
	return visitQualified_expression(qe);
}

unique_ptr<iHdlExprItem> VhdlExprParser::visitQualified_expression(
		vhdlParser::Qualified_expressionContext *ctx) {
	// qualified_expression:
	//       type_mark APOSTROPHE aggregate
	// ;
	auto _tm = ctx->type_mark();
	auto tm = visitType_mark(_tm);
	auto a = ctx->aggregate();
	auto e = visitAggregate(a);
	return create_object<HdlOp>(ctx, move(tm), HdlOpType::APOSTROPHE,
			move(e));
}

unique_ptr<iHdlExprItem> VhdlExprParser::visitAllocator(
		vhdlParser::AllocatorContext *ctx) {
	// allocator
	// : KW_NEW ( qualified_expression | subtype_indication )
	// ;
	auto n = create_object<HdlValueId>(ctx->KW_NEW(), "new");
	unique_ptr<iHdlExprItem> e;
	auto qe = ctx->qualified_expression();
	if (qe)
		e = visitQualified_expression(qe);
	else {
		auto si = ctx->subtype_indication();
		e = VhdlTypeDeclarationParser::visitSubtype_indication(si);
	}
	return create_object<HdlOp>(ctx, move(n), HdlOpType::CALL, move(e));
}

unique_ptr<iHdlExprItem> VhdlExprParser::visitAggregate(
		vhdlParser::AggregateContext *ctx) {
	// aggregate:
	//    LPAREN element_association ( COMMA element_association )* RPAREN
	// ;
	vector<unique_ptr<iHdlExprItem>> elements;
	for (auto elm : ctx->element_association()) {
		auto e = visitElement_association(elm);
		elements.push_back(move(e));
	}
	if (elements.size() == 1) {
		auto e = dynamic_cast<HdlOp*>(elements[0].get());
		if (!e || e->op != HdlOpType::MAP_ASSOCIATION)
			return move(elements[0]);
	}
	return create_object<HdlValueArr>(ctx, elements);
}

unique_ptr<iHdlExprItem> VhdlExprParser::visitElement_association(
		vhdlParser::Element_associationContext *ctx) {
	// ement_association
	//   : (  choices ARROW )? expression
	//   ;
	auto e = visitExpression(ctx->expression());
	auto _c = ctx->choices();
	if (_c) {
		auto ch = visitChoices(_c);
		if (ch.size() > 1) {
			NotImplementedLogger::print(
					"ExprParser.visitElement_association - multiple choices",
					_c);
		}
		assert(ch.size());
		return create_object<HdlOp>(ctx, move(ch[0]),
				HdlOpType::MAP_ASSOCIATION, move(e));
	}
	return e;
}

unique_ptr<iHdlExprItem> VhdlExprParser::visitTarget(
		vhdlParser::TargetContext *ctx) {
	// target
	// : name
	// | aggregate
	// ;
	auto n = ctx->name();
	if (n) {
		return VhdlReferenceParser::visitName(n);
	} else {
		return visitAggregate(ctx->aggregate());
	}
}

unique_ptr<iHdlExprItem> VhdlExprParser::visitWaveform(
		vhdlParser::WaveformContext *ctx) {
	// waveform :
	// waveform_element ( COMMA waveform_element )*
	// | UNAFFECTED
	// ;
	if (ctx->KW_UNAFFECTED()) {
		NotImplementedLogger::print("ExprParser.visitWaveform - UNAFFECTED",
				ctx);
		return create_object<HdlExprNotImplemented>(ctx);
	}
	auto we = ctx->waveform_element();
	auto weIt = we.begin();

	auto top = visitWaveform_element(*weIt);
	++weIt;
	while (weIt != we.end()) {
		top = create_object<HdlOp>(ctx, move(top), DOT,
				visitWaveform_element(*weIt));
		++weIt;
	}

	return top;
}

unique_ptr<iHdlExprItem> VhdlExprParser::visitCondition(
		vhdlParser::ConditionContext *ctx) {
	// condition
	// : expression
	// ;
	return VhdlExprParser::visitExpression(ctx->expression());
}

unique_ptr<iHdlExprItem> VhdlExprParser::visitConditional_waveforms(
		vhdlParser::Conditional_waveformsContext *ctx) {
	// conditional_waveforms:
	//       waveform WHEN condition
	//       ( ELSE waveform WHEN condition )*
	//       ( ELSE waveform )?
	// ;
	auto waveforms = ctx->waveform();
	auto conditions = ctx->condition();
	auto c = conditions.rbegin();
	unique_ptr<iHdlExprItem> res = nullptr;
	for (auto w = waveforms.rbegin(); w != waveforms.rend(); ++w) {
		auto w_expr = visitWaveform(*w);
		if (res == nullptr) {
			// the first iteration
			bool has_default_else = waveforms.size() > conditions.size();
			if (has_default_else) {
				// this waveform is a default else
				res = move(w_expr);
				continue;
			}
		}
		auto c_expr = visitCondition(*c);
		res = HdlOp::ternary(*w, move(c_expr), move(w_expr), move(res));
		c++;
	}
	return res;
}

unique_ptr<iHdlExprItem> VhdlExprParser::visitWaveform_element(
		vhdlParser::Waveform_elementContext *ctx) {
	// waveform_element :
	// expression ( AFTER expression )?
	// ;
	auto ex = ctx->expression();
	auto e = ex.begin();
	auto top = visitExpression(*e);
	++e;
	if (e != ex.end()) {
		NotImplementedLogger::print(
				"ExprParser.visitWaveform_element - AFTER expression", ctx);
	}
	return top;
}

unique_ptr<iHdlExprItem> VhdlExprParser::visitChoice(
		vhdlParser::ChoiceContext *ctx) {
	// choice:
	//       discrete_range
	//       | simple_expression
	//       | OTHERS
	// ;

	auto dr = ctx->discrete_range();
	if (dr) {
		return visitDiscrete_range(dr);
	}
	auto se = ctx->simple_expression();
	if (se) {
		return VhdlExprParser::visitSimple_expression(se);
	}
#ifndef NDEBUG
	auto o = ctx->KW_OTHERS();
	assert(o);
#endif
	return update_code_position(HdlValueSymbol::others(), ctx);
}
vector<unique_ptr<iHdlExprItem>> VhdlExprParser::visitChoices(
		vhdlParser::ChoicesContext *ctx) {
	// choices: choice ( choice )*;
	vector<unique_ptr<iHdlExprItem>> res;
	auto _choice = ctx->choice();
	for (auto c : _choice) {
		res.push_back(visitChoice(c));
	}
	return res;
}

unique_ptr<iHdlExprItem> VhdlExprParser::visitProcedure_call_statement(
		vhdlParser::Procedure_call_statementContext *ctx) {
	// procedure_call_statement: procedure_call SEMI
	//   ;
	return visitProcedure_call(ctx->procedure_call());
}
unique_ptr<iHdlExprItem> VhdlExprParser::visitProcedure_call(
		vhdlParser::Procedure_callContext *ctx) {
	// procedure_call: name;
	auto fnCall = VhdlReferenceParser::visitName(ctx->name());
	auto c = dynamic_cast<HdlOp*>(fnCall.get());

	if (c == nullptr || c->op != HdlOpType::CALL) {
		vector<unique_ptr<iHdlExprItem>> args;
		return HdlOp::call(ctx, move(fnCall), args);
	}
	return fnCall;
}

unique_ptr<iHdlExprItem> VhdlExprParser::visitType_mark(
		vhdlParser::Type_markContext *ctx) {
	// type_mark: name;
	auto n = ctx->name();
	return VhdlReferenceParser::visitName(n);
}

}
}
