#pragma once

#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../notImplementedLogger.h"
#include "../hdlObjects/named.h"
#include "../hdlObjects/expr.h"
#include "../hdlObjects/function.h"
#include "../hdlObjects/variable.h"
#include "../hdlObjects/packageHeader.h"
#include "../hdlObjects/process.h"

namespace hdlConvertor {
namespace vhdl {

class PackageHeaderParser {
	hdlObjects::PackageHeader * ph;
	bool hierarchyOnly;
public:
	using vhdlParser = vhdl_antlr::vhdlParser;
	using Function = hdlObjects::Function;
	using Variable = hdlObjects::Variable;

	PackageHeaderParser(bool _hierarchyOnly);
	hdlObjects::PackageHeader * visitPackage_declaration(
			vhdlParser::Package_declarationContext* ctx);
	void visitPackage_declarative_part(
			hdlObjects::PackageHeader * ph,
			vhdlParser::Package_declarative_partContext* ctx);
	void visitPackage_declarative_item(
			vhdlParser::Package_declarative_itemContext* ctx);
	hdlObjects::Entity * visitComponent_declaration(
			vhdlParser::Component_declarationContext* ctx);
	static std::vector<Variable*> * visitConstant_declaration(
			vhdlParser::Constant_declarationContext* ctx);
	static Variable * visitSubtype_declaration(
			vhdlParser::Subtype_declarationContext* ctx);
};

}
}
