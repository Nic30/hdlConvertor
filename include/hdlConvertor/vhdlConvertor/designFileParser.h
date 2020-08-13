#pragma once
#include <vector>

#include <hdlConvertor/baseHdlParser/baseHdlParser.h>
#include <hdlConvertor/hdlAst/hdlContext.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/hdlAst/iHdlStatement.h>
#include <hdlConvertor/hdlAst/iHdlStatement.h>
#include <hdlConvertor/vhdlConvertor/commentParser.h>
#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlDesignFileParser: public BaseHdlParser {
	VhdlCommentParser commentParser;
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	VhdlDesignFileParser(antlr4::TokenStream &tokens, hdlAst::HdlContext &ctx,
			bool _hierarchyOnly);
	void visitDesign_file(vhdlParser::Design_fileContext *ctx);
	void visitDesign_unit(vhdlParser::Design_unitContext *ctx);
	void visitLibrary_unit(vhdlParser::Library_unitContext *ctx);
	void visitSecondary_unit(vhdlParser::Secondary_unitContext *ctx);
	void visitContext_clause(vhdlParser::Context_clauseContext *ctx);
	void visitPrimary_unit(vhdlParser::Primary_unitContext *ctx);
	void visitContext_item(vhdlParser::Context_itemContext *ctx);
	void visitLibrary_clause(vhdlParser::Library_clauseContext *ctx);
	void visitUse_clause(vhdlParser::Use_clauseContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlObj>> &res);
};

}
}
