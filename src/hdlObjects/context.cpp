#include "context.h"

namespace hdlConvertor {
namespace hdlObjects {

Context::~Context() {
	for (auto i : imports)
		delete i;

	for (auto i : entities)
		delete i;

	for (auto i : architectures)
		delete i;

	for (auto i : packages)
		delete i;

	for (auto i : packageHeaders)
		delete i;

	for (auto i : variables)
		delete i;
}

}
}
