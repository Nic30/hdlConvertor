#include <hdlConvertor/hdlObjects/hdlStmFor.h>
#include <hdlConvertor/hdlObjects/hdlStmExpr.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlStmFor::HdlStmFor(std::unique_ptr<iHdlStatement> _init,
		std::unique_ptr<iHdlExpr> _cond, std::unique_ptr<iHdlStatement> _step,
		std::unique_ptr<iHdlStatement> _body) :
		iHdlStatement(), init(move(_init)), cond(move(_cond)), step(
				move(_step)), body(move(_body)) {

}

HdlStmFor::~HdlStmFor() {
}

HdlStmForIn::HdlStmForIn(std::unique_ptr<HdlVariableDef> _var,
		std::unique_ptr<iHdlExpr> _collection,
		std::unique_ptr<iHdlStatement> _body) :
		iHdlStatement() {
	var_defs.push_back(move(_var));
	collection = move(_collection);
	body = move(_body);
}

HdlStmForIn::HdlStmForIn(std::vector<std::unique_ptr<iHdlObj>> &_vars,
		std::unique_ptr<iHdlExpr> _collection,
		std::unique_ptr<iHdlStatement> _body) {
	var_defs = move(_vars);
	collection = move(_collection);
	body = move(_body);
}

HdlStmForIn::HdlStmForIn(std::vector<std::unique_ptr<iHdlExpr>> &vars,
		std::unique_ptr<iHdlExpr> _collection,
		std::unique_ptr<iHdlStatement> _body) :
		iHdlStatement() {
	for (auto &v : vars) {
		var_defs.push_back(std::make_unique<HdlStmExpr>(move(v)));
	}
	collection = move(_collection);
	body = move(_body);
}

HdlStmForIn::HdlStmForIn(std::unique_ptr<iHdlExpr> _var,
		std::unique_ptr<iHdlExpr> _collection,
		std::unique_ptr<iHdlStatement> _body) {
	var_defs.push_back(std::make_unique<HdlStmExpr>(move(_var)));
	collection = move(_collection);
	body = move(_body);
}

HdlStmForIn::~HdlStmForIn() {
}

}
}
