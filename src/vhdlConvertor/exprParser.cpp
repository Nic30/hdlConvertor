#include "exprParser.h"
#include "../notImplementedLogger.h"
#include "literalParser.h"
#include "referenceParser.h"
#include "operatoTypeParser.h"
#include "directionParser.h"

namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlObjects;

std::vector<Expr*> * ExprParser::visitActual_parameter_part(
		vhdlParser::Actual_parameter_partContext* ctx) {
	std::vector<Expr*> * l = new std::vector<Expr*>();
	if (!ctx)
		return l;
	// actual_parameter_part
	// : association_list
	// ;

	return visitAssociation_list(ctx->association_list());
}

std::vector<Expr*> * ExprParser::visitAssociation_list(
		vhdlParser::Association_listContext *ctx) {
	// association_list
	// : association_element ( COMMA association_element )*
	// ;

	std::vector<Expr*> * ae = new std::vector<Expr*>();
	for (auto e : ctx->association_element()) {
		ae->push_back(visitAssociation_element(e));
	}
	return ae;
}

Expr* ExprParser::visitAssociation_element(
		vhdlParser::Association_elementContext* ctx) {
	// association_element
	// : ( formal_part ARROW )? actual_part
	// ;
	Expr * ap = visitActual_part(ctx->actual_part());
	auto fp = ctx->formal_part();
	if (fp) {
		auto vfp = new Expr(visitFormal_part(fp), ARROW, ap);
		vfp->position.update_from_elem(ctx);
		return vfp;
	}
	ap->position.update_from_elem(ctx);
	return ap;
}
Expr* ExprParser::visitFormal_part(vhdlParser::Formal_partContext* ctx) {
	// formal_part:
	//       formal_designator
	//       | name LPAREN formal_designator RPAREN
	//       | type_mark LPAREN formal_designator RPAREN
	// ;
	// formal_designator:
	//       name
	// ;
	Expr * id = ReferenceParser::visitName(ctx->formal_designator()->name());
	auto n = ctx->name();
	if (n) {
		return new Expr(ReferenceParser::visitName(n), INDEX, id);
	}
	auto tm = ctx->type_mark();
	if (tm) {
		// type_mark: name;
		return new Expr(visitType_mark(tm), INDEX, id);
	}

	return id;
}

Expr* ExprParser::visitExplicit_range(vhdlParser::Explicit_rangeContext* ctx) {
	// explicit_range
	// : simple_expression direction simple_expression
	// ;
	OperatorType op;
	if (ctx->direction()->DOWNTO()) {
		op = DOWNTO;
	} else {
		op = TO;
	}
	return new Expr(visitSimple_expression(ctx->simple_expression(0)), op,
			visitSimple_expression(ctx->simple_expression(1)));
}
Expr* ExprParser::visitRange(vhdlParser::RangeContext* ctx) {
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
	return new Expr(a, o, b);
}
Expr* ExprParser::visitPrefix(vhdlParser::PrefixContext * ctx) {
	// prefix:
	//       name
	//       | function_call
	// ;
	auto n = ctx->name();
	if (n)
		return ReferenceParser::visitName(n);

	return visitFunction_call(ctx->function_call());
}
Expr* ExprParser::visitFunction_call(vhdlParser::Function_callContext *ctx) {
	// function_call:
	//       name ( LPAREN actual_parameter_part RPAREN )?
	// ;
	auto n = ReferenceParser::visitName(ctx->name());
	std::vector<Expr*> * args = nullptr;
	auto app = ctx->actual_parameter_part();
	if (app) {
		args = visitActual_parameter_part(app);
	} else {
		args = new std::vector<Expr*>();
	}
	auto call = Expr::call(n, *args);
	delete args;
	return call;
}

Expr* ExprParser::visitActual_part(vhdlParser::Actual_partContext* ctx) {
	// actual_part
	// : name LPAREN actual_designator RPAREN
	// | actual_designator
	// ;
	auto name = ctx->name();
	Expr * ad = visitActual_designator(ctx->actual_designator());
	if (name) {
		std::vector<Expr*> ops = { ad, };
		return Expr::call(ReferenceParser::visitName(name), ops);
	}
	return ad;
}
Expr* ExprParser::visitActual_designator(
		vhdlParser::Actual_designatorContext* ctx) {
	// actual_designator
	// : expression
	// | OPEN
	// ;
	if (ctx->OPEN())
		return Expr::OPEN();

	return visitExpression(ctx->expression());
}
Expr* ExprParser::visitSubtype_indication(
		vhdlParser::Subtype_indicationContext* ctx) {
	// subtype_indication
	// : selected_name ( selected_name )? ( constraint )* ( tolerance_aspect )?
	// ;

	// subtype_indication:
	//       ( resolution_indication )? type_mark ( constraint )?
	// ;

	auto _ri = ctx->resolution_indication();
	Expr * ri = nullptr;
	if (_ri) {
		ri = visitResolution_indication(_ri);
		NotImplementedLogger::print(
				"ExprParser.visitResolution_indication - element_resolution");
		delete ri;
	}

	// type_mark: name;
	Expr * e = visitType_mark(ctx->type_mark());
	auto c = ctx->constraint();
	if (c) {
		e = visitConstraint(e, c);
	}
	return e;
}
Expr * ExprParser::visitResolution_indication(
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
			"ExprParser.visitResolution_indication - element_resolution");
	return nullptr;
}

Expr* ExprParser::visitConstraint(Expr* selectedName,
		vhdlParser::ConstraintContext* ctx) {
	// constraint:
	//       range_constraint
	//       | array_constraint
	//       | record_constraint
	// ;

	auto r = ctx->range_constraint();
	OperatorType op;
	Expr* op1 = NULL;
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
			auto r = ctx->record_constraint();
			assert(r);
			NotImplementedLogger::print(
					"ExprParser.visitConstraint - record_constraint");
		}
	}

	return new Expr(selectedName, op, op1);

}
Expr* ExprParser::visitArray_constraint(
		vhdlParser::Array_constraintContext * ctx) {
	// array_constraint:
	//       index_constraint ( array_element_constraint )?
	//       | LPAREN OPEN RPAREN ( array_element_constraint )?
	// ;
	auto ic = ctx->index_constraint();
	auto aec = ctx->array_element_constraint();
	if (aec) {
		NotImplementedLogger::print(
				"ExprParser.visitArray_constraint - array_element_constraint");
	}
	if (ic) {
		auto e = visitIndex_constraint(ic);
		return e;
	}
	return nullptr;

}
Expr* ExprParser::visitIndex_constraint(
		vhdlParser::Index_constraintContext* ctx) {
	// index_constraint
	// : LPAREN discrete_range ( COMMA discrete_range )* RPAREN
	// ;
	if (ctx->discrete_range().size() > 1) {
		NotImplementedLogger::print(
				"ExprParser.visitIndex_constraint multiple discrete_range");
	}
	return visitDiscrete_range(ctx->discrete_range(0));
}
Expr* ExprParser::visitDiscrete_range(vhdlParser::Discrete_rangeContext* ctx) {
	// discrete_range
	// : range
	// | subtype_indication
	// ;
	auto r = ctx->range();
	if (r)
		return visitRange(r);
	return visitSubtype_indication(ctx->subtype_indication());
}

hdlObjects::OperatorType ExprParser::visitSign(vhdlParser::SignContext * ctx) {
	// sign: PLUS | MINUS;
	if (ctx->MINUS()) {
		return OperatorType::SUB;
	} else {
		assert(ctx->PLUS());
		return OperatorType::ADD;
	}
}
Expr* ExprParser::visitSimple_expression(
		vhdlParser::Simple_expressionContext* ctx) {
	// simple_expression:
	//	( sign )? term ( adding_operator term )*
	//	;
	// adding_operator: PLUS | MINUS | AMPERSAND;

	auto t = ctx->term();
	auto tIt = t.begin();
	auto opList = ctx->adding_operator();
	auto opListIt = opList.begin();
	Expr* op0 = visitTerm(*tIt);
	if (t.size() > 1)
		tIt++;

	while (opListIt != opList.end()) {
		auto op = *opListIt;
		++opListIt;
		Expr* op1 = visitTerm(*tIt);
		++tIt;
		OperatorType opType;
		if (op->PLUS())
			opType = ADD;
		else if (op->MINUS()) {
			opType = SUB;
		} else {
			assert(op->AMPERSAND());
			opType = CONCAT;
		}
		op0 = new Expr(op0, opType, op1);
	}

	auto s = ctx->sign();
	if (s) {
		op0 = new Expr(op0, visitSign(s), NULL);
	}
	return op0;
}
Expr* ExprParser::visitExpression(vhdlParser::ExpressionContext* ctx) {
	//expression
	//	: CONDITION_OPERATOR primary
	//	| logical_expression
	//	;
	auto le = ctx->logical_expression();
	if (le) {
		auto vle = visitLogical_expression(le);
		return vle;
	}

	auto p = ctx->primary();
	assert(p);
	auto vp = visitPrimary(p);
	return vp;
}

Expr* ExprParser::visitLogical_expression(
		vhdlParser::Logical_expressionContext *ctx) {
	// logical_expression:
	//       relation ( logical_operator relation )*
	// ;
	auto rel = ctx->relation();
	auto relIt = rel.begin();
	auto ops = ctx->logical_operator();
	auto opIt = ops.begin();
	Expr* op0 = visitRelation(*relIt);
	++relIt;
	while (opIt != ops.end()) {
		Expr * op1 = visitRelation(*relIt);
		++relIt;
		op0 = new Expr(op0, OperatorType_from(*opIt), op1);
		++opIt;
	}
	return op0;
}

Expr* ExprParser::visitRelation(vhdlParser::RelationContext* ctx) {
	// relation
	// : shift_expression
	// ( : relational_operator shift_expression )?
	// ;

	auto ex = ctx->shift_expression(0);
	Expr * op0 = visitShift_expression(ex);

	auto op = ctx->relational_operator();
	if (op) {
		Expr * op1 = visitShift_expression(ctx->shift_expression(1));
		op0 = new Expr(op0, OperatorType_from(op), op1);
	}

	return op0;

}
Expr* ExprParser::visitShift_expression(
		vhdlParser::Shift_expressionContext* ctx) {
	// shift_expression
	// : simple_expression
	// ( : shift_operator simple_expression )?
	// ;
	Expr * op0 = visitSimple_expression(ctx->simple_expression(0));
	auto op = ctx->shift_operator();
	if (op) {
		Expr * op1 = visitSimple_expression(ctx->simple_expression(1));
		op0 = new Expr(op0, OperatorType_from(op), op1);
	}
	return op0;
}
Expr * ExprParser::visitTerm(vhdlParser::TermContext* ctx) {
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
	Expr * op0 = visitFactor(*t);
	if (fac.size() > 1)
		t++;

	while (opListIt != opList.end()) {
		auto op = *opListIt;
		++opListIt;
		Expr * op1 = visitFactor(*t);
		++t;
		OperatorType opType;
		if (op->MUL())
			opType = MUL;
		else if (op->DIV())
			opType = DIV;
		else if (op->MOD())
			opType = MOD;
		else {
			assert(op->REM());
			opType = REM;
		}
		op0 = new Expr(op0, opType, op1);
	}
	return op0;
}
Expr* ExprParser::visitFactor(vhdlParser::FactorContext* ctx) {
	// factor
	// : primary ( : DOUBLESTAR primary )?
	// | ABS primary
	// | NOT primary
	// ;
	Expr * op0 = visitPrimary(ctx->primary(0));
	auto p1 = ctx->primary(1);
	if (p1)
		return new Expr(op0, POW, visitPrimary(p1));
	if (ctx->ABS())
		return new Expr(op0, ABS, NULL);
	if (ctx->NOT())
		return new Expr(op0, NOT, NULL);
	return op0;
}
Expr * ExprParser::visitPrimary(vhdlParser::PrimaryContext* ctx) {
	// primary
	// : literal
	// | qualified_expression
	// | LPAREN expression RPAREN
	// | allocator
	// | aggregate
	// | name
	// ;
	auto l = ctx->literal();
	if (l)
		return LiteralParser::visitLiteral(l);
	auto qe = ctx->qualified_expression();
	if (qe)
		return visitQualified_expression(qe);
	auto e = ctx->expression();
	if (e)
		return visitExpression(e);
	auto al = ctx->allocator();
	if (al)
		return visitAllocator(al);
	auto ag = ctx->aggregate();
	if (ag)
		return visitAggregate(ag);
	auto n = ctx->name();
	return ReferenceParser::visitName(n);
}
Expr* ExprParser::visitQualified_expression(
		vhdlParser::Qualified_expressionContext* ctx) {
	// qualified_expression
	// : subtype_indication APOSTROPHE ( aggregate | LPAREN expression
	// RPAREN )
	// ;
	NotImplementedLogger::print("ExprParser visitQualified_expression");
	return nullptr;
}
Expr* ExprParser::visitAllocator(vhdlParser::AllocatorContext* ctx) {
	// allocator
	// : NEW ( qualified_expression | subtype_indication )
	// ;
	NotImplementedLogger::print("ExprParser visitAllocator");
	return nullptr;

}
Expr* ExprParser::visitAggregate(vhdlParser::AggregateContext* ctx) {
	// aggregate
	// : LPAREN element_association ( COMMA element_association )* RPAREN
	// ;
	std::vector<Expr*> elements;
	for (auto elm : ctx->element_association()) {
		Expr * e = visitElement_association(elm);
		elements.push_back(e);
	}
	Expr * arr = Expr::ARRAY(elements);

	return arr;
}

Expr* ExprParser::visitElement_association(
		vhdlParser::Element_associationContext* ctx) {
	// ement_association
	//   : (  choices ARROW )? expression
	//   ;
	if (ctx->choices()) {
		NotImplementedLogger::print(
				"ExprParser.visitElement_association.choices");
	}
	return visitExpression(ctx->expression());
}

Expr* ExprParser::visitTarget(vhdlParser::TargetContext* ctx) {
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

Expr * ExprParser::visitWaveform(vhdlParser::WaveformContext* ctx) {
	// waveform :
	// waveform_element ( COMMA waveform_element )*
	// | UNAFFECTED
	// ;
	if (ctx->UNAFFECTED()) {
		NotImplementedLogger::print("ExprParser.visitWaveform - UNAFFECTED");
		return nullptr;
	}
	auto we = ctx->waveform_element();
	auto weIt = we.begin();

	Expr* top = visitWaveform_element(*weIt);
	++weIt;
	while (weIt != we.end()) {
		top = new Expr(top, DOT, visitWaveform_element(*weIt));
		++weIt;
	}

	return top;
}

Expr *ExprParser::visitWaveform_element(
		vhdlParser::Waveform_elementContext* ctx) {
	// waveform_element :
	// expression ( AFTER expression )?
	// ;
	auto ex = ctx->expression();
	auto e = ex.begin();
	Expr* top = visitExpression(*e);
	++e;
	if (e != ex.end()) {
		NotImplementedLogger::print(
				"ExprParser.visitWaveform_element - AFTER expression");
	}
	return top;
}

Expr * ExprParser::visitChoice(vhdlParser::ChoiceContext * ctx) {
	//choice
	//  : identifier
	//  | discrete_range
	//  | simple_expression
	//  | OTHERS
	//  ;
	//
	// choice:
	//       simple_expression
	//       | discrete_range
	//       | simple_name
	// ;

	auto se = ctx->simple_expression();
	if (se) {
		return ExprParser::visitSimple_expression(se);
	}
	auto dr = ctx->discrete_range();
	if (dr) {
		return visitDiscrete_range(dr);
	}
	auto e = ctx->simple_expression();
	assert(e);
	return visitSimple_expression(e);
}
std::vector<Expr *> ExprParser::visitChoices(vhdlParser::ChoicesContext * ctx) {
	//choices
	//  : choice ( BAR choice )*
	//  ;
	std::vector<Expr *> res;
	for (auto c : ctx->choice()) {
		res.push_back(visitChoice(c));
	}
	return res;
}

Expr * ExprParser::visitProcedure_call_statement(
		vhdlParser::Procedure_call_statementContext * ctx) {
	// procedure_call_statement
	//   : ( label_colon )? procedure_call SEMI
	//   ;
	if (ctx->label()) {
		NotImplementedLogger::print(
				"ExprParser.visitProcedure_call_statement - label_colon");
	}
	return visitProcedure_call(ctx->procedure_call());
}
Expr * ExprParser::visitProcedure_call(
		vhdlParser::Procedure_callContext * ctx) {
	// procedure_call: name ( LPAREN actual_parameter_part RPAREN )?;
	Expr * fnName = ReferenceParser::visitName(ctx->name());
	auto args = ExprParser::visitActual_parameter_part(
			ctx->actual_parameter_part());
	auto c = Expr::call(fnName, *args);
	delete args;
	return c;
}

Expr * ExprParser::visitType_mark(vhdlParser::Type_markContext * ctx) {
	// type_mark: name;
	return ReferenceParser::visitName(ctx->name());
}

}
}
