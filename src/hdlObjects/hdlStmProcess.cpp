#include <hdlConvertor/hdlObjects/hdlStmProcess.h>
#include <hdlConvertor/hdlObjects/hdlStmBlock.h>

using namespace std;

namespace hdlConvertor {
namespace hdlObjects {

HdlStmProcess::HdlStmProcess() :
		iHdlStatement(), body(make_unique<HdlStmBlock>()) {
}

HdlStmProcess::HdlStmProcess(
		unique_ptr<vector<unique_ptr<iHdlExpr>>> _sensitivity) :
		iHdlStatement(), sensitivity_list(move(_sensitivity)), body(
				make_unique<HdlStmBlock>()) {
}
HdlStmProcess::HdlStmProcess(
		unique_ptr<vector<unique_ptr<iHdlExpr>>> _sensitivity,
		unique_ptr<iHdlStatement> _body) :
		iHdlStatement(), sensitivity_list(move(_sensitivity)), body(move(_body)) {
}

HdlStmProcess::~HdlStmProcess() {
}

}
}
