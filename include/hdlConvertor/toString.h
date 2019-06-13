#pragma once

#include <vector>
#include <iostream>

#include <hdlConvertor/debugConfig.h>
#include <hdlConvertor/hdlObjects/context.h>
#include <hdlConvertor/hdlObjects/operator.h>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/process.h>
#include <hdlConvertor/hdlObjects/aPackage.h>
#include <hdlConvertor/hdlObjects/arch.h>
#include <hdlConvertor/hdlObjects/entity.h>
#include <hdlConvertor/hdlObjects/statement.h>


namespace hdlConvertor {

class ToString {
	static constexpr size_t INDENT_INCR = 2;

	static inline std::ostream& mkIndent(int indent) {
		for (int i = 0; i < indent; i++) {
			std::cout << ' ';
		}
		return std::cout;
	}

	static inline std::ostream & dumpKey(const char * key, int indent) {
		return mkIndent(indent) << "\"" << key << "\":";
	}

	template<typename T>
	static std::ostream & dumpVal(const char * key, int indent, T val) {
		return dumpKey(key, indent) << "\"" << val << "\"";
	}
	template<typename T>
	static std::ostream & dumpArrP(const char * name, int indent,
			std::vector<T> const & objects) {
		dumpKey(name, indent) << "[";
		indent += INDENT_INCR;
		for (auto it : objects) {
			mkIndent(indent);
			dump(it, indent);
			std::cout << ",\n";
		}
		mkIndent(indent - INDENT_INCR);
		std::cout << "]";
		return std::cout;
	}

	template<typename T>
	static std::ostream & dumpItemP(const char * name, int indent,
			T const & object) {
		mkIndent(indent) << "\"" << name << "\":";
		dump(object, indent);
		return std::cout;
	}
public:
	static void dump(const hdlObjects::aPackage * p, int indent);
	static void dump(const hdlObjects::Arch * p, int indent);
	static void dump(const hdlObjects::Context * c, int indent);
	static void dump(const hdlObjects::Entity * e, int indent);
	static void dump(const hdlObjects::Expr * e, int indent);
	static void dump(const hdlObjects::iHdlObj * o, int indent);
	static void dump(const hdlObjects::Named * n, int indent);
	static void dump(const hdlObjects::Operator * v, int indent);
	static void dump(const hdlObjects::Position * o, int indent);
	static void dump(const hdlObjects::Process * p, int indent);
	static void dump(const hdlObjects::Statement * p, int indent);
	static void dump(const hdlObjects::LiteralVal * p, int indent);
	static void dump(const hdlObjects::Variable * v, int indent);
	static void dump(const hdlObjects::WithDoc * wd, int indent);
	static void dump(const hdlObjects::WithNameAndDoc * wnd, int indent);
};

}
