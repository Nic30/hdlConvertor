#include <hdlConvertor/hdlAst/hdlStmProcess.h>
#include <hdlConvertor/hdlAst/hdlStmBlock.h>

#include <hdlConvertor/createObject.h>

namespace hdlConvertor {
namespace hdlAst {

using namespace std;

HdlStmProcess::HdlStmProcess() :
		iHdlStatement(), trigger_constrain(HdlStmProcessTriggerConstrain::ALWAYS_NONE), body(
				create_object<HdlStmBlock>(nullptr)) {
}

HdlStmProcess::HdlStmProcess(
		unique_ptr<vector<unique_ptr<iHdlExprItem>>> _sensitivity) :
		iHdlStatement(), trigger_constrain(HdlStmProcessTriggerConstrain::ALWAYS_NONE), sensitivity_list(
				move(_sensitivity)), body(create_object<HdlStmBlock>(nullptr)) {
}
HdlStmProcess::HdlStmProcess(
		unique_ptr<vector<unique_ptr<iHdlExprItem>>> _sensitivity,
		unique_ptr<iHdlStatement> _body) :
		iHdlStatement(), trigger_constrain(HdlStmProcessTriggerConstrain::ALWAYS_NONE), sensitivity_list(
				move(_sensitivity)), body(move(_body)) {
}

HdlStmProcess::~HdlStmProcess() {
}

}
}
