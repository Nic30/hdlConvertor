#pragma once

namespace hdlConvertor {
namespace hdlObjects {

class iHdlExprItem {
public:
	virtual iHdlExprItem * clone() const = 0;
	virtual ~iHdlExprItem() {
	}
};

}
}
