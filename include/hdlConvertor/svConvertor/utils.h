#pragma once

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/hdlAst/hdlOpType.h>

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
	static std::unique_ptr<hdlAst::iHdlExprItem> mkStringT();

	static std::unique_ptr<hdlAst::iHdlExprItem> mkIntT();
	// wire type is represented by wire id or call wire(range, signed)
	static std::unique_ptr<hdlAst::iHdlExprItem> mkWireT();
	static std::unique_ptr<hdlAst::iHdlExprItem> mkWireT(
			antlr4::ParserRuleContext *const ctx,
			std::unique_ptr<hdlAst::iHdlExprItem> range, SIGNING_VAL signed_);
	static std::unique_ptr<hdlAst::iHdlExprItem> mkWireT(
			antlr4::ParserRuleContext *const ctx,
			std::unique_ptr<hdlAst::iHdlExprItem> net_type,
			std::unique_ptr<hdlAst::iHdlExprItem> range, SIGNING_VAL signed_);
	static std::unique_ptr<hdlAst::iHdlExprItem> signing(SIGNING_VAL signing);
};

std::unique_ptr<hdlAst::iHdlExprItem> append_expr(
		antlr4::ParserRuleContext *const ctx,
		std::unique_ptr<hdlAst::iHdlExprItem> selected_name,
		hdlAst::HdlOpType operator_to_join_with,
		std::unique_ptr<hdlAst::iHdlExprItem> new_part);
std::unique_ptr<hdlAst::iHdlExprItem> reduce(
		std::vector<std::unique_ptr<hdlAst::iHdlExprItem>> &ops,
		hdlAst::HdlOpType op);

}
}
