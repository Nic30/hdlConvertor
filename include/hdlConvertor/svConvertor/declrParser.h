#pragma once

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/svConvertor/baseSvParser.h>
#include <hdlConvertor/hdlAst/hdlIdDef.h>
#include <hdlConvertor/hdlAst/iHdlStatement.h>
#include <hdlConvertor/hdlAst/iHdlStatement.h>
#include <hdlConvertor/hdlAst/hdlStm_others.h>


namespace hdlConvertor {
namespace sv {

/*
 * Parser of other SystemVerilog declarations
 * */
class VerDeclrParser: public BaseSvParser {
public:
	using BaseSvParser::BaseSvParser;
	using sv2017Parser = sv2017_antlr::sv2017Parser;

	void visitData_declaration(sv2017Parser::Data_declarationContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlObj>> &res);
	void visitList_of_variable_decl_assignments(
			sv2017Parser::List_of_variable_decl_assignmentsContext *ctx,
			std::unique_ptr<hdlAst::iHdlExprItem> base_type,
			std::vector<std::unique_ptr<hdlAst::HdlIdDef>> &res);
	std::unique_ptr<hdlAst::HdlStmImport> visitPackage_import_declaration(
			sv2017Parser::Package_import_declarationContext *ctx);
	std::unique_ptr<hdlAst::HdlIdDef> visitType_declaration(
			sv2017Parser::Type_declarationContext *ctx);
	void visitNet_type_declaration(
			sv2017Parser::Net_type_declarationContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlObj>> &res);

};

}
}
