#include <hdlConvertor/hdlObjects/hdlStmAssign.h>
#include <stdexcept>

namespace hdlConvertor {
namespace hdlObjects {

using namespace std;

HdlStmAssign::HdlStmAssign(iHdlExpr * dst, iHdlExpr * src, bool _is_blocking) :
		HdlStmAssign(dst, src, nullptr, nullptr, _is_blocking) {

}

HdlStmAssign::HdlStmAssign(iHdlExpr* dst, iHdlExpr * src, iHdlExpr *time_delay,
		vector<iHdlExpr*> * event_delay, bool _is_blocking) :
		iHdlStatement(StatementType::s_ASSIGNMENT) {
	if (dst == nullptr || src == nullptr) {
		// [note] this happens only if there is a bug in this library
		throw runtime_error("wrong assign initialisation");
	}
	exprs.push_back(dst);
	exprs.push_back(src);
	exprs.push_back(time_delay);
	if (event_delay) {
		for (auto e : *event_delay) {
			exprs.push_back(e);
		}
		delete event_delay;
	}
	is_blocking = _is_blocking;
}

}
}
