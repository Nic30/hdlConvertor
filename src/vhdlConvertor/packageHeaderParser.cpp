#include "packageHeaderParser.h"

PackageHeaderParser::PackageHeaderParser(bool _hierarchyOnly) {
	ph = new PackageHeader();
	hierarchyOnly = _hierarchyOnly;
}

PackageHeader * PackageHeaderParser::visitPackage_declaration(
		vhdlParser::Package_declarationContext* ctx) {
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
void PackageHeaderParser::visitPackage_declarative_part(PackageHeader * ph,
		vhdlParser::Package_declarative_partContext* ctx) {
	// package_declarative_part
	// : ( package_declarative_item )*
	// ;
	for (auto i : ctx->package_declarative_item()) {
		visitPackage_declarative_item(i);
	}
}

void PackageHeaderParser::visitPackage_declarative_item(
		vhdlParser::Package_declarative_itemContext* ctx) {
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
		ph->function_headers.push_back(SubProgramDeclarationParser::visitSubprogram_declaration(sp));
		return;
	}
	auto td = ctx->type_declaration();
	if (td) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitType_declaration");
	}
	auto st = ctx->subtype_declaration();
	if (st) {
		auto _st = SubtypeDeclarationParser::visitSubtype_declaration(st);
		ph->subtype_headers.push_back(_st);
		return;	
	}
	auto constd = ctx->constant_declaration();
	if (constd) {
		auto constants = ConstantParser::visitConstant_declaration(constd);
		for (auto c : *constants) {
			ph->constants.push_back(c);
		}
		delete constants;
		return;	
	}
	auto sd = ctx->signal_declaration();
	if (sd) {
		auto signals = SignalParser::visitSignal_declaration(sd);
		for (auto s : *signals) {
			ph->signals.push_back(s);
		}
		delete signals;
		return;	
	}
	auto vd = ctx->variable_declaration();
	if (vd) {
		auto variables = VariableParser::visitVariable_declaration(vd);
		for (auto v : *variables) {
			ph->variables.push_back(v);
		}
		delete variables;
        return;  
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
		vhdlParser::Component_declarationContext* ctx) {
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
