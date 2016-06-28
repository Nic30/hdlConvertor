#include "packageParser.h"

PackageParser::PackageParser(bool _hierarchyOnly) {
	hierarchyOnly = _hierarchyOnly;
	p = new Package();
}
Package * PackageParser::visitPackage_body(
		Ref<vhdlParser::Package_bodyContext> ctx) {
	// package_body
	// : PACKAGE BODY identifier IS
	// package_body_declarative_part
	// END ( PACKAGE BODY )? ( identifier )? SEMI
	// ;
	Expr * id = LiteralParser::visitIdentifier(ctx->identifier(0));
	p->name = strdup(id->extractStr());
	delete id;

	if (!hierarchyOnly) {
		auto pdp = ctx->package_body_declarative_part();
		if (pdp)
			visitPackage_body_declarative_part(p, pdp);
	}
	return p;
}
void PackageParser::visitPackage_body_declarative_part(
		aPackage * p,
		Ref<vhdlParser::Package_body_declarative_partContext> ctx) {
	// package_body_declarative_part
	// : ( package_body_declarative_item )*
	// ;
	auto pbdi = ctx->package_body_declarative_item();
	for (auto i : pbdi) {
		visitPackage_body_declarative_item(i);
	}
}
void PackageParser::visitPackage_body_declarative_item(
		Ref<vhdlParser::Package_body_declarative_itemContext> ctx) {
	// package_body_declarative_item
	// : subprogram_declaration
	// | subprogram_body
	// | type_declaration
	// | subtype_declaration
	// | constant_declaration
	// | variable_declaration
	// | file_declaration
	// | alias_declaration
	// | use_clause
	// | group_template_declaration
	// | group_declaration
	// ;
	auto sd = ctx->subprogram_declaration();
	if (sd) {
		visitSubprogram_declaration(sd);
		return;
	}

	auto sb = ctx->subprogram_body();
	if (sb) {
		Function * f = visitSubprogram_body(sb);
		p->functions.push_back(f);
		return;
	}

	NotImplementedLogger::print(
			"PackageParser.visitPackage_body_declarative_item");
}
Function * PackageParser::visitSubprogram_body(
		Ref<vhdlParser::Subprogram_bodyContext> ctx) {
	// subprogram_body :
	// subprogram_specification IS
	// subprogram_declarative_part
	// BEGIN
	// subprogram_statement_part
	// END ( subprogram_kind )? ( designator )? SEMI
	// ;
	Function * f = PackageHeaderParser::visitSubprogram_specification(
			ctx->subprogram_specification());

	auto vs = visitSubprogram_declarative_part(
			ctx->subprogram_declarative_part());
	for (auto v : *vs) {
		f->locals.push_back(v);
	}
	delete vs;

	auto stmts = visitSubprogram_statement_part(
			ctx->subprogram_statement_part());
	for (auto s : *stmts) {
		f->body.push_back(s);
	}
	delete stmts;

	return f;
}
std::vector<Variable*>* PackageParser::PackageParser::visitSubprogram_declarative_part(
		Ref<vhdlParser::Subprogram_declarative_partContext> ctx) {
	// subprogram_declarative_part
	// : ( subprogram_declarative_item )*
	// ;
	std::vector<Variable*> * vars = new std::vector<Variable*>();
	for (auto sd : ctx->subprogram_declarative_item()) {
		auto spdis = visitSubprogram_declarative_item(sd);
		for (auto spdi : *spdis)
			vars->push_back(spdi);
		delete spdis;
	}

	return vars;
}
std::vector<Variable *> * PackageParser::visitSubprogram_declarative_item(
		Ref<vhdlParser::Subprogram_declarative_itemContext> ctx) {
	// subprogram_declarative_item
	// : subprogram_declaration
	// | subprogram_body
	// | type_declaration
	// | subtype_declaration
	// | constant_declaration
	// | variable_declaration
	// | file_declaration
	// | alias_declaration
	// | attribute_declaration
	// | attribute_specification
	// | use_clause
	// | group_template_declaration
	// | group_declaration
	// ;
	auto vd = ctx->variable_declaration();
	if (vd) {
		return visitVariable_declaration(vd);
	}

	NotImplementedLogger::print(
			"PackageParser.visitSubprogram_declarative_item");
	return new std::vector<Variable*>();
}

std::vector<Variable*> * PackageParser::visitVariable_declaration(
		Ref<vhdlParser::Variable_declarationContext> ctx) {
	// variable_declaration :
	// ( SHARED )? VARIABLE identifier_list COLON
	// subtype_indication ( VARASGN expression )? SEMI
	// ;
	if (ctx->SHARED())
		NotImplementedLogger::print(
				"PackageParser.visitVariable_declaration - SHARED");

	std::vector<Variable*> * vl = InterfaceParser::extractVariables(
			ctx->identifier_list(), ctx->subtype_indication(),
			ctx->expression());
	return vl;
}

void PackageParser::visitSubprogram_declaration(
		Ref<vhdlParser::Subprogram_declarationContext> ctx) {
	// subprogram_declaration
	// : subprogram_specification SEMI
	// ;
	NotImplementedLogger::print("PackageParser.visitSubprogram_declaration");
}

std::vector<Statement *> * PackageParser::visitSubprogram_statement_part(
		Ref<vhdlParser::Subprogram_statement_partContext> ctx) {
	// subprogram_statement_part
	// : ( sequential_statement )*
	// ;
	std::vector<Statement *> * statements = new std::vector<Statement*>();
	for (auto s : ctx->sequential_statement()) {
		statements->push_back(StatementParser::visitSequential_statement(s));
	}
	return statements;
}
