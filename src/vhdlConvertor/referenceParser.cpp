#include "referenceParser.h"

Expr * ReferenceParser::visitSelected_name(
		vhdlParser::Selected_nameContext* ctx) {
	// selected_name
	// : identifier (DOT suffix)*
	// ;
	Expr * top = LiteralParser::visitIdentifier(ctx->identifier());
	for (auto s : ctx->suffix()) {
		top = new Expr(top, DOT, visitSuffix(s));
	}
	assert(top);
	return top;
}
Expr * ReferenceParser::visitSuffix(vhdlParser::SuffixContext* ctx) {
	// suffix
	// : identifier
	// | CHARACTER_LITERAL
	// | STRING_LITERAL
	// | ALL
	// ;
	auto id = ctx->identifier();
	if (id)
		return LiteralParser::visitIdentifier(id);

	auto n = ctx->CHARACTER_LITERAL();
	if (n)
		return LiteralParser::visitCHARACTER_LITERAL(n);
	n = ctx->STRING_LITERAL();
	if (n)
		return LiteralParser::visitSTRING_LITERAL(n);

	return Expr::all();
}

Expr * ReferenceParser::visitName(vhdlParser::NameContext* ctx) {
	// name
	// : selected_name
	// | name_part ( DOT name_part)*
	// ;
	auto sn = ctx->selected_name();
	if (sn)
		return visitSelected_name(sn);

	auto np = ctx->name_part();
	Expr * op0 = NULL;
	for (auto it = np.begin(); it != np.end(); ++it) {
		auto n = *it;
		if (!op0) {
			op0 = visitName_part(n);
		} else {
			Expr * op1 = visitName_part(n);
			op0 = new Expr(op0, DOT, op1);
		}
	}
	assert(op0);
	return op0;
}

Expr * ReferenceParser::visitName_part(vhdlParser::Name_partContext* ctx) {
// name_part
// : selected_name (name_part_specificator)*
// ;
	Expr * sn = visitSelected_name(ctx->selected_name());
	for (auto sp : ctx->name_part_specificator()) {
		sn = visitName_part_specificator(sn, sp);
	}
	return sn;
}

Expr * ReferenceParser::visitName_attribute_part(
		Expr * selectedName,
		vhdlParser::Name_attribute_partContext* ctx) {
// name_attribute_part
// : APOSTROPHE attribute_designator ( expression ( COMMA expression
// )* )?
// ;
	auto expressions = ctx->expression();
	if (expressions.size() > 0)
		NotImplementedLogger::print(
				"ExprParser.visitName_attribute_part - expression");
	return visitAttribute_designator(selectedName, ctx->attribute_designator());
}

Expr * ReferenceParser::visitAttribute_designator(
		Expr * selectedName,
		vhdlParser::Attribute_designatorContext* ctx) {
// attribute_designator
// : identifier
// | RANGE
// | REVERSE_RANGE
// | ACROSS
// | THROUGH
// | REFERENCE
// | TOLERANCE
// ;
	auto idctx = ctx->identifier();
	if (idctx) {
		Expr * id = LiteralParser::visitIdentifier(idctx);
		return new Expr(selectedName, DOT, id);
	}

	if (ctx->RANGE())
	{
		return new Expr(selectedName, RANGE, NULL);
	}

	if (ctx->REVERSE_RANGE())
	{
		return new Expr(selectedName, REVERSE_RANGE, NULL);
	}

	if (ctx->ACROSS())
	{
		return new Expr(selectedName, ACROSS, NULL);
	}

	if (ctx->THROUGH())
	{
		return new Expr(selectedName, THROUGH, NULL);
	}

	if (ctx->REFERENCE())
	{
		return new Expr(selectedName, REFERENCE, NULL);
	}

	if (ctx->TOLERANCE())
	{
		return new Expr(selectedName, TOLERANCE, NULL);
	}	

	NotImplementedLogger::print(
			"ExprParser.visitAttribute_designator - non identifier");
	return Expr::null();
}

Expr * ReferenceParser::visitName_part_specificator(
		Expr * selectedName,
		vhdlParser::Name_part_specificatorContext* ctx) {
	// name_part_specificator
	// : name_attribute_part
	// | name_function_call_or_indexed_part
	// | name_slice_part
	// ;

	auto na = ctx->name_attribute_part();
	if (na) {
		return visitName_attribute_part(selectedName, na);
	}
	auto callOrIndx = ctx->name_function_call_or_indexed_part();
	if (callOrIndx) {
		// name_function_call_or_indexed_part
		// : LPAREN actual_parameter_part? RPAREN
		// ;
		return Expr::call(selectedName,
				ExprParser::visitActual_parameter_part(
						callOrIndx->actual_parameter_part()));
	}
	auto ns = ctx->name_slice_part();
	if (ns)
	{
		return Expr::slice(selectedName, 
				visitName_slice_part(ns));
	}
	return Expr::null();
}

std::vector<Expr*> * ReferenceParser::visitName_slice_part(
		vhdlParser::Name_slice_partContext *ctx) {
	//name_slice_part
	//   : LPAREN explicit_range ( COMMA explicit_range )* RPAREN
	//   ;

	// TODO: Needs work..
	std::vector<Expr*> * sp = new std::vector<Expr*>();
	for (auto er : ctx->explicit_range()) {
		sp->push_back(ExprParser::visitExplicit_range(er));
	}
	return sp;
}