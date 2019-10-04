#include <hdlConvertor/svConvertor/utils.h>

#include <hdlConvertor/svConvertor/exprParser.h>
#include <hdlConvertor/hdlObjects/hdlValue.h>
#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Lexer.h>

namespace hdlConvertor {
namespace sv {

using sv2017Parser = sv2017_antlr::sv2017Parser;
using sv2017Lexer = sv2017_antlr::sv2017Lexer;
using namespace hdlConvertor::hdlObjects;

iHdlExpr* Utils::mkStringT() {
	return iHdlExpr::ID("__str__");
}

iHdlExpr* Utils::mkIntT() {
	return iHdlExpr::ID("integer");
}
iHdlExpr* Utils::mkWireT() {
	return iHdlExpr::ID("wire");
}
iHdlExpr* Utils::mkWireT(iHdlExpr *net_type, iHdlExpr *range, bool signed_) {
	std::vector<iHdlExpr*> operands = { range, iHdlExpr::INT(signed_ ? 1 : 0) };
	if (net_type == nullptr)
		net_type = mkWireT();
	return iHdlExpr::call(net_type, operands);
}
iHdlExpr* Utils::mkWireT(iHdlExpr *range, bool signed_) {
	return mkWireT(nullptr, range, signed_);
}

iHdlExpr* append_expr(iHdlExpr *selected_name,
		HdlOperatorType operator_to_join_with, iHdlExpr *new_part) {
	if (selected_name) {
		return new iHdlExpr(selected_name, operator_to_join_with, new_part);
	} else {
		return new_part;
	}
}
iHdlExpr* reduce(const std::vector<iHdlExpr*> &ops, HdlOperatorType op) {
	iHdlExpr *res = nullptr;
	for (auto p : ops) {
		if (res == nullptr)
			res = p;
		else
			res = new iHdlExpr(res, op, p);
	}
	return res;
}

}
}
