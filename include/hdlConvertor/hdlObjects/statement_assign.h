#pragma once

#include <vector>
#include <hdlConvertor/hdlObjects/statement.h>
#include <hdlConvertor/hdlObjects/expr.h>

namespace hdlConvertor {
namespace hdlObjects {

class HdlAssignStm: public Statement {
public:
	bool is_blocking;
	HdlAssignStm(Expr* dst, Expr * src, bool _is_blocking);
};

class HdlControlledAssignStm: public HdlAssignStm {
public:
	HdlControlledAssignStm(Expr* dst, Expr * src, Expr *time_delay,
			std::vector<Expr*> * event_delay, bool _is_blocking = false);
};

}
}
