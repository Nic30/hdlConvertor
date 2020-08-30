#pragma once
#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/hdlAst/hdlStmProcess.h>
#include <hdlConvertor/hdlAst/iHdlStatement.h>
#include <hdlConvertor/vhdlConvertor/baseVhdlParser.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlProcessParser : public BaseVhdlParser {
public:
	using BaseVhdlParser::BaseVhdlParser;
	using vhdlParser = vhdl_antlr::vhdlParser;

	std::unique_ptr<hdlAst::HdlStmProcess> visitProcess_statement(
			vhdlParser::Process_statementContext *ctx);
	void visitProcess_sensitivity_list(
			vhdlParser::Process_sensitivity_listContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlExprItem>> &sensitivity);
	void visitSensitivity_list(vhdlParser::Sensitivity_listContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlExprItem>> &sensitivity);
	void visitProcess_declarative_item(
			vhdlParser::Process_declarative_itemContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlObj>> &objs);
	void visitProcess_or_package_declarative_item(
			vhdlParser::Process_or_package_declarative_itemContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlObj>> &objs);
};

}
}
