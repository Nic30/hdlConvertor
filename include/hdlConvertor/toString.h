#pragma once

#include <vector>
#include <iostream>

#include <hdlConvertor/hdlAst/hdlContext.h>
#include <hdlConvertor/hdlAst/hdlOp.h>
#include <hdlConvertor/hdlAst/named.h>
#include <hdlConvertor/hdlAst/hdlStmProcess.h>
#include <hdlConvertor/hdlAst/hdlNamespace.h>
#include <hdlConvertor/hdlAst/iHdlStatement.h>
#include <hdlConvertor/hdlAst/hdlModuleDec.h>
#include <hdlConvertor/hdlAst/hdlModuleDef.h>


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
	static void dump(const hdlAst::HdlValueIdspace * o, int indent);
	static void dump(const hdlAst::HdlModuleDef * o, int indent);
	static void dump(const hdlAst::HdlContext * o, int indent);
	static void dump(const hdlAst::HdlModuleDec * o, int indent);
	static void dump(const hdlAst::iHdlExpr * o, int indent);
	static void dump(const hdlAst::iHdlObj * o, int indent);
	static void dump(const hdlAst::Named * o, int indent);
	static void dump(const hdlAst::HdlOp * o, int indent);
	static void dump(const hdlAst::CodePosition * o, int indent);
	static void dump(const hdlAst::HdlStmProcess * o, int indent);
	static void dump(const hdlAst::iHdlStatement * o, int indent);
	static void dump(const hdlAst::HdlValue * o, int indent);
	static void dump(const hdlAst::HdlIdDef * o, int indent);
	static void dump(const hdlAst::WithDoc * o, int indent);
	static void dump(const hdlAst::WithNameAndDoc * o, int indent);
};

}
