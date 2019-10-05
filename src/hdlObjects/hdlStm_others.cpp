#include <hdlConvertor/hdlObjects/hdlStm_others.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlStmImport::HdlStmImport(std::vector<std::unique_ptr<iHdlExpr>> &_path) :
		iHdlStatement(), path(move(_path)) {
}

HdlStmImport::~HdlStmImport() {
}

HdlStmReturn::HdlStmReturn() :
		iHdlStatement() {
}

HdlStmReturn::HdlStmReturn(std::unique_ptr<iHdlExpr> _val) :
		iHdlStatement(), val(move(_val)) {
}

HdlStmReturn::~HdlStmReturn() {
}

HdlStmWait::HdlStmWait(std::unique_ptr<iHdlExpr> _val) :
		iHdlStatement() {
	val.push_back(move(_val));
}

HdlStmWait::HdlStmWait(std::vector<std::unique_ptr<iHdlExpr>> &_val) :
		iHdlStatement(), val(move(_val)) {
}

HdlStmWait::~HdlStmWait() {
}

}
}
