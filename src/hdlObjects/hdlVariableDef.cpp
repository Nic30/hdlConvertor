#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlVariableDef::HdlVariableDef(const std::string &id, iHdlExpr *_type,
		iHdlExpr *val) :
		WithNameAndDoc(id), type(_type), value(val), is_latched(false), is_const(false), is_static(
				false), direction(HdlDirection::DIR_INTERNAL) {
}
HdlVariableDef::HdlVariableDef(const std::string &id, iHdlExpr *_type,
		iHdlExpr *val, HdlDirection _direction, bool _is_latched) :
		HdlVariableDef(id, _type, val) {
	direction = _direction;
	is_latched = _is_latched;
}

HdlVariableDef::~HdlVariableDef() {
	if (value)
		delete value;
}

}
}
