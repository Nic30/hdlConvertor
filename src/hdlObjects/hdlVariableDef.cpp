#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlVariableDef::HdlVariableDef(const std::string & id, iHdlExpr * _type,
		iHdlExpr * val) {
	name = id;
	type = _type;
	value = val;
	is_latched = false;
	is_const = false;
	direction = HdlDirection::DIR_INTERNAL;
}

HdlVariableDef::~HdlVariableDef() {
	if (value)
		delete value;
}

}
}
