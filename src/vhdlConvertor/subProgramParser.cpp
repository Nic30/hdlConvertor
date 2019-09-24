#include <hdlConvertor/vhdlConvertor/exprParser.h>
#include <hdlConvertor/vhdlConvertor/interfaceParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/statementParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramParser.h>

namespace hdlConvertor {
namespace vhdl {

using namespace hdlConvertor::hdlObjects;
using vhdlParser = vhdl_antlr::vhdlParser;

HdlFunctionDef * VhdlSubProgramParser::visitSubprogram_body(
		vhdlParser::Subprogram_bodyContext* ctx) {
	// subprogram_body :
	// subprogram_specification IS
	// subprogram_declarative_part
	// BEGIN
	// subprogram_statement_part
	// END ( subprogram_kind )? ( designator )? SEMI
	// ;
	HdlFunctionDef * f = visitSubprogram_specification(
			ctx->subprogram_specification());

	auto vs = VhdlSubProgramDeclarationParser::visitSubprogram_declarative_part(
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

HdlFunctionDef * VhdlSubProgramParser::visitSubprogram_specification(
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

HdlFunctionDef * VhdlSubProgramParser::visitProcedure_specification(
		vhdlParser::Procedure_specificationContext* ctx) {
	// procedure_specification
	// : PROCEDURE designator ( LPAREN formal_parameter_list RPAREN )?
	// ;
	auto designator = ctx->designator();
	iHdlExpr * returnT = NULL;
	bool isOperator = VhdlLiteralParser::isStrDesignator(designator);
	auto name = VhdlLiteralParser::visitDesignator(designator);

	auto fpl = ctx->formal_parameter_list();
	std::vector<HdlVariableDef*> * paramList = new std::vector<HdlVariableDef*>();
	if (fpl)
		paramList = visitFormal_parameter_list(fpl);

	return new HdlFunctionDef(name, isOperator, returnT, paramList);
}

HdlFunctionDef * VhdlSubProgramParser::visitFunction_specification(
		vhdlParser::Function_specificationContext* ctx) {
	// function_specification:
	//       ( PURE IMPURE )? FUNCTION designator
	//           subprogram_header
	//           ( ( PARAMETER )? LPAREN formal_parameter_list RPAREN )? RETURN type_mark
	// ;
	auto designator = ctx->designator();
	iHdlExpr * returnT = VhdlExprParser::visitType_mark(ctx->type_mark());
	assert(returnT);

	bool isOperator = VhdlLiteralParser::isStrDesignator(designator);
	auto name = VhdlLiteralParser::visitDesignator(designator);

	auto fpl = ctx->formal_parameter_list();
	std::vector<HdlVariableDef*> * paramList = new std::vector<HdlVariableDef*>();
	if (fpl)
		paramList = visitFormal_parameter_list(fpl);

	return new HdlFunctionDef(name, isOperator, returnT, paramList);
}

std::vector<HdlVariableDef*> * VhdlSubProgramParser::visitFormal_parameter_list(
		vhdlParser::Formal_parameter_listContext* ctx) {
	// formal_parameter_list
	// : interface_list
	// ;
	return VhdlInterfaceParser::visitInterface_list(ctx->interface_list());
}

std::vector<iHdlStatement *> * VhdlSubProgramParser::visitSubprogram_statement_part(
		vhdlParser::Subprogram_statement_partContext* ctx) {
	// subprogram_statement_part
	// : ( sequential_statement )*
	// ;
	std::vector<iHdlStatement *> * statements = new std::vector<iHdlStatement*>();
	for (auto s : ctx->sequential_statement()) {
		statements->push_back(VhdlStatementParser::visitSequential_statement(s));
	}
	return statements;
}

}
}
