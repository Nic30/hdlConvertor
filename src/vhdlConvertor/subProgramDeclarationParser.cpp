#include <hdlConvertor/createObject.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/vhdlConvertor/exprParser.h>
#include <hdlConvertor/vhdlConvertor/interfaceParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/variableParser.h>
#include <assert.h>

namespace hdlConvertor {
namespace vhdl {

using namespace hdlConvertor::hdlObjects;
using vhdlParser = vhdl_antlr::vhdlParser;

std::unique_ptr<hdlObjects::HdlFunctionDef> VhdlSubProgramDeclarationParser::visitSubprogram_declaration(
		vhdlParser::Subprogram_declarationContext *ctx) {
	// subprogram_declaration
	// : subprogram_specification SEMI
	// ;
	return visitSubprogram_specification(ctx->subprogram_specification());
}

std::unique_ptr<hdlObjects::HdlFunctionDef> VhdlSubProgramDeclarationParser::visitSubprogram_specification(
		vhdlParser::Subprogram_specificationContext *ctx) {
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

std::unique_ptr<hdlObjects::HdlFunctionDef> VhdlSubProgramDeclarationParser::visitProcedure_specification(
		vhdlParser::Procedure_specificationContext *ctx) {
	// procedure_specification
	// : PROCEDURE designator ( LPAREN formal_parameter_list RPAREN )?
	// ;
	auto designator = ctx->designator();
	bool isOperator = VhdlLiteralParser::isStrDesignator(designator);
	auto name = VhdlLiteralParser::visitDesignator(designator);

	auto fpl = ctx->formal_parameter_list();
	std::unique_ptr<std::vector<std::unique_ptr<HdlVariableDef>>> paramList;
	if (fpl)
		paramList = visitFormal_parameter_list(fpl);
	else
		paramList = std::make_unique<
				std::vector<std::unique_ptr<HdlVariableDef>>>();
	return create_object<HdlFunctionDef>(ctx, name, isOperator, nullptr,
			move(paramList));
}

std::unique_ptr<hdlObjects::HdlFunctionDef> VhdlSubProgramDeclarationParser::visitFunction_specification(
		vhdlParser::Function_specificationContext *ctx) {
	// function_specification
	// : ( PURE | IMPURE )? FUNCTION designator
	// ( LPAREN formal_parameter_list RPAREN )? RETURN subtype_indication
	// ;
	// function_specification:
	//       ( PURE IMPURE )? FUNCTION designator
	//           subprogram_header
	//           ( ( PARAMETER )? LPAREN formal_parameter_list RPAREN )? RETURN type_mark
	// ;

	auto designator = ctx->designator();
	auto returnT = VhdlExprParser::visitType_mark(ctx->type_mark());
	assert(returnT);

	bool isOperator = VhdlLiteralParser::isStrDesignator(designator);
	auto name = VhdlLiteralParser::visitDesignator(designator);

	auto fpl = ctx->formal_parameter_list();
	std::unique_ptr<std::vector<std::unique_ptr<HdlVariableDef>>> paramList;
	if (fpl)
		paramList = visitFormal_parameter_list(fpl);
	else
		paramList = std::make_unique<
				std::vector<std::unique_ptr<HdlVariableDef>>>();
	return create_object<HdlFunctionDef>(ctx, name, isOperator,
			std::move(returnT), std::move(paramList));
}

std::unique_ptr<std::vector<std::unique_ptr<HdlVariableDef>>> VhdlSubProgramDeclarationParser::visitFormal_parameter_list(
		vhdlParser::Formal_parameter_listContext *ctx) {
	// formal_parameter_list
	// : interface_list
	// ;
	return VhdlInterfaceParser::visitInterface_list(ctx->interface_list());
}

std::unique_ptr<std::vector<std::unique_ptr<HdlVariableDef>>> VhdlSubProgramDeclarationParser::visitSubprogram_declarative_item(
		vhdlParser::Subprogram_declarative_itemContext *ctx) {
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

	do {
		auto sp = ctx->subprogram_declaration();
		if (sp) {
			// SubProgramDeclarationParser::visitSubprogram_declaration(sp);
			NotImplementedLogger::print("PackageParser.subprogram_declaration",
					sp);
			break;
		}
		auto sb = ctx->subprogram_body();
		if (sb) {
			//SubProgramParser::visitSubprogram_body(sb);
			NotImplementedLogger::print("PackageParser.visitSubprogram_body",
					sb);
			break;
		}
		auto td = ctx->type_declaration();
		if (td) {
			NotImplementedLogger::print("PackageParser.visitType_declaration",
					td);
			break;
		}
		auto st = ctx->subtype_declaration();
		if (st) {
			//SubtypeDeclarationParser::visitSubtype_declaration(st);

			NotImplementedLogger::print(
					"PackageParser.visitSubtype_declaration", st);
			break;
		}
		auto constd = ctx->constant_declaration();
		if (constd) {
			// ConstantParser::visitConstant_declaration(constd);
			NotImplementedLogger::print(
					"PackageParser.visitConstant_declaration", constd);
			break;
		}
		auto vd = ctx->variable_declaration();
		if (vd) {
			return VhdlVariableParser::visitVariable_declaration(vd);
		}
		auto fd = ctx->file_declaration();
		if (fd) {
			NotImplementedLogger::print("PackageParser.visitFile_declaration",
					fd);
		}
		auto aliasd = ctx->alias_declaration();
		if (aliasd) {
			NotImplementedLogger::print("PackageParser.visitAlias_declaration",
					aliasd);
			break;
		}
		auto atrd = ctx->attribute_declaration();
		if (atrd) {
			NotImplementedLogger::print(
					"PackageParser.visitAttribute_declaration", atrd);
			break;
		}
		auto as = ctx->attribute_specification();
		if (as) {
			NotImplementedLogger::print(
					"PackageParser.visitAttribute_specification", as);
			break;
		}
		auto uc = ctx->use_clause();
		if (uc) {
			NotImplementedLogger::print("PackageParser.visitUse_clause", uc);
			break;
		}
		auto gtd = ctx->group_template_declaration();
		if (gtd) {
			NotImplementedLogger::print(
					"PackageParser.visitGroup_template_declaration", gtd);
			break;
		}
		auto gd = ctx->group_declaration();
		if (gd) {
			NotImplementedLogger::print("PackageParser.visitGroup_declaration",
					gd);
			break;
		}

	} while (0);

	NotImplementedLogger::print(
			"SubProgramParser.visitSubprogram_declarative_item", ctx);
	return std::make_unique<std::vector<std::unique_ptr<HdlVariableDef>>>();
}

}
}
