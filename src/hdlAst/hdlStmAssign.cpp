#include <hdlConvertor/hdlAst/hdlStmAssign.h>
#include <stdexcept>

using namespace std;

namespace hdlConvertor {
namespace hdlAst {

HdlStmAssign::HdlStmAssign(std::unique_ptr<iHdlExprItem> _dst,
		std::unique_ptr<iHdlExprItem> _src, bool _is_blocking) :
		HdlStmAssign(move(_dst), move(_src), nullptr, nullptr, _is_blocking) {
}

HdlStmAssign::HdlStmAssign(std::unique_ptr<iHdlExprItem> _dst,
		std::unique_ptr<iHdlExprItem> _src, std::unique_ptr<iHdlExprItem> _time_delay,
		std::unique_ptr<vector<std::unique_ptr<iHdlExprItem>>> _event_delay,
		bool _is_blocking) :
		iHdlStatement(), dst(move(_dst)), src(move(_src)), time_delay(
				move(_time_delay)), event_delay(move(_event_delay)), is_blocking(
				_is_blocking) {
	if (dst == nullptr || src == nullptr) {
		// [note] this happens only if there is a bug in this library
		throw runtime_error("wrong assign initialization");
	}
}

HdlStmAssign::~HdlStmAssign() {
}

}
}
