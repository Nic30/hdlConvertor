#pragma once
#include <vector>

#include <hdlConvertor/hdlAst/named.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/hdlAst/iHdlObj.h>
#include <hdlConvertor/hdlAst/codePosition.h>

namespace hdlConvertor {
namespace hdlAst {

class HdlCompInst: public WithDoc, public WithPos, public iHdlObj {
public:
	std::unique_ptr<iHdlExprItem> name;
	std::unique_ptr<iHdlExprItem> module_name;
	std::vector<std::unique_ptr<iHdlExprItem>> genericMap;
	std::vector<std::unique_ptr<iHdlExprItem>> portMap;

	HdlCompInst(std::unique_ptr<iHdlExprItem> name,
			std::unique_ptr<iHdlExprItem> _module_name);
	virtual ~HdlCompInst() override;
};

}
}
