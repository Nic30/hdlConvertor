#pragma once
#include <vector>

#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>
#include <hdlConvertor/hdlObjects/codePosition.h>

namespace hdlConvertor {
namespace hdlObjects {

class HdlCompInstance: public WithDoc, public WithPos, public iHdlObj {
public:
	std::unique_ptr<iHdlExprItem> name;
	std::unique_ptr<iHdlExprItem> module_name;
	std::vector<std::unique_ptr<iHdlExprItem>> genericMap;
	std::vector<std::unique_ptr<iHdlExprItem>> portMap;

	HdlCompInstance(std::unique_ptr<iHdlExprItem> name,
			std::unique_ptr<iHdlExprItem> _module_name);
	virtual ~HdlCompInstance() override;
};

}
}
