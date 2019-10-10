#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

using namespace std;

namespace hdlConvertor {
namespace hdlObjects {

HdlVariableDef::HdlVariableDef(const string &id, unique_ptr<iHdlExpr> _type,
		unique_ptr<iHdlExpr> val) :
		iHdlObj(), WithNameAndDoc(id), type(move(_type)), value(move(val)), is_latched(
				false), is_const(false), is_static(false), direction(
				HdlDirection::DIR_INTERNAL) {
}
HdlVariableDef::HdlVariableDef(const string &id, unique_ptr<iHdlExpr> _type,
		unique_ptr<iHdlExpr> val, HdlDirection _direction, bool _is_latched) :
		HdlVariableDef(id, move(_type), move(val)) {
	direction = _direction;
	is_latched = _is_latched;
}

HdlVariableDef::~HdlVariableDef() {
}

}
}
