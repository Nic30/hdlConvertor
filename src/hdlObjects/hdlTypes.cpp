#include <hdlConvertor/hdlObjects/hdlTypes.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlClassDef::HdlClassDef() :
		type(HdlClassType::hdl_class), is_packed(false), is_virtual(false) {
}
HdlClassDef::HdlClassDef(const HdlClassDef &other) :
		type(other.type), is_packed(other.is_packed), is_virtual(
				other.is_virtual) {
	throw std::runtime_error("HdlClassDef copy constructor not implemented");
}

iHdlExprItem* HdlClassDef::clone() const {
	return new HdlClassDef(*this);
}

HdlEnumDef::HdlEnumDef() {
}
HdlEnumDef::HdlEnumDef(const HdlEnumDef &other) {
	for (auto & member : other.values) {
		std::unique_ptr<std::string> k = nullptr;
		std::unique_ptr<iHdlExprItem> v = nullptr;
		if (member.first) {
			k = std::make_unique<std::string>(*member.first);
		}
		if (member.second) {
			v = member.second->clone_uniq();
		}
		values.push_back( { move(k), move(v) });
	}
}
iHdlExprItem* HdlEnumDef::clone() const {
	return new HdlEnumDef(*this);
}

}
}
