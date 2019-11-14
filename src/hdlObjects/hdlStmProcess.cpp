#include <hdlConvertor/hdlObjects/hdlStmProcess.h>
#include <hdlConvertor/hdlObjects/hdlStmBlock.h>

#include <hdlConvertor/createObject.h>

using namespace std;

namespace hdlConvertor {
namespace hdlObjects {

HdlStmProcess::HdlStmProcess() :
		iHdlStatement(), body(create_object<HdlStmBlock>(nullptr)) {
}

HdlStmProcess::HdlStmProcess(
		unique_ptr<vector<unique_ptr<iHdlExpr>>> _sensitivity) :
		iHdlStatement(), sensitivity_list(move(_sensitivity)), body(
				create_object<HdlStmBlock>(nullptr)) {
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
