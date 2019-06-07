#pragma once

#include <vector>
#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/entity.h>
#include <hdlConvertor/hdlObjects/expr.h>
#include <hdlConvertor/hdlObjects/function.h>
#include <hdlConvertor/hdlObjects/variable.h>
#include <hdlConvertor/hdlObjects/packageHeader.h>
#include <hdlConvertor/hdlObjects/process.h>

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
