#include "referenceParser.h"

Expr * ReferenceParser::visitSelected_name(
		Ref<vhdlParser::Selected_nameContext> ctx) {
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
Expr * ReferenceParser::visitSuffix(Ref<vhdlParser::SuffixContext> ctx) {
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

Expr * ReferenceParser::visitName(Ref<vhdlParser::NameContext> ctx) {
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
Expr * ReferenceParser::visitAttribute_designator(
		Expr * selectedName,
		Ref<vhdlParser::Attribute_designatorContext> ctx) {
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
	NotImplementedLogger::print(
			"ExprParser.visitAttribute_designator - non identifier");
	return NULL;
}
Expr * ReferenceParser::visitName_attribute_part(
		Expr * selectedName,
		Ref<vhdlParser::Name_attribute_partContext> ctx) {
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
Expr * ReferenceParser::visitName_part_specificator(
		Expr * selectedName,
		Ref<vhdlParser::Name_part_specificatorContext> ctx) {
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
	NotImplementedLogger::print("ExprParser.visitName_slice_partContext");
	return NULL;
}

Expr * ReferenceParser::visitName_part(Ref<vhdlParser::Name_partContext> ctx) {
// name_part
// : selected_name (name_part_specificator)*
// ;
	Expr * sn = visitSelected_name(ctx->selected_name());
	for (auto sp : ctx->name_part_specificator()) {
		sn = visitName_part_specificator(sn, sp);
	}
	return sn;
}
