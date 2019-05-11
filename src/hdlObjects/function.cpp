#include "function.h"

namespace hdlConvertor {
namespace hdlObjects {

Function::Function(char * name, bool isOperator, Expr * returnT,
		std::vector<Variable*> * params) :
		WithNameAndDoc(name), isOperator(isOperator), returnT(returnT), params(params) {
}

Function::~Function() {
	for (auto p : *params)
		delete p;
	delete params;

	for (auto l : locals)
		delete l;

	for (auto b : body)
		delete b;

}

}
}
