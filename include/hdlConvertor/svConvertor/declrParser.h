#pragma once

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/svConvertor/commentParser.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace sv {

/*
 * Parser of other SystemVerilog declarations
 * */
class VerDeclrParser {
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;
	SVCommentParser &commentParser;

	VerDeclrParser(SVCommentParser &commentParser);
	void visitData_declaration(sv2017Parser::Data_declarationContext *ctx,
			std::vector<std::unique_ptr<hdlObjects::iHdlObj>> &res);
	void visitList_of_variable_decl_assignments(
			sv2017Parser::List_of_variable_decl_assignmentsContext *ctx,
			std::unique_ptr<hdlObjects::iHdlExpr> base_type,
			std::vector<std::unique_ptr<hdlObjects::HdlVariableDef>> &res);
	std::unique_ptr<hdlObjects::HdlVariableDef> visitType_declaration(
			sv2017Parser::Type_declarationContext *ctx);
	void visitNet_type_declaration(
			sv2017Parser::Net_type_declarationContext *ctx,
			std::vector<std::unique_ptr<hdlObjects::iHdlObj>> &res);

};

}
}
