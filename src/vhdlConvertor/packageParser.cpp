#include "packageParser.h"

PackageParser::PackageParser(bool _hierarchyOnly) {
	hierarchyOnly = _hierarchyOnly;
	p = new Package();
}
Package * PackageParser::visitPackage_body(
		vhdlParser::Package_bodyContext* ctx) {
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
		vhdlParser::Package_body_declarative_partContext* ctx) {
	// package_body_declarative_part
	// : ( package_body_declarative_item )*
	// ;
	auto pbdi = ctx->package_body_declarative_item();
	for (auto i : pbdi) {
		visitPackage_body_declarative_item(i);
	}
}
void PackageParser::visitPackage_body_declarative_item(
		vhdlParser::Package_body_declarative_itemContext* ctx) {
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
    auto sp = ctx->subprogram_declaration();
	if (sp) {
		p->function_headers.push_back(SubProgramDeclarationParser::visitSubprogram_declaration(sp));
        return;
	}
    auto sb = ctx->subprogram_body();
	if (sb) {
		// TODO: implement
		//Function * f = SubProgramParser::visitSubprogram_body(sb);
		//p->functions.push_back(f);
		return;
	}
    auto td = ctx->type_declaration();
	if (td) {
		NotImplementedLogger::print(
				"PackageParser.visitType_declaration");
        return;        
	}
    auto st = ctx->subtype_declaration();
	if (st) {
		auto _st = SubtypeDeclarationParser::visitSubtype_declaration(st);
		p->subtype_headers.push_back(_st);
		return;	       
	}
    auto constd = ctx->constant_declaration();
	if (constd) {
		auto constants = ConstantParser::visitConstant_declaration(constd);
		for (auto c : *constants) {
			p->constants.push_back(c);
		}
		delete constants;
        return;
	}    
	auto vd = ctx->variable_declaration();
	if (vd) {
		auto variables = VariableParser::visitVariable_declaration(vd);
		for (auto v : *variables) {
			p->variables.push_back(v);
		}
		delete variables;
        return;        
	}
	auto fd = ctx->file_declaration();
	if (fd) {
		NotImplementedLogger::print(
				"PackageParser.visitFile_declaration");
        return;        
	}
	auto aliasd = ctx->alias_declaration();
	if (aliasd) {
		NotImplementedLogger::print(
				"PackageParser.visitAlias_declaration");
        return;        
	}
    auto uc = ctx->use_clause();
	if (uc) {
		NotImplementedLogger::print("PackageParser.visitUse_clause");
        return;
	}
	auto gtd = ctx->group_template_declaration();
	if (gtd) {
		NotImplementedLogger::print(
				"PackageParser.visitGroup_template_declaration");
        return;        
	}
	auto gd = ctx->group_declaration();
	if (gd) {
		NotImplementedLogger::print(
				"PackageParser.visitGroup_declaration");
        return;        
	}
	NotImplementedLogger::print(
			"PackageParser.visitProcess_declarative_item");
	return;
}