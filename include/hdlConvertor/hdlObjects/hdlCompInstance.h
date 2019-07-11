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
	iHdlExpr * name;
	iHdlExpr * entityName;
	std::vector<iHdlExpr*> genericMap;
	std::vector<iHdlExpr*> portMap;

	HdlCompInstance(iHdlExpr * name, iHdlExpr * _entityName);
	~HdlCompInstance();
};

}
}
