#pragma once
#include <vector>

#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>
#include <hdlConvertor/hdlObjects/codePosition.h>

namespace hdlConvertor {
namespace hdlObjects {

class HdlCompInstance: public WithNameAndDoc, public iHdlObj {
public:
	std::unique_ptr<iHdlExpr> module_name;
	std::vector<std::unique_ptr<iHdlExpr>> genericMap;
	std::vector<std::unique_ptr<iHdlExpr>> portMap;

	HdlCompInstance(const std::string &name,
			std::unique_ptr<iHdlExpr> _module_name);
	virtual ~HdlCompInstance() override;
};

}
}
