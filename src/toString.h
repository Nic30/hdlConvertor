#pragma once

#include <vector>
#include <iostream>
#include "debugConfig.h"
#include "hdlObjects/context.h"
#include "hdlObjects/operator.h"
#include "hdlObjects/named.h"
#include "hdlObjects/generate.h"


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
	static void dump(const hdlObjects::Context * c, int indent);
	static void dump(const hdlObjects::aPackage * p, int indent);
	static void dump(const hdlObjects::Entity * e, int indent);
	static void dump(const hdlObjects::Expr * e, int indent);
	static void dump(const hdlObjects::Named * n, int indent);
	static void dump(const hdlObjects::WithDoc * wd, int indent);
	static void dump(const hdlObjects::WithNameAndDoc * wnd, int indent);
	static void dump(const hdlObjects::Port * p, int indent);
	static void dump(const hdlObjects::Symbol * p, int indent);
	static void dump(const hdlObjects::Variable * v, int indent);
	static void dump(const hdlObjects::Operator * v, int indent);
	static void dump(const hdlObjects::Process * p, int indent);
	static void dump(const hdlObjects::Position * o, int indent);
	static void dump(const hdlObjects::Generate * o, int indent);
};

}
