#include <hdlConvertor/toString.h>
#include <limits>

namespace hdlConvertor {

using namespace hdlAst;

void ToString::dump(const HdlValueIdspace * p, int indent) {
	dump(static_cast<const WithNameAndDoc*>(p), indent);
	indent += INDENT_INCR;
	dumpArrP("objs", indent, p->objs) << ",\n";
	indent -= INDENT_INCR;
	mkIndent(indent) << "}";
}

void ToString::dump(const hdlAst::HdlContext * c, int indent) {
	mkIndent(indent) << "{\n";
	indent += INDENT_INCR;
	dumpArrP("objs", indent, c->objs) << ",\n";
	indent -= INDENT_INCR;
	mkIndent(indent) << "}";
}
void ToString::dump(const HdlModuleDec * e, int indent) {
	dump(static_cast<const WithNameAndDoc*>(e), indent);
	indent += INDENT_INCR;
	dumpArrP("generics", indent, e->generics) << ",\n";
	dumpArrP("ports", indent, e->ports) << "\n";
	mkIndent(indent - INDENT_INCR) << "}";
}
void ToString::dump(const iHdlExpr * e, int indent) {
	HdlOp * op = dynamic_cast<HdlOp*>(e->data);
	std::cout << "{\n";
	if (op) {
		dumpItemP("binOperator", indent + INDENT_INCR, op) << "\n";
	} else {
		auto literal = dynamic_cast<HdlValue*>(e->data);
		if (literal) {
			dumpItemP("literal", indent + INDENT_INCR, literal) << "\n";
		} else
			throw std::runtime_error("Expr is improperly initialised");
	}
	mkIndent(indent) << "}";
}
void ToString::dump(const hdlAst::iHdlObj * o, int indent) {
	auto c = dynamic_cast<const HdlContext*>(o);
	if (c)
		dump(c, indent);
	auto md = dynamic_cast<const HdlModuleDec*>(o);
	if (md)
		dump(md, indent);
	auto ex = dynamic_cast<const iHdlExpr*>(o);
	if (ex)
		dump(ex, indent);
	auto v = dynamic_cast<const HdlIdDef*>(o);
	if (v)
		dump(v, indent);
	auto s = dynamic_cast<const iHdlStatement*>(o);
	if (s)
		dump(s, indent);

	assert(false);
}
void ToString::dump(const hdlAst::iHdlStatement * o, int indent) {
	std::cout
			<< "\"[TODO] void ToString::dump(const hdlAst::Statement * o, int indent)\""
			<< std::endl;
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
void ToString::dump(const HdlValue * s, int indent) {
	std::cout << "{\n";
	indent += INDENT_INCR;
	dumpVal("type", indent, HdlValueType_toString(s->type)) << ",\n";
	const char * _v;

	switch (s->type) {
	case HdlValueType::symb_ID:
	case HdlValueType::symb_STRING:
		dumpVal("value", indent, s->_str) << "\n";
		break;
	case HdlValueType::symb_FLOAT:
		dumpVal("value", indent, s->_float) << "\n";
		break;
	case HdlValueType::symb_ARRAY:
		assert(0 && "not implemented");
		break;
	case HdlValueType::symb_INT:
		if (s->bits > 0)
			dumpVal("bits", indent, s->bits) << ",\n";
		auto & i = s->_int;
		if (i.is_bitstring()) {
			dumpVal("base", indent, i.bitstring_base) << ",\n";
			_v = i.bitstring.c_str();
		} else {
			_v = std::to_string(i.val).c_str();
		}
		dumpVal("value", indent, _v) << "\n";
		break;
	case HdlValueType::symb_ALL:
	case HdlValueType::symb_OPEN:
	default:
		break;
	}
	mkIndent(indent - INDENT_INCR) << "}";
}

void ToString::dump(const HdlIdDef * v, int indent) {
	dump(static_cast<const WithNameAndDoc*>(v), indent);
	indent += INDENT_INCR;
	dumpKey("type", indent);
	dump(v->type, indent);
	std::cout << ",\n";
	dumpVal("direction", indent, HdlDirection_toString(v->direction)) << ",\n";
	if (v->value) {
		dumpKey("value", indent) << "\n";
		dump(v->value, indent);
	} else {
		dumpVal("value", indent, "None");
	}
	mkIndent(indent - INDENT_INCR) << "}";
}
void ToString::dump(const HdlOp * o, int indent) {
	std::cout << "{\n";
	indent += INDENT_INCR;
	dumpVal("operator", indent, HdlOpType_toString(o->op)) << ",\n";
	dumpArrP("operands", indent, o->operands) << "\n";
	mkIndent(indent - INDENT_INCR) << "}";
}

void ToString::dump(const HdlStmProcess * p, int indent) {
	mkIndent(indent) << "{\n";
	indent += INDENT_INCR;
	dumpArrP("objs", indent, p->objs()) << ",\n";
	if (p->sensitivity_list_specified)
		dumpArrP("sensitivity_list", indent, p->sensitivity_list()) << ",\n";

	//dumpArrP("body", indent, body) << ",\n";
	indent -= INDENT_INCR;
	mkIndent(indent) << "}";
}

void ToString::dump(const CodePosition * o, int indent) {
	mkIndent(indent) << "{\n";
	indent += INDENT_INCR;
	auto dump_size_t = [&](const std::string & name, size_t val) {
		mkIndent(indent) << "\"" << name << "\":";
		if (val != CodePosition::INVALID) {
			std::cout << val;
		} else {
			std::cout << "null";
		}
		std::cout << ",\n";
	};

	dump_size_t("startLine", o->start_line);
	dump_size_t("stopLine", o->stop_line);
	dump_size_t("startColumn", o->start_column);
	dump_size_t("stopColumn", o->stop_column);
	indent -= INDENT_INCR;
	mkIndent(indent) << "}";
}

}
