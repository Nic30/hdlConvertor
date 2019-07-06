#include <hdlConvertor/hdlObjects/statement_assign.h>
#include <stdexcept>

using namespace std;

namespace hdlConvertor {
namespace hdlObjects {

HdlAssignStm::HdlAssignStm(Expr * dst, Expr * src, bool _is_blocking) :
		Statement(StatementType::s_ASSIGNMENT) {
	if (dst == nullptr || src == nullptr) {
		// [note] this happens only if there is a bug in this library
		throw runtime_error("wrong assign initialisation");
	}
	exprs.push_back(dst);
	exprs.push_back(src);
	is_blocking = _is_blocking;
}

HdlControlledAssignStm::HdlControlledAssignStm(Expr* dst, Expr * src,
		Expr *time_delay, vector<Expr*> * event_delay, bool _is_blocking) :
		HdlAssignStm(dst, src, _is_blocking) {
	type = StatementType::s_CONTROLLED_ASSIGNMENT;
	exprs.push_back(time_delay);
	if (event_delay) {
		for (auto e : *event_delay) {
			exprs.push_back(e);
		}
		delete event_delay;
	}
}

}
}
