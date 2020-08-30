#include <hdlConvertor/createObject.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/vhdlConvertor/constantParser.h>
#include <hdlConvertor/vhdlConvertor/exprParser.h>
#include <hdlConvertor/vhdlConvertor/interfaceParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramParser.h>
#include <hdlConvertor/vhdlConvertor/typeDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/variableParser.h>

#include <assert.h>

namespace hdlConvertor {
namespace vhdl {

using namespace hdlConvertor::hdlAst;
using vhdlParser = vhdl_antlr::vhdlParser;

std::unique_ptr<hdlAst::HdlFunctionDef> VhdlSubProgramDeclarationParser::visitSubprogram_declaration(
		vhdlParser::Subprogram_declarationContext *ctx) {
	// subprogram_declaration
	// : subprogram_specification SEMI
	// ;
	return visitSubprogram_specification(ctx->subprogram_specification());
}

std::unique_ptr<hdlAst::HdlFunctionDef> VhdlSubProgramDeclarationParser::visitSubprogram_specification(
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

std::unique_ptr<hdlAst::HdlFunctionDef> VhdlSubProgramDeclarationParser::visitProcedure_specification(
		vhdlParser::Procedure_specificationContext *ctx) {
	// procedure_specification
	// : PROCEDURE designator ( LPAREN formal_parameter_list RPAREN )?
	// ;
	auto designator = ctx->designator();
	bool isOperator = VhdlLiteralParser::isStrDesignator(designator);
	auto name = VhdlLiteralParser::visitDesignator(designator);

	auto fpl = ctx->formal_parameter_list();
	std::unique_ptr<std::vector<std::unique_ptr<HdlIdDef>>> paramList;
	if (fpl)
		paramList = visitFormal_parameter_list(fpl);
	else
		paramList = std::make_unique<std::vector<std::unique_ptr<HdlIdDef>>>();
	return create_object<HdlFunctionDef>(ctx, name, isOperator, nullptr,
			move(paramList));
}

std::unique_ptr<hdlAst::HdlFunctionDef> VhdlSubProgramDeclarationParser::visitFunction_specification(
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
	std::unique_ptr<std::vector<std::unique_ptr<HdlIdDef>>> paramList;
	if (fpl)
		paramList = visitFormal_parameter_list(fpl);
	else
		paramList = std::make_unique<std::vector<std::unique_ptr<HdlIdDef>>>();
	return create_object<HdlFunctionDef>(ctx, name, isOperator,
			std::move(returnT), std::move(paramList));
}

std::unique_ptr<std::vector<std::unique_ptr<HdlIdDef>>> VhdlSubProgramDeclarationParser::visitFormal_parameter_list(
		vhdlParser::Formal_parameter_listContext *ctx) {
	// formal_parameter_list
	// : interface_list
	// ;
	return VhdlInterfaceParser::visitInterface_list(ctx->interface_list());
}

template<typename TO, typename FROM>
std::unique_ptr<TO> static_unique_pointer_cast (std::unique_ptr<FROM>&& old){
    return std::unique_ptr<TO>{static_cast<TO*>(old.release())};
    //conversion: unique_ptr<FROM>->FROM*->TO*->unique_ptr<TO>
}


}
}
