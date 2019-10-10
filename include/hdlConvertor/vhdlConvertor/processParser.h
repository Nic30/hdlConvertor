#pragma once
#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/hdlStmProcess.h>
#include <hdlConvertor/hdlObjects/iHdlStatement.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlProcessParser {

public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::unique_ptr<hdlObjects::HdlStmProcess> visitProcess_statement(
			vhdlParser::Process_statementContext *ctx);
	static void visitProcess_sensitivity_list(
			vhdlParser::Process_sensitivity_listContext *ctx,
			std::vector<std::unique_ptr<hdlObjects::iHdlExpr>> &sensitivity);
	static void visitSensitivity_list(vhdlParser::Sensitivity_listContext *ctx,
			std::vector<std::unique_ptr<hdlObjects::iHdlExpr>> &sensitivity);
	static void visitProcess_declarative_item(
			vhdlParser::Process_declarative_itemContext *ctx,
			std::vector<std::unique_ptr<hdlObjects::iHdlObj>> &objs);
};

}
}
