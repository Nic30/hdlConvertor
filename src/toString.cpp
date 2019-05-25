#include "toString.h"
#include <limits>

namespace hdlConvertor {

using namespace hdlObjects;

void ToString::dump(const aPackage * p, int indent) {
	dump(static_cast<const WithNameAndDoc*>(p), indent);
	indent += INDENT_INCR;
	dumpArrP("components", indent, p->components) << ",\n";
	dumpArrP("function_headers", indent, p->function_headers) << ",\n";
	dumpArrP("functions", indent, p->functions) << "\n";
    dumpArrP("subtype_headers", indent, p->subtype_headers) << ",\n";
    dumpArrP("signals", indent, p->signals) << ",\n";
    dumpArrP("constants", indent, p->constants) << ",\n";
	dumpArrP("variables", indent, p->variables) << ",\n";
	indent -= INDENT_INCR;
	mkIndent(indent) << "}";
}

void ToString::dump(const hdlObjects::Context * c, int indent) {
	mkIndent(indent) << "{\n";
	indent += INDENT_INCR;
	dumpArrP("imports", indent, c->imports) << ",\n";
	dumpArrP("entities", indent, c->entities) << ",\n";
	dumpArrP("architectures", indent, c->architectures) << ",\n";
	dumpArrP("packages", indent, c->packages) << ",\n";
	dumpArrP("packageHeaders", indent, c->packageHeaders) << ",\n";
	dumpArrP("variables", indent, c->variables) << ",\n";
	indent -= INDENT_INCR;
	mkIndent(indent) << "}";
}
void ToString::dump(const Entity * e, int indent) {
	dump(static_cast<const WithNameAndDoc*>(e), indent);
	indent += INDENT_INCR;
	dumpArrP("generics", indent, e->generics) << ",\n";
	dumpArrP("ports", indent, e->ports) << "\n";
	mkIndent(indent - INDENT_INCR) << "}";
}
void ToString::dump(const Expr * e, int indent) {
	Operator * op = dynamic_cast<Operator*>(e->data);
	std::cout << "{\n";
	if (op) {
		dumpItemP("binOperator", indent + INDENT_INCR, op) << "\n";
	} else {
		Symbol * literal = dynamic_cast<Symbol*>(e->data);
		if (literal) {
			dumpItemP("literal", indent + INDENT_INCR, literal) << "\n";
		} else
			throw std::runtime_error("Expr is improperly initialised");
	}
	mkIndent(indent) << "}";
}
void ToString::dump(const Named * n, int indent) {
	std::cout << "{\n";
	mkIndent(indent + INDENT_INCR) << "\"name\":\"" << n->name << "\",\n";
}
void ToString::dump(const WithDoc * wd, int indent) {
	std::cout << "{\n";
	// [NOTE] .c_str() because of the msvc
	mkIndent(indent + INDENT_INCR) << "\"__doc__\":\"" << wd->__doc__.c_str()
			<< "\",\n";
}
void ToString::dump(const WithNameAndDoc * wnd, int indent) {
	std::cout << "{\n";
	mkIndent(indent + INDENT_INCR) << "\"name\":\"" << wnd->name << "\",\n";

	// [NOTE] .c_str() because of the msvc
	mkIndent(indent + INDENT_INCR) << "\"__doc__\":\"" << wnd->__doc__.c_str()
			<< "\",\n";
}
void ToString::dump(const Port * p, int indent) {
	std::cout << "{\n";
	indent += INDENT_INCR;
	dumpVal("direction", indent, Direction_toString(p->direction)) << ",\n";
	dumpKey("variable", indent);
	dump(p->variable, indent);
	std::cout << "\n";
	mkIndent(indent - INDENT_INCR) << "}";
}
void ToString::dump(const Symbol * s, int indent) {
	std::cout << "{\n";
	indent += INDENT_INCR;
	dumpVal("type", indent, SymbolType_toString(s->type)) << ",\n";
	const char * _v;

	switch (s->type) {
	case symb_ID:
	case symb_STRING:
		dumpVal("value", indent, s->value._str) << "\n";
		break;
	case symb_FLOAT:
		dumpVal("value", indent, s->value._float) << "\n";
		break;
	case symb_ARRAY:
		assert(0 && "not implemented");
		break;
	case symb_INT:
		if (s->bits > 0)
			dumpVal("bits", indent, s->bits) << ",\n";
#ifdef USE_PYTHON
#if PY_MAJOR_VERSION < 3
		_v = PyString_AsString(PyObject_Str(s->value._int));
#else
		_v = PyUnicode_AsUTF8(PyObject_Str(s->value._int));
#endif
#else
		_v = std::to_string(s->value._int).c_str();
#endif
		dumpVal("value", indent, _v) << "\n";
		break;
	case symb_ALL:
	case symb_OPEN:
	default:
		break;
	}
	mkIndent(indent - INDENT_INCR) << "}";
}

void ToString::dump(const Variable * v, int indent) {
	dump(static_cast<const WithNameAndDoc*>(v), indent);
	indent += INDENT_INCR;
	dumpKey("type", indent);
	dump(v->type, indent);
	std::cout << ",\n";

	if (v->value) {
		dumpKey("value", indent) << "\n";
		dump(v->value, indent);
	} else {
		dumpVal("value", indent, "None");
	}
	mkIndent(indent - INDENT_INCR) << "}";
}
void ToString::dump(const Operator * o, int indent) {
	std::cout << "{\n";
	indent += INDENT_INCR;
	dumpItemP("op0", indent, o->op0) << ",\n";
	dumpVal("operator", indent, OperatorType_toString(o->op)) << ",\n";

	int arity = OperatorType_arity(o->op);
	switch (arity) {
	case -1:
	case 3:
		dumpArrP("operands", indent, *o->operands) << "\n";
		break;
	case 1:
		break;
	case 2:
		if (o->op1) // may be unary variant of the bin operator (e.g. verilog &a)
			dumpItemP("op1", indent, o->op1) << "\n";
		break;
	default:
		throw "Invalid arity of operator";
	}
	mkIndent(indent - INDENT_INCR) << "}";
}

void ToString::dump(const Process * p, int indent) {
	mkIndent(indent) << "{\n";
	indent += INDENT_INCR;
	dumpArrP("function_headers", indent, p->function_headers) << ",\n";
	dumpArrP("functions", indent, p->functions) << ",\n";
	dumpArrP("subtype_headers", indent, p->subtype_headers) << ",\n";
	dumpArrP("constants", indent, p->constants) << ",\n";
	dumpArrP("variables", indent, p->variables) << ",\n";
	if (p->sensitivity_list_specified)
		dumpArrP("sensitivity_list", indent, p->sensitivity_list) << ",\n";

	//dumpArrP("body", indent, body) << ",\n";
	indent -= INDENT_INCR;
	mkIndent(indent) << "}";
}

void ToString::dump(const Generate * o, int indent) {
	mkIndent(indent) << "{\n";
	indent += INDENT_INCR;
	dumpArrP("componentInstances", indent, o->componentInstances) << ",\n";
	dumpArrP("components", indent, o->components) << ",\n";
	dumpArrP("constants", indent, o->constants) << ",\n";
	dumpArrP("function_headers", indent, o->function_headers) << ",\n";
	dumpArrP("functions", indent, o->functions) << ",\n";
	dumpArrP("subtype_headers", indent, o->subtype_headers) << ",\n";
	dumpArrP("variables", indent, o->variables) << ",\n";
	dumpArrP("processes", indent, o->processes) << ",\n";
	dumpArrP("generates", indent, o->generates) << ",\n";
	indent -= INDENT_INCR;
	mkIndent(indent) << "}";
}
void ToString::dump(const Position * o, int indent) {
	mkIndent(indent) << "{\n";
	indent += INDENT_INCR;
	auto dump_size_t = [&](const std::string & name, size_t val) {
		mkIndent(indent) << "\"" << name << "\":";
		if (val != Position::INVALID) {
			std::cout << val;
		} else {
			std::cout << "null";
		}
		std::cout << ",\n";
	};

	dump_size_t("startLine", o->startLine);
	dump_size_t("stopLine", o->stopLine);
	dump_size_t("startColumn", o->startColumn);
	dump_size_t("stopColumn", o->stopColumn);
	indent -= INDENT_INCR;
	mkIndent(indent) << "}";
}

}
