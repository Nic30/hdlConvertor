#pragma once
#include <hdlConvertor/hdlObjects/iHdlStatement.h>

namespace hdlConvertor {
namespace hdlObjects {
/*
 * HDL AST node for loop-control statements
 * */
class HdlStmBreak: public iHdlStatement {
};
class HdlStmContinue: public iHdlStatement {
};

/*
 * HDL AST node for nop statement
 * */
class HdlStmNop: public iHdlStatement {
};

class HdlStmImport: public iHdlStatement {
public:
	std::vector<std::unique_ptr<iHdlExpr>> path;

	HdlStmImport(std::vector<std::unique_ptr<iHdlExpr>> &_path);
	virtual ~HdlStmImport() override;
};

class HdlStmReturn: public iHdlStatement {
public:
	std::unique_ptr<iHdlExpr> val;

	HdlStmReturn();
	HdlStmReturn(std::unique_ptr<iHdlExpr> val);
	virtual ~HdlStmReturn() override;
};

class HdlStmWait: public iHdlStatement {
public:
	std::vector<std::unique_ptr<iHdlExpr>> val;

	HdlStmWait(std::unique_ptr<iHdlExpr> val);
	HdlStmWait(std::vector<std::unique_ptr<iHdlExpr>> &val);
	virtual ~HdlStmWait() override;
};

}
}
