#pragma once

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/hdlOperatorType.h>

namespace hdlConvertor {
namespace sv {

class Utils {
public:
	static hdlObjects::iHdlExpr* mkStringT();

	static hdlObjects::iHdlExpr* mkIntT();
	// wire type is represented by wire id or call wire(range, signed)
	static hdlObjects::iHdlExpr* mkWireT();
	static hdlObjects::iHdlExpr* mkWireT(hdlObjects::iHdlExpr *range,
			bool signed_);
	static bool is_signed(antlr4::ParserRuleContext *ctx);
	static bool is_reg(antlr4::ParserRuleContext *ctx);
};

hdlObjects::iHdlExpr* append_dot_separated_expr(
		hdlObjects::iHdlExpr *selected_name, hdlObjects::iHdlExpr *new_part);
hdlObjects::iHdlExpr* reduce(const std::vector<hdlObjects::iHdlExpr*> &ops,
		hdlObjects::HdlOperatorType op);

}
}
