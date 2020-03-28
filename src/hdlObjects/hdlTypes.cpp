#include <hdlConvertor/hdlObjects/hdlTypes.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace hdlObjects {


// constraints
HdlConstraint::~HdlConstraint() {}
HdlNoConstraint::~HdlNoConstraint() {}
HdlRangeConstraint::HdlRangeConstraint() {}
HdlRangeConstraint::~HdlRangeConstraint() {}
HdlRecordConstraint::~HdlRecordConstraint() {}
HdlArrayConstraint::~HdlArrayConstraint() {}

// type declaration base class
HdlTypeDec::HdlTypeDec(const std::string& name) :
		WithNameAndDoc(name), iHdlObj() {
}
    
HdlTypeDec::~HdlTypeDec() {
}

// subtype
HdlSubtype::HdlSubtype() {
}
HdlSubtype::HdlSubtype(const HdlSubtype& other) 
	: iHdlObj(other), 
	parent_type(std::make_unique<iHdlExpr>(*other.parent_type)), 
	constraint(std::make_unique<HdlConstraint>(*other.constraint))
{
}
HdlSubtype::~HdlSubtype() {}

HdlSubtypeDec::HdlSubtypeDec(const std::string& name, std::unique_ptr<HdlSubtype> sti)
	: HdlTypeDec(name), subtype(std::move(subtype))
{
}

HdlSubtypeDec::~HdlSubtypeDec() {}

// ranges
HdlSimpleRange::HdlSimpleRange(
		std::unique_ptr<iHdlExpr> left, HdlRangeDirection dir, 
		std::unique_ptr<iHdlExpr> right)
	: left(std::move(left)), dir(dir), right(std::move(right))
{
}
HdlSimpleRange::~HdlSimpleRange() {}
HdlRange::~HdlRange() {}

// enumerated type
HdlEnumTypeDec::HdlEnumTypeDec(const std::string& name)
	: HdlTypeDec(name)
{
}
HdlEnumTypeDec::~HdlEnumTypeDec() {
}

// array type
HdlArrayTypeDec::HdlArrayTypeDec(const std::string& name)
	: HdlTypeDec(name)
{
}
HdlArrayTypeDec::~HdlArrayTypeDec() {
}

// struct or record type
HdlStructTypeDec::HdlStructTypeDec(const std::string& name)
	: HdlTypeDec(name), isUnion(false) 
{
}

HdlStructTypeDec::~HdlStructTypeDec() {
}


}
}
