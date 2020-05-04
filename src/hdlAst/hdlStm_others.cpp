#include <hdlConvertor/hdlAst/hdlStm_others.h>

namespace hdlConvertor {
namespace hdlAst {

HdlStmImport::HdlStmImport(std::vector<std::unique_ptr<iHdlExprItem>> &_path) :
		iHdlStatement(), path(move(_path)) {
}

HdlStmImport::~HdlStmImport() {
}

HdlStmReturn::HdlStmReturn() :
		iHdlStatement() {
}

HdlStmReturn::HdlStmReturn(std::unique_ptr<iHdlExprItem> _val) :
		iHdlStatement(), val(move(_val)) {
}

HdlStmReturn::~HdlStmReturn() {
}
HdlStmWait::HdlStmWait() :
		iHdlStatement() {
}
HdlStmWait::HdlStmWait(std::unique_ptr<iHdlExprItem> _val) :
		iHdlStatement() {
	val.push_back(move(_val));
}

HdlStmWait::HdlStmWait(std::vector<std::unique_ptr<iHdlExprItem>> &_val) :
		iHdlStatement(), val(move(_val)) {
}

HdlStmWait::~HdlStmWait() {
}

}
}
