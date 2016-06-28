#include "packageHeaderParser.h"

PackageHeaderParser::PackageHeaderParser(bool _hierarchyOnly) {
	ph = new PackageHeader();
	hierarchyOnly = _hierarchyOnly;
}

PackageHeader * PackageHeaderParser::visitPackage_declaration(
		Ref<vhdlParser::Package_declarationContext> ctx) {
	// package_declaration
	// : PACKAGE identifier IS
	// package_declarative_part
	// END ( PACKAGE )? ( identifier )? SEMI
	// ;
	Expr * name = LiteralParser::visitIdentifier(ctx->identifier(0));
	ph->name = name->extractStr();
	visitPackage_declarative_part(ph, ctx->package_declarative_part());
	return ph;
}
void PackageHeaderParser::visitPackage_declarative_part(
		PackageHeader * ph,
		Ref<vhdlParser::Package_declarative_partContext> ctx) {
	// package_declarative_part
	// : ( package_declarative_item )*
	// ;
	for (auto i : ctx->package_declarative_item()) {
		visitPackage_declarative_item(i);
	}
}
Function * PackageHeaderParser::visitSubprogram_declaration(
		Ref<vhdlParser::Subprogram_declarationContext> ctx) {
	// subprogram_declaration
	// : subprogram_specification SEMI
	// ;
	return visitSubprogram_specification(ctx->subprogram_specification());
}
Function * PackageHeaderParser::visitSubprogram_specification(
		Ref<vhdlParser::Subprogram_specificationContext> ctx) {
	// subprogram_specification
	// : procedure_specification
	// | function_specification
	// ;

	auto p = ctx->procedure_specification();
	if (p)
		return visitProcedure_specification(p);
	else
		return visitFunction_specification(ctx->function_specification());
}

Function * PackageHeaderParser::visitProcedure_specification(
		Ref<vhdlParser::Procedure_specificationContext> ctx) {
	// procedure_specification
	// : PROCEDURE designator ( LPAREN formal_parameter_list RPAREN )?
	// ;
	auto designator = ctx->designator();
	Expr * returnT = NULL;
	bool isOperator = LiteralParser::isStrDesignator(designator);
	char * name = LiteralParser::visitDesignator(designator);
	std::vector<Variable*> * paramList = visitFormal_parameter_list(
			ctx->formal_parameter_list());

	return new Function(name, isOperator, returnT, paramList);
}
Function * PackageHeaderParser::visitFunction_specification(
		Ref<vhdlParser::Function_specificationContext> ctx) {
	// function_specification
	// : ( PURE | IMPURE )? FUNCTION designator
	// ( LPAREN formal_parameter_list RPAREN )? RETURN subtype_indication
	// ;
	auto designator = ctx->designator();
	Expr * returnT = ExprParser::visitSubtype_indication(
			ctx->subtype_indication());
	assert(returnT);

	bool isOperator = LiteralParser::isStrDesignator(designator);
	char * name = LiteralParser::visitDesignator(designator);
	std::vector<Variable*> * paramList = visitFormal_parameter_list(
			ctx->formal_parameter_list());

	return new Function(name, isOperator, returnT, paramList);
}

std::vector<Variable*> * PackageHeaderParser::visitFormal_parameter_list(
		Ref<vhdlParser::Formal_parameter_listContext> ctx) {
	// formal_parameter_list
	// : interface_list
	// ;
	return InterfaceParser::visitInterface_list(ctx->interface_list());
}

std::vector<Variable*> * PackageHeaderParser::visitConstant_declaration(
		Ref<vhdlParser::Constant_declarationContext> ctx) {
	//constant_declaration :
	//    CONSTANT identifier_list COLON subtype_indication
	//    ( VARASGN expression )? SEMI
	//  ;
	return InterfaceParser::extractVariables(ctx->identifier_list(),
			ctx->subtype_indication(), ctx->expression());
}

Variable * PackageHeaderParser::visitSubtype_declaration(
		Ref<vhdlParser::Subtype_declarationContext> ctx) {
	//subtype_declaration
	//  : SUBTYPE identifier IS subtype_indication SEMI
	//  ;
	auto t = ExprParser::visitSubtype_indication(ctx->subtype_indication());
	Variable * v = new Variable(ctx->identifier()->getText(), Expr::TYPE_T(),
			t);
	return v;
}

void PackageHeaderParser::visitPackage_declarative_item(
		Ref<vhdlParser::Package_declarative_itemContext> ctx) {
	// package_declarative_item
	// : subprogram_declaration
	// | type_declaration
	// | subtype_declaration
	// | constant_declaration
	// | signal_declaration
	// | variable_declaration
	// | file_declaration
	// | alias_declaration
	// | component_declaration
	// | attribute_declaration
	// | attribute_specification
	// | disconnection_specification
	// | use_clause
	// | group_template_declaration
	// | group_declaration
	// | nature_declaration
	// | subnature_declaration
	// | terminal_declaration
	// ;
	auto sp = ctx->subprogram_declaration();
	if (sp) {
		ph->functions.push_back(visitSubprogram_declaration(sp));
		return;
	}
	auto td = ctx->type_declaration();
	if (td) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitType_declaration");
	}
	auto st = ctx->subtype_declaration();
	if (st) {
		auto _st = visitSubtype_declaration(st);
		ph->variables.push_back(_st);
	}
	auto constd = ctx->constant_declaration();
	if (constd) {
		auto constants = visitConstant_declaration(constd);
		for (auto c : *constants) {
			ph->variables.push_back(c);
		}
		delete constants;
	}
	auto sd = ctx->signal_declaration();
	if (sd) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitSignal_declaration");
	}
	auto vd = ctx->variable_declaration();
	if (vd) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitVariable_declaration");
	}
	auto fd = ctx->file_declaration();
	if (fd) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitFile_declaration");
	}
	auto aliasd = ctx->alias_declaration();
	if (aliasd) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitAlias_declaration");
	}
	auto compd = ctx->component_declaration();
	if (compd) {
		ph->components.push_back(visitComponent_declaration(compd));
	}
	auto atrd = ctx->attribute_declaration();
	if (atrd) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitAttribute_declaration");
	}
	auto as = ctx->attribute_specification();
	if (as) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitAttribute_specification");
	}
	auto discs = ctx->disconnection_specification();
	if (discs) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitDisconnection_specification");
	}
	auto uc = ctx->use_clause();
	if (uc) {
		NotImplementedLogger::print("PackageHeaderParser.visitUse_clause");
	}
	auto gtd = ctx->group_template_declaration();
	if (gtd) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitGroup_template_declaration");
	}
	auto gd = ctx->group_declaration();
	if (gd) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitGroup_declaration");
	}
	auto nd = ctx->nature_declaration();
	if (nd) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitNature_declaration");
	}
	auto snd = ctx->subnature_declaration();
	if (snd) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitSubnature_declaration");
	}
	auto tdc = ctx->terminal_declaration();
	if (tdc) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitTerminal_declaration");
	}
}
Entity * PackageHeaderParser::visitComponent_declaration(
		Ref<vhdlParser::Component_declarationContext> ctx) {
	// component_declaration
	// : COMPONENT identifier ( IS )?
	// ( generic_clause )?
	// ( port_clause )?
	// END COMPONENT ( identifier )? SEMI
	// ;
	Entity * e = new Entity();
	e->name = strdup(ctx->identifier(0)->getText().c_str());
	if (!hierarchyOnly) {
		EntityParser::visitGeneric_clause(ctx->generic_clause(), &e->generics);
		EntityParser::visitPort_clause(ctx->port_clause(), &e->ports);
	}
	return e;
}
