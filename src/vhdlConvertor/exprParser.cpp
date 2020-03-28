#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/vhdlConvertor/operatorTypeParser.h>
#include <hdlConvertor/hdlObjects/hdlCall.h>
#include <hdlConvertor/vhdlConvertor/directionParser.h>
#include <hdlConvertor/vhdlConvertor/exprParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>
#include <hdlConvertor/createObject.h>
#include <assert.h>

namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlObjects;

std::unique_ptr<std::vector<std::unique_ptr<iHdlExpr>>> VhdlExprParser::visitAssociation_list(
		vhdlParser::Association_listContext *ctx) {
	// association_list:
	//       association_element ( COMMA association_element )*
	// ;
	auto ae = std::make_unique<std::vector<std::unique_ptr<iHdlExpr>>>();
	for (auto e : ctx->association_element()) {
		ae->push_back(visitAssociation_element(e));
	}
	return ae;
}

std::unique_ptr<iHdlExpr> VhdlExprParser::visitAssociation_element(
		vhdlParser::Association_elementContext *ctx) {
	// association_element:
	//       ( formal_part ARROW )? actual_part
	// ;
	auto ap = visitActual_part(ctx->actual_part());
	auto fp = visitFormal_part(ctx->formal_part());
	if (fp) {
            return create_object<iHdlExpr>(ctx, move(fp), ARROW, move(ap));
	}
	return ap;
}

std::unique_ptr<iHdlExpr> VhdlExprParser::visitFormal_part(
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
		std::vector<std::unique_ptr<iHdlExpr>> args;
		args.push_back(VhdlReferenceParser::visitName(names[1]));
		return iHdlExpr::call(ctx, move(id), args);
	} else {
		return id;
	}
}

std::unique_ptr<HdlRange> VhdlExprParser::visitExplicit_range(
		vhdlParser::Explicit_rangeContext *ctx) {
	// explicit_range
	// : simple_expression direction simple_expression
	// ;
	HdlRangeDirection dir;
	if (ctx->direction()->KW_DOWNTO()) {
		dir = DOWNTO;
	} else {
		dir = TO;
	}
	auto rng = create_object<HdlRange>(ctx);
	rng->range = create_object<HdlSimpleRange>(ctx,
			visitSimple_expression(ctx->simple_expression(0)), dir,
			visitSimple_expression(ctx->simple_expression(1)));
	return rng;
}

std::unique_ptr<HdlRange> VhdlExprParser::visitRange(
		vhdlParser::RangeContext *ctx) {
	//range:
	//      attribute_name
	//      | simple_expression direction simple_expression
	//;
	auto an = ctx->attribute_name();
	if (an) {
		//TODO::return VhdlReferenceParser::visitAttribute_name(an);
		//
		// fill this in with appropriate HdlRange logic
		NotImplementedLogger::print(
				"ExprParser.visitRange - attribute name",
				ctx);
		return nullptr;
	}
	auto se = ctx->simple_expression();
	if (2 == se.size()) {
		auto a = visitSimple_expression(se[0]);
		auto o = visitDirection(ctx->direction());
		auto b = visitSimple_expression(se[1]);
		auto rng = create_object<HdlRange>(ctx);
		rng->range = create_object<HdlSimpleRange>(ctx, std::move(a), o, std::move(b));
		return rng;
	}

	NotImplementedLogger::print("ExprParser.visitRange - unrecognized range", ctx);
	return nullptr;
}

std::unique_ptr<iHdlExpr> VhdlExprParser::visitActual_part(
		vhdlParser::Actual_partContext *ctx) {
	// actual_part:
	//       name LPAREN actual_designator RPAREN
	//       | actual_designator
	// ;

	auto name = ctx->name();
	auto _ad = ctx->actual_designator();
	std::unique_ptr<iHdlExpr> ad = visitActual_designator(_ad);
	if (name) {
		std::vector<std::unique_ptr<iHdlExpr>> ops;
		ops.push_back(move(ad));
		return iHdlExpr::call(ctx, VhdlReferenceParser::visitName(name), ops);
	}
	return ad;
}
std::unique_ptr<iHdlExpr> VhdlExprParser::visitActual_designator(
		vhdlParser::Actual_designatorContext *ctx) {
	//actual_designator:
	//      ( INERTIAL )? expression
	//      | subtype_indication
	//      | OPEN
	//;
	if (ctx->KW_OPEN())
		return iHdlExpr::OPEN();
	auto sti = ctx->subtype_indication();
	if (sti) {
		//TODO::return visitSubtype_indication(sti);
		//
		// rhinton doesn't know when a subtype indication might be
		// appropriate in an actual part
		NotImplementedLogger::print(
				"ExprParser.visitActual_designator - subtype_indication",
				sti);
		return nullptr;
	}
	return visitExpression(ctx->expression());
}
std::unique_ptr<HdlSubtype> VhdlExprParser::visitSubtype_indication(
		vhdlParser::Subtype_indicationContext *ctx) {
	// subtype_indication:
	//       ( resolution_indication )? type_mark ( constraint )?
	// ;

	auto _ri = ctx->resolution_indication();
	std::unique_ptr<iHdlExpr> ri = nullptr;
	if (_ri) {
		ri = visitResolution_indication(_ri);
		NotImplementedLogger::print(
				"ExprParser.visitResolution_indication - element_resolution",
				_ri);
	}

	auto st = create_object<HdlSubtype>(ctx);
	st->parent_type = visitType_mark(ctx->type_mark());
	auto c = ctx->constraint();
	if (c) 
		st->constraint = visitConstraint(c);
	return st;
}
std::unique_ptr<iHdlExpr> VhdlExprParser::visitResolution_indication(
		vhdlParser::Resolution_indicationContext *ctx) {
	// resolution_indication:
	//       name | LPAREN element_resolution RPAREN
	// ;
	// element_resolution: array_element_resolution | record_resolution;
	NotImplementedLogger::print(
			"ExprParser.visitResolution_indication - element_resolution", ctx);
	return nullptr;

	//TODO:: seems silly to return the just the name and pretend that the
	// resolution indication is implemented.
        //
	//TODO::auto n = ctx->name();
	//TODO::if (n) {
	//TODO::	return VhdlReferenceParser::visitName(n);
	//TODO::}

}

std::unique_ptr<HdlConstraint> VhdlExprParser::visitConstraint(
		vhdlParser::ConstraintContext *ctx) {
	// constraint:
	//       range_constraint
	//       | array_constraint
	//       | record_constraint
	// ;

	auto rng = ctx->range_constraint();
	if (rng) {
		// range_constraint
		// : RANGE range
		// ;
		auto rcons = std::make_unique<HdlRangeConstraint>();
		rcons->range = visitRange(rng->range());
		return rcons;
	} 
	auto ary = ctx->array_constraint();
	if (ary) 
		return visitArray_constraint(ary);
	auto rec = ctx->record_constraint();
	if (rec) {
		//TODO:: should be fairly easy with constraint infrastructure
		NotImplementedLogger::print(
				"ExprParser.visitConstraint - record_constraint", rec);
		return nullptr;
	}

	NotImplementedLogger::print(
			"ExprParser.visitConstraint - unrecognized constraint", ctx);
	return nullptr;
}
std::unique_ptr<HdlArrayConstraint> VhdlExprParser::visitArray_constraint(
		vhdlParser::Array_constraintContext *ctx) {
	// array_constraint:
	//       index_constraint ( array_element_constraint )?
	//       | LPAREN OPEN RPAREN ( array_element_constraint )?
	// ;
	std::unique_ptr<HdlArrayConstraint> cons;
	auto ic = ctx->index_constraint();
	if (ic) {
		cons = visitIndex_constraint(ic);
	} else {
		cons = create_object<HdlArrayConstraint>(ctx);
	}
	// When OPEN, we could create a NoConstraint in the HdlArrayConstraint
	// 'indexes' member.  But that seems unnecessary.

	auto aec = ctx->array_element_constraint();
	if (aec) {
		cons->element = visitArray_element_constraint(aec);
	}
        return cons;
}
std::unique_ptr<HdlArrayConstraint> VhdlExprParser::visitIndex_constraint(
		vhdlParser::Index_constraintContext *ctx) {
	// index_constraint
	// : LPAREN discrete_range ( COMMA discrete_range )* RPAREN
	// ;
	auto acons = std::make_unique<HdlArrayConstraint>();
	for (auto dr_ctx : ctx->discrete_range()) {
		acons->indexes.push_back(visitDiscrete_range(dr_ctx));
	}
	return acons;
}
std::unique_ptr<HdlConstraint> VhdlExprParser::visitArray_element_constraint(
		vhdlParser::Array_element_constraintContext *ctx) {
	// array_element_constraint: element_constraint;
	// element_constraint:
	//       array_constraint
	//       | record_constraint
	// ;
	NotImplementedLogger::print(
			"ExprParser.visitArray_element_constraint",
			ctx);
	return nullptr;
	//TODO:: this should be easy with constraint infrastructure
}
std::unique_ptr<HdlRange> VhdlExprParser::visitDiscrete_range(
		vhdlParser::Discrete_rangeContext *ctx) {
	// discrete_range
	// : range
	// | subtype_indication
	// ;
	auto r = ctx->range();
	if (r)
		return visitRange(r);
	auto rcons = std::make_unique<HdlRange>();
	rcons->subtype = visitSubtype_indication(ctx->subtype_indication());
	return rcons;
}

HdlOperatorType VhdlExprParser::visitSign(
		vhdlParser::SignContext *ctx) {
	// sign: PLUS | MINUS;
	if (ctx->MINUS()) {
		return HdlOperatorType::SUB;
	} else {
		assert(ctx->PLUS());
		return HdlOperatorType::ADD;
	}
}
std::unique_ptr<iHdlExpr> VhdlExprParser::visitSimple_expression(
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
		return create_object<iHdlExpr>(ctx, move(p0), HdlOperatorType::POW, move(p1));
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
		return create_object<iHdlExpr>(ctx, op, move(se0));
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
		return create_object<iHdlExpr>(ctx, std::move(se0), op, std::move(se1));
	}
}
std::unique_ptr<iHdlExpr> VhdlExprParser::visitExpression(
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
	return create_object<iHdlExpr>(ctx, std::move(op0), op, std::move(op1));
}

std::unique_ptr<iHdlExpr> VhdlExprParser::visitPrimary(
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
		return iHdlExpr::null();

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

std::unique_ptr<iHdlExpr> VhdlExprParser::visitQualified_expression(
		vhdlParser::Qualified_expressionContext *ctx) {
	// qualified_expression:
	//       type_mark APOSTROPHE aggregate
	// ;
	auto _tm = ctx->type_mark();
	auto tm = visitType_mark(_tm);
	auto a = ctx->aggregate();
	auto e = visitAggregate(a);
	return create_object<iHdlExpr>(ctx, std::move(tm), HdlOperatorType::APOSTROPHE, std::move(e));
}
std::unique_ptr<iHdlExpr> VhdlExprParser::visitAllocator(
		vhdlParser::AllocatorContext *ctx) {
	// allocator
	// : NEW ( qualified_expression | subtype_indication )
	// ;
	auto n = iHdlExpr::ID("new");
	std::unique_ptr<iHdlExpr> e;
	auto qe = ctx->qualified_expression();
	if (qe) {
		e = visitQualified_expression(qe);
	} else {
		//TODO::auto si = ctx->subtype_indication();
		//TODO::e = make_unique<iHdlExpr>();
		//TODO::e->asdf = visitSubtype_indication(si);
		//
		//rhinton: need to figure out how to make this subtype
		// indication work.  VHDL is strange.
		NotImplementedLogger::print(
				"ExprParser.Allocator - subtype indication", 
				ctx->subtype_indication());
	}
	return create_object<iHdlExpr>(ctx, std::move(n), HdlOperatorType::CALL, std::move(e));

}
std::unique_ptr<iHdlExpr> VhdlExprParser::visitAggregate(
		vhdlParser::AggregateContext *ctx) {
	// aggregate:
	//    LPAREN element_association ( COMMA element_association )* RPAREN
	// ;
	std::vector<std::unique_ptr<iHdlExpr>> elements;
	for (auto elm : ctx->element_association()) {
		auto e = visitElement_association(elm);
		elements.push_back(move(e));
	}
	std::unique_ptr<iHdlExpr> arr = iHdlExpr::ARRAY(ctx, elements);

	return arr;
}

std::unique_ptr<iHdlExpr> VhdlExprParser::visitElement_association(
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
		return create_object<iHdlExpr>(ctx, std::move(ch[0]),
				HdlOperatorType::MAP_ASSOCIATION, std::move(e));
	}
	return e;
}

std::unique_ptr<iHdlExpr> VhdlExprParser::visitTarget(
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

std::unique_ptr<iHdlExpr> VhdlExprParser::visitWaveform(
		vhdlParser::WaveformContext *ctx) {
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

	auto top = visitWaveform_element(*weIt);
	++weIt;
	while (weIt != we.end()) {
		top = create_object<iHdlExpr>(ctx, move(top), DOT,
				visitWaveform_element(*weIt));
		++weIt;
	}

	return top;
}

std::unique_ptr<iHdlExpr> VhdlExprParser::visitCondition(
		vhdlParser::ConditionContext *ctx) {
	// condition
	// : expression
	// ;
	return VhdlExprParser::visitExpression(ctx->expression());
}

std::unique_ptr<iHdlExpr> VhdlExprParser::visitConditional_waveforms(
		vhdlParser::Conditional_waveformsContext *ctx) {
	// conditional_waveforms:
	//       waveform WHEN condition
	//       ( ELSE waveform WHEN condition )*
	//       ( ELSE waveform )?
	// ;
	auto waveforms = ctx->waveform();
	auto conditions = ctx->condition();
	auto c = conditions.rbegin();
	std::unique_ptr<iHdlExpr> res = nullptr;
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
		res = iHdlExpr::ternary(*w, move(c_expr), move(w_expr), move(res));
		c++;
	}
	return res;
}

std::unique_ptr<iHdlExpr> VhdlExprParser::visitWaveform_element(
		vhdlParser::Waveform_elementContext *ctx) {
	// waveform_element :
	// expression ( AFTER expression )?
	// ;
	auto ex = ctx->expression();
	auto e = ex.begin();
	std::unique_ptr<iHdlExpr> top = visitExpression(*e);
	++e;
	if (e != ex.end()) {
		NotImplementedLogger::print(
				"ExprParser.visitWaveform_element - AFTER expression", ctx);
	}
	return top;
}

std::unique_ptr<iHdlExpr> VhdlExprParser::visitChoice(
		vhdlParser::ChoiceContext *ctx) {
	// choice:
	//       discrete_range
	//       | simple_expression
	//       | OTHERS
	// ;

	auto dr = ctx->discrete_range();
	if (dr) {
		//TODO::return visitDiscrete_range(dr);
		//
		//rhinton: need to figure out how to shoehorn a range into an
		// expression
		NotImplementedLogger::print(
				"ExprParser.visitChoice - discrete range choice", dr);
		return nullptr;
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
std::vector<std::unique_ptr<iHdlExpr>> VhdlExprParser::visitChoices(
		vhdlParser::ChoicesContext *ctx) {
	// choices: choice ( choice )*;
	std::vector<std::unique_ptr<iHdlExpr>> res;
	auto _choice = ctx->choice();
	for (auto c : _choice) {
		res.push_back(visitChoice(c));
	}
	return res;
}

std::unique_ptr<iHdlExpr> VhdlExprParser::visitProcedure_call_statement(
		vhdlParser::Procedure_call_statementContext *ctx) {
	// procedure_call_statement: procedure_call SEMI
	//   ;
	return visitProcedure_call(ctx->procedure_call());
}
std::unique_ptr<iHdlExpr> VhdlExprParser::visitProcedure_call(
		vhdlParser::Procedure_callContext *ctx) {
	// procedure_call: name;
	auto fnCall = VhdlReferenceParser::visitName(ctx->name());
	auto c = dynamic_cast<HdlCall*>(fnCall->data);

	if (c == nullptr || c->op != HdlOperatorType::CALL) {
		std::vector<std::unique_ptr<iHdlExpr>> args;
		return iHdlExpr::call(ctx, move(fnCall), args);
	}
	return fnCall;
}

std::unique_ptr<iHdlExpr> VhdlExprParser::visitType_mark(
		vhdlParser::Type_markContext *ctx) {
	// type_mark: name;
	auto n = ctx->name();
	return VhdlReferenceParser::visitName(n);
}

}
}
