#include "subProgramDeclarationParser.h"
#include "literalParser.h"
#include "exprParser.h"
#include "notImplementedLogger.h"
#include "interfaceParser.h"
#include "variableParser.h"

namespace hdlConvertor {
namespace vhdl {

using namespace hdlConvertor::hdlObjects;
using vhdlParser = vhdl_antlr::vhdlParser;


Function * SubProgramDeclarationParser::visitSubprogram_declaration(
		vhdlParser::Subprogram_declarationContext* ctx) {
	// subprogram_declaration
	// : subprogram_specification SEMI
	// ;
	return visitSubprogram_specification(ctx->subprogram_specification());
}

Function * SubProgramDeclarationParser::visitSubprogram_specification(
		vhdlParser::Subprogram_specificationContext* ctx) {
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

Function * SubProgramDeclarationParser::visitProcedure_specification(
		vhdlParser::Procedure_specificationContext* ctx) {
	// procedure_specification
	// : PROCEDURE designator ( LPAREN formal_parameter_list RPAREN )?
	// ;
	auto designator = ctx->designator();
	Expr * returnT = NULL;
	bool isOperator = LiteralParser::isStrDesignator(designator);
	char * name = LiteralParser::visitDesignator(designator);

	auto fpl = ctx->formal_parameter_list();
	std::vector<Variable*> * paramList = new std::vector<Variable*>();
	if (fpl)
		paramList = visitFormal_parameter_list(fpl);

	return new Function(name, isOperator, returnT, paramList);
}

Function * SubProgramDeclarationParser::visitFunction_specification(
		vhdlParser::Function_specificationContext* ctx) {
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

	auto fpl = ctx->formal_parameter_list();
	std::vector<Variable*> * paramList = new std::vector<Variable*>();
	if (fpl)
		paramList = visitFormal_parameter_list(fpl);

	return new Function(name, isOperator, returnT, paramList);
}

std::vector<Variable*> * SubProgramDeclarationParser::visitFormal_parameter_list(
		vhdlParser::Formal_parameter_listContext* ctx) {
	// formal_parameter_list
	// : interface_list
	// ;
	return InterfaceParser::visitInterface_list(ctx->interface_list());
}

std::vector<Variable*>* SubProgramDeclarationParser::visitSubprogram_declarative_part(
		vhdlParser::Subprogram_declarative_partContext* ctx) {
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

std::vector<Variable*>* SubProgramDeclarationParser::visitSubprogram_declarative_item(
		vhdlParser::Subprogram_declarative_itemContext* ctx) {
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

auto sp = ctx->subprogram_declaration();
	if (sp) {
		// SubProgramDeclarationParser::visitSubprogram_declaration(sp);
		NotImplementedLogger::print(
				"PackageParser.subprogram_declaration");
	}
    auto sb = ctx->subprogram_body();
	if (sb) {
		//SubProgramParser::visitSubprogram_body(sb);
		NotImplementedLogger::print(
				"PackageParser.visitSubprogram_body");
	}
    auto td = ctx->type_declaration();
	if (td) {
		NotImplementedLogger::print(
				"PackageParser.visitType_declaration");
	}
    auto st = ctx->subtype_declaration();
	if (st) {
		//SubtypeDeclarationParser::visitSubtype_declaration(st);

		NotImplementedLogger::print(
				"PackageParser.visitSubtype_declaration");
	}
    auto constd = ctx->constant_declaration();
	if (constd) {
		// ConstantParser::visitConstant_declaration(constd);
		NotImplementedLogger::print(
				"PackageParser.visitConstant_declaration");
	}
	auto vd = ctx->variable_declaration();
	if (vd) {
		return VariableParser::visitVariable_declaration(vd);
	}
	auto fd = ctx->file_declaration();
	if (fd) {
		NotImplementedLogger::print(
				"PackageParser.visitFile_declaration");
	}
	auto aliasd = ctx->alias_declaration();
	if (aliasd) {
		NotImplementedLogger::print(
				"PackageParser.visitAlias_declaration");
	}
    auto atrd = ctx->attribute_declaration();
	if (atrd) {
		NotImplementedLogger::print(
				"PackageParser.visitAttribute_declaration");
	}
	auto as = ctx->attribute_specification();
	if (as) {
		NotImplementedLogger::print(
				"PackageParser.visitAttribute_specification");
	}
    auto uc = ctx->use_clause();
	if (uc) {
		NotImplementedLogger::print("PackageParser.visitUse_clause");
	}
	auto gtd = ctx->group_template_declaration();
	if (gtd) {
		NotImplementedLogger::print(
				"PackageParser.visitGroup_template_declaration");
	}
	auto gd = ctx->group_declaration();
	if (gd) {
		NotImplementedLogger::print(
				"PackageParser.visitGroup_declaration");
	}

	NotImplementedLogger::print(
			"SubProgramParser.visitSubprogram_declarative_item");
	return new std::vector<Variable*>();
}

}
}
