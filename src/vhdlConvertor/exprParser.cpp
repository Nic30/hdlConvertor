#include <hdlConvertor/vhdlConvertor/exprParser.h>

#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>
#include <hdlConvertor/vhdlConvertor/operatorTypeParser.h>
#include <hdlConvertor/vhdlConvertor/directionParser.h>
#include <hdlConvertor/hdlObjects/hdlCall.h>

namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlObjects;

std::vector<iHdlExpr*> * ExprParser::visitActual_parameter_part(
		vhdlParser::Actual_parameter_partContext* ctx) {
	std::vector<iHdlExpr*> * l = new std::vector<iHdlExpr*>();
	if (!ctx)
		return l;
	// actual_parameter_part
	// : association_list
	// ;

	return visitAssociation_list(ctx->association_list());
}

std::vector<iHdlExpr*> * ExprParser::visitAssociation_list(
		vhdlParser::Association_listContext *ctx) {
	// association_list:
	//       association_element ( COMMA association_element )*
	// ;
	std::vector<iHdlExpr*> * ae = new std::vector<iHdlExpr*>();
	for (auto e : ctx->association_element()) {
		ae->push_back(visitAssociation_element(e));
	}
	return ae;
}

iHdlExpr* ExprParser::visitAssociation_element(
		vhdlParser::Association_elementContext* ctx) {
	// association_element:
	//       ( formal_part ARROW )? actual_part
	// ;

	auto _ap = ctx->actual_part();
	iHdlExpr * ap = visitActual_part(_ap);
	auto fp = ctx->formal_part();
	if (fp) {
		auto vfp = new iHdlExpr(visitFormal_part(fp), ARROW, ap);
		vfp->position.update_from_elem(ctx);
		return vfp;
	}
	ap->position.update_from_elem(ctx);
	return ap;
}
iHdlExpr* ExprParser::visitFormal_part(vhdlParser::Formal_partContext* ctx) {
	// formal_part:
	//       formal_designator
	//       | name LPAREN formal_designator RPAREN
	//       | type_mark LPAREN formal_designator RPAREN
	// ;
	// formal_designator:
	//       name
	// ;
	iHdlExpr * id = ReferenceParser::visitName(ctx->formal_designator()->name());
	auto n = ctx->name();
	if (n) {
		return new iHdlExpr(ReferenceParser::visitName(n), INDEX, id);
	}
	auto tm = ctx->type_mark();
	if (tm) {
		// type_mark: name;
		return new iHdlExpr(visitType_mark(tm), INDEX, id);
	}

	return id;
}

iHdlExpr* ExprParser::visitExplicit_range(vhdlParser::Explicit_rangeContext* ctx) {
	// explicit_range
	// : simple_expression direction simple_expression
	// ;
	HdlOperatorType op;
	if (ctx->direction()->DOWNTO()) {
		op = DOWNTO;
	} else {
		op = TO;
	}
	return new iHdlExpr(visitSimple_expression(ctx->simple_expression(0)), op,
			visitSimple_expression(ctx->simple_expression(1)));
}
iHdlExpr* ExprParser::visitRange(vhdlParser::RangeContext* ctx) {
	// range
	// : explicit_range
	// | name
	// ;
	//range:
	//      attribute_name
	//      | simple_expression direction simple_expression
	//;
	auto an = ctx->attribute_name();
	if (an)
		return ReferenceParser::visitAttribute_name(an);
	auto se = ctx->simple_expression();
	auto a = visitSimple_expression(se[0]);
	auto o = visitDirection(ctx->direction());
	auto b = visitSimple_expression(se[1]);
	return new iHdlExpr(a, o, b);
}
iHdlExpr* ExprParser::visitPrefix(vhdlParser::PrefixContext * ctx) {
	// prefix:
	//       name
	//       | function_call
	// ;
	auto n = ctx->name();
	if (n)
		return ReferenceParser::visitName(n);

	return visitFunction_call(ctx->function_call());
}
iHdlExpr* ExprParser::visitFunction_call(vhdlParser::Function_callContext *ctx) {
	// function_call:
	//       name ( LPAREN actual_parameter_part RPAREN )?
	// ;
	auto n = ReferenceParser::visitName(ctx->name());
	std::vector<iHdlExpr*> * args = nullptr;
	auto app = ctx->actual_parameter_part();
	if (app) {
		args = visitActual_parameter_part(app);
	} else {
		args = new std::vector<iHdlExpr*>();
	}
	auto call = iHdlExpr::call(n, *args);
	delete args;
	return call;
}

iHdlExpr* ExprParser::visitActual_part(vhdlParser::Actual_partContext* ctx) {
	// actual_part:
	//       name LPAREN actual_designator RPAREN
	//       | actual_designator
	// ;

	auto name = ctx->name();
	auto _ad = ctx->actual_designator();
	iHdlExpr * ad = visitActual_designator(_ad);
	if (name) {
		std::vector<iHdlExpr*> ops = { ad, };
		return iHdlExpr::call(ReferenceParser::visitName(name), ops);
	}
	return ad;
}
iHdlExpr* ExprParser::visitActual_designator(
		vhdlParser::Actual_designatorContext* ctx) {
	//actual_designator:
	//      ( INERTIAL )? expression
	//      | subtype_indication
	//      | OPEN
	//;
	if (ctx->OPEN())
		return iHdlExpr::OPEN();
	auto sti = ctx->subtype_indication();
	if (sti)
		return visitSubtype_indication(sti);
	return visitExpression(ctx->expression());
}
iHdlExpr* ExprParser::visitSubtype_indication(
		vhdlParser::Subtype_indicationContext* ctx) {
	// subtype_indication:
	//       ( resolution_indication )? type_mark ( constraint )?
	// ;

	auto _ri = ctx->resolution_indication();
	iHdlExpr * ri = nullptr;
	if (_ri) {
		ri = visitResolution_indication(_ri);
		NotImplementedLogger::print(
				"ExprParser.visitResolution_indication - element_resolution", _ri);
		delete ri;
	}

	// type_mark: name;
	iHdlExpr * e = visitType_mark(ctx->type_mark());
	auto c = ctx->constraint();
	if (c) {
		e = visitConstraint(e, c);
	}
	return e;
}
iHdlExpr * ExprParser::visitResolution_indication(
		vhdlParser::Resolution_indicationContext * ctx) {
	// resolution_indication:
	//       name | LPAREN element_resolution RPAREN
	// ;
	// element_resolution: array_element_resolution | record_resolution;
	auto n = ctx->name();
	if (n) {
		return ReferenceParser::visitName(n);
	}

	NotImplementedLogger::print(
			"ExprParser.visitResolution_indication - element_resolution", ctx);
	return nullptr;
}

iHdlExpr* ExprParser::visitConstraint(iHdlExpr* selectedName,
		vhdlParser::ConstraintContext* ctx) {
	// constraint:
	//       range_constraint
	//       | array_constraint
	//       | record_constraint
	// ;

	auto r = ctx->range_constraint();
	HdlOperatorType op;
	iHdlExpr* op1 = NULL;
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
iHdlExpr* ExprParser::visitArray_constraint(
		vhdlParser::Array_constraintContext * ctx) {
	// array_constraint:
	//       index_constraint ( array_element_constraint )?
	//       | LPAREN OPEN RPAREN ( array_element_constraint )?
	// ;
	auto ic = ctx->index_constraint();
	auto aec = ctx->array_element_constraint();
	if (aec) {
		NotImplementedLogger::print(
				"ExprParser.visitArray_constraint - array_element_constraint", aec);
	}
	if (ic) {
		auto e = visitIndex_constraint(ic);
		return e;
	}
	return nullptr;

}
iHdlExpr* ExprParser::visitIndex_constraint(
		vhdlParser::Index_constraintContext* ctx) {
	// index_constraint
	// : LPAREN discrete_range ( COMMA discrete_range )* RPAREN
	// ;
	if (ctx->discrete_range().size() > 1) {
		NotImplementedLogger::print(
				"ExprParser.visitIndex_constraint multiple discrete_range", ctx);
	}
	return visitDiscrete_range(ctx->discrete_range(0));
}
iHdlExpr* ExprParser::visitDiscrete_range(vhdlParser::Discrete_rangeContext* ctx) {
	// discrete_range
	// : range
	// | subtype_indication
	// ;
	auto r = ctx->range();
	if (r)
		return visitRange(r);
	return visitSubtype_indication(ctx->subtype_indication());
}

hdlObjects::HdlOperatorType ExprParser::visitSign(vhdlParser::SignContext * ctx) {
	// sign: PLUS | MINUS;
	if (ctx->MINUS()) {
		return HdlOperatorType::SUB;
	} else {
		assert(ctx->PLUS());
		return HdlOperatorType::ADD;
	}
}
iHdlExpr* ExprParser::visitSimple_expression(
		vhdlParser::Simple_expressionContext* ctx) {
	// simple_expression:
	//       ( sign )? term ( adding_operator term )*
	// ;
	// adding_operator: PLUS | MINUS | AMPERSAND;
	if (!ctx)
		throw std::runtime_error("visitSimple_expression got nullptr");

	auto t = ctx->term();
	auto tIt = t.begin();
	auto opList = ctx->adding_operator();
	auto opListIt = opList.begin();
	iHdlExpr* op0 = visitTerm(*tIt);
	if (t.size() > 1)
		tIt++;

	while (opListIt != opList.end()) {
		auto op = *opListIt;
		++opListIt;
		iHdlExpr* op1 = visitTerm(*tIt);
		++tIt;
		HdlOperatorType opType;
		if (op->PLUS())
			opType = ADD;
		else if (op->MINUS()) {
			opType = SUB;
		} else {
			assert(op->AMPERSAND());
			opType = CONCAT;
		}
		op0 = new iHdlExpr(op0, opType, op1);
	}

	auto s = ctx->sign();
	if (s) {
		op0 = new iHdlExpr(op0, visitSign(s), NULL);
	}
	return op0;
}
iHdlExpr* ExprParser::visitExpression(vhdlParser::ExpressionContext* ctx) {
	// expression:
	//       condition_operator primary
	//       | logical_expression
	// ;
	auto le = ctx->logical_expression();
	if (le) {
		auto vle = visitLogical_expression(le);
		return vle;
	}

	NotImplementedLogger::print(
			"ExprParser.visitExpression - CONDITION_OPERATOR", ctx);
	auto p = ctx->primary();
	assert(p);
	auto vp = visitPrimary(p);
	return vp;
}

iHdlExpr* ExprParser::visitLogical_expression(
		vhdlParser::Logical_expressionContext *ctx) {
	// logical_expression:
	//       relation ( logical_operator relation )*
	// ;
	auto rel = ctx->relation();
	auto relIt = rel.begin();
	auto ops = ctx->logical_operator();
	auto opIt = ops.begin();
	iHdlExpr* op0 = visitRelation(*relIt);
	++relIt;
	while (opIt != ops.end()) {
		iHdlExpr * op1 = visitRelation(*relIt);
		++relIt;
		op0 = new iHdlExpr(op0, OperatorType_from(*opIt), op1);
		++opIt;
	}
	return op0;
}

iHdlExpr* ExprParser::visitRelation(vhdlParser::RelationContext* ctx) {
	// relation
	// : shift_expression
	// ( : relational_operator shift_expression )?
	// ;

	auto ex = ctx->shift_expression(0);
	iHdlExpr * op0 = visitShift_expression(ex);

	auto op = ctx->relational_operator();
	if (op) {
		iHdlExpr * op1 = visitShift_expression(ctx->shift_expression(1));
		op0 = new iHdlExpr(op0, OperatorType_from(op), op1);
	}

	return op0;
}
iHdlExpr* ExprParser::visitShift_expression(
		vhdlParser::Shift_expressionContext* ctx) {
	// shift_expression
	// : simple_expression
	// ( : shift_operator simple_expression )?
	// ;
	auto se = ctx->simple_expression(0);
	iHdlExpr * op0 = visitSimple_expression(se);
	auto op = ctx->shift_operator();
	if (op) {
		iHdlExpr * op1 = visitSimple_expression(ctx->simple_expression(1));
		op0 = new iHdlExpr(op0, OperatorType_from(op), op1);
	}
	return op0;
}
iHdlExpr * ExprParser::visitTerm(vhdlParser::TermContext* ctx) {
	// term
	// : factor ( : multiplying_operator factor )*
	// ;

	// multiplying_operator
	// : MUL
	// | DIV
	// | MOD
	// | REM
	// ;
	auto fac = ctx->factor();
	auto t = fac.begin();

	auto opList = ctx->multiplying_operator();
	auto opListIt = opList.begin();
	iHdlExpr * op0 = visitFactor(*t);
	if (fac.size() > 1)
		t++;

	while (opListIt != opList.end()) {
		auto op = *opListIt;
		++opListIt;
		iHdlExpr * op1 = visitFactor(*t);
		++t;
		HdlOperatorType opType;
		if (op->MUL())
			opType = HdlOperatorType::MUL;
		else if (op->DIV())
			opType = HdlOperatorType::DIV;
		else if (op->MOD())
			opType = HdlOperatorType::MOD;
		else {
			assert(op->REM());
			opType = HdlOperatorType::REM;
		}
		op0 = new iHdlExpr(op0, opType, op1);
	}
	return op0;
}
iHdlExpr* ExprParser::visitFactor(vhdlParser::FactorContext* ctx) {
	// factor
	// : primary ( : DOUBLESTAR primary )?
	// | ABS primary
	// | NOT primary
	// ;
	auto p0 = ctx->primary(0);
	iHdlExpr * op0 = visitPrimary(p0);
	auto p1 = ctx->primary(1);
	if (p1)
		return new iHdlExpr(op0, POW, visitPrimary(p1));
	if (ctx->ABS())
		return new iHdlExpr(op0, ABS, NULL);
	if (ctx->NOT())
		return new iHdlExpr(op0, NOT, NULL);
	return op0;
}
iHdlExpr * ExprParser::visitPrimary(vhdlParser::PrimaryContext* ctx) {
	// primary:
	//         literal
	//       | LPAREN expression RPAREN
	//       | allocator
	//       | aggregate
	//       | function_call
	//       | type_conversion
	//       | qualified_expression
	//       | name
	// ;
	auto l = ctx->literal();
	if (l)
		return LiteralParser::visitLiteral(l);
	auto e = ctx->expression();
	if (e)
		return visitExpression(e);
	auto al = ctx->allocator();
	if (al)
		return visitAllocator(al);
	auto ag = ctx->aggregate();
	if (ag)
		return visitAggregate(ag);
	auto fc = ctx->function_call();
	if (fc)
		return visitFunction_call(fc);
	auto tc = ctx->type_conversion();
	if (tc)
		return visitType_conversion(tc);
	auto qe = ctx->qualified_expression();
	if (qe)
		return visitQualified_expression(qe);

	auto n = ctx->name();
	assert(n);
	return ReferenceParser::visitName(n);
}
iHdlExpr* ExprParser::visitType_conversion(
		vhdlParser::Type_conversionContext * ctx) {
	// type_conversion: type_mark LPAREN expression RPAREN;
	auto _tm = ctx->type_mark();
	auto tm = visitType_mark(_tm);
	auto _e = ctx->expression();
	auto e = visitExpression(_e);

	return new iHdlExpr(tm, HdlOperatorType::CALL, e);
}
iHdlExpr* ExprParser::visitQualified_expression(
		vhdlParser::Qualified_expressionContext* ctx) {
	// qualified_expression:
	//       type_mark APOSTROPHE
	//       	(LPAREN expression RPAREN)
	//       	| aggregate
	// ;
	auto _tm = ctx->type_mark();
	iHdlExpr * tm = visitType_mark(_tm);
	iHdlExpr * e = nullptr;
	auto _e = ctx->expression();
	if (_e)
		e = visitExpression(_e);
	else {
		auto a = ctx->aggregate();
		e = visitAggregate(a);
	}
	return new iHdlExpr(tm, HdlOperatorType::APOSTROPHE, e);
}
iHdlExpr* ExprParser::visitAllocator(vhdlParser::AllocatorContext* ctx) {
	// allocator
	// : NEW ( qualified_expression | subtype_indication )
	// ;
	auto n = iHdlExpr::ID("new");
	iHdlExpr * e;
	auto qe = ctx->qualified_expression();
	if (qe)
		e = visitQualified_expression(qe);
	else {
		auto si = ctx->subtype_indication();
		e = visitSubtype_indication(si);
	}
	return new iHdlExpr(n, HdlOperatorType::CALL, e);

}
iHdlExpr* ExprParser::visitAggregate(vhdlParser::AggregateContext* ctx) {
	// aggregate:
	//    LPAREN element_association ( COMMA element_association )* RPAREN
	// ;
	std::vector<iHdlExpr*> elements;
	for (auto elm : ctx->element_association()) {
		iHdlExpr * e = visitElement_association(elm);
		elements.push_back(e);
	}
	iHdlExpr * arr = iHdlExpr::ARRAY(elements);

	return arr;
}

iHdlExpr* ExprParser::visitElement_association(
		vhdlParser::Element_associationContext* ctx) {
	// ement_association
	//   : (  choices ARROW )? expression
	//   ;
	auto e = visitExpression(ctx->expression());
	auto _c = ctx->choices();
	if (_c) {
		auto ch = visitChoices(_c);
		if (ch.size() > 1) {
			NotImplementedLogger::print(
					"ExprParser.visitElement_association - multiple choices", _c);
		}
		assert(ch.size());
		return new iHdlExpr(ch[0], HdlOperatorType::MAP_ASSOCIATION, e);
	}
	return e;
}

iHdlExpr* ExprParser::visitTarget(vhdlParser::TargetContext* ctx) {
	// target
	// : name
	// | aggregate
	// ;
	auto n = ctx->name();
	if (n) {
		return ReferenceParser::visitName(n);
	} else {
		return visitAggregate(ctx->aggregate());
	}
}

iHdlExpr * ExprParser::visitWaveform(vhdlParser::WaveformContext* ctx) {
	// waveform :
	// waveform_element ( COMMA waveform_element )*
	// | UNAFFECTED
	// ;
	if (ctx->UNAFFECTED()) {
		NotImplementedLogger::print("ExprParser.visitWaveform - UNAFFECTED", ctx);
		return nullptr;
	}
	auto we = ctx->waveform_element();
	auto weIt = we.begin();

	iHdlExpr* top = visitWaveform_element(*weIt);
	++weIt;
	while (weIt != we.end()) {
		top = new iHdlExpr(top, DOT, visitWaveform_element(*weIt));
		++weIt;
	}

	return top;
}
iHdlExpr* ExprParser::visitCondition(vhdlParser::ConditionContext* ctx) {
	// condition
	// : expression
	// ;
	return ExprParser::visitExpression(ctx->expression());
}
iHdlExpr * ExprParser::visitConditional_waveforms(
		vhdlParser::Conditional_waveformsContext * ctx) {
	// conditional_waveforms:
	//       waveform WHEN condition
	//       ( ELSE waveform WHEN condition )*
	//       ( ELSE waveform )?
	// ;
	auto waveforms = ctx->waveform();
	auto conditions = ctx->condition();
	auto c = conditions.rbegin();
	iHdlExpr * res = nullptr;
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

iHdlExpr *ExprParser::visitWaveform_element(
		vhdlParser::Waveform_elementContext* ctx) {
	// waveform_element :
	// expression ( AFTER expression )?
	// ;
	auto ex = ctx->expression();
	auto e = ex.begin();
	iHdlExpr* top = visitExpression(*e);
	++e;
	if (e != ex.end()) {
		NotImplementedLogger::print(
				"ExprParser.visitWaveform_element - AFTER expression", ctx);
	}
	return top;
}

iHdlExpr * ExprParser::visitChoice(vhdlParser::ChoiceContext * ctx) {
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
		return ExprParser::visitSimple_expression(se);
	}
#ifndef NDEBUG
	auto o = ctx->OTHERS();
	assert(o);
#endif
	return iHdlExpr::others();
}
std::vector<iHdlExpr *> ExprParser::visitChoices(vhdlParser::ChoicesContext * ctx) {
	// choices: choice ( choice )*;
	std::vector<iHdlExpr *> res;
	auto _choice = ctx->choice();
	for (auto c : _choice) {
		res.push_back(visitChoice(c));
	}
	return res;
}

iHdlExpr * ExprParser::visitProcedure_call_statement(
		vhdlParser::Procedure_call_statementContext * ctx) {
	// procedure_call_statement
	//   : ( label_colon )? procedure_call SEMI
	//   ;
	if (ctx->label()) {
		NotImplementedLogger::print(
				"ExprParser.visitProcedure_call_statement - label_colon", ctx);
	}
	return visitProcedure_call(ctx->procedure_call());
}
iHdlExpr * ExprParser::visitProcedure_call(
		vhdlParser::Procedure_callContext * ctx) {
	// procedure_call: name;
	iHdlExpr * fnCall = ReferenceParser::visitName(ctx->name());
	auto c = dynamic_cast<HdlCall*>(fnCall->data);

	if (c == nullptr || c->op != HdlOperatorType::CALL) {
		std::vector<iHdlExpr*> args;
		return iHdlExpr::call(fnCall, args);
	}
	return fnCall;
}

iHdlExpr * ExprParser::visitType_mark(vhdlParser::Type_markContext * ctx) {
	// type_mark: name;
	auto n = ctx->name();
	return ReferenceParser::visitName(n);
}

}
}
