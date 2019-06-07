#pragma once

namespace hdlConvertor {
namespace hdlObjects {

class ExprItem {
public:
	virtual ExprItem * clone() const = 0;
	virtual ~ExprItem() {
	}
};

}
}
