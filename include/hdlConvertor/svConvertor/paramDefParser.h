#pragma once

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>

#include <hdlConvertor/svConvertor/commentParser.h>
#include <hdlConvertor/hdlAst/hdlIdDef.h>

namespace hdlConvertor {
namespace sv {

class VerParamDefParser {
	SVCommentParser &commentParser;
public:
	VerParamDefParser(SVCommentParser &commentParser);
	using sv2017Parser = sv2017_antlr::sv2017Parser;

	void visitParameter_port_list(sv2017Parser::Parameter_port_listContext *ctx,
			std::vector<std::unique_ptr<hdlAst::HdlIdDef>> &res);
	void visitParameter_port_declaration(
			sv2017Parser::Parameter_port_declarationContext *ctx,
			std::vector<std::unique_ptr<hdlAst::HdlIdDef>> &res);
	/*
	 * Automatically add type to a parameters defined in parameter list
	 * */
	void visitTyped_list_of_param_assignments(
			std::unique_ptr<hdlAst::iHdlExprItem> data_type,
			sv2017Parser::List_of_param_assignmentsContext *lpa,
			const std::string &doc,
			std::vector<std::unique_ptr<hdlAst::HdlIdDef>> &res);
	void visitList_of_param_assignments(
			sv2017Parser::List_of_param_assignmentsContext *ctx,
			std::vector<std::unique_ptr<hdlAst::HdlIdDef>> &res);
	void visitList_of_type_assignments(
			sv2017Parser::List_of_type_assignmentsContext *ctx,
			std::vector<std::unique_ptr<hdlAst::HdlIdDef>> &res);
	std::unique_ptr<hdlAst::HdlIdDef> visitParam_assignment(
			sv2017Parser::Param_assignmentContext *ctx);
	void visitParameter_declaration(
			sv2017Parser::Parameter_declarationContext *ctx,
			std::vector<std::unique_ptr<hdlAst::HdlIdDef>> &res);
	std::unique_ptr<hdlAst::iHdlExprItem> visitParam_expression(
			sv2017Parser::Param_expressionContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitConstant_param_expression(
			sv2017Parser::Constant_param_expressionContext *ctx);
	void visitLocal_parameter_declaration(
			sv2017Parser::Local_parameter_declarationContext *ctx,
			std::vector<std::unique_ptr<hdlAst::HdlIdDef>> &res);
};

}
}
