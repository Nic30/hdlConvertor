#pragma once
#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/hdlAst/hdlStmProcess.h>
#include <hdlConvertor/hdlAst/iHdlStatement.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlProcessParser {

public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::unique_ptr<hdlAst::HdlStmProcess> visitProcess_statement(
			vhdlParser::Process_statementContext *ctx);
	static void visitProcess_sensitivity_list(
			vhdlParser::Process_sensitivity_listContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlExprItem>> &sensitivity);
	static void visitSensitivity_list(vhdlParser::Sensitivity_listContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlExprItem>> &sensitivity);
	static void visitProcess_declarative_item(
			vhdlParser::Process_declarative_itemContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlObj>> &objs);
};

}
}
