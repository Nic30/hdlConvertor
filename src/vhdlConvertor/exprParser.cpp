#include "exprParser.h"

std::vector<Expr*> * ExprParser::visitActual_parameter_part(
		Ref<vhdlParser::Actual_parameter_partContext> ctx) {
	std::vector<Expr*> * l = new std::vector<Expr*>();
	if (!ctx)
		return l;
	// actual_parameter_part
	// : association_list
	// ;
	// association_list
	// : association_element ( COMMA association_element )*
	// ;
	for (auto e : ctx->association_list()->association_element()) {
		l->push_back(visitAssociation_element(e));
	}
	return l;
}
Expr* ExprParser::visitAssociation_element(
		Ref<vhdlParser::Association_elementContext> ctx) {
	// association_element
	// : ( formal_part ARROW )? actual_part
	// ;
	Expr * ap = visitActual_part(ctx->actual_part());
	auto fp = ctx->formal_part();
	if (fp) {
		return new Expr(visitFormal_part(fp), ARROW, ap);
	}
	return ap;
}
Expr* ExprParser::visitFormal_part(Ref<vhdlParser::Formal_partContext> ctx) {
	// formal_part
	// : identifier
	// | identifier LPAREN explicit_range RPAREN
	// ;
	Expr * id = LiteralParser::visitIdentifier(ctx->identifier());
	auto er = ctx->explicit_range();
	if (er) {
		return new Expr(id, RANGE, visitExplicit_range(er));
	}
	return id;
}

Expr* ExprParser::visitExplicit_range(
		Ref<vhdlParser::Explicit_rangeContext> ctx) {
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
Expr* ExprParser::visitRange(Ref<vhdlParser::RangeContext> ctx) {
	// range
	// : explicit_range
	// | name
	// ;

	auto er = ctx->explicit_range();
	if (er)
		return visitExplicit_range(er);

	return ReferenceParser::visitName(ctx->name());
}
Expr* ExprParser::visitActual_part(Ref<vhdlParser::Actual_partContext> ctx) {
	// actual_part
	// : name LPAREN actual_designator RPAREN
	// | actual_designator
	// ;
	auto name = ctx->name();
	Expr * ad = visitActual_designator(ctx->actual_designator());
	if (name) {
		std::vector<Expr*> * ops = new std::vector<Expr*>();
		ops->push_back(ad);
		return Expr::call(ReferenceParser::visitName(name), ops);
	}
	return ad;
}
Expr* ExprParser::visitActual_designator(
		Ref<vhdlParser::Actual_designatorContext> ctx) {
	// actual_designator
	// : expression
	// | OPEN
	// ;
	if (ctx->OPEN())
		return Expr::OPEN();

	return visitExpression(ctx->expression());
}
Expr* ExprParser::visitSubtype_indication(
		Ref<vhdlParser::Subtype_indicationContext> ctx) {
	// subtype_indication
	// : selected_name ( selected_name )? ( constraint )? ( tolerance_aspect
	// )?
	// ;
	auto c = ctx->constraint();
	assert(ctx->tolerance_aspect() == NULL);
	auto snames = ctx->selected_name();
	auto mainSelName = snames[0];

	if (snames.size() > 1)
		NotImplementedLogger::print(
				"ExprParser.visitSubtype_indication - selected_name2");
	if (ctx->tolerance_aspect())
		NotImplementedLogger::print(
				"ExprParser.visitSubtype_indication - tolerance_aspect");

	if (c) {
		return visitConstraint(mainSelName, c);
	} else {
		return ReferenceParser::visitSelected_name(mainSelName);
	}
}

Expr* ExprParser::visitConstraint(
		Ref<vhdlParser::Selected_nameContext> selectedName,
		Ref<vhdlParser::ConstraintContext> ctx) {
	// constraint
	// : range_constraint
	// | index_constraint
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
		auto i = ctx->index_constraint();
		op = INDEX;
		op1 = visitIndex_constraint(i);
	}

	return new Expr(ReferenceParser::visitSelected_name(selectedName), op, op1);

}
Expr* ExprParser::visitIndex_constraint(
		Ref<vhdlParser::Index_constraintContext> ctx) {
	// index_constraint
	// : LPAREN discrete_range ( COMMA discrete_range )* RPAREN
	// ;
	if (ctx->discrete_range().size() > 1) {
		NotImplementedLogger::print(
				"ExprParser.visitIndex_constraint multiple discrete_range");
	}
	return visitDiscrete_range(ctx->discrete_range(0));
}
Expr* ExprParser::visitDiscrete_range(
		Ref<vhdlParser::Discrete_rangeContext> ctx) {
	// discrete_range
	// : range
	// | subtype_indication
	// ;
	auto r = ctx->range();
	if (r)
		return visitRange(r);
	return visitSubtype_indication(ctx->subtype_indication());
}
Expr* ExprParser::visitSimple_expression(
		Ref<vhdlParser::Simple_expressionContext> ctx) {
	// simple_expression
	// : ( PLUS | MINUS )? term ( : adding_operator term )*
	// ;
	// adding_operator
	// : PLUS
	// | MINUS
	// | AMPERSAND
	// ;

	auto t = ctx->term();
	auto tIt = t.begin();
	auto opList = ctx->adding_operator();
	auto opListIt = opList.begin();
	Expr* op0 = visitTerm(*tIt);
	if (t.size() > 1)
		tIt++;
	if (ctx->MINUS()) {
		op0 = new Expr(op0, UN_MINUS, NULL);
	}
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
	return op0;
}
Expr* ExprParser::visitExpression(Ref<vhdlParser::ExpressionContext> ctx) {
	// expression
	// : relation ( : logical_operator relation )*
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
Expr* ExprParser::visitRelation(Ref<vhdlParser::RelationContext> ctx) {
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
		Ref<vhdlParser::Shift_expressionContext> ctx) {
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
Expr * ExprParser::visitTerm(Ref<vhdlParser::TermContext> ctx) {
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
Expr* ExprParser::visitFactor(Ref<vhdlParser::FactorContext> ctx) {
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
Expr * ExprParser::visitPrimary(Ref<vhdlParser::PrimaryContext> ctx) {
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
		Ref<vhdlParser::Qualified_expressionContext> ctx) {
	// qualified_expression
	// : subtype_indication APOSTROPHE ( aggregate | LPAREN expression
	// RPAREN )
	// ;
	NotImplementedLogger::print("ExprParser visitQualified_expression");
	return NULL;
}
Expr* ExprParser::visitAllocator(Ref<vhdlParser::AllocatorContext> ctx) {
	// allocator
	// : NEW ( qualified_expression | subtype_indication )
	// ;
	NotImplementedLogger::print("ExprParser visitAllocator");
	return NULL;

}
Expr* ExprParser::visitAggregate(Ref<vhdlParser::AggregateContext> ctx) {
	// aggregate
	// : LPAREN element_association ( COMMA element_association )* RPAREN
	// ;
	NotImplementedLogger::print("ExprParser visitAggregate");
	return NULL;
}

Expr* ExprParser::visitTarget(Ref<vhdlParser::TargetContext> ctx) {
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
Expr * ExprParser::visitWaveform(Ref<vhdlParser::WaveformContext> ctx) {
	// waveform :
	// waveform_element ( COMMA waveform_element )*
	// | UNAFFECTED
	// ;
	if (ctx->UNAFFECTED()) {
		NotImplementedLogger::print("ExprParser.visitWaveform - UNAFFECTED");
		return NULL;
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
		Ref<vhdlParser::Waveform_elementContext> ctx) {
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
