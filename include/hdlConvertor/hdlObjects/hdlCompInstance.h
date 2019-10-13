#pragma once
#include <vector>

#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/position.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>

namespace hdlConvertor {
namespace hdlObjects {

class HdlCompInstance: public WithDoc, public WithPos, public iHdlObj {
public:
	std::unique_ptr<iHdlExpr> name;
	std::unique_ptr<iHdlExpr> entityName;
	std::vector<std::unique_ptr<iHdlExpr>> genericMap;
	std::vector<std::unique_ptr<iHdlExpr>> portMap;

	HdlCompInstance(std::unique_ptr<iHdlExpr> name,
			std::unique_ptr<iHdlExpr> _entityName);
	virtual ~HdlCompInstance() override;
};

}
}
