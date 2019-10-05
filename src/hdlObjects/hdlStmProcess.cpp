#include <hdlConvertor/hdlObjects/hdlStmProcess.h>

using namespace std;

namespace hdlConvertor {
namespace hdlObjects {

HdlStmProcess::HdlStmProcess() :
		iHdlStatement() {
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
