#pragma once

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/svConvertor/commentParser.h>

#include <hdlConvertor/hdlAst/iHdlStatement.h>
#include <hdlConvertor/hdlAst/hdlStmFor.h>
#include <hdlConvertor/hdlAst/hdlStmExpr.h>
#include <hdlConvertor/hdlAst/hdlIdDef.h>

namespace hdlConvertor {
namespace sv {

class VerGenerateParser {
	SVCommentParser &commentParser;
	bool hierarchyOnly;
public:

	using sv2017Parser = sv2017_antlr::sv2017Parser;
	VerGenerateParser(SVCommentParser &commentParser, bool hierarchyOnly);
	void visitGenerate_region(sv2017Parser::Generate_regionContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlObj>> &res);
	void visitGenerate_item(sv2017Parser::Generate_itemContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlObj>> &res);
	void visitModule_or_generate_item(
			sv2017Parser::Module_or_generate_itemContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlObj>> &res,
			std::vector<std::unique_ptr<hdlAst::HdlIdDef>> &params);
	void visitGenvar_declaration(sv2017Parser::Genvar_declarationContext *ctx,
			std::vector<std::unique_ptr<hdlAst::HdlIdDef>> &res);
	std::unique_ptr<hdlAst::HdlIdDef> visitGenvar_initialization(
			sv2017Parser::Genvar_initializationContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitGenvar_expression(
			sv2017Parser::Genvar_expressionContext *ctx);
	std::unique_ptr<hdlAst::HdlStmExpr> visitGenvar_iteration(
			sv2017Parser::Genvar_iterationContext *ctx);
	std::unique_ptr<hdlAst::HdlStmFor> visitLoop_generate_construct(
			sv2017Parser::Loop_generate_constructContext *ctx);
	void visitGenerate_begin_end_block(
			sv2017Parser::Generate_begin_end_blockContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlObj>> &res);
	void visitConditional_generate_construct(
			sv2017Parser::Conditional_generate_constructContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlStatement>> &res);
	void visitCase_generate_construct(
			sv2017Parser::Case_generate_constructContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlStatement>> &res);
	void visitIf_generate_construct(
			sv2017Parser::If_generate_constructContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlStatement>> &res);
};

}
}
