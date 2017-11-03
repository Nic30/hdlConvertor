#pragma once

class ExprItem {
public:
	virtual ExprItem * clone() const = 0;
	virtual ~ExprItem() {
	}
};
