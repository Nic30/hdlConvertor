#pragma once

namespace hdlConvertor {
namespace hdlObjects {

/*
 * Interface for data of HDL expression
 * */
class iHdlExprItem {
public:
	virtual iHdlExprItem * clone() const = 0;
	virtual ~iHdlExprItem() {
	}
};

}
}
