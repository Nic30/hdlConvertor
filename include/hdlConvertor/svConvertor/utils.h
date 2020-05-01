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

enum SIGNING_VAL {
	UNSIGNED = 0,
	SIGNED = 1,
	NO_SIGN,
};

class Utils {
public:
	static std::unique_ptr<hdlObjects::iHdlExprItem> mkStringT();

	static std::unique_ptr<hdlObjects::iHdlExprItem> mkIntT();
	// wire type is represented by wire id or call wire(range, signed)
	static std::unique_ptr<hdlObjects::iHdlExprItem> mkWireT();
	static std::unique_ptr<hdlObjects::iHdlExprItem> mkWireT(
			antlr4::ParserRuleContext *const ctx,
			std::unique_ptr<hdlObjects::iHdlExprItem> range, SIGNING_VAL signed_);
	static std::unique_ptr<hdlObjects::iHdlExprItem> mkWireT(
			antlr4::ParserRuleContext *const ctx,
			std::unique_ptr<hdlObjects::iHdlExprItem> net_type,
			std::unique_ptr<hdlObjects::iHdlExprItem> range, SIGNING_VAL signed_);
	static std::unique_ptr<hdlObjects::iHdlExprItem> signing(SIGNING_VAL signing);
};

std::unique_ptr<hdlObjects::iHdlExprItem> append_expr(
		antlr4::ParserRuleContext *const ctx,
		std::unique_ptr<hdlObjects::iHdlExprItem> selected_name,
		hdlObjects::HdlOperatorType operator_to_join_with,
		std::unique_ptr<hdlObjects::iHdlExprItem> new_part);
std::unique_ptr<hdlObjects::iHdlExprItem> reduce(
		std::vector<std::unique_ptr<hdlObjects::iHdlExprItem>> &ops,
		hdlObjects::HdlOperatorType op);

}
}
