#include <hdlConvertor/hdlAst/iHdlObj.h>
#include <hdlConvertor/hdlAst/iHdlExprItem.h>

namespace hdlConvertor {
namespace hdlAst {

iHdlObj::HdlAttribute::HdlAttribute(const std::string &_id,
		std::unique_ptr<iHdlExprItem> &&_value) :
		id(_id), value(std::move(_value)) {
}

iHdlObj::iHdlObj() :
		hdlAttributes(nullptr) {
}

iHdlObj::iHdlObj(const iHdlObj &other) {
	if (other.hdlAttributes) {
		hdlAttributes = new std::vector<HdlAttribute>();
		for (const auto &a : *other.hdlAttributes) {
			hdlAttributes->push_back(HdlAttribute(a.id, std::unique_ptr<iHdlExprItem>(a.value->clone())));
		}
	} else {
		hdlAttributes = nullptr;
	}
}
iHdlObj::~iHdlObj() {
	if (hdlAttributes)
		delete hdlAttributes;
}

}
}
