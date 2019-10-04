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
	static hdlObjects::iHdlExpr* mkWireT(hdlObjects::iHdlExpr *net_type,
			hdlObjects::iHdlExpr *range, bool signed_);
};

hdlObjects::iHdlExpr* append_expr(hdlObjects::iHdlExpr *selected_name,
		hdlObjects::HdlOperatorType operator_to_join_with,
		hdlObjects::iHdlExpr *new_part);
hdlObjects::iHdlExpr* reduce(const std::vector<hdlObjects::iHdlExpr*> &ops,
		hdlObjects::HdlOperatorType op);

}
}
