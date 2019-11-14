#pragma once

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/hdlOperatorType.h>

namespace antlr4
{
	class ParserRuleContext;
}

namespace hdlConvertor {
namespace sv {

class Utils {
public:
	static std::unique_ptr<hdlObjects::iHdlExpr> mkStringT();

	static std::unique_ptr<hdlObjects::iHdlExpr> mkIntT();
	// wire type is represented by wire id or call wire(range, signed)
	static std::unique_ptr<hdlObjects::iHdlExpr> mkWireT();
	static std::unique_ptr<hdlObjects::iHdlExpr> mkWireT(
			antlr4::ParserRuleContext *const ctx,
			std::unique_ptr<hdlObjects::iHdlExpr> range, bool signed_);
	static std::unique_ptr<hdlObjects::iHdlExpr> mkWireT(
			antlr4::ParserRuleContext *const ctx,
			std::unique_ptr<hdlObjects::iHdlExpr> net_type,
			std::unique_ptr<hdlObjects::iHdlExpr> range, bool signed_);
};

std::unique_ptr<hdlObjects::iHdlExpr> append_expr(
		antlr4::ParserRuleContext *const ctx,
		std::unique_ptr<hdlObjects::iHdlExpr> selected_name,
		hdlObjects::HdlOperatorType operator_to_join_with,
		std::unique_ptr<hdlObjects::iHdlExpr> new_part);
std::unique_ptr<hdlObjects::iHdlExpr> reduce(
		std::vector<std::unique_ptr<hdlObjects::iHdlExpr>> &ops,
		hdlObjects::HdlOperatorType op);

}
}
