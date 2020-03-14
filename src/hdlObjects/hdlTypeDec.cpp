#include <hdlConvertor/hdlObjects/hdlTypeDec.h>

namespace hdlConvertor {
namespace hdlObjects {

// type declaration base class
HdlTypeDec::HdlTypeDec(const std::string& name) :
		WithNameAndDoc(name), iHdlObj() {
}
    
HdlTypeDec::~HdlTypeDec() {
}

// enumerated type
HdlEnumTypeDec::~HdlEnumTypeDec() {
}

HdlTypeDec::TypeClass HdlEnumTypeDec::typeClass() {
	return hdltc_enum;
}

// array type
HdlArrayTypeDec::~HdlArrayTypeDec() {
}

HdlTypeDec::TypeClass HdlArrayTypeDec::typeClass() {
	return hdltc_array;
}

// struct or record type
HdlStructTypeDec::~HdlStructTypeDec() {
}

HdlTypeDec::TypeClass HdlStructTypeDec::typeClass() {
	return hdltc_struct;
}


}
}
