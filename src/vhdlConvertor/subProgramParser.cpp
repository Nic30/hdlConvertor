#include <hdlConvertor/vhdlConvertor/exprParser.h>
#include <hdlConvertor/vhdlConvertor/interfaceParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/statementParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramParser.h>

#include <hdlConvertor/createObject.h>

using namespace hdlConvertor::hdlObjects;
using vhdlParser = vhdl_antlr::vhdlParser;

namespace hdlConvertor {
namespace vhdl {

std::unique_ptr<HdlFunctionDef> VhdlSubProgramParser::visitSubprogram_body(
		vhdlParser::Subprogram_bodyContext *ctx) {
	// subprogram_body:
	//       subprogram_specification KW_IS
	//           ( subprogram_declarative_item )*
	//       KW_BEGIN
	//           ( sequential_statement )*
	//       KW_END ( subprogram_kind )? ( designator )? SEMI
	// ;
	auto f = visitSubprogram_specification(ctx->subprogram_specification());

	for (auto sd : ctx->subprogram_declarative_item()) {
		auto spdis =
				VhdlSubProgramDeclarationParser::visitSubprogram_declarative_item(
						sd);
		for (auto &spdi : *spdis)
			f->body.push_back(std::move(spdi));
	}
	for (auto s : ctx->sequential_statement()) {
		auto stm = VhdlStatementParser::visitSequential_statement(s);
		f->body.push_back(move(stm));
	}

	return f;
}

std::unique_ptr<HdlFunctionDef> VhdlSubProgramParser::visitSubprogram_specification(
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

std::unique_ptr<HdlFunctionDef> VhdlSubProgramParser::visitProcedure_specification(
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

	return create_object<HdlFunctionDef>(ctx, name, isOperator, nullptr, std::move(paramList));
}

std::unique_ptr<HdlFunctionDef> VhdlSubProgramParser::visitFunction_specification(
		vhdlParser::Function_specificationContext *ctx) {
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

	return create_object<HdlFunctionDef>(ctx, name, isOperator, std::move(returnT),
			std::move(paramList));
}

std::unique_ptr<std::vector<std::unique_ptr<HdlVariableDef>>> VhdlSubProgramParser::visitFormal_parameter_list(
		vhdlParser::Formal_parameter_listContext *ctx) {
	// formal_parameter_list
	// : interface_list
	// ;
	return VhdlInterfaceParser::visitInterface_list(ctx->interface_list());
}

}
}
