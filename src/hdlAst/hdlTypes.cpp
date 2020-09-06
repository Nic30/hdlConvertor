#include <hdlConvertor/hdlAst/hdlTypes.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/hdlAst/hdlIdDef.h>

namespace hdlConvertor {
namespace hdlAst {

static const char *const HdlClassType_toStr[HdlClassType::INTERFACE + 1] = {
		"CLASS", "STRUCT", "UNION", "INTERFACE", };

const char* HdlClassType_toString(HdlClassType ct) {
	if (ct > HdlClassType::INTERFACE)
		throw std::runtime_error("Invalid HdlClassType value");
	return HdlClassType_toStr[ct];
}

HdlClassDef::HdlClassDef() :
		type(HdlClassType::CLASS), is_packed(false), is_virtual(false) {
}
HdlClassDef::HdlClassDef(const HdlClassDef &other) :
		type(other.type), is_packed(other.is_packed), is_virtual(
				other.is_virtual) {
	throw std::runtime_error("HdlClassDef copy constructor not implemented");
}

iHdlExprItem* HdlClassDef::clone() const {
	return new HdlClassDef(*this);
}

HdlPhysicalDef::HdlPhysicalDef() {
}
HdlPhysicalDef::HdlPhysicalDef(const HdlPhysicalDef &other) {
    std::unique_ptr<iHdlExprItem> r = other.range->clone_uniq();
    range = move(r);
    for (auto &member: other.members) {
        std::unique_ptr<iHdlExprItem> v = nullptr;
        if (member.second) {
            v = member.second->clone_uniq();
        }
        members.push_back( { member.first, move(v) } );
    }
}
iHdlExprItem* HdlPhysicalDef::clone() const {
    return new HdlPhysicalDef(*this);
}

HdlEnumDef::HdlEnumDef() {
}
HdlEnumDef::HdlEnumDef(const HdlEnumDef &other) {
	for (auto &member : other.values) {
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
