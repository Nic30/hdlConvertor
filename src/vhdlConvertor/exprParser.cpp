#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/vhdlConvertor/operatorTypeParser.h>
#include <hdlConvertor/hdlObjects/hdlCall.h>
#include <hdlConvertor/vhdlConvertor/directionParser.h>
#include <hdlConvertor/vhdlConvertor/exprParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>

namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlObjects;

std::vector<iHdlExpr*>* VhdlExprParser::visitAssociation_list(
		vhdlParser::Association_listContext *ctx) {
	// association_list:
	//       association_element ( COMMA association_element )*
	// ;
	std::vector<iHdlExpr*> *ae = new std::vector<iHdlExpr*>();
	for (auto e : ctx->association_element()) {
		ae->push_back(visitAssociation_element(e));
	}
	return ae;
}

iHdlExpr* VhdlExprParser::visitAssociation_element(
		vhdlParser::Association_elementContext *ctx) {
	// association_element:
	//       ( formal_part ARROW )? actual_part
	// ;

	auto _ap = ctx->actual_part();
	iHdlExpr *ap = visitActual_part(_ap);
	auto fp = ctx->formal_part();
	if (fp) {
		auto vfp = new iHdlExpr(visitFormal_part(fp), ARROW, ap);
		vfp->position.update_from_elem(ctx);
		return vfp;
	}
	ap->position.update_from_elem(ctx);
	return ap;
}
iHdlExpr* VhdlExprParser::visitFormal_part(vhdlParser::Formal_partContext *ctx) {
	// formal_part:
	//       formal_designator
	//       | name LPAREN formal_designator RPAREN
	//       | type_mark LPAREN formal_designator RPAREN
	// ;
	// formal_part:
	//       name (LPAREN name RPAREN)?
	// ;
	auto names = ctx->name();
	iHdlExpr *id = VhdlReferenceParser::visitName(names[0]);
	if (names.size() > 1) {
		std::vector<iHdlExpr*> args = { VhdlReferenceParser::visitName(names[1]) };
		return iHdlExpr::call(id, args);
	} else {
		return id;
	}
}

iHdlExpr* VhdlExprParser::visitExplicit_range(
		vhdlParser::Explicit_rangeContext *ctx) {
	// explicit_range
	// : simple_expression direction simple_expression
	// ;
	HdlOperatorType op;
	if (ctx->direction()->KW_DOWNTO()) {
		op = DOWNTO;
	} else {
		op = TO;
	}
	return new iHdlExpr(visitSimple_expression(ctx->simple_expression(0)), op,
			visitSimple_expression(ctx->simple_expression(1)));
}

iHdlExpr* VhdlExprParser::visitRange(vhdlParser::RangeContext *ctx) {
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
	return new iHdlExpr(a, o, b);
}

iHdlExpr* VhdlExprParser::visitActual_part(vhdlParser::Actual_partContext *ctx) {
	// actual_part:
	//       name LPAREN actual_designator RPAREN
	//       | actual_designator
	// ;

	auto name = ctx->name();
	auto _ad = ctx->actual_designator();
	iHdlExpr *ad = visitActual_designator(_ad);
	if (name) {
		std::vector<iHdlExpr*> ops = { ad, };
		return iHdlExpr::call(VhdlReferenceParser::visitName(name), ops);
	}
	return ad;
}
iHdlExpr* VhdlExprParser::visitActual_designator(
		vhdlParser::Actual_designatorContext *ctx) {
	//actual_designator:
	//      ( INERTIAL )? expression
	//      | subtype_indication
	//      | OPEN
	//;
	if (ctx->KW_OPEN())
		return iHdlExpr::OPEN();
	auto sti = ctx->subtype_indication();
	if (sti)
		return visitSubtype_indication(sti);
	return visitExpression(ctx->expression());
}
iHdlExpr* VhdlExprParser::visitSubtype_indication(
		vhdlParser::Subtype_indicationContext *ctx) {
	// subtype_indication:
	//       ( resolution_indication )? type_mark ( constraint )?
	// ;

	auto _ri = ctx->resolution_indication();
	iHdlExpr *ri = nullptr;
	if (_ri) {
		ri = visitResolution_indication(_ri);
		NotImplementedLogger::print(
				"ExprParser.visitResolution_indication - element_resolution",
				_ri);
		delete ri;
	}

	// type_mark: name;
	iHdlExpr *e = visitType_mark(ctx->type_mark());
	auto c = ctx->constraint();
	if (c) {
		e = visitConstraint(e, c);
	}
	return e;
}
iHdlExpr* VhdlExprParser::visitResolution_indication(
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
	return nullptr;
}

iHdlExpr* VhdlExprParser::visitConstraint(iHdlExpr *selectedName,
		vhdlParser::ConstraintContext *ctx) {
	// constraint:
	//       range_constraint
	//       | array_constraint
	//       | record_constraint
	// ;

	auto r = ctx->range_constraint();
	HdlOperatorType op;
	iHdlExpr *op1 = NULL;
	if (r) {
		// range_constraint
		// : RANGE range
		// ;
		op = RANGE;
		op1 = visitRange(r->range());
	} else {
		auto i = ctx->array_constraint();
		if (i) {
			op = INDEX;
			op1 = visitArray_constraint(i);
		} else {
#ifndef NDEBUG
			auto r = ctx->record_constraint();
			assert(r);
#endif
			NotImplementedLogger::print(
					"ExprParser.visitConstraint - record_constraint", r);
			op = DOT;
			op1 = nullptr;
		}
	}

	return new iHdlExpr(selectedName, op, op1);

}
iHdlExpr* VhdlExprParser::visitArray_constraint(
		vhdlParser::Array_constraintContext *ctx) {
	// array_constraint:
	//       index_constraint ( array_element_constraint )?
	//       | LPAREN OPEN RPAREN ( array_element_constraint )?
	// ;
	auto ic = ctx->index_constraint();
	auto aec = ctx->array_element_constraint();
	if (aec) {
		NotImplementedLogger::print(
				"ExprParser.visitArray_constraint - array_element_constraint",
				aec);
	}
	if (ic) {
		auto e = visitIndex_constraint(ic);
		return e;
	}
	return nullptr;

}
iHdlExpr* VhdlExprParser::visitIndex_constraint(
		vhdlParser::Index_constraintContext *ctx) {
	// index_constraint
	// : LPAREN discrete_range ( COMMA discrete_range )* RPAREN
	// ;
	if (ctx->discrete_range().size() > 1) {
		NotImplementedLogger::print(
				"ExprParser.visitIndex_constraint multiple discrete_range",
				ctx);
	}
	return visitDiscrete_range(ctx->discrete_range(0));
}
iHdlExpr* VhdlExprParser::visitDiscrete_range(
		vhdlParser::Discrete_rangeContext *ctx) {
	// discrete_range
	// : range
	// | subtype_indication
	// ;
	auto r = ctx->range();
	if (r)
		return visitRange(r);
	return visitSubtype_indication(ctx->subtype_indication());
}

hdlObjects::HdlOperatorType VhdlExprParser::visitSign(
		vhdlParser::SignContext *ctx) {
	// sign: PLUS | MINUS;
	if (ctx->MINUS()) {
		return HdlOperatorType::SUB;
	} else {
		assert(ctx->PLUS());
		return HdlOperatorType::ADD;
	}
}
iHdlExpr* VhdlExprParser::visitSimple_expression(
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
		auto p1 = visitPrimary(_primary[1]);
		assert(ctx->DOUBLESTAR());
		return new iHdlExpr(p0, HdlOperatorType::POW, p1);
	}
	auto se = ctx->simple_expression();
	HdlOperatorType op;
	if (se.size() == 1) {
		if (ctx->KW_ABS()) {
			op = HdlOperatorType::ABS;
		} else if (ctx->KW_NOT()) {
			op = HdlOperatorType::NOT;
		} else {
			auto lo = ctx->logical_operator();
			if (lo) {
				op = HdlOperatorType_from(lo);
			} else {
				auto s = ctx->sign();
				assert(s);
				op = HdlOperatorType_from(s);
			}
		}
		auto se0 = visitSimple_expression(se[0]);
		return new iHdlExpr(op, se0);
	} else {
		assert(se.size() == 2);
		auto mo = ctx->multiplying_operator();
		if (mo) {
			op = HdlOperatorType_from(mo);
		} else {
			auto ao = ctx->adding_operator();
			assert(ao);
			op = HdlOperatorType_from(ao);
		}

		auto se0 = visitSimple_expression(se[0]);
		auto se1 = visitSimple_expression(se[1]);
		return new iHdlExpr(se0, op, se1);
	}
}
iHdlExpr* VhdlExprParser::visitExpression(vhdlParser::ExpressionContext *ctx) {
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
	HdlOperatorType op;
	if (so) {
		op = HdlOperatorType_from(so);
	} else {
		auto ro = ctx->relational_operator();
		if (ro) {
			op = HdlOperatorType_from(ro);
		} else {
			auto lo = ctx->logical_operator();
			assert(lo);
			op = HdlOperatorType_from(lo);
		}
	}
	return new iHdlExpr(op0, op, op1);

}

iHdlExpr* VhdlExprParser::visitPrimary(vhdlParser::PrimaryContext *ctx) {
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
		return iHdlExpr::null();

	auto bsl = ctx->BIT_STRING_LITERAL();
	if (bsl) {
		return VhdlLiteralParser::visitBIT_STRING_LITERAL(bsl->getText());
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

iHdlExpr* VhdlExprParser::visitQualified_expression(
		vhdlParser::Qualified_expressionContext *ctx) {
	// qualified_expression:
	//       type_mark APOSTROPHE aggregate
	// ;
	auto _tm = ctx->type_mark();
	iHdlExpr *tm = visitType_mark(_tm);
	auto a = ctx->aggregate();
	auto e = visitAggregate(a);
	return new iHdlExpr(tm, HdlOperatorType::APOSTROPHE, e);
}
iHdlExpr* VhdlExprParser::visitAllocator(vhdlParser::AllocatorContext *ctx) {
	// allocator
	// : NEW ( qualified_expression | subtype_indication )
	// ;
	auto n = iHdlExpr::ID("new");
	iHdlExpr *e;
	auto qe = ctx->qualified_expression();
	if (qe)
		e = visitQualified_expression(qe);
	else {
		auto si = ctx->subtype_indication();
		e = visitSubtype_indication(si);
	}
	return new iHdlExpr(n, HdlOperatorType::CALL, e);

}
iHdlExpr* VhdlExprParser::visitAggregate(vhdlParser::AggregateContext *ctx) {
	// aggregate:
	//    LPAREN element_association ( COMMA element_association )* RPAREN
	// ;
	std::vector<iHdlExpr*> elements;
	for (auto elm : ctx->element_association()) {
		iHdlExpr *e = visitElement_association(elm);
		elements.push_back(e);
	}
	iHdlExpr *arr = iHdlExpr::ARRAY(elements);

	return arr;
}

iHdlExpr* VhdlExprParser::visitElement_association(
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
		return new iHdlExpr(ch[0], HdlOperatorType::MAP_ASSOCIATION, e);
	}
	return e;
}

iHdlExpr* VhdlExprParser::visitTarget(vhdlParser::TargetContext *ctx) {
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

iHdlExpr* VhdlExprParser::visitWaveform(vhdlParser::WaveformContext *ctx) {
	// waveform :
	// waveform_element ( COMMA waveform_element )*
	// | UNAFFECTED
	// ;
	if (ctx->KW_UNAFFECTED()) {
		NotImplementedLogger::print("ExprParser.visitWaveform - UNAFFECTED",
				ctx);
		return nullptr;
	}
	auto we = ctx->waveform_element();
	auto weIt = we.begin();

	iHdlExpr *top = visitWaveform_element(*weIt);
	++weIt;
	while (weIt != we.end()) {
		top = new iHdlExpr(top, DOT, visitWaveform_element(*weIt));
		++weIt;
	}

	return top;
}
iHdlExpr* VhdlExprParser::visitCondition(vhdlParser::ConditionContext *ctx) {
	// condition
	// : expression
	// ;
	return VhdlExprParser::visitExpression(ctx->expression());
}
iHdlExpr* VhdlExprParser::visitConditional_waveforms(
		vhdlParser::Conditional_waveformsContext *ctx) {
	// conditional_waveforms:
	//       waveform WHEN condition
	//       ( ELSE waveform WHEN condition )*
	//       ( ELSE waveform )?
	// ;
	auto waveforms = ctx->waveform();
	auto conditions = ctx->condition();
	auto c = conditions.rbegin();
	iHdlExpr *res = nullptr;
	for (auto w = waveforms.rbegin(); w != waveforms.rend(); ++w) {
		auto w_expr = visitWaveform(*w);
		if (res == nullptr) {
			// the first iteration
			bool has_default_else = waveforms.size() > conditions.size();
			if (has_default_else) {
				// this waveform is a default else
				res = w_expr;
				continue;
			}
		}
		auto c_expr = visitCondition(*c);
		res = iHdlExpr::ternary(c_expr, w_expr, res);
		c++;
	}
	return res;
}

iHdlExpr* VhdlExprParser::visitWaveform_element(
		vhdlParser::Waveform_elementContext *ctx) {
	// waveform_element :
	// expression ( AFTER expression )?
	// ;
	auto ex = ctx->expression();
	auto e = ex.begin();
	iHdlExpr *top = visitExpression(*e);
	++e;
	if (e != ex.end()) {
		NotImplementedLogger::print(
				"ExprParser.visitWaveform_element - AFTER expression", ctx);
	}
	return top;
}

iHdlExpr* VhdlExprParser::visitChoice(vhdlParser::ChoiceContext *ctx) {
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
	return iHdlExpr::others();
}
std::vector<iHdlExpr*> VhdlExprParser::visitChoices(
		vhdlParser::ChoicesContext *ctx) {
	// choices: choice ( choice )*;
	std::vector<iHdlExpr*> res;
	auto _choice = ctx->choice();
	for (auto c : _choice) {
		res.push_back(visitChoice(c));
	}
	return res;
}

iHdlExpr* VhdlExprParser::visitProcedure_call_statement(
		vhdlParser::Procedure_call_statementContext *ctx) {
	// procedure_call_statement: procedure_call SEMI
	//   ;
	return visitProcedure_call(ctx->procedure_call());
}
iHdlExpr* VhdlExprParser::visitProcedure_call(
		vhdlParser::Procedure_callContext *ctx) {
	// procedure_call: name;
	iHdlExpr *fnCall = VhdlReferenceParser::visitName(ctx->name());
	auto c = dynamic_cast<HdlCall*>(fnCall->data);

	if (c == nullptr || c->op != HdlOperatorType::CALL) {
		std::vector<iHdlExpr*> args;
		return iHdlExpr::call(fnCall, args);
	}
	return fnCall;
}

iHdlExpr* VhdlExprParser::visitType_mark(vhdlParser::Type_markContext *ctx) {
	// type_mark: name;
	auto n = ctx->name();
	return VhdlReferenceParser::visitName(n);
}

}
}
