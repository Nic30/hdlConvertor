#include <hdlConvertor/hdlObjects/hdlTypeDec.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

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

// array type
HdlArrayTypeDec::~HdlArrayTypeDec() {
}

// struct or record type
HdlStructTypeDec::~HdlStructTypeDec() {
}


}
}
