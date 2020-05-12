#pragma once
#include <hdlConvertor/hdlAst/iHdlStatement.h>

namespace hdlConvertor {
namespace hdlAst {
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
	std::vector<std::unique_ptr<iHdlExprItem>> path;

	HdlStmImport(std::vector<std::unique_ptr<iHdlExprItem>> &_path);
	virtual ~HdlStmImport() override;
};

class HdlStmReturn: public iHdlStatement {
public:
	std::unique_ptr<iHdlExprItem> val;

	HdlStmReturn();
	HdlStmReturn(std::unique_ptr<iHdlExprItem> val);
	virtual ~HdlStmReturn() override;
};

class HdlStmWait: public iHdlStatement {
public:
	std::vector<std::unique_ptr<iHdlExprItem>> val;

	HdlStmWait();
	HdlStmWait(std::unique_ptr<iHdlExprItem> val);
	HdlStmWait(std::vector<std::unique_ptr<iHdlExprItem>> &val);
	virtual ~HdlStmWait() override;
};

}
}
