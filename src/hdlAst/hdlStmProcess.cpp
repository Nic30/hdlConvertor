#include <hdlConvertor/hdlAst/hdlStmProcess.h>
#include <hdlConvertor/hdlAst/hdlStmBlock.h>

#include <hdlConvertor/createObject.h>

using namespace std;

namespace hdlConvertor {
namespace hdlAst {

HdlStmProcess::HdlStmProcess() :
		iHdlStatement(), body(create_object<HdlStmBlock>(nullptr)) {
}

HdlStmProcess::HdlStmProcess(
		unique_ptr<vector<unique_ptr<iHdlExprItem>>> _sensitivity) :
		iHdlStatement(), sensitivity_list(move(_sensitivity)), body(
				create_object<HdlStmBlock>(nullptr)) {
}
HdlStmProcess::HdlStmProcess(
		unique_ptr<vector<unique_ptr<iHdlExprItem>>> _sensitivity,
		unique_ptr<iHdlStatement> _body) :
		iHdlStatement(), sensitivity_list(move(_sensitivity)), body(move(_body)) {
}

HdlStmProcess::~HdlStmProcess() {
}

}
}
