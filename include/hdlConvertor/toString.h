#pragma once

#include <vector>
#include <iostream>

#include <hdlConvertor/hdlObjects/hdlContext.h>
#include <hdlConvertor/hdlObjects/hdlCall.h>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/hdlStmProcess.h>
#include <hdlConvertor/hdlObjects/hdlNamespace.h>
#include <hdlConvertor/hdlObjects/iHdlStatement.h>
#include <hdlConvertor/hdlObjects/hdlModuleDec.h>
#include <hdlConvertor/hdlObjects/hdlModuleDef.h>


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
	static void dump(const hdlObjects::HdlNamespace * o, int indent);
	static void dump(const hdlObjects::HdlModuleDef * o, int indent);
	static void dump(const hdlObjects::HdlContext * o, int indent);
	static void dump(const hdlObjects::HdlModuleDec * o, int indent);
	static void dump(const hdlObjects::iHdlExpr * o, int indent);
	static void dump(const hdlObjects::iHdlObj * o, int indent);
	static void dump(const hdlObjects::Named * o, int indent);
	static void dump(const hdlObjects::HdlCall * o, int indent);
	static void dump(const hdlObjects::Position * o, int indent);
	static void dump(const hdlObjects::HdlStmProcess * o, int indent);
	static void dump(const hdlObjects::iHdlStatement * o, int indent);
	static void dump(const hdlObjects::HdlValue * o, int indent);
	static void dump(const hdlObjects::HdlVariableDef * o, int indent);
	static void dump(const hdlObjects::WithDoc * o, int indent);
	static void dump(const hdlObjects::WithNameAndDoc * o, int indent);
};

}
