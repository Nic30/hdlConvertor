#include "utils.h"
#include "exprParser.h"

Expr *Utils::mkStringT() {
	return Expr::ID("__str__");
}
Expr *Utils::mkWireT() {
	return Expr::ID("wire");
}
Expr *Utils::mkWireT(Expr * range) {
	std::vector<Expr*> * operands = new std::vector<Expr*>();
	operands->push_back(range);
	return Expr::call(mkWireT(), operands);
}
Expr *Utils::mkWireT(Ref<Verilog2001Parser::RangeContext> range) {
	if (range)
		return mkWireT(VerExprParser::visitRange(range));
	else
		return mkWireT();
}
